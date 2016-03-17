#include "scoretabwidget.hpp"
#include <QComboBox>
#include <QString>

ScoreTabWidget::ScoreTabWidget(QWidget *parent) : QWidget(parent)
{
    QComboBox* facile = new QComboBox;
        facile->addItem("partiton1",1);
        facile->addItem("partiton2",2);
        facile->addItem("partiton3",3);
        facile->addItem("partiton4",4);
        facile->addItem("partiton5",5);
        facile->addItem("partiton6",6);
        facile->addItem("partiton7",7);

    QComboBox* intermediaire = new QComboBox;
        intermediaire->addItem("partiton1",1);
        intermediaire->addItem("partiton2",2);
        intermediaire->addItem("partiton3",3);
        intermediaire->addItem("partiton4",4);
        intermediaire->addItem("partiton5",5);
        intermediaire->addItem("partiton6",6);
        intermediaire->addItem("partiton7",7);

    QComboBox* difficile = new QComboBox;
        difficile->addItem("partiton1",1);
        difficile->addItem("partiton2",2);
        difficile->addItem("partiton3",3);
        difficile->addItem("partiton4",4);
        difficile->addItem("partiton5",5);
        difficile->addItem("partiton6",6);
        difficile->addItem("partiton7",7);

    labelText1__.setParent(this);
    labelText1__.setWordWrap(true);
    labelText1__.setText((QString("Facile:")));
    labelText2__.setParent(this);
    labelText2__.setWordWrap(true);
    labelText2__.setText((QString("Intermediaire:")));
    labelText3__.setParent(this);
    labelText3__.setWordWrap(true);
    labelText3__.setText((QString("Difficile:")));
    layout__.addWidget(&labelText1__);
    layout__.addWidget(facile,0,1);
    layout__.addWidget(&labelText2__,1,0);
    layout__.addWidget(intermediaire,1,1);
    layout__.addWidget(&labelText3__,2,0);
    layout__.addWidget(difficile,2,1);
    layout__.setAlignment(Qt::AlignHCenter);
    this->setLayout(&layout__);
}

//
