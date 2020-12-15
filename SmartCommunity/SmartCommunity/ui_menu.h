/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *centralwidget;
    QListWidget *weather_Widget;
    QLabel *data_label;
    QLabel *time_label;
    QPushButton *light_pushButton;
    QPushButton *fix_pushButton;
    QPushButton *game_pushButton;
    QPushButton *back_pushButton;
    QWidget *adv_widget;
    QWidget *mp4_widget;
    QPushButton *start_pushButton;
    QSpinBox *port_spinBox;
    QLabel *camera_label;
    QPushButton *all_pushButton;
    QMenuBar *menubar;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QStringLiteral("Menu"));
        Menu->resize(800, 480);
        Menu->setStyleSheet(QLatin1String("QMainWindow{background-color: rgb(80, 80, 80);}\n"
""));
        centralwidget = new QWidget(Menu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        weather_Widget = new QListWidget(centralwidget);
        weather_Widget->setObjectName(QStringLiteral("weather_Widget"));
        weather_Widget->setGeometry(QRect(520, 59, 270, 130));
        weather_Widget->setStyleSheet(QStringLiteral(""));
        data_label = new QLabel(centralwidget);
        data_label->setObjectName(QStringLiteral("data_label"));
        data_label->setGeometry(QRect(520, 30, 131, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        data_label->setFont(font);
        data_label->setStyleSheet(QStringLiteral("color: rgb(172, 224, 255);"));
        data_label->setAlignment(Qt::AlignCenter);
        time_label = new QLabel(centralwidget);
        time_label->setObjectName(QStringLiteral("time_label"));
        time_label->setGeometry(QRect(520, 0, 131, 31));
        time_label->setFont(font);
        time_label->setStyleSheet(QStringLiteral("color: rgb(172, 224, 255);"));
        time_label->setAlignment(Qt::AlignCenter);
        light_pushButton = new QPushButton(centralwidget);
        light_pushButton->setObjectName(QStringLiteral("light_pushButton"));
        light_pushButton->setGeometry(QRect(500, 360, 81, 81));
        light_pushButton->setStyleSheet(QStringLiteral("border-image: url(:/image/off.png);"));
        fix_pushButton = new QPushButton(centralwidget);
        fix_pushButton->setObjectName(QStringLiteral("fix_pushButton"));
        fix_pushButton->setGeometry(QRect(590, 360, 81, 81));
        fix_pushButton->setStyleSheet(QStringLiteral("border-image: url(:/image/fix.png);"));
        game_pushButton = new QPushButton(centralwidget);
        game_pushButton->setObjectName(QStringLiteral("game_pushButton"));
        game_pushButton->setGeometry(QRect(690, 360, 101, 81));
        game_pushButton->setStyleSheet(QLatin1String("border-image: url(:/image/game.png);\n"
""));
        back_pushButton = new QPushButton(centralwidget);
        back_pushButton->setObjectName(QStringLiteral("back_pushButton"));
        back_pushButton->setGeometry(QRect(670, 10, 101, 41));
        adv_widget = new QWidget(centralwidget);
        adv_widget->setObjectName(QStringLiteral("adv_widget"));
        adv_widget->setGeometry(QRect(10, 370, 491, 71));
        adv_widget->setStyleSheet(QStringLiteral("border-image: url(:/image/adv5.png);"));
        mp4_widget = new QWidget(centralwidget);
        mp4_widget->setObjectName(QStringLiteral("mp4_widget"));
        mp4_widget->setGeometry(QRect(0, 0, 511, 351));
        start_pushButton = new QPushButton(centralwidget);
        start_pushButton->setObjectName(QStringLiteral("start_pushButton"));
        start_pushButton->setGeometry(QRect(700, 280, 91, 61));
        QFont font1;
        font1.setPointSize(7);
        font1.setBold(true);
        font1.setWeight(75);
        start_pushButton->setFont(font1);
        port_spinBox = new QSpinBox(centralwidget);
        port_spinBox->setObjectName(QStringLiteral("port_spinBox"));
        port_spinBox->setGeometry(QRect(700, 200, 91, 71));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        port_spinBox->setFont(font2);
        port_spinBox->setMaximum(65535);
        port_spinBox->setValue(8888);
        camera_label = new QLabel(centralwidget);
        camera_label->setObjectName(QStringLiteral("camera_label"));
        camera_label->setGeometry(QRect(520, 200, 171, 141));
        camera_label->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        camera_label->setAlignment(Qt::AlignCenter);
        all_pushButton = new QPushButton(centralwidget);
        all_pushButton->setObjectName(QStringLiteral("all_pushButton"));
        all_pushButton->setGeometry(QRect(520, 200, 171, 141));
        all_pushButton->setFlat(true);
        Menu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Menu);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Menu->setMenuBar(menubar);

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "MainWindow", 0));
        data_label->setText(QString());
        time_label->setText(QString());
        light_pushButton->setText(QString());
        fix_pushButton->setText(QString());
        game_pushButton->setText(QString());
        back_pushButton->setText(QApplication::translate("Menu", "\350\277\224\345\233\236", 0));
        start_pushButton->setText(QApplication::translate("Menu", "\345\274\200\345\220\257\346\221\204\345\203\217\345\244\264", 0));
        camera_label->setText(QApplication::translate("Menu", "\346\234\252\345\274\200\345\220\257\346\221\204\345\203\217\345\244\264\357\274\201", 0));
        all_pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
