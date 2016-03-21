#include "partitionoptwidget.hpp"

#include <QDir>
#include <QDebug>

PartitionOptWidget::PartitionOptWidget(QWidget *parent) : QWidget(parent)
{
    groupBox__.setParent(this);
    groupBox__.setTitle(QString("Options de la partition"));
    groupBox__.setStyleSheet(QString("QGroupBox{border:1px solid gray;border-radius:3px;margin-top:0.5em;}QGroupBox::title{subcontrol-origin:margin;left:4px;padding:0 2px 0 2px;}"));
    demo__.setParent(this);
    demo__.setText(QString("Démo"));
    demo__.setStyleSheet(QString("QPushButton{font-size:18pt;font-weight:bold;}"));
    demo__.setDisabled(true);
    play__.setParent(this);
    play__.setText(QString("Jouer"));
    play__.setStyleSheet(QString("QPushButton{font-size:18pt;font-weight:bold;}"));
    play__.setDisabled(true);
    difficulty__.setParent(this);
    difficulty__.addItem(QString());
    partition__.setParent(this);
    partition__.addItem(QString());
    difficultyLabel__.setParent(this);
    difficultyLabel__.setText(QString("Difficulté:"));
    partitionLabel__.setParent(this);
    partitionLabel__.setText(QString("Partition:"));

    connect(&difficulty__, SIGNAL(currentTextChanged(const QString &)), this, SLOT(difficultyChanged__(const QString &)));
    connect(&partition__, SIGNAL(currentTextChanged(const QString &)), this, SLOT(partitionChanged__(const QString &)));
    connect(&demo__, SIGNAL(clicked()), this, SLOT(playDemo__()));
    connect(&play__, SIGNAL(clicked()), this, SLOT(playGame__()));

    QDir dir(":/partition");
    QStringList dirList = dir.entryList();
    for(int i=0; i<dirList.size(); i++) {
        difficulty__.addItem(dirList.at(i));
    }

    groupBoxLayout__.addWidget(&difficultyLabel__);
    groupBoxLayout__.addWidget(&difficulty__);
    groupBoxLayout__.addWidget(&partitionLabel__);
    groupBoxLayout__.addWidget(&partition__);
    groupBoxLayout__.addWidget(&demo__);
    groupBoxLayout__.addWidget(&play__);

    groupBox__.setLayout(&groupBoxLayout__);

    layout__.addWidget(&groupBox__);

    setLayout(&layout__);
}

void PartitionOptWidget::difficultyChanged__(const QString & text) {
    qInfo("difficulty combo box changed");
    partition__.clear();
    partition__.addItem(QString());
    QDir dir(":/partition/"+text);
    QStringList dirList = dir.entryList();
    for(int i=0; i<dirList.size(); i++) {
        partition__.addItem(dirList.at(i));
    }
}

void PartitionOptWidget::partitionChanged__(const QString & text) {
    qInfo("partition combo box changed");
    if(difficulty__.currentText().isEmpty() || partition__.currentText().isEmpty()) {
        demo__.setDisabled(true);
        play__.setDisabled(true);
    } else {
        demo__.setEnabled(true);
        play__.setEnabled(true);
    }
    emit partitionChanged(QString(":/partition/"+difficulty__.currentText()+"/"+text));
}

void PartitionOptWidget::playDemo__() {
    qInfo("demo button clicked");
    disable();
    emit playDemo();
}

void PartitionOptWidget::playGame__() {
    qInfo("play button clicked");
    disable();
    emit playGame();
}

void PartitionOptWidget::enable() {
    setEnabled(true);
}

void PartitionOptWidget::disable() {
    setDisabled(true);
}
