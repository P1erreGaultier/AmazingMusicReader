#-------------------------------------------------
#
# Project created by QtCreator 2016-02-29T23:35:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = AmazingMusicReader
TEMPLATE = app

SOURCES += main.cpp \
    partitionwidget.cpp \
    keyboardwidget.cpp \
    hometabwidget.cpp \
    playtabwidget.cpp \
    scoretabwidget.cpp

HEADERS += \
    partitionwidget.hpp \
    keyboardwidget.hpp \
    hometabwidget.hpp \
    playtabwidget.hpp \
    scoretabwidget.hpp

RESOURCES += \
    Partoch.qrc \
    styles.qrc
