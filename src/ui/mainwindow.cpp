#include <QFile>        // for file operation
#include <QMessageBox>
#include <QDockWidget>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qextserialport.h"
#include "DebugConsole.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentStyle(GCS_MAINWINDOW_STYLE_INDOOR),
    currentView (VIEW_UNCONNECTED),
    styleFileName(QCoreApplication::applicationDirPath() + "style-indoor.css")

{
    /*! @brief Create style*/


    ui->setupUi(this);
    ui->mainToolBar->addAction(ui->actionEngineerView);
    ui->mainToolBar->addAction(ui->actionOperatorView);


    m_SerialSettingWindow = new SerialSetting(this); /// create Serial Setting window
    m_debugConsoleWindow = new DebugConsole(this);  ///  create a debug console window

    loadStyle(currentStyle);




    createDockWidgets();

    loadGcsViewState();


    connect(ui->actionEngineerView, SIGNAL(triggered()),SLOT(loadGcsEngineerView()));
    connect(ui->actionOperatorView, SIGNAL(triggered()), SLOT(loadGcsOperatorView()));
    connect(ui->actionCom_Settings,SIGNAL(triggered()),SLOT(onComSettingTriggered()));
    connect(ui->actionConnect,SIGNAL(triggered()),SLOT(onComOpenCloseTriggered()));
    connect(m_SerialSettingWindow->SerialSetting::port,SIGNAL(readyRead()),SLOT(onSerialDataReady()));
    connect(ui->actionDebug_console, SIGNAL(triggered()),SLOT(onDebugConsoleTriggered()));
    connect(m_SerialSettingWindow, SIGNAL(portNameChanged(QString)), SLOT(onPortNameChanged(QString)));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadGcsViewState()
{
    switch (currentView)
    {
    case VIEW_ENGINEER:
        consoleDockWidget->show();
        serialDockWidget->show();
        break;

    case VIEW_OPERATOR:
        consoleDockWidget->hide();
        serialDockWidget->hide();
        break;
    case VIEW_UNCONNECTED:
        consoleDockWidget->hide();
        serialDockWidget->show();
        break;
    case VIEW_FIRMWAREUPDATE:
    case VIEW_FULL:
    default:
        consoleDockWidget->hide();
        serialDockWidget->hide();
        break;
    }
}

/** @brief For style control */
/** @brief Load a specific style */
void MainWindow::loadStyle(MainWindow::GCS_MAINWINDOW_STYLE style)
{
    switch (style) {
    case GCS_MAINWINDOW_STYLE_NATIVE: {
        // Native mode means setting no style
        // so if we were already in native mode
        // take no action
        // Only if a style was set, remove it.
        if (style != currentStyle) {
            qApp->setStyleSheet("");
            showInfoMessage(tr("Please restart QGroundControl"), tr("Please restart QGroundControl to switch to fully native look and feel. Currently you have loaded Qt's plastique style."));
        }
    }
    break;
    case GCS_MAINWINDOW_STYLE_INDOOR:
    qApp->setStyle("fusion");
        styleFileName = ":files/styles/style-indoor.css";
        reloadStylesheet();
        break;
    case GCS_MAINWINDOW_STYLE_OUTDOOR:
    qApp->setStyle("fusion");
        styleFileName = ":files/styles/style-outdoor.css";
        reloadStylesheet();
        break;
    }
    currentStyle = style;
}

/** @brief Reload the CSS style sheet */
void MainWindow::reloadStylesheet()
{
    // Load style sheet
    QFile* styleSheet = new QFile(styleFileName);
    if (!styleSheet->exists())
    {
        styleSheet = new QFile(":files/styles/style-indoor.css");
    }
    if (styleSheet->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString style = QString(styleSheet->readAll());
        style.replace("ICONDIR", QCoreApplication::applicationDirPath()+ "files/styles/");
        qApp->setStyleSheet(style);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText(tr("QGroundControl did lot load a new style"));
        msgBox.setInformativeText(tr("Stylesheet file %1 was not readable").arg(styleFileName));
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
    delete styleSheet;
}

/** @brief Shows an info message as popup or as widget */
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

void MainWindow::selectStylesheet()
{
}

void MainWindow::loadNativeStyle()
{
    loadStyle(GCS_MAINWINDOW_STYLE_NATIVE);
}

void MainWindow::loadIndoorStyle()
{
    loadStyle(GCS_MAINWINDOW_STYLE_INDOOR);
}

void MainWindow::loadOutdoorStyle()
{
    loadStyle(GCS_MAINWINDOW_STYLE_OUTDOOR);
}

void MainWindow::loadGcsUnconnectedView()
{
    if (currentView != VIEW_UNCONNECTED)
    {
//        storeViewState();
        currentView = VIEW_UNCONNECTED;
//        ui.actionUnconnectedView->setChecked(true);
        loadGcsViewState();
    }
}

void MainWindow::loadGcsEngineerView()
{
    if (currentView != VIEW_ENGINEER)
    {
//        storeViewState();
        currentView = VIEW_ENGINEER;
        ui->actionEngineerView->setChecked(true);
        ui->actionOperatorView->setChecked(false);
        loadGcsViewState();
    }
}

void MainWindow::loadGcsOperatorView()
{
    if (currentView != VIEW_OPERATOR)
    {
//        storeViewState();
        currentView = VIEW_OPERATOR;
        ui->actionOperatorView->setChecked(true);
        ui->actionEngineerView->setChecked(false);
        loadGcsViewState();
    }
}

void MainWindow::loadGcsFirmwareUpdateView()
{
    if (currentView != VIEW_FIRMWAREUPDATE)
    {
//        storeViewState();
        currentView = VIEW_FIRMWAREUPDATE;
//        ui.actionFirmwareUpdateView->setChecked(true);
        loadGcsViewState();
    }
}


void MainWindow::onSerialDataReady()
{
//    if(m_SerialSettingWindow->SerialSetting::port->bytesAvailable())
//    {
//        ui->receiveText->moveCursor(QTextCursor::End);
//        ui->receiveText->insertPlainText(QString::fromLatin1(m_SerialSettingWindow->SerialSetting::port->readAll()));
    //    }
}

void MainWindow::onPortNameChanged(QString a_name)
{
    ui->messageDisplay->insertPlainText("Port changed"+a_name);
}

void MainWindow::onComSettingTriggered()
{
    serialDockWidget->show();
}

void MainWindow::onComOpenCloseTriggered()
{

    if(m_SerialSettingWindow->SerialSetting::port->isOpen())
    {
        m_SerialSettingWindow->SerialSetting::port->close();
        ui->actionConnect->setText("Connect");
//        m_debugConsoleWindow->DebugConsole::debug_ui->
    }
    else
    {
        m_SerialSettingWindow->SerialSetting::port->setPortName("COM9");
        m_SerialSettingWindow->SerialSetting::port->open(QIODevice::ReadWrite);
         ui->actionConnect->setText("Disconn");
    }


}



void MainWindow::onDebugConsoleTriggered()
{
    consoleDockWidget->show();
}

void MainWindow::createDockWidgets()
{
    if(!consoleDockWidget){
        /** @brief Create Debug Console widget */
        consoleDockWidget = new QDockWidget(tr("Communication Console"), this);
        consoleDockWidget->setWidget(m_debugConsoleWindow );
        consoleDockWidget->setObjectName("DEBUGCONSOLE_DOCKWIDGET");
        addDockWidget(Qt::BottomDockWidgetArea,consoleDockWidget);
    }
    if(!serialDockWidget)
    {
    /** @brief Create Serial Setting widget */
    serialDockWidget = new QDockWidget(tr("Serial Setting"), this);
    serialDockWidget->setWidget(m_SerialSettingWindow );
    serialDockWidget->setObjectName("SERIALSETTING_DOCKWIDGET");
    addDockWidget(Qt::RightDockWidgetArea,serialDockWidget);
    }
}
