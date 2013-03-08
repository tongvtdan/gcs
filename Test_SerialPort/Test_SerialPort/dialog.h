#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class QextSerialPort;
class QTimer;

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

protected:
    void changeEvent(QEvent *e);
    
private slots:
    void on_baudrateBox_currentIndexChanged(int index);

    void on_databitsBox_currentIndexChanged(int index);

    void on_opencloseButton_clicked();

    void on_sendButton_clicked();

    void on_ReadyRead();

private:
    Ui::Dialog *ui;
    QextSerialPort *myport;
    QTimer *mytimer;

};

#endif // DIALOG_H
