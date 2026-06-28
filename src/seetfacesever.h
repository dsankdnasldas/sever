#pragma once
#include "ui_seetfacesever.h"
#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include "qfaceobject.h"
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDateTime>
#include <QThread>
#include <QSqlQuery>
#include <QSqlError>

class seetfacesever : public QMainWindow {
    Q_OBJECT
    
public:
    seetfacesever(QWidget* parent = nullptr);
    ~seetfacesever();

signals:
    void query(cv::Mat& image);

protected slots:
    void accept_client();
    void read_data();
    void recv_faceid(int64_t faceid);
private:
    Ui_seetfacesever* ui;
    QTcpServer mserver;
    QTcpSocket *msocket;
    quint64 bsize;
    QFaceObject faceobj;
    QSqlTableModel model;
    QFaceObject fobj;
};