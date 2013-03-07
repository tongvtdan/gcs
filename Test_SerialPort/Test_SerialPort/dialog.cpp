#include "dialog.h"
#include "ui_dialog.h"
#include <QtCore/QStringList>
#include <QtCore/QTimer>
#include <QtCore/QVariant>
#include "qextserialport.h"
#include <QextSerialEnumerator.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    /* config comport combobox*/
    QList<QextPortInfo> portlist = QextSerialEnumerator::getPorts();
    #ifdef Q_OS_WIN
        foreach(QextPortInfo port,portlist)
        {
            ui->comportBox->addItems(QStringList()<<(port.portName));
        }
    #else
        ui->portBox->addItems(QStringList()<<QLatin1String("/dev/ttyS0")<<QLatin1String("/dev/ttyS1")<<QLatin1String("/dev/ttyUSB0")<<QLatin1String("/dev/ttyUSB1"));
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
    ui->parityBox->setCurrentIndex(2);

    /* config stop bits combobox*/
    ui->stopbitsBox->addItem("1",STOP_1);
    ui->stopbitsBox->addItem("2",STOP_2);

    /* config query mode combobox*/
    ui->querymodeBox->addItem("Polling",QextSerialPort::Polling);
    ui->querymodeBox->addItem("EventDriven",QextSerialPort::EventDriven);

    //ui->statuslabel->setText("com port opened!");

    /* config Timer */
    mytimer = new QTimer(this);
    mytimer->setInterval(40);

    PortSettings myportsetting = {BAUD9600,DATA_8,PAR_NONE,STOP_1,FLOW_OFF,10};

    myport = new QextSerialPort(ui->comportBox->currentText(),myportsetting,QextSerialPort::Polling);

    connect(ui->opencloseButton,SIGNAL(clicked()),SLOT(on_opencloseButton_clicked()));
    connect(ui->sendButton,SIGNAL(clicked()),SLOT(on_sendButton_clicked()));
    connect(mytimer, SIGNAL(timeout()), SLOT(on_ReadyRead()));
    connect(myport,SIGNAL(readyRead()),SLOT(on_ReadyRead()));

    setWindowTitle(QLatin1String("SerialPort Demo"));
}

Dialog::~Dialog()
{
    delete ui;
    delete myport;
}

void Dialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Dialog::on_baudrateBox_currentIndexChanged(int index)
{
    //myport->setBaudRate((BaudRateType)9600);
}

void Dialog::on_databitsBox_currentIndexChanged(int index)
{
    //myport->setDataBits((DataBitsType)8);
}

void Dialog::on_opencloseButton_clicked()
{
    ui->comboBox->addItem("item");
    if (myport->isOpen()== false)
    {
        myport->setPortName(ui->comportBox->currentText());
        myport->open(QIODevice::ReadWrite);
        ui->statuslabel->setText("PORT OPENED");
    }

    else
    {
        myport->close();
        ui->statuslabel->setText("PORT CLOSED");
    }

    if (myport->isOpen()) {
        if (myport->queryMode() == QextSerialPort::Polling)
            mytimer->start();

       // ui->led->turnOn();
    }
    else {
        mytimer->stop();
        //ui->led->turnOff();
    }
}

void Dialog::on_sendButton_clicked()
{
    if (myport->isOpen() && !(ui->sendTextEdit->toPlainText().isEmpty()))
        myport->write(ui->sendTextEdit->toPlainText().toLatin1());
}

void Dialog::on_ReadyRead()
{
    //EventDriven test.
    if (qApp->arguments().contains(QLatin1String("--debug")) && myport->queryMode()==QextSerialPort::EventDriven){
        ui->receiTextEdit->appendPlainText(QString::number(myport->bytesAvailable()));
        return;
    }

    if (myport->bytesAvailable()) {
        ui->receiTextEdit->moveCursor(QTextCursor::End);
        ui->receiTextEdit->insertPlainText(QString::fromLatin1(myport->readAll()));
    }
}
