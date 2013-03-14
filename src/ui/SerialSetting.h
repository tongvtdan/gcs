#ifndef SERIALSETTING_H
#define SERIALSETTING_H

#include <QWidget>
#include "DebugConsole.h"

namespace Ui {
class SerialSetting;
}
class QextSerialPort;
class QextSerialEnumerator;
class DebugConsole;

class SerialSetting : public QWidget
{
    Q_OBJECT

public:
    explicit SerialSetting(QWidget *parent = 0);
    ~SerialSetting();

    QextSerialPort *port;
    QextSerialEnumerator *enumerator;
    Ui::SerialSetting *serial_ui;

public slots:
    void onPortNameChanged(const QString &newname);
    void onBaudRateChanged(int idx);
    void onParityChanged(int idx);
    void onDataBitsChanged(int idx);
    void onStopBitsChanged(int idx);
    void onQueryModeChanged(int idx);
    /*! Connect port->readyRead signal in order to call from outside*/
    void onReadyRead();
    /*! Trigger when a device plug or unplug from COM/USB port*/
    void onPortAddedOrRemoved();
    /*! Update a status label in Serial Setting Window*/
    void updatePortStatus();
signals:
    void portNameChanged(QString newname);
    void dataAvailable(QByteArray m_data);
private:
    DebugConsole* m_console;
    QString m_name;

};

#endif // SERIALSETTING_H
