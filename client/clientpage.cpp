#include "clientpage.h"
#include "ui_clientpage.h"

ClientPage::ClientPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientPage)
{
    ui->setupUi(this);
    /*居中显示页面*/
    this->move((QApplication::desktop()->width() - width())/2,(QApplication::desktop()->height() -height())/5);
}

ClientPage::~ClientPage()
{
    delete ui;
}

void ClientPage::init()
{
    /*设置顶格图标和文字*/
    initTitle();
    /*设置图标*/
    initIcon();
    /*初始化地图*/
    initMap();
    /*初始化房贷计算器*/
    initCalculater();
    /*初始化直播看房*/
    initLive();
    /*初始化谷歌地图*/
    initMarket();
    /*初始化装修案例*/
    initFitmentEG();
    /*初始化找经纪人*/
    initAgent();
    /*初始化用户个人界面*/
    initClient();
    /*初始化设置界面*/
    initSetting();
    /*初始化搜索页面*/
    initSearch();
}

QWidget *ClientPage::createBtn(QWidget* curPage,int houseID,QString name,QString price,QString location,QString area,QString imgPath,
                               QString type,int floor,bool elevator,QString fitment)
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
    /*创建图片按钮*/
    customToolButton* btnImg = new customToolButton;
    btnImg->init(imgPath,QSize(180,180));
    btnImg->setFixedSize(180,180);
    connect(btnImg,&customToolButton::clicked,this,[=](){
       /*图片按钮槽函数*/
    });
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
    /*创建购买按钮*/
    customToolButton* btnBuy = new customToolButton;
    btnBuy->init(":/Image/buyhouse.svg",QSize(100,100));
    btnBuy->setFixedSize(QSize(100,100));
    connect(btnBuy,&customToolButton::clicked,this,[=](){
        QMessageBox* confirmBuy = new QMessageBox(this);
        confirmBuy->setWindowTitle("购买界面");
        confirmBuy->setText("该房屋暂时没有被购买");
        confirmBuy->setInformativeText("确认购买此房屋？");
        confirmBuy->setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        confirmBuy->setDefaultButton(QMessageBox::No);
        confirmBuy->setButtonText(QMessageBox::Yes,"是,我想购买");
        confirmBuy->setButtonText(QMessageBox::No,"不，我再想想");
        confirmBuy->setStyleSheet("QLabel{min-width: 200px;min-height: 50px;border-radius:10px;font: 10pt \"方正粗黑宋简体\";}");
        int ret = confirmBuy->exec();
        switch (ret) {
            case QMessageBox::Yes:{
                /*连接数据库*/
                database.connectDB("transactionBuyHouse");
                /*执行sql语句*/
                QString sql = "update house set client_account = %1,sold = true where id = %2;";
                if(!database.update(sql.arg(clientID).arg(houseID)))
                {
                    QMessageBox* hint = new QMessageBox(confirmBuy);
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
                            confirmBuy->close();
                        }
                    }
                }
                else
                {
                    QMessageBox* hint = new QMessageBox(confirmBuy);
                    hint->setWindowIcon(QIcon(":/Image/thanks.svg"));
                    hint->setWindowTitle("买卖成功");
                    hint->setText("恭喜你，交易成功！");
                    hint->setStandardButtons(QMessageBox::Close);
                    hint->setButtonText(QMessageBox::Close,"关闭此页面");
                    hint->setStyleSheet("QLabel{min-width: 200px;min-height: 50px;border-radius:10px;font: 10pt \"方正粗黑宋简体\";}");
                    int ans = hint->exec();
                    switch (ans) {
                        case QMessageBox::Close:{
                            hint->close();
                            confirmBuy->close();
                        }
                    }
                }
                /*更新当前新的页面*/
                clearLayout(curPage);
                curPage->setLayout(updateHouseInfo(curPage,type));
                /*关闭数据库*/
                database.disconneectDB("transactionBuyHouse");
                break;
            }
        case QMessageBox::No:{
                confirmBuy->close();
                break;
            }
        }
    });
    /*将房屋基本信息、按钮和特色信息一起设置水平布局*/
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(btnImg);
    layout->addWidget(widgetText);
    layout->addWidget(group);
    layout->addWidget(btnBuy);
    /*把布局应用到一个总的Widget中*/
    QWidget* ans = new QWidget;
    widgetText->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    ans->setLayout(layout);
    return ans;
}

QVBoxLayout* ClientPage::updateHouseInfo(QWidget* curPage,QString type)
{
    /*更新房屋信息*/
    QVBoxLayout* layout = new QVBoxLayout;
    database.connectDB("newHouseConnection");
    QString sql = "select * from house where type = '%1' and sold = false;";
    QList<QMap<QString,QString>> res = database.select(sql.arg(type));
    database.disconneectDB("newHouseConnection");
    for(auto& data:res)
    {
        for(int i=0;i<20;i++)
        {
            QString unit = "元/m²";
            if(type=="租房")
            {
                unit = "元/月";
            }
            QWidget* now = createBtn(curPage,data["id"].toUInt(),data["name"],data["price"]+unit,data["location"],data["area"]+"m²",":/Image/housePre.svg",
                    data["type"],data["floor"].toInt(),data["elevator"].toInt(),data["fitment"]);
            now->setFixedHeight(200);
            now->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
            now->setStyleSheet("background-color:rgb(225,225,225);border-radius:10px;");
            layout->addWidget(now);
        }
    }
    return layout;
}

QVBoxLayout *ClientPage::updateHouseInfo(QWidget *curPage, QString name,bool needInnerBtn)
{
    /*更新房屋信息*/
    QVBoxLayout* layout = new QVBoxLayout;
    database.connectDB("searchHouseClientConnection");
    QString sql = "select * from house where name like '%%1%' and sold = false;";
    QList<QMap<QString,QString>> res = database.select(sql.arg(name));
    database.disconneectDB("searchHouseClientConnection");
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
                    data["type"],data["floor"].toInt(),data["elevator"].toInt(),data["fitment"],needInnerBtn);
            now->setFixedHeight(200);
            now->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
            now->setStyleSheet("background-color:rgb(225,225,225);border-radius:10px;");
            layout->addWidget(now);
        }
    }
    return layout;
}

QWidget *ClientPage::createBtn(QWidget* curPage,int houseID,QString name,QString price,QString location,QString area,
                               QString type,int floor,bool elevator,QString fitment,bool needInnerBtn)
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
    /*创建购买按钮*/
    customToolButton* btnBuy = new customToolButton;
    btnBuy->init(":/Image/buyhouse.svg",QSize(100,100));
    btnBuy->setFixedSize(QSize(100,100));
    connect(btnBuy,&customToolButton::clicked,this,[=](){
        QMessageBox* confirmBuy = new QMessageBox(this);
        confirmBuy->setWindowTitle("购买界面");
        confirmBuy->setText("该房屋暂时没有被购买");
        confirmBuy->setInformativeText("确认购买此房屋？");
        confirmBuy->setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        confirmBuy->setDefaultButton(QMessageBox::No);
        confirmBuy->setButtonText(QMessageBox::Yes,"是,我想购买");
        confirmBuy->setButtonText(QMessageBox::No,"不，我再想想");
        confirmBuy->setStyleSheet("QLabel{min-width: 200px;min-height: 50px;border-radius:10px;font: 10pt \"方正粗黑宋简体\";}");
        int ret = confirmBuy->exec();
        switch (ret) {
            case QMessageBox::Yes:{
                /*连接数据库*/
                database.connectDB("transactionBuyHouse");
                /*执行sql语句*/
                QString sql = "update house set client_account = %1,sold = true where id = %2;";
                if(!database.update(sql.arg(clientID).arg(houseID)))
                {
                    QMessageBox* hint = new QMessageBox(confirmBuy);
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
                            confirmBuy->close();
                        }
                    }
                }
                else
                {
                    QMessageBox* hint = new QMessageBox(confirmBuy);
                    hint->setWindowIcon(QIcon(":/Image/thanks.svg"));
                    hint->setWindowTitle("买卖成功");
                    hint->setText("恭喜你，交易成功！");
                    hint->setStandardButtons(QMessageBox::Close);
                    hint->setButtonText(QMessageBox::Close,"关闭此页面");
                    hint->setStyleSheet("QLabel{min-width: 200px;min-height: 50px;border-radius:10px;font: 10pt \"方正粗黑宋简体\";}");
                    int ans = hint->exec();
                    switch (ans) {
                        case QMessageBox::Close:{
                            hint->close();
                            confirmBuy->close();
                        }
                    }
                }
                /*更新当前新的页面*/
                clearLayout(curPage);
                curPage->setLayout(updateHouseInfo(curPage,type));
                /*关闭数据库*/
                database.disconneectDB("transactionBuyHouse");
                break;
            }
        case QMessageBox::No:{
                confirmBuy->close();
                break;
            }
        }
    });
    /*将房屋基本信息、按钮和特色信息一起设置水平布局*/
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(widgetText);
    layout->addWidget(group);
    if(needInnerBtn)
    {
        layout->addWidget(btnBuy);
    }
    /*把布局应用到一个总的Widget中*/
    QWidget* ans = new QWidget;
    widgetText->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    ans->setLayout(layout);
    return ans;
}

void ClientPage::clearLayout(QWidget *widget)
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

void ClientPage::initTitle()
{
    this->setWindowTitle("海星找房");
    this->setWindowIcon(QIcon(":/Image/house.svg"));
    ui->stackedWidget_group1->setCurrentIndex(0);
    ui->widget_search->editor->setPlaceholderText("搜索您想要的房屋信息");
    ui->widget_search->editor->setMouseTracking(true);
}

void ClientPage::initIcon()
{
    ui->toolButton_home->init(":/Image/main_page.svg",QSize(70,70));
    ui->toolButton_newHouse->init(":/Image/house1.svg",QSize(55,55));
    ui->toolButton_secondaryHouse->init(":/Image/house2.svg",QSize(55,55));
    ui->toolButton_fitment->init(":/Image/house4.svg",QSize(55,55));
    ui->toolButton_rentHouse->init(":/Image/house3.svg",QSize(55,55));
    ui->toolButton_live->init(":/Image/live.svg",QSize(55,55));
    ui->toolButton_map->init(":/Image/map.svg",QSize(55,55));
    ui->toolButton_calculater->init(":/Image/calculater.svg",QSize(55,55));
    ui->toolButton_market->init(":/Image/map.svg",QSize(55,55));
    ui->toolButton_agent->init(":/Image/agent.svg",QSize(55,55));
    ui->toolButton_houseType->init(":/Image/house_type",QSize(55,55));
    ui->toolButton_fitmentEG->init(":/Image/fitment.svg",QSize(55,55));
    ui->toolButton_plot->init(":/Image/plot.svg",QSize(55,55));
    ui->toolButton_client->init(":/Image/head.svg",QSize(55,55));
    ui->toolButton_settings->init(":/Image/usersetting.svg",QSize(50,50));
    ui->toolButton_search->init(":/Image/search.svg",QSize(50,50));
}

void ClientPage::initMap()
{
    /*初始化js类*/
    QWebEngineView* webPageMap = new QWebEngineView;
    /*由于高德地图在这里调用的是本地HTML，所以这里忽略SSL连接错误并不会起作用*/
    webPageMap->setPage(new CustomWebEnginePage(this));
    QWebChannel* webChannel = new QWebChannel(this);
    customWeb* webBase = new customWeb(this);
    /*用来最终向JS注册想要交互的类"qtChannel"相当于一个标识，在js中就以此名称来代表这个类*/
    webChannel->registerObject("qtChannel",(QObject*)webBase);
    webPageMap->page()->setWebChannel(webChannel);
    webPageMap->load(QUrl("qrc:/html/myMap.html"));
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(webPageMap);
    ui->page_map->setLayout(layout);
}

void ClientPage::initCalculater()
{
    QWebEngineView* webPageCalculater = new QWebEngineView;
    webPageCalculater->setPage(new CustomWebEnginePage(this));
    webPageCalculater->load(QUrl("https://fangd.sinaapp.com/"));
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(webPageCalculater);
    ui->page_calculater->setLayout(layout);
}

void ClientPage::initLive()
{
    QWebEngineView* webPageLive = new QWebEngineView;
    //webPageLive->setPage(new CustomWebEnginePage);
    webPageLive->load(QUrl("https://live.leju.com/house/bj/"));
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(webPageLive);
    ui->page_live->setLayout(layout);
}

void ClientPage::initMarket()
{
    QWebEngineView* webPageLive = new QWebEngineView;
    //webPageLive->setPage(new CustomWebEnginePage);
    webPageLive->load(QUrl("https://www.google.com.hk/maps/?hl=zh-CN"));
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(webPageLive);
    ui->page_market->setLayout(layout);
}

void ClientPage::initFitmentEG()
{
    QWebEngineView* webPageLive = new QWebEngineView;
    //webPageLive->setPage(new CustomWebEnginePage);
    webPageLive->load(QUrl("https://www.to8to.com/"));
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(webPageLive);
    ui->page_fitmentEG->setLayout(layout);
}

void ClientPage::initAgent()
{
    QWebEngineView* webPageLive = new QWebEngineView;
    //webPageLive->setPage(new CustomWebEnginePage);
    webPageLive->load(QUrl("https://www.zhongjie.com/brokers"));
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(webPageLive);
    ui->page_agent->setLayout(layout);
}

void ClientPage::initClient()
{
    /*首先查询信息*/
    database.connectDB("queryClientInfo");
    QString sql = "select * from client where account = %1";
    QList<QMap<QString,QString>> res = database.select(sql.arg(clientID));
    QString name,sex,birth,level;
    for(auto & data : res)
    {
        name=data["name"];
        sex=data["sex"];
        birth=data["birthday"];
        level=data["level"];
    }
    database.disconneectDB("queryClientInfo");
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
        database.connectDB("updateClientInfo");
        QString sql = "update client set name='%1',sex='%2',birthday='%3' where account=%4;";
        if(database.update(sql.arg(textName->editor->text()).arg(textSex->editor->text()).arg(textBirth->editor->text()).arg(clientID)))
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
        database.disconneectDB("updateClientInfo");
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

    ui->page_client->setLayout(allLayout);
    ui->page_client->setStyleSheet("background-color:white;");
}

void ClientPage::initSetting()
{
    /*开始填充内容*/
    QPixmap bgImg(":/house/two.png");
    QLabel* labelBg = new QLabel;
    labelBg->setPixmap(bgImg);

    QLabel* labelAccount = new QLabel("账号:");
    labelAccount->setStyleSheet("font: 10pt \"方正粗黑宋简体\";");
    customInputText* textAccount = new customInputText;
    textAccount->setValue(QString::number(clientID));
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
    textPassword->editor->setPlaceholderText("输入原始密码");
    connect(textPassword->editor,&QLineEdit::textChanged,this,[=](){
        if(verifyPassword(textPassword->editor->text())&&textPassword->editor->text().size())
        {
            /*更新新密码*/
            updatePassword();
            textPassword->setEnabled(false);
            textPassword->editor->clear();
        }
    });
    customToolButton* btnEditPassword = new customToolButton;
    btnEditPassword->init(":/Image/edit.svg",QSize(55,55));
    btnEditPassword->setMinimumSize(QSize(60,60));
    connect(btnEditPassword,&customToolButton::clicked,this,[=](){
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
    connect(btnChange,&customToolButton::clicked,this,&ClientPage::openInitPage);
    QLabel* labelOut = new QLabel("退出当前账号");
    labelOut->setFixedHeight(20);
    labelOut->setStyleSheet("font: 9pt \"方正粗黑宋简体\";");
    customToolButton* btnOut = new customToolButton;
    btnOut->init(":/Image/out.svg",QSize(55,55));
    btnOut->setMinimumSize(QSize(60,60));
    connect(btnOut,&customToolButton::clicked,this,&ClientPage::openInitPage);
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

    ui->page_setting->setLayout(allLayout);
    ui->page_setting->setStyleSheet("background-color:white;");
}

void ClientPage::initSearch()
{
    QWidget* pageSearch = new QWidget;
    QScrollArea *scrollInfo = new QScrollArea(pageSearch);
    QWidget *scrollInfoContents = new QWidget(pageSearch); //滑动栏需要用单独的一个widget
    connect(ui->toolButton_search, &customToolButton::clicked, this, [=](){
            if(ui->widget_search->editor->text().size()==0)
            {
                return;
            }
            clearLayout(scrollInfoContents);
            QVBoxLayout* layoutScrollInfoContents = updateHouseInfo(scrollInfoContents,ui->widget_search->editor->text(),true);
            if(layoutScrollInfoContents->count()==0)
            {
                QLabel* labelHint = new QLabel("没有查询到相关的房屋信息!");
                labelHint->setStyleSheet("font: 15pt \"方正粗黑宋简体\";");
                labelHint->setAlignment(Qt::AlignCenter);
                labelHint->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
                layoutScrollInfoContents->addWidget(labelHint);
            }
            scrollInfoContents->setLayout(layoutScrollInfoContents);
            scrollInfo->setWidget(scrollInfoContents);
            scrollInfo->setWidgetResizable(true);//打开滑动条
            scrollInfo->move(0,this->height());
            scrollInfo->resize(pageSearch->size());//重复设置大小为全局大小
            /*查询栏滑动特效*/
            /*只能在图形绘制完成之后，geometry可以获取到布局内控件的位置*/
            QPropertyAnimation* aniScrollArea = new QPropertyAnimation(scrollInfo,"geometry",pageSearch);
            aniScrollArea->setStartValue(scrollInfo->geometry());
            aniScrollArea->setEndValue(QRectF(scrollInfo->x(),0,scrollInfo->width(),scrollInfo->height()));
            aniScrollArea->setDuration(1000);
            aniScrollArea->setEasingCurve(QEasingCurve::InOutExpo);
            aniScrollArea->start();
    });
    scrollInfo->move(0, this->height());
    scrollInfo->setStyleSheet("border:none;");
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(pageSearch);
    ui->page_search->setLayout(layout);
    ui->page_search->setStyleSheet("background-color:white;");
}

bool ClientPage::verifyPassword(const QString& curPassword)
{
    database.connectDB("verifyClientPasssword");
    QString sql = "select password from client where account=%1";
    QList<QMap<QString,QString>> res=database.select(sql.arg(clientID));
    auto data = *res.begin();
    QString oldSHA1 = data["password"];
    QString newSHA1 = getSHA1(curPassword);
    bool flag=false;
    if(oldSHA1==newSHA1)
    {
        flag=true;
    }
    database.disconneectDB("verifyClientPassword");
    return flag;
}

void ClientPage::updatePassword()
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
    widgetAll->show();
    textPassword->enterEditEffect();
    connect(btnConfirm,&customToolButton::clicked,widgetAll,[=](){
        if(textPassword->editor->text().size()==0||textConfirm->editor->text().size()==0)
        {
            QMessageBox::information(widgetAll,"","请先输入新密码",QMessageBox::Close);
        }
        else if(textPassword->editor->text()==textConfirm->editor->text())
        {
            database.connectDB("updateClientPassword");
            QString sql = "update client set password='%1' where account=%2";
            if(database.update(sql.arg(QString(getSHA1(textPassword->editor->text()))).arg(clientID)))
            {
                QMessageBox::information(this,"","更新密码成功!",QMessageBox::Close);
            }
            else
            {
                QMessageBox::information(this,"","哎呀,出错了!",QMessageBox::Close);
            }
            database.disconneectDB("updateClientPassword");
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

QByteArray ClientPage::getSHA1(const QString& str)
{
    /*该结果的每个元素是8位十六进制数，也就是说一个元素是两个十六进制数组成。如果需要转成人能看懂的数据，把每个元素转成2个十六进制数即可*/
    QByteArray res = QCryptographicHash::hash(str.toLocal8Bit(), QCryptographicHash::Sha1);
    return res;
}

void ClientPage::openInitPage()
{
    emit callInitPage();
}

void ClientPage::on_toolButton_home_clicked()
{
    ui->stackedWidget_group1->setCurrentIndex(0);
}

void ClientPage::on_toolButton_newHouse_clicked()
{
    /*去背景*/
    ui->stackedWidget_group1->setStyleSheet("background-color:transparent;");
    /*去边框*/
    ui->scrollArea_newHouse->setStyleSheet("background-color:transparent;border:none;");
    /*删除原有布局*/
    clearLayout(ui->SAWC_newHouse);
    /*添加新内容*/
    ui->SAWC_newHouse->setLayout(updateHouseInfo(ui->SAWC_newHouse,"新房"));
    /*最后设置显示的页面*/
    ui->stackedWidget_group1->setCurrentIndex(1);
}

void ClientPage::on_toolButton_secondaryHouse_clicked()
{
    ui->stackedWidget_group1->setStyleSheet("background-color:transparent;");
    ui->scrollArea_secondaryHouse->setStyleSheet("background-color:transparent;border:none;");
    clearLayout(ui->SAWC_secondaryHouse);
    ui->SAWC_secondaryHouse->setLayout(updateHouseInfo(ui->SAWC_secondaryHouse,"二手房"));
    ui->stackedWidget_group1->setCurrentIndex(2);
}
void ClientPage::on_toolButton_fitment_clicked()
{
    ui->stackedWidget_group1->setCurrentIndex(3);
}

void ClientPage::on_toolButton_rentHouse_clicked()
{
    ui->stackedWidget_group1->setStyleSheet("background-color:transparent;");
    ui->scrollArea_rentHouse->setStyleSheet("background-color:transparent;border:none;");
    clearLayout(ui->SAWC_rentHouse);
    ui->SAWC_rentHouse->setLayout(updateHouseInfo(ui->SAWC_rentHouse,"租房"));
    ui->stackedWidget_group1->setCurrentIndex(4);
}

void ClientPage::on_toolButton_map_clicked()
{
    /**QWebEngineView使用方法：只需要拖一个Qwidget，然后提升为QWebEngineView，然后直接通过ui引用加载资源或者网址
     * 引用资源的load和setUrl两个方法都可以用
     * 引用html资源的时候，必须要加qrc,必须要加!!!*/
    ui->stackedWidget_group1->setCurrentIndex(5);
}

void ClientPage::on_toolButton_calculater_clicked()
{
    ui->stackedWidget_group1->setCurrentIndex(6);
}

void ClientPage::on_toolButton_live_clicked()
{
    ui->stackedWidget_group1->setCurrentIndex(7);
}

void ClientPage::on_toolButton_market_clicked()
{
    ui->stackedWidget_group1->setCurrentIndex(8);
}

void ClientPage::on_toolButton_fitmentEG_clicked()
{
    ui->stackedWidget_group1->setCurrentIndex(9);
}

void ClientPage::on_toolButton_agent_clicked()
{
    ui->stackedWidget_group1->setCurrentIndex(10);
}

void ClientPage::on_toolButton_client_clicked()
{
    ui->stackedWidget_group1->setCurrentIndex(11);
}

void ClientPage::on_toolButton_settings_clicked()
{
    ui->stackedWidget_group1->setCurrentIndex(12);
}

void ClientPage::on_toolButton_search_clicked()
{
    ui->stackedWidget_group1->setCurrentIndex(13);
}
