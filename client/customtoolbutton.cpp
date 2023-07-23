#include "customtoolbutton.h"

customToolButton::customToolButton(QWidget *parent) : QToolButton(parent)
{

}
void customToolButton::init(QString imgPath,QSize size)
{
    this->setMouseTracking(true);
    /*设置参数*/
    path = imgPath;
    QPixmap img(path);
    imgWidth = size.width();
    imgHeight = size.height();
    oldWidth = imgWidth;
    oldHeight = imgHeight;
    newWidth = imgWidth - 25;
    newHeight = imgHeight - 25;
    /*分配动画*/
    animationEnter = new QPropertyAnimation(this,"");
    animationEnter->setStartValue(0);
    animationEnter->setEndValue(25);
    animationEnter->setDuration(200);
    animationEnter->setEasingCurve(QEasingCurve::InOutExpo);
    connect(animationEnter,&QPropertyAnimation::valueChanged,this,&customToolButton::enterImgChanged);

    animationLeave = new QPropertyAnimation(this,"");
    animationLeave->setStartValue(0);
    animationLeave->setEndValue(25);
    animationLeave->setDuration(200);
    animationLeave->setEasingCurve(QEasingCurve::InOutExpo);
    connect(animationLeave,&QPropertyAnimation::valueChanged,this,&customToolButton::leaveImgChanged);
    /*调用paintEvent更新画面*/
    update();
}

void customToolButton::paintEvent(QPaintEvent *)
{
    if(path.size()==0)return;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPixmap img(path);
    img = img.scaled(newWidth,newHeight,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    int pixX = rect().center().x() - newWidth / 2;
    int pixY = rect().center().y() - newHeight / 2;//newHeight/2是为了将图像的点往上移，减10是为了把图像网上移一点
    QPoint point(pixX, pixY);
    painter.drawPixmap(point, img);
}

void customToolButton::enterEvent(QEvent *)
{
    imgWidth = imgWidth - 25;
    imgHeight = imgHeight -25;
    animationEnter->start();
}

void customToolButton::leaveEvent(QEvent *)
{

    imgWidth = oldWidth;
    imgHeight = oldHeight;
    animationLeave->start();
}

void customToolButton::enterImgChanged(QVariant v)
{
    newWidth = imgWidth + v.toUInt();
    newHeight = imgHeight + v.toUInt();
    update();
}

void customToolButton::leaveImgChanged(QVariant v)
{
    newWidth = imgWidth - v.toUInt();
    newHeight = imgHeight - v.toUInt();
    update();
}
