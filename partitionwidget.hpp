#ifndef PARTITIONWIDGET_HPP
#define PARTITIONWIDGET_HPP

#include <QMap>
#include <QPainter>
#include <QString>
#include <QTimer>
#include <QVector>
#include <QWidget>

/**
* La classe qui represente la partition
* @author Alexis Giraudet & Pierre Gaultier
*/
class PartitionWidget : public QWidget {
  Q_OBJECT

public:
  /**
  * Constructeur
  * Crée un PartitionWidget
  * @param parent Widget parent
  */
  explicit PartitionWidget(QWidget *parent = 0);
  ~PartitionWidget();

protected:
  void paintEvent(QPaintEvent *event);

private:
  QTimer timer__;
  int lineWidthX__;
  int lineStartY__;
  int noteStartY__;
  int widthX__;
  int heightY__;
  int sizeX__;
  int sizeY__;
  int lastNote__;
  int currentIndex__;
  QVector<QString> notes__;
  QVector<int> partition__;
  QMap<int, int> goodNotes__;
  QMap<int, int> badNotes__;
  QString uSingleBarline__;
  QString uLineStaff1__;
  QString uLineStaff5__;
  QString uGClef__;
  QString uQuarterNote__;
  QString uNoteheadBlack__;
  QString uBlackStar__;
  QString uWhiteStar__;
  bool playing__;
  bool playingGame__;
  QString playerName__;
  QString partitionName__;

  void drawQuarterNote__(QPainter &painter, int position, int note,
                         const QColor &color, bool noteName);
  void drawBarline__(QPainter &painter, int position);
  void drawLinestaff5__(QPainter &painter, int position);
  void drawGClef__(QPainter &painter, int position);
  void drawProgressBar__(QPainter &painter, int position);

signals:
  void pushKey(int key);
  void demoOver();
  void gameOver();

private slots:
  void playDemo__();

public slots:
  void partitionChanged(const QString &partition);
  void playDemo();
  void playGame();
  void keyPushed(int key);
};

#endif // PARTITIONWIDGET_HPP
