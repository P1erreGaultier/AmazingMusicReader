#include "hometabwidget.hpp"



HomeTabWidget::HomeTabWidget(QWidget *parent) : QWidget(parent)
{
    labelImage__.setParent(this);
    labelImage__.setPixmap(QPixmap(QString(":/image/icon_386x216.png")));
    labelText__.setParent(this);
    labelText__.setWordWrap(true);
    labelText__.setText(QString::fromUtf8("Bienvenue dans AmazingMusicTrainer, une application pour apprendre les bases du solfège en s'amusant, et à votre niveau.\nCliquez sur le bouton \"Jouer\" pour lancer une partie, ou sur le bouton \"Performance\" pour voir vos progrès. Vous pouvez aussi vous deplcer à l'aide des onglets en haut à gauche"));
    labelText__.setFont(QFont("Calibri", 10, QFont::Bold));
    btnJouer = new QPushButton("Jouer");
    btnPerformance = new QPushButton("Progression");
    btnJouer->setMinimumHeight(60);
    btnJouer->setFont(QFont("Calibri", 30, QFont::Bold));
    btnJouer->setMinimumHeight(60);
    btnPerformance->setFont(QFont("Calibri", 30, QFont::Bold));
    labelImage__.setAlignment(Qt::AlignHCenter);
    layout__.addWidget(&labelImage__);
    layout__.addWidget(btnJouer);
    layout__.addWidget(btnPerformance);
    layout__.addWidget(&labelText__);

    layout__.setAlignment(Qt::AlignHCenter);
    this->setLayout(&layout__);

}
