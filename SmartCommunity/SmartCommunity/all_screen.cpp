#include "all_screen.h"
#include "ui_all_screen.h"
#include <string.h>
#include <QMessageBox>
#include "menu.h"
#include <QtDebug>
All_screen::All_screen(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::All_screen)
{
    ui->setupUi(this);


    //connect(ui->back_pushButton, SIGNAL(clicked()), this, SLOT(reject()));
    timer = new QTimer(this);
    timer->setInterval(100);

    connect(timer, SIGNAL(timeout()), this, SLOT(flushBuff()));

    pd.dev_name = nullptr;

    //初始化创建QUdpSocket对象
    mSocket = new QUdpSocket();
    bufrgb = nullptr;
}

All_screen::~All_screen()
{
    if (timer->isActive())
    {
        timer->stop();
    }
    delete ui;
}

void All_screen::rec_port(quint16 port)
{
    this->port = port;
    pd.dev_name = (char*)"/dev/video7";
    int flag = init_dev(&pd);
    if (flag == -1)
    {
        QMessageBox::information(this, tr("Tip"), tr("no device"));
        exit(1);
    }
    else if (flag == -2)
    {
        QMessageBox::information(this, tr("Tip"), tr("device is wrong"));
        exit(2);
    }
    else if (flag == -3)
    {
        QMessageBox::information(this, tr("Tip"), tr("can not open device"));
        exit(3);
    }

    timer->start();
}



void All_screen::flushBuff()
{

    read_frame (&pd);
    if (!bufrgb)
    {
        bufrgb = (unsigned char*)malloc(640 * 480 * 3);
    }

    memset(bufrgb, 0, 640 * 480 * 3);


    convert_yuv_to_rgb_buffer((unsigned char*)pd.buffers[pd.buf.index].start, bufrgb, 640, 480);
    QImage image(bufrgb, 640, 480, QImage::Format_RGB888);
    QPixmap pic = QPixmap::fromImage(image);
    pic.scaled(ui->label->width(), ui->label->height());
    ui->label->setPixmap(pic);
    return_data(&pd);

    QByteArray byte;
    QBuffer buf(&byte);
    image.save(&buf, "JPEG");
    QByteArray ss = qCompress(byte, 1);
    QByteArray vv = ss.toBase64();

    QByteArray ba;
    QDataStream out(&ba, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_6);
    out << (quint64)0;
    out << vv;
    out.device()->seek(0);
    out << (quint64)(ba.size() - sizeof(quint64));

    //单播
    mSocket->writeDatagram(ba, QHostAddress("192.168.20.169"), 8888);

}


void All_screen::on_back_pushButton_clicked()
{
    if(pd.dev_name != nullptr)
    {
        qDebug() << "不为空";
        stop_dev(&pd);
    }
    Menu* menu = new Menu;
    menu->show();
    delete this;
}
