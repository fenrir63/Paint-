#-------------------------------------------------
#
# Project created by QtCreator 2015-09-24T19:55:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = paint
TEMPLATE = app

SOURCES += main.cpp\
        paint.cpp \
    paintscene.cpp \
    filemenu.cpp \
    filemanager.cpp \
    painttools.cpp

HEADERS  += paint.h \
    paintscene.h \
    filemenu.h \
    filemanager.h \
    painttools.h

FORMS    += paint.ui

RESOURCES += \
    resources.qrc
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.13
