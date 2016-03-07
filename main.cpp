#include <QApplication>
#include "keyboardwidget.hpp"
#include "partitionwidget.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    PartitionWidget window;

    KeyboardWidget keyboard;
    keyboard.show();
    keyboard.showNotes(true);
    window.show();
    return app.exec();

}

