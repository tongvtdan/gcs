#-------------------------------------------------
#
# Project created by QtCreator 2013-03-11T14:29:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gcs
TEMPLATE = app

include (libs/thirdParty/qextserialport/src/qextserialport.pri)

SOURCES += src/main.cpp\
        src/ui/mainwindow.cpp

HEADERS  += src/ui/mainwindow.h

FORMS    += src/ui/mainwindow.ui

OTHER_FILES += \
    ChangeLog.txt \
    README.md
