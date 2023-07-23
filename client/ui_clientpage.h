/********************************************************************************
** Form generated from reading UI file 'clientpage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTPAGE_H
#define UI_CLIENTPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <custominputtext.h>
#include <customtoolbutton.h>

QT_BEGIN_NAMESPACE

class Ui_ClientPage
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    customToolButton *toolButton_home;
    QSpacerItem *horizontalSpacer;
    customInputText *widget_search;
    customToolButton *toolButton_search;
    QSpacerItem *horizontalSpacer_2;
    customToolButton *toolButton_client;
    QSpacerItem *horizontalSpacer_3;
    customToolButton *toolButton_settings;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_9;
    QVBoxLayout *verticalLayout_7;
    customToolButton *toolButton_newHouse;
    QLabel *label_4;
    QFrame *frame_8;
    QVBoxLayout *verticalLayout_6;
    customToolButton *toolButton_secondaryHouse;
    QLabel *label_3;
    QFrame *frame_7;
    QVBoxLayout *verticalLayout_3;
    customToolButton *toolButton_rentHouse;
    QLabel *label_5;
    QFrame *frame_10;
    QVBoxLayout *verticalLayout_8;
    customToolButton *toolButton_fitment;
    QLabel *label;
    QFrame *frame_4;
    QGridLayout *gridLayout;
    QFrame *frame_18;
    QVBoxLayout *verticalLayout_16;
    customToolButton *toolButton_plot;
    QLabel *label_13;
    QFrame *frame_11;
    QVBoxLayout *verticalLayout_9;
    customToolButton *toolButton_live;
    QLabel *label_6;
    QFrame *frame_15;
    QVBoxLayout *verticalLayout_13;
    customToolButton *toolButton_agent;
    QLabel *label_10;
    QFrame *frame_16;
    QVBoxLayout *verticalLayout_14;
    customToolButton *toolButton_houseType;
    QLabel *label_11;
    QFrame *frame_12;
    QVBoxLayout *verticalLayout_10;
    customToolButton *toolButton_map;
    QLabel *label_7;
    QFrame *frame_14;
    QVBoxLayout *verticalLayout_12;
    customToolButton *toolButton_market;
    QLabel *label_9;
    QFrame *frame_13;
    QVBoxLayout *verticalLayout_11;
    customToolButton *toolButton_calculater;
    QLabel *label_8;
    QFrame *frame_17;
    QVBoxLayout *verticalLayout_15;
    customToolButton *toolButton_fitmentEG;
    QLabel *label_12;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget_group1;
    QWidget *page_home;
    QWidget *page_newHouse;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea_newHouse;
    QWidget *SAWC_newHouse;
    QWidget *page_secondaryHouse;
    QGridLayout *gridLayout_4;
    QScrollArea *scrollArea_secondaryHouse;
    QWidget *SAWC_secondaryHouse;
    QWidget *page_fitment;
    QGridLayout *gridLayout_5;
    QScrollArea *scrollArea_fitment;
    QWidget *SAWC_fitment;
    QWidget *page_rentHouse;
    QGridLayout *gridLayout_6;
    QScrollArea *scrollArea_rentHouse;
    QWidget *SAWC_rentHouse;
    QWidget *page_map;
    QWidget *page_calculater;
    QWidget *page_live;
    QWidget *page_market;
    QWidget *page_fitmentEG;
    QWidget *page_agent;
    QWidget *page_client;
    QWidget *widget_client;
    QWidget *page_setting;
    QWidget *widget_setting;
    QWidget *page_search;

    void setupUi(QWidget *ClientPage)
    {
        if (ClientPage->objectName().isEmpty())
            ClientPage->setObjectName(QString::fromUtf8("ClientPage"));
        ClientPage->resize(1553, 954);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ClientPage->sizePolicy().hasHeightForWidth());
        ClientPage->setSizePolicy(sizePolicy);
        ClientPage->setMinimumSize(QSize(0, 0));
        ClientPage->setMaximumSize(QSize(16777215, 16777215));
        ClientPage->setAutoFillBackground(false);
        ClientPage->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(ClientPage);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_5 = new QFrame(ClientPage);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        sizePolicy.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy);
        frame_5->setStyleSheet(QString::fromUtf8("#frame_5{border-image: url(:/Image/background.jpg);}\n"
""));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        frame_3 = new QFrame(frame_5);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy1);
        frame_3->setMinimumSize(QSize(0, 50));
        frame_3->setMaximumSize(QSize(16777215, 50));
        frame_3->setStyleSheet(QString::fromUtf8("#Frame{border-image: url(:/Image/background.jpg);}\n"
""));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButton_home = new customToolButton(frame_3);
        toolButton_home->setObjectName(QString::fromUtf8("toolButton_home"));
        toolButton_home->setMinimumSize(QSize(0, 50));
        toolButton_home->setMaximumSize(QSize(16777215, 50));
        toolButton_home->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"background-color:transparent;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/main_page.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_home->setIcon(icon);
        toolButton_home->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(toolButton_home);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widget_search = new customInputText(frame_3);
        widget_search->setObjectName(QString::fromUtf8("widget_search"));

        horizontalLayout_2->addWidget(widget_search);

        toolButton_search = new customToolButton(frame_3);
        toolButton_search->setObjectName(QString::fromUtf8("toolButton_search"));
        toolButton_search->setMinimumSize(QSize(100, 50));
        toolButton_search->setMaximumSize(QSize(100, 50));
        toolButton_search->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"background-color:transparent;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Image/search.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_search->setIcon(icon1);
        toolButton_search->setIconSize(QSize(40, 40));
        toolButton_search->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton_search);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        toolButton_client = new customToolButton(frame_3);
        toolButton_client->setObjectName(QString::fromUtf8("toolButton_client"));
        sizePolicy1.setHeightForWidth(toolButton_client->sizePolicy().hasHeightForWidth());
        toolButton_client->setSizePolicy(sizePolicy1);
        toolButton_client->setMinimumSize(QSize(100, 50));
        toolButton_client->setMaximumSize(QSize(100, 50));
        toolButton_client->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"background-color:transparent;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Image/head.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_client->setIcon(icon2);
        toolButton_client->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(toolButton_client);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        toolButton_settings = new customToolButton(frame_3);
        toolButton_settings->setObjectName(QString::fromUtf8("toolButton_settings"));
        sizePolicy1.setHeightForWidth(toolButton_settings->sizePolicy().hasHeightForWidth());
        toolButton_settings->setSizePolicy(sizePolicy1);
        toolButton_settings->setMinimumSize(QSize(100, 50));
        toolButton_settings->setMaximumSize(QSize(100, 50));
        toolButton_settings->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"font: 10pt \"\346\226\271\346\255\243\350\210\222\344\275\223\";\n"
"background-color:transparent;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Image/usersetting.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_settings->setIcon(icon3);
        toolButton_settings->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(toolButton_settings);


        verticalLayout_4->addWidget(frame_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(frame_5);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(2);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(frame);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setAutoFillBackground(false);
        scrollArea->setStyleSheet(QString::fromUtf8("QScollArea{background-color:rgb(45, 255, 255);\n"
"border-radius:15px;}"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setLineWidth(1);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 434, 876));
        scrollAreaWidgetContents_3->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border-radius:15px;"));
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        frame_6 = new QFrame(scrollAreaWidgetContents_3);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        sizePolicy1.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy1);
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_6);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_9 = new QFrame(frame_6);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_9);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        toolButton_newHouse = new customToolButton(frame_9);
        toolButton_newHouse->setObjectName(QString::fromUtf8("toolButton_newHouse"));
        sizePolicy.setHeightForWidth(toolButton_newHouse->sizePolicy().hasHeightForWidth());
        toolButton_newHouse->setSizePolicy(sizePolicy);
        toolButton_newHouse->setMinimumSize(QSize(0, 70));
        toolButton_newHouse->setMaximumSize(QSize(16777215, 16777215));
        toolButton_newHouse->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"font: 14pt \"\345\215\216\346\226\207\346\226\260\351\255\217\";\n"
"background-color:transparent;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Image/house1.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_newHouse->setIcon(icon4);
        toolButton_newHouse->setIconSize(QSize(50, 50));

        verticalLayout_7->addWidget(toolButton_newHouse);

        label_4 = new QLabel(frame_9);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);
        label_4->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223\";"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_4);


        horizontalLayout_3->addWidget(frame_9);

        frame_8 = new QFrame(frame_6);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_8);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        toolButton_secondaryHouse = new customToolButton(frame_8);
        toolButton_secondaryHouse->setObjectName(QString::fromUtf8("toolButton_secondaryHouse"));
        sizePolicy.setHeightForWidth(toolButton_secondaryHouse->sizePolicy().hasHeightForWidth());
        toolButton_secondaryHouse->setSizePolicy(sizePolicy);
        toolButton_secondaryHouse->setMinimumSize(QSize(0, 70));
        toolButton_secondaryHouse->setMaximumSize(QSize(16777215, 16777215));
        toolButton_secondaryHouse->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"font: 14pt \"\345\215\216\346\226\207\346\226\260\351\255\217\";\n"
"background-color:transparent;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Image/house2.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_secondaryHouse->setIcon(icon5);
        toolButton_secondaryHouse->setIconSize(QSize(50, 50));

        verticalLayout_6->addWidget(toolButton_secondaryHouse);

        label_3 = new QLabel(frame_8);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223\";"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_3);


        horizontalLayout_3->addWidget(frame_8);

        frame_7 = new QFrame(frame_6);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_7);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        toolButton_rentHouse = new customToolButton(frame_7);
        toolButton_rentHouse->setObjectName(QString::fromUtf8("toolButton_rentHouse"));
        sizePolicy1.setHeightForWidth(toolButton_rentHouse->sizePolicy().hasHeightForWidth());
        toolButton_rentHouse->setSizePolicy(sizePolicy1);
        toolButton_rentHouse->setMinimumSize(QSize(0, 70));
        toolButton_rentHouse->setMaximumSize(QSize(16777215, 70));
        toolButton_rentHouse->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"font: 14pt \"\345\215\216\346\226\207\346\226\260\351\255\217\";\n"
"background-color:transparent;"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Image/house3.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_rentHouse->setIcon(icon6);
        toolButton_rentHouse->setIconSize(QSize(50, 50));

        verticalLayout_3->addWidget(toolButton_rentHouse);

        label_5 = new QLabel(frame_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223\";"));
        label_5->setScaledContents(false);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_5);


        horizontalLayout_3->addWidget(frame_7);

        frame_10 = new QFrame(frame_6);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame_10);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        toolButton_fitment = new customToolButton(frame_10);
        toolButton_fitment->setObjectName(QString::fromUtf8("toolButton_fitment"));
        sizePolicy1.setHeightForWidth(toolButton_fitment->sizePolicy().hasHeightForWidth());
        toolButton_fitment->setSizePolicy(sizePolicy1);
        toolButton_fitment->setMinimumSize(QSize(0, 70));
        toolButton_fitment->setMaximumSize(QSize(16777215, 70));
        toolButton_fitment->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"font: 14pt \"\345\215\216\346\226\207\346\226\260\351\255\217\";\n"
"background-color:transparent;"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Image/house4.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_fitment->setIcon(icon7);
        toolButton_fitment->setIconSize(QSize(50, 50));

        verticalLayout_8->addWidget(toolButton_fitment);

        label = new QLabel(frame_10);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223\";"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label);


        horizontalLayout_3->addWidget(frame_10);


        verticalLayout_5->addWidget(frame_6);

        frame_4 = new QFrame(scrollAreaWidgetContents_3);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border-radius:15px;"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame_18 = new QFrame(frame_4);
        frame_18->setObjectName(QString::fromUtf8("frame_18"));
        frame_18->setFrameShape(QFrame::StyledPanel);
        frame_18->setFrameShadow(QFrame::Raised);
        verticalLayout_16 = new QVBoxLayout(frame_18);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        toolButton_plot = new customToolButton(frame_18);
        toolButton_plot->setObjectName(QString::fromUtf8("toolButton_plot"));
        sizePolicy1.setHeightForWidth(toolButton_plot->sizePolicy().hasHeightForWidth());
        toolButton_plot->setSizePolicy(sizePolicy1);
        toolButton_plot->setMinimumSize(QSize(0, 70));
        toolButton_plot->setMaximumSize(QSize(16777215, 70));
        toolButton_plot->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"font: 14pt \"\345\215\216\346\226\207\346\226\260\351\255\217\";\n"
"background-color:transparent;"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Image/plot.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_plot->setIcon(icon8);
        toolButton_plot->setIconSize(QSize(50, 50));

        verticalLayout_16->addWidget(toolButton_plot);

        label_13 = new QLabel(frame_18);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy3.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy3);
        label_13->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223\";"));
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(label_13);


        gridLayout->addWidget(frame_18, 3, 1, 1, 1);

        frame_11 = new QFrame(frame_4);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frame_11->sizePolicy().hasHeightForWidth());
        frame_11->setSizePolicy(sizePolicy4);
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        verticalLayout_9 = new QVBoxLayout(frame_11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        toolButton_live = new customToolButton(frame_11);
        toolButton_live->setObjectName(QString::fromUtf8("toolButton_live"));
        sizePolicy.setHeightForWidth(toolButton_live->sizePolicy().hasHeightForWidth());
        toolButton_live->setSizePolicy(sizePolicy);
        toolButton_live->setMinimumSize(QSize(0, 70));
        toolButton_live->setMaximumSize(QSize(16777215, 70));
        toolButton_live->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"font: 14pt \"\345\215\216\346\226\207\346\226\260\351\255\217\";\n"
"background-color:transparent;"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Image/live.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_live->setIcon(icon9);
        toolButton_live->setIconSize(QSize(50, 50));

        verticalLayout_9->addWidget(toolButton_live);

        label_6 = new QLabel(frame_11);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(0, 0));
        label_6->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223\";"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_6);


        gridLayout->addWidget(frame_11, 0, 0, 1, 1);

        frame_15 = new QFrame(frame_4);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        sizePolicy4.setHeightForWidth(frame_15->sizePolicy().hasHeightForWidth());
        frame_15->setSizePolicy(sizePolicy4);
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);
        verticalLayout_13 = new QVBoxLayout(frame_15);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        toolButton_agent = new customToolButton(frame_15);
        toolButton_agent->setObjectName(QString::fromUtf8("toolButton_agent"));
        sizePolicy1.setHeightForWidth(toolButton_agent->sizePolicy().hasHeightForWidth());
        toolButton_agent->setSizePolicy(sizePolicy1);
        toolButton_agent->setMinimumSize(QSize(0, 70));
        toolButton_agent->setMaximumSize(QSize(16777215, 70));
        toolButton_agent->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"font: 14pt \"\345\215\216\346\226\207\346\226\260\351\255\217\";\n"
"background-color:transparent;"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Image/agent.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_agent->setIcon(icon10);
        toolButton_agent->setIconSize(QSize(50, 50));

        verticalLayout_13->addWidget(toolButton_agent);

        label_10 = new QLabel(frame_15);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy3.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy3);
        label_10->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223\";"));
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_13->addWidget(label_10);


        gridLayout->addWidget(frame_15, 2, 0, 1, 1);

        frame_16 = new QFrame(frame_4);
        frame_16->setObjectName(QString::fromUtf8("frame_16"));
        frame_16->setFrameShape(QFrame::StyledPanel);
        frame_16->setFrameShadow(QFrame::Raised);
        verticalLayout_14 = new QVBoxLayout(frame_16);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        toolButton_houseType = new customToolButton(frame_16);
        toolButton_houseType->setObjectName(QString::fromUtf8("toolButton_houseType"));
        sizePolicy1.setHeightForWidth(toolButton_houseType->sizePolicy().hasHeightForWidth());
        toolButton_houseType->setSizePolicy(sizePolicy1);
        toolButton_houseType->setMinimumSize(QSize(0, 70));
        toolButton_houseType->setMaximumSize(QSize(16777215, 70));
        toolButton_houseType->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"font: 14pt \"\345\215\216\346\226\207\346\226\260\351\255\217\";\n"
"background-color:transparent;"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Image/house_type.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_houseType->setIcon(icon11);
        toolButton_houseType->setIconSize(QSize(50, 50));

        verticalLayout_14->addWidget(toolButton_houseType);

        label_11 = new QLabel(frame_16);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy3.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy3);
        label_11->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223\";"));
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_14->addWidget(label_11);


        gridLayout->addWidget(frame_16, 2, 1, 1, 1);

        frame_12 = new QFrame(frame_4);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        verticalLayout_10 = new QVBoxLayout(frame_12);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        toolButton_map = new customToolButton(frame_12);
        toolButton_map->setObjectName(QString::fromUtf8("toolButton_map"));
        sizePolicy1.setHeightForWidth(toolButton_map->sizePolicy().hasHeightForWidth());
        toolButton_map->setSizePolicy(sizePolicy1);
        toolButton_map->setMinimumSize(QSize(0, 70));
        toolButton_map->setMaximumSize(QSize(16777215, 70));
        toolButton_map->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"font: 14pt \"\345\215\216\346\226\207\346\226\260\351\255\217\";\n"
"background-color:transparent;"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Image/map.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_map->setIcon(icon12);
        toolButton_map->setIconSize(QSize(50, 50));

        verticalLayout_10->addWidget(toolButton_map);

        label_7 = new QLabel(frame_12);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223\";"));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_7);


        gridLayout->addWidget(frame_12, 0, 1, 1, 1);

        frame_14 = new QFrame(frame_4);
        frame_14->setObjectName(QString::fromUtf8("frame_14"));
        frame_14->setFrameShape(QFrame::StyledPanel);
        frame_14->setFrameShadow(QFrame::Raised);
        verticalLayout_12 = new QVBoxLayout(frame_14);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        toolButton_market = new customToolButton(frame_14);
        toolButton_market->setObjectName(QString::fromUtf8("toolButton_market"));
        sizePolicy1.setHeightForWidth(toolButton_market->sizePolicy().hasHeightForWidth());
        toolButton_market->setSizePolicy(sizePolicy1);
        toolButton_market->setMinimumSize(QSize(0, 70));
        toolButton_market->setMaximumSize(QSize(16777215, 70));
        toolButton_market->setToolTipDuration(500);
        toolButton_market->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"font: 14pt \"\345\215\216\346\226\207\346\226\260\351\255\217\";\n"
"background-color:transparent;"));
        toolButton_market->setIcon(icon12);
        toolButton_market->setIconSize(QSize(50, 50));

        verticalLayout_12->addWidget(toolButton_market);

        label_9 = new QLabel(frame_14);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy3.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy3);
        label_9->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223\";"));
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(label_9);


        gridLayout->addWidget(frame_14, 1, 1, 1, 1);

        frame_13 = new QFrame(frame_4);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        sizePolicy4.setHeightForWidth(frame_13->sizePolicy().hasHeightForWidth());
        frame_13->setSizePolicy(sizePolicy4);
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        verticalLayout_11 = new QVBoxLayout(frame_13);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        toolButton_calculater = new customToolButton(frame_13);
        toolButton_calculater->setObjectName(QString::fromUtf8("toolButton_calculater"));
        sizePolicy1.setHeightForWidth(toolButton_calculater->sizePolicy().hasHeightForWidth());
        toolButton_calculater->setSizePolicy(sizePolicy1);
        toolButton_calculater->setMinimumSize(QSize(0, 70));
        toolButton_calculater->setMaximumSize(QSize(16777215, 70));
        toolButton_calculater->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"font: 14pt \"\345\215\216\346\226\207\346\226\260\351\255\217\";\n"
"background-color:transparent;"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/Image/calculater.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_calculater->setIcon(icon13);
        toolButton_calculater->setIconSize(QSize(50, 50));

        verticalLayout_11->addWidget(toolButton_calculater);

        label_8 = new QLabel(frame_13);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy3.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy3);
        label_8->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223\";"));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_8);


        gridLayout->addWidget(frame_13, 1, 0, 1, 1);

        frame_17 = new QFrame(frame_4);
        frame_17->setObjectName(QString::fromUtf8("frame_17"));
        sizePolicy4.setHeightForWidth(frame_17->sizePolicy().hasHeightForWidth());
        frame_17->setSizePolicy(sizePolicy4);
        frame_17->setFrameShape(QFrame::StyledPanel);
        frame_17->setFrameShadow(QFrame::Raised);
        verticalLayout_15 = new QVBoxLayout(frame_17);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        toolButton_fitmentEG = new customToolButton(frame_17);
        toolButton_fitmentEG->setObjectName(QString::fromUtf8("toolButton_fitmentEG"));
        sizePolicy1.setHeightForWidth(toolButton_fitmentEG->sizePolicy().hasHeightForWidth());
        toolButton_fitmentEG->setSizePolicy(sizePolicy1);
        toolButton_fitmentEG->setMinimumSize(QSize(0, 70));
        toolButton_fitmentEG->setMaximumSize(QSize(16777215, 70));
        toolButton_fitmentEG->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"font: 14pt \"\345\215\216\346\226\207\346\226\260\351\255\217\";\n"
"background-color:transparent;"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/Image/fitment.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_fitmentEG->setIcon(icon14);
        toolButton_fitmentEG->setIconSize(QSize(50, 50));

        verticalLayout_15->addWidget(toolButton_fitmentEG);

        label_12 = new QLabel(frame_17);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy3.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy3);
        label_12->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223\";"));
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout_15->addWidget(label_12);


        gridLayout->addWidget(frame_17, 3, 0, 1, 1);


        verticalLayout_5->addWidget(frame_4);

        scrollArea->setWidget(scrollAreaWidgetContents_3);

        verticalLayout_2->addWidget(scrollArea);


        horizontalLayout->addWidget(frame);

        frame_2 = new QFrame(frame_5);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(5);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy5);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget_group1 = new QStackedWidget(frame_2);
        stackedWidget_group1->setObjectName(QString::fromUtf8("stackedWidget_group1"));
        stackedWidget_group1->setFrameShadow(QFrame::Plain);
        page_home = new QWidget();
        page_home->setObjectName(QString::fromUtf8("page_home"));
        stackedWidget_group1->addWidget(page_home);
        page_newHouse = new QWidget();
        page_newHouse->setObjectName(QString::fromUtf8("page_newHouse"));
        gridLayout_3 = new QGridLayout(page_newHouse);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        scrollArea_newHouse = new QScrollArea(page_newHouse);
        scrollArea_newHouse->setObjectName(QString::fromUtf8("scrollArea_newHouse"));
        scrollArea_newHouse->setAutoFillBackground(false);
        scrollArea_newHouse->setFrameShape(QFrame::NoFrame);
        scrollArea_newHouse->setFrameShadow(QFrame::Sunken);
        scrollArea_newHouse->setWidgetResizable(true);
        scrollArea_newHouse->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        SAWC_newHouse = new QWidget();
        SAWC_newHouse->setObjectName(QString::fromUtf8("SAWC_newHouse"));
        SAWC_newHouse->setGeometry(QRect(0, 0, 100, 30));
        sizePolicy.setHeightForWidth(SAWC_newHouse->sizePolicy().hasHeightForWidth());
        SAWC_newHouse->setSizePolicy(sizePolicy);
        scrollArea_newHouse->setWidget(SAWC_newHouse);

        gridLayout_3->addWidget(scrollArea_newHouse, 0, 0, 1, 1);

        stackedWidget_group1->addWidget(page_newHouse);
        page_secondaryHouse = new QWidget();
        page_secondaryHouse->setObjectName(QString::fromUtf8("page_secondaryHouse"));
        gridLayout_4 = new QGridLayout(page_secondaryHouse);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        scrollArea_secondaryHouse = new QScrollArea(page_secondaryHouse);
        scrollArea_secondaryHouse->setObjectName(QString::fromUtf8("scrollArea_secondaryHouse"));
        scrollArea_secondaryHouse->setWidgetResizable(true);
        SAWC_secondaryHouse = new QWidget();
        SAWC_secondaryHouse->setObjectName(QString::fromUtf8("SAWC_secondaryHouse"));
        SAWC_secondaryHouse->setGeometry(QRect(0, 0, 98, 28));
        scrollArea_secondaryHouse->setWidget(SAWC_secondaryHouse);

        gridLayout_4->addWidget(scrollArea_secondaryHouse, 0, 0, 1, 1);

        stackedWidget_group1->addWidget(page_secondaryHouse);
        page_fitment = new QWidget();
        page_fitment->setObjectName(QString::fromUtf8("page_fitment"));
        gridLayout_5 = new QGridLayout(page_fitment);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        scrollArea_fitment = new QScrollArea(page_fitment);
        scrollArea_fitment->setObjectName(QString::fromUtf8("scrollArea_fitment"));
        scrollArea_fitment->setWidgetResizable(true);
        SAWC_fitment = new QWidget();
        SAWC_fitment->setObjectName(QString::fromUtf8("SAWC_fitment"));
        SAWC_fitment->setGeometry(QRect(0, 0, 98, 28));
        scrollArea_fitment->setWidget(SAWC_fitment);

        gridLayout_5->addWidget(scrollArea_fitment, 0, 0, 1, 1);

        stackedWidget_group1->addWidget(page_fitment);
        page_rentHouse = new QWidget();
        page_rentHouse->setObjectName(QString::fromUtf8("page_rentHouse"));
        gridLayout_6 = new QGridLayout(page_rentHouse);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        scrollArea_rentHouse = new QScrollArea(page_rentHouse);
        scrollArea_rentHouse->setObjectName(QString::fromUtf8("scrollArea_rentHouse"));
        scrollArea_rentHouse->setWidgetResizable(true);
        SAWC_rentHouse = new QWidget();
        SAWC_rentHouse->setObjectName(QString::fromUtf8("SAWC_rentHouse"));
        SAWC_rentHouse->setGeometry(QRect(0, 0, 98, 28));
        scrollArea_rentHouse->setWidget(SAWC_rentHouse);

        gridLayout_6->addWidget(scrollArea_rentHouse, 0, 0, 1, 1);

        stackedWidget_group1->addWidget(page_rentHouse);
        page_map = new QWidget();
        page_map->setObjectName(QString::fromUtf8("page_map"));
        sizePolicy.setHeightForWidth(page_map->sizePolicy().hasHeightForWidth());
        page_map->setSizePolicy(sizePolicy);
        stackedWidget_group1->addWidget(page_map);
        page_calculater = new QWidget();
        page_calculater->setObjectName(QString::fromUtf8("page_calculater"));
        stackedWidget_group1->addWidget(page_calculater);
        page_live = new QWidget();
        page_live->setObjectName(QString::fromUtf8("page_live"));
        stackedWidget_group1->addWidget(page_live);
        page_market = new QWidget();
        page_market->setObjectName(QString::fromUtf8("page_market"));
        stackedWidget_group1->addWidget(page_market);
        page_fitmentEG = new QWidget();
        page_fitmentEG->setObjectName(QString::fromUtf8("page_fitmentEG"));
        stackedWidget_group1->addWidget(page_fitmentEG);
        page_agent = new QWidget();
        page_agent->setObjectName(QString::fromUtf8("page_agent"));
        stackedWidget_group1->addWidget(page_agent);
        page_client = new QWidget();
        page_client->setObjectName(QString::fromUtf8("page_client"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(page_client->sizePolicy().hasHeightForWidth());
        page_client->setSizePolicy(sizePolicy6);
        widget_client = new QWidget(page_client);
        widget_client->setObjectName(QString::fromUtf8("widget_client"));
        widget_client->setGeometry(QRect(210, 130, 361, 321));
        sizePolicy.setHeightForWidth(widget_client->sizePolicy().hasHeightForWidth());
        widget_client->setSizePolicy(sizePolicy);
        stackedWidget_group1->addWidget(page_client);
        page_setting = new QWidget();
        page_setting->setObjectName(QString::fromUtf8("page_setting"));
        widget_setting = new QWidget(page_setting);
        widget_setting->setObjectName(QString::fromUtf8("widget_setting"));
        widget_setting->setGeometry(QRect(260, 320, 120, 80));
        stackedWidget_group1->addWidget(page_setting);
        page_search = new QWidget();
        page_search->setObjectName(QString::fromUtf8("page_search"));
        stackedWidget_group1->addWidget(page_search);

        verticalLayout->addWidget(stackedWidget_group1);


        horizontalLayout->addWidget(frame_2);


        verticalLayout_4->addLayout(horizontalLayout);


        gridLayout_2->addWidget(frame_5, 0, 0, 1, 1);


        retranslateUi(ClientPage);

        stackedWidget_group1->setCurrentIndex(10);


        QMetaObject::connectSlotsByName(ClientPage);
    } // setupUi

    void retranslateUi(QWidget *ClientPage)
    {
        ClientPage->setWindowTitle(QCoreApplication::translate("ClientPage", "Form", nullptr));
        toolButton_home->setText(QCoreApplication::translate("ClientPage", "...", nullptr));
        toolButton_search->setText(QString());
        toolButton_client->setText(QString());
        toolButton_settings->setText(QString());
        toolButton_newHouse->setText(QString());
        label_4->setText(QCoreApplication::translate("ClientPage", "\346\226\260\346\210\277", nullptr));
        toolButton_secondaryHouse->setText(QString());
        label_3->setText(QCoreApplication::translate("ClientPage", "\344\272\214\346\211\213\346\210\277", nullptr));
        toolButton_rentHouse->setText(QString());
        label_5->setText(QCoreApplication::translate("ClientPage", "\347\247\237\346\210\277", nullptr));
        toolButton_fitment->setText(QString());
        label->setText(QCoreApplication::translate("ClientPage", "\350\243\205\344\277\256", nullptr));
        toolButton_plot->setText(QString());
        label_13->setText(QCoreApplication::translate("ClientPage", "\346\211\276\345\260\217\345\214\272", nullptr));
        toolButton_live->setText(QString());
        label_6->setText(QCoreApplication::translate("ClientPage", "\347\233\264\346\222\255\347\234\213\346\210\277", nullptr));
        toolButton_agent->setText(QString());
        label_10->setText(QCoreApplication::translate("ClientPage", "\346\211\276\347\273\217\347\272\252\344\272\272", nullptr));
        toolButton_houseType->setText(QString());
        label_11->setText(QCoreApplication::translate("ClientPage", "\346\210\267\345\236\213\346\226\271\346\241\210", nullptr));
        toolButton_map->setText(QString());
        label_7->setText(QCoreApplication::translate("ClientPage", "\351\253\230\345\276\267\345\234\260\345\233\276", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_market->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        toolButton_market->setText(QString());
#if QT_CONFIG(shortcut)
        toolButton_market->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        label_9->setText(QCoreApplication::translate("ClientPage", "\350\260\267\346\255\214\345\234\260\345\233\276", nullptr));
        toolButton_calculater->setText(QString());
        label_8->setText(QCoreApplication::translate("ClientPage", "\346\210\277\350\264\267\350\256\241\347\256\227", nullptr));
        toolButton_fitmentEG->setText(QString());
        label_12->setText(QCoreApplication::translate("ClientPage", "\350\243\205\344\277\256\346\241\210\344\276\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientPage: public Ui_ClientPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTPAGE_H
