#include "menu.h"
#include "ui_menu.h"
#include "login_regist.h"
#include "games_show.h"
#include <string.h>
#include <QMessageBox>
#include "all_screen.h"
Menu::Menu(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    bufrgb = nullptr;
    timer3 = new QTimer(this);
    timer3->setInterval(100);
    pd.dev_name = nullptr;
    connect(timer3, SIGNAL(timeout()), this, SLOT(flushBuff()));

    //初始化创建QUdpSocket对象
    mSocket = new QUdpSocket();
    //微视频
    QString cmd = QString("mplayer -slave -quiet "
                          "-geometry 10:10 -zoom -x %1 -y %2 "
                          "./video/%3.mp4 &")
                  .arg(ui->mp4_widget->width())
                  .arg(ui->mp4_widget->height())
                  .arg(QString::number(3));
    process = new QProcess;
    qDebug() << cmd;
    process->start(cmd);
    //当执行进程结束时，会调用该槽函数
    connect(process, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(video_auto(int, QProcess::ExitStatus )));

    //显示实时时间
    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    ui->data_label->setText(date.toString("yyyy/MM/dd"));
    ui->time_label->setText(time.toString("hh:mm:ss"));

    //更新时间
    timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &Menu::updateTime);
    timer->start(1000);

    //更新时间
    timer2 = new QTimer;
    connect(timer2, &QTimer::timeout, this, &Menu::advplay);
    timer2->start(2000);

    manager = new QNetworkAccessManager;
    connect(manager, &QNetworkAccessManager::finished, this, &Menu::read_data);

    QUrl url("http://apis.juhe.cn/simpleWeather/query?city=%E5%B9%BF%E5%B7%9E&key=cfa26837b1520414f6f0176136f626a9");
    QNetworkRequest request(url);
    manager->get(request);

    //灯初始化
    isRunning = 0;
    fd = open("/dev/gz13_led_drv", O_WRONLY);
    if(fd == -1)
    {
        qDebug() << "open error\n";
        return;
    }
}

Menu::~Menu()
{
    if (timer->isActive())
    {
        timer->stop();
    }
    if (timer2->isActive())
    {
        timer2->stop();
    }
    if (timer3->isActive())
    {
        timer3->stop();
    }
    delete ui;
}

void Menu::updateTime()
{
    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    ui->data_label->setText(date.toString("yyyy/MM/dd"));
    ui->time_label->setText(time.toString("hh:mm:ss"));
}

void Menu::advplay()
{
    ui->adv_widget->setStyleSheet(QString("border-image: url(:/image/adv%1.png);")
                                  .arg(QString::number(i++)));
    if(i == 6)
    {
        i = 1;
    }
}

void Menu::read_data(QNetworkReply* reply)
{
    QByteArray data = reply->readAll();

    QJsonDocument doc = QJsonDocument::fromJson(data);

    QJsonObject object = doc.object();

    QJsonObject result_object = object.value("result").toObject();

    QJsonObject realtime_object = result_object.value("realtime").toObject();

    QJsonArray array = result_object.value("future").toArray();

    QListWidgetItem* item = new QListWidgetItem;
    ui->weather_Widget->addItem(item);
    Weather_form* weather_form = new Weather_form;

    QPixmap map;
    qDebug() << realtime_object.value("info").toString();

    QString weather = realtime_object.value("info").toString();
    qDebug() << weather;
    QString a = "阴";
    if(weather == a)
    {
        QString fileName = QString(":/icon/ying.png");
        map.load(fileName);
        qDebug() << fileName;
    }
    else if(realtime_object.value("info").toString() == "阴转多云")
    {
        QString fileName = QString(":/icon/ying_to_cloudy.png");
        map.load(fileName);
    }
    else if(weather == "多云")
    {
        QString fileName = QString(":/icon/cloudy.png");
        map.load(fileName);
        qDebug() << fileName;
    }
    else if(realtime_object.value("info").toString() == "多云转晴")
    {
        QString fileName = QString(":/icon/cloudy_to_sunny.png");
        map.load(fileName);
    }
    else if(realtime_object.value("info").toString() == "晴")
    {
        QString fileName = QString(":/icon/sunny.png");
        map.load(fileName);
    }


    weather_form->setInfo(map, result_object.value("city").toString(),
                          realtime_object.value("temperature").toString(),
                          realtime_object.value("info").toString(),
                          realtime_object.value("direct").toString(),
                          realtime_object.value("power").toString(),
                          realtime_object.value("aqi").toString());

    item->setSizeHint(QSize(280, 315));
    ui->weather_Widget->setItemWidget(item, weather_form);


    for (int i = 0; i < array.size(); i++)
    {
        qDebug() << i;
        QListWidgetItem* item = new QListWidgetItem;
        Weather_form* weather_form = new Weather_form;
        ui->weather_Widget->addItem(item);
        QJsonObject object2 = array.at(i).toObject();

        qDebug() << object2.value("weather").toString();
        QString weather = object2.value("weather").toString();
        qDebug() << weather;

        if(weather == "阴")
        {
            QString fileName = QString(":/icon/ying.png");
            map.load(fileName);
            qDebug() << fileName;
        }
        else if( object2.value("weather").toString() == "阴转多云")
        {
            QString fileName = QString(":/icon/ying_to_cloudy.png");
            map.load(fileName);
        }
        else if( object2.value("weather").toString() == "多云")
        {
            QString fileName = QString(":/icon/cloudy.png");
            map.load(fileName);
        }
        else if( object2.value("weather").toString() == "多云转晴")
        {
            QString fileName = QString(":/icon/cloudy_to_sunny.png");
            map.load(fileName);
        }
        else if( object2.value("weather").toString() == "晴")
        {
            QString fileName = QString(":/icon/sunny.png");
            map.load(fileName);
        }

        weather_form->setInfo(map, object2.value("date").toString(),
                              object2.value("temperature").toString(),
                              object2.value("weather").toString(),
                              object2.value("direct").toString());
        item->setSizeHint(QSize(270, 130));
        ui->weather_Widget->setItemWidget(item, weather_form);
    }
}

static int a = 1;
void Menu::video_auto(int exitCode, QProcess::ExitStatus exitStatus)
{
    QString cmd = QString("mplayer -slave -quiet "
                          "-geometry 10:10 -zoom -x %1 -y %2 "
                          "./video/%3.mp4 &")
                  .arg(ui->mp4_widget->width())
                  .arg(ui->mp4_widget->height())
                  .arg(QString::number(a++));;
    if(a == 4)
    {
        a = 1;
    }
    qDebug() << cmd;
    process->start(cmd);
}


void Menu::on_light_pushButton_clicked()
{
    char user_buff[2];
    //用户实现对LED的控制---流水灯
    if(isRunning == 0)//D8亮
    {
        user_buff[0] = 1;
        user_buff[1] = 7; //
        write(fd, user_buff, sizeof(user_buff));

        user_buff[0] = 1;
        user_buff[1] = 8; //
        write(fd, user_buff, sizeof(user_buff));

        user_buff[0] = 1; //
        user_buff[1] = 9;
        write(fd, user_buff, sizeof(user_buff));

        user_buff[0] = 1;//
        user_buff[1] = 10;
        write(fd, user_buff, sizeof(user_buff));
        ui->light_pushButton->setStyleSheet("border-image: url(:/image/on.png);");

    }
    else if (isRunning == 1)
    {
        user_buff[0] = 0;
        user_buff[1] = 7; //
        write(fd, user_buff, sizeof(user_buff));

        user_buff[0] = 0;
        user_buff[1] = 8; //
        write(fd, user_buff, sizeof(user_buff));

        user_buff[0] = 0; //
        user_buff[1] = 9;
        write(fd, user_buff, sizeof(user_buff));

        user_buff[0] = 0;//
        user_buff[1] = 10;
        write(fd, user_buff, sizeof(user_buff));
        ui->light_pushButton->setStyleSheet("border-image: url(:/image/off.png);");
    }

    isRunning++;
    if(isRunning == 2)
    {
        isRunning = 0;
    }
}

void Menu::on_fix_pushButton_clicked()
{

}

void Menu::on_game_pushButton_clicked()
{
    process->terminate();
    Games_show* game_show = new Games_show;
    game_show->show();
    delete this;
}

void Menu::on_back_pushButton_clicked()
{
    if(pd.dev_name != nullptr)
    {
        qDebug() << "=====================================null";
        stop_dev(&pd);
    }
    process->terminate();
    Login_regist* l_r = new Login_regist;
    l_r->show();
    delete this;
}

void Menu::beginCapture()
{

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

    timer3->start();
}

void Menu::flushBuff()
{

    read_frame (&pd);

    if (!bufrgb)
    {

        bufrgb = (unsigned char*)malloc(640 * 480 * 3);
    }

    memset(bufrgb, 0, 640 * 480 * 3);

    convert_yuv_to_rgb_buffer((unsigned char*)pd.buffers[pd.buf.index].start, bufrgb, 640, 480);
    QImage image(bufrgb, 640, 480, QImage::Format_RGB888);

    ui->camera_label->setPixmap(QPixmap::fromImage(image));
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
    qint64 len = mSocket->writeDatagram(ba, QHostAddress("192.168.20.169"), ui->port_spinBox->value());

}

void Menu::on_start_pushButton_clicked()
{
    pd.dev_name = (char*)"/dev/video7";
    beginCapture();
    ui->start_pushButton->setEnabled(0);
}

void Menu::on_all_pushButton_clicked()
{
    if(pd.dev_name != nullptr)
    {
        qDebug() << "=====================================null";
        stop_dev(&pd);
    }

    process->terminate();
    All_screen* all_screen = new All_screen;
    connect(this, &Menu::sendport, all_screen, &All_screen::rec_port);
    emit sendport(ui->port_spinBox->value());
    all_screen->show();
    delete this;
}
