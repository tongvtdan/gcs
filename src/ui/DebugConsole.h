#ifndef DEBUGCONSOLE_H
#define DEBUGCONSOLE_H

#include <QWidget>

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
signals:
    void m_transmitButtonClick();   /// signal when transmit button click


private:
//    Ui::DebugConsole *debug_ui;
};

#endif // DEBUGCONSOLE_H
