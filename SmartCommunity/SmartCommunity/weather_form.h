#ifndef WEATHER_FORM_H
#define WEATHER_FORM_H

#include <QWidget>

namespace Ui
{
    class Weather_form;
}

class Weather_form : public QWidget
{
    Q_OBJECT

public:
    explicit Weather_form(QWidget* parent = nullptr);
    ~Weather_form();
    void setInfo(QPixmap& map, const QString& date,
                 const QString& temperature,
                 const QString& weather,
                 const QString& direct,
                 const QString& power = nullptr,
                 const QString& aqi = nullptr);

private slots:

private:
    Ui::Weather_form* ui;
};

#endif // WEATHER_FORM_H
