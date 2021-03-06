#include "partitionoptwidget.hpp"

#include <QDir>
#include <QDebug>

/**
* Constructeur
* Crée un PartitionOptWidget
* @param parent Widget parent
*/
PartitionOptWidget::PartitionOptWidget(QWidget *parent) : QWidget(parent) {
  groupBox__.setParent(this);
  groupBox__.setTitle(QString("Options de la partition"));
  groupBox__.setStyleSheet(
      QString("QGroupBox{border:1px solid "
              "gray;border-radius:3px;margin-top:0.5em;}QGroupBox::title{"
              "subcontrol-origin:margin;left:4px;padding:0 2px 0 2px;}"));
  demo__.setParent(this);
  demo__.setText(QString("Démo"));
  demo__.setStyleSheet(
      QString("QPushButton{font-size:18pt;font-weight:bold;}"));
  demo__.setDisabled(true);
  play__.setParent(this);
  play__.setText(QString("Jouer"));
  play__.setStyleSheet(
      QString("QPushButton{font-size:18pt;font-weight:bold;}"));
  play__.setDisabled(true);
  difficulty__.setParent(this);
  difficulty__.addItem(QString());
  partition__.setParent(this);
  partition__.addItem(QString());
  partition__.setDisabled(true);
  difficultyLabel__.setParent(this);
  difficultyLabel__.setText(QString("Difficulté:"));
  difficultyLabel__.setAlignment(Qt::AlignBottom);
  partitionLabel__.setParent(this);
  partitionLabel__.setText(QString("Partition:"));
  partitionLabel__.setAlignment(Qt::AlignBottom);

  connect(&difficulty__, SIGNAL(currentTextChanged(const QString &)), this,
          SLOT(difficultyChanged__(const QString &)));
  connect(&partition__, SIGNAL(currentTextChanged(const QString &)), this,
          SLOT(partitionChanged__(const QString &)));
  connect(&demo__, SIGNAL(clicked()), this, SLOT(playDemo__()));
  connect(&play__, SIGNAL(clicked()), this, SLOT(playGame__()));

  QDir dir(":/partition");
  QStringList dirList = dir.entryList();
  for (int i = 0; i < dirList.size(); i++) {
    difficulty__.addItem(dirList.at(i));
  }

  groupBoxLayout__.addStretch();
  groupBoxLayout__.addWidget(&difficultyLabel__);
  groupBoxLayout__.addWidget(&difficulty__);
  groupBoxLayout__.addStretch();
  groupBoxLayout__.addWidget(&partitionLabel__);
  groupBoxLayout__.addWidget(&partition__);
  groupBoxLayout__.addStretch();
  groupBoxLayout__.addWidget(&demo__);
  groupBoxLayout__.addWidget(&play__);
  groupBoxLayout__.addStretch();

  groupBox__.setLayout(&groupBoxLayout__);

  layout__.addWidget(&groupBox__);

  setLayout(&layout__);
}
/**
 * Fonction qui change les partitions disponibles quand la difficulté est
 * modifié
 * @param text la nouvelle difficulté
 */
void PartitionOptWidget::difficultyChanged__(const QString &text) {
  qInfo("difficulty combo box changed");
  partition__.clear();
  partition__.addItem(QString());
  if (!text.isEmpty()) {
    partition__.setEnabled(true);

    QDir dir(":/partition/" + text);
    QStringList dirList = dir.entryList();
    for (int i = 0; i < dirList.size(); i++) {
      partition__.addItem(dirList.at(i));
    }
  } else {
    partition__.setDisabled(true);
  }
}

/**
 * Fonction qui active les boutons demo et jouer et charge une partition quand
 * elle est selectionnée
 * @param text la partition
 */
void PartitionOptWidget::partitionChanged__(const QString &text) {
  qInfo("partition combo box changed");
  if (difficulty__.currentText().isEmpty() ||
      partition__.currentText().isEmpty()) {
    demo__.setDisabled(true);
    play__.setDisabled(true);
  } else {
    demo__.setEnabled(true);
    play__.setEnabled(true);
  }
  emit partitionChanged(
      QString(":/partition/" + difficulty__.currentText() + "/" + text));
}
/**
 * Fonction qui envoie le signal pour jouer la demo de la partition selectionée
 */
void PartitionOptWidget::playDemo__() {
  qInfo("demo button clicked");
  disable();
  emit playDemo();
}

/**
 * Fonction qui envoie le signal pour lancer la partie de la partition
 * selectionée
 */
void PartitionOptWidget::playGame__() {
  qInfo("play button clicked");
  disable();
  emit playGame();
}

void PartitionOptWidget::enable() { setEnabled(true); }

void PartitionOptWidget::disable() { setDisabled(true); }
