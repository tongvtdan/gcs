#ifndef DEBUGCONSOLE_H
#define DEBUGCONSOLE_H

#include <QWidget>
#include "SerialSetting.h"
namespace Ui {
class DebugConsole;
}

class DebugConsole : public QWidget
{
    Q_OBJECT

public:
    explicit DebugConsole(QWidget *parent = 0);
    ~DebugConsole();

    Ui::DebugConsole *debug_ui;
public slots:
    /*! @brief send data over serial*/
    void sendData();
    void updatePortNameChanged(QString p_name);
    void onConnectButtonClick(bool buttonstate);
    void onDataReceive(QByteArray m_data);
signals:
    void m_connectButtonClick();   /// signal when transmit button click
    void sendButtonClick(QByteArray m_text);


private:
//    SerialSetting* m_serial;
};

#endif // DEBUGCONSOLE_H
