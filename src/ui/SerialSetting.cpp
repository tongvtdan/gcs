#include "SerialSetting.h"
#include "ui_SerialSetting.h"
#include "qextserialport.h"
#include "qextserialenumerator.h"
#include "DebugConsole.h"
#include "mainwindow.h"

SerialSetting::SerialSetting(QWidget *parent) :
    QWidget(parent),
    serial_ui(new Ui::SerialSetting)
{
    serial_ui->setupUi(this);

    foreach (QextPortInfo info, QextSerialEnumerator::getPorts())
    {
        if(info.portName !="")      // don't add dummy port names
        {
         serial_ui->portBox->addItem(info.portName);
        }
    }
    //make sure user can input their own port name!
    serial_ui->portBox->setEditable(true);

    serial_ui->baudRateBox->addItem("1200", BAUD1200);
    serial_ui->baudRateBox->addItem("2400", BAUD2400);
    serial_ui->baudRateBox->addItem("4800", BAUD4800);
    serial_ui->baudRateBox->addItem("9600", BAUD9600);
    serial_ui->baudRateBox->addItem("19200", BAUD19200);
    serial_ui->baudRateBox->setCurrentIndex(3);

    serial_ui->parityBox->addItem("NONE", PAR_NONE);
    serial_ui->parityBox->addItem("ODD", PAR_ODD);
    serial_ui->parityBox->addItem("EVEN", PAR_EVEN);

    serial_ui->dataBitsBox->addItem("5", DATA_5);
    serial_ui->dataBitsBox->addItem("6", DATA_6);
    serial_ui->dataBitsBox->addItem("7", DATA_7);
    serial_ui->dataBitsBox->addItem("8", DATA_8);
    serial_ui->dataBitsBox->setCurrentIndex(3);

    serial_ui->stopBitsBox->addItem("1", STOP_1);
    serial_ui->stopBitsBox->addItem("2", STOP_2);

    serial_ui->queryModeBox->addItem("EventDriven", QextSerialPort::EventDriven);

    //! [1]
    PortSettings settings = {BAUD9600, DATA_8, PAR_NONE, STOP_1, FLOW_OFF,10};
    port = new QextSerialPort(serial_ui->portBox->currentText(), settings, QextSerialPort::EventDriven);
    //! [1]

    enumerator = new QextSerialEnumerator(this);
    enumerator->setUpNotifications();
//    m_console = new DebugConsole(this);
//    m_console->hide();

    connect(serial_ui->baudRateBox, SIGNAL(currentIndexChanged(int)), SLOT(onBaudRateChanged(int)));
    connect(serial_ui->parityBox, SIGNAL(currentIndexChanged(int)), SLOT(onParityChanged(int)));
    connect(serial_ui->dataBitsBox, SIGNAL(currentIndexChanged(int)), SLOT(onDataBitsChanged(int)));
    connect(serial_ui->stopBitsBox, SIGNAL(currentIndexChanged(int)), SLOT(onStopBitsChanged(int)));
    connect(serial_ui->queryModeBox, SIGNAL(currentIndexChanged(int)), SLOT(onQueryModeChanged(int)));
    connect(serial_ui->portBox, SIGNAL(editTextChanged(QString)), SLOT(onPortNameChanged(QString))); /// connect to outside of this class

    connect(enumerator, SIGNAL(deviceDiscovered(QextPortInfo)), SLOT(onPortAddedOrRemoved()));
    connect(enumerator, SIGNAL(deviceRemoved(QextPortInfo)), SLOT(onPortAddedOrRemoved()));
    connect(port, SIGNAL(readyRead()),SLOT(onReadyRead()));
    connect(port,SIGNAL(aboutToClose()),SLOT(updatePortStatus()));

}

SerialSetting::~SerialSetting()
{
    delete serial_ui;
    delete port;
}

void SerialSetting::onPortNameChanged(const QString &newname)
{
    if(port->isOpen())
    {
        port->close();
    }
    if(m_name != newname)
    {
        m_name = newname;
    }
    emit portNameChanged(m_name);
}

void SerialSetting::onBaudRateChanged(int idx)
{
    port->setBaudRate((BaudRateType)serial_ui->baudRateBox->itemData(idx).toInt());
}

void SerialSetting::onParityChanged(int idx)
{
    port->setParity((ParityType)serial_ui->parityBox->itemData(idx).toInt());
}

void SerialSetting::onDataBitsChanged(int idx)
{
    port->setDataBits((DataBitsType)serial_ui->dataBitsBox->itemData(idx).toInt());
}

void SerialSetting::onStopBitsChanged(int idx)
{
    port->setStopBits((StopBitsType)serial_ui->stopBitsBox->itemData(idx).toInt());
}

void SerialSetting::onQueryModeChanged(int idx)
{
    port->setQueryMode((QextSerialPort::QueryMode)serial_ui->queryModeBox->itemData(idx).toInt());
}

void SerialSetting::onReadyRead()
{
    if (port->bytesAvailable()) {
        emit dataAvailable(port->readAll());    /// emit the signal with data received
    }
}

void SerialSetting::onPortAddedOrRemoved()
{
    QString current = serial_ui->portBox->currentText();

    serial_ui->portBox->blockSignals(true);
    serial_ui->portBox->clear();
    foreach (QextPortInfo info, QextSerialEnumerator::getPorts())
        if(info.portName != "")
        serial_ui->portBox->addItem(info.portName);

    serial_ui->portBox->setCurrentIndex(serial_ui->portBox->findText(current));

    serial_ui->portBox->blockSignals(false);

}


void SerialSetting::updatePortStatus()
{
   port->flush();
}

