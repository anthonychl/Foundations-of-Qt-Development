#-------------------------------------------------
#
# Project created by QtCreator 2015-10-08T20:14:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = thread5
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    global.cpp \
    textproducer.cpp \
    textconsumer.cpp

HEADERS  += mainwindow.h \
    global.h \
    textproducer.h \
    textconsumer.h

FORMS    += mainwindow.ui
