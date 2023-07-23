#include "initpage.h"

#include <QApplication>
#include <QDebug>
#include <QDesktopWidget>
#include "clientpage.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InitPage w;
    w.show();
    return a.exec();
}
