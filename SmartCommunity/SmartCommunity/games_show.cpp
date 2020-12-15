#include "games_show.h"
#include "ui_games_show.h"
#include "gobang.h"
#include "menu.h"
Games_show::Games_show(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::Games_show)
{
    ui->setupUi(this);
}

Games_show::~Games_show()
{
    delete ui;
}

void Games_show::on_gobang_pushButton_clicked()
{
    Gobang* gobang = new Gobang;
    gobang->show();
    delete this;
}

void Games_show::on_back_pushButton_clicked()
{
    Menu* menu = new Menu;
    menu->show();
    delete this;
}
