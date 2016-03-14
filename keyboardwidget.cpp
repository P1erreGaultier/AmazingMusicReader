#include "keyboardwidget.hpp"

#include <QDebug>

KeyboardWidget::KeyboardWidget(QWidget *parent)
    : QWidget(parent)
{
    layout__.setSpacing(0);
    layout__.setMargin(0);

    setLayout(&layout__);

    notes__.append("DO");
    notes__.append("RÉ");
    notes__.append("MI");
    notes__.append("FA");
    notes__.append("SOL");
    notes__.append("LA");
    notes__.append("SI");

    signalMapper__ = new QSignalMapper(this);
    connect(signalMapper__, SIGNAL(mapped(int)), this, SIGNAL(keyPushed(int)));
    connect(signalMapper__, SIGNAL(mapped(int)), this, SLOT(pushKey(int)));

    QPushButton * button;
    for(int i = 0; i < 15; i++) {
        button = new QPushButton(this);
        button->setFocusPolicy(Qt::NoFocus);
        buttons__.append(button);
        layout__.addWidget(button);

        signalMapper__->setMapping(button, i);
        connect(button, SIGNAL(clicked()), signalMapper__, SLOT(map()));
        signalMapper__->setMapping(button, i);
    }
}

KeyboardWidget::~KeyboardWidget()
{
    QPushButton * button;
    QVectorIterator<QPushButton*> it(buttons__);

    while(it.hasNext()) {
        button = it.next();
        layout__.removeWidget(button);
        delete button;
    }
}

void KeyboardWidget::showNotes(bool show)
{
    QPushButton * button;
    QString note;
    QVectorIterator<QPushButton*> buttonsIterator(buttons__);
    QVectorIterator<QString> notesIterator(notes__);

    while(buttonsIterator.hasNext()) {
        if(!notesIterator.hasNext()) {
            notesIterator.toFront();
        }
        button = buttonsIterator.next();
        note = notesIterator.next();
        if(show) {
            button->setText(note);
        } else {
            button->setText("");
        }
    }
}

void KeyboardWidget::pushKey(int key)
{
    qDebug() << key << "pushed";
    QSound::play(":/styles/piano/audio/"+QString::number(key)+".wav");
}
