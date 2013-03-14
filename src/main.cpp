#include "src/ui/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    /// to show window maximum
//    w.setWindowState(w.windowState() | Qt::WindowMaximized);
//    w.showMaximized();
    w.show();

    return a.exec();
}
