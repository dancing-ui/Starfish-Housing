#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

void DataBase::connectDB(QString linkName)
{
    db = QSqlDatabase::database(linkName);
    if(!db.isOpen())
    {
        db = QSqlDatabase::addDatabase("QMYSQL",linkName);  //连接的MYSQL的数据库驱动和连接名，
        //对于不同的连接需要指定连接名，否则在删除的时候会因为没有连接名导致所有连接都关闭
        db.setHostName("127.0.0.1");         //主机名
        db.setPort(3306);                    //端口
        db.setDatabaseName("housesystem");          //数据库名
        db.setUserName("root");              //用户名
        db.setPassword("123456");            //密码
        //测试连接
        db.open();
    }
    if(db.isOpen())
    {
        qDebug() <<linkName<< "连接成功";
    }
    else
    {
         qDebug() <<linkName<< "连接失败";
    }
}

void DataBase::disconneectDB(QString linkName)
{
    QSqlDatabase dbc = QSqlDatabase::database(linkName);//获取连接名对应的数据库
    qDebug()<<linkName<<"已断开连接";
    dbc.close();//关闭连接
}

QList<QMap<QString, QString>> DataBase::select(QString sql)
{
    QList<QMap<QString, QString>> res;
    QSqlQuery query(db);
    //prepare防止sql注入
    query.prepare(sql);
    query.exec();
    QSqlRecord record = query.record();
    int column = record.count();
    while(query.next())
    {
        QMap<QString,QString> oneColumn;
        for(int i=0;i<column;i++)
        {
            oneColumn[record.fieldName(i)]= query.value(i).toString();
        }
        res.push_back(oneColumn);
    }
    query.finish();
    return res;
}

bool DataBase::update(QString sql)
{
    db.transaction();
    QSqlQuery query(db);
    query.prepare(sql);
    bool result = query.exec();
    /*释放资源*/
    query.finish();
    if(result)
    {
        /*提交事务*/
        db.commit();
        return true;
    }
    db.rollback();
    QSqlError error = query.lastError();
    qDebug()<<error;
    return false;
}

bool DataBase::remove(QString sql)
{
    db.transaction();
    QSqlQuery query(db);
    query.prepare(sql);
    bool result = query.exec();
    /*释放资源*/
    query.finish();
    if(result)
    {
        /*提交事务*/
        db.commit();
        return true;
    }
    db.rollback();
    QSqlError error = query.lastError();
    qDebug()<<error;
    return false;
}

bool DataBase::insert(QString sql)
{
    db.transaction();
    QSqlQuery query(db);
    query.prepare(sql);
    bool result = query.exec();
    /*释放资源*/
    query.finish();
    if(result)
    {
        /*提交事务*/
        db.commit();
        return true;
    }
    db.rollback();
    QSqlError error = query.lastError();
    qDebug()<<error;
    return false;
}
