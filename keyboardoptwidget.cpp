#include "keyboardoptwidget.hpp"

#include <QDir>

/**
* Constructeur
* Crée un KeyboardOptWidget
* @param parent Widget parent
*/
KeyboardOptWidget::KeyboardOptWidget(QWidget *parent) : QWidget(parent)//,space__(0,0,QSizePolicy::Minimum,QSizePolicy::Expanding)
{
    groupBox__.setParent(this);
    groupBox__.setTitle(QString("Options du clavier"));
    groupBox__.setStyleSheet(QString("QGroupBox{border:1px solid gray;border-radius:3px;margin-top:0.5em;}QGroupBox::title{subcontrol-origin:margin;left:4px;padding:0 2px 0 2px;}"));
    notesCheckBox__.setParent(this);
    notesCheckBox__.setText(QString("Afficher les notes"));
    styleComboBox__.setParent(this);
    styleLabel__.setParent(this);
    styleLabel__.setText(QString("Style du clavier:"));
    styleLabel__.setAlignment(Qt::AlignBottom);

    connect(&notesCheckBox__, SIGNAL(stateChanged(int)), this, SLOT(showNotes__(int)));

    groupBoxLayout__.addStretch();
    groupBoxLayout__.addWidget(&notesCheckBox__);
    groupBoxLayout__.addStretch();
    groupBoxLayout__.addWidget(&styleLabel__);
    groupBoxLayout__.addWidget(&styleComboBox__);
    groupBoxLayout__.addStretch();

    groupBox__.setLayout(&groupBoxLayout__);

    layout__.addWidget(&groupBox__);

    QDir dir(":/keyboard");
    QStringList dirList = dir.entryList();
    for(int i=0; i<dirList.size(); i++) {
        styleComboBox__.addItem(dirList.at(i));
    }

    setLayout(&layout__);
}


/**
* fonction qui envoie le signal pour afficher les notes sur le clavier
*/
void KeyboardOptWidget::showNotes__(int state) {
    qInfo("show note check box clicked");
    emit showNotes(state);
}
