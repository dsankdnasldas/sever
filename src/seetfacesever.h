#pragma once
#include "ui_seetfacesever.h"
#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include "qfaceobject.h"

class seetfacesever : public QMainWindow {
    Q_OBJECT
    
public:
    seetfacesever(QWidget* parent = nullptr);
    ~seetfacesever();

protected slots:
    void accept_client();
    void read_data();

private:
    Ui_seetfacesever* ui;
    QTcpServer mserver;
    QTcpSocket *msocket;
    quint64 bsize;
    QFaceObject faceobj;
};