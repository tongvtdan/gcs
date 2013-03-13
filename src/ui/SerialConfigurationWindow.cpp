

#include "qextserialport.h"
#include "qextserialenumerator.h"
#include "SerialConfigurationWindow.h"
#include "ui_SerialConfigurationWindow.h"
//#include "DebugConsole.h"


#include <QtCore>
SerialSettingsWindow::SerialSettingsWindow(QWidget *parent) :
    QDialog(parent),
    port_ui(new Ui::SerialSettingsWindow)
{
    port_ui->setupUi(this);

    //! [0]

    foreach (QextPortInfo info, QextSerialEnumerator::getPorts())
    {
        if(info.portName !="")      // don't add dummy port names
        {
         port_ui->portBox->addItem(info.portName);
        }
    }
    //make sure user can input their own port name!
    port_ui->portBox->setEditable(true);

    port_ui->baudRateBox->addItem("1200", BAUD1200);
    port_ui->baudRateBox->addItem("2400", BAUD2400);
    port_ui->baudRateBox->addItem("4800", BAUD4800);
    port_ui->baudRateBox->addItem("9600", BAUD9600);
    port_ui->baudRateBox->addItem("19200", BAUD19200);
    port_ui->baudRateBox->setCurrentIndex(3);

    port_ui->parityBox->addItem("NONE", PAR_NONE);
    port_ui->parityBox->addItem("ODD", PAR_ODD);
    port_ui->parityBox->addItem("EVEN", PAR_EVEN);

    port_ui->dataBitsBox->addItem("5", DATA_5);
    port_ui->dataBitsBox->addItem("6", DATA_6);
    port_ui->dataBitsBox->addItem("7", DATA_7);
    port_ui->dataBitsBox->addItem("8", DATA_8);
    port_ui->dataBitsBox->setCurrentIndex(3);

    port_ui->stopBitsBox->addItem("1", STOP_1);
    port_ui->stopBitsBox->addItem("2", STOP_2);

    port_ui->queryModeBox->addItem("Polling", QextSerialPort::Polling);
    port_ui->queryModeBox->addItem("EventDriven", QextSerialPort::EventDriven);
    //! [0]
//    port_ui->led->turnOff();
    timer = new QTimer(this);
    timer->setInterval(40);
    //! [1]
    PortSettings settings = {BAUD9600, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 10};
    port = new QextSerialPort(port_ui->portBox->currentText(), settings, QextSerialPort::Polling);
    //! [1]

    enumerator = new QextSerialEnumerator(this);
    enumerator->setUpNotifications();

    m_debugConsole = new DebugConsole(this);


    connect(port_ui->baudRateBox, SIGNAL(currentIndexChanged(int)), SLOT(onBaudRateChanged(int)));
    connect(port_ui->parityBox, SIGNAL(currentIndexChanged(int)), SLOT(onParityChanged(int)));
    connect(port_ui->dataBitsBox, SIGNAL(currentIndexChanged(int)), SLOT(onDataBitsChanged(int)));
    connect(port_ui->stopBitsBox, SIGNAL(currentIndexChanged(int)), SLOT(onStopBitsChanged(int)));
    connect(port_ui->queryModeBox, SIGNAL(currentIndexChanged(int)), SLOT(onQueryModeChanged(int)));
    connect(port_ui->timeoutBox, SIGNAL(valueChanged(int)), SLOT(onTimeoutChanged(int)));
    connect(port_ui->portBox, SIGNAL(editTextChanged(QString)), SLOT(onPortNameChanged(QString)));
    connect(port_ui->connectButton, SIGNAL(clicked()), SLOT(onConnectButtonClicked()));
    connect(port_ui->closeButton, SIGNAL(clicked()), SLOT(onCloseButtonClicked()));

    connect(enumerator, SIGNAL(deviceDiscovered(QextPortInfo)), SLOT(onPortAddedOrRemoved()));
    connect(enumerator, SIGNAL(deviceRemoved(QextPortInfo)), SLOT(onPortAddedOrRemoved()));

}

SerialSettingsWindow::~SerialSettingsWindow()
{
    delete port_ui;
    delete port;
}

void SerialSettingsWindow::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        port_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void SerialSettingsWindow::onPortNameChanged(const QString &/*name*/)
{
    if (port->isOpen()) {
        port->close();
//        port_ui->led->turnOff();
    }
}

void SerialSettingsWindow::onBaudRateChanged(int idx)
{
    port->setBaudRate((BaudRateType)port_ui->baudRateBox->itemData(idx).toInt());
}

void SerialSettingsWindow::onParityChanged(int idx)
{
    port->setParity((ParityType)port_ui->parityBox->itemData(idx).toInt());
}

void SerialSettingsWindow::onDataBitsChanged(int idx)
{
    port->setDataBits((DataBitsType)port_ui->dataBitsBox->itemData(idx).toInt());
}

void SerialSettingsWindow::onStopBitsChanged(int idx)
{
    port->setStopBits((StopBitsType)port_ui->stopBitsBox->itemData(idx).toInt());
}

void SerialSettingsWindow::onQueryModeChanged(int idx)
{
    port->setQueryMode((QextSerialPort::QueryMode)port_ui->queryModeBox->itemData(idx).toInt());
}

void SerialSettingsWindow::onTimeoutChanged(int val)
{
    port->setTimeout(val);
}

void SerialSettingsWindow::onCloseButtonClicked()
{
    this->reject();
}

void SerialSettingsWindow::onConnectButtonClicked()
{
    if(!port->isOpen())
    {
        port->setPortName(port_ui->portBox->currentText());
        port->open(QIODevice::ReadWrite);
        port_ui->connectButton->setText("Disconnect");
        port_ui->connectStatusLabel->setText("Connected");
    }
    else
    {
        port->close();
        port_ui->connectButton->setText("Connect");
        port_ui->connectStatusLabel->setText("Disconnected");
    }
//    port_ui->led->turnOn(port->isOpen());
}

void SerialSettingsWindow::onReadyRead()
{
}

void SerialSettingsWindow::onPortAddedOrRemoved()
{
    QString current = port_ui->portBox->currentText();

    port_ui->portBox->blockSignals(true);
    port_ui->portBox->clear();
    foreach (QextPortInfo info, QextSerialEnumerator::getPorts())
        if(info.portName != "")
        port_ui->portBox->addItem(info.portName);

    port_ui->portBox->setCurrentIndex(port_ui->portBox->findText(current));

    port_ui->portBox->blockSignals(false);
}
