#include "partitionwidget.hpp"

#include <QDateTime>
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
#include <QInputDialog>

PartitionWidget::PartitionWidget(QWidget *parent) : QWidget(parent)
{
    timer__.setParent(this);

    connect(&timer__, SIGNAL(timeout()), this, SLOT(playDemo__()));

    uSingleBarline__ = QString("𝄀");
    uLineStaff1__ = QString("𝄖");
    uLineStaff5__ = QString("𝄚");
    uGClef__ = QString("𝄞");
    uQuarterNote__ = QString("𝅘𝅥");
    uNoteheadBlack__ = QString("𝅘");
    uBlackStar__ = QString("★");
    uWhiteStar__ = QString("☆");

    heightY__ = 25;
    lineWidthX__ = 3;
    lineStartY__ = 5;
    noteStartY__ = 2;

    currentIndex__ = -1;
    lastNote__ = -1;

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
    if(lastNote__ >= 0) {
        drawQuarterNote__(painter, 0, lastNote__, Qt::blue, true);
    } else {
        //draw GClef
    }

    qDebug() << "refresh";

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
        drawQuarterNote__(painter, i+1, partition__.at(i), Qt::black, false);
    }
    drawBarline__(painter, partition__.size()+1);

    painter.setBrush(QBrush(Qt::green));
    QPen pen = painter.pen();
    pen.setColor(Qt::green);
    painter.setPen(pen);
    for(QMap<int,int>::const_iterator it = goodNotes__.constBegin(); it != goodNotes__.constEnd(); it++) {
        drawQuarterNote__(painter, it.key()+1, it.value(), Qt::green, true);
    }

    painter.setBrush(QBrush(Qt::red));
    pen = painter.pen();
    pen.setColor(Qt::red);
    painter.setPen(pen);
    for(QMap<int,int>::const_iterator it = badNotes__.constBegin(); it != badNotes__.constEnd(); it++) {
        drawQuarterNote__(painter, it.key()+1, it.value(), Qt::red, true);
    }
}

void PartitionWidget::drawQuarterNote__(QPainter & painter, int position, int note, const QColor & color, bool noteName) {
    painter.drawEllipse(QPoint(position*sizeX__*lineWidthX__+sizeX__*lineWidthX__/2, sizeY__*(note+noteStartY__)/2), sizeX__/2, sizeY__/2);
    painter.drawLine(QPoint(position*sizeX__*lineWidthX__+sizeX__*lineWidthX__/2+sizeX__/2, sizeY__*(note+noteStartY__)/2), QPoint(position*sizeX__*lineWidthX__+sizeX__*lineWidthX__/2+sizeX__/2,sizeY__*(note+noteStartY__-3)/2));
    if(!(note%2)) {
        painter.drawLine(QPoint(position*sizeX__*lineWidthX__, sizeY__*(note+noteStartY__)/2), QPoint(position*sizeX__*lineWidthX__+sizeX__*lineWidthX__/2, sizeY__*(note+noteStartY__)/2));
    }
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
    goodNotes__.clear();
    badNotes__.clear();
    lastNote__ = -1;
    currentIndex__ = 0;
    playing__ = true;
    playingGame__ = false;

    update();

    timer__.start(500);
}

void PartitionWidget::playDemo__() {
    if(partition__.size() == (goodNotes__.size()+badNotes__.size())) {
        timer__.stop();
        emit demoOver();
    } else {
        int key = partition__.at(goodNotes__.size()+badNotes__.size());
        keyPushed(key);
        emit pushKey(key);
    }
}

void PartitionWidget::playGame() {
    goodNotes__.clear();
    badNotes__.clear();
    lastNote__ = -1;
    currentIndex__ = 0;
    playing__ = true;
    playingGame__ = true;

    update();
}

void PartitionWidget::keyPushed(int key) {
   if(key < 15) {
       lastNote__ = key;

       if(playing__) {
           if(currentIndex__ < partition__.size()) {
               if(partition__.at(currentIndex__) == key) {
                   goodNotes__.insert(currentIndex__, key);
               } else {
                   badNotes__.insert(currentIndex__, key);
               }
               currentIndex__++;
           }
           if(currentIndex__ == partition__.size() && playingGame__) {
               emit gameOver();

               QString score = uBlackStar__.repeated((int)(goodNotes__.size()/partition__.size()*5.0+0.5));
               score.append(uWhiteStar__.repeated((int)(5.0-goodNotes__.size()/partition__.size()*5.0)));

               if(playerName__.isEmpty()) {
                   playerName__ = QInputDialog::getText(this, QString("Title"), QString("label")+score, QLineEdit::Normal, QString());
               } else {
                   QMessageBox messageBox;
                   messageBox.setText(QString("Votre score: ")+score/*QString::number(goodNotes__.size())+QString("/")+QString::number(partition__.size())*/);
                   messageBox.exec();
               }

               if(!playerName__.isEmpty()) {
                   QString buff;
                   buff.append(playerName__).append(QString(";"));
                   buff.append(QDateTime::currentDateTime().toString()).append(QString(";"));
                   buff.append(QString::number(goodNotes__.size())).append(QString(";"));
                   buff.append(QString::number(partition__.size())).append(QString(";"));
                   buff.append(QString("\n"));

                   QFile scoreFile(QString("score.csv"));
                   if(scoreFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
                       QTextStream scoreStream(&scoreFile);
                       scoreStream << buff;
                   }
               }
           }
       }

       update();
   }
}
