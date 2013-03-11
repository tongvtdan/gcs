#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    // window style
    enum GCS_MAINWINDOW_STYLE
        {
            GCS_MAINWINDOW_STYLE_NATIVE,
            GCS_MAINWINDOW_STYLE_INDOOR,
            GCS_MAINWINDOW_STYLE_OUTDOOR
        };
protected:
    QString styleFileName;
    GCS_MAINWINDOW_STYLE currentStyle;
public slots:
    /** @brief Load a specific style */
    void loadStyle(GCS_MAINWINDOW_STYLE style);
    /** @brief Reload the CSS style sheet */
    void reloadStylesheet();
    /** @brief Shows an info message as popup or as widget */
    void showInfoMessage(const QString& title, const QString& message);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
