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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_seetfacesever
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *seetfacesever)
    {
        if (seetfacesever->objectName().isEmpty())
            seetfacesever->setObjectName("seetfacesever");
        seetfacesever->resize(800, 600);
        centralwidget = new QWidget(seetfacesever);
        centralwidget->setObjectName("centralwidget");
        seetfacesever->setCentralWidget(centralwidget);
        menubar = new QMenuBar(seetfacesever);
        menubar->setObjectName("menubar");
        seetfacesever->setMenuBar(menubar);
        statusbar = new QStatusBar(seetfacesever);
        statusbar->setObjectName("statusbar");
        seetfacesever->setStatusBar(statusbar);

        retranslateUi(seetfacesever);

        QMetaObject::connectSlotsByName(seetfacesever);
    } // setupUi

    void retranslateUi(QMainWindow *seetfacesever)
    {
        seetfacesever->setWindowTitle(QCoreApplication::translate("seetfacesever", "seetfacesever", nullptr));
    } // retranslateUi

};

namespace Ui {
    class seetfacesever: public Ui_seetfacesever {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEETFACESEVER_H
