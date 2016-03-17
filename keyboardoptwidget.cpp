#include "keyboardoptwidget.hpp"

#include <QDir>

KeyboardOptWidget::KeyboardOptWidget(QWidget *parent) : QWidget(parent)
{
    showNotes__.setParent(this);
    selectStyle__.setParent(this);

    layout__.addWidget(&showNotes__);
    layout__.addWidget(&selectStyle__);

    QDir dir(":/keyboard");
    QStringList dirList = dir.entryList();
    for(int i=0; i<dirList.size(); i++) {
        selectStyle__.addItem(dirList.at(i));
    }

    setLayout(&layout__);
}
