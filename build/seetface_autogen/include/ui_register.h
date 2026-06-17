/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QRadioButton *mrb;
    QRadioButton *wrb;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QDateEdit *birthdayEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *addressEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *phoneEdit;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *registerBt;
    QPushButton *resetBt;
    QVBoxLayout *verticalLayout_2;
    QLabel *headpicLb;
    QLineEdit *picFileEdit;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *addpicBt;
    QPushButton *videoswitchBt;
    QPushButton *cameraBt;
    QPushButton *bluetoothBt;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName("Register");
        Register->resize(648, 427);
        horizontalLayout_8 = new QHBoxLayout(Register);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(Register);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(15);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        nameEdit = new QLineEdit(Register);
        nameEdit->setObjectName("nameEdit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy);
        nameEdit->setFont(font);

        horizontalLayout->addWidget(nameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(Register);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        mrb = new QRadioButton(Register);
        mrb->setObjectName("mrb");
        mrb->setFont(font);

        horizontalLayout_4->addWidget(mrb);

        wrb = new QRadioButton(Register);
        wrb->setObjectName("wrb");
        wrb->setFont(font);

        horizontalLayout_4->addWidget(wrb);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_6 = new QLabel(Register);
        label_6->setObjectName("label_6");
        label_6->setFont(font);

        horizontalLayout_5->addWidget(label_6);

        birthdayEdit = new QDateEdit(Register);
        birthdayEdit->setObjectName("birthdayEdit");
        sizePolicy.setHeightForWidth(birthdayEdit->sizePolicy().hasHeightForWidth());
        birthdayEdit->setSizePolicy(sizePolicy);
        birthdayEdit->setFont(font);

        horizontalLayout_5->addWidget(birthdayEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(Register);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        addressEdit = new QLineEdit(Register);
        addressEdit->setObjectName("addressEdit");
        sizePolicy.setHeightForWidth(addressEdit->sizePolicy().hasHeightForWidth());
        addressEdit->setSizePolicy(sizePolicy);
        addressEdit->setFont(font);

        horizontalLayout_2->addWidget(addressEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(Register);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        phoneEdit = new QLineEdit(Register);
        phoneEdit->setObjectName("phoneEdit");
        sizePolicy.setHeightForWidth(phoneEdit->sizePolicy().hasHeightForWidth());
        phoneEdit->setSizePolicy(sizePolicy);
        phoneEdit->setFont(font);

        horizontalLayout_3->addWidget(phoneEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        registerBt = new QPushButton(Register);
        registerBt->setObjectName("registerBt");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(registerBt->sizePolicy().hasHeightForWidth());
        registerBt->setSizePolicy(sizePolicy1);
        registerBt->setFont(font);

        horizontalLayout_6->addWidget(registerBt);

        resetBt = new QPushButton(Register);
        resetBt->setObjectName("resetBt");
        sizePolicy1.setHeightForWidth(resetBt->sizePolicy().hasHeightForWidth());
        resetBt->setSizePolicy(sizePolicy1);
        resetBt->setFont(font);

        horizontalLayout_6->addWidget(resetBt);


        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_8->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        headpicLb = new QLabel(Register);
        headpicLb->setObjectName("headpicLb");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(headpicLb->sizePolicy().hasHeightForWidth());
        headpicLb->setSizePolicy(sizePolicy2);
        headpicLb->setStyleSheet(QString::fromUtf8("background-color: rgb(25, 118, 211);"));

        verticalLayout_2->addWidget(headpicLb);

        picFileEdit = new QLineEdit(Register);
        picFileEdit->setObjectName("picFileEdit");

        verticalLayout_2->addWidget(picFileEdit);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        addpicBt = new QPushButton(Register);
        addpicBt->setObjectName("addpicBt");
        sizePolicy1.setHeightForWidth(addpicBt->sizePolicy().hasHeightForWidth());
        addpicBt->setSizePolicy(sizePolicy1);
        addpicBt->setFont(font);

        horizontalLayout_7->addWidget(addpicBt);

        videoswitchBt = new QPushButton(Register);
        videoswitchBt->setObjectName("videoswitchBt");
        sizePolicy1.setHeightForWidth(videoswitchBt->sizePolicy().hasHeightForWidth());
        videoswitchBt->setSizePolicy(sizePolicy1);
        videoswitchBt->setFont(font);

        horizontalLayout_7->addWidget(videoswitchBt);

        cameraBt = new QPushButton(Register);
        cameraBt->setObjectName("cameraBt");
        sizePolicy1.setHeightForWidth(cameraBt->sizePolicy().hasHeightForWidth());
        cameraBt->setSizePolicy(sizePolicy1);
        cameraBt->setFont(font);

        horizontalLayout_7->addWidget(cameraBt);


        verticalLayout_2->addLayout(horizontalLayout_7);

        bluetoothBt = new QPushButton(Register);
        bluetoothBt->setObjectName("bluetoothBt");
        sizePolicy1.setHeightForWidth(bluetoothBt->sizePolicy().hasHeightForWidth());
        bluetoothBt->setSizePolicy(sizePolicy1);
        bluetoothBt->setFont(font);

        verticalLayout_2->addWidget(bluetoothBt);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);

        horizontalLayout_8->addLayout(verticalLayout_2);


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Form", nullptr));
        label->setText(QCoreApplication::translate("Register", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("Register", "\346\200\247\345\210\253\357\274\232", nullptr));
        mrb->setText(QCoreApplication::translate("Register", "\347\224\267", nullptr));
        wrb->setText(QCoreApplication::translate("Register", "\345\245\263", nullptr));
        label_6->setText(QCoreApplication::translate("Register", "\347\224\237\346\227\245\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Register", "\345\234\260\345\235\200\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Register", "\347\224\265\350\257\235\357\274\232", nullptr));
        registerBt->setText(QCoreApplication::translate("Register", "\346\263\250\345\206\214", nullptr));
        resetBt->setText(QCoreApplication::translate("Register", "\351\207\215\347\275\256", nullptr));
        headpicLb->setText(QString());
        addpicBt->setText(QCoreApplication::translate("Register", "\346\267\273\345\212\240\345\244\264\345\203\217", nullptr));
        videoswitchBt->setText(QCoreApplication::translate("Register", "\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264", nullptr));
        cameraBt->setText(QCoreApplication::translate("Register", "\346\213\215\347\205\247", nullptr));
        bluetoothBt->setText(QCoreApplication::translate("Register", "\350\223\235\347\211\231\347\273\221\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
