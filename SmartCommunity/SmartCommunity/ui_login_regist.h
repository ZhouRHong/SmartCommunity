/********************************************************************************
** Form generated from reading UI file 'login_regist.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_REGIST_H
#define UI_LOGIN_REGIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login_regist
{
public:
    QWidget *centralwidget;
    QPushButton *login_Button;
    QPushButton *regist_Button;
    QLineEdit *account_Edit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *passwd_Edit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login_regist)
    {
        if (Login_regist->objectName().isEmpty())
            Login_regist->setObjectName(QStringLiteral("Login_regist"));
        Login_regist->resize(800, 480);
        Login_regist->setStyleSheet(QStringLiteral("QMainWindow{border-image: url(:/image/city.jpg);}"));
        centralwidget = new QWidget(Login_regist);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        login_Button = new QPushButton(centralwidget);
        login_Button->setObjectName(QStringLiteral("login_Button"));
        login_Button->setGeometry(QRect(430, 280, 111, 41));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        login_Button->setFont(font);
        regist_Button = new QPushButton(centralwidget);
        regist_Button->setObjectName(QStringLiteral("regist_Button"));
        regist_Button->setGeometry(QRect(240, 280, 111, 41));
        regist_Button->setFont(font);
        account_Edit = new QLineEdit(centralwidget);
        account_Edit->setObjectName(QStringLiteral("account_Edit"));
        account_Edit->setGeometry(QRect(300, 140, 241, 41));
        account_Edit->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 150, 41, 31));
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(250, 190, 41, 31));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        passwd_Edit = new QLineEdit(centralwidget);
        passwd_Edit->setObjectName(QStringLiteral("passwd_Edit"));
        passwd_Edit->setGeometry(QRect(300, 190, 241, 41));
        passwd_Edit->setFont(font);
        passwd_Edit->setEchoMode(QLineEdit::Password);
        Login_regist->setCentralWidget(centralwidget);
        login_Button->raise();
        regist_Button->raise();
        passwd_Edit->raise();
        account_Edit->raise();
        label->raise();
        label_2->raise();
        menubar = new QMenuBar(Login_regist);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Login_regist->setMenuBar(menubar);
        statusbar = new QStatusBar(Login_regist);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Login_regist->setStatusBar(statusbar);

        retranslateUi(Login_regist);

        QMetaObject::connectSlotsByName(Login_regist);
    } // setupUi

    void retranslateUi(QMainWindow *Login_regist)
    {
        Login_regist->setWindowTitle(QApplication::translate("Login_regist", "MainWindow", 0));
        login_Button->setText(QApplication::translate("Login_regist", "\347\231\273\345\275\225", 0));
        regist_Button->setText(QApplication::translate("Login_regist", "\346\263\250\345\206\214", 0));
        account_Edit->setText(QApplication::translate("Login_regist", "root", 0));
        account_Edit->setPlaceholderText(QApplication::translate("Login_regist", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", 0));
        label->setText(QApplication::translate("Login_regist", "\350\264\246\345\217\267\357\274\232", 0));
        label_2->setText(QApplication::translate("Login_regist", "\345\257\206\347\240\201\357\274\232", 0));
        passwd_Edit->setText(QApplication::translate("Login_regist", "123123", 0));
        passwd_Edit->setPlaceholderText(QApplication::translate("Login_regist", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0));
    } // retranslateUi

};

namespace Ui {
    class Login_regist: public Ui_Login_regist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_REGIST_H
