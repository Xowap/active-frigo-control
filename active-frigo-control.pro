#-------------------------------------------------
#
# Project created by QtCreator 2014-12-20T23:22:08
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = active-frigo-control
TEMPLATE = app


SOURCES += main.cpp\
        homescreen.cpp

HEADERS  += homescreen.h

FORMS    += homescreen.ui

CONFIG += mobility
MOBILITY = 

