/********************************************************************************
** Form generated from reading UI file 'gobang.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOBANG_H
#define UI_GOBANG_H

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

class Ui_Gobang
{
public:
    QWidget *centralwidget;
    QLabel *gameStatus;
    QPushButton *regret;
    QPushButton *restart;
    QLabel *who;
    QPushButton *back_regret;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Gobang)
    {
        if (Gobang->objectName().isEmpty())
            Gobang->setObjectName(QStringLiteral("Gobang"));
        Gobang->resize(800, 480);
        Gobang->setStyleSheet(QStringLiteral("QMainWindow{border-image: url(:/image/wuziqi.jpg);}"));
        centralwidget = new QWidget(Gobang);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gameStatus = new QLabel(centralwidget);
        gameStatus->setObjectName(QStringLiteral("gameStatus"));
        gameStatus->setGeometry(QRect(670, 169, 101, 21));
        regret = new QPushButton(centralwidget);
        regret->setObjectName(QStringLiteral("regret"));
        regret->setGeometry(QRect(670, 269, 101, 51));
        regret->setFocusPolicy(Qt::NoFocus);
        restart = new QPushButton(centralwidget);
        restart->setObjectName(QStringLiteral("restart"));
        restart->setGeometry(QRect(670, 210, 101, 51));
        restart->setFocusPolicy(Qt::NoFocus);
        who = new QLabel(centralwidget);
        who->setObjectName(QStringLiteral("who"));
        who->setGeometry(QRect(670, 109, 101, 31));
        back_regret = new QPushButton(centralwidget);
        back_regret->setObjectName(QStringLiteral("back_regret"));
        back_regret->setGeometry(QRect(670, 330, 101, 51));
        back_regret->setFocusPolicy(Qt::NoFocus);
        Gobang->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Gobang);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Gobang->setMenuBar(menubar);
        statusbar = new QStatusBar(Gobang);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Gobang->setStatusBar(statusbar);

        retranslateUi(Gobang);

        QMetaObject::connectSlotsByName(Gobang);
    } // setupUi

    void retranslateUi(QMainWindow *Gobang)
    {
        Gobang->setWindowTitle(QApplication::translate("Gobang", "MainWindow", 0));
        gameStatus->setText(QApplication::translate("Gobang", "\346\243\213\345\261\200\350\277\233\350\241\214\344\270\255", 0));
        regret->setText(QApplication::translate("Gobang", "\346\202\224\346\243\213", 0));
        restart->setText(QApplication::translate("Gobang", "\351\207\215\346\226\260\345\274\200\345\261\200", 0));
        who->setText(QApplication::translate("Gobang", "\350\257\267\347\231\275\346\243\213\350\220\275\345\255\220", 0));
        back_regret->setText(QApplication::translate("Gobang", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class Gobang: public Ui_Gobang {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOBANG_H
