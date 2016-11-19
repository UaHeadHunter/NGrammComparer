#-------------------------------------------------
#
# Project created by QtCreator 2016-11-19T21:07:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NGrammTextComparer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    textfilesmanager.cpp \
    textparser.cpp

HEADERS  += mainwindow.h \
    textfilesmanager.h \
    textparser.h

FORMS    += mainwindow.ui
