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
        src/ui/mainwindow.cpp \
    src/ui/SerialConfigurationWindow.cpp \
    src/common/hled.cpp \
    src/ui/DebugConsole.cpp

HEADERS  += src/ui/mainwindow.h \
    src/ui/SerialConfigurationWindow.h \
    src/common/hled.h \
    src/ui/DebugConsole.h

FORMS    += src/ui/mainwindow.ui \
    src/ui/SerialConfigurationWindow.ui \
    src/ui/DebugConsole.ui

OTHER_FILES += \
    ChangeLog.txt \
    README.md

RESOURCES += \
    gss_resources.qrc
