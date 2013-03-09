#-------------------------------------------------
#
# Project created by QtCreator 2013-03-07T17:13:38
#
#-------------------------------------------------

QT       += core gui

TARGET = GSSControlStation
TEMPLATE = app
include (../qextserialport/src/qextserialport.pri)

SOURCES += main.cpp\
        mainwindow.cpp \
    aboutdialog.cpp \
    consolewidget.cpp \
    connectdialog.cpp

HEADERS  += mainwindow.h \
    aboutdialog.h \
    consolewidget.h \
    connectdialog.h

FORMS    += mainwindow.ui \
    aboutdialog.ui \
    consolewidget.ui \
    connectdialog.ui

RESOURCES += \
    gss_resources.qrc
