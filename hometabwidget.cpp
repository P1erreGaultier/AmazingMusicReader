#include "hometabwidget.hpp"



HomeTabWidget::HomeTabWidget(QWidget *parent) : QWidget(parent)
{
    labelImage__.setParent(this);
    labelImage__.setPixmap(QPixmap(QString(":/image/icon_386x216.png")));
    labelText__.setParent(this);
    labelText__.setWordWrap(true);
    labelText__.setText(QString::fromUtf8("Bienvenue dans AmazingMusicTrainer, une application pour apprendre les bases du solfège en s'amusant.\nCliquez sur le bouton \"Jouer\" pour lancer une partie, ou sur le bouton \"Performance\" pour voir vos progrès."));
    labelText__.setFont(QFont("Calibri", 10, QFont::Bold));
    btnJouer = new QPushButton("Jouer");
    btnPerformance = new QPushButton("Progression");

    labelImage__.setAlignment(Qt::AlignHCenter);
    layout__.addWidget(&labelImage__);
    layout__.addWidget(&labelText__);
    layout__.addWidget(btnJouer);
    layout__.addWidget(btnPerformance);
    layout__.setAlignment(Qt::AlignHCenter);
    this->setLayout(&layout__);





}
