#ifndef INITPAGE_H
#define INITPAGE_H

#include <QWidget>
#include <QIcon>
#include <QDesktopWidget>
#include <QGraphicsBlurEffect>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCryptographicHash>
#include "custominputtext.h"
#include "customtoolbutton.h"
#include "customimagewidget.h"
#include "database.h"
#include "managerpage.h"
QT_BEGIN_NAMESPACE
namespace Ui { class InitPage; }
QT_END_NAMESPACE

class InitPage : public QWidget
{
    Q_OBJECT

public:
    InitPage(QWidget *parent = nullptr);
    ~InitPage();
    void init();

private slots:
    void openManagerPage();
    void openSelf();
private:
    DataBase database;
    customInputText* textPassword;
    customInputText* textAccount;
    bool managerPermission=false;
    void verifyUser();
    QByteArray getSHA1(QString str);

    ManagerPage managerPage;


    Ui::InitPage *ui;
};
#endif // INITPAGE_H
