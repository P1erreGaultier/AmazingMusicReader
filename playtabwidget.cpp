#include "playtabwidget.hpp"

PlayTabWidget::PlayTabWidget(QWidget *parent) : QWidget(parent)
{
    keyboard__.setParent(this);
    partition__.setParent(this);
    start__.setParent(this);
    start__.setText(QString("Jouer"));
    keyboardOptNotes__.setParent(this);
    keyboardOptNotes__.setText(QString("afficher les notes du clavier"));

    connect(&keyboardOptNotes__ , SIGNAL(stateChanged(int)),&keyboard__,SLOT(showNotes(int)));

    layout__.addWidget(&start__, 0, 0);
    layout__.addWidget(&partition__, 0, 1);
    layout__.addWidget(&keyboard__, 1, 1);
    layout__.addWidget(&keyboardOptNotes__, 1, 0);

    this->setLayout(&layout__);
}
