#-------------------------------------------------
# Pierre Gaultier
# Alexis Giraudet
#-------------------------------------------------

QT += core gui widgets

TARGET = AmazingMusicReader
TEMPLATE = app

SOURCES += main.cpp \
    partitionwidget.cpp \
    keyboardwidget.cpp \
    hometabwidget.cpp \
    playtabwidget.cpp \
    scoretabwidget.cpp \
    keyboardoptwidget.cpp \
    partitionoptwidget.cpp

HEADERS += \
    partitionwidget.hpp \
    keyboardwidget.hpp \
    hometabwidget.hpp \
    playtabwidget.hpp \
    scoretabwidget.hpp \
    keyboardoptwidget.hpp \
    partitionoptwidget.hpp

RESOURCES += \
    image.qrc \
    keyboard.qrc \
    partition.qrc
