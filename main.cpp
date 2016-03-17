#include "hometabwidget.hpp"
#include "playtabwidget.hpp"
#include "scoretabwidget.hpp"

#include <QApplication>
#include <QObject>
#include <QTabWidget>
#include <QPalette>

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
    tabWidget.setMinimumHeight(400);
    tabWidget.setMinimumWidth(1600);
    tabWidget.show();

    return app.exec();
}

