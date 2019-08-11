#-------------------------------------------------
#
# Project created by QtCreator 2015-10-12T22:44:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = thread9
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    textthread.cpp \
    textandnumber.cpp \
    textdialog.cpp

HEADERS  += mainwindow.h \
    textthread.h \
    textandnumber.h \
    textdialog.h

FORMS    += mainwindow.ui \
    textdialog.ui
