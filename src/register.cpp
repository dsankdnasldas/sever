#include "register.h"
#include "qfaceobject.h"

#include <QDate>
#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QSqlRecord>
#include <QSqlTableModel>

Register::Register(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_resetBt_clicked()
{
    ui->nameEdit->clear();
    ui->birthdayEdit->setDate(QDate::currentDate());
    ui->addressEdit->clear();
    ui->phoneEdit->clear();
    ui->picFileEdit->clear();
    ui->headpicLb->clear();
}

void Register::on_addpicBt_clicked()
{
    const QString filepath = QFileDialog::getOpenFileName(this);
    if (filepath.isEmpty()) {
        return;
    }

    ui->picFileEdit->setText(filepath);

    QPixmap pixmap(filepath);
    pixmap = pixmap.scaledToWidth(ui->headpicLb->width());
    ui->headpicLb->setPixmap(pixmap);
}

void Register::on_registerBt_clicked()
{
    QFaceObject faceobj;
    cv::Mat image = cv::imread(ui->picFileEdit->text().toUtf8().data());
    if (image.empty()) {
        QMessageBox::warning(this, "注册提示", "头像图片读取失败");
        return;
    }

    const int faceID = faceobj.face_register(image);
    qDebug() << faceID;

    QDir().mkpath("./data");
    const QString headfile = QString("./data/%1.jpg").arg(QString(ui->nameEdit->text().toUtf8().toBase64()));
    cv::imwrite(headfile.toUtf8().data(), image);

    QSqlTableModel model;
    model.setTable("employee");

    QSqlRecord record = model.record();
    record.setValue("name", ui->nameEdit->text());
    record.setValue("sex", ui->mrb->isChecked() ? "男" : "女");
    record.setValue("birthday", ui->birthdayEdit->text());
    record.setValue("address", ui->addressEdit->text());
    record.setValue("phone", ui->phoneEdit->text());
    record.setValue("faceID", faceID);
    record.setValue("headfile", headfile);

    const bool inserted = model.insertRecord(0, record);
    if (inserted && model.submitAll()) {
        QMessageBox::information(this, "注册提示", "注册成功");
    } else {
        QMessageBox::information(this, "注册提示", "注册失败");
    }
}

void Register::on_bluetoothBt_clicked()
{
    qDebug() << "Bluetooth binding clicked";
}
