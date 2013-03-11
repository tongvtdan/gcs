/********************************************************************************
** Form generated from reading UI file 'consolewidget.ui'
**
** Created: Fri Mar 8 14:54:08 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSOLEWIDGET_H
#define UI_CONSOLEWIDGET_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHeaderView>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_consolewidget
{
public:
    QPlainTextEdit *plainTextEdit;
    QLineEdit *lineEdit;
    QPushButton *consoleDistButton;

    void setupUi(QWidget *consolewidget)
    {
        if (consolewidget->objectName().isEmpty())
            consolewidget->setObjectName(QString::fromUtf8("consolewidget"));
        consolewidget->resize(720, 210);
        consolewidget->setMinimumSize(QSize(720, 210));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/files/images_icons/apps/guake.ico"), QSize(), QIcon::Normal, QIcon::Off);
        consolewidget->setWindowIcon(icon);
        plainTextEdit = new QPlainTextEdit(consolewidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 20, 701, 111));
        lineEdit = new QLineEdit(consolewidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 140, 701, 31));
        consoleDistButton = new QPushButton(consolewidget);
        consoleDistButton->setObjectName(QString::fromUtf8("consoleDistButton"));
        consoleDistButton->setGeometry(QRect(631, 180, 81, 23));

        retranslateUi(consolewidget);

        QMetaObject::connectSlotsByName(consolewidget);
    } // setupUi

    void retranslateUi(QWidget *consolewidget)
    {
        consolewidget->setWindowTitle(QApplication::translate("consolewidget", "Form", 0, QApplication::UnicodeUTF8));
        consoleDistButton->setText(QApplication::translate("consolewidget", "Disconnect", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class consolewidget: public Ui_consolewidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSOLEWIDGET_H
