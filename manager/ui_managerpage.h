/********************************************************************************
** Form generated from reading UI file 'managerpage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERPAGE_H
#define UI_MANAGERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManagerPage
{
public:
    QGridLayout *gridLayout;
    QFrame *mainFrame;

    void setupUi(QWidget *ManagerPage)
    {
        if (ManagerPage->objectName().isEmpty())
            ManagerPage->setObjectName(QString::fromUtf8("ManagerPage"));
        ManagerPage->resize(1137, 763);
        gridLayout = new QGridLayout(ManagerPage);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        mainFrame = new QFrame(ManagerPage);
        mainFrame->setObjectName(QString::fromUtf8("mainFrame"));
        mainFrame->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);"));
        mainFrame->setFrameShape(QFrame::StyledPanel);
        mainFrame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(mainFrame, 0, 0, 1, 1);


        retranslateUi(ManagerPage);

        QMetaObject::connectSlotsByName(ManagerPage);
    } // setupUi

    void retranslateUi(QWidget *ManagerPage)
    {
        ManagerPage->setWindowTitle(QCoreApplication::translate("ManagerPage", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManagerPage: public Ui_ManagerPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERPAGE_H
