#-------------------------------------------------
#
# Project created by QtCreator 2016-02-14T11:26:22
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = db3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imagedialog.cpp \
    imagecollection.cpp

HEADERS  += mainwindow.h \
    imagedialog.h \
    imagecollection.h

FORMS    += mainwindow.ui \
    imagedialog.ui
