/********************************************************************************
** Form generated from reading UI file 'games_show.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMES_SHOW_H
#define UI_GAMES_SHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Games_show
{
public:
    QWidget *centralwidget;
    QPushButton *gobang_pushButton;
    QPushButton *back_pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Games_show)
    {
        if (Games_show->objectName().isEmpty())
            Games_show->setObjectName(QStringLiteral("Games_show"));
        Games_show->resize(800, 480);
        Games_show->setStyleSheet(QLatin1String("QMainWindow{border-image: url(:/image/game.jpg);}\n"
""));
        centralwidget = new QWidget(Games_show);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gobang_pushButton = new QPushButton(centralwidget);
        gobang_pushButton->setObjectName(QStringLiteral("gobang_pushButton"));
        gobang_pushButton->setGeometry(QRect(130, 150, 150, 150));
        gobang_pushButton->setStyleSheet(QStringLiteral("border-image: url(:/icon/wuziqi.png);"));
        back_pushButton = new QPushButton(centralwidget);
        back_pushButton->setObjectName(QStringLiteral("back_pushButton"));
        back_pushButton->setGeometry(QRect(640, 350, 101, 51));
        Games_show->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Games_show);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Games_show->setMenuBar(menubar);
        statusbar = new QStatusBar(Games_show);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Games_show->setStatusBar(statusbar);

        retranslateUi(Games_show);

        QMetaObject::connectSlotsByName(Games_show);
    } // setupUi

    void retranslateUi(QMainWindow *Games_show)
    {
        Games_show->setWindowTitle(QApplication::translate("Games_show", "MainWindow", 0));
        gobang_pushButton->setText(QString());
        back_pushButton->setText(QApplication::translate("Games_show", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class Games_show: public Ui_Games_show {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMES_SHOW_H
