#include "customimagewidget.h"

customImageWidget::customImageWidget(QWidget *parent) : QWidget(parent)
{

}

void customImageWidget::setPixmap(const QPixmap &curPixmap)
{
    pixmap = curPixmap;
    update();
}

void customImageWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    if (!pixmap.isNull())
        painter.drawPixmap(this->rect(), pixmap);
}

void customImageWidget::resizeEvent(QResizeEvent *)
{
    this->setGeometry(0,0,this->width(),this->height());
}
