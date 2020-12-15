#ifndef REGIST_H
#define REGIST_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTcpSocket>
#include "softkeyboard.h"
#include <QWidget>
#include <QMouseEvent>
namespace Ui
{
    class Regist;
}

class Regist : public QMainWindow
{
    Q_OBJECT

public:
    explicit Regist(QWidget* parent = nullptr);
    ~Regist();

private slots:
    void on_ok_Button_clicked();

    void on_back_Button_clicked();
    void read_data();

protected:
    bool eventFilter(QObject* watched, QEvent* event);

private slots:
    void setaccount_Text(QString text);
    void setpass1_Text(QString text);
    void setpass2_Text(QString text);

private:
    Ui::Regist* ui;
    QTcpSocket* socket;
    SoftKeyboard* softKeyboard;
};

#endif // REGIST_H
