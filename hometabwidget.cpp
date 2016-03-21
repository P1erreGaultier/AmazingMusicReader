#include "hometabwidget.hpp"

#include <QTabWidget>
#include <QDebug>

/**
* Constructeur
* Crée un HomeTabWidget
* @param tabParent QtabWidget du main pour pouvoir agir sur les onglet de l'onglet parent
* @param parent Widget parent
*/
HomeTabWidget::HomeTabWidget(QTabWidget & tabParent, QWidget *parent) : QWidget(parent), tabParent__(tabParent), space__(0,0,QSizePolicy::Minimum,QSizePolicy::Expanding)
{
    labelImage__.setParent(this);
    labelImage__.setPixmap(QPixmap(QString(":/image/icon_386x216.png")));
    labelImage__.setAlignment(Qt::AlignHCenter);
    labelText__.setParent(this);
    labelText__.setWordWrap(true);
    labelText__.setText(QString::fromUtf8("Bienvenue dans AmazingMusicTrainer, une application pour apprendre les bases du solfège en s'amusant, et à votre niveau.\nCliquez sur le bouton \"Jouer\" pour lancer une partie, ou sur le bouton \"Performance\" pour voir vos progrès. Vous pouvez aussi vous deplcer à l'aide des onglets en haut à gauche"));
    buttonPlay__.setParent(this);
    buttonPlay__.setText(QString("Jouer"));
    buttonScore__.setParent(this);
    buttonScore__.setText(QString("Progression"));
    layout__.addSpacerItem(&space__);
    layout__.addWidget(&labelImage__);
    layout__.addSpacerItem(&space__);
    layout__.addWidget(&buttonPlay__);
    layout__.addWidget(&buttonScore__);
    layout__.addSpacerItem(&space__);
    layout__.addWidget(&labelText__);
    layout__.addSpacerItem(&space__);

    QFont font;
    font = labelText__.font();
    font.setBold(true);
    font.setPointSize(10);
    labelText__.setFont(font);
    font = buttonPlay__.font();
    font.setBold(true);
    font.setPointSize(30);
    buttonPlay__.setFont(font);
    font = buttonScore__.font();
    font.setBold(true);
    font.setPointSize(30);
    buttonScore__.setFont(font);

    layout__.setAlignment(Qt::AlignHCenter);
    this->setLayout(&layout__);

    connect(&buttonPlay__, SIGNAL(clicked()), this, SLOT(playClicked()));
    connect(&buttonScore__, SIGNAL(clicked()), this, SLOT(scoreClicked()));

}

void HomeTabWidget::scoreClicked() {
    qInfo("play button clicked");
    tabParent__.setCurrentIndex(2);
}

void HomeTabWidget::playClicked() {
    qInfo("score button clicked");
    tabParent__.setCurrentIndex(1);
}
