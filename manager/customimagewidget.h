#ifndef CUSTOMIMAGEWIDGET_H
#define CUSTOMIMAGEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
class customImageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit customImageWidget(QWidget *parent = nullptr);

    QPixmap pixmap;
    void setPixmap(const QPixmap& curPixmap);
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *) override;
signals:

};

#endif // CUSTOMIMAGEWIDGET_H
