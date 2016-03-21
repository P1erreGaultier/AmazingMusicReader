#ifndef KEYBOARDWIDGET_HPP
#define KEYBOARDWIDGET_HPP

#include <QHBoxLayout>
#include <QPushButton>
#include <QSignalMapper>
#include <QTimer>
#include <QWidget>

/**
* La classe qui represente le clavier
* @aut
*/
class KeyboardWidget : public QWidget
{
    Q_OBJECT

private:
    QString style__;
    QSignalMapper * signalMapper__;
    QHBoxLayout layout__;
    QVector<QTimer*> timers__;
    QVector<QPushButton*> buttons__;
    QVector<QString> notes__;

public:
    explicit KeyboardWidget(QWidget *parent = 0);
    ~KeyboardWidget();

signals:
    void keyPushed(int key);

private slots:
    void pullKey__(int key);

public slots:
    void showNotes(int state);
    void pushKey(int key);
    void setStyle(QString style);
};

#endif // KEYBOARDWIDGET_HPP
