#ifndef SCORETABWIDGET_H
#define SCORETABWIDGET_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
class ScoreTabWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ScoreTabWidget(QWidget *parent = 0);

private:
    QGridLayout layout__;
    QLabel labelText1__;
    QLabel labelText2__;
    QLabel labelText3__;

signals:

public slots:
};

#endif // SCORETABWIDGET_H
