#include "seetfacesever.h"
#include "ui_seetfacesever.h"

seetfacesever::seetfacesever(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_seetfacesever)
{
    ui->setupUi(this);

    connect(&mserver, &QTcpServer::newConnection, this, &seetfacesever::accept_client);
    mserver.listen(QHostAddress::Any,9999);
    bsize = 0;
}

seetfacesever::~seetfacesever()
{
    delete ui; 
}

//接受客户端连接
void seetfacesever::accept_client()
{
    //获取与客户端通信的套接字
    msocket = mserver.nextPendingConnection();

    //当客户端有数据到达会发送readyRead信号
    connect(msocket,&QTcpSocket::readyRead,this,&seetfacesever::read_data);
}

//读取客户端发送的数据
void seetfacesever::read_data()
{
    QDataStream stream(msocket); //把套接字绑定到数据流
    stream.setVersion(QDataStream::Qt_6_1);
    if(bsize == 0){
        if(msocket->bytesAvailable()<(qint64)sizeof(bsize)) 
            return;
        //采集数据的长度
        stream>>bsize;
    }
    if(msocket->bytesAvailable() < bsize)
    {
        return;
    }
    QByteArray data;
    stream>>data;
    bsize = 0;
    if(data.size() == 0)//没有读取到数据
    {
        return;
    }
    //显示图片
    QPixmap mmp;
    mmp.loadFromData(data,"jpg");
    mmp = mmp.scaled(ui->picLb->size());
    ui->picLb->setPixmap(mmp);
}