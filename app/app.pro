#-------------------------------------------------
#
# Project created by QtCreator 2014-12-20T23:22:08
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = active-frigo-control
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
    autobalancedlayout.cpp \
    config.cpp \
    soundset.cpp \
    soundtarget.cpp \
    soundbuttons.cpp \
    homescreen.cpp \
    layouthelper.cpp

HEADERS  += \
    autobalancedlayout.h \
    config.h \
    soundset.h \
    soundtarget.h \
    soundbuttons.h \
    homescreen.h \
    layouthelper.h

FORMS    += \
    homescreen.ui

CONFIG += mobility
MOBILITY = 

INCLUDEPATH += $$PWD/../frigotunnel/lib

LIBS += -L../frigotunnel/lib -lfrigotunnel

RESOURCES += \
    resources.qrc
