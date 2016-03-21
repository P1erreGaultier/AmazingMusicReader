#include "scoretabwidget.hpp"

#include <QComboBox>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QSet>
#include <QDebug>

/**
* Constructeur
* Crée un ScoreTabWidget
* @param parent Widget parent
*/
ScoreTabWidget::ScoreTabWidget(QWidget *parent) : QWidget(parent)
{
    playerNameLabel__.setParent(this);
    playerNameLabel__.setText(QString("Filtrer les résultats pour le joueur:"));
    playerName__.setParent(this);
    scoreTree__.setParent(this);
    scoreWatcher__.setParent(this);
    scoreWatcher__.addPath(QString("score.csv"));

    scoreChanged__(QString());

    connect(&playerName__, SIGNAL(currentTextChanged(const QString&)), this, SLOT(playerNameChanged__(const QString&)));
    connect(&scoreWatcher__, SIGNAL(fileChanged(const QString&)), this, SLOT(scoreChanged__(const QString&)));

    layout__.addWidget(&playerNameLabel__);
    layout__.addWidget(&playerName__);
    layout__.addWidget(&scoreTree__);

    setLayout(&layout__);
}

ScoreTabWidget::~ScoreTabWidget() {
    QTreeWidgetItem * item;
    QVectorIterator<QTreeWidgetItem*> itemIt(items__);
    while(itemIt.hasNext()) {
        item = itemIt.next();
        delete item;
    }
}

void ScoreTabWidget::scoreChanged__(const QString & file) {
    playerName__.setDisabled(true);

    playerName__.clear();
    scores__.clear();

    QSet<QString> players;
    QFile scoreFile(QString("score.csv"));
    if (scoreFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&scoreFile);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList lineSplit = line.split(QChar(';'));
            if(lineSplit.size() >= 4) {
              scores__.append(lineSplit);
              players.insert(lineSplit.at(0));
            }
        }
    }

    playerName__.addItem(QString());
    for(QSet<QString>::const_iterator it = players.constBegin(); it != players.constEnd(); it++) {
        playerName__.addItem(*it);
    }

    playerName__.setEnabled(true);

    playerNameChanged__(QString());
}

void ScoreTabWidget::playerNameChanged__(const QString & text) {
    qInfo("player name combo box changed");

    scoreTree__.setDisabled(true);

    QTreeWidgetItem * item;
    QVectorIterator<QTreeWidgetItem*> itemIt(items__);
    while(itemIt.hasNext()) {
        item = itemIt.next();
        delete item;
    }
    items__.clear();
    scoreTree__.clear();


    QStringList headerLabels;
    headerLabels.append(QString("Nom"));
    headerLabels.append(QString("Date"));
    headerLabels.append(QString("Partition"));
    headerLabels.append(QString("Score"));
    scoreTree__.setColumnCount(4);
    scoreTree__.setHeaderLabels(headerLabels);

    for (int i = 0; i < scores__.size(); ++i) {
        if(text.isEmpty() || text == scores__.at(i).at(0)) {
            item = new QTreeWidgetItem(&scoreTree__);
            item->setText(0, scores__.at(i).at(0));
            item->setText(1, scores__.at(i).at(1));
            item->setText(2, scores__.at(i).at(2));
            item->setText(3, scores__.at(i).at(3));
            items__.append(item);
            scoreTree__.addTopLevelItem(item);
        }
    }

    for(int i=0; i<4; i++) {
        scoreTree__.resizeColumnToContents(i);
    }

    scoreTree__.setEnabled(true);
}
