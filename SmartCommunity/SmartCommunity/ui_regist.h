/********************************************************************************
** Form generated from reading UI file 'regist.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGIST_H
#define UI_REGIST_H

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

class Ui_Regist
{
public:
    QWidget *centralwidget;
    QLineEdit *passwd_Edit;
    QLineEdit *account_Edit;
    QPushButton *ok_Button;
    QPushButton *back_Button;
    QLineEdit *pass2_Edit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Regist)
    {
        if (Regist->objectName().isEmpty())
            Regist->setObjectName(QStringLiteral("Regist"));
        Regist->resize(800, 480);
        Regist->setStyleSheet(QLatin1String("QMainWindow{border-image: url(:/image/timg.png);}\n"
""));
        centralwidget = new QWidget(Regist);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        passwd_Edit = new QLineEdit(centralwidget);
        passwd_Edit->setObjectName(QStringLiteral("passwd_Edit"));
        passwd_Edit->setGeometry(QRect(330, 170, 211, 41));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        passwd_Edit->setFont(font);
        account_Edit = new QLineEdit(centralwidget);
        account_Edit->setObjectName(QStringLiteral("account_Edit"));
        account_Edit->setGeometry(QRect(330, 110, 211, 41));
        account_Edit->setFont(font);
        ok_Button = new QPushButton(centralwidget);
        ok_Button->setObjectName(QStringLiteral("ok_Button"));
        ok_Button->setGeometry(QRect(270, 300, 81, 31));
        ok_Button->setFont(font);
        back_Button = new QPushButton(centralwidget);
        back_Button->setObjectName(QStringLiteral("back_Button"));
        back_Button->setGeometry(QRect(450, 300, 81, 31));
        back_Button->setFont(font);
        pass2_Edit = new QLineEdit(centralwidget);
        pass2_Edit->setObjectName(QStringLiteral("pass2_Edit"));
        pass2_Edit->setGeometry(QRect(330, 230, 211, 41));
        pass2_Edit->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(240, 120, 81, 31));
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(240, 180, 81, 31));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(240, 240, 81, 31));
        label_3->setFont(font);
        Regist->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Regist);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Regist->setMenuBar(menubar);
        statusbar = new QStatusBar(Regist);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Regist->setStatusBar(statusbar);

        retranslateUi(Regist);

        QMetaObject::connectSlotsByName(Regist);
    } // setupUi

    void retranslateUi(QMainWindow *Regist)
    {
        Regist->setWindowTitle(QApplication::translate("Regist", "MainWindow", 0));
        ok_Button->setText(QApplication::translate("Regist", "\347\241\256\350\256\244", 0));
        back_Button->setText(QApplication::translate("Regist", "\350\277\224\345\233\236", 0));
        label->setText(QApplication::translate("Regist", "\350\264\246    \345\217\267\357\274\232", 0));
        label_2->setText(QApplication::translate("Regist", "\345\257\206    \347\240\201\357\274\232", 0));
        label_3->setText(QApplication::translate("Regist", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class Regist: public Ui_Regist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGIST_H
