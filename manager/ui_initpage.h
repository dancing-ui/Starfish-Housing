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
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InitPage
{
public:

    void setupUi(QWidget *InitPage)
    {
        if (InitPage->objectName().isEmpty())
            InitPage->setObjectName(QString::fromUtf8("InitPage"));
        InitPage->resize(1010, 773);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InitPage->sizePolicy().hasHeightForWidth());
        InitPage->setSizePolicy(sizePolicy);
        InitPage->setMinimumSize(QSize(1010, 773));
        InitPage->setMaximumSize(QSize(1010, 773));

        retranslateUi(InitPage);

        QMetaObject::connectSlotsByName(InitPage);
    } // setupUi

    void retranslateUi(QWidget *InitPage)
    {
        InitPage->setWindowTitle(QCoreApplication::translate("InitPage", "InitPage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InitPage: public Ui_InitPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITPAGE_H
