#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QTimer>
namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_start_pushButton_clicked();

    void on_close_pushButton_clicked();

    void new_client();

    //读客户端的数据
    void read_data();

    void on_pushButton_clicked();

    void on_monitoring_pushButton_clicked();

private:
    Ui::MainWindow* ui;
    QTcpServer* server;
    QTcpSocket* socket;
    QString ip1 = "";
    void regist_fun( QString account, QString passwd, QString passwd2);
    void login_fun(QString account, QString passwd);
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
