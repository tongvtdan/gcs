/********************************************************************************
** Form generated from reading UI file 'consolewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSOLEWIDGET_H
#define UI_CONSOLEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

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
            consolewidget->setObjectName(QStringLiteral("consolewidget"));
        consolewidget->resize(720, 210);
        consolewidget->setMinimumSize(QSize(720, 210));
        QIcon icon;
        icon.addFile(QStringLiteral(":/files/images_icons/apps/guake.ico"), QSize(), QIcon::Normal, QIcon::Off);
        consolewidget->setWindowIcon(icon);
        plainTextEdit = new QPlainTextEdit(consolewidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 20, 701, 111));
        lineEdit = new QLineEdit(consolewidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 140, 701, 31));
        consoleDistButton = new QPushButton(consolewidget);
        consoleDistButton->setObjectName(QStringLiteral("consoleDistButton"));
        consoleDistButton->setGeometry(QRect(631, 180, 81, 23));

        retranslateUi(consolewidget);

        QMetaObject::connectSlotsByName(consolewidget);
    } // setupUi

    void retranslateUi(QWidget *consolewidget)
    {
        consolewidget->setWindowTitle(QApplication::translate("consolewidget", "Form", 0));
        consoleDistButton->setText(QApplication::translate("consolewidget", "Disconnect", 0));
    } // retranslateUi

};

namespace Ui {
    class consolewidget: public Ui_consolewidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSOLEWIDGET_H
