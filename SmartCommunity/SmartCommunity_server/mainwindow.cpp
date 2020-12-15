#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include "all_look.h"
MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //[1]
    server = new QTcpServer;

    //[3]
    connect(server, &QTcpServer::newConnection, this, &MainWindow::new_client);

    db = QSqlDatabase::addDatabase("QSQLITE"); //跟SQLite3进行连接
    db.setDatabaseName("user_info.db"); //给数据库设置一个名字,最好加一个.db后缀

    db.open();
    if(!db.open())
    {
        qDebug() << "open database Failed" << db.lastError();
    }

//    QSqlQuery query;

//    QString sqlTable = QString("CREATE TABLE info(id INTEGER PRIMARY KEY AUTOINCREMENT,"
//                               "account varchar(20),"
//                               "passwd varchar(20));");
//    qDebug() << sqlTable;

//    //[3] 执行语句 --- QSqlQuery

//    query.prepare(sqlTable);
//    if(!query.exec())
//    {
//        qDebug() << "Error Failed to create table" << db.lastError();
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_pushButton_clicked()
{
    //[2]
    server->listen(QHostAddress::Any, ui->port_spinBox->text().toUShort());
    ui->status_label->setText("START");
    ui->start_pushButton->setEnabled(0);
    ui->close_pushButton->setEnabled(1);
    ui->port_label->setText(ui->port_spinBox->text());
}

void MainWindow::on_close_pushButton_clicked()
{
    server->close();

    ui->status_label->setText("STOP");
    ui->start_pushButton->setEnabled(1);
    ui->close_pushButton->setEnabled(0);
}

void MainWindow::new_client()
{
    //[4] 获取新连接的客户端
    socket = server->nextPendingConnection();
    qDebug() << socket;

    //[5]建立与新的客户端数据读取
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::read_data);
    QString ip =  socket->peerAddress().toString();
    ip.remove(0, 7);
    if(ip1 != ip)
    {
        ui->IP_textBrowser->append(ip);
    }
    ip1 = ip;
}

void MainWindow::read_data()
{
    //[6]读客户端数据
    //ui->message_textBrowser->append(ip + "\n" + socket->readAll());
    //socket->readAll();
//    qDebug() << socket->readLine();
//    qDebug() << socket->readLine();

    //操作标志
    QString operation = QString(socket->readLine()).remove(QChar('\n'), Qt::CaseInsensitive);

    //账号
    QString account = QString(socket->readLine()).remove(QChar('\n'), Qt::CaseInsensitive);

    //密码
    QString passwd = QString(socket->readLine()).remove(QChar('\n'), Qt::CaseInsensitive);

    //二次密码
    QString passwd2 = QString(socket->readLine()).remove(QChar('\n'), Qt::CaseInsensitive);

    qDebug() << operation;
    qDebug() << account;
    qDebug() << passwd;
    qDebug() << passwd2;

    if(operation == "regist")
    {
        qDebug() << "进入注册";
        regist_fun( account,  passwd,  passwd2);
    }
    else if (operation == "login")
    {
        login_fun(account,  passwd);
    }
}


void MainWindow::on_pushButton_clicked()
{
    ui->message_textBrowser->clear();
}

void MainWindow::regist_fun(QString account, QString passwd, QString passwd2)
{
    QMessageBox a;

    QSqlQuery query;

    if(account == "admin")
    {
        qDebug() << "您不能使用管理员账户名注册！！！";
        socket->write( "您不能使用管理员账户名注册！！！");
        return;
    }
    QString sqlSelect = QString("SELECT account FROM info;");

    if(!query.exec(sqlSelect))
    {
        qDebug() << "Error Failed to slect record" << db.lastError();
    }
    else
    {
        //开始读取表中的记录
        while (query.next())
        {

            /*判断账户是否重复或者为管理账户*/
            if(query.value("account").toString() == account)
            {
                socket->write( "该账户名已经被注册！！！");
                return;
            }

        }
    }

    if(passwd == passwd2)
    {

        QString sqlinsert = QString("INSERT INTO info(account,passwd)VALUES('%1','%2')")
                            .arg(account)
                            .arg(passwd.toInt());
        qDebug() << sqlinsert;
        if(!query.exec(sqlinsert))
        {
            qDebug() << "Error Failed to insert record" << db.lastError();
        }
        socket->write( "添加成功！！！");
        return;
    }
    else
    {
        socket->write( "两次输入密码不一致！！！");
        return;
    }
}


void MainWindow::login_fun(QString account, QString passwd)
{
    QMessageBox a;
    QSqlQuery query;
    QString sqlSelect = QString("SELECT * FROM info;");

    if(!query.exec(sqlSelect))
    {
        qDebug() << "Error Failed to slect record" << db.lastError();
    }
    else
    {
        //开始读取表中的记录
        while (query.next())
        {
            if(query.value("account").toString() == account)
            {
                if(query.value("passwd").toString() == passwd)
                {
                    socket->write("login_success");
                    return;
                }
                else
                {
                    socket->write("login_fail");
                    return;
                }
            }
        }
    }
    /*遍历完没有就说明没有注册*/
    socket->write("该账户未注册！！！");
}

void MainWindow::on_monitoring_pushButton_clicked()
{
    ALL_look* all_look = new ALL_look(this);
    all_look->show();
    this->hide();
}
