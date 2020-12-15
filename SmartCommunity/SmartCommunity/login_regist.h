#ifndef LOGIN_REGIST_H
#define LOGIN_REGIST_H

#include <QMainWindow>
#include <QtDebug>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTcpSocket>
#include <regist.h>
#include <QTimer>
#include "softkeyboard.h"
#include <QWidget>
#include <QMouseEvent>


namespace Ui
{
    class Login_regist;
}

class Login_regist : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login_regist(QWidget* parent = nullptr);
    ~Login_regist();
    void callKeyBoard();

private slots:
    void on_regist_Button_clicked();
    void read_data();

    void on_login_Button_clicked();

protected:
    bool eventFilter(QObject* watched, QEvent* event);

private slots:
    void setaccount_Text(QString text);


private:
    Ui::Login_regist* ui;
    QTcpSocket* socket;
    SoftKeyboard* softKeyboard;
};

#endif // LOGIN_REGIST_H
