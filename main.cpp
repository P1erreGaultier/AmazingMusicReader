#include <QApplication>
#include "partitionwidget.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    PartitionWidget window;
    window.show();
    return app.exec();
}

