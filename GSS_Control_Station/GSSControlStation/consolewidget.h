#ifndef CONSOLEWIDGET_H
#define CONSOLEWIDGET_H

#include <QWidget>

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
};

#endif // CONSOLEWIDGET_H
