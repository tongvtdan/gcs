#include "DebugConsole.h"
#include "ui_DebugConsole.h"

DebugConsole::DebugConsole(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DebugConsole)
{
    ui->setupUi(this);
}

DebugConsole::~DebugConsole()
{
    delete ui;
}
