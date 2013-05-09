#ifndef DEBUGCONSOLE_H
#define DEBUGCONSOLE_H

#include <QWidget>
#include "SerialSetting.h"
#include "src/ui/mainwindow.h"
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
    MainWindow *m_mainwindow;
public slots:
    /*! @brief send data over serial*/
    void sendData();
    void updatePortNameChanged(QString p_name);
    void onConnectButtonClick(bool buttonstate);
    void onDataReceive(QByteArray m_data);
    void updateLog(QString msgLog);

//    void onAutoPackageSignChanged();
//    void onStartSignChanged();
//    void onStopSignChanged();
signals:
    void m_connectButtonClick();   /// signal when transmit button click
    void sendButtonClick(QByteArray m_text);


private:
    QString str;
};

#endif // DEBUGCONSOLE_H
