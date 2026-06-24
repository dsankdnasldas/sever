#include "seetfacesever.h"
#include "register.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <opencv2/opencv.hpp>
#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cv::setUseOptimized(false);

    qRegisterMetaType<cv::Mat>("cv::Mat&");
    qRegisterMetaType<cv::Mat>("cv::Mat");
    qRegisterMetaType<int64_t>("int64_t");
    //连接数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据名称
    db.setDatabaseName("server.db");
    //打开数据库
    if(!db.open())
    {
        qDebug()<<db.lastError().text();
        return -1;
    }

    //注册表格
    QString createsql = "create table if not exists employee(employeeID integer primary key autoincrement,name varchar(256), sex varchar(32),"
                        "birthday text, address text, phone text, faceID integer unique, headfile text, BluetoothID integer unique)";
    QSqlQuery query;
    if(!query.exec(createsql))
    {
       qDebug()<<query.lastError().text();
       return -1;
    }

    //考勤表格
    createsql = "create table if not exists attendance(attendaceID integer primary key autoincrement, employeeID integer,"
                "attendaceTime TimeStamp NOT NULL DEFAULT(datetime('now','localtime')))";
    if(!query.exec(createsql))
    {
       qDebug()<<query.lastError().text();
       return -1;
    }
    seetfacesever w;
    w.show();
    //Register r;
    //r.show();
    return a.exec();
}