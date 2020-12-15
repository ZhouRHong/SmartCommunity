/****************************************************************************
** Meta object code from reading C++ file 'menu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "menu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Menu_t {
    QByteArrayData data[21];
    char stringdata0[307];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Menu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Menu_t qt_meta_stringdata_Menu = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Menu"
QT_MOC_LITERAL(1, 5, 8), // "sendport"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 4), // "port"
QT_MOC_LITERAL(4, 20, 10), // "updateTime"
QT_MOC_LITERAL(5, 31, 7), // "advplay"
QT_MOC_LITERAL(6, 39, 9), // "read_data"
QT_MOC_LITERAL(7, 49, 14), // "QNetworkReply*"
QT_MOC_LITERAL(8, 64, 5), // "reply"
QT_MOC_LITERAL(9, 70, 10), // "video_auto"
QT_MOC_LITERAL(10, 81, 8), // "exitCode"
QT_MOC_LITERAL(11, 90, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(12, 111, 10), // "exitStatus"
QT_MOC_LITERAL(13, 122, 27), // "on_light_pushButton_clicked"
QT_MOC_LITERAL(14, 150, 25), // "on_fix_pushButton_clicked"
QT_MOC_LITERAL(15, 176, 26), // "on_game_pushButton_clicked"
QT_MOC_LITERAL(16, 203, 26), // "on_back_pushButton_clicked"
QT_MOC_LITERAL(17, 230, 12), // "beginCapture"
QT_MOC_LITERAL(18, 243, 9), // "flushBuff"
QT_MOC_LITERAL(19, 253, 27), // "on_start_pushButton_clicked"
QT_MOC_LITERAL(20, 281, 25) // "on_all_pushButton_clicked"

    },
    "Menu\0sendport\0\0port\0updateTime\0advplay\0"
    "read_data\0QNetworkReply*\0reply\0"
    "video_auto\0exitCode\0QProcess::ExitStatus\0"
    "exitStatus\0on_light_pushButton_clicked\0"
    "on_fix_pushButton_clicked\0"
    "on_game_pushButton_clicked\0"
    "on_back_pushButton_clicked\0beginCapture\0"
    "flushBuff\0on_start_pushButton_clicked\0"
    "on_all_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Menu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   82,    2, 0x08 /* Private */,
       5,    0,   83,    2, 0x08 /* Private */,
       6,    1,   84,    2, 0x08 /* Private */,
       9,    2,   87,    2, 0x08 /* Private */,
      13,    0,   92,    2, 0x08 /* Private */,
      14,    0,   93,    2, 0x08 /* Private */,
      15,    0,   94,    2, 0x08 /* Private */,
      16,    0,   95,    2, 0x08 /* Private */,
      17,    0,   96,    2, 0x08 /* Private */,
      18,    0,   97,    2, 0x08 /* Private */,
      19,    0,   98,    2, 0x08 /* Private */,
      20,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Short,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 11,   10,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Menu *_t = static_cast<Menu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendport((*reinterpret_cast< qint16(*)>(_a[1]))); break;
        case 1: _t->updateTime(); break;
        case 2: _t->advplay(); break;
        case 3: _t->read_data((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->video_auto((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 5: _t->on_light_pushButton_clicked(); break;
        case 6: _t->on_fix_pushButton_clicked(); break;
        case 7: _t->on_game_pushButton_clicked(); break;
        case 8: _t->on_back_pushButton_clicked(); break;
        case 9: _t->beginCapture(); break;
        case 10: _t->flushBuff(); break;
        case 11: _t->on_start_pushButton_clicked(); break;
        case 12: _t->on_all_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Menu::*_t)(qint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Menu::sendport)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Menu::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Menu.data,
      qt_meta_data_Menu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Menu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Menu.stringdata0))
        return static_cast<void*>(const_cast< Menu*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Menu::sendport(qint16 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
