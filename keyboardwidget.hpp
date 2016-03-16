#ifndef KEYBOARDWIDGET_HPP
#define KEYBOARDWIDGET_HPP

#include <QHBoxLayout>
#include <QPushButton>
#include <QSignalMapper>
#include <QSound>
#include <QWidget>

class KeyboardWidget : public QWidget
{
    Q_OBJECT

private:
    QSignalMapper * signalMapper__;
    QHBoxLayout layout__;
    QVector<QPushButton*> buttons__;
    QVector<QString> notes__;
    QVector<QSound*> sounds__;

public:
    KeyboardWidget(QWidget *parent = 0);
    ~KeyboardWidget();

signals:
    void keyPushed(int key);

public slots:
    void showNotes(bool show);
    void pushKey(int key);
    void setStyle(QString style);
};

#endif // KEYBOARDWIDGET_HPP
