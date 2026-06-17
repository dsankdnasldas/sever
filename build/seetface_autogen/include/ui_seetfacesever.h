/********************************************************************************
** Form generated from reading UI file 'seetfacesever.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEETFACESEVER_H
#define UI_SEETFACESEVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_seetfacesever
{
public:
    QWidget *centralwidget;
    QLabel *picLb;

    void setupUi(QMainWindow *seetfacesever)
    {
        if (seetfacesever->objectName().isEmpty())
            seetfacesever->setObjectName("seetfacesever");
        seetfacesever->resize(649, 428);
        centralwidget = new QWidget(seetfacesever);
        centralwidget->setObjectName("centralwidget");
        picLb = new QLabel(centralwidget);
        picLb->setObjectName("picLb");
        picLb->setGeometry(QRect(10, 10, 411, 401));
        picLb->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 255);"));
        seetfacesever->setCentralWidget(centralwidget);

        retranslateUi(seetfacesever);

        QMetaObject::connectSlotsByName(seetfacesever);
    } // setupUi

    void retranslateUi(QMainWindow *seetfacesever)
    {
        seetfacesever->setWindowTitle(QCoreApplication::translate("seetfacesever", "seetfacesever", nullptr));
        picLb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class seetfacesever: public Ui_seetfacesever {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEETFACESEVER_H
