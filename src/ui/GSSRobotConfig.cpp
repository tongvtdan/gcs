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
