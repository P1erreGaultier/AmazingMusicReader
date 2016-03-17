#-------------------------------------------------
# Pierre Gaultier
# Alexis Giraudet
#-------------------------------------------------

QT += core gui widgets multimedia

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
    image.qrc \
    keyboard.qrc \
    partition.qrc
