#include "DebugConsole.h"
#include "ui_DebugConsole.h"

DebugConsole::DebugConsole(QWidget *parent) :
    QWidget(parent),
    debug_ui(new Ui::DebugConsole)
{
    debug_ui->setupUi(this);
}

DebugConsole::~DebugConsole()
{
    delete debug_ui;
}
