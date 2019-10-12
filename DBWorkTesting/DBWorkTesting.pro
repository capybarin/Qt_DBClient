#-------------------------------------------------
#
# Project created by QtCreator 2017-11-14T08:38:14
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DBWorkTesting
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    typemodel.cpp \
    manufacmodel.cpp \
    detailmvcmodel.cpp \
    detail_model_model.cpp

HEADERS  += mainwindow.h \
    manufacmodel.h \
    detailmvcmodel.h \
    detail_model_model.h \
    typemodel.h

FORMS    += mainwindow.ui
