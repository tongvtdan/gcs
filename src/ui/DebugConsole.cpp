#include "DebugConsole.h"
#include "ui_DebugConsole.h"
#include "SerialSetting.h"
#include <QDebug>
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
    debug_ui->receiveText->appendHtml(QString("<font color=\"red\">Port %1 is selected!</font>\n").arg((p_name)));
}

void DebugConsole::onConnectButtonClick(bool buttonstate)
{
    if(buttonstate)
    {
        debug_ui->connectButton->setText("Disconn.");
        debug_ui->receiveText->appendHtml(QString("<font color=\"yellow\">Port is connected </font>\n"));
    }
    else
    {
        debug_ui->connectButton->setText("Connect");
        debug_ui->receiveText->appendHtml(QString("<font color=\"yellow\">Port is disconnected </font>\n"));
    }
}

void DebugConsole::onDataReceive(QByteArray m_data)
{

    int len = m_data.size();
    int i;

    /// find packageStart sign
    for(i=0;i<len;i++)
    {
        if(m_data.at(i) == '$') /// detect package Start sign
        {
            str="";
            str[0] = '$';

        }
        else
        {
            if(str[0] == '$')
            {
                str.append(m_data.at(i));
            }

        }
    }

    if(str[str.length()-1] == '#')      /// detect the package stop sign #
//    if(str.length() == 4)               ///  detect number of bytes.
    {
        debug_ui->receiveText->appendHtml(QString("<font color=\"green\">string Reveiced: %1</font>").arg(str)) ;
        str = "";
    }

}
