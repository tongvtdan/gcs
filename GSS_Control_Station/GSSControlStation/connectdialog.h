#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>

namespace Ui {
class connectDialog;
}

class QTimer;
class QextSerialPort;

class connectDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit connectDialog(QWidget *parent = 0);
    ~connectDialog();
    
private slots:
    void connectButton_clicked();
    void on_ReadyRead();

private:
    Ui::connectDialog *ui;
    QTimer *mytimer;
    QextSerialPort *myport;
};

#endif // CONNECTDIALOG_H
