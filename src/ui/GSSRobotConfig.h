#ifndef GSSROBOTCONFIG_H
#define GSSROBOTCONFIG_H

#include <QWidget>

namespace Ui {
class GSSRobotConfig;
}

class GSSRobotConfig : public QWidget
{
    Q_OBJECT
    
public:
    explicit GSSRobotConfig(QWidget *parent = 0);
    ~GSSRobotConfig();
    
private:
    Ui::GSSRobotConfig *ui;
};

#endif // GSSROBOTCONFIG_H
