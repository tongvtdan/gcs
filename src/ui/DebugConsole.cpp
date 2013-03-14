#include "DebugConsole.h"
#include "ui_DebugConsole.h"
#include "SerialSetting.h"

DebugConsole::DebugConsole(QWidget *parent) :
    QWidget(parent),
    debug_ui(new Ui::DebugConsole)
{
    debug_ui->setupUi(this);
    connect(debug_ui->sendText, SIGNAL(returnPressed()),SLOT(sendData()));
    connect(debug_ui->sendButton,SIGNAL(clicked()),SLOT(sendData()));
    connect(debug_ui->connectButton,SIGNAL(clicked()),SIGNAL(m_connectButtonClick()));
    connect(debug_ui->connectButton,SIGNAL(toggled(bool)),SLOT(onConnectButtonClick(bool)));

}

DebugConsole::~DebugConsole()
{
    delete debug_ui;
}

void DebugConsole::sendData()
{
    debug_ui->sentText->clear();
    debug_ui->sentText->setText("Sent: "+ debug_ui->sendText->text());
    emit sendButtonClick(debug_ui->sendText->text().toLatin1());

}

void DebugConsole::updatePortNameChanged(QString p_name)
{
//    debug_ui->receiveText->appendPlainText("Selected: "+ p_name);
    debug_ui->receiveText->appendHtml(QString("<font color=\"red\">Port %1 is selected!</font>\n").arg((p_name)));
}

void DebugConsole::onConnectButtonClick(bool buttonstate)
{
    if(buttonstate)
    {
        debug_ui->connectButton->setText("Disconn.");
    }
    else debug_ui->connectButton->setText("Connect");
}

void DebugConsole::onDataReceive(QByteArray m_data)
{
    debug_ui->receiveText->appendHtml(QString("<font color=\"green\">Reveiced: %1</font>\n").arg(QString::fromLatin1(m_data))) ;
//            appendPlainText(QString::fromLatin1(m_data));
}
