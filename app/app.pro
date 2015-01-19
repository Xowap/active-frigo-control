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
        homescreen.cpp \
    autobalancedlayout.cpp

HEADERS  += homescreen.h \
    autobalancedlayout.h

FORMS    +=

CONFIG += mobility
MOBILITY = 

INCLUDEPATH += $$PWD/../frigotunnel/lib

LIBS += -L../frigotunnel/lib -lfrigotunnel
