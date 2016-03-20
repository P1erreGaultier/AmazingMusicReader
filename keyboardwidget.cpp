#include "keyboardwidget.hpp"

#include <QHBoxLayout>
#include <QPushButton>
#include <QSignalMapper>
#include <QWidget>
#include <QSound>
#include <QDebug>

KeyboardWidget::KeyboardWidget(QWidget *parent)
    : QWidget(parent)
{
    layout__.setSpacing(0);
    layout__.setMargin(0);

    notes__.append(QString("DO"));
    notes__.append(QString("RÉ"));
    notes__.append(QString("MI"));
    notes__.append(QString("FA"));
    notes__.append(QString("SOL"));
    notes__.append(QString("LA"));
    notes__.append(QString("SI"));

    signalMapper__ = new QSignalMapper(this);
    connect(signalMapper__, SIGNAL(mapped(int)), this, SIGNAL(keyPushed(int)));
    connect(signalMapper__, SIGNAL(mapped(int)), this, SLOT(pushKey(int)));
    connect(signalMapper__, SIGNAL(mapped(int)), this, SLOT(pullKey__(int)));

    QPushButton * button;
    QTimer * timer;
    for(int i = 0; i < 15; i++) {
        button = new QPushButton(this);
        timer = new QTimer(this);
        button->setFocusPolicy(Qt::NoFocus);
        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        button->setStyleSheet("QPushButton {background-color: white; color: black;}");
        //button->setFlat(true);
        //button->setAutoFillBackground(true);
        //button->setIcon(QIcon(":/piano/skin/key.png"));
        //button->setIconSize();

        timers__.append(timer);
        buttons__.append(button);
        layout__.addWidget(button);

        signalMapper__->setMapping(button, i);
        connect(button, SIGNAL(clicked()), signalMapper__, SLOT(map()));
        signalMapper__->setMapping(timer, i+15);
        connect(timer, SIGNAL(timeout()), signalMapper__, SLOT(map()));
    }

    setStyle(QString("piano"));

    setLayout(&layout__);
}

KeyboardWidget::~KeyboardWidget()
{
    QPushButton * button;
    QVectorIterator<QPushButton*> buttonIt(buttons__);

    delete signalMapper__;

    while(buttonIt.hasNext()) {
        button = buttonIt.next();
        layout__.removeWidget(button);
        delete button;
    }
}

void KeyboardWidget::showNotes(int state)
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
        if(state) {
            button->setText(note);
        } else {
            button->setText(QString());
        }
    }
}

void KeyboardWidget::pullKey__(int key) {
    if(key >= 15) {
        qDebug() << "pullKey__ " << key;
        timers__.at(key-15)->stop();
        buttons__.at(key-15)->setStyleSheet("QPushButton {background-color: white; color: black;}");
    }
}

void KeyboardWidget::pushKey(int key)
{
    if(key < 15) {
        qDebug() << key << "pushed";
        buttons__.at(key)->setStyleSheet("QPushButton {background-color: blue; color: white;}");
        QSound::play(QString(":/keyboard/")+style__+QString("/audio/")+QString::number(key)+QString(".wav"));
        timers__.at(key)->start(250);
    }
}

void KeyboardWidget::setStyle(QString style)
{
    style__ = style;
}
