#include "connectdialog.h"
#include "ui_connectdialog.h"

#include "qextserialport.h"
#include <QextSerialEnumerator.h>

#include <QtCore/QStringList>
#include <QtCore/QTimer>
#include <QtCore/QVariant>


connectDialog::connectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connectDialog)
{
    ui->setupUi(this);

    //ui->comportBox->addItem("COM1",100);

    /* config comport combobox*/
    QList<QextPortInfo> portlist = QextSerialEnumerator::getPorts();
    #ifdef Q_OS_WIN
        foreach(QextPortInfo port,portlist)
        {
            ui->comportBox->addItems(QStringList()<<(port.portName));
        }
    #else
        ui->comportBox->addItems(QStringList()<<QLatin1String("/dev/ttyS0")<<QLatin1String("/dev/ttyS1")<<QLatin1String("/dev/ttyUSB0")<<QLatin1String("/dev/ttyUSB1"));
    #endif

    ui->comportBox->setCurrentIndex(0);

    /* config baudrate combobox*/
    ui->baudrateBox->addItem("9600",BAUD9600);
    ui->baudrateBox->addItem("57600",BAUD57600);
    ui->baudrateBox->addItem("115200",BAUD115200);
    ui->baudrateBox->setCurrentIndex(0);

    /* config baudrate combobox*/
    ui->databitsBox->addItem("7",DATA_7);
    ui->databitsBox->addItem("8",DATA_8);
    ui->databitsBox->setCurrentIndex(1);

    /* config parity combobox*/
    ui->parityBox->addItem("NONE",PAR_NONE);
    ui->parityBox->addItem("ODD",PAR_ODD);
    ui->parityBox->addItem("EVEN",PAR_EVEN);
    //ui->parityBox->setCurrentIndex(0);

    /* config stop bits combobox*/
    ui->stopbitsBox->addItem("1",STOP_1);
    ui->stopbitsBox->addItem("2",STOP_2);

    /* config query mode combobox*/
    ui->querymodeBox->addItem("Polling",QextSerialPort::Polling);
    ui->querymodeBox->addItem("Event Driven",QextSerialPort::EventDriven);
    ui->querymodeBox->setCurrentIndex(1);

    /* config Timer */
    mytimer = new QTimer(this);
    mytimer->setInterval(10);

    PortSettings myportsetting = {BAUD9600,DATA_8,PAR_NONE,STOP_1,FLOW_OFF,10};
    myport = new QextSerialPort(ui->comportBox->currentText(),myportsetting,QextSerialPort::EventDriven);

    connect(ui->connectButton,SIGNAL(clicked()),SLOT(connectButton_clicked()));
    //connect(ui->sendButton,SIGNAL(clicked()),SLOT(sendButton_clicked()));
    //connect(ui->cleartranButton,SIGNAL(clicked()),SLOT(cleartranButton_clicked()));
    //connect(ui->clearRecButton,SIGNAL(clicked()),SLOT(clearreceiButton_clicked()));
    //connect(mytimer, SIGNAL(timeout()), SLOT(on_ReadyRead()));
    //connect(myport,SIGNAL(readyRead()),SLOT(on_ReadyRead()));
}

connectDialog::~connectDialog()
{
    delete ui;
}

void connectDialog::connectButton_clicked()
{
    if (myport->isOpen()== false)
    {
        myport->setPortName(ui->comportBox->currentText());
        myport->open(QIODevice::ReadWrite);
        ui->connectButton->setText("Disconnect");
        ui->linkstatuslabel->setText("Connected");
    }
    else
    {
        myport->close();
        ui->connectButton->setText("Connect");
        ui->linkstatuslabel->setText("Disconnected");
    }

    if (myport->isOpen()) {
        if (myport->queryMode() == QextSerialPort::EventDriven)
            mytimer->start();
    }
    else {
        mytimer->stop();
    }
}

void connectDialog::on_ReadyRead()
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

//    if (myport->bytesAvailable()) {
//        ui->receiTextEdit->moveCursor(QTextCursor::End);
//        //ui->receiTextEdit->insertPlainText(QString::fromLatin1(myport->readAll()));
//        ui->receiTextEdit->insertPlainText(QString::fromLatin1(myport->readLine()));
//    }
}


