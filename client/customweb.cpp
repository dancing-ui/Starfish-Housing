#include "customweb.h"

customWeb::customWeb(QObject* parent)
    :QObject(parent)
{

}

void customWeb::setCity(QString city)
{
    emit cityChanged(city);
}

void customWeb::getAutocomplete(QJsonValue result)
{
    emit sendAutocomplete(result);
}

void customWeb::test(QString str)
{
    QMessageBox::information(NULL, "jscallme", str);
}

