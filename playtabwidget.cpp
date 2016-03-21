#include "playtabwidget.hpp"

/**
* Constructeur
* Crée un PlayTabWidget
* @param parent Widget parent
*/
PlayTabWidget::PlayTabWidget(QWidget *parent) : QWidget(parent) {
  keyboard__.setParent(this);
  keyboardOpt__.setParent(this);
  partition__.setParent(this);
  partitionOpt__.setParent(this);

  /*connect(&keyboardOptNotes__ ,
   * SIGNAL(stateChanged(int)),&keyboard__,SLOT(showNotes(int)));*/
  connect(&partitionOpt__, SIGNAL(partitionChanged(const QString &)),
          &partition__, SLOT(partitionChanged(const QString &)));
  connect(&partitionOpt__, SIGNAL(playDemo()), &partition__, SLOT(playDemo()));
  connect(&partition__, SIGNAL(demoOver()), &partitionOpt__, SLOT(enable()));
  connect(&partitionOpt__, SIGNAL(playGame()), &partition__, SLOT(playGame()));
  connect(&partition__, SIGNAL(gameOver()), &partitionOpt__, SLOT(enable()));
  connect(&partition__, SIGNAL(pushKey(int)), &keyboard__, SLOT(pushKey(int)));
  connect(&keyboard__, SIGNAL(keyPushed(int)), &partition__,
          SLOT(keyPushed(int)));
  connect(&keyboardOpt__, SIGNAL(showNotes(int)), &keyboard__,
          SLOT(showNotes(int)));

  layout__.addWidget(&partitionOpt__, 0, 0);
  layout__.addWidget(&partition__, 0, 1);
  layout__.addWidget(&keyboard__, 1, 1);
  layout__.addWidget(&keyboardOpt__, 1, 0);

  this->setLayout(&layout__);
}
