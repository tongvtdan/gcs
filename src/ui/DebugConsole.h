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

private:
    Ui::DebugConsole *debug_ui;
};

#endif // DEBUGCONSOLE_H
