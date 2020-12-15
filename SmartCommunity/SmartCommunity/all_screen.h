#ifndef ALL_SCREEN_H
#define ALL_SCREEN_H

#include <QMainWindow>
#include <QtGui>
#include "v4l2.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QUdpSocket>
namespace Ui
{
    class All_screen;
}

class All_screen : public QMainWindow
{
    Q_OBJECT

public:
    explicit All_screen(QWidget* parent = nullptr);
    ~All_screen();
    void rec_port(quint16 port);
private slots:
    void flushBuff();
    void on_back_pushButton_clicked();


private:
    Ui::All_screen* ui;
    pass_data pd;
    QTimer* timer;
    QTcpSocket* socket;
    unsigned char* bufrgb;
    QUdpSocket* mSocket;
    quint16 port;
};

#endif // ALL_SCREEN_H
