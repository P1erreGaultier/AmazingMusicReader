#include "keyboardwidget.hpp"

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

    QPushButton * button;
    for(int i = 0; i < 15; i++) {
        button = new QPushButton(this);
        button->setFocusPolicy(Qt::NoFocus);
        buttons__.append(button);
        layout__.addWidget(button);
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
    // highlight and play sound
    ;
}
