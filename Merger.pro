#-------------------------------------------------
#
# Project created by QtCreator 2015-01-22T13:00:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Merger
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imagemerger.cpp \
    imageview.cpp \
    imageviewscene.cpp \
    mergeoffsetview.cpp

HEADERS  += mainwindow.h \
    imagemerger.h \
    imageview.h \
    imageviewscene.h \
    mergeoffsetview.h

FORMS    += mainwindow.ui
