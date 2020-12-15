#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtDebug>
#include "login_regist.h"
#include <QFile>
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
    void on_skip_Button_clicked();
    void ad_play();


private:
    Ui::MainWindow* ui;
    QTimer* timer;


};

#endif // MAINWINDOW_H
