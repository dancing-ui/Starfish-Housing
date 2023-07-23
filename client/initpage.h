#ifndef INITPAGE_H
#define INITPAGE_H

#include <QWidget>
#include <QTimer>
#include <QDebug>
#include <QCryptographicHash>
#include "carouselimagewindow.h"
#include "database.h"
#include "clientpage.h"
#include "customtoolbutton.h"
#include "custominputtext.h"
#include "customscrollarea.h"
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
    void initSettings();
    void verifyAccount();
    void verifyPassword();
    QByteArray getSHA1(QString str);

private slots:
    void openClientPage();
    void openSelf();

    void on_toolButton_settings_clicked();

private:
    Ui::InitPage *ui;
    /*数据库*/
    DataBase database;
    /*进入客户页面许可*/
    bool clientPermission=false;
    ClientPage clientPage;
    QWidget* settings;
signals:

};
#endif // INITPAGE_H
