#include "keyboardwidget.hpp"

#include <QString>

KeyboardWidget::KeyboardWidget(QWidget *parent) : QWidget(parent)
{
    setLayout(&layout__);

    static QString notes[] = {"do", "re", "mi", "fa", "sol", "la", "si"};
    QPushButton * button;
    for(int i = 0; i < 15; i++) {
        button = new QPushButton(notes[i%sizeof(notes)], this);
        buttons__.append(button);
        layout__.addWidget(button);
    }
}

KeyboardWidget::~KeyboardWidget()
{
    for(QVectorIterator<QPushButton*> it(buttons__); it.hasNext(); delete it.next());

}
