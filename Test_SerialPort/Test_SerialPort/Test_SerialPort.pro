#-------------------------------------------------
#
# Project created by QtCreator 2013-03-06T10:24:10
#
#-------------------------------------------------

QT       += core gui
#contains(QT_VERSION, ^5\\..*\\..*): QT += widgets

TARGET = Test_SerialPort
TEMPLATE = app
include (../qextserialport/src/qextserialport.pri)

SOURCES += main.cpp\
        dialog.cpp

HEADERS  += dialog.h

FORMS    += dialog.ui
