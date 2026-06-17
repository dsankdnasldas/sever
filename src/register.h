#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include "ui_register.h"

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_resetBt_clicked();

    void on_addpicBt_clicked();

    void on_registerBt_clicked();

    void on_bluetoothBt_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
