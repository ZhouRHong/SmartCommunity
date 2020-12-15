#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QTime>
#include <QDate>
#include <QTimer>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <weather_form.h>
#include <QListWidgetItem>
#include <QtDebug>
#include <QProcess>
#include <QtGui>
#include "v4l2.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QUdpSocket>

extern "C"
{
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
}

namespace Ui
{
    class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget* parent = nullptr);
    ~Menu();
private slots:
    void updateTime();
    void advplay();
    void read_data(QNetworkReply* reply);
    void video_auto(int exitCode, QProcess::ExitStatus exitStatus);

    void on_light_pushButton_clicked();

    void on_fix_pushButton_clicked();

    void on_game_pushButton_clicked();

    void on_back_pushButton_clicked();

    void beginCapture();

    void flushBuff();

    void on_start_pushButton_clicked();

    //void on_port_spinBox_valueChanged(int arg1);

    void on_all_pushButton_clicked();
signals:
    void sendport(qint16 port);
private:
    Ui::Menu* ui;
    QTimer* timer;
    QTimer* timer2;

    QNetworkAccessManager* manager;
    int i = 1;

    int fd; //文件描述符
    int isRunning; //灯的运行状态
    QProcess* process;

    pass_data pd;
    QTimer* timer3;
//  QTcpSocket* socket;
//  QTcpServer* tcp_server;
//  int start_tcp;
    unsigned char* bufrgb;
    QUdpSocket* mSocket;
};

#endif // MENU_H
