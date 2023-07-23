#include "custominputtext.h"

customInputText::customInputText(QWidget *parent) : QWidget(parent)
{
    init();
}

void customInputText::init()
{
    QFont textFont = QFont("Corbel", 12);
    editor = new QLineEdit(this);//编辑框
    editor->setStyleSheet("background-color:rgb(240,240,240);border:none;");
    editor->setFont(textFont);

    bgWidget = new QWidget(this);//背景
    bgWidget->setStyleSheet("background-color:rgb(240,240,240);border-radius:5px;");
    bgWidget->lower();
    bgWidget->show();

    indicator = new QWidget(this);//下面那条移动的线
    indicator->setFixedHeight(4);
    indicator->setStyleSheet("background-color:#0078d4;border-radius:2px");

    opac = new QGraphicsOpacityEffect(this);
    opac->setOpacity(0);//设置完全不透明
    indicator->setGraphicsEffect(opac);

    connect(editor, &QLineEdit::returnPressed, this, [=](){//按回车退出编辑
        leaveEditEffect();
        onEditing = false;
        editor->setReadOnly(true);
        curText = editor->text();
    });
    connect(editor, &QLineEdit::editingFinished, this, [=](){//按其它地方退出编辑
        leaveEditEffect();
        onEditing = false;
        editor->setReadOnly(true);
        curText = editor->text();
        QTimer *delay = new QTimer(this);
        connect(delay, &QTimer::timeout, this, [=](){mousePressed = false;});
        delay->setSingleShot(true);
        delay->start(10);
        mousePressed = false;
        emit textEdited(curText);
    });
    this->setMouseTracking(true);
}
void customInputText::resizeEvent(QResizeEvent *)
{
    leaveEditEffect();
    int width = QFontMetrics(editor->font()).size(Qt::TextSingleLine, editor->text()).width() + 3;
    if (!onEditing)
    {
        if (width > this->width() * 0.7 - margin)
            editor->resize(this->width() * 0.7 - margin, editor->height());
        else
            editor->resize(width, editor->height());
        editor->move(this->width() - margin - editor->width(), this->height() / 2 - editor->height() / 2);
        indicator->move(this->width() - margin, this->height() - 7);
    }
    else
    {
        editor->resize(this->width() * 0.7 - margin, editor->height());
        editor->move(this->width() * 0.3, this->height() / 2 - editor->height() / 2 - 2);
        indicator->move(this->width() * 0.3, this->height() - 7);
    }
    bgWidget->setFixedSize(this->size());
}

void customInputText::enterEditEffect()
{
    editor->setCursorPosition(editor->text().length());//设置光标到文字末尾
    editor->setStyleSheet("color:#1c1c1c;background-color:#00000000;border-style:none;");
    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
    QPropertyAnimation *longer = new QPropertyAnimation(indicator, "geometry", this);//滑动条变长
    longer->setStartValue(indicator->geometry());
    longer->setEndValue(QRectF(0, this->height()-7, this->width(), 4));//0, this->height() - 7控制滑动条位置，this->width(), 4控制长度和宽度
    longer->setDuration(500);
    longer->setEasingCurve(QEasingCurve::InOutExpo);
    QPropertyAnimation *fade = new QPropertyAnimation(opac, "opacity", this);//让下面那个滑动条从左到右慢慢变长出现，原理就是利用一个透明动画opacity
    fade->setStartValue(opac->opacity());//刚开始是透明
    fade->setEndValue(0.99);//不透明
    fade->setDuration(150);
    QPropertyAnimation *move = new QPropertyAnimation(editor, "geometry", this);//光标移动到最前面
    move->setStartValue(editor->geometry());
    move->setEndValue(QRectF(0, this->height() / 2 - editor->height() / 2 - 2, this->width(), editor->height()));
    move->setDuration(500);
    move->setEasingCurve(QEasingCurve::InOutExpo);
    group->addAnimation(longer);
    group->addAnimation(fade);
    group->addAnimation(move);
    group->start();
}

void customInputText::leaveEditEffect()
{
    editor->setCursorPosition(0);
    editor->setStyleSheet("color:#5c5c5c;background-color:#00000000;border-style:none;");
    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
    QPropertyAnimation *shorter = new QPropertyAnimation(indicator, "geometry", this);
    shorter->setStartValue(indicator->geometry());
    shorter->setEndValue(QRectF(this->width(), this->height() - 7, 4, 4));
    shorter->setDuration(500);
    shorter->setEasingCurve(QEasingCurve::InOutExpo);
    QPropertyAnimation *fade = new QPropertyAnimation(opac, "opacity", this);
    fade->setStartValue(opac->opacity());
    fade->setEndValue(0);
    fade->setDuration(350);
    QPropertyAnimation *move = new QPropertyAnimation(editor, "geometry", this);
    move->setStartValue(editor->geometry());
    int width = QFontMetrics(editor->font()).size(Qt::TextSingleLine, editor->text()).width() + 3;
    if(width > this->width() * 0.7 - margin)
        move->setEndValue(QRectF(this->width() * 0.3, this->height() / 2 - editor->height() / 2, this->width() * 0.7 - margin, editor->height()));
    else
        move->setEndValue(QRectF(this->width() - width - margin, this->height() / 2 - editor->height() / 2, width, editor->height()));
    move->setDuration(500);
    move->setEasingCurve(QEasingCurve::InOutExpo);
    group->addAnimation(shorter);
    group->addAnimation(fade);
    group->addAnimation(move);
    group->start();
}

void customInputText::mousePressEvent(QMouseEvent *){
    mousePressed = true;
}

void customInputText::mouseReleaseEvent(QMouseEvent *){
    if(mousePressed)
    {
        if(onEditing)
        {
            leaveEditEffect();
            onEditing = false;
            curText = editor->text();
            editor->setReadOnly(true);
            emit textEdited(curText);
        }
        else
        {
            if(enabled)
            {
                enterEditEffect();//鼠标按下且释放的时候，打开输入栏
                editor->raise();
                onEditing = true;
                editor->setReadOnly(false);
                editor->setText(curText + "");
                editor->setFocus();
            }
        }
        mousePressed = false;
    }
}

void customInputText::setValue(const QString &text){//设置初始文字
    editor->setText(text);
    editor->setCursorPosition(0);
    curText = text;
    int width = QFontMetrics(editor->font()).size(Qt::TextSingleLine, editor->text()).width() + 3;
    if (!onEditing)
    {
        if (width > this->width() * 0.7 - margin)
            editor->resize(this->width() * 0.7 - margin, editor->height());
        else
            editor->resize(width, editor->height());
        editor->move(this->width() - margin - editor->width(), this->height() / 2 - editor->height() / 2);
    }
    else
    {
        editor->resize(this->width() * 0.7 - margin, editor->height());
        editor->move(this->width() * 0.3, this->height() / 2 - editor->height() / 2 - 2);
    }
}
