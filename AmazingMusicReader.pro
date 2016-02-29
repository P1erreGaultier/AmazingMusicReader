QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AmazingMusicReader

TEMPLATE = app

SOURCES += main.cpp \
    keyboardwidget.cpp

HEADERS += \
    keyboardwidget.hpp
