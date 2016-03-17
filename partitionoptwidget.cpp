#include "partitionoptwidget.hpp"

#include <QDir>
#include <QDebug>

PartitionOptWidget::PartitionOptWidget(QWidget *parent) : QWidget(parent)
{
    play__.setParent(this);
    play__.setText(QString("Jouer"));
    difficulty__.setParent(this);
    partition__.setParent(this);

    QDir dir(":/partition");
    QStringList dirList = dir.entryList();
    for(int i=0; i<dirList.size(); i++) {
        difficulty__.addItem(dirList.at(i));
    }

    connect(&difficulty__, SIGNAL(currentTextChanged(const QString &)), this, SLOT(difficultyChanged(const QString &)));
    connect(&play__, SIGNAL(clicked()), this, SLOT(start()));

    layout__.addWidget(&difficulty__);
    layout__.addWidget(&partition__);
    layout__.addWidget(&play__);

    setLayout(&layout__);
}

void PartitionOptWidget::difficultyChanged(const QString & text) {
    partition__.clear();
    QDir dir(":/partition/"+text);
    QStringList dirList = dir.entryList();
    for(int i=0; i<dirList.size(); i++) {
        partition__.addItem(dirList.at(i));
    }
}

void PartitionOptWidget::partitionChanged(const QString & text) {
    emit currentPartitionChanged(QString(":/partition/"+difficulty__.currentText()+"/"+text));
}

void PartitionOptWidget::start() {
    play__.setEnabled(false);
    difficulty__.setEnabled(false);
    partition__.setEnabled(false);

    emit playClicked();
}

void PartitionOptWidget::stop() {
    play__.setEnabled(true);
    difficulty__.setEnabled(true);
    partition__.setEnabled(true);
}
