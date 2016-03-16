#ifndef PLAYTABWIDGET_H
#define PLAYTABWIDGET_H

#include "keyboardwidget.hpp"
#include "partitionwidget.hpp"

#include <QCheckBox>
#include <QObject>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>

class PlayTabWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PlayTabWidget(QWidget *parent = 0);

private:
    QGridLayout layout__;
    KeyboardWidget keyboard__;
    PartitionWidget partition__;
    QCheckBox keyboardOptNotes__;
    QPushButton start__;

signals:

public slots:
};

#endif // PLAYTABWIDGET_H
