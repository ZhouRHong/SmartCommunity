#ifndef ALLSCREEN_H
#define ALLSCREEN_H

#include <QMainWindow>
#include <QUdpSocket>
namespace Ui
{
    class Allscreen;
}

class Allscreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit Allscreen(QWidget* parent = nullptr);
    ~Allscreen();

private slots:

    void on_backe_pushButton_clicked();

    void read_data();

    void ShowImage(QByteArray ba);
public slots:
    void recvinfo(QHostAddress ip, quint16 port);

private:
    Ui::Allscreen* ui;
    QUdpSocket* mSocket;
};

#endif // ALLSCREEN_H
