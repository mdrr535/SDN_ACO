/****************************************************************************
** Meta object code from reading C++ file 'CommandReceiver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Network/CommandReceiver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CommandReceiver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CommandReceiver_t {
    QByteArrayData data[23];
    char stringdata0[290];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CommandReceiver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CommandReceiver_t qt_meta_stringdata_CommandReceiver = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CommandReceiver"
QT_MOC_LITERAL(1, 16, 18), // "signalPathReceived"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 10), // "QList<int>"
QT_MOC_LITERAL(4, 47, 4), // "path"
QT_MOC_LITERAL(5, 52, 19), // "signalPathsReceived"
QT_MOC_LITERAL(6, 72, 18), // "QList<QList<int> >"
QT_MOC_LITERAL(7, 91, 5), // "paths"
QT_MOC_LITERAL(8, 97, 16), // "signalPTReceived"
QT_MOC_LITERAL(9, 114, 2), // "pt"
QT_MOC_LITERAL(10, 117, 20), // "signalMetricReceived"
QT_MOC_LITERAL(11, 138, 14), // "QVector<float>"
QT_MOC_LITERAL(12, 153, 10), // "metricData"
QT_MOC_LITERAL(13, 164, 21), // "signalMessageReceived"
QT_MOC_LITERAL(14, 186, 7), // "message"
QT_MOC_LITERAL(15, 194, 18), // "signalTreeReceived"
QT_MOC_LITERAL(16, 213, 4), // "tree"
QT_MOC_LITERAL(17, 218, 19), // "signalTreesReceived"
QT_MOC_LITERAL(18, 238, 26), // "QList<QList<QList<int> > >"
QT_MOC_LITERAL(19, 265, 5), // "trees"
QT_MOC_LITERAL(20, 271, 2), // "on"
QT_MOC_LITERAL(21, 274, 10), // "handleData"
QT_MOC_LITERAL(22, 285, 4) // "data"

    },
    "CommandReceiver\0signalPathReceived\0\0"
    "QList<int>\0path\0signalPathsReceived\0"
    "QList<QList<int> >\0paths\0signalPTReceived\0"
    "pt\0signalMetricReceived\0QVector<float>\0"
    "metricData\0signalMessageReceived\0"
    "message\0signalTreeReceived\0tree\0"
    "signalTreesReceived\0QList<QList<QList<int> > >\0"
    "trees\0on\0handleData\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommandReceiver[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,
       8,    1,   65,    2, 0x06 /* Public */,
      10,    1,   68,    2, 0x06 /* Public */,
      13,    1,   71,    2, 0x06 /* Public */,
      15,    1,   74,    2, 0x06 /* Public */,
      17,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    0,   80,    2, 0x0a /* Public */,
      21,    1,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, 0x80000000 | 6,   16,
    QMetaType::Void, 0x80000000 | 18,   19,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   22,

       0        // eod
};

void CommandReceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CommandReceiver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalPathReceived((*reinterpret_cast< QList<int>(*)>(_a[1]))); break;
        case 1: _t->signalPathsReceived((*reinterpret_cast< QList<QList<int> >(*)>(_a[1]))); break;
        case 2: _t->signalPTReceived((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->signalMetricReceived((*reinterpret_cast< QVector<float>(*)>(_a[1]))); break;
        case 4: _t->signalMessageReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->signalTreeReceived((*reinterpret_cast< QList<QList<int> >(*)>(_a[1]))); break;
        case 6: _t->signalTreesReceived((*reinterpret_cast< QList<QList<QList<int> > >(*)>(_a[1]))); break;
        case 7: _t->on(); break;
        case 8: _t->handleData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QList<int> > >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<float> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QList<int> > >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QList<QList<int> > > >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CommandReceiver::*)(QList<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommandReceiver::signalPathReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CommandReceiver::*)(QList<QList<int> > );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommandReceiver::signalPathsReceived)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CommandReceiver::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommandReceiver::signalPTReceived)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CommandReceiver::*)(QVector<float> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommandReceiver::signalMetricReceived)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CommandReceiver::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommandReceiver::signalMessageReceived)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CommandReceiver::*)(QList<QList<int>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommandReceiver::signalTreeReceived)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CommandReceiver::*)(QList<QList<QList<int> > > );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommandReceiver::signalTreesReceived)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CommandReceiver::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CommandReceiver.data,
    qt_meta_data_CommandReceiver,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CommandReceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommandReceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CommandReceiver.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CommandReceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CommandReceiver::signalPathReceived(QList<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CommandReceiver::signalPathsReceived(QList<QList<int> > _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CommandReceiver::signalPTReceived(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CommandReceiver::signalMetricReceived(QVector<float> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CommandReceiver::signalMessageReceived(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CommandReceiver::signalTreeReceived(QList<QList<int>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CommandReceiver::signalTreesReceived(QList<QList<QList<int> > > _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
