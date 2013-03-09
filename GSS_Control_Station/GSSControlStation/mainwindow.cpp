#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qextserialport.h"
#include <QextSerialEnumerator.h>

#include <QtCore/QStringList>
#include <QtCore/QTimer>
#include <QtCore/QVariant>

#include <QMessageBox>
#include <QAction>
#include <QFile>
#include <QDockWidget>

#include "aboutDialog.h"
#include "ui_aboutdialog.h"

#include "connectdialog.h"
#include "ui_connectdialog.h"

#include "consolewidget.h"
#include "ui_consolewidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentStyle(GSC_MAINWINDOW_STYLE_INDOOR),
    styleFileName(QCoreApplication::applicationDirPath() + "files/styles/style-indoor.css")

{
    ui->setupUi(this);

    ui->mainToolBar->addAction(ui->actionEngineer);
    ui->mainToolBar->addAction(ui->actionOperator);

    loadStyle(currentStyle);

    connect(ui->actionAbout_GSSControlStation,SIGNAL(triggered()),SLOT(actionAbout_Clicked()));
    connect(ui->actionDebug_Console,SIGNAL(triggered()),SLOT(actionDebugConsole_triggered()));
    connect(ui->actionConnect,SIGNAL(triggered()),SLOT(actionConnect_triggered()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadStyle(MainWindow::GSC_MAINWINDOW_STYLE style)
{
    switch (style) {
    case GSC_MAINWINDOW_STYLE_NATIVE: {
        // Native mode means setting no style
        // so if we were already in native mode
        // take no action
        // Only if a style was set, remove it.
        if (style != currentStyle) {
            qApp->setStyleSheet("");

            showInfoMessage(tr("Please restart GSS SC"),
                            tr("Please restart GSS SC to switch to fully native look and feel. Currently you have loaded Qt's plastique style."));
        }
    }
    break;
    case GSC_MAINWINDOW_STYLE_INDOOR:
    qApp->setStyle("plastique");
        styleFileName = ":files/styles/style-indoor.css";
        reloadStylesheet();
        break;
    case GSC_MAINWINDOW_STYLE_OUTDOOR:
    qApp->setStyle("plastique");
        styleFileName = ":files/styles/style-outdoor.css";
        reloadStylesheet();
        break;
    }
    currentStyle = style;
}

void MainWindow::reloadStylesheet()
{
    // Load style sheet
    QFile* styleSheet = new QFile(styleFileName);
    if (!styleSheet->exists())
    {
        styleSheet = new QFile("files/styles/style-indoor.css");
    }
    if (styleSheet->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString style = QString(styleSheet->readAll());
        qApp->setStyleSheet(style);
    }
    else
    {
        showInfoMessage(tr("GSS SC did lot load a new style"),
                        tr("Stylesheet file %1 was not readable").arg(styleFileName));
    }
    delete styleSheet;
}

void MainWindow::showInfoMessage(const QString &title, const QString &message)
{
    QMessageBox msgBox(this);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText(title);
    msgBox.setInformativeText(message);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

void MainWindow::actionAbout_Clicked()
{
    my_aboutdialog = new aboutDialog(this);
    my_aboutdialog->show();
}

void MainWindow::actionDebugConsole_triggered()
{
    createDockWindows();
}

void MainWindow::createDockWindows()
{
    consoleDockWidget = new QDockWidget(tr("Communication Console"), this);
    consoleDockWidget->setWidget( new consolewidget(this) );
    consoleDockWidget->setObjectName("DEBUGCONSOLE_DOCKWIDGET");

    consolewidget *debug = dynamic_cast<consolewidget*>(consoleDockWidget->widget());
    debug->show();
    //connect(mavlinkDecoder, SIGNAL(textMessageReceived(int, int, int, const QString)), debugConsole, SLOT(receiveTextMessage(int, int, int, const QString)));
    addDockWidget(Qt::BottomDockWidgetArea,consoleDockWidget);
}

void MainWindow::actionConnect_triggered()
{
    my_connectDialog = new connectDialog(this);
    my_connectDialog->show();
}

