#include "partitionwidget.hpp"

#include <QPainter>
#include <QPen>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include <QWidget>
#include <QTextItem>
#include <QFontMetrics>

PartitionWidget::PartitionWidget(QWidget *parent) : QWidget(parent)
{
    uSingleBarline__ = QString("𝄀");
    uLineStaff1__ = QString("𝄖");
    uLineStaff5__ = QString("𝄚");
    uGClef__ = QString("𝄞");
    uQuarterNote__ = QString("𝅘𝅥");
    uNoteheadBlack__ = QString("𝅘");

    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

PartitionWidget::~PartitionWidget()
{
    ;
}

void PartitionWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QFont font = painter.font();
    font.setPointSize(font.pointSize() * 6);
    painter.setFont(font);

    QFontMetrics metrics(font);
    qDebug() << metrics.height();
    qDebug() << metrics.width("");
    qDebug() << metrics.boundingRect(uLineStaff5__);

    /*painter.drawText(0,this->height()/2,uLineStaff5__);
    painter.drawText(0,this->height()/2,uQuarterNote__);
    painter.drawText(metrics.width(uLineStaff5__),this->height()/2,uLineStaff5__);
    painter.drawText(metrics.width(uLineStaff5__),this->height()/2,uQuarterNote__);*/

    for(int i = 0; i<partition__.size(); i++) {
        if(i%4 == 0) {
            painter.drawText(i*metrics.width(uLineStaff5__), this->height()/2, uSingleBarline__);
        }
        painter.drawText(i*metrics.width(uLineStaff5__), this->height()/2, uLineStaff5__);

        painter.drawText(i*metrics.width(uLineStaff5__)+metrics.height()/2, this->height()/2+i*metrics.boundingRect(uLineStaff5__).height()/12 - metrics.height(), uQuarterNote__);
    }
    painter.drawText(partition__.size()*metrics.width(uLineStaff5__), this->height()/2, uSingleBarline__);

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

void PartitionWidget::currentPartitionChanged(const QString &partition) {
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
