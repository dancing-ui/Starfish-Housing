#ifndef CUSTOMINPUTTEXT_H
#define CUSTOMINPUTTEXT_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGraphicsOpacityEffect>
#include <QEvent>
#include <QTimer>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QDebug>
class customInputText : public QWidget
{
    Q_OBJECT
public:
    explicit customInputText(QWidget *parent = nullptr);
    void init();
    QLineEdit* lineEditor(){return editor;}
    QString value(){return editor->text();}

    void setValue(const QString &text);
    void setValidator(QValidator *vali){editor->setValidator(vali);}
    void setEnabled(bool enable = true){enabled = enable;}
    void enterEditEffect();
    void leaveEditEffect();

    QLineEdit *editor;
private:
    const int margin = 10;
    const int spacing = 10;

    QWidget *bgWidget;
    QWidget *indicator;
    QGraphicsOpacityEffect *opac;

    QString curText = "";
    bool mousePressed = false;
    bool onEditing = false;

    bool enabled = true;

    //重写事件都要写override
    void mousePressEvent(QMouseEvent *)override;
    void mouseReleaseEvent(QMouseEvent *)override;
    void resizeEvent(QResizeEvent *)override;
signals:
    void textEdited(QString text);
};

#endif // CUSTOMINPUTTEXT_H
