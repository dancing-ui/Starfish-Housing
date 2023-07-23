#include "initpage.h"

#include <QApplication>
#include <QTextCodec>
#include <QtDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InitPage w;
    w.show();
    return a.exec();
}
