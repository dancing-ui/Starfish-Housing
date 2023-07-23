#include "customwebenginepage.h"

CustomWebEnginePage::CustomWebEnginePage(QWidget* parent) : QWidget(parent)
{

}

bool CustomWebEnginePage::certificateError(const QWebEngineCertificateError &certificateError)
{
    return true;
}
