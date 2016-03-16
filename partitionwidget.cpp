#include "partitionwidget.hpp"

#include <QPainter>
#include <QPen>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include <QWidget>

PartitionWidget::PartitionWidget(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(800, 200);
}

PartitionWidget::~PartitionWidget()
{
    ;
}

void PartitionWidget::paintEvent(QPaintEvent *event)
    {
        QPainter painter(this);
        QPoint p;
        QVector<QPoint> V(12);

        QString clef("𝄚𝄞𝄚");
        QString quarter_note("♩");

        //Creation de la grille de la partition
        painter.setPen(QPen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap));
        //horizontal
        painter.drawLine(0, 50,1250,50);
        painter.drawLine(0, 75,1250,75);
        painter.drawLine(0, 100,1250,100);
        painter.drawLine(0, 125,1250,125);
        painter.drawLine(0, 150,1250,150);

        //vertical
        painter.drawLine(50, 50,50,150);
        painter.drawLine(450, 50,450,150);
        painter.drawLine(850, 50,850,150);
        painter.drawLine(1250,50,1250,150);


        QFont font = painter.font();
        font.setPointSize(font.pointSize() * 8);
        painter.setFont(font);
        painter.drawText(50, 150, clef);

        //font.setPointSize(font.pointSize() / 2);
        //painter.setFont(font);




        //Creation des points representant les notes dans le vector V
        QFile file(":/partoch1.txt");
        if(!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "error", file.errorString());
        }

        QTextStream in(&file);

        for (int i = 0; i < V.size(); i++) {
             QString line = in.readLine();
             p.setX((1+i)*100);
             p.setY(line.toInt()*12.5);
             V[i] = p;
            }
         file.close();

        //Tracé des points
        //painter.setPen(QPen(Qt::blue, 12, Qt::SolidLine, Qt::RoundCap));
        for (int i = 0; i < V.size(); ++i) {
            //painter.drawPoint(V.at(i));
            painter.drawText(V.at(i), quarter_note);
        }
    }
