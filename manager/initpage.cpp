#include "initpage.h"
#include "ui_initpage.h"

InitPage::InitPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InitPage)
{
    ui->setupUi(this);
    init();
    this->move((QApplication::desktop()->width() - width())/2,(QApplication::desktop()->height() -height())/5);
}

InitPage::~InitPage()
{
    delete ui;
}

void InitPage::init()
{
    /*窗口设置*/
    this->setWindowTitle("海星找房管理端");
    this->setWindowIcon(QIcon(":/Image/house.svg"));
    this->setWindowFlags(this->windowFlags()&~Qt::WindowMinMaxButtonsHint|Qt::WindowMinimizeButtonHint);//隐藏放大按钮
    /*标题设置*/
    QLabel* labelTitle = new QLabel("欢迎使用\n海星找房管理端");
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitle->setFixedHeight(this->height()/3);
    labelTitle->setStyleSheet("color:red;border-radius:15px;\nfont: 20pt \"方正舒体\";\n");
    /*账号*/
    QLabel* labelAccount = new QLabel("账号:");
    labelAccount->setAlignment(Qt::AlignCenter);
    labelAccount->setFixedWidth(75);
    labelAccount->setStyleSheet("border-radius:15px;\nfont: 15pt \"方正舒体\";\n");
    textAccount = new customInputText;
    QHBoxLayout* layoutAccount = new QHBoxLayout;
    layoutAccount->setMargin(0);
    layoutAccount->addWidget(labelAccount);
    layoutAccount->addWidget(textAccount);
    QWidget* widgetAccount = new QWidget;
    widgetAccount->setLayout(layoutAccount);
    /*密码*/
    QLabel* labelPassword = new QLabel("密码:");
    labelPassword->setAlignment(Qt::AlignCenter);
    labelPassword->setFixedWidth(75);
    labelPassword->setStyleSheet("border-radius:15px;\nfont: 15pt \"方正舒体\";\n");
    textPassword = new customInputText;
    textPassword->editor->setEchoMode(QLineEdit::Password);
    QHBoxLayout* layoutPassword = new QHBoxLayout;
    layoutPassword->setMargin(0);
    layoutPassword->addWidget(labelPassword);
    layoutPassword->addWidget(textPassword);
    QWidget* widgetPassword = new QWidget;
    widgetPassword->setLayout(layoutPassword);
    /*登录*/
    QLabel* labelLogIn = new QLabel("登录->");
    labelLogIn->setAlignment(Qt::AlignCenter);
    labelLogIn->setFixedWidth(75);
    labelLogIn->setStyleSheet("border-radius:15px;\nfont: 10pt \"方正舒体\";\n");
    customToolButton* btnLogIn = new customToolButton;
    btnLogIn->init(":/Image/login.svg",QSize(55,55));
    btnLogIn->setMinimumSize(QSize(60,60));
    connect(btnLogIn,&customToolButton::clicked,this,&InitPage::openManagerPage);
    QHBoxLayout* layoutLogIn = new QHBoxLayout;
    layoutLogIn->setMargin(0);
    layoutLogIn->addWidget(labelLogIn);
    layoutLogIn->addWidget(btnLogIn);
    QWidget* widgetLogIn = new QWidget;
    widgetLogIn->setLayout(layoutLogIn);
    /*账号和密码布局*/
    QVBoxLayout* layoutGroup = new QVBoxLayout;
    layoutGroup->addWidget(widgetAccount);
    layoutGroup->addWidget(widgetPassword);
    layoutGroup->addWidget(widgetLogIn);
    QWidget* widgetAccountPassword = new QWidget;
    widgetAccountPassword->setLayout(layoutGroup);
    widgetAccountPassword->setFixedSize(QSize(300,160));
    widgetAccountPassword->setStyleSheet("background-color:rgb(255,255,255);border-radius:10px;");
    /*标题和账号布局*/
    QVBoxLayout* layoutAll = new QVBoxLayout;
    layoutAll->addWidget(labelTitle);
    layoutAll->addWidget(widgetAccountPassword);
    layoutAll->setMargin(0);
    QWidget* widgetAll = new QWidget;
    widgetAll->setFixedWidth(300);
    widgetAll->setLayout(layoutAll);
    /*左侧图片显示*/
    customImageWidget* lateralPicture = new customImageWidget(this);
    lateralPicture->setPixmap(QPixmap(":/Image/background.jpg"));
    /*图片与功能区布局*/
    QHBoxLayout* layoutFrame = new QHBoxLayout;
    layoutFrame->addWidget(lateralPicture);
    layoutFrame->addWidget(widgetAll);
    layoutFrame->setMargin(20);
    this->setLayout(layoutFrame);
    /*背景模糊化*/
    customImageWidget* background = new customImageWidget(this);
    background->resize(QSize(this->size()));
    background->setPixmap(QPixmap(":/Image/background.jpg"));
    QGraphicsBlurEffect *blureffect = new QGraphicsBlurEffect;
    blureffect->setBlurHints(QGraphicsBlurEffect::PerformanceHint);
    blureffect->setBlurRadius(5);	//数值越大，越模糊
    background->setGraphicsEffect(blureffect);//设置模糊特效
    /*显示功能区和左侧图片*/
    lateralPicture->raise();
    widgetAll->raise();
    /*准备管理端*/
    connect(&managerPage,&ManagerPage::callInitPage,this,&InitPage::openSelf);
}

void InitPage::openManagerPage()
{
    verifyUser();
    if(managerPermission)
    {
        managerPermission=false;
        managerPage.managerID=textAccount->editor->text().toUInt();
        managerPage.init();
        this->hide();
        managerPage.show();
    }
}

void InitPage::openSelf()
{
    textAccount->editor->clear();
    textPassword->editor->clear();
    managerPage.hide();
    this->show();
}

void InitPage::verifyUser()
{
    QString strAccount = textAccount->editor->text();
    QString strPassword = textPassword->editor->text();
    database.connectDB("managerVerify");
    QString sql = "select password from manager where account=%1";
    QList<QMap<QString,QString>> res = database.select(sql.arg(strAccount.toUInt()));
    if(res.size()==0)return;
    else if(res.size()==1)
    {
        auto data=*res.begin();
        QString dbPassword = data["password"];
        strPassword = getSHA1(strPassword);
        if(strPassword==dbPassword)
        {
            managerPermission=true;
        }
    }
    database.disconneectDB("managerVerify");
}
QByteArray InitPage::getSHA1(QString str)
{
    /*该结果的每个元素是8位十六进制数，也就是说一个元素是两个十六进制数组成。如果需要转成人能看懂的数据，把每个元素转成2个十六进制数即可*/
    QByteArray res = QCryptographicHash::hash(str.toLocal8Bit(), QCryptographicHash::Sha1);
    return res;
}
