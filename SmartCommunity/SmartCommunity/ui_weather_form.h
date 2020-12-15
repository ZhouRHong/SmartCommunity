/********************************************************************************
** Form generated from reading UI file 'weather_form.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHER_FORM_H
#define UI_WEATHER_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Weather_form
{
public:
    QLabel *temperature_label;
    QLabel *level_label;
    QLabel *weather_label;
    QLabel *quality_label;
    QLabel *wind_label;
    QLabel *city_label;
    QLabel *pic_label;

    void setupUi(QWidget *Weather_form)
    {
        if (Weather_form->objectName().isEmpty())
            Weather_form->setObjectName(QStringLiteral("Weather_form"));
        Weather_form->resize(270, 130);
        Weather_form->setStyleSheet(QStringLiteral(""));
        temperature_label = new QLabel(Weather_form);
        temperature_label->setObjectName(QStringLiteral("temperature_label"));
        temperature_label->setGeometry(QRect(130, 30, 141, 51));
        temperature_label->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 0);"));
        temperature_label->setAlignment(Qt::AlignCenter);
        level_label = new QLabel(Weather_form);
        level_label->setObjectName(QStringLiteral("level_label"));
        level_label->setGeometry(QRect(190, 0, 81, 31));
        level_label->setStyleSheet(QStringLiteral("background-color: rgb(255, 85, 0);"));
        level_label->setAlignment(Qt::AlignCenter);
        weather_label = new QLabel(Weather_form);
        weather_label->setObjectName(QStringLiteral("weather_label"));
        weather_label->setGeometry(QRect(60, 30, 72, 51));
        weather_label->setStyleSheet(QLatin1String("background-color: rgb(118, 39, 0);\n"
"color: rgb(255, 255, 255);"));
        weather_label->setAlignment(Qt::AlignCenter);
        quality_label = new QLabel(Weather_form);
        quality_label->setObjectName(QStringLiteral("quality_label"));
        quality_label->setGeometry(QRect(0, 80, 101, 41));
        quality_label->setStyleSheet(QStringLiteral("background-color: rgb(65, 255, 154);"));
        quality_label->setAlignment(Qt::AlignCenter);
        wind_label = new QLabel(Weather_form);
        wind_label->setObjectName(QStringLiteral("wind_label"));
        wind_label->setGeometry(QRect(100, 80, 171, 41));
        wind_label->setStyleSheet(QStringLiteral("background-color: rgb(139, 56, 255);"));
        wind_label->setAlignment(Qt::AlignCenter);
        city_label = new QLabel(Weather_form);
        city_label->setObjectName(QStringLiteral("city_label"));
        city_label->setGeometry(QRect(0, 0, 191, 31));
        city_label->setStyleSheet(QStringLiteral("background-color: rgb(85, 85, 255);"));
        city_label->setAlignment(Qt::AlignCenter);
        pic_label = new QLabel(Weather_form);
        pic_label->setObjectName(QStringLiteral("pic_label"));
        pic_label->setGeometry(QRect(0, 30, 61, 51));
        pic_label->setStyleSheet(QStringLiteral(""));

        retranslateUi(Weather_form);

        QMetaObject::connectSlotsByName(Weather_form);
    } // setupUi

    void retranslateUi(QWidget *Weather_form)
    {
        Weather_form->setWindowTitle(QApplication::translate("Weather_form", "Form", 0));
        temperature_label->setText(QString());
        level_label->setText(QString());
        weather_label->setText(QString());
        quality_label->setText(QString());
        wind_label->setText(QString());
        city_label->setText(QString());
        pic_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Weather_form: public Ui_Weather_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHER_FORM_H
