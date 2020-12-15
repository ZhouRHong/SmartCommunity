#include "all_look.h"
#include "ui_all_look.h"
#include "mainwindow.h"
#include "allscreen.h"
ALL_look::ALL_look(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::ALL_look)
{
    ui->setupUi(this);
    basize = 0;
    re_connet();
}

ALL_look::~ALL_look()
{
    delete ui;
}

void ALL_look::re_connet()
{
    mSocket1 = new QUdpSocket();
    mSocket1->bind(QHostAddress(ui->ip1_lineEdit->text()), ui->port1_spinBox->value());
    connect(mSocket1, SIGNAL(readyRead()), this, SLOT(read_data1()));

    mSocket2 = new QUdpSocket();
    mSocket2->bind(QHostAddress(ui->ip1_lineEdit->text()), ui->port2_spinBox->value());
    connect(mSocket2, SIGNAL(readyRead()), this, SLOT(read_data2()));

    mSocket3 = new QUdpSocket();
    mSocket3->bind(QHostAddress(ui->ip1_lineEdit->text()), ui->port3_spinBox->value());
    connect(mSocket3, SIGNAL(readyRead()), this, SLOT(read_data3()));
}

void ALL_look::on_back_pushButton_clicked()
{
    mSocket2->disconnectFromHost();
    mSocket2->close();
    mSocket1->disconnectFromHost();
    mSocket1->close();
    mSocket3->disconnectFromHost();
    mSocket3->close();

    MainWindow* w = dynamic_cast<MainWindow*>(this->parent());
    w->show();
    delete this;
}

void ALL_look::read_data1()
{

    QByteArray message;
    QHostAddress address;
    quint16 port;
    message.resize(mSocket1->bytesAvailable());//根据可读数据来设置空间大小
    mSocket1->readDatagram(message.data(), message.size(), &address, &port); //读取数据
    ShowImage1(message);

//    QDataStream in(mSocket);
//    // QByteArray message;
//    in.setVersion(QDataStream::Qt_5_6);

//    if(basize == 0)
//    {
//        if(mSocket->bytesAvailable() < (int)sizeof(quint64))
//        {
//            return;
//        }
//        in >> basize;
//    }
//    if(mSocket->bytesAvailable() < basize)
//    {
//        return;
//    }
//    in >> message;
//    ShowImage(message);
}


void ALL_look::read_data2()
{
    QByteArray array;
    QHostAddress address;
    quint16 port;
    array.resize(mSocket2->bytesAvailable());//根据可读数据来设置空间大小
    mSocket2->readDatagram(array.data(), array.size(), &address, &port); //读取数据
    ShowImage2(array);
//    QDataStream in(mSocket1);
//    QByteArray message;
//    in.setVersion(QDataStream::Qt_5_6);

//    if(basize == 0)
//    {
//        if(mSocket1->bytesAvailable() < (int)sizeof(quint64))
//        {
//            return;
//        }
//        in >> basize;
//    }
//    if(mSocket1->bytesAvailable() < basize)
//    {
//        return;
//    }
//    in >> message;
    //    ShowImage1(message);
}

void ALL_look::read_data3()
{
    QByteArray array;
    QHostAddress address;
    quint16 port;
    array.resize(mSocket3->bytesAvailable());//根据可读数据来设置空间大小
    mSocket3->readDatagram(array.data(), array.size(), &address, &port); //读取数据
    ShowImage3(array);
}

void ALL_look::ShowImage1(QByteArray ba)
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
    pic.scaled(ui->look2_label->width(), ui->look2_label->height());
    ui->look1_label->setPixmap(pic);

    update();
}


void ALL_look::ShowImage2(QByteArray ba)
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
    pic.scaled(ui->look2_label->width(), ui->look2_label->height());
    ui->look2_label->setPixmap(pic);

    update();
}

void ALL_look::ShowImage3(QByteArray ba)
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
    pic.scaled(ui->look2_label->width(), ui->look2_label->height());
    ui->look3_label->setPixmap(pic);

    update();
}

void ALL_look::on_look1_pushButton_clicked()
{
    mSocket1->disconnectFromHost();
    mSocket1->close();
    mSocket2->disconnectFromHost();
    mSocket2->close();
    mSocket3->disconnectFromHost();
    mSocket3->close();

    Allscreen* allscreen = new Allscreen(this);
    allscreen->show();
    connect(this, &ALL_look::sendinfo, allscreen, &Allscreen::recvinfo);
    emit sendinfo(QHostAddress(ui->ip1_lineEdit->text()), ui->port1_spinBox->value());
    this->hide();
}


void ALL_look::on_look2_pushButton_clicked()
{
    mSocket1->disconnectFromHost();
    mSocket1->close();
    mSocket2->disconnectFromHost();
    mSocket2->close();
    mSocket3->disconnectFromHost();
    mSocket3->close();

    Allscreen* allscreen = new Allscreen(this);
    allscreen->show();
    connect(this, &ALL_look::sendinfo, allscreen, &Allscreen::recvinfo);
    emit sendinfo(QHostAddress(ui->ip1_lineEdit->text()), ui->port2_spinBox->value());
    this->hide();
}

void ALL_look::on_look3_pushButton_clicked()
{
    mSocket1->disconnectFromHost();
    mSocket1->close();
    mSocket2->disconnectFromHost();
    mSocket2->close();
    mSocket3->disconnectFromHost();
    mSocket3->close();

    Allscreen* allscreen = new Allscreen(this);
    allscreen->show();
    connect(this, &ALL_look::sendinfo, allscreen, &Allscreen::recvinfo);
    emit sendinfo(QHostAddress(ui->ip1_lineEdit->text()), ui->port3_spinBox->value());
    this->hide();
}


void ALL_look::on_fix1_pushButton_clicked()
{
    mSocket1->disconnectFromHost();
    mSocket1->close();
    mSocket1 = new QUdpSocket();
    //绑定R
    mSocket1->bind(QHostAddress(ui->ip1_lineEdit->text()), ui->port1_spinBox->value());

    connect(mSocket1, SIGNAL(readyRead()), this, SLOT(read_data1()));
}

void ALL_look::on_fix2_pushButton_clicked()
{
    mSocket2->disconnectFromHost();
    mSocket2->close();
    mSocket2 = new QUdpSocket();
    //绑定R
    mSocket2->bind(QHostAddress(ui->ip1_lineEdit->text()), ui->port2_spinBox->value());

    connect(mSocket2, SIGNAL(readyRead()), this, SLOT(read_data2()));
}

void ALL_look::on_fix3_pushButton_clicked()
{
    mSocket3->disconnectFromHost();
    mSocket3->close();
    mSocket3 = new QUdpSocket();
    //绑定R
    mSocket3->bind(QHostAddress(ui->ip1_lineEdit->text()), ui->port3_spinBox->value());

    connect(mSocket3, SIGNAL(readyRead()), this, SLOT(read_data3()));
}

