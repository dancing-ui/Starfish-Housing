#ifndef CLIENTPAGE_H
#define CLIENTPAGE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QSqlDriver>
#include <QMessageBox>
#include <QtWebEngineWidgets>
#include <QNetworkReply>
#include <QScopedPointer>
#include "customtoolbutton.h"
#include "database.h"
#include "customweb.h"
#include "custominputtext.h"
#include "customwebenginepage.h"

namespace Ui {
class ClientPage;
}

class ClientPage : public QWidget
{

    Q_OBJECT

public:
    explicit ClientPage(QWidget *parent = nullptr);
    ~ClientPage();
    void init();
    int clientID;
private:
    QWidget* createBtn(QWidget* curPage,int houseID,QString name,QString price,QString location,QString area,QString imgPath,
                       QString type,int floor,bool elevator,QString fitment);
    QVBoxLayout* updateHouseInfo(QWidget* curPage,QString type);
    QVBoxLayout* updateHouseInfo(QWidget* curPage,QString name,bool needInnerBtn);
    QWidget* createBtn(QWidget* curPage,int houseID,QString name,QString price,QString location,QString area,
                                   QString type,int floor,bool elevator,QString fitment,bool needInnerBtn);
    void clearLayout(QWidget* widget);
    DataBase database;//数据库
    QNetworkAccessManager *m_manager;
    QWidget* searchPage;
    void initTitle();
    void initIcon();
    void initMap();
    void initCalculater();
    void initLive();
    void initMarket();
    void initFitmentEG();
    void initAgent();
    void initClient();
    void initSetting();
    void initSearch();
    bool verifyPassword(const QString& curPassword);
    void updatePassword();
    QByteArray getSHA1(const QString& str);
signals:
    void callInitPage();
private slots:
    void openInitPage();

    void on_toolButton_home_clicked();

    void on_toolButton_newHouse_clicked();

    void on_toolButton_secondaryHouse_clicked();

    void on_toolButton_fitment_clicked();

    void on_toolButton_rentHouse_clicked();


    void on_toolButton_map_clicked();

    void on_toolButton_calculater_clicked();

    void on_toolButton_live_clicked();
    void on_toolButton_market_clicked();

    void on_toolButton_fitmentEG_clicked();

    void on_toolButton_agent_clicked();

    void on_toolButton_client_clicked();

    void on_toolButton_settings_clicked();
    void on_toolButton_search_clicked();

private:
    Ui::ClientPage *ui;
};

#endif // CLIENTPAGE_H
