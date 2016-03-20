#include "keyboardoptwidget.hpp"

#include <QDir>

KeyboardOptWidget::KeyboardOptWidget(QWidget *parent) : QWidget(parent)
{
    notesCheckBox__.setParent(this);
    notesCheckBox__.setText(QString("Afficher les notes"));
    styleComboBox__.setParent(this);

    connect(&notesCheckBox__, SIGNAL(stateChanged(int)), this, SLOT(showNotes__(int)));

    layout__.addWidget(&notesCheckBox__);
    layout__.addWidget(&styleComboBox__);

    QDir dir(":/keyboard");
    QStringList dirList = dir.entryList();
    for(int i=0; i<dirList.size(); i++) {
        styleComboBox__.addItem(dirList.at(i));
    }

    setLayout(&layout__);
}

void KeyboardOptWidget::showNotes__(int state) {
    emit showNotes(state);
}
