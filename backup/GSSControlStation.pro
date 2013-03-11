#-------------------------------------------------
#
# Project created by QtCreator 2013-03-07T17:13:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GSSControlStation
TEMPLATE = app
include (libs/thirdParty/qextserialport/src/qextserialport.pri)

SOURCES += src/main.cpp\
        src/ui/mainwindow.cpp \
    src/ui/aboutdialog.cpp \
    src/ui/consolewidget.cpp \
    src/ui/connectdialog.cpp

HEADERS  += src/ui/mainwindow.h \
    src/ui/aboutdialog.h \
    src/ui/consolewidget.h \
    src/ui/connectdialog.h

FORMS    += src/ui/mainwindow.ui \
    src/ui/aboutdialog.ui \
    src/ui/consolewidget.ui \
    src/ui/connectdialog.ui

RESOURCES += \
    gss_resources.qrc
