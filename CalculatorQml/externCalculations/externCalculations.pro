#-------------------------------------------------
#
# Project created by QtCreator 2020-01-15T10:08:34
#
#-------------------------------------------------

QT       -= core gui

TARGET = externCalculations
TEMPLATE = lib

DEFINES += EXTERNCALCULATIONS_LIBRARY

SOURCES += externcalculations.cpp

HEADERS += externcalculations.h\
        externcalculations_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
