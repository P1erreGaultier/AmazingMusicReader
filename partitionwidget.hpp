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
    int lineWidthX__;
    int lineStartY__;
    int noteStartY__;
    int widthX__;
    int heightY__;
    int sizeX__;
    int sizeY__;
    QVector<QString> notes__;
    QVector<int> partition__;
    QString uSingleBarline__;
    QString uLineStaff1__;
    QString uLineStaff5__;
    QString uGClef__;
    QString uQuarterNote__;
    QString uNoteheadBlack__;

    void drawQuarterNote__(QPainter & painter, int position, int note);
    void drawBarline__(QPainter & painter, int position);
    void drawLinestaff5__(QPainter & painter, int position);
    void drawGClef__(QPainter & painter, int position);

signals:
    void pushKey(int key);
    void demoOver();
    void gameOver();

public slots:
    void partitionChanged(const QString &partition);
    void playDemo();
    void playGame();
    void keyPushed(int key);
};

#endif // PARTITIONWIDGET_HPP
