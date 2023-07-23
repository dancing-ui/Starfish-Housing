#ifndef CUSTOMWEB_H
#define CUSTOMWEB_H

#include <QObject>
#include <QMessageBox>
#include <QJsonObject>
#include <QDebug>
class customWeb:public QObject
{
    Q_OBJECT

public:
    explicit customWeb(QObject* parent=nullptr);
    void setCity(QString city);
public slots:
    void getAutocomplete(QJsonValue result);//html->customWeb
    void test(QString str);
signals:
    void cityChanged(QString city);//customWeb->html
    void inputChanged(QString input);//customWeb->html
    void sendAutocomplete(QJsonValue autocom);//customWeb->html
};

#endif // CUSTOMWEB_H
