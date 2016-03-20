#include "partitionoptwidget.hpp"

#include <QDir>
#include <QDebug>

PartitionOptWidget::PartitionOptWidget(QWidget *parent) : QWidget(parent)
{
    demo__.setParent(this);
    demo__.setText(QString("Demo"));
    play__.setParent(this);
    play__.setText(QString("Jouer"));
    difficulty__.setParent(this);
    partition__.setParent(this);
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

    layout__.addWidget(&difficultyLabel__);
    layout__.addWidget(&difficulty__);
    layout__.addWidget(&partitionLabel__);
    layout__.addWidget(&partition__);
    layout__.addWidget(&demo__);
    layout__.addWidget(&play__);

    setLayout(&layout__);
}

void PartitionOptWidget::difficultyChanged__(const QString & text) {
    partition__.clear();
    QDir dir(":/partition/"+text);
    QStringList dirList = dir.entryList();
    for(int i=0; i<dirList.size(); i++) {
        partition__.addItem(dirList.at(i));
    }
}

void PartitionOptWidget::partitionChanged__(const QString & text) {
    emit partitionChanged(QString(":/partition/"+difficulty__.currentText()+"/"+text));
}

void PartitionOptWidget::playDemo__() {
    disable();
    emit playDemo();
}

void PartitionOptWidget::playGame__() {
    disable();
    emit playGame();
}

void PartitionOptWidget::enable() {
    setEnabled(true);
}

void PartitionOptWidget::disable() {
    setDisabled(true);
}
