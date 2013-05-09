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

private slots:
    void on_forward_Button_clicked();
    void on_backward_Button_clicked();

    void on_right_Button_clicked();

    void on_left_Button_clicked();

    void on_stopButton_clicked();

signals:
    void naviButtonClick(QByteArray m_text);
    void bkwButtonCLick(QByteArray m_text);
    void leftButtonCLick(QByteArray m_text);
    void rightButtonCLick(QByteArray m_text);
    void stopButtonCLick(QByteArray m_text);

private:
    Ui::GSSRobotConfig *ui;
};

#endif // GSSROBOTCONFIG_H
