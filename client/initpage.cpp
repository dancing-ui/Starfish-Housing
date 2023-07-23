#include "initpage.h"
#include "ui_initpage.h"

InitPage::InitPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InitPage)
{
    ui->setupUi(this);
    init();
    /*居中显示页面*/
    this->move((QApplication::desktop()->width() - width())/2,(QApplication::desktop()->height() -height())/5);
    /*因为有析构函数，所以千万不要用下面这个函数，用了之后会因为和析构函数冲突导致程序异常结束*/
    //setAttribute(Qt::WA_DeleteOnClose);
}

InitPage::~InitPage()
{
    delete ui;
}

void InitPage::init()
{
    /*设置顶格图标和文字*/
    this->setWindowTitle("海星找房");
    this->setWindowIcon(QIcon(":/Image/house.svg"));
    /*轮换海报*/
    CarouselImageWindow* w = new CarouselImageWindow(ui->widget_picture);
    w->addImage(":/house/one.png");
    w->addImage(":/house/two.png");
    w->addImage(":/house/three.png");
    w->startPlay();
    w->show();
    /*验证账号和密码*/
    ui->widget_account->editor->setPlaceholderText("请输入账号");
    ui->widget_password->editor->setPlaceholderText("请输入密码");
    ui->widget_password->editor->setEchoMode(QLineEdit::Password);
    connect(ui->widget_account->editor,&QLineEdit::textChanged,this,[=](){
        ui->label_account->clear();
    });
    connect(ui->widget_password->editor,&QLineEdit::textChanged,this,[=](){
        ui->label_password->clear();
    });
    connect(ui->toolButton_logIn,&customToolButton::clicked,this,&InitPage::openClientPage);
    /*设置图标*/
    ui->toolButton_settings->init(":/Image/settings.svg",QSize(70,70));
    ui->toolButton_logIn->init(":/Image/login.svg",QSize(60,60));
    ui->toolButton_signUp->init(":/Image/signup.svg",QSize(60,60));
    /*提前把客户端准备好*/
    connect(&clientPage,&ClientPage::callInitPage,this,&InitPage::openSelf);
    /*初始化设置*/
    initSettings();
}

void InitPage::initSettings()
{
    customToolButton* back = new customToolButton;
    back->init(":/Image/back.svg",QSize(55,55));
    back->setMinimumSize(QSize(60,60));
    connect(back,&customToolButton::clicked,this,[=](){
        settings->hide();
        this->show();
    });
    QLabel* labelVersion = new QLabel("海星找房 v1.0");
    labelVersion->setStyleSheet("font: 15pt \"方正粗黑宋简体\";");
    labelVersion->setFixedHeight(200);
    labelVersion->setAlignment(Qt::AlignCenter);
    QLabel* author = new QLabel("作者:Xian Yu");
    author->setStyleSheet("font: 15pt \"方正粗黑宋简体\";");
    author->setAlignment(Qt::AlignCenter);
    QLabel* date = new QLabel("时间:2022-9-24");
    date->setStyleSheet("font: 15pt \"方正粗黑宋简体\";");
    date->setAlignment(Qt::AlignCenter);
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(back);
    layout->addWidget(labelVersion);
    layout->addWidget(author);
    layout->addWidget(date);
    settings = new QWidget;
    settings->resize(this->size());
    settings->setLayout(layout);
    settings->setStyleSheet("background-color:rgb(255,255,255);border-radius:10px;border:2px solid gray;");
    settings->setWindowFlag(Qt::FramelessWindowHint);
    settings->hide();
}

void InitPage::verifyAccount()
{
    QString account = ui->widget_account->editor->text();
    if(account.size()==0)
    {
        ui->label_account->clear();
        return;
    }
    database.connectDB("acccountConnection");
    QString tableName = "client";
    QString sql = "select account from %1 where account = %2;";
    QList<QMap<QString,QString>> res = database.select(sql.arg(tableName).arg(account));
    if(res.size()==0)
    {
        ui->label_account->setText("账号不存在");
    }
    else
    {
        ui->label_account->clear();//账号存在时，需要清空提示框文字
    }
    database.disconneectDB("acccountConnection");
}

void InitPage::verifyPassword()
{
    QString account = ui->widget_account->editor->text();
    QString password = ui->widget_password->editor->text();
    if(password.size()==0)
    {
        ui->label_password->clear();
        return;
    }
    if(account.size()==0)
    {
        ui->label_password->setText("请先输入账号");
        return;
    }
    database.connectDB("clientPasswordConnection");
    QString tableName = "client";
    QString sql = "select password from %1 where account = %2;";
    QList<QMap<QString,QString>> res = database.select(sql.arg(tableName).arg(account));
    if(res.size()==0)
    {
        ui->label_account->setText("账号不存在");
    }
    else if(res.size()==1)
    {
        auto data = *res.begin();
        QString oldSHA1 = data["password"];
        QString newSHA1 = getSHA1(password);
        if(oldSHA1!=newSHA1)
        {
            ui->label_password->setText("密码错误");
        }
        else
        {
            ui->label_password->clear();//密码正确时，需要清空提示框文字
            if(tableName=="client")
            {
                clientPermission=true;
            }
        }
    }
    database.disconneectDB("clientPasswordConnection");
}

QByteArray InitPage::getSHA1(QString str)
{
    /*该结果的每个元素是8位十六进制数，也就是说一个元素是两个十六进制数组成。如果需要转成人能看懂的数据，把每个元素转成2个十六进制数即可*/
    QByteArray res = QCryptographicHash::hash(str.toLocal8Bit(), QCryptographicHash::Sha1);
    return res;
}

void InitPage::openClientPage()
{
    verifyAccount();
    verifyPassword();
    if(clientPermission)
    {
        clientPermission=false;
        clientPage.clientID = ui->widget_account->editor->text().toInt();
        clientPage.init();//根据用户ID初始化页面
        this->hide();
        clientPage.show();
    }
}

void InitPage::openSelf()
{
    clientPage.hide();
    ui->widget_account->editor->clear();
    ui->widget_password->editor->clear();
    this->show();
}


void InitPage::on_toolButton_settings_clicked()
{
    this->hide();
    settings->move(this->pos());
    settings->show();
}
