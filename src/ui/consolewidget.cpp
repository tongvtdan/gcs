#include "consolewidget.h"
#include "ui_consolewidget.h"

#include "connectdialog.h"
#include "mainwindow.h"

consolewidget::consolewidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::consolewidget)
{
    ui->setupUi(this);

//    connect(mytimer, SIGNAL(timeout()), SLOT(on_ReadyRead()));
//    connect(myport,SIGNAL(readyRead()),SLOT(on_ReadyRead()));
}

consolewidget::~consolewidget()
{
    delete ui;
}

void consolewidget::on_ReadyRead()
{
    /* EventDriven test */
    //    if (qApp->arguments().contains(QLatin1String("--debug")) && myport->queryMode()==QextSerialPort::EventDriven){
    //        ui->receiTextEdit->appendPlainText(QString::number(myport->bytesAvailable()));
    //        return;
    //    }

    //        if (myport->queryMode()==QextSerialPort::EventDriven){
    //            ui->receiTextEdit->appendPlainText(QString::number(myport->bytesAvailable()));
    //            return;
    //        }

//        if (my_connectDialog.myport->bytesAvailable()) {
//            ui->receiTextEdit->moveCursor(QTextCursor::End);
//            ui->receiTextEdit->insertPlainText(QString::fromLatin1(myport->readAll()));
//            ui->receiTextEdit->insertPlainText(QString::fromLatin1(myport->readLine()));
//        }
}

