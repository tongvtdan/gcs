#include "DebugConsole.h"
#include "ui_DebugConsole.h"

DebugConsole::DebugConsole(QWidget *parent) :
    QWidget(parent),
    debug_ui(new Ui::DebugConsole)
{
    debug_ui->setupUi(this);
    connect(debug_ui->sendText, SIGNAL(returnPressed()),SLOT(sendData()));
}

DebugConsole::~DebugConsole()
{
    delete debug_ui;
}

void DebugConsole::sendData()
{
    debug_ui->sentText->setText(debug_ui->sendText->text());

}
