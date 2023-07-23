#include "customscrollarea.h"

customScrollArea::customScrollArea(QWidget *parent) : QScrollArea(parent)//现在整个滑动区域都在外面
{
    resize(parent->width(),parent->height()-100);
    container=new customScrollAreaList(this);
    container->move(0,0);
    container->resize(this->width(),3);

    rfrshView=new QTimer;//更新滚动时的画面
    rfrshView->setSingleShot(true);//单次计时

    indicator=new customScrollAreaIndicator(this);//下滑条
    indicator->resize(indicator->width(), (int)((double)this->height() * this->height() / (double)container->height()));
    indicator->move(this->width()-indicator->width()-3,0);
    this->setMouseTracking(true);
    container->setMouseTracking(true);
    indicator->setMouseTracking(true);

    bounce=new QPropertyAnimation(container,"pos");//边界动画

    connect(rfrshView, SIGNAL(timeout()), this, SLOT(scrollContainer()));
    connect(indicator, SIGNAL(scrollPage(int)), this, SLOT(scrollIndicator(int)));//滑动条滑动
}

void customScrollArea::scrollContainer()//滚动时的画面
{
    //curSpd：鼠标滑动速度
    if(curSpd>0)//滑动速度
    {
        if(curSpd>MAXSPEED)
        {
            curSpd=MAXSPEED;
        }
        int dp=scrollDown==true?curSpd:-curSpd;//往下滑页就是把y变小，y变小时，下面的内容才能显示出来
        //往上滑页就是把y变大
        //scrollDown为false时，代表往下，为true时代表往上
        container->move(container->x(),container->y()+dp);//使用移动实现滚动效果，当y减小时，代表当前的这一块往上移动
    }
    else
    {
        return;//如果不返回就会一直滑
    }
    //container->y()<=0说明在往下滑
    if(container->y()<=0&&container->y()+container->height()>=this->height())//滑动减速
    {
        curSpd-=damp;//减小滑动速度
        curSpd=curSpd<0?0:curSpd;
    }
    else
    {
        curSpd/=2;//滑动速度减半
    }

    if(curSpd==0&&(container->y()>0||container->y()+container->height()<this->height()))//速度为0，且滑到顶或者滑到底
    {
        bounceBack();//边界动画
    }
    else//速度不为0时，再次打开动画计时器,继续接受滑动事件，直到速度为0
    {
        rfrshView->start(30);//因为是单次计时器，所以只要没有到边界，都需要重新打开得到边界画面
    }
}
void customScrollArea::bounceBack()//边界动画
{
    rfrshView->stop();
    bounce->setDuration(500);
    bounce->setStartValue(container->pos());
    if(container->y()>0)//到达上边界
    {
        bounce->setEndValue(QPoint(container->x(),0));//移动到原位置
    }
    else//到达下边界
    {
        bounce->setEndValue(QPoint(container->x(),this->height()- container->height()));//回到this->height()- container->height()的位置
        //this->height()- container->height()肯定是负数，因为到达下边界之后，containe左上角那个基点肯定是负的
    }
    bounce->setEasingCurve(QEasingCurve::InOutQuad);
    bounce->start();
}
void customScrollArea::paintEvent(QPaintEvent* )
{
    container->resize(this->width(),container->height());
    if(container->height()>this->height()&&
       container->y()<this->height()-container->height()&&
            curSpd==0&&
            bounce->state()==QAbstractAnimation::Stopped)

    {
        container->move(container->x(),this->height()-container->height());//移动到最下方
    }
    if(container->height()<=this->height())
    {
        container->move(container->x(),0);
        indicator->hide();
    }
    else
    {
        indicator->show();
    }
    indicator->resize(indicator->width(),
(int)((double)this->height()*this->height()/
      (double)container->height()));
    indicator->move(this->width()-indicator->width()-3,
-container->y()*this->height()/container->height());
}
void customScrollArea::addWidget(QWidget* newWidget, bool setAnimation)
{
    newWidget->setParent(container);
    container->AddWidget(newWidget,setAnimation);
}
void customScrollArea::addWidgets(QVector<QWidget*> widgets)
{
    for(int i=0;i<widgets.size();i++)
    {
        addWidget(widgets[i],false);
    }
}
void customScrollArea::removeWidget(QWidget* w)
{
    container->RemoveWidget(w);
}
void customScrollArea::updateHeight()
{
    container->updateHeight();
}
void customScrollArea::clear()
{
    container->clear();
}
void customScrollArea::scrollIndicator(int dp)//实现滑动条的滚动
{
    int newY=container->y()-dp*container->height()/this->height();
    if(newY>0)
    {
        newY=0;
    }
    else if(newY<this->height()-container->height())
    {
        newY=this->height()-container->height();
    }
    container->move(container->x(),newY);
    update();
}
void customScrollArea::wheelEvent(QWheelEvent* event)//鼠标滑轮事件
{
    //container->y()>0说明现在在往上滑
    if(container->y() > 0 || container->y() + container->height() < this->height())
    {
        return;
    }
    curSpd += 5;
    bool newDirection = event->angleDelta().y() > 0;
    if(newDirection != scrollDown)//向上滚
        curSpd = 5;
    if(curSpd > MAXSPEED)
        curSpd = MAXSPEED;
    scrollDown = newDirection;
    if(!rfrshView->isActive())
        rfrshView->start(30);
    update();
}

customScrollAreaList::customScrollAreaList(QWidget *parent) : QWidget(parent)
{

}

void customScrollAreaList::AddWidget(QWidget* widget,bool setAnimation)
{
    //Add animation for all widgets current
    this->resize(this->width(),this->height()+widget->height()+spacing);
    widgets.push_back(widget);
    size++;
    ys.push_back(0);
    widget->resize(this->width(),widget->height());
    widget->show();
    if(setAnimation==true)
    {
        QGraphicsOpacityEffect* widgetOpac=new QGraphicsOpacityEffect(widget);
        widgetOpac->setOpacity(0);
        widget->setGraphicsEffect(widgetOpac);
        QParallelAnimationGroup* dpGroup=new QParallelAnimationGroup;
        QSequentialAnimationGroup* newWidgetFadeIn=new QSequentialAnimationGroup;
        for(int i=0;i<size-1;i++)
        {
            ys[i]+=widget->height()+spacing;
            QPropertyAnimation* move=new QPropertyAnimation(widgets[i],"pos");
            move->setDuration(750);
            move->setStartValue(widgets[i]->pos());
            move->setEndValue(QPoint(widgets[i]->x(),ys[i]));
            move->setEasingCurve(QEasingCurve::InOutQuart);
            dpGroup->addAnimation(move);
        }
        newWidgetFadeIn->addPause(300);
        QPropertyAnimation* fade=new QPropertyAnimation(widgetOpac,"opacity",widget);
        fade->setDuration(300);
        fade->setStartValue(0);
        fade->setEndValue(0.99);
        newWidgetFadeIn->addAnimation(fade);
        dpGroup->addAnimation(newWidgetFadeIn);
        dpGroup->start();
        connect(dpGroup,&QPropertyAnimation::stateChanged,[=](){
            if(dpGroup->state()==QAbstractAnimation::Stopped)
            {
                if(widgetOpac->opacity()!=0.99)
                {
                    fade->start(QAbstractAnimation::DeleteWhenStopped);
                    connect(fade,&QPropertyAnimation::finished,[=](){
                        widgetOpac->deleteLater();
                    });
                }
                else
                {
                    dpGroup->deleteLater();
                    widgetOpac->deleteLater();
                }
            }
        });
    }
    else
    {
        for(int i=0;i<size-1;i++)
        {
            ys[i]+=widget->height()+spacing;
            widgets[i]->move(QPoint(widgets[i]->pos().x(),ys[i]));
        }
    }
}
void customScrollAreaList::RemoveWidget(QWidget* widget)
{
    int index;
    if(widget==nullptr)
    {
        index=size-1;
        if(index!=-1)
        {
            widget=widgets[index];
        }
    }
    else
    {
        index=widgets.indexOf(widget);
    }
    if(index==-1||widget==nullptr)
    {
        return;
    }
    this->resize(this->width(),this->height()-widget->height()-spacing);
    this->parentWidget()->update();
    widget->hide();
    widget->setParent(nullptr);
    QParallelAnimationGroup* dpGroup=new QParallelAnimationGroup;
    for(int i=index-1;i>=0;i--)
    {
        ys[i]-=(widget->height()+spacing);
        QPropertyAnimation* move=new QPropertyAnimation(widgets[i],"pos");
        move->setDuration(750);
        move->setStartValue(widgets[i]->pos());
        move->setEndValue(QPoint(widgets[i]->x(),ys[i]));
        move->setEasingCurve(QEasingCurve::InOutQuart);
        dpGroup->addAnimation(move);
    }
    dpGroup->start(QAbstractAnimation::DeleteWhenStopped);
    widgets.remove(index);
    size--;
    ys.remove(index);
}
void customScrollAreaList::updateHeight()
{
    for(int i=size-2;i>=0;i--)
    {
        ys[i]=ys[i+1]+widgets[i+1]->height()+spacing;
        widgets[i]->move(widgets[i]->pos().x(),ys[i]);
    }
    this->resize(this->width(),ys[0]+widgets[0]->height()+spacing);
}
void customScrollAreaList::clear()
{
    int n=size;
    for(int i=0;i<n;i++)
    {
        RemoveWidget();
    }
}
void customScrollAreaList::paintEvent(QPaintEvent* )
{
    for(int i=0;i<widgets.size();i++)
    {
        widgets[i]->resize(this->width(),widgets[i]->height());
    }
}

customScrollAreaIndicator::customScrollAreaIndicator(QWidget *parent):QWidget(parent)
{
    this->resize(defaultWidth,0);//宽度为2，高度为0，就是一条线
    aniPause=new QTimer(this);
    aniPause->setSingleShot(true);
    this->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    this->curColor=defaultColor;
    this->setMouseTracking(true);//接收鼠标事件
}
void customScrollAreaIndicator::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(curColor);
    painter.drawRect(this->rect());
}

void customScrollAreaIndicator::mousePressEvent(QMouseEvent* event)
{
    curColor=pressColor;
    pressed=true;
//>note: globalPos -> globalPosition here due to deprecation
    //>      may cause issues
#if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
    lastY = event->globalPosition().y();
#else
    lastY = event->globalPos().y();
#endif
    update();
}
void customScrollAreaIndicator::mouseMoveEvent(QMouseEvent* event)
{
    //鼠标按住，而且动画计时器还没开始
    if(pressed==true&&aniPause->isActive()==false)
    {
        //>note: globalPos -> globalPosition here due to deprecation
                //>      may cause issues
        #if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
                int dp = event->globalPosition().y() - lastY;
        #else
                int dp = event->globalPos().y() - lastY;
        #endif
                emit scrollPage(dp);
                //>note: globalPos -> globalPosition here due to deprecation
                //>      may cause issues
        #if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
                lastY = event->globalPosition().y();
        #else
                lastY = event->globalPos().y();
        #endif
    }
}
void customScrollAreaIndicator::mouseReleaseEvent(QMouseEvent* )
{
    pressed=false;
    curColor=hoverColor;
    update();
}
