/********************************************************************************
** Form generated from reading UI file 'fix.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIX_H
#define UI_FIX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fix
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Fix)
    {
        if (Fix->objectName().isEmpty())
            Fix->setObjectName(QStringLiteral("Fix"));
        Fix->resize(800, 480);
        centralwidget = new QWidget(Fix);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Fix->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Fix);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Fix->setMenuBar(menubar);
        statusbar = new QStatusBar(Fix);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Fix->setStatusBar(statusbar);

        retranslateUi(Fix);

        QMetaObject::connectSlotsByName(Fix);
    } // setupUi

    void retranslateUi(QMainWindow *Fix)
    {
        Fix->setWindowTitle(QApplication::translate("Fix", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class Fix: public Ui_Fix {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIX_H
