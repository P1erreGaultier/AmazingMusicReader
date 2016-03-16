#ifndef PARTITIONWIDGET_HPP
#define PARTITIONWIDGET_HPP

#include <QWidget>
#include <QPainter>

class PartitionWidget : public QWidget
{
    Q_OBJECT

    public:
        explicit PartitionWidget(QWidget *parent = 0);
        ~PartitionWidget();

    protected:
        void paintEvent(QPaintEvent *event);

};

#endif // PARTITIONWIDGET_HPP
