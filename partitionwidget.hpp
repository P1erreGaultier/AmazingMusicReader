#ifndef PARTITIONWIDGET_HPP
#define PARTITIONWIDGET_HPP

#include <QWidget>
#include <QPainter>
#include <QVector>

class PartitionWidget : public QWidget
{
    Q_OBJECT

    public:
        explicit PartitionWidget(QWidget *parent = 0);
        ~PartitionWidget();

    protected:
        void paintEvent(QPaintEvent *event);

    private:
        QVector<int> notes__;
        QString uSingleBarline__;
        QString uLineStaff5__;
        QString uGClef__;
        QString uQuarterNote__;
        QString uNoteheadBlack__;
};

#endif // PARTITIONWIDGET_HPP
