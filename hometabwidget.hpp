#ifndef HOMETABWIDGET_H
#define HOMETABWIDGET_H

#include <QLabel>
#include <QObject>
#include <QVBoxLayout>
#include <QWidget>

class HomeTabWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HomeTabWidget(QWidget *parent = 0);

private:
    QLabel label__;
    QVBoxLayout layout__;

signals:

public slots:
};

#endif // HOMETABWIDGET_H
