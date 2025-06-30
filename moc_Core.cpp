/****************************************************************************
** Meta object code from reading C++ file 'Core.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Core/Core.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Core.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Core_t {
    QByteArrayData data[51];
    char stringdata0[731];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Core_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Core_t qt_meta_stringdata_Core = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Core"
QT_MOC_LITERAL(1, 5, 27), // "signalRefreshNetworkMapView"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 17), // "signalShowMessage"
QT_MOC_LITERAL(4, 52, 7), // "message"
QT_MOC_LITERAL(5, 60, 20), // "connectSdnController"
QT_MOC_LITERAL(6, 81, 15), // "clearNetworkMap"
QT_MOC_LITERAL(7, 97, 23), // "handleMouseReleaseEvent"
QT_MOC_LITERAL(8, 121, 21), // "handleMousePressEvent"
QT_MOC_LITERAL(9, 143, 20), // "handleMouseMoveEvent"
QT_MOC_LITERAL(10, 164, 22), // "handleDoubleClickEvent"
QT_MOC_LITERAL(11, 187, 25), // "handleKeyDeletePressEvent"
QT_MOC_LITERAL(12, 213, 17), // "changeStateToEdit"
QT_MOC_LITERAL(13, 231, 20), // "prepareSdnController"
QT_MOC_LITERAL(14, 252, 11), // "prepareHost"
QT_MOC_LITERAL(15, 264, 13), // "prepareSwitch"
QT_MOC_LITERAL(16, 278, 11), // "prepareLink"
QT_MOC_LITERAL(17, 290, 16), // "prepareTextLabel"
QT_MOC_LITERAL(18, 307, 9), // "showPorts"
QT_MOC_LITERAL(19, 317, 13), // "showBandwidth"
QT_MOC_LITERAL(20, 331, 9), // "showDelay"
QT_MOC_LITERAL(21, 341, 18), // "showPacketLossRate"
QT_MOC_LITERAL(22, 360, 19), // "createMininetScript"
QT_MOC_LITERAL(23, 380, 19), // "createWeightsMatrix"
QT_MOC_LITERAL(24, 400, 4), // "path"
QT_MOC_LITERAL(25, 405, 14), // "saveNetworkMap"
QT_MOC_LITERAL(26, 420, 14), // "loadNetworkMap"
QT_MOC_LITERAL(27, 435, 13), // "visualizePath"
QT_MOC_LITERAL(28, 449, 10), // "QList<int>"
QT_MOC_LITERAL(29, 460, 14), // "visualizePaths"
QT_MOC_LITERAL(30, 475, 18), // "QList<QList<int> >"
QT_MOC_LITERAL(31, 494, 5), // "paths"
QT_MOC_LITERAL(32, 500, 13), // "visualizeTree"
QT_MOC_LITERAL(33, 514, 4), // "tree"
QT_MOC_LITERAL(34, 519, 14), // "visualizeTrees"
QT_MOC_LITERAL(35, 534, 26), // "QList<QList<QList<int> > >"
QT_MOC_LITERAL(36, 561, 5), // "trees"
QT_MOC_LITERAL(37, 567, 10), // "eraseMarks"
QT_MOC_LITERAL(38, 578, 12), // "changeMetric"
QT_MOC_LITERAL(39, 591, 14), // "QVector<float>"
QT_MOC_LITERAL(40, 606, 10), // "metricData"
QT_MOC_LITERAL(41, 617, 21), // "runAntColonyAlgorithm"
QT_MOC_LITERAL(42, 639, 7), // "numAnts"
QT_MOC_LITERAL(43, 647, 13), // "numIterations"
QT_MOC_LITERAL(44, 661, 5), // "alpha"
QT_MOC_LITERAL(45, 667, 4), // "beta"
QT_MOC_LITERAL(46, 672, 11), // "evaporation"
QT_MOC_LITERAL(47, 684, 1), // "Q"
QT_MOC_LITERAL(48, 686, 11), // "startSwitch"
QT_MOC_LITERAL(49, 698, 9), // "endSwitch"
QT_MOC_LITERAL(50, 708, 22) // "antColonyAnimationStep"

    },
    "Core\0signalRefreshNetworkMapView\0\0"
    "signalShowMessage\0message\0"
    "connectSdnController\0clearNetworkMap\0"
    "handleMouseReleaseEvent\0handleMousePressEvent\0"
    "handleMouseMoveEvent\0handleDoubleClickEvent\0"
    "handleKeyDeletePressEvent\0changeStateToEdit\0"
    "prepareSdnController\0prepareHost\0"
    "prepareSwitch\0prepareLink\0prepareTextLabel\0"
    "showPorts\0showBandwidth\0showDelay\0"
    "showPacketLossRate\0createMininetScript\0"
    "createWeightsMatrix\0path\0saveNetworkMap\0"
    "loadNetworkMap\0visualizePath\0QList<int>\0"
    "visualizePaths\0QList<QList<int> >\0"
    "paths\0visualizeTree\0tree\0visualizeTrees\0"
    "QList<QList<QList<int> > >\0trees\0"
    "eraseMarks\0changeMetric\0QVector<float>\0"
    "metricData\0runAntColonyAlgorithm\0"
    "numAnts\0numIterations\0alpha\0beta\0"
    "evaporation\0Q\0startSwitch\0endSwitch\0"
    "antColonyAnimationStep"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Core[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  169,    2, 0x06 /* Public */,
       3,    1,  172,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  175,    2, 0x0a /* Public */,
       6,    0,  176,    2, 0x0a /* Public */,
       7,    1,  177,    2, 0x0a /* Public */,
       8,    1,  180,    2, 0x0a /* Public */,
       9,    1,  183,    2, 0x0a /* Public */,
      10,    1,  186,    2, 0x0a /* Public */,
      11,    0,  189,    2, 0x0a /* Public */,
      12,    0,  190,    2, 0x0a /* Public */,
      13,    0,  191,    2, 0x0a /* Public */,
      14,    0,  192,    2, 0x0a /* Public */,
      15,    0,  193,    2, 0x0a /* Public */,
      16,    0,  194,    2, 0x0a /* Public */,
      17,    0,  195,    2, 0x0a /* Public */,
      18,    1,  196,    2, 0x0a /* Public */,
      19,    0,  199,    2, 0x0a /* Public */,
      20,    0,  200,    2, 0x0a /* Public */,
      21,    0,  201,    2, 0x0a /* Public */,
      22,    1,  202,    2, 0x0a /* Public */,
      23,    1,  205,    2, 0x0a /* Public */,
      25,    1,  208,    2, 0x0a /* Public */,
      26,    1,  211,    2, 0x0a /* Public */,
      27,    1,  214,    2, 0x0a /* Public */,
      29,    1,  217,    2, 0x0a /* Public */,
      32,    1,  220,    2, 0x0a /* Public */,
      34,    1,  223,    2, 0x0a /* Public */,
      37,    0,  226,    2, 0x0a /* Public */,
      38,    1,  227,    2, 0x0a /* Public */,
      41,    8,  230,    2, 0x0a /* Public */,
      50,    0,  247,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 28,   24,
    QMetaType::Void, 0x80000000 | 30,   31,
    QMetaType::Void, 0x80000000 | 30,   33,
    QMetaType::Void, 0x80000000 | 35,   36,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 39,   40,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QString, QMetaType::QString,   42,   43,   44,   45,   46,   47,   48,   49,
    QMetaType::Void,

       0        // eod
};

void Core::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Core *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalRefreshNetworkMapView((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 1: _t->signalShowMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->connectSdnController(); break;
        case 3: _t->clearNetworkMap(); break;
        case 4: _t->handleMouseReleaseEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: _t->handleMousePressEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 6: _t->handleMouseMoveEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 7: _t->handleDoubleClickEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 8: _t->handleKeyDeletePressEvent(); break;
        case 9: _t->changeStateToEdit(); break;
        case 10: _t->prepareSdnController(); break;
        case 11: _t->prepareHost(); break;
        case 12: _t->prepareSwitch(); break;
        case 13: _t->prepareLink(); break;
        case 14: _t->prepareTextLabel(); break;
        case 15: _t->showPorts((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->showBandwidth(); break;
        case 17: _t->showDelay(); break;
        case 18: _t->showPacketLossRate(); break;
        case 19: _t->createMininetScript((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->createWeightsMatrix((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->saveNetworkMap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: _t->loadNetworkMap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->visualizePath((*reinterpret_cast< QList<int>(*)>(_a[1]))); break;
        case 24: _t->visualizePaths((*reinterpret_cast< QList<QList<int> >(*)>(_a[1]))); break;
        case 25: _t->visualizeTree((*reinterpret_cast< QList<QList<int> >(*)>(_a[1]))); break;
        case 26: _t->visualizeTrees((*reinterpret_cast< QList<QList<QList<int> > >(*)>(_a[1]))); break;
        case 27: _t->eraseMarks(); break;
        case 28: _t->changeMetric((*reinterpret_cast< QVector<float>(*)>(_a[1]))); break;
        case 29: _t->runAntColonyAlgorithm((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8]))); break;
        case 30: _t->antColonyAnimationStep(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 23:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        case 24:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QList<int> > >(); break;
            }
            break;
        case 25:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QList<int> > >(); break;
            }
            break;
        case 26:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QList<QList<int> > > >(); break;
            }
            break;
        case 28:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<float> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Core::*)(QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Core::signalRefreshNetworkMapView)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Core::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Core::signalShowMessage)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Core::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Core.data,
    qt_meta_data_Core,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Core::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Core::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Core.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Core::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    }
    return _id;
}

// SIGNAL 0
void Core::signalRefreshNetworkMapView(QPixmap _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Core::signalShowMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
