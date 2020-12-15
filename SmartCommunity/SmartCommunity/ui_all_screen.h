/********************************************************************************
** Form generated from reading UI file 'all_screen.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALL_SCREEN_H
#define UI_ALL_SCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_All_screen
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *back_pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *All_screen)
    {
        if (All_screen->objectName().isEmpty())
            All_screen->setObjectName(QStringLiteral("All_screen"));
        All_screen->resize(800, 480);
        centralwidget = new QWidget(All_screen);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, -30, 680, 480));
        QFont font;
        font.setPointSize(23);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        back_pushButton = new QPushButton(centralwidget);
        back_pushButton->setObjectName(QStringLiteral("back_pushButton"));
        back_pushButton->setGeometry(QRect(700, 360, 91, 51));
        All_screen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(All_screen);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        All_screen->setMenuBar(menubar);
        statusbar = new QStatusBar(All_screen);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        All_screen->setStatusBar(statusbar);

        retranslateUi(All_screen);

        QMetaObject::connectSlotsByName(All_screen);
    } // setupUi

    void retranslateUi(QMainWindow *All_screen)
    {
        All_screen->setWindowTitle(QApplication::translate("All_screen", "MainWindow", 0));
        label->setText(QApplication::translate("All_screen", "\346\234\252\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264\357\274\201", 0));
        back_pushButton->setText(QApplication::translate("All_screen", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class All_screen: public Ui_All_screen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALL_SCREEN_H
