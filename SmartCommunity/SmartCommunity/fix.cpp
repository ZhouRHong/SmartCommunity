#include "fix.h"
#include "ui_fix.h"

Fix::Fix(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Fix)
{
    ui->setupUi(this);
}

Fix::~Fix()
{
    delete ui;
}
