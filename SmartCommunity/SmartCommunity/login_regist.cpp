#include "login_regist.h"
#include "ui_login_regist.h"
#include "menu.h"
Login_regist::Login_regist(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::Login_regist)
{
    ui->setupUi(this);
    //[1]
    socket = new QTcpSocket;

    //[3]
    connect(socket, &QTcpSocket::readyRead, this, &Login_regist::read_data);

    //[2]
    socket->connectToHost("192.168.20.169", 8888);

    //生成键盘
    softKeyboard = new SoftKeyboard();
    //指定键盘生成控件
    ui->account_Edit->installEventFilter(this);
    ui->passwd_Edit->installEventFilter(this);

}
static int times = 0;
void Login_regist::read_data()
{
    QMessageBox a;
    QString data = socket->readAll();
    if(data == "login_success")
    {
        qDebug() << "登陆成功";
        Menu* menu = new Menu;
        menu->show();
        delete this;
        return;
    }
    else if(data == "login_fail")
    {
        a.information(nullptr, "提示", QString("您已经输错了密码%1次").arg(++times));
        /*判断输错密码次数*/
        if(times == 3)
        {
            QMessageBox* m_box = new QMessageBox(QMessageBox::Information, QString("提示"), QString("还剩3秒退出"));
            //三秒后退出
            QTimer::singleShot(3000, m_box, SLOT(accept()));
            m_box->exec();
            times = 0;
            this->close();
        }
        return;
    }
    a.information(nullptr, "提示", data);
}


Login_regist::~Login_regist()
{
    delete ui;
}

void Login_regist::callKeyBoard()
{
    // qDebug()<<"callKeyBoard";
    softKeyboard->show();
}

void Login_regist::on_regist_Button_clicked()
{
    Regist* regist = new Regist;
    regist->show();
    delete this;
}

void Login_regist::on_login_Button_clicked()
{
    QString ins("login\n" + ui->account_Edit->text() + "\n"
                + ui->passwd_Edit->text() + "\n");
    socket->write(ins.toUtf8());

}


//事件过滤函数
bool Login_regist::eventFilter(QObject* watched, QEvent* event)
{

    if(event->type() == QEvent::MouseButtonRelease) //事件类型
    {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event); //将事件强制转换
        if(mouseEvent->button() == Qt::LeftButton)
        {
            QPoint point = this->pos();
            if(watched == ui->account_Edit)
            {
                softKeyboard->hideInputBufferArea(ui->account_Edit);
                //softKeyboard->resize(800, 200);
                softKeyboard->setGeometry(0, 190, 800, 200);
//               softKeyboard->move(point + ui->account_Edit->pos());
                softKeyboard->show();
                ui->account_Edit->setFocus();
            }
            else if(watched == ui->passwd_Edit)
            {
                connect(softKeyboard, SIGNAL(sendInputBufferAreaText(QString)), this, SLOT(setaccount_Text(QString)));
                softKeyboard->showInputBufferArea("请输入密码：");
                //softKeyboard->resize(800, 200);
                softKeyboard->setGeometry(0, 190, 800, 200);
                // softKeyboard->move(point + ui->passwd_Edit->pos());
                softKeyboard->show();
                ui->passwd_Edit->setFocus();
            }
        }
    }
    return QWidget::eventFilter(watched, event); //返回父类的事件过滤器
}

void Login_regist::setaccount_Text(QString text)
{
    ui->passwd_Edit->setText(text);
}
