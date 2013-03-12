#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "SerialConfigurationWindow.h"
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
protected:
    QString styleFileName;
    GCS_MAINWINDOW_STYLE currentStyle;
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

    void comPortOpenCloseButtonClick();
    void onSerialDataReady();
private Q_SLOTS:
    void onComSettingTriggered();
    void onComOpenCloseTriggered();
    void onSendButtonClick();



private:
    Ui::MainWindow *ui;
    SerialSettingsWindow *m_SerialConfigWindow;
    QextSerialPort *m_port;
};

#endif // MAINWINDOW_H
