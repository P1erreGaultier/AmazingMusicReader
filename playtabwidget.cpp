#include "playtabwidget.hpp"

PlayTabWidget::PlayTabWidget(QWidget *parent) : QWidget(parent)
{
    keyboard__.setParent(this);
    keyboardOpt__.setParent(this);
    partition__.setParent(this);
    partitionOpt__.setParent(this);

    /*connect(&keyboardOptNotes__ , SIGNAL(stateChanged(int)),&keyboard__,SLOT(showNotes(int)));*/

    layout__.addWidget(&partitionOpt__, 0, 0);
    layout__.addWidget(&partition__, 0, 1);
    layout__.addWidget(&keyboard__, 1, 1);
    layout__.addWidget(&keyboardOpt__, 1, 0);

    this->setLayout(&layout__);
}
