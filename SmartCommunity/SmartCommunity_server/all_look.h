#ifndef ALL_LOOK_H
#define ALL_LOOK_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QProcess>
namespace Ui
{
    class ALL_look;
}

class ALL_look : public QMainWindow
{
    Q_OBJECT

public:
    explicit ALL_look(QWidget* parent = nullptr);
    ~ALL_look();
    void re_connet();
    void fixre_connet();

private slots:
    void on_back_pushButton_clicked();
    void read_data1();
    void read_data2();
    void read_data3();
    void ShowImage1(QByteArray ba);
    void ShowImage2(QByteArray ba);
    void ShowImage3(QByteArray ba);

    void on_look1_pushButton_clicked();
    void on_look2_pushButton_clicked();
    void on_look3_pushButton_clicked();

    void on_fix1_pushButton_clicked();

    void on_fix2_pushButton_clicked();

    void on_fix3_pushButton_clicked();



signals:
    void sendinfo(QHostAddress ip, quint16 port);
private:
    Ui::ALL_look* ui;
    QUdpSocket* mSocket1;
    QUdpSocket* mSocket2;
    QUdpSocket* mSocket3;

    quint64 basize;


};

#endif // ALL_LOOK_H
