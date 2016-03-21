#include "scoretabwidget.hpp"
#include <QComboBox>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QSet>

/**
* Constructeur
* Crée un ScoreTabWidget
* @param parent Widget parent
*/
ScoreTabWidget::ScoreTabWidget(QWidget *parent) : QWidget(parent)
{
    playerName__.setParent(this);
    scoreTree__.setParent(this);

    //connect(&playerName__, SIGNAL(currentTextChanged(const QString&)), this, SLOT(currentPlayerNameChanged__(const QString&)));

    updateScore();

    layout__.addWidget(&playerName__);
    layout__.addWidget(&scoreTree__);

    setLayout(&layout__);
}

void ScoreTabWidget::clearScoreTree__() {
    QTreeWidgetItem * item;
    QVectorIterator<QTreeWidgetItem*> itemIt(items__);

    while(itemIt.hasNext()) {
        item = itemIt.next();
        scoreTree__.removeItemWidget(item, 0);
        delete item;
    }

    scoreTree__.clear();
}

void ScoreTabWidget::updateScore() {
    playerName__.clear();
    //scoreTree__.clear();
    clearScoreTree__();

    playerName__.addItem(QString());

    QSet<QString> playersNames;
    int columnCount = 0;
    QFile scoreFile(QString("score.csv"));
    if (scoreFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&scoreFile);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList lineSplit = line.split(QChar(';'));
            scores__.append(lineSplit);
            if(lineSplit.size() > columnCount) {
                columnCount = lineSplit.size();
            }
            playersNames.insert(lineSplit.at(0));
        }
    }

    for(QSet<QString>::const_iterator it = playersNames.constBegin(); it != playersNames.constEnd(); it++) {
        playerName__.addItem(*it);
    }

    scoreTree__.setColumnCount(columnCount);
    QList<QTreeWidgetItem *> items;
    for (int i = 0; i < scores__.size(); ++i) {
        if(playerName__.currentText().isEmpty() || playerName__.currentText() == scores__.at(i).at(0)) {
            QTreeWidgetItem * item = new QTreeWidgetItem((QTreeWidget*)NULL, scores__.at(i));
            items__.append(item);
            items.append(item);
        }
    }
    scoreTree__.insertTopLevelItems(0, items);
}

void ScoreTabWidget::currentPlayerNameChanged__(const QString & text) {
    qInfo("player name combo box changed");
    updateScore();
}
