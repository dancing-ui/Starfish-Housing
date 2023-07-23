QT       += core gui
QT       += sql
QT       += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#以下两行强制编码为utf-8，防止中文乱码
QMAKE_CXXFLAGS += /source-charset:utf-8
QMAKE_CXXFLAGS += /execution-charset:utf-8

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    customimagewidget.cpp \
    custominputtext.cpp \
    customtoolbutton.cpp \
    database.cpp \
    main.cpp \
    initpage.cpp \
    managerpage.cpp

HEADERS += \
    customimagewidget.h \
    custominputtext.h \
    customtoolbutton.h \
    database.h \
    initpage.h \
    managerpage.h

FORMS += \
    initpage.ui \
    managerpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
