#include <QFile>        // for file operation
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentStyle(GCS_MAINWINDOW_STYLE_INDOOR),
    styleFileName(QCoreApplication::applicationDirPath() + "style-indoor.css")

{
    ui->setupUi(this);
    ui->mainToolBar->addAction(ui->actionEngineer);
    ui->mainToolBar->addAction(ui->actionOperator);
    //    currentStyle = GCS_MAINWINDOW_STYLE_INDOOR;
    //    styleFileName = QCoreApplication::applicationDirPath() + "styles/style-indoor.css";
    loadStyle(currentStyle);
}

MainWindow::~MainWindow()
{
    delete ui;
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
    qApp->setStyle("plastique");
        styleFileName = ":files/styles/style-indoor.css";
        reloadStylesheet();
        break;
    case GCS_MAINWINDOW_STYLE_OUTDOOR:
    qApp->setStyle("plastique");
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

