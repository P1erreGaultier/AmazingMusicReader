#include "keyboardwidget.hpp"

#include <QDebug>

KeyboardWidget::KeyboardWidget(QWidget *parent)
    : QWidget(parent)
{
    layout__.setSpacing(0);
    layout__.setMargin(0);

    setLayout(&layout__);

    notes__.append(QString::fromUtf8("DO"));
    notes__.append(QString::fromUtf8("RÉ"));
    notes__.append(QString::fromUtf8("MI"));
    notes__.append(QString::fromUtf8("FA"));
    notes__.append(QString::fromUtf8("SOL"));
    notes__.append(QString::fromUtf8("LA"));
    notes__.append(QString::fromUtf8("SI"));

    signalMapper__ = new QSignalMapper(this);
    connect(signalMapper__, SIGNAL(mapped(int)), this, SIGNAL(keyPushed(int)));
    connect(signalMapper__, SIGNAL(mapped(int)), this, SLOT(pushKey(int)));

    QPushButton * button;
    for(int i = 0; i < 15; i++) {
        button = new QPushButton(this);
        button->setFocusPolicy(Qt::NoFocus);
        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        //button->setFlat(true);
        //button->setAutoFillBackground(true);
        //button->setIcon(QIcon(":/piano/skin/key.png"));
        //button->setIconSize();

        buttons__.append(button);
        layout__.addWidget(button);

        signalMapper__->setMapping(button, i);
        connect(button, SIGNAL(clicked()), signalMapper__, SLOT(map()));
        signalMapper__->setMapping(button, i);
    }

    setStyle("piano");
}

KeyboardWidget::~KeyboardWidget()
{
    QPushButton * button;
    QSound * sound;
    QVectorIterator<QPushButton*> buttonIt(buttons__);
    QVectorIterator<QSound*> soundIt(sounds__);

    delete signalMapper__;

    while(soundIt.hasNext()) {
        sound = soundIt.next();
        delete sound;
    }

    while(buttonIt.hasNext()) {
        button = buttonIt.next();
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
    sounds__.at(key)->play();
}

void KeyboardWidget::setStyle(QString style)
{
    QSound * sound;
    QVectorIterator<QSound*> soundIt(sounds__);

    while(soundIt.hasNext()) {
        sound = soundIt.next();
        delete sound;
    }

    for(int i = 0; i < 15; i++) {
        sounds__.append(new QSound(QString(":/styles/")+style+QString("/audio/")+QString::number(i)+QString(".wav")));
    }
}
