#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>
#include <QStackedWidget>

#include "SerialSetting.h"
#include "qextserialport.h"
#include "DebugConsole.h"
#include "GSSRobotConfig.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    // window style
    enum GCS_MAINWINDOW_STYLE
        {
            GCS_MAINWINDOW_STYLE_NATIVE,
            GCS_MAINWINDOW_STYLE_INDOOR,
            GCS_MAINWINDOW_STYLE_OUTDOOR
        };

    enum GCS_VIEW_SECTIONS
    {
        VIEW_ENGINEER,
        VIEW_OPERATOR,
        VIEW_FIRMWAREUPDATE,
        VIEW_UNCONNECTED,    ///< View in unconnected mode, when no GSS System is available
        VIEW_FULL            ///< All widgets shown at once
    };
    SerialSetting *m_SerialSettingWindow;
    DebugConsole *m_debugConsoleWindow;
    GSSRobotConfig *m_robotConfigWindow;
protected:

    GCS_MAINWINDOW_STYLE currentStyle;
    /** @brief Keeps track of the current view */
    GCS_VIEW_SECTIONS currentView;

    QString styleFileName;

    QPointer<QDockWidget> consoleDockWidget; // Debug consolse Dock widget
    QPointer<QDockWidget> serialDockWidget;
    QPointer<GSSRobotConfig> robotConfigDockWidget;

    void loadGcsViewState();

    /**
     * @brief Adds an already instantiated QWidget to the center stack
     *
     * This function does all the hosekeeping to have a QWidget added to the tools menu
     * tools menu and connects the QMenuAction to a slot that shows the widget and
     * checks/unchecks the tools menu item. This is used for all the central widgets (those in
     * the center stack.
     *
     * @param widget        The QWidget being added
     * @param title         The entry that will appear in the Menu
     */
    void addCentralWidget(QWidget* widget, const QString& title);


public slots:
    /** @brief Load a specific style */
    void loadStyle(GCS_MAINWINDOW_STYLE style);
    /** @brief Reload the CSS style sheet */
    void reloadStylesheet();
    /** @brief Shows an info message as popup or as widget */
    void showInfoMessage(const QString& title, const QString& message);
    /** @brief Get current visual style */
    int getStyle()
    {
        return currentStyle;
    }
    /** @brief Let the user select the CSS style sheet */
    void selectStylesheet();
    /** @brief Switch to native application style */
    void loadNativeStyle();
    /** @brief Switch to indoor mission style */
    void loadIndoorStyle();
    /** @brief Switch to outdoor mission style */
    void loadOutdoorStyle();

    /** @brief Load default view when no GSS System is connected */
    void loadGcsUnconnectedView();
    /** @brief Load view for engineer */
    void loadGcsEngineerView();
    /** @brief Load view for operator */
    void loadGcsOperatorView();
    /** @brief Load firmware update view */
    void loadGcsFirmwareUpdateView();

    void onSerialDataReady(QByteArray m_dataReceived);       /// will connect data received from port in Serial Setting window to display inDebug console window
    void getPortNameChanged(QString a_name);
    void handleConnection();    /// handle connection between Serial Setting and other widgets
    void onSendData(QByteArray m_data);    /// will call slot from Serial

    /**
     * @brief Shows a Widget from the center stack based on the action sender
     *
     * This slot is written to be used in conjunction with the addCentralWidget() function
     * It shows the Widget based on the action sender
     *
     */

private Q_SLOTS:
    void onComSettingTriggered();
    void onComOpenCloseTriggered();
    void onDebugConsoleTriggered();


signals:
    void connectionStatus(bool comportStatus);
private:
    Ui::MainWindow *ui;

    QextSerialPort *m_port;
    QString m_portName;

    void createDockWidgets();

};

#endif // MAINWINDOW_H
