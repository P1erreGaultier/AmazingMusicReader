#ifndef PARTITIONWIDGET_HPP
#define PARTITIONWIDGET_HPP

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
class PartitionWidget : public QWidget
{

    protected:
        void paintEvent(QPaintEvent *event);

};
#endif // PARTITIONWIDGET_HPP
