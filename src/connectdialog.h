#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>
//#include "mainwindow.h"

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
    QextSerialPort *myport;
private slots:
    void ComOKBtn_clicked();

private:
    Ui::connectDialog *ui;
    QTimer *mytimer;

};

#endif // CONNECTDIALOG_H
