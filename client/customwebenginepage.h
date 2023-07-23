#ifndef CUSTOMWEBENGINEPAGE_H
#define CUSTOMWEBENGINEPAGE_H

/*忽略SSL握手失败的提示，也就是说QT的QWebEngine有bug，只能用于http，不能用于https*/
#include <QWebEnginePage>
#include <QWidget>

class CustomWebEnginePage : public QWebEnginePage,QWidget
{
public:
    CustomWebEnginePage(QWidget* parent = NULL);

    virtual bool certificateError(const QWebEngineCertificateError &certificateError);
};

#endif // CUSTOMWEBENGINEPAGE_H
