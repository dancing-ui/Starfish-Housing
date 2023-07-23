#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QtDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);
    QSqlDatabase db;
    void connectDB(QString linkName);
    void disconneectDB(QString linkName);
    QList<QMap<QString,QString>> select(QString sql);
    bool update(QString sql);
    bool remove(QString sql);
    bool insert(QString sql);
signals:

};

#endif // DATABASE_H
