#include "regist.h"
#include "ui_regist.h"
#include "login_regist.h"
Regist::Regist(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::Regist)
{
    ui->setupUi(this);

    //[1]
    socket = new QTcpSocket;

    //[3]
    connect(socket, &QTcpSocket::readyRead, this, &Regist::read_data);

    //[2]
    socket->connectToHost("192.168.20.169", 8888);

    //生成键盘
    softKeyboard = new SoftKeyboard();
    //指定键盘生成控件
    ui->account_Edit->installEventFilter(this);
    ui->passwd_Edit->installEventFilter(this);
    ui->pass2_Edit->installEventFilter(this);

}

Regist::~Regist()
{
    delete ui;
}

void Regist::on_ok_Button_clicked()
{
    QString ins("regist\n" + ui->account_Edit->text() + "\n"
                + ui->passwd_Edit->text() + "\n"
                + ui->pass2_Edit->text() + "\n");
    socket->write(ins.toUtf8());
}

void Regist::on_back_Button_clicked()
{
    Login_regist* lr = new Login_regist;
    lr->show();
    delete this;
}

void Regist::read_data()
{
    QMessageBox a;
    a.information(nullptr, "提示", socket->readAll());
}

bool Regist::eventFilter(QObject* watched, QEvent* event)
{
    if(event->type() == QEvent::MouseButtonRelease) //事件类型
    {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event); //将事件强制转换
        if(mouseEvent->button() == Qt::LeftButton)
        {
            if(watched == ui->account_Edit)
            {
                softKeyboard->hideInputBufferArea(ui->account_Edit);
                //softKeyboard->resize(800, 200);
                softKeyboard->setGeometry(0, 190, 800, 200);
                softKeyboard->show();
                ui->account_Edit->setFocus();
            }
            else if(watched == ui->passwd_Edit)
            {
                connect(softKeyboard, SIGNAL(sendInputBufferAreaText(QString)), this, SLOT(setpass1_Text(QString)));
                softKeyboard->showInputBufferArea("请输入密码：");
                softKeyboard->setGeometry(0, 190, 800, 200);
                softKeyboard->show();
                ui->passwd_Edit->setFocus();
            }
            else if (watched == ui->pass2_Edit)
            {
                connect(softKeyboard, SIGNAL(sendInputBufferAreaText(QString)), this, SLOT(setpass2_Text(QString)));
                softKeyboard->showInputBufferArea("请再次输入密码：");
                softKeyboard->setGeometry(0, 190, 800, 200);
                softKeyboard->show();
                ui->passwd_Edit->setFocus();
            }
        }
    }
    return QWidget::eventFilter(watched, event); //返回父类的事件过滤器
}

void Regist::setaccount_Text(QString text)
{
    ui->account_Edit->setText(text);
}

void Regist::setpass1_Text(QString text)
{
    ui->passwd_Edit->setText(text);
}

void Regist::setpass2_Text(QString text)
{
    ui->pass2_Edit->setText(text);
}
