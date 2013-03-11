/********************************************************************************
** Form generated from reading UI file 'connectdialog.ui'
**
** Created: Sat Mar 9 15:42:16 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTDIALOG_H
#define UI_CONNECTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_connectDialog
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *comportlabel;
    QComboBox *comportBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *baudratelabel;
    QComboBox *baudrateBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *paritylabel;
    QComboBox *parityBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *databitslabel;
    QComboBox *databitsBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *stopbitslabel;
    QComboBox *stopbitsBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *querymodelabel;
    QComboBox *querymodeBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *ComOKBtn;
    QPushButton *cancelButton;

    void setupUi(QDialog *connectDialog)
    {
        if (connectDialog->objectName().isEmpty())
            connectDialog->setObjectName(QString::fromUtf8("connectDialog"));
        connectDialog->resize(240, 300);
        connectDialog->setMinimumSize(QSize(240, 300));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/files/images_icons/apps/connect.ico"), QSize(), QIcon::Normal, QIcon::Off);
        connectDialog->setWindowIcon(icon);
        groupBox = new QGroupBox(connectDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(5, 5, 230, 250));
        groupBox->setMinimumSize(QSize(230, 250));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comportlabel = new QLabel(groupBox);
        comportlabel->setObjectName(QString::fromUtf8("comportlabel"));

        horizontalLayout->addWidget(comportlabel);

        comportBox = new QComboBox(groupBox);
        comportBox->setObjectName(QString::fromUtf8("comportBox"));
        comportBox->setMinimumSize(QSize(136, 22));

        horizontalLayout->addWidget(comportBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        baudratelabel = new QLabel(groupBox);
        baudratelabel->setObjectName(QString::fromUtf8("baudratelabel"));

        horizontalLayout_2->addWidget(baudratelabel);

        baudrateBox = new QComboBox(groupBox);
        baudrateBox->setObjectName(QString::fromUtf8("baudrateBox"));
        baudrateBox->setMinimumSize(QSize(136, 22));

        horizontalLayout_2->addWidget(baudrateBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        paritylabel = new QLabel(groupBox);
        paritylabel->setObjectName(QString::fromUtf8("paritylabel"));

        horizontalLayout_3->addWidget(paritylabel);

        parityBox = new QComboBox(groupBox);
        parityBox->setObjectName(QString::fromUtf8("parityBox"));
        parityBox->setMinimumSize(QSize(136, 22));

        horizontalLayout_3->addWidget(parityBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        databitslabel = new QLabel(groupBox);
        databitslabel->setObjectName(QString::fromUtf8("databitslabel"));

        horizontalLayout_4->addWidget(databitslabel);

        databitsBox = new QComboBox(groupBox);
        databitsBox->setObjectName(QString::fromUtf8("databitsBox"));
        databitsBox->setMinimumSize(QSize(136, 22));

        horizontalLayout_4->addWidget(databitsBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        stopbitslabel = new QLabel(groupBox);
        stopbitslabel->setObjectName(QString::fromUtf8("stopbitslabel"));

        horizontalLayout_5->addWidget(stopbitslabel);

        stopbitsBox = new QComboBox(groupBox);
        stopbitsBox->setObjectName(QString::fromUtf8("stopbitsBox"));
        stopbitsBox->setMinimumSize(QSize(136, 22));

        horizontalLayout_5->addWidget(stopbitsBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        querymodelabel = new QLabel(groupBox);
        querymodelabel->setObjectName(QString::fromUtf8("querymodelabel"));

        horizontalLayout_6->addWidget(querymodelabel);

        querymodeBox = new QComboBox(groupBox);
        querymodeBox->setObjectName(QString::fromUtf8("querymodeBox"));
        querymodeBox->setMinimumSize(QSize(136, 22));

        horizontalLayout_6->addWidget(querymodeBox);


        verticalLayout->addLayout(horizontalLayout_6);

        layoutWidget = new QWidget(connectDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 263, 230, 27));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        ComOKBtn = new QPushButton(layoutWidget);
        ComOKBtn->setObjectName(QString::fromUtf8("ComOKBtn"));

        horizontalLayout_7->addWidget(ComOKBtn);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_7->addWidget(cancelButton);


        horizontalLayout_8->addLayout(horizontalLayout_7);


        retranslateUi(connectDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), connectDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(connectDialog);
    } // setupUi

    void retranslateUi(QDialog *connectDialog)
    {
        connectDialog->setWindowTitle(QApplication::translate("connectDialog", "Connection", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("connectDialog", "Settings", 0, QApplication::UnicodeUTF8));
        comportlabel->setText(QApplication::translate("connectDialog", "COMPort", 0, QApplication::UnicodeUTF8));
        baudratelabel->setText(QApplication::translate("connectDialog", "Baudrate", 0, QApplication::UnicodeUTF8));
        paritylabel->setText(QApplication::translate("connectDialog", "Parity", 0, QApplication::UnicodeUTF8));
        databitslabel->setText(QApplication::translate("connectDialog", "DataBits", 0, QApplication::UnicodeUTF8));
        stopbitslabel->setText(QApplication::translate("connectDialog", "StopBits", 0, QApplication::UnicodeUTF8));
        querymodelabel->setText(QApplication::translate("connectDialog", "QueryMode", 0, QApplication::UnicodeUTF8));
        ComOKBtn->setText(QApplication::translate("connectDialog", "OK", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("connectDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class connectDialog: public Ui_connectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTDIALOG_H
