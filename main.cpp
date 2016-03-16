#include "keyboardwidget.hpp"
#include "partitionwidget.hpp"

#include <QObject>
#include <QApplication>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    KeyboardWidget keyboardWidget(&window);
    PartitionWidget partitionWidget(&window);
    QCheckBox showNotes("Afficher le nom des notes", &window);
    QVBoxLayout layout;
    QHBoxLayout optLayout;

    QObject::connect(&showNotes , SIGNAL(stateChanged(int)),&keyboardWidget,SLOT(showNotes(int)));

    optLayout.addWidget(&showNotes);

    layout.addWidget(&partitionWidget);
    layout.addWidget(&keyboardWidget);
    layout.addLayout(&optLayout);

    window.setLayout(&layout);

    window.show();
    partitionWidget.show();
    keyboardWidget.show();

    return app.exec();
}

