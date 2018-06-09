/****************************************************************************
** Meta object code from reading C++ file 'managerlogin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../managerlogin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'managerlogin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_managerLogin_t {
    QByteArrayData data[8];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_managerLogin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_managerLogin_t qt_meta_stringdata_managerLogin = {
    {
QT_MOC_LITERAL(0, 0, 12), // "managerLogin"
QT_MOC_LITERAL(1, 13, 10), // "ShowSignal"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "CloseSignal"
QT_MOC_LITERAL(4, 37, 18), // "ManagerLoginSignal"
QT_MOC_LITERAL(5, 56, 23), // "on_returnButton_clicked"
QT_MOC_LITERAL(6, 80, 17), // "enableLoginButton"
QT_MOC_LITERAL(7, 98, 22) // "on_loginButton_clicked"

    },
    "managerLogin\0ShowSignal\0\0CloseSignal\0"
    "ManagerLoginSignal\0on_returnButton_clicked\0"
    "enableLoginButton\0on_loginButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_managerLogin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       7,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void managerLogin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        managerLogin *_t = static_cast<managerLogin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowSignal(); break;
        case 1: _t->CloseSignal(); break;
        case 2: _t->ManagerLoginSignal(); break;
        case 3: _t->on_returnButton_clicked(); break;
        case 4: _t->enableLoginButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_loginButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (managerLogin::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&managerLogin::ShowSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (managerLogin::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&managerLogin::CloseSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (managerLogin::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&managerLogin::ManagerLoginSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject managerLogin::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_managerLogin.data,
      qt_meta_data_managerLogin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *managerLogin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *managerLogin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_managerLogin.stringdata0))
        return static_cast<void*>(const_cast< managerLogin*>(this));
    return QDialog::qt_metacast(_clname);
}

int managerLogin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void managerLogin::ShowSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void managerLogin::CloseSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void managerLogin::ManagerLoginSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
