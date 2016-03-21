#include "keyboardoptwidget.hpp"

#include <QDir>

KeyboardOptWidget::KeyboardOptWidget(QWidget *parent) : QWidget(parent)
{
    groupBox__.setParent(this);
    groupBox__.setTitle(QString("Options du clavier"));
    groupBox__.setStyleSheet(QString("QGroupBox{border:1px solid gray;border-radius:3px;margin-top:0.5em;}QGroupBox::title{subcontrol-origin:margin;left:4px;padding:0 2px 0 2px;}"));
    notesCheckBox__.setParent(this);
    notesCheckBox__.setText(QString("Afficher les notes"));
    styleComboBox__.setParent(this);

    connect(&notesCheckBox__, SIGNAL(stateChanged(int)), this, SLOT(showNotes__(int)));

    groupBoxLayout__.addWidget(&notesCheckBox__);
    groupBoxLayout__.addWidget(&styleComboBox__);

    groupBox__.setLayout(&groupBoxLayout__);

    layout__.addWidget(&groupBox__);

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
