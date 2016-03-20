#include "partitionwidget.hpp"

#include <QPainter>
#include <QPen>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include <QWidget>
#include <QTextItem>
#include <QThread>
#include <QFontMetrics>

PartitionWidget::PartitionWidget(QWidget *parent) : QWidget(parent)
{
    uSingleBarline__ = QString("𝄀");
    uLineStaff1__ = QString("𝄖");
    uLineStaff5__ = QString("𝄚");
    uGClef__ = QString("𝄞");
    uQuarterNote__ = QString("𝅘𝅥");
    uNoteheadBlack__ = QString("𝅘");

    heightY__ = 25;
    lineWidthX__ = 3;
    lineStartY__ = 5;
    noteStartY__ = 2;

    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

PartitionWidget::~PartitionWidget()
{
    ;
}

void PartitionWidget::paintEvent(QPaintEvent *event)
{
    widthX__ = (partition__.size() + 1) * lineWidthX__ +1;

    QPainter painter(this);
    painter.setBrush(QBrush(Qt::black));

    sizeX__ = this->width() / widthX__;
    sizeY__ = this->height() / heightY__;

    sizeX__ = sizeY__ = (sizeX__ < sizeY__)? sizeY__: sizeX__;


    drawLinestaff5__(painter, 0);
    drawBarline__(painter, 0);
    // add GKey

    /*QFont font = painter.font();
    font.setPointSize(font.pointSize() * 6);
    painter.setFont(font);

    QFontMetrics metrics(font, painter.device());
    qDebug() << metrics.height();
    qDebug() << metrics.width(uLineStaff5__);
    qDebug() << metrics.size(0,uLineStaff5__);
    qDebug() << metrics.size(0, uNoteheadBlack__);*/

    /*painter.drawText(0,this->height()/2,uLineStaff5__);
    painter.drawText(0,this->height()/2,uQuarterNote__);
    painter.drawText(metrics.width(uLineStaff5__),this->height()/2,uLineStaff5__);
    painter.drawText(metrics.width(uLineStaff5__),this->height()/2,uQuarterNote__);*/

    for(int i = 0; i<partition__.size(); i++) {
        if(i%4 == 0) {
            drawBarline__(painter, i+1);
        }
        drawLinestaff5__(painter, i+1);
        drawQuarterNote__(painter, i+1, partition__.at(i));
    }
    drawBarline__(painter, partition__.size()+1);

    /*QPoint p;
        QVector<QPoint> V;

        painter.setPen(QPen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap));
        QFont font = painter.font();
        font.setPointSize(font.pointSize() * 8);
        painter.setFont(font);
        painter.drawText(-10, 130, clef);


        QFile file(":/partition/easy/partition1.txt");
        if(!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "error", file.errorString());
        }

        QTextStream in(&file);

        for (int i = 0; i < V.size(); i++) {
             QString line = in.readLine();
             p.setX((1+i)*100-50);
             p.setY(line.toInt()*12.5-3);
             V[i] = p;
            }
         file.close();

        //Tracé des notes
        //painter.setPen(QPen(Qt::blue, 12, Qt::SolidLine, Qt::RoundCap));
        for (int i = 0; i < V.size(); ++i) {
            painter.drawText(V.at(i), quarter_note);
        }


        //Creation de la grille de la partition
        painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
        //horizontal
        painter.drawLine(0, 50,50 + V.size()*100,50);
        painter.drawLine(0, 75,50 + V.size()*100,75);
        painter.drawLine(0, 100,50 + V.size()*100,100);
        painter.drawLine(0, 125,50 + V.size()*100,125);
        painter.drawLine(0, 150,50 + V.size()*100,150);

        //vertical
        for (int i = 0; i <= V.size()/4; ++i) {
            painter.drawLine(i*400+50, 50,i*400+50,150);
        }*/
}

void PartitionWidget::drawQuarterNote__(QPainter & painter, int position, int note) {
    painter.drawEllipse(QPoint(position*sizeX__*lineWidthX__+sizeX__*lineWidthX__/2, sizeY__*(note+noteStartY__)/2), sizeX__/2, sizeY__/2);
    painter.drawLine(QPoint(position*sizeX__*lineWidthX__+sizeX__*lineWidthX__/2+sizeX__/2, sizeY__*(note+noteStartY__)/2), QPoint(position*sizeX__*lineWidthX__+sizeX__*lineWidthX__/2+sizeX__/2,sizeY__*(note+noteStartY__-3)/2));
}

void PartitionWidget::drawBarline__(QPainter & painter, int position) {
    painter.drawLine(QPoint(position*sizeX__*lineWidthX__, lineStartY__*sizeY__), QPoint(position*sizeX__*lineWidthX__, (lineStartY__+4)*sizeY__));
}

void PartitionWidget::drawLinestaff5__(QPainter & painter, int position) {
    for(int i=0; i<5; i++) {
        painter.drawLine(QPoint(position*sizeX__*lineWidthX__, (lineStartY__+i)*sizeY__), QPoint((position+1)*sizeX__*lineWidthX__, (lineStartY__+i)*sizeY__));
    }
}

void PartitionWidget::drawGClef__(QPainter & painter, int position) {

}

void PartitionWidget::partitionChanged(const QString &partition) {
    partition__.clear();

    qDebug() << partition;

    QFile file(partition);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        partition__.append(line.toInt());
    }

    qDebug() << "OK";

    update();
}

void PartitionWidget::playDemo() {
    for(int i=0; i<partition__.size(); i++) {
        keyPushed(partition__.at(i));
        emit pushKey(partition__.at(i));
        QThread::msleep(500);
    }
    emit demoOver();
}

void PartitionWidget::playGame() {
    ;
}

void PartitionWidget::keyPushed(int key) {
    ;
}
