#ifndef KEYBOARDWIDGET_HPP
#define KEYBOARDWIDGET_HPP

#include <QHBoxLayout>
#include <QPushButton>
#include <QWidget>

class KeyboardWidget : public QWidget
{
    Q_OBJECT

private:
    QHBoxLayout layout__;
    QVector<QPushButton*> buttons__;
    QVector<QString> notes__;

public:
    KeyboardWidget(QWidget *parent = 0);
    ~KeyboardWidget();

public slots:
    void showNotes(bool show);
    void pushKey(int key);
};

#endif // KEYBOARDWIDGET_HPP
