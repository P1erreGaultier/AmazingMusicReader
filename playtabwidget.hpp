#ifndef PLAYTABWIDGET_H
#define PLAYTABWIDGET_H

#include "keyboardwidget.hpp"
#include "keyboardoptwidget.hpp"
#include "partitionwidget.hpp"
#include "partitionoptwidget.hpp"

#include <QCheckBox>
#include <QObject>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>

/**
* La classe qui represente l'onglet de jeu
* @author Alexis Giraudet & Pierre Gaultier
*/
class PlayTabWidget : public QWidget {
  Q_OBJECT
public:
  explicit PlayTabWidget(QWidget *parent = 0);

private:
  QGridLayout layout__;
  KeyboardWidget keyboard__;
  KeyboardOptWidget keyboardOpt__;
  PartitionWidget partition__;
  PartitionOptWidget partitionOpt__;

signals:

public slots:
};

#endif // PLAYTABWIDGET_H
