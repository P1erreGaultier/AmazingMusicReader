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

    notes__.append(QString("DO"));
    notes__.append(QString("RÉ"));
    notes__.append(QString("MI"));
    notes__.append(QString("FA"));
    notes__.append(QString("SOL"));
    notes__.append(QString("LA"));
    notes__.append(QString("SI"));

    heightY__ = 30;
    lineWidthX__ = 6;
    lineStartY__ = 5;
    noteStartY__ = 20;

    lastNote__ = -1;
    currentIndex__ = -1;

    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

PartitionWidget::~PartitionWidget()
{
    ;
}

void PartitionWidget::paintEvent(QPaintEvent *event)
{
    widthX__ = (partition__.size() + 1) * lineWidthX__ +2;

    QPainter painter(this);
    painter.setBrush(QBrush(Qt::black));

    sizeX__ = width() / widthX__;
    sizeY__ = height() / heightY__;

    //sizeX__ = sizeY__ = (sizeX__ < sizeY__)? sizeY__: sizeX__;

    if(currentIndex__ >= 0) {
        drawProgressBar__(painter, currentIndex__);
    }

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

    for(QMap<int,int>::const_iterator it = goodNotes__.constBegin(); it != goodNotes__.constEnd(); it++) {
        drawQuarterNote__(painter, it.key()+1, it.value(), Qt::green, true);
    }

    for(QMap<int,int>::const_iterator it = badNotes__.constBegin(); it != badNotes__.constEnd(); it++) {
        drawQuarterNote__(painter, it.key()+1, it.value(), Qt::red, true);
    }
}

void PartitionWidget::drawQuarterNote__(QPainter & painter, int position, int note, const QColor & color, bool noteName) {
    painter.setBrush(QBrush(Qt::black));
    QPen pen = painter.pen();
    pen.setColor(Qt::black);
    painter.setPen(pen);

    int x = sizeX__ + position*sizeX__*lineWidthX__ + sizeX__*lineWidthX__/2;
    int y = (noteStartY__-note)*sizeY__;

    if(!(note%2)) {
        painter.drawLine(QPoint(x-2*sizeX__, y), QPoint(x+2*sizeX__, y));
    }

    painter.setBrush(QBrush(color));
    pen.setColor(color);
    painter.setPen(pen);
    painter.drawEllipse(QPoint(x, y), sizeX__, sizeY__);
    painter.drawLine(QPoint(x+sizeX__, y), QPoint(x+sizeX__,y-sizeY__*5));

    x = sizeX__ + position*sizeX__*lineWidthX__ + sizeX__*2;
    y = (noteStartY__+3)*sizeY__;

    if(noteName) {
        painter.drawText(x, y, notes__.at(note%notes__.size()));
    }
}

void PartitionWidget::drawBarline__(QPainter & painter, int position) {
    int x = sizeX__ + position*sizeX__*lineWidthX__;
    int y1 = (noteStartY__-2)*sizeY__;
    int y2 = y1-sizeY__*2*4;

    painter.setBrush(QBrush(Qt::black));
    QPen pen = painter.pen();
    pen.setColor(Qt::black);
    painter.setPen(pen);

    painter.drawLine(QPoint(x, y1), QPoint(x, y2));
}

void PartitionWidget::drawLinestaff5__(QPainter & painter, int position) {
    painter.setBrush(QBrush(Qt::black));
    QPen pen = painter.pen();
    pen.setColor(Qt::black);
    painter.setPen(pen);

    int x1 = sizeX__ + position*sizeX__*lineWidthX__;
    int x2 = x1 + sizeX__*lineWidthX__;
    int y = (noteStartY__-2)*sizeY__;

    for(int i=0; i<5; i++) {
        painter.drawLine(QPoint(x1, y-sizeY__*2*i), QPoint(x2, y-sizeY__*2*i));
    }
}

void PartitionWidget::drawGClef__(QPainter & painter, int position) {

}

void PartitionWidget::drawProgressBar__(QPainter & painter, int position) {
    int x = sizeX__ + position*sizeX__*lineWidthX__ + sizeX__*lineWidthX__/2;
    int y1 = (noteStartY__)*sizeY__;
    int y2 = y1-sizeY__*2*6;

    painter.setBrush(QBrush(Qt::blue));
    QPen pen = painter.pen();
    pen.setColor(Qt::blue);
    painter.setPen(pen);

    painter.drawLine(QPoint(x, y1), QPoint(x, y2));
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
           if(currentIndex__ >= partition__.size() && playingGame__) {
               emit gameOver();

               playing__ = playingGame__ = false;
               currentIndex__ = -1;

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
