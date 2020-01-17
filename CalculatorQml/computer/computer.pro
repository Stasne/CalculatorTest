#-------------------------------------------------
#
# Project created by QtCreator 2020-01-14T19:07:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = computer
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11
SOURCES += main.cpp\
		computer.cpp \
	calculator.cpp \
	queuecontroller.cpp

HEADERS  += computer.h \
	calculator.h \
	queuecontroller.h \
	common.h

FORMS    +=

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../externCalculations/release/ -lexternCalculations
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../externCalculations/debug/ -lexternCalculations

INCLUDEPATH += $$PWD/../externCalculations/debug
DEPENDPATH += $$PWD/../externCalculations/debug
