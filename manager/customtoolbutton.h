#ifndef CUSTOMTOOLBUTTON_H
#define CUSTOMTOOLBUTTON_H

#include <QWidget>
#include <QToolButton>
#include <QPainter>
#include <QDebug>
#include <QPropertyAnimation>
#include <QComboBox>
class customToolButton : public QToolButton
{
    Q_OBJECT
    //Q_PROPERTY自定义旋转属性
    //Q_PROPERTY(qreal rotationAngle READ rotationAngle WRITE setRotationAngle NOTIFY rotationAngleChanged)
public:
    explicit customToolButton(QWidget *parent = nullptr);
    QString path;
    virtual void paintEvent(QPaintEvent *) override;
    virtual void enterEvent(QEvent *) override;
    virtual void leaveEvent(QEvent *) override;

    void init(QString imgPath,QSize size);

    QPropertyAnimation* animationEnter;
    QPropertyAnimation* animationLeave;

    int imgWidth=0;
    int imgHeight=0;

    int oldWidth=0;
    int oldHeight=0;

    int newWidth=0;
    int newHeight=0;
signals:

private slots:
    void enterImgChanged(QVariant v);
    void leaveImgChanged(QVariant v);
};

#endif // CUSTOMTOOLBUTTON_H
