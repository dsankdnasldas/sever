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
    birthdayDisplay();
}

Register::~Register()
{
    delete ui;
}

void Register::on_resetBt_clicked()
{
    ui->nameEdit->clear();
    ui->addressEdit->clear();
    ui->phoneEdit->clear();
    ui->picFileEdit->clear();
    ui->headpicLb->clear();
    initbirthdayComboBoxes();
}

void Register::timerEvent(QTimerEvent *e)
{

    //获取摄像头数据并且显示在界面上
    if(cap.isOpened())
    {
        cap>>image;
        if(image.data == nullptr) return;
    }
    //Mat---》QImage
    cv::Mat rgbImage;
    cv::cvtColor(image,rgbImage,cv::COLOR_BGR2RGB);
    QImage qImg(rgbImage.data, rgbImage.cols, rgbImage.rows,rgbImage.step1(), QImage::Format_RGB888);
    //在qt界面上显示
    QPixmap mmp=QPixmap::fromImage(qImg);
    mmp = mmp.scaledToWidth(ui->headpicLb->width());
    ui->headpicLb->setPixmap(mmp);
}

void Register::on_addpicBt_clicked()
{
    const QString filepath = QFileDialog::getOpenFileName(this, "选择图片", "./data", "Images (*.png *.jpg)");
    if (filepath.isEmpty()) {
        return;
    }

    ui->picFileEdit->setText(filepath);

    QPixmap pixmap(filepath);
    pixmap = pixmap.scaledToWidth(ui->headpicLb->width());
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
    // build birthday string from year/month/day comboboxes
    const QString birthday = QString("%1/%2/%3").arg(ui->yearCb->currentText()).arg(ui->monthCb->currentText()).arg(ui->dayCb->currentText());
    record.setValue("birthday", birthday);
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

void Register::on_videoswitchBt_clicked()
{
    if(ui->videoswitchBt->text() == "打开摄像头")
    {
        //打开摄像头
        if(cap.open(0))
        {
            ui->videoswitchBt->setText("关闭摄像头");
            //启动定时器事件
            timerid = startTimer(100);
        }
    }else
    {

        killTimer(timerid);//关闭定时器事件
        ui->videoswitchBt->setText("打开摄像头");
        //关闭摄像头
        cap.release();
        ui->headpicLb->clear();
    }
}

void Register::on_cameraBt_clicked()
{
    //保存数据
    //把头像保存到一个固定路径下
    QString headfile = QString("./data/1.jpg").arg(QString(ui->nameEdit->text().toUtf8().toBase64()));
    ui->picFileEdit->setText(headfile);
    cv::imwrite(headfile.toUtf8().data(), image);
    killTimer(timerid);//关闭定时器事件
    ui->videoswitchBt->setText("打开摄像头");
    //关闭摄像头
    cap.release();
}

void Register::on_bluetoothBt_clicked()
{
    qDebug() << "Bluetooth binding clicked";
}


//tools
void Register::birthdayDisplay()
{
    // populate year (1990-2016)
    for (int y = 1990; y <= 2016; ++y) {
        ui->yearCb->addItem(QString::number(y));
    }
    // populate months 1-12
    for (int m = 1; m <= 12; ++m) {
        ui->monthCb->addItem(QString::number(m));
    }
    // helper to refresh days based on current year/month
    auto refreshDays = [this]() {
        int year = ui->yearCb->currentText().toInt();
        int month = ui->monthCb->currentText().toInt();
        if (month < 1 || month > 12) month = 1;
        const int days = QDate(year, month, 1).daysInMonth();
        const QString curDay = ui->dayCb->currentText();
        ui->dayCb->clear();
        for (int d = 1; d <= days; ++d) ui->dayCb->addItem(QString::number(d));
        // try to restore previous day if possible
        int idx = ui->dayCb->findText(curDay);
        if (idx >= 0) ui->dayCb->setCurrentIndex(idx);
    };
    // connect changes
    connect(ui->yearCb, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [refreshDays](int){ refreshDays(); });
    connect(ui->monthCb, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [refreshDays](int){ refreshDays(); });
    // set default to 2000/1/1
    const QString defYear = QString::number(2000);
    int yi = ui->yearCb->findText(defYear);
    if (yi >= 0) ui->yearCb->setCurrentIndex(yi);
    int mi = ui->monthCb->findText("1");
    if (mi >= 0) ui->monthCb->setCurrentIndex(mi);
    refreshDays();
    int di = ui->dayCb->findText("1");
    if (di >= 0) ui->dayCb->setCurrentIndex(di);
}

void Register::initbirthdayComboBoxes()
{
    // This function is now integrated into birthdayDisplay() and is no longer needed separately.
    // reset comboboxes to default 2000/1/1
    int yi = ui->yearCb->findText(QString::number(2000));
    if (yi >= 0) ui->yearCb->setCurrentIndex(yi);
    int mi = ui->monthCb->findText("1");
    if (mi >= 0) ui->monthCb->setCurrentIndex(mi);
    // refresh days and set day to 1
    int di = ui->dayCb->findText("1");
    if (di >= 0) ui->dayCb->setCurrentIndex(di);
}