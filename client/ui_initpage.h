/********************************************************************************
** Form generated from reading UI file 'initpage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITPAGE_H
#define UI_INITPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <custominputtext.h>
#include <customtoolbutton.h>

QT_BEGIN_NAMESPACE

class Ui_InitPage
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget_4;
    QGridLayout *gridLayout_3;
    QWidget *widget_picture;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    customToolButton *toolButton_settings;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    customToolButton *toolButton_logIn;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_4;
    customToolButton *toolButton_signUp;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_account;
    QLabel *label_password;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QLabel *label;
    customInputText *widget_account;
    customInputText *widget_password;

    void setupUi(QWidget *InitPage)
    {
        if (InitPage->objectName().isEmpty())
            InitPage->setObjectName(QString::fromUtf8("InitPage"));
        InitPage->resize(665, 952);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InitPage->sizePolicy().hasHeightForWidth());
        InitPage->setSizePolicy(sizePolicy);
        InitPage->setMinimumSize(QSize(665, 952));
        InitPage->setMaximumSize(QSize(665, 952));
        InitPage->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(InitPage);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(InitPage);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy1);
        widget_4->setMinimumSize(QSize(665, 792));
        widget_4->setMaximumSize(QSize(16777215, 16777215));
        widget_4->setAutoFillBackground(false);
        gridLayout_3 = new QGridLayout(widget_4);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_picture = new QWidget(widget_4);
        widget_picture->setObjectName(QString::fromUtf8("widget_picture"));
        sizePolicy1.setHeightForWidth(widget_picture->sizePolicy().hasHeightForWidth());
        widget_picture->setSizePolicy(sizePolicy1);
        widget_picture->setMinimumSize(QSize(665, 792));
        widget_picture->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(widget_picture, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget_4, 0, 0, 1, 1);

        widget_3 = new QWidget(InitPage);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy2);
        widget_3->setMinimumSize(QSize(0, 60));
        widget_3->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy2.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy2);
        widget_2->setMinimumSize(QSize(0, 60));
        widget_2->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255 255)"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton_settings = new customToolButton(widget_2);
        toolButton_settings->setObjectName(QString::fromUtf8("toolButton_settings"));
        sizePolicy1.setHeightForWidth(toolButton_settings->sizePolicy().hasHeightForWidth());
        toolButton_settings->setSizePolicy(sizePolicy1);
        toolButton_settings->setMaximumSize(QSize(70, 70));

        horizontalLayout->addWidget(toolButton_settings);

        horizontalSpacer = new QSpacerItem(70, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 13pt \"\346\226\271\346\255\243\350\210\222\344\275\223\";"));

        horizontalLayout->addWidget(label_3);

        toolButton_logIn = new customToolButton(widget_2);
        toolButton_logIn->setObjectName(QString::fromUtf8("toolButton_logIn"));
        sizePolicy1.setHeightForWidth(toolButton_logIn->sizePolicy().hasHeightForWidth());
        toolButton_logIn->setSizePolicy(sizePolicy1);
        toolButton_logIn->setMaximumSize(QSize(60, 60));
        toolButton_logIn->setCursor(QCursor(Qt::ArrowCursor));
        toolButton_logIn->setLayoutDirection(Qt::LeftToRight);
        toolButton_logIn->setAutoFillBackground(false);
        toolButton_logIn->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"font: 15pt \"\346\226\271\346\255\243\350\210\222\344\275\223\";\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/login.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_logIn->setIcon(icon);
        toolButton_logIn->setIconSize(QSize(40, 40));
        toolButton_logIn->setPopupMode(QToolButton::DelayedPopup);
        toolButton_logIn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_logIn->setAutoRaise(true);
        toolButton_logIn->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(toolButton_logIn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 13pt \"\346\226\271\346\255\243\350\210\222\344\275\223\";"));

        horizontalLayout->addWidget(label_4);

        toolButton_signUp = new customToolButton(widget_2);
        toolButton_signUp->setObjectName(QString::fromUtf8("toolButton_signUp"));
        sizePolicy1.setHeightForWidth(toolButton_signUp->sizePolicy().hasHeightForWidth());
        toolButton_signUp->setSizePolicy(sizePolicy1);
        toolButton_signUp->setMaximumSize(QSize(60, 60));
        toolButton_signUp->setContextMenuPolicy(Qt::PreventContextMenu);
        toolButton_signUp->setLayoutDirection(Qt::LeftToRight);
        toolButton_signUp->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"font: 15pt \"\346\226\271\346\255\243\350\210\222\344\275\223\";\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Image/signup.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_signUp->setIcon(icon1);
        toolButton_signUp->setIconSize(QSize(40, 40));
        toolButton_signUp->setAutoRepeat(false);
        toolButton_signUp->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_signUp->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_signUp);

        horizontalSpacer_6 = new QSpacerItem(200, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout->addWidget(widget_2);


        gridLayout_2->addWidget(widget_3, 2, 0, 1, 1);

        widget = new QWidget(InitPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"\n"
""));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_account = new QLabel(widget);
        label_account->setObjectName(QString::fromUtf8("label_account"));
        sizePolicy2.setHeightForWidth(label_account->sizePolicy().hasHeightForWidth());
        label_account->setSizePolicy(sizePolicy2);
        label_account->setMinimumSize(QSize(90, 30));
        label_account->setMaximumSize(QSize(16777215, 30));
        label_account->setStyleSheet(QString::fromUtf8("color:red;\n"
"font: 15pt \"\346\245\267\344\275\223\";\n"
""));
        label_account->setFrameShape(QFrame::NoFrame);
        label_account->setOpenExternalLinks(false);

        gridLayout->addWidget(label_account, 0, 4, 1, 1);

        label_password = new QLabel(widget);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        sizePolicy2.setHeightForWidth(label_password->sizePolicy().hasHeightForWidth());
        label_password->setSizePolicy(sizePolicy2);
        label_password->setMinimumSize(QSize(90, 30));
        label_password->setMaximumSize(QSize(16777215, 30));
        label_password->setStyleSheet(QString::fromUtf8("color:red;\n"
"font: 15pt \"\346\245\267\344\275\223\";\n"
""));
        label_password->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(label_password, 1, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(180, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 50));
        label_2->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"font: 15pt \"\346\226\271\346\255\243\350\210\222\344\275\223\";"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 50));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"font: 15pt \"\346\226\271\346\255\243\350\210\222\344\275\223\";\n"
""));
        label->setFrameShape(QFrame::NoFrame);
        label->setLineWidth(10);
        label->setMidLineWidth(10);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        widget_account = new customInputText(widget);
        widget_account->setObjectName(QString::fromUtf8("widget_account"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_account->sizePolicy().hasHeightForWidth());
        widget_account->setSizePolicy(sizePolicy3);
        widget_account->setMinimumSize(QSize(0, 0));
        widget_account->setMaximumSize(QSize(16777215, 40));
        widget_account->setStyleSheet(QString::fromUtf8("background-color:white;"));

        gridLayout->addWidget(widget_account, 0, 2, 1, 1);

        widget_password = new customInputText(widget);
        widget_password->setObjectName(QString::fromUtf8("widget_password"));
        sizePolicy3.setHeightForWidth(widget_password->sizePolicy().hasHeightForWidth());
        widget_password->setSizePolicy(sizePolicy3);
        widget_password->setMaximumSize(QSize(16777215, 40));
        widget_password->setStyleSheet(QString::fromUtf8("background-color:white;"));

        gridLayout->addWidget(widget_password, 1, 2, 1, 1);


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);

        widget_3->raise();
        widget->raise();
        widget_4->raise();

        retranslateUi(InitPage);

        QMetaObject::connectSlotsByName(InitPage);
    } // setupUi

    void retranslateUi(QWidget *InitPage)
    {
        InitPage->setWindowTitle(QCoreApplication::translate("InitPage", "InitPage", nullptr));
        toolButton_settings->setText(QString());
        label_3->setText(QCoreApplication::translate("InitPage", "\347\231\273\345\275\225", nullptr));
        toolButton_logIn->setText(QString());
        label_4->setText(QCoreApplication::translate("InitPage", "\346\263\250\345\206\214", nullptr));
        toolButton_signUp->setText(QString());
        label_account->setText(QString());
        label_password->setText(QString());
        label_2->setText(QCoreApplication::translate("InitPage", "\345\257\206\347\240\201\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("InitPage", "\350\264\246\345\217\267\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InitPage: public Ui_InitPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITPAGE_H
