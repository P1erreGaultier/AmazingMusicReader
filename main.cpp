#include "hometabwidget.hpp"
#include "playtabwidget.hpp"
#include "scoretabwidget.hpp"

#include <QtGlobal>
#include <QApplication>
#include <QDateTime>
#include <QFile>
#include <QObject>
#include <QTabWidget>
#include <QTextStream>
#include <QPalette>
#include <QDebug>

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QDateTime local(QDateTime::currentDateTime());
    QString buffer;
    buffer.append(local.toString());
    buffer.append(QString(" "));
    buffer.append(QString(context.file));
    buffer.append(QString(":"));
    buffer.append(QString::number(context.line));
    buffer.append(QString(" "));
    buffer.append(msg);
    buffer.append(QString("\n"));

    QFile logFile(QString("AmazingMusicReader.log"));
    if(logFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        QTextStream logStream(&logFile);
        logStream << buffer;
    }
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(myMessageOutput);
    QApplication app(argc, argv);
    QTabWidget tabWidget;
    HomeTabWidget homeWidget(tabWidget, &tabWidget);
    PlayTabWidget playWidget(&tabWidget);
    ScoreTabWidget scoreWidget(&tabWidget);

    tabWidget.addTab(&homeWidget, QString("Accueil"));
    tabWidget.addTab(&playWidget, QString("Jouer"));
    tabWidget.addTab(&scoreWidget, QString("Progression"));
    tabWidget.resize(800, 600);
    tabWidget.show();

    return app.exec();
}

