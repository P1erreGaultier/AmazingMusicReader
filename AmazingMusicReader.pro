#-------------------------------------------------
#
# Project created by QtCreator 2016-02-29T23:35:25
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AmazingMusicReader
TEMPLATE = app

SOURCES += main.cpp \
    partitionwidget.cpp \
    keyboardwidget.cpp

HEADERS += \
    partitionwidget.hpp \
    keyboardwidget.hpp

RESOURCES += \
    Partoch.qrc \
    styles.qrc
