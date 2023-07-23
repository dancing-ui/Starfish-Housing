#include "managerpage.h"
#include "ui_managerpage.h"

ManagerPage::ManagerPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerPage)
{
    ui->setupUi(this);
}

ManagerPage::~ManagerPage()
{
    delete ui;
}

void ManagerPage::init()
{
    /*初始化标题栏*/
    initTitle();
    /*个人界面*/
    initPersonelPage();
    /*增加信息界面*/
    initAddPage();
    /*删除信息界面*/
    initRemovePage();
    /*查找信息界面*/
    initSelectPage();
    /*修改信息界面*/
    initUpdatePage();
    /*软件设置界面*/
    initSettingPage();
    /*初始化统计界面*/
    initChart();
}

void ManagerPage::initTitle()
{
    /*窗口设置*/
    this->setWindowTitle("海星找房管理端");
    this->setWindowIcon(QIcon(":/Image/house.svg"));
    /*tab控件栏*/
    mainPage = new QTabWidget;
    mainPage->setTabShape(QTabWidget::Triangular);
    mainPage->setTabPosition(QTabWidget::North);
    mainPage->setTabsClosable(true);//打开关闭按钮
    mainPage->setUsesScrollButtons(true);
    connect(mainPage,&QTabWidget::tabCloseRequested,this,[=](int currentIndex){
        /*关闭按钮的槽函数*/
        /*在这里暂时没啥用，因为不会关闭页面*/
    });
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(mainPage);
    ui->mainFrame->setLayout(layout);
}

void ManagerPage::initPersonelPage()
{
    /*首先查询信息*/
    database.connectDB("queryManagerInfo");
    QString sql = "select * from manager where account = %1";
    QList<QMap<QString,QString>> res = database.select(sql.arg(managerID));
    QString name,sex,birth,level;
    for(auto & data : res)
    {
        name=data["name"];
        sex=data["sex"];
        birth=data["birthday"];
        level=data["level"];
    }
    database.disconneectDB("queryManagerInfo");
    /*然后开始填充内容*/
    QPixmap bgImg(":/house/one.png");
    QLabel* labelBg = new QLabel;
    labelBg->setPixmap(bgImg);
    //提醒保存的标签得在最上面，检测是否被修改
    QLabel* labelSave = new QLabel;
    labelSave->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    labelSave->setMaximumHeight(60);
    labelSave->setAlignment(Qt::AlignCenter);
    labelSave->setStyleSheet("font: 10pt \"方正粗黑宋简体\";color:red;");
    /*接下来是一系列按钮和控件*/
    QLabel* labelName = new QLabel("姓名:");
    labelName->setStyleSheet("font: 10pt \"方正粗黑宋简体\";");
    customInputText* textName = new customInputText;
    textName->setValue(name);
    textName->setEnabled(false);//设置不可点击编辑
    textName->editor->setReadOnly(true);
    connect(textName->editor,&QLineEdit::textChanged,this,[=](){
        labelSave->setText("检测到信息被修改,请点击下方保存按钮保存新信息!");
    });
    customToolButton* btnEditName = new customToolButton;
    btnEditName->init(":/Image/edit.svg",QSize(55,55));
    btnEditName->setMinimumSize(QSize(60,60));
    connect(btnEditName,&customToolButton::clicked,this,[=](){
        textName->setEnabled(true);
        textName->editor->setReadOnly(false);
        textName->enterEditEffect();
        textName->setMouseTracking(true);
    });
    QHBoxLayout* layoutName = new QHBoxLayout;
    layoutName->addWidget(labelName);
    layoutName->addWidget(textName);
    layoutName->addSpacing(20);
    layoutName->addWidget(btnEditName);
    layoutName->setMargin(0);
    QWidget* widgetName = new QWidget;
    widgetName->setLayout(layoutName);
    widgetName->setMaximumHeight(60);


    QLabel* labelSex = new QLabel("性别:");
    labelSex->setStyleSheet("font: 10pt \"方正粗黑宋简体\";");
    customInputText* textSex = new customInputText;
    textSex->setValue(sex);
    textSex->setEnabled(false);//设置不可点击编辑
    textSex->editor->setReadOnly(true);
    connect(textSex->editor,&QLineEdit::textChanged,this,[=](){
        labelSave->setText("检测到信息被修改,请点击下方保存按钮保存新信息!");
    });
    customToolButton* btnEditSex = new customToolButton;
    btnEditSex->init(":/Image/edit.svg",QSize(55,55));
    btnEditSex->setMinimumSize(QSize(60,60));
    connect(btnEditSex,&customToolButton::clicked,this,[=](){
        textSex->setEnabled(true);
        textSex->editor->setReadOnly(false);
        textSex->enterEditEffect();
        textSex->editor->setMouseTracking(true);
    });
    QHBoxLayout* layoutSex = new QHBoxLayout;
    layoutSex->addWidget(labelSex);
    layoutSex->addWidget(textSex);
    layoutSex->addSpacing(20);
    layoutSex->addWidget(btnEditSex);
    layoutSex->setMargin(0);
    QWidget* widgetSex = new QWidget;
    widgetSex->setLayout(layoutSex);
    widgetSex->setMaximumHeight(60);

    QLabel* labelBirth = new QLabel("生日:");
    labelBirth->setStyleSheet("font: 10pt \"方正粗黑宋简体\";");
    customInputText* textBirth = new customInputText;
    textBirth->setValue(birth);
    textBirth->setEnabled(false);//设置不可点击编辑
    textBirth->editor->setReadOnly(true);
    connect(textBirth->editor,&QLineEdit::textChanged,this,[=](){
        labelSave->setText("检测到信息被修改,请点击下方保存按钮保存新信息!");
    });
    customToolButton* btnEditBirth = new customToolButton;
    btnEditBirth->init(":/Image/edit.svg",QSize(55,55));
    btnEditBirth->setMinimumSize(QSize(60,60));
    connect(btnEditBirth,&customToolButton::clicked,this,[=](){
        textBirth->setEnabled(true);
        textBirth->editor->setReadOnly(false);
        textBirth->enterEditEffect();
        textBirth->setMouseTracking(true);
    });
    QHBoxLayout* layoutBirth = new QHBoxLayout;
    layoutBirth->addWidget(labelBirth);
    layoutBirth->addWidget(textBirth);
    layoutBirth->addSpacing(20);
    layoutBirth->addWidget(btnEditBirth);
    layoutBirth->setMargin(0);
    QWidget* widgetBirth = new QWidget;
    widgetBirth->setLayout(layoutBirth);
    widgetBirth->setMaximumHeight(60);

    QLabel* labelLevel = new QLabel("当前等级:");
    labelLevel->setStyleSheet("font: 10pt \"方正粗黑宋简体\";");
    customInputText* textLevel = new customInputText;
    textLevel->setValue(level);
    textLevel->setEnabled(false);//设置不可点击编辑
    textLevel->editor->setReadOnly(true);
    customToolButton* btnEditLevel = new customToolButton;
    btnEditLevel->setToolTip("不可修改");
    btnEditLevel->init(":/Image/edit.svg",QSize(55,55));
    btnEditLevel->setMinimumSize(QSize(60,60));
    QHBoxLayout* layoutLevel = new QHBoxLayout;
    layoutLevel->addWidget(labelLevel);
    layoutLevel->addWidget(textLevel);
    layoutLevel->addSpacing(20);
    layoutLevel->addWidget(btnEditLevel);
    layoutLevel->setMargin(0);
    QWidget* widgetLevel = new QWidget;
    widgetLevel->setLayout(layoutLevel);
    widgetLevel->setMaximumHeight(60);

    customToolButton* btnSave = new customToolButton;
    btnSave->init(":/Image/save.svg",QSize(55,55));
    btnSave->setMinimumSize(QSize(60,60));
    btnSave->setToolTip("保存信息");
    connect(btnSave,&customToolButton::clicked,this,[=](){
        database.connectDB("updateManagerInfo");
        QString sql = "update manager set name='%1',sex='%2',birthday='%3' where account=%4;";
        if(database.update(sql.arg(textName->editor->text()).arg(textSex->editor->text()).arg(textBirth->editor->text()).arg(managerID)))
        {
            QMessageBox::information(this,"","更新信息成功",QMessageBox::Close);
            labelSave->clear();
            textName->setEnabled(false);
            textName->editor->setReadOnly(true);
            textSex->setEnabled(false);
            textSex->editor->setReadOnly(true);
            textBirth->setEnabled(false);
            textBirth->editor->setReadOnly(true);
        }
        else
        {
            QMessageBox::information(this,"警告","哎呀,更新失败了",QMessageBox::Close);
        }
        database.disconneectDB("updateManagerInfo");
    });

    QHBoxLayout* layoutSetting = new QHBoxLayout;
    layoutSetting->addWidget(btnSave);
    layoutSetting->setMargin(0);
    QWidget* widgetSetting = new QWidget;
    widgetSetting->setLayout(layoutSetting);
    widgetSetting->setMaximumHeight(60);

    QVBoxLayout* layoutInfo = new QVBoxLayout;
    layoutInfo->addWidget(widgetName);
    layoutInfo->addWidget(widgetSex);
    layoutInfo->addWidget(widgetBirth);
    layoutInfo->addWidget(widgetLevel);
    layoutInfo->addWidget(labelSave);
    layoutInfo->addWidget(widgetSetting);

    QWidget* infoGroup = new QWidget;
    infoGroup->setLayout(layoutInfo);

    QHBoxLayout* allLayout = new QHBoxLayout;
    allLayout->addWidget(labelBg);
    allLayout->addWidget(infoGroup);

    personelPage = new QWidget;
    personelPage->setLayout(allLayout);

    mainPage->addTab(personelPage,"个人信息");
}

void ManagerPage::initAddPage()
{
    /*房屋信息*/
    QLabel* labelName = new QLabel("房屋名:");
    labelName->setAlignment(Qt::AlignCenter);
    labelName->setFixedHeight(75);
    labelName->setStyleSheet("border-radius:15px;\nfont: 15pt \"方正粗黑宋简体\";\n");
    customInputText* textName = new customInputText;
    QHBoxLayout* layoutName = new QHBoxLayout;
    layoutName->setMargin(0);
    layoutName->addWidget(labelName);
    layoutName->addWidget(textName);
    QWidget* widgetName = new QWidget;
    widgetName->setLayout(layoutName);
    widgetName->setMaximumHeight(60);

    QLabel* labelArea = new QLabel("房屋面积:");
    labelArea->setAlignment(Qt::AlignCenter);
    labelArea->setFixedHeight(75);
    labelArea->setStyleSheet("border-radius:15px;\nfont: 15pt \"方正粗黑宋简体\";\n");
    customInputText* textArea = new customInputText;
    QHBoxLayout* layoutArea = new QHBoxLayout;
    layoutArea->setMargin(0);
    layoutArea->addWidget(labelArea);
    layoutArea->addWidget(textArea);
    QWidget* widgetArea = new QWidget;
    widgetArea->setLayout(layoutArea);
    widgetArea->setMaximumHeight(60);

    QLabel *labelPrice = new QLabel("房屋价格:");
    labelPrice->setAlignment(Qt::AlignCenter);
    labelPrice->setFixedHeight(75);
    labelPrice->setStyleSheet("border-radius:15px;\nfont: 15pt \"方正粗黑宋简体\";\n");
    customInputText *textPrice = new customInputText;
    QHBoxLayout *layoutPrice = new QHBoxLayout;
    layoutPrice->setMargin(0);
    layoutPrice->addWidget(labelPrice);
    layoutPrice->addWidget(textPrice);
    QWidget *widgetPrice = new QWidget;
    widgetPrice->setLayout(layoutPrice);
    widgetPrice->setMaximumHeight(60);

    QLabel *labelLocation = new QLabel("房屋位置:");
    labelLocation->setAlignment(Qt::AlignCenter);
    labelLocation->setFixedHeight(75);
    labelLocation->setStyleSheet("border-radius:15px;\nfont: 15pt \"方正粗黑宋简体\";\n");
    customInputText *textLocation = new customInputText;
    QHBoxLayout *layoutLocation = new QHBoxLayout;
    layoutLocation->setMargin(0);
    layoutLocation->addWidget(labelLocation);
    layoutLocation->addWidget(textLocation);
    QWidget *widgetLocation = new QWidget;
    widgetLocation->setLayout(layoutLocation);
    widgetLocation->setMaximumHeight(60);

    QLabel *labelType = new QLabel("房屋类型:");
    labelType->setAlignment(Qt::AlignCenter);
    labelType->setFixedHeight(75);
    labelType->setStyleSheet("border-radius:15px;\nfont: 15pt \"方正粗黑宋简体\";\n");
    customInputText *textType = new customInputText;
    QHBoxLayout *layoutType = new QHBoxLayout;
    layoutType->setMargin(0);
    layoutType->addWidget(labelType);
    layoutType->addWidget(textType);
    QWidget *widgetType = new QWidget;
    widgetType->setLayout(layoutType);
    widgetType->setMaximumHeight(60);

    QLabel *labelFloor = new QLabel("房屋楼层:");
    labelFloor->setAlignment(Qt::AlignCenter);
    labelFloor->setFixedHeight(75);
    labelFloor->setStyleSheet("border-radius:15px;\nfont: 15pt \"方正粗黑宋简体\";\n");
    customInputText *textFloor = new customInputText;
    QHBoxLayout *layoutFloor = new QHBoxLayout;
    layoutFloor->setMargin(0);
    layoutFloor->addWidget(labelFloor);
    layoutFloor->addWidget(textFloor);
    QWidget *widgetFloor = new QWidget;
    widgetFloor->setLayout(layoutFloor);
    widgetFloor->setMaximumHeight(60);

    QLabel *labelElevator = new QLabel("是否有电梯:");
    labelElevator->setAlignment(Qt::AlignCenter);
    labelElevator->setFixedHeight(75);
    labelElevator->setStyleSheet("border-radius:15px;\nfont: 15pt \"方正粗黑宋简体\";\n");
    customInputText *textElevator = new customInputText;
    QHBoxLayout *layoutElevator = new QHBoxLayout;
    layoutElevator->setMargin(0);
    layoutElevator->addWidget(labelElevator);
    layoutElevator->addWidget(textElevator);
    QWidget *widgetElevator = new QWidget;
    widgetElevator->setLayout(layoutElevator);
    widgetElevator->setMaximumHeight(60);

    QLabel *labelFitment = new QLabel("装修类型:");
    labelFitment->setAlignment(Qt::AlignCenter);
    labelFitment->setFixedHeight(75);
    labelFitment->setStyleSheet("border-radius:15px;\nfont: 15pt \"方正粗黑宋简体\";\n");
    customInputText *textFitment = new customInputText;
    QHBoxLayout *layoutFitment = new QHBoxLayout;
    layoutFitment->setMargin(0);
    layoutFitment->addWidget(labelFitment);
    layoutFitment->addWidget(textFitment);
    QWidget *widgetFitment = new QWidget;
    widgetFitment->setLayout(layoutFitment);
    widgetFitment->setMaximumHeight(60);

    /*按钮*/
    customToolButton* btnOK = new customToolButton;
    btnOK->init(":/Image/confirm.svg",QSize(55,55));
    btnOK->setFixedSize(QSize(60,60));
    auto verifyAddInfo = [=]()->bool
    {
        if(textName->editor->text().size()==0||textArea->editor->text().size()==0||
                textType->editor->text().size()==0||textFloor->editor->text().size()==0||
                textPrice->editor->text().size()==0||textFitment->editor->text().size()==0||
                textElevator->editor->text().size()==0||textLocation->editor->text().size()==0)
        {
            return false;
        }
        return true;
    };
    connect(btnOK,&customToolButton::clicked,this,[=](){
        if(verifyAddInfo()==false)
        {
            return;
        }
        database.connectDB("addInfo");
        QString sql = "insert into house(name,area,price,location,type,floor,elevator,fitment,sold,client_account,manager_account)"
                      "values('%1',%2,%3,'%4','%5',%6,%7,'%8',false,1,2);";
        bool isOK = database.insert(sql.arg(textName->editor->text()).arg(textArea->editor->text()).arg(textPrice->editor->text())
                        .arg(textLocation->editor->text()).arg(textType->editor->text()).arg(textFloor->editor->text())
                        .arg(textElevator->editor->text()).arg(textFitment->editor->text()));

        if(isOK)
        {
            QMessageBox::information(this,"","添加成功",QMessageBox::Close);
        }
        else
        {
            QMessageBox::information(this,"","添加失败，信息填写不规范",QMessageBox::Close);
        }
        database.disconneectDB("addInfo");
    });

    QVBoxLayout* layoutInfo = new QVBoxLayout;
    layoutInfo->addWidget(widgetName);
    layoutInfo->addWidget(widgetArea);
    layoutInfo->addWidget(widgetPrice);
    layoutInfo->addWidget(widgetLocation);
    layoutInfo->addWidget(widgetType);
    layoutInfo->addWidget(widgetFloor);
    layoutInfo->addWidget(widgetElevator);
    layoutInfo->addWidget(widgetFitment);
    layoutInfo->addWidget(btnOK);
    QWidget* widgetInfo = new QWidget;
    widgetInfo->setLayout(layoutInfo);

    QLabel* labelTitle = new QLabel("《信息填写指南》");
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitle->setFixedHeight(75);
    labelTitle->setStyleSheet("color:red;border-radius:15px;\nfont: 20pt \"方正粗黑宋简体\";\n");
    QLabel* labelHint = new QLabel("房屋名请具体填写到小区名;\n"
                                   "有电梯填写true，否则填false;\n");
    labelHint->setAlignment(Qt::AlignTop|Qt::AlignCenter);
    labelHint->setStyleSheet("border-radius:15px;\nfont: 20pt \"方正粗黑宋简体\";\n");
    QVBoxLayout* layoutHint = new QVBoxLayout;
    layoutHint->addWidget(labelTitle);
    layoutHint->addWidget(labelHint);
    QWidget* widgetHint = new QWidget;
    widgetHint->setLayout(layoutHint);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(widgetInfo);
    layout->addWidget(widgetHint);

    addPage = new QWidget(this);
    addPage->setLayout(layout);

    mainPage->addTab(addPage,"增加房屋信息");
}

void ManagerPage::initRemovePage()
{
    removePage = new QWidget;
    customToolButton* btnSearch = new customToolButton;
    btnSearch->init(":/Image/search.svg",QSize(55,55));
    btnSearch->setFixedSize(QSize(60,60));
    customInputText* textSearch = new customInputText;
    textSearch->editor->setPlaceholderText("请输入要删除的房屋名");
    textSearch->setFixedSize(QSize(this->width()/3,60));

    QHBoxLayout* layoutSearch = new QHBoxLayout;
    layoutSearch->addWidget(textSearch);
    layoutSearch->addWidget(btnSearch);
    layoutSearch->setMargin(0);
    QWidget* widgetSearch = new QWidget(removePage);//父控件要先申请空间，子控件再继承
    widgetSearch->setLayout(layoutSearch);
    widgetSearch->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    QScrollArea* scrollInfo = new QScrollArea(removePage);
    QWidget* scrollInfoContents = new QWidget(removePage);//滑动栏需要用单独的一个widget
    connect(btnSearch,&customToolButton::clicked,this,[=](){
        if(textSearch->editor->text().size()==0)return;
        clearLayout(scrollInfoContents);
        scrollInfoContents->setLayout(updateHouseInfo(scrollInfoContents,textSearch->editor->text(),true,false));
        scrollInfo->setWidget(scrollInfoContents);
        scrollInfo->setWidgetResizable(true);//打开滑动条
        scrollInfo->move(0,this->height());
        /*查询栏滑动特效*/
        /*只能在图形绘制完成之后，geometry可以获取到布局内控件的位置*/
        QPropertyAnimation* aniScrollSearch = new QPropertyAnimation(widgetSearch,"geometry",removePage);
        aniScrollSearch->setStartValue(widgetSearch->geometry());
        aniScrollSearch->setEndValue(QRectF(widgetSearch->x(),0,widgetSearch->width(),widgetSearch->height()));
        aniScrollSearch->setDuration(1000);
        aniScrollSearch->setEasingCurve(QEasingCurve::InOutExpo);
        aniScrollSearch->start();
        QPropertyAnimation* aniScrollArea = new QPropertyAnimation(scrollInfo,"geometry",removePage);
        aniScrollArea->setStartValue(scrollInfo->geometry());
        aniScrollArea->setEndValue(QRectF(scrollInfo->x(),widgetSearch->height(),scrollInfo->width(),scrollInfo->height()));
        aniScrollArea->setDuration(1000);
        aniScrollArea->setEasingCurve(QEasingCurve::InOutExpo);
        aniScrollArea->start();
    });
    mainPage->addTab(removePage,"删除房屋信息");
    widgetSearch->move(removePage->width()/2,removePage->height()/2);//居中显示
    scrollInfo->move(0,this->height());
    scrollInfo->setStyleSheet("border:none;");
    scrollInfo->resize(this->width(),this->height());
}

void ManagerPage::initSelectPage()
{
    selectPage = new QWidget;
    customToolButton *btnSearch = new customToolButton;
    btnSearch->init(":/Image/search.svg", QSize(55, 55));
    btnSearch->setFixedSize(QSize(60, 60));
    customInputText *textSearch = new customInputText;
    textSearch->editor->setPlaceholderText("请输入要查找的房屋名");
    textSearch->setFixedSize(QSize(this->width() / 3, 60));

    QHBoxLayout *layoutSearch = new QHBoxLayout;
    layoutSearch->addWidget(textSearch);
    layoutSearch->addWidget(btnSearch);
    layoutSearch->setMargin(0);
    QWidget *widgetSearch = new QWidget(selectPage); //父控件要先申请空间，子控件再继承
    widgetSearch->setLayout(layoutSearch);
    widgetSearch->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QScrollArea *scrollInfo = new QScrollArea(selectPage);
    QWidget *scrollInfoContents = new QWidget(selectPage); //滑动栏需要用单独的一个widget
    connect(btnSearch, &customToolButton::clicked, this, [=]()
            {
            if(textSearch->editor->text().size()==0)return;
            clearLayout(scrollInfoContents);
            scrollInfoContents->setLayout(updateHouseInfo(scrollInfoContents,textSearch->editor->text(),false,false));
            scrollInfo->setWidget(scrollInfoContents);
            scrollInfo->setWidgetResizable(true);//打开滑动条
            scrollInfo->move(0,this->height());
            /*查询栏滑动特效*/
            /*只能在图形绘制完成之后，geometry可以获取到布局内控件的位置*/
            QPropertyAnimation* aniScrollSearch = new QPropertyAnimation(widgetSearch,"geometry",selectPage);
            aniScrollSearch->setStartValue(widgetSearch->geometry());
            aniScrollSearch->setEndValue(QRectF(widgetSearch->x(),0,widgetSearch->width(),widgetSearch->height()));
            aniScrollSearch->setDuration(1000);
            aniScrollSearch->setEasingCurve(QEasingCurve::InOutExpo);
            aniScrollSearch->start();
            QPropertyAnimation* aniScrollArea = new QPropertyAnimation(scrollInfo,"geometry",selectPage);
            aniScrollArea->setStartValue(scrollInfo->geometry());
            aniScrollArea->setEndValue(QRectF(scrollInfo->x(),widgetSearch->height(),scrollInfo->width(),scrollInfo->height()));
            aniScrollArea->setDuration(1000);
            aniScrollArea->setEasingCurve(QEasingCurve::InOutExpo);
            aniScrollArea->start(); });
    mainPage->addTab(selectPage, "查找房屋信息");
    widgetSearch->move(selectPage->width() / 2, selectPage->height() / 2); //居中显示
    scrollInfo->move(0, this->height());
    scrollInfo->setStyleSheet("border:none;");
    scrollInfo->resize(this->width(), this->height());
}

void ManagerPage::initUpdatePage()
{
    updatePage = new QWidget;
    customToolButton *btnSearch = new customToolButton;
    btnSearch->init(":/Image/search.svg", QSize(55, 55));
    btnSearch->setFixedSize(QSize(60, 60));
    customInputText *textSearch = new customInputText;
    textSearch->editor->setPlaceholderText("请输入要修改的房屋名");
    textSearch->setFixedSize(QSize(this->width() / 3, 60));

    QHBoxLayout *layoutSearch = new QHBoxLayout;
    layoutSearch->addWidget(textSearch);
    layoutSearch->addWidget(btnSearch);
    layoutSearch->setMargin(0);
    QWidget *widgetSearch = new QWidget(updatePage); //父控件要先申请空间，子控件再继承
    widgetSearch->setLayout(layoutSearch);
    widgetSearch->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QScrollArea *scrollInfo = new QScrollArea(updatePage);
    QWidget *scrollInfoContents = new QWidget(updatePage); //滑动栏需要用单独的一个widget
    connect(btnSearch, &customToolButton::clicked, this, [=](){
            if(textSearch->editor->text().size()==0)return;
            clearLayout(scrollInfoContents);
            scrollInfoContents->setLayout(updateHouseInfo(scrollInfoContents,textSearch->editor->text(),true,true));
            scrollInfo->setWidget(scrollInfoContents);
            scrollInfo->setWidgetResizable(true);//打开滑动条
            scrollInfo->move(0,this->height());
            /*查询栏滑动特效*/
            /*只能在图形绘制完成之后，geometry可以获取到布局内控件的位置*/
            QPropertyAnimation* aniScrollSearch = new QPropertyAnimation(widgetSearch,"geometry",updatePage);
            aniScrollSearch->setStartValue(widgetSearch->geometry());
            aniScrollSearch->setEndValue(QRectF(widgetSearch->x(),0,widgetSearch->width(),widgetSearch->height()));
            aniScrollSearch->setDuration(1000);
            aniScrollSearch->setEasingCurve(QEasingCurve::InOutExpo);
            aniScrollSearch->start();
            QPropertyAnimation* aniScrollArea = new QPropertyAnimation(scrollInfo,"geometry",updatePage);
            aniScrollArea->setStartValue(scrollInfo->geometry());
            aniScrollArea->setEndValue(QRectF(scrollInfo->x(),widgetSearch->height(),scrollInfo->width(),scrollInfo->height()));
            aniScrollArea->setDuration(1000);
            aniScrollArea->setEasingCurve(QEasingCurve::InOutExpo);
            aniScrollArea->start();
    });
    mainPage->addTab(updatePage, "修改房屋信息");
    widgetSearch->move(updatePage->width() / 2, updatePage->height() / 2); //居中显示
    scrollInfo->move(0, this->height());
    scrollInfo->setStyleSheet("border:none;");
    scrollInfo->resize(this->width(), this->height());
}

void ManagerPage::initSettingPage()
{
    /*开始填充内容*/
    QPixmap bgImg(":/house/two.png");
    QLabel* labelBg = new QLabel;
    labelBg->setPixmap(bgImg);

    QLabel* labelAccount = new QLabel("账号:");
    labelAccount->setStyleSheet("font: 10pt \"方正粗黑宋简体\";");
    customInputText* textAccount = new customInputText;
    textAccount->setValue(QString::number(managerID));
    textAccount->setEnabled(false);//设置不可点击编辑
    textAccount->editor->setReadOnly(true);
    customToolButton* btnEditAccount = new customToolButton;
    btnEditAccount->init(":/Image/edit.svg",QSize(55,55));
    btnEditAccount->setMinimumSize(QSize(60,60));
    btnEditAccount->setToolTip("不可修改");
    QHBoxLayout* layoutAccount = new QHBoxLayout;
    layoutAccount->addWidget(labelAccount);
    layoutAccount->addWidget(textAccount);
    layoutAccount->addSpacing(20);
    layoutAccount->addWidget(btnEditAccount);
    layoutAccount->setMargin(0);
    QWidget* widgetAccount = new QWidget;
    widgetAccount->setLayout(layoutAccount);
    widgetAccount->setMaximumHeight(60);

    QLabel* labelPassword = new QLabel("修改密码:");
    labelPassword->setStyleSheet("font: 10pt \"方正粗黑宋简体\";");
    customInputText* textPassword = new customInputText;
    textPassword->setEnabled(false);//设置不可点击编辑
    textPassword->editor->setReadOnly(true);
    textPassword->editor->setEchoMode(QLineEdit::Password);
    connect(textPassword->editor,&QLineEdit::textChanged,this,[=](){
        if(verifyPassword(textPassword->editor->text()))
        {
            /*更新新密码*/
            updatePassword();
            textPassword->editor->setPlaceholderText("输入原始密码");
            textPassword->setEnabled(false);
            textPassword->editor->clear();
        }
    });
    customToolButton* btnEditPassword = new customToolButton;
    btnEditPassword->init(":/Image/edit.svg",QSize(55,55));
    btnEditPassword->setMinimumSize(QSize(60,60));
    connect(btnEditPassword,&customToolButton::clicked,this,[=](){
        textPassword->editor->setPlaceholderText("输入原始密码");
        textPassword->setEnabled(true);
        textPassword->editor->setReadOnly(false);
        textPassword->enterEditEffect();
        textPassword->editor->setMouseTracking(true);
    });
    QHBoxLayout* layoutPassword = new QHBoxLayout;
    layoutPassword->addWidget(labelPassword);
    layoutPassword->addWidget(textPassword);
    layoutPassword->addSpacing(20);
    layoutPassword->addWidget(btnEditPassword);
    layoutPassword->setMargin(0);
    QWidget* widgetPassword = new QWidget;
    widgetPassword->setLayout(layoutPassword);
    widgetPassword->setMaximumHeight(60);
    widgetPassword->setStyleSheet("border:2px;");

    QLabel* labelChange = new QLabel("切换账号");
    labelChange->setFixedHeight(20);
    labelChange->setStyleSheet("font: 9pt \"方正粗黑宋简体\";");
    customToolButton* btnChange = new customToolButton;
    btnChange->init(":/Image/change.svg",QSize(55,55));
    btnChange->setMinimumSize(QSize(60,60));
    connect(btnChange,&customToolButton::clicked,this,&ManagerPage::openInitPage);
    QLabel* labelOut = new QLabel("退出当前账号");
    labelOut->setFixedHeight(20);
    labelOut->setStyleSheet("font: 9pt \"方正粗黑宋简体\";");
    customToolButton* btnOut = new customToolButton;
    btnOut->init(":/Image/out.svg",QSize(55,55));
    btnOut->setMinimumSize(QSize(60,60));
    connect(btnOut,&customToolButton::clicked,this,&ManagerPage::openInitPage);
    QGridLayout* layoutOut = new QGridLayout;
    layoutOut->addWidget(btnChange,0,0);
    layoutOut->addWidget(btnOut,0,1);
    layoutOut->addWidget(labelChange,1,0);
    layoutOut->addWidget(labelOut,1,1);
    layoutOut->setMargin(0);
    QWidget* widgetOut = new QWidget;
    widgetOut->setLayout(layoutOut);
    widgetOut->setFixedHeight(100);

    QVBoxLayout* layoutInfo = new QVBoxLayout;
    layoutInfo->addSpacing(100);
    layoutInfo->addWidget(widgetAccount);
    layoutInfo->addWidget(widgetPassword);
    layoutInfo->addWidget(widgetOut);

    QWidget* infoGroup = new QWidget;
    infoGroup->setLayout(layoutInfo);

    QHBoxLayout* allLayout = new QHBoxLayout;
    allLayout->addWidget(labelBg);
    allLayout->addWidget(infoGroup);

    settingPage = new QWidget;
    settingPage->setLayout(allLayout);

    mainPage->addTab(settingPage,"软件设置");
}

void ManagerPage::initChart()
{
    // 创建QChartView 对象
    QChartView *chartView;
    // QChartView 对象载入饼状图
    chartView = new QChartView(createPieChart());
    // 显示图标
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(chartView);
    chartPage = new QWidget;
    chartPage->setLayout(layout);

    mainPage->addTab(chartPage,"数据统计");
}

QChart *ManagerPage::createPieChart()
{
    database.connectDB("chartInfoConnection");
    QString sql = "select type from house";
    QList<QMap<QString,QString>> ans = database.select(sql);
    database.disconneectDB("chartInfoConnection");
    QMap<QString,qreal> cnt = calChartRate(ans);

    QChart *chart = new QChart();
    chart->setTitle("房屋类型饼状图");

    QPieSeries *series = new QPieSeries(chart);
    foreach(QString name,cnt.keys())
    {
        series->append(name,cnt[name]);
    }

    series->setLabelsVisible();
    //饼图的大小
    series->setPieSize(0.6);

    for(auto& slice:series->slices())
    {
        slice->setLabelVisible();// 是否显示指标文字
        slice->setExploded();//扇面区分
        slice->setExplodeDistanceFactor(0.1);// 扇面分开的距离指数
    }

    chart->setAnimationOptions(QChart::AllAnimations);//设置动画效果

    chart->addSeries(series);
    chart->setTheme(QChart::ChartThemeBlueIcy); //选择主题
    return chart;
}

QMap<QString, qreal> ManagerPage::calChartRate(QList<QMap<QString, QString> > &arg)
{
    QMap<QString,qreal> cnt;
    for(auto& data:arg)
    {
        cnt[data["type"]]++;
    }
    return cnt;
}
bool ManagerPage::verifyPassword(const QString& curPassword)
{
    database.connectDB("verifyManagerPasssword");
    QString sql = "select password from manager where account=%1";
    QList<QMap<QString,QString>> res=database.select(sql.arg(managerID));
    auto data = *res.begin();
    QString oldSHA1 = data["password"];
    QString newSHA1 = getSHA1(curPassword);
    bool flag=false;
    if(oldSHA1==newSHA1)
    {
        flag=true;
    }
    database.disconneectDB("verifyManagerPasssword");
    return flag;
}

void ManagerPage::updatePassword()
{
    /*更新新密码*/
    QLabel* labelNew = new QLabel("输入新密码:");
    customInputText* textPassword = new customInputText;
    textPassword->editor->setPlaceholderText("输入新密码");
    textPassword->editor->setEchoMode(QLineEdit::Normal);
    QHBoxLayout* layoutNew = new QHBoxLayout;
    layoutNew->addWidget(labelNew);
    layoutNew->addWidget(textPassword);
    layoutNew->setMargin(0);
    QWidget* widgetNew = new QWidget;
    widgetNew->setLayout(layoutNew);
    /*确认密码*/
    QLabel* labelConfirm = new QLabel("确认新密码:");
    customInputText* textConfirm = new customInputText;
    textConfirm->editor->setPlaceholderText("再次输入新密码");
    textConfirm->editor->setEchoMode(QLineEdit::Normal);
    QHBoxLayout* layoutConfirm = new QHBoxLayout;
    layoutConfirm->addWidget(labelConfirm);
    layoutConfirm->addWidget(textConfirm);
    layoutConfirm->setMargin(0);
    QWidget* widgetConfirm = new QWidget;
    widgetConfirm->setLayout(layoutConfirm);
    /*确认取消按钮组*/
    customToolButton* btnConfirm = new customToolButton;
    btnConfirm->init(":/Image/confirm.svg",QSize(55,55));
    btnConfirm->setMinimumSize(QSize(60,60));
    customToolButton* btnCancel = new customToolButton;
    btnCancel->init(":/Image/cancel.svg",QSize(55,55));
    btnCancel->setMinimumSize(QSize(60,60));
    QHBoxLayout* layoutBtn = new QHBoxLayout;
    layoutBtn->addWidget(btnConfirm);
    layoutBtn->addWidget(btnCancel);
    QWidget* widgetBtn = new QWidget;
    widgetBtn->setLayout(layoutBtn);

    QVBoxLayout* layoutAll = new QVBoxLayout;
    layoutAll->addWidget(widgetNew);
    layoutAll->addWidget(widgetConfirm);
    layoutAll->addWidget(widgetBtn);
    QWidget* widgetAll = new QWidget;
    widgetAll->setLayout(layoutAll);
    widgetAll->setFixedSize(QSize(400,200));
    this->setEnabled(false);
    widgetAll->setEnabled(true);
    widgetAll->setMouseTracking(true);
    widgetAll->setStyleSheet("background-color:white;");
    widgetAll->setWindowTitle("修改密码");
    widgetAll->setWindowIcon(QIcon(":/Image/house.svg"));
    widgetAll->setWindowFlags(Qt::FramelessWindowHint);
    widgetAll->setAttribute (Qt::WA_ShowModal, true);//模态对话框
    widgetAll->move(this->width()/2,this->height()/2);
    widgetAll->show();
    textPassword->enterEditEffect();
    connect(btnConfirm,&customToolButton::clicked,widgetAll,[=](){
        if(textPassword->editor->text().size()==0||textConfirm->editor->text().size()==0)
        {
            QMessageBox::information(widgetAll,"","请先输入密码",QMessageBox::Close);
        }
        else if(textPassword->editor->text()==textConfirm->editor->text())
        {
            database.connectDB("updateManagerPassword");
            QString sql = "update manager set password='%1' where account=%2";
            if(database.update(sql.arg(QString(getSHA1(textPassword->editor->text()))).arg(managerID)))
            {
                QMessageBox::information(this,"","更新密码成功!",QMessageBox::Close);
            }
            else
            {
                QMessageBox::information(this,"","哎呀,出错了!",QMessageBox::Close);
            }
            database.disconneectDB("updateManagerPassword");
            this->setEnabled(true);
            widgetAll->close();
            widgetAll->deleteLater();
        }
        else
        {
            QMessageBox::information(widgetAll,"","两次输入的密码不相同",QMessageBox::Close);
        }
    });
    connect(btnCancel,&customToolButton::clicked,widgetAll,[=](){
        this->setEnabled(true);
        widgetAll->close();
        widgetAll->deleteLater();
    });
}

QByteArray ManagerPage::getSHA1(const QString& str)
{
    /*该结果的每个元素是8位十六进制数，也就是说一个元素是两个十六进制数组成。如果需要转成人能看懂的数据，把每个元素转成2个十六进制数即可*/
    QByteArray res = QCryptographicHash::hash(str.toLocal8Bit(), QCryptographicHash::Sha1);
    return res;
}

QVBoxLayout *ManagerPage::updateHouseInfo(QWidget *curPage, QString name,bool needInnerBtn,bool needUpdate)
{
    /*更新房屋信息*/
    QVBoxLayout* layout = new QVBoxLayout;
    database.connectDB("searchHouseForRemoveConnection");
    QString sql = "select * from house where name like '%%1%';";
    QList<QMap<QString,QString>> res = database.select(sql.arg(name));
    database.disconneectDB("searchHouseForRemoveConnection");
    for(auto& data:res)
    {
        for(int i=0;i<20;i++)
        {
            QString unit = "元/m²";
            if(data["type"]=="租房")
            {
                unit = "元/月";
            }
            QWidget* now = createBtn(curPage,data["id"].toUInt(),data["name"],data["price"]+unit,data["location"],data["area"]+"m²",
                    data["type"],data["floor"].toInt(),data["elevator"].toInt(),data["fitment"],needInnerBtn,needUpdate);
            now->setFixedHeight(200);
            now->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
            now->setStyleSheet("background-color:rgb(225,225,225);border-radius:10px;");
            layout->addWidget(now);
        }
    }
    return layout;
}

void ManagerPage::clearLayout(QWidget *widget)
{
    /*先判断布局是否为空*/
    if(widget->layout()==NULL)return;
    QLayout* layout = widget->layout();
    /*再依次删除布局中内容*/
    while(layout->count())
    {
        QWidget* now = layout->itemAt(0)->widget();
        /*老样子，删除前先判断是否为空*/
        if(now)
        {
            now->setParent(NULL);
            layout->removeWidget(now);
            delete now;
        }
    }
    /*最后删除布局*/
    delete layout;
}
QWidget *ManagerPage::createBtn(QWidget* curPage,int houseID,QString name,QString price,QString location,QString area,
                               QString type,int floor,bool elevator,QString fitment,bool needInnerBtn,bool needUpdate)
{
    /*创建房屋基本信息文本*/
    QLabel* labelName = new QLabel(name);
    labelName->setStyleSheet("font: 20pt \"方正粗黑宋简体\";");
    labelName->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QLabel* labelPrice = new QLabel(price);
    labelPrice->setStyleSheet("font: 15pt \"方正粗黑宋简体\";color:red;");
    labelPrice->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QLabel* labelLocation= new QLabel(location);
    labelLocation->setStyleSheet("font: 10pt \"方正粗黑宋简体\";");
    labelLocation->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QLabel* labelArea = new QLabel(area);
    labelArea->setStyleSheet("font: 10pt \"方正粗黑宋简体\";");
    labelArea->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    /*添加文本布局*/
    QVBoxLayout* layoutText = new QVBoxLayout;
    layoutText->addWidget(labelName);
    layoutText->addWidget(labelPrice);
    layoutText->addWidget(labelLocation);
    layoutText->addWidget(labelArea);
    /*把布局应用到到Widget中*/
    QWidget* widgetText = new QWidget;
    widgetText->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    widgetText->setLayout(layoutText);
    /*创建房屋特色文本*/
    QLabel* labelFloor = new QLabel;
    labelFloor->setText(QString("楼层:").append(QString::number(floor)));
    labelFloor->setStyleSheet("font: 10pt \"方正粗黑宋简体\";");
    labelFloor->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QLabel* labelElevator = new QLabel;
    labelElevator->setText(QString("电梯:").append(elevator==true?"有":"无"));
    labelElevator->setStyleSheet("font: 10pt \"方正粗黑宋简体\";color:red;");
    labelElevator->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QLabel* labelFitment = new QLabel(fitment);
    labelFitment->setText(QString("装修风格:").append(fitment));
    labelFitment->setStyleSheet("font: 10pt \"方正粗黑宋简体\";");
    labelFitment->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    /*设置特色文本布局*/
    QVBoxLayout * layoutFeature = new QVBoxLayout;
    layoutFeature->addWidget(labelFloor);
    layoutFeature->addWidget(labelElevator);
    layoutFeature->addWidget(labelFitment);
    /*将特色文本用一个组合框框起来*/
    QGroupBox * group = new QGroupBox;
    group->setTitle("特色:");
    group->setStyleSheet("font: 15pt \"方正粗黑宋简体\";margin-top:20px;");
    group->setLayout(layoutFeature);
    group->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    /*创建按钮*/
    customToolButton* btnRemove;
    if(needInnerBtn)
    {
        btnRemove = new customToolButton;
        btnRemove->init(":/Image/cancel.svg",QSize(100,100));
        btnRemove->setFixedSize(QSize(100,100));
        connect(btnRemove,&customToolButton::clicked,this,[=](){
            QMessageBox* confirmRemove = new QMessageBox(this);
            confirmRemove->setWindowTitle("");
            QString str = "删除";
            if(needUpdate)
            {
                str="修改";
            }
            confirmRemove->setText("确认"+str+"该房屋信息?");
            confirmRemove->setStandardButtons(QMessageBox::Yes|QMessageBox::No);
            confirmRemove->setDefaultButton(QMessageBox::No);
            confirmRemove->setButtonText(QMessageBox::Yes,"是,我想"+str);
            confirmRemove->setButtonText(QMessageBox::No,"不，我再想想");
            confirmRemove->setStyleSheet("QLabel{min-width: 200px;min-height: 50px;border-radius:10px;font: 10pt \"方正粗黑宋简体\";}");
            int ret = confirmRemove->exec();
            switch (ret) {
                case QMessageBox::Yes:{
                    /*连接数据库*/
                    database.connectDB("transactionRemoveHouse");
                    /*执行sql语句*/
                    QString sql = "delete from house where id = %1;";
                    if(!database.update(sql.arg(houseID)))
                    {
                        QMessageBox* hint = new QMessageBox(confirmRemove);
                        hint->setWindowIcon(QIcon(":/Image/error.svg"));
                        hint->setWindowTitle("错误");
                        hint->setText("哎呀,出错啦!");
                        hint->setStandardButtons(QMessageBox::Close);
                        hint->setButtonText(QMessageBox::Close,"关闭此页面");
                        hint->setStyleSheet("QLabel{min-width: 200px;min-height: 50px;border-radius:10px;font: 10pt \"方正粗黑宋简体\";}");
                        int ans = hint->exec();
                        switch (ans) {
                            case QMessageBox::Close:{
                                hint->close();
                                confirmRemove->close();
                            }
                        }
                    }
                    else
                    {
                        if(!needUpdate)
                        {
                            QMessageBox* hint = new QMessageBox(confirmRemove);
                            hint->setWindowIcon(QIcon(":/Image/thanks.svg"));
                            hint->setText(str+"成功!");
                            hint->setStandardButtons(QMessageBox::Close);
                            hint->setButtonText(QMessageBox::Close,"关闭此页面");
                            hint->setStyleSheet("QLabel{min-width: 200px;min-height: 50px;border-radius:10px;font: 10pt \"方正粗黑宋简体\";}");
                            int ans = hint->exec();
                            switch (ans) {
                                case QMessageBox::Close:{
                                    hint->close();
                                    confirmRemove->close();
                                }
                            }
                        }
                        else
                        {
                            mainPage->setCurrentWidget(addPage);
                        }
                    }
                    /*更新当前新的页面*/
                    clearLayout(curPage);
                    curPage->setLayout(updateHouseInfo(curPage,type,needInnerBtn,needUpdate));
                    /*关闭数据库*/
                    database.disconneectDB("transactionRemoveHouse");
                    break;
                }
            case QMessageBox::No:{
                    confirmRemove->close();
                    break;
                }
            }
        });
    }
    /*将房屋基本信息、按钮和特色信息一起设置水平布局*/
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(widgetText);
    layout->addWidget(group);
    if(needInnerBtn)
    {
        layout->addWidget(btnRemove);
    }
    /*把布局应用到一个总的Widget中*/
    QWidget* ans = new QWidget;
    widgetText->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    ans->setLayout(layout);
    return ans;
}

void ManagerPage::openInitPage()
{
    emit callInitPage();
}
