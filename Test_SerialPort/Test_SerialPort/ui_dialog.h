/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Wed Mar 6 15:46:39 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *opencloseButton;
    QPlainTextEdit *receiTextEdit;
    QPlainTextEdit *sendTextEdit;
    QPushButton *sendButton;
    QLabel *statuslabel;
    QComboBox *comboBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *comportlabel;
    QComboBox *comportBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *baudratelabel;
    QComboBox *baudrateBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *databitslabel;
    QComboBox *databitsBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *paritylabel;
    QComboBox *parityBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *stopbitslabel;
    QComboBox *stopbitsBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *timeoutlabel;
    QSpinBox *timeoutspinBox;
    QHBoxLayout *horizontalLayout_7;
    QLabel *querymodelabel;
    QComboBox *querymodeBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(521, 414);
        opencloseButton = new QPushButton(Dialog);
        opencloseButton->setObjectName(QString::fromUtf8("opencloseButton"));
        opencloseButton->setGeometry(QRect(10, 220, 81, 23));
        receiTextEdit = new QPlainTextEdit(Dialog);
        receiTextEdit->setObjectName(QString::fromUtf8("receiTextEdit"));
        receiTextEdit->setGeometry(QRect(160, 10, 351, 291));
        sendTextEdit = new QPlainTextEdit(Dialog);
        sendTextEdit->setObjectName(QString::fromUtf8("sendTextEdit"));
        sendTextEdit->setGeometry(QRect(10, 320, 411, 81));
        sendButton = new QPushButton(Dialog);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(430, 350, 71, 23));
        statuslabel = new QLabel(Dialog);
        statuslabel->setObjectName(QString::fromUtf8("statuslabel"));
        statuslabel->setGeometry(QRect(10, 250, 121, 20));
        comboBox = new QComboBox(Dialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 280, 69, 22));
        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 141, 192));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comportlabel = new QLabel(widget);
        comportlabel->setObjectName(QString::fromUtf8("comportlabel"));

        horizontalLayout->addWidget(comportlabel);

        comportBox = new QComboBox(widget);
        comportBox->setObjectName(QString::fromUtf8("comportBox"));

        horizontalLayout->addWidget(comportBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        baudratelabel = new QLabel(widget);
        baudratelabel->setObjectName(QString::fromUtf8("baudratelabel"));

        horizontalLayout_2->addWidget(baudratelabel);

        baudrateBox = new QComboBox(widget);
        baudrateBox->setObjectName(QString::fromUtf8("baudrateBox"));

        horizontalLayout_2->addWidget(baudrateBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        databitslabel = new QLabel(widget);
        databitslabel->setObjectName(QString::fromUtf8("databitslabel"));

        horizontalLayout_3->addWidget(databitslabel);

        databitsBox = new QComboBox(widget);
        databitsBox->setObjectName(QString::fromUtf8("databitsBox"));

        horizontalLayout_3->addWidget(databitsBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        paritylabel = new QLabel(widget);
        paritylabel->setObjectName(QString::fromUtf8("paritylabel"));

        horizontalLayout_4->addWidget(paritylabel);

        parityBox = new QComboBox(widget);
        parityBox->setObjectName(QString::fromUtf8("parityBox"));

        horizontalLayout_4->addWidget(parityBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        stopbitslabel = new QLabel(widget);
        stopbitslabel->setObjectName(QString::fromUtf8("stopbitslabel"));

        horizontalLayout_5->addWidget(stopbitslabel);

        stopbitsBox = new QComboBox(widget);
        stopbitsBox->setObjectName(QString::fromUtf8("stopbitsBox"));

        horizontalLayout_5->addWidget(stopbitsBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        timeoutlabel = new QLabel(widget);
        timeoutlabel->setObjectName(QString::fromUtf8("timeoutlabel"));

        horizontalLayout_6->addWidget(timeoutlabel);

        timeoutspinBox = new QSpinBox(widget);
        timeoutspinBox->setObjectName(QString::fromUtf8("timeoutspinBox"));

        horizontalLayout_6->addWidget(timeoutspinBox);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        querymodelabel = new QLabel(widget);
        querymodelabel->setObjectName(QString::fromUtf8("querymodelabel"));

        horizontalLayout_7->addWidget(querymodelabel);

        querymodeBox = new QComboBox(widget);
        querymodeBox->setObjectName(QString::fromUtf8("querymodeBox"));

        horizontalLayout_7->addWidget(querymodeBox);


        verticalLayout->addLayout(horizontalLayout_7);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        opencloseButton->setText(QApplication::translate("Dialog", "Open/ Close", 0, QApplication::UnicodeUTF8));
        sendTextEdit->setPlainText(QString());
        sendButton->setText(QApplication::translate("Dialog", "Send", 0, QApplication::UnicodeUTF8));
        statuslabel->setText(QString());
        comportlabel->setText(QApplication::translate("Dialog", "COM Port", 0, QApplication::UnicodeUTF8));
        baudratelabel->setText(QApplication::translate("Dialog", "BaudRate", 0, QApplication::UnicodeUTF8));
        databitslabel->setText(QApplication::translate("Dialog", "DataBits", 0, QApplication::UnicodeUTF8));
        paritylabel->setText(QApplication::translate("Dialog", "Parity", 0, QApplication::UnicodeUTF8));
        stopbitslabel->setText(QApplication::translate("Dialog", "StopBits", 0, QApplication::UnicodeUTF8));
        timeoutlabel->setText(QApplication::translate("Dialog", "Time Out", 0, QApplication::UnicodeUTF8));
        querymodelabel->setText(QApplication::translate("Dialog", "QueryMode", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
