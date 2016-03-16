#include "hometabwidget.hpp"
#include "playtabwidget.hpp"
#include "scoretabwidget.hpp"

#include <QApplication>
#include <QObject>
#include <QTabWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTabWidget tabWidget;
    HomeTabWidget homeWidget;
    PlayTabWidget playWidget;
    ScoreTabWidget scoreWidget;

    tabWidget.addTab(&homeWidget, QString("Accueil"));
    tabWidget.addTab(&playWidget, QString("Jouer"));
    tabWidget.addTab(&scoreWidget, QString("Progression"));

    tabWidget.show();

    return app.exec();
}

