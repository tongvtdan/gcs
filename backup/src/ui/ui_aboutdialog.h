/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created: Fri Mar 8 13:30:38 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDialog>
#include <QHeaderView>
#include <QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_aboutDialog
{
public:
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *aboutDialog)
    {
        if (aboutDialog->objectName().isEmpty())
            aboutDialog->setObjectName(QString::fromUtf8("aboutDialog"));
        aboutDialog->resize(400, 300);
        plainTextEdit = new QPlainTextEdit(aboutDialog);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 10, 381, 281));

        retranslateUi(aboutDialog);

        QMetaObject::connectSlotsByName(aboutDialog);
    } // setupUi

    void retranslateUi(QDialog *aboutDialog)
    {
        aboutDialog->setWindowTitle(QApplication::translate("aboutDialog", "About GSSControlStation", 0, QApplication::UnicodeUTF8));
        plainTextEdit->setPlainText(QApplication::translate("aboutDialog", "Nguy\341\273\205n Minh Ti\341\272\277n\n"
"C\303\264ng ty TNHH H\341\273\207 th\341\273\221ng C\306\241 \304\221i\341\273\207n t\341\273\255 Xanh", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class aboutDialog: public Ui_aboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
