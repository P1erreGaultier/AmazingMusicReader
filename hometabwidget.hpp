#ifndef HOMETABWIDGET_H
#define HOMETABWIDGET_H

#include <QLabel>
#include <QObject>
#include <QVBoxLayout>
#include <QWidget>
#include <QPixmap>
#include <QPushButton>
#include <QSignalMapper>

class HomeTabWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HomeTabWidget(QWidget *parent = 0);


private:
    QLabel labelImage__;
    QLabel labelText__;
    QVBoxLayout layout__;
    QPushButton *btnPerformance;
    QPushButton *btnJouer;


signals:

public slots:
};

#endif // HOMETABWIDGET_H
