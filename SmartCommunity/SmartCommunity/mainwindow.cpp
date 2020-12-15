#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*设置样式*/
    QFile file("./mystyle.qss");
    qDebug() << "sty ok======";
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray data = file.readAll();
        //qApp 它是一个 宏定义，是一个函数的函数返回 值，返回该应用程序中，只有一个qApp对象

        //#define qApp (static_cast<QApplication *>(QCoreApplication::instance()))
        qApp->setStyleSheet(data);
        qDebug() << "sty ok======";
    }
    file.close();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::ad_play);
    timer->setInterval(1000);
    timer->start();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_skip_Button_clicked()
{
    timer->stop();
    Login_regist* l_r = new Login_regist;
    l_r->show();
    // delete this;
    this->close();
}

static int i = 1;
static int a = 3;

void MainWindow::ad_play()
{
    qDebug() << QString("QMainWindow{border-image: url(:/image/g%1.jpg);}").arg(QString::number(i));
    this->setStyleSheet(QString("QMainWindow{border-image: url(:/image/g%1.jpg);}")
                        .arg(QString::number(i++)));

    ui->skip_Button->setText( QString("跳过广告 （%1s）")
                              .arg(QString::number(a--)));


    if(i == 4)
    {
        timer->stop();
        Login_regist* l_r = new Login_regist;
        l_r->show();
        this->close();
    }
}

