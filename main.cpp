#include <QApplication>

#include "keyboardwidget.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    KeyboardWidget keyboard;
    keyboard.show();
    keyboard.showNotes(true);

    return a.exec();
}

