#ifndef KEYBOARDWIDGET_H
#define KEYBOARDWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

class KeyboardWidget : public QWidget
{
    Q_OBJECT

private:
    QHBoxLayout layout__;
    QVector<QPushButton*> buttons__;

public:
    explicit KeyboardWidget(QWidget *parent = 0);
    virtual ~KeyboardWidget();
    /*void showNoteName();*/
    /*void hideNoteName();*/

signals:

public slots:
};

#endif // KEYBOARDWIDGET_H
