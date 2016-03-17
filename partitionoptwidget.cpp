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

    connect(&difficulty__, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(currentIndexChanged(const QString &)));

    layout__.addWidget(&difficulty__);
    layout__.addWidget(&partition__);
    layout__.addWidget(&play__);

    setLayout(&layout__);
}

void PartitionOptWidget::currentIndexChanged(const QString & text) {
    partition__.clear();
    QDir dir(":/partition/"+text);
    QStringList dirList = dir.entryList();
    for(int i=0; i<dirList.size(); i++) {
        partition__.addItem(dirList.at(i));
    }
}
