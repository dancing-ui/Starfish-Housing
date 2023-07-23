#ifndef CUSTOMSCROLLAREA_H
#define CUSTOMSCROLLAREA_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPainter>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QGraphicsOpacityEffect>
#include <QVector>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QTimer>
#include <QtMath>
#include <QDebug>
#include <QScrollArea>
#define MAXSPEED 70
class customScrollAreaIndicator : public QWidget
{
    Q_OBJECT
private:
    QColor curColor;
    QColor defaultColor = QColor(100, 100, 100, 130);
    QColor hoverColor = QColor(70, 70, 70, 150);
    QColor pressColor = QColor(50, 50, 50, 170);

    QTimer* hovTimer;
    QTimer* aniPause;

    int lastY;

    int defaultWidth = 2;
    int defaultWidthAtFocus = 9;
    int margin = 3;

    bool pressed = false;

public:
    explicit customScrollAreaIndicator(QWidget *parent = nullptr);
private:
    void paintEvent(QPaintEvent* )override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

signals:
    void scrollPage(int);

};
class customScrollAreaList : public QWidget
{
  Q_OBJECT
public:
    explicit customScrollAreaList(QWidget *parent = nullptr);
    void AddWidget(QWidget* widget, bool setAnimation = true);
    void RemoveWidget(QWidget* widget = nullptr);
    void updateHeight();
    void clear();

private:
    int spacing = 3;
    QVector<QWidget*> widgets;
    int size = 0;
    QVector<int> ys;

    void paintEvent(QPaintEvent* event) override;
};
class customScrollArea : public QScrollArea
{
    Q_OBJECT
public:

private:
    QTimer* getCord;
    QTimer* rfrshView;

    customScrollAreaList* container;
    customScrollAreaIndicator* indicator;

    QPropertyAnimation* bounce;

    bool pressed = false;
    bool scrollDown = true;
    bool outOfEdge = false;
    bool ignoreMaxSpeed = false;

    int strtY;
    int lastY;
    int bfEdgeY;    //last y value before out of edge

    int curSpd = 0;
    int damp = 1;
    int moveStored = 0;
    int nextMove = 1;

    void paintEvent(QPaintEvent* event)override;
    void wheelEvent(QWheelEvent* event)override;//鼠标滑轮事件
    void bounceBack();

public:
    explicit customScrollArea(QWidget *parent = nullptr);
    void addWidget(QWidget* newWidget, bool setAnimation = true);
    void addWidgets(QVector<QWidget*> widgets);
    void removeWidget(QWidget* w  = nullptr);
    void scrollToTop();
    void updateHeight();
    void clear();

signals:

private slots:
    void scrollContainer();
    void scrollIndicator(int dp);

signals:

};

#endif // CUSTOMSCROLLAREA_H
