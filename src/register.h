#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include "ui_register.h"
#include <opencv2/opencv.hpp>

namespace Ui {
class Register;

}
class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
    void timerEvent(QTimerEvent *e);

private slots:
    void on_resetBt_clicked();

    void on_addpicBt_clicked();

    void on_registerBt_clicked();

    void on_videoswitchBt_clicked();

    void on_cameraBt_clicked();

    void on_bluetoothBt_clicked();

private:
    Ui::Register *ui;
    int timerid;
    cv::VideoCapture cap;
    cv::Mat image;
    void birthdayDisplay();
    void initbirthdayComboBoxes();
};

#endif // REGISTER_H
