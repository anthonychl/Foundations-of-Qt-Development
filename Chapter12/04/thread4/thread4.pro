#-------------------------------------------------
#
# Project created by QtCreator 2015-10-07T20:04:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = thread4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    textdevice.cpp \
    increasethread.cpp \
    textthread.cpp

HEADERS  += mainwindow.h \
    textdevice.h \
    increasethread.h \
    textthread.h

FORMS    += mainwindow.ui
