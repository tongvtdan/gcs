#ifndef CONSOLEWIDGET_H
#define CONSOLEWIDGET_H

#include <QWidget>
//#include "mainwindow.h"

namespace Ui {
class consolewidget;
}

class consolewidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit consolewidget(QWidget *parent = 0);
    ~consolewidget();
    
private:
    Ui::consolewidget *ui;
    void on_ReadyRead();
};

#endif // CONSOLEWIDGET_H
