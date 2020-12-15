#include "weather_form.h"
#include "ui_weather_form.h"

Weather_form::Weather_form(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::Weather_form)
{
    ui->setupUi(this);
}

Weather_form::~Weather_form()
{
    delete ui;
}

void Weather_form::setInfo(QPixmap& map,
                           const QString& date,
                           const QString& temperature,
                           const QString& weather,
                           const QString& direct,
                           const QString& power,
                           const QString& aqi)
{
    map = map.scaled(ui->pic_label->width(), ui->pic_label->height());
    ui->city_label->setText(date);
    ui->pic_label->setPixmap(map);
    ui->temperature_label->setText(temperature);
    ui->quality_label->setText(aqi);
    ui->wind_label->setText(direct);
    ui->level_label->setText(power);
    ui->weather_label->setText(weather);
}


