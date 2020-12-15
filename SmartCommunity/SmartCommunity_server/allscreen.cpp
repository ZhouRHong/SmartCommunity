#include "allscreen.h"
#include "ui_allscreen.h"
#include "all_look.h"
Allscreen::Allscreen(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::Allscreen)
{
    ui->setupUi(this);
//    mSocket->bind(QHostAddress(QString("192.168.20.169")), 6666);

//    connect(mSocket, SIGNAL(readyRead()), this, SLOT(read_data()));
}

Allscreen::~Allscreen()
{
    delete ui;
}

void Allscreen::on_backe_pushButton_clicked()
{
    mSocket->disconnectFromHost();
    mSocket->close();

    ALL_look* all_look = dynamic_cast<ALL_look*>(this->parent());
    all_look->re_connet();
    all_look->show();
    delete this;
}

void Allscreen::recvinfo(QHostAddress ip, quint16 port)
{
    mSocket = new QUdpSocket;
    mSocket->bind(ip, port);
    qDebug() << ip << port;
    connect(mSocket, SIGNAL(readyRead()), this, SLOT(read_data()));
}


void Allscreen::read_data()
{
    QByteArray array;
    QHostAddress address;
    quint16 port;
    array.resize(mSocket->bytesAvailable());//根据可读数据来设置空间大小
    mSocket->readDatagram(array.data(), array.size(), &address, &port); //读取数据
    ShowImage(array);
}

void Allscreen::ShowImage(QByteArray ba)
{
    QString ss = QString::fromLatin1(ba.data(), ba.size());
    QByteArray rc;
    rc = QByteArray::fromBase64(ss.toLatin1());
    QByteArray rdc = qUncompress(rc);
    if(rdc.isEmpty())
    {
        return;
    }
    QImage img;
    img.loadFromData(rdc);
    QPixmap pic = QPixmap::fromImage(img);
    pic.scaled(ui->label->width(), ui->label->height());
    ui->label->setPixmap(pic);
    update();
}
