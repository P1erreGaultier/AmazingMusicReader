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

    private:
        QString singleBarline__;
        QString lineStaff5__;
        QString gClef__;
        QString quarterNote__;
        QString noteheadBlack__;
};

#endif // PARTITIONWIDGET_HPP
