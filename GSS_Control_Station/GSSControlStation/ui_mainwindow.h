/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Mar 8 14:41:40 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_Settings;
    QAction *actionSave_Settings;
    QAction *actionExit;
    QAction *actionConnect;
    QAction *actionOperator;
    QAction *actionEngineer;
    QAction *actionSystem_configuration;
    QAction *actionDebug_Console;
    QAction *actionParameter;
    QAction *actionSystem_Status;
    QAction *actionAbout_GSSControlStation;
    QAction *actionDisconnect;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuCommunication;
    QMenu *menuPerspectives;
    QMenu *menuMain_Widgits;
    QMenu *menuTool_Widgets;
    QMenu *menuHelps;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(720, 480);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/files/images_icons/apps/globe.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setIconSize(QSize(40, 40));
        MainWindow->setAnimated(true);
        actionLoad_Settings = new QAction(MainWindow);
        actionLoad_Settings->setObjectName(QString::fromUtf8("actionLoad_Settings"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/files/images_icons/apps/download.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad_Settings->setIcon(icon1);
        actionSave_Settings = new QAction(MainWindow);
        actionSave_Settings->setObjectName(QString::fromUtf8("actionSave_Settings"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/files/images_icons/apps/save.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_Settings->setIcon(icon2);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/files/images_icons/apps/button_cancel_256.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon3);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/files/images_icons/apps/connect.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon4);
        actionOperator = new QAction(MainWindow);
        actionOperator->setObjectName(QString::fromUtf8("actionOperator"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/files/images_icons/apps/system-users.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionOperator->setIcon(icon5);
        actionEngineer = new QAction(MainWindow);
        actionEngineer->setObjectName(QString::fromUtf8("actionEngineer"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/files/images_icons/apps/engineer_avatar.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionEngineer->setIcon(icon6);
        actionSystem_configuration = new QAction(MainWindow);
        actionSystem_configuration->setObjectName(QString::fromUtf8("actionSystem_configuration"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/files/images_icons/apps/preferences_system.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSystem_configuration->setIcon(icon7);
        actionDebug_Console = new QAction(MainWindow);
        actionDebug_Console->setObjectName(QString::fromUtf8("actionDebug_Console"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/files/images_icons/apps/guake.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionDebug_Console->setIcon(icon8);
        actionParameter = new QAction(MainWindow);
        actionParameter->setObjectName(QString::fromUtf8("actionParameter"));
        actionSystem_Status = new QAction(MainWindow);
        actionSystem_Status->setObjectName(QString::fromUtf8("actionSystem_Status"));
        actionAbout_GSSControlStation = new QAction(MainWindow);
        actionAbout_GSSControlStation->setObjectName(QString::fromUtf8("actionAbout_GSSControlStation"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/files/images_icons/apps/info_box_blue.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_GSSControlStation->setIcon(icon9);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/files/images_icons/apps/disconnect.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon10);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 720, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuCommunication = new QMenu(menuBar);
        menuCommunication->setObjectName(QString::fromUtf8("menuCommunication"));
        menuPerspectives = new QMenu(menuBar);
        menuPerspectives->setObjectName(QString::fromUtf8("menuPerspectives"));
        menuMain_Widgits = new QMenu(menuBar);
        menuMain_Widgits->setObjectName(QString::fromUtf8("menuMain_Widgits"));
        menuTool_Widgets = new QMenu(menuBar);
        menuTool_Widgets->setObjectName(QString::fromUtf8("menuTool_Widgets"));
        menuHelps = new QMenu(menuBar);
        menuHelps->setObjectName(QString::fromUtf8("menuHelps"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuCommunication->menuAction());
        menuBar->addAction(menuPerspectives->menuAction());
        menuBar->addAction(menuMain_Widgits->menuAction());
        menuBar->addAction(menuTool_Widgets->menuAction());
        menuBar->addAction(menuHelps->menuAction());
        menuFile->addAction(actionLoad_Settings);
        menuFile->addAction(actionSave_Settings);
        menuFile->addAction(actionExit);
        menuCommunication->addAction(actionConnect);
        menuCommunication->addAction(actionDisconnect);
        menuPerspectives->addAction(actionOperator);
        menuPerspectives->addAction(actionEngineer);
        menuMain_Widgits->addAction(actionSystem_configuration);
        menuTool_Widgets->addAction(actionDebug_Console);
        menuTool_Widgets->addAction(actionParameter);
        menuTool_Widgets->addAction(actionSystem_Status);
        menuHelps->addAction(actionAbout_GSSControlStation);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "GSSControlStation", 0, QApplication::UnicodeUTF8));
        actionLoad_Settings->setText(QApplication::translate("MainWindow", "Load Settings", 0, QApplication::UnicodeUTF8));
        actionSave_Settings->setText(QApplication::translate("MainWindow", "Save Settings", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionConnect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        actionOperator->setText(QApplication::translate("MainWindow", "Operator", 0, QApplication::UnicodeUTF8));
        actionEngineer->setText(QApplication::translate("MainWindow", "Engineer", 0, QApplication::UnicodeUTF8));
        actionSystem_configuration->setText(QApplication::translate("MainWindow", "System Configuration", 0, QApplication::UnicodeUTF8));
        actionDebug_Console->setText(QApplication::translate("MainWindow", "Debug Console", 0, QApplication::UnicodeUTF8));
        actionParameter->setText(QApplication::translate("MainWindow", "Parameter", 0, QApplication::UnicodeUTF8));
        actionSystem_Status->setText(QApplication::translate("MainWindow", "System Status", 0, QApplication::UnicodeUTF8));
        actionAbout_GSSControlStation->setText(QApplication::translate("MainWindow", "About GSSControlStation", 0, QApplication::UnicodeUTF8));
        actionDisconnect->setText(QApplication::translate("MainWindow", "Disconnect", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuCommunication->setTitle(QApplication::translate("MainWindow", "Communication", 0, QApplication::UnicodeUTF8));
        menuPerspectives->setTitle(QApplication::translate("MainWindow", "Perspectives", 0, QApplication::UnicodeUTF8));
        menuMain_Widgits->setTitle(QApplication::translate("MainWindow", "Main Widgets", 0, QApplication::UnicodeUTF8));
        menuTool_Widgets->setTitle(QApplication::translate("MainWindow", "Tool Widgets", 0, QApplication::UnicodeUTF8));
        menuHelps->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
