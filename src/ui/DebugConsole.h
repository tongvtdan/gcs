#ifndef DEBUGCONSOLE_H
#define DEBUGCONSOLE_H

#include <QDialog>

namespace Ui {
class DebugConsole;
}

class DebugConsole : public QDialog
{
    Q_OBJECT
    
public:
    explicit DebugConsole(QWidget *parent = 0);
    ~DebugConsole();
    
    Ui::DebugConsole *debug_ui;
private:
//    Ui::DebugConsole *debug_ui;
};

#endif // DEBUGCONSOLE_H
