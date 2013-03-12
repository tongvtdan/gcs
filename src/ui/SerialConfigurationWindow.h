#ifndef SERIALCONFIGURATIONWINDOW_H
#define SERIALCONFIGURATIONWINDOW_H

#include <QDialog>
#include "DebugConsole.h"

namespace Ui {
class SerialSettingsWindow;
}
class QTimer;
class QextSerialPort;
class QextSerialEnumerator;

class SerialSettingsWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit SerialSettingsWindow(QWidget *parent = 0);
    ~SerialSettingsWindow();
    QTimer *timer;
    QextSerialPort *port;
    QextSerialEnumerator *enumerator;
    Ui::SerialSettingsWindow *port_ui;

protected:
    void changeEvent(QEvent *e);
private Q_SLOTS:
    void onPortNameChanged(const QString &);
    void onBaudRateChanged(int idx);
    void onParityChanged(int idx);
    void onDataBitsChanged(int idx);
    void onStopBitsChanged(int idx);
    void onQueryModeChanged(int idx);
    void onTimeoutChanged(int val);
    void onCloseButtonClicked();
    void onConnectButtonClicked();
    void onReadyRead();

    void onPortAddedOrRemoved();

private:
    DebugConsole *m_debugConsole;
//    Ui::SerialSettingsWindow *port_ui;

//    QTimer *timer;
//    QextSerialPort *port;
//    QextSerialEnumerator *enumerator;


};

#endif // SERIALCONFIGURATIONWINDOW_H
