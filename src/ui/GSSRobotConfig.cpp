#include "GSSRobotConfig.h"
#include "ui_GSSRobotConfig.h"

GSSRobotConfig::GSSRobotConfig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GSSRobotConfig)
{
    ui->setupUi(this);
}

GSSRobotConfig::~GSSRobotConfig()
{
    delete ui;
}

void GSSRobotConfig::on_forward_Button_clicked()
{
    QString m_str;
    m_str = "TP1*S5*D70*#";
    emit naviButtonClick(m_str.toLatin1());
    ui->stopButton->setChecked(false);
}
void GSSRobotConfig::on_backward_Button_clicked()
{
    QString m_str;
    m_str = "TP1*S5*D66*#";
    emit naviButtonClick(m_str.toLatin1());
    ui->stopButton->setChecked(false);
}

void GSSRobotConfig::on_right_Button_clicked()
{
    QString m_str;
    m_str = "TP1*S5*D82*#";
    emit naviButtonClick(m_str.toLatin1());
}

void GSSRobotConfig::on_left_Button_clicked()
{
    QString m_str;
    m_str = "TP1*S5*D76*#";
    emit naviButtonClick(m_str.toLatin1());
}

void GSSRobotConfig::on_stopButton_clicked()
{
    QString m_str;
    m_str = "TP1*S5*D79*#";
    emit naviButtonClick(m_str.toLatin1());
}
