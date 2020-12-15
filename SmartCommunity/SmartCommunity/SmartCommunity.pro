#-------------------------------------------------
#
# Project created by QtCreator 2020-11-28T14:41:26
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartCommunity
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        all_screen.cpp \
        fix.cpp \
        games_show.cpp \
        gobang.cpp \
        login_regist.cpp \
        main.cpp \
        mainwindow.cpp \
        menu.cpp \
        regist.cpp \
        softkeyboard.cpp \
        v4l2.cpp \
        weather_form.cpp

HEADERS += \
        all_screen.h \
        fix.h \
        games_show.h \
        gobang.h \
        login_regist.h \
        mainwindow.h \
        menu.h \
        regist.h \
        softkeyboard.h \
        v4l2.h \
        weather_form.h

FORMS += \
        all_screen.ui \
        fix.ui \
        games_show.ui \
        gobang.ui \
        login_regist.ui \
        mainwindow.ui \
        menu.ui \
        regist.ui \
        weather_form.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \
    res1.qrc
