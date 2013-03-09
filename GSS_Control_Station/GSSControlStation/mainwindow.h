#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>

#include "aboutDialog.h"
#include "consolewidget.h"
#include "connectdialog.h"

namespace Ui {
class MainWindow;
}

class QextSerialPort;
class QTimer;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    enum GSC_MAINWINDOW_STYLE
    {
        GSC_MAINWINDOW_STYLE_NATIVE,
        GSC_MAINWINDOW_STYLE_INDOOR,
        GSC_MAINWINDOW_STYLE_OUTDOOR
    };

protected:
    QPointer<QDockWidget> consoleDockWidget; // Debug consolse Dock widget
    QString styleFileName;
    GSC_MAINWINDOW_STYLE currentStyle;
private slots:
    void actionAbout_Clicked();

    /** @brief Load a specific style */
    void loadStyle(GSC_MAINWINDOW_STYLE style);
    /** @brief Reload the CSS style sheet */
    void reloadStylesheet();
    /** @brief Shows an info message as popup or as widget */
    void showInfoMessage(const QString& title, const QString& message);

    void actionDebugConsole_triggered();

    void actionConnect_triggered();

private:
    Ui::MainWindow *ui;
    aboutDialog *my_aboutdialog;
    consolewidget *my_consolewidget;
    connectDialog *my_connectDialog;

    QextSerialPort *myport;
    QTimer *mytimer;

    void createDockWindows(); // to create Dock Widget

};

#endif // MAINWINDOW_H
