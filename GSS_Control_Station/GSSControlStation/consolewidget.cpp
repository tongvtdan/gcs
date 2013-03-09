#include "consolewidget.h"
#include "ui_consolewidget.h"

consolewidget::consolewidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::consolewidget)
{
    ui->setupUi(this);
}

consolewidget::~consolewidget()
{
    delete ui;
}
