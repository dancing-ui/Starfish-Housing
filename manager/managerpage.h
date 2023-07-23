#ifndef MANAGERPAGE_H
#define MANAGERPAGE_H

#include <QWidget>
#include <QTabWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QScrollArea>
#include <QGroupBox>
#include <QCryptographicHash>
#include <QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include "customtoolbutton.h"
#include "custominputtext.h"
#include "database.h"
using namespace std;
namespace Ui {
class ManagerPage;
}

class ManagerPage : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerPage(QWidget *parent = nullptr);
    ~ManagerPage();
    uint64_t managerID;

    QTabWidget* mainPage;
    QWidget* personelPage;
    QWidget* addPage;
    QWidget* removePage;
    QWidget* selectPage;
    QWidget* updatePage;
    QWidget* settingPage;
    QWidget* chartPage;

     void init();
     void initTitle();
     void initPersonelPage();
     void initAddPage();
     void initRemovePage();
     void initSelectPage();
     void initUpdatePage();
     void initSettingPage();
     void initChart();

     /*画饼状图*/
     QChart* createPieChart();
     QMap<QString,qreal> calChartRate(QList<QMap<QString,QString>>& arg);

     bool verifyPassword(const QString& curPassword);
     void updatePassword();
     QByteArray getSHA1(const QString& str);

     void clearLayout(QWidget* widget);
     QVBoxLayout* updateHouseInfo(QWidget* curPage,QString name,bool needInnerBtn,bool needUpdate);
     QWidget* createBtn(QWidget* curPage,int houseID,QString name,QString price,QString location,QString area,
                                    QString type,int floor,bool elevator,QString fitment,bool needInnerBtn,bool needUpdate);

private:
     DataBase database;

signals:
    void callInitPage();
private slots:
    void openInitPage();

private:
    Ui::ManagerPage *ui;
};

#endif // MANAGERPAGE_H
