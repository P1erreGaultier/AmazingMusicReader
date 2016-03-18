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
    QVector<QString> notes__;
    QVector<int> partition__;
    QString uSingleBarline__;
    QString uLineStaff1__;
    QString uLineStaff5__;
    QString uGClef__;
    QString uQuarterNote__;
    QString uNoteheadBlack__;

public slots:
    void currentPartitionChanged(const QString &partition);
};

#endif // PARTITIONWIDGET_HPP
