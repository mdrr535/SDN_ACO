/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "UI/MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[54];
    char stringdata0[1276];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 26), // "signalConnectSdnController"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 21), // "signalClearNetworkMap"
QT_MOC_LITERAL(4, 61, 29), // "signalHandleMouseReleaseEvent"
QT_MOC_LITERAL(5, 91, 27), // "signalHandleMousePressEvent"
QT_MOC_LITERAL(6, 119, 26), // "signalHandleMouseMoveEvent"
QT_MOC_LITERAL(7, 146, 28), // "signalHandleDoubleClickEvent"
QT_MOC_LITERAL(8, 175, 31), // "signalHandleKeyDeletePressEvent"
QT_MOC_LITERAL(9, 207, 23), // "signalChangeStateToEdit"
QT_MOC_LITERAL(10, 231, 26), // "signalPrepareSdnController"
QT_MOC_LITERAL(11, 258, 17), // "signalPrepareHost"
QT_MOC_LITERAL(12, 276, 19), // "signalPrepareSwitch"
QT_MOC_LITERAL(13, 296, 17), // "signalPrepareLink"
QT_MOC_LITERAL(14, 314, 22), // "signalPrepareTextLabel"
QT_MOC_LITERAL(15, 337, 15), // "signalShowPorts"
QT_MOC_LITERAL(16, 353, 19), // "signalShowBandwidth"
QT_MOC_LITERAL(17, 373, 15), // "signalShowDelay"
QT_MOC_LITERAL(18, 389, 24), // "signalShowPacketLossRate"
QT_MOC_LITERAL(19, 414, 25), // "signalCreateMininetScript"
QT_MOC_LITERAL(20, 440, 24), // "signalCreateWeightMatrix"
QT_MOC_LITERAL(21, 465, 10), // "loadRoutes"
QT_MOC_LITERAL(22, 476, 9), // "showRoute"
QT_MOC_LITERAL(23, 486, 9), // "hideRoute"
QT_MOC_LITERAL(24, 496, 20), // "signalSaveNetworkMap"
QT_MOC_LITERAL(25, 517, 20), // "signalLoadNetworkMap"
QT_MOC_LITERAL(26, 538, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(27, 561, 39), // "on_actionMake_Full_Connection..."
QT_MOC_LITERAL(28, 601, 32), // "on_actionSdnController_triggered"
QT_MOC_LITERAL(29, 634, 23), // "on_actionHost_triggered"
QT_MOC_LITERAL(30, 658, 25), // "on_actionSwitch_triggered"
QT_MOC_LITERAL(31, 684, 23), // "on_actionLink_triggered"
QT_MOC_LITERAL(32, 708, 23), // "on_actionText_triggered"
QT_MOC_LITERAL(33, 732, 23), // "on_actionEdit_triggered"
QT_MOC_LITERAL(34, 756, 34), // "mouseLeftButtonReleaseEventOc..."
QT_MOC_LITERAL(35, 791, 14), // "cursorPosition"
QT_MOC_LITERAL(36, 806, 32), // "mouseLeftButtonPressEventOccured"
QT_MOC_LITERAL(37, 839, 21), // "mouseMoveEventOccured"
QT_MOC_LITERAL(38, 861, 28), // "mouseDoubleClickEventOccured"
QT_MOC_LITERAL(39, 890, 28), // "on_actionShowPorts_triggered"
QT_MOC_LITERAL(40, 919, 7), // "checked"
QT_MOC_LITERAL(41, 927, 31), // "on_actionDisplayDelay_triggered"
QT_MOC_LITERAL(42, 959, 35), // "on_actionDisplayBandwidth_tri..."
QT_MOC_LITERAL(43, 995, 36), // "on_actionDisplayPacketLoss_tr..."
QT_MOC_LITERAL(44, 1032, 25), // "on_actionSaveAs_triggered"
QT_MOC_LITERAL(45, 1058, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(46, 1082, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(47, 1106, 35), // "on_actionCreateMnDataFile_tri..."
QT_MOC_LITERAL(48, 1142, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(49, 1166, 33), // "on_actionWeights_Matrix_trigg..."
QT_MOC_LITERAL(50, 1200, 33), // "on_actionRun_Ant_Colony_trigg..."
QT_MOC_LITERAL(51, 1234, 21), // "refreshNetworkMapView"
QT_MOC_LITERAL(52, 1256, 11), // "showMessage"
QT_MOC_LITERAL(53, 1268, 7) // "message"

    },
    "MainWindow\0signalConnectSdnController\0"
    "\0signalClearNetworkMap\0"
    "signalHandleMouseReleaseEvent\0"
    "signalHandleMousePressEvent\0"
    "signalHandleMouseMoveEvent\0"
    "signalHandleDoubleClickEvent\0"
    "signalHandleKeyDeletePressEvent\0"
    "signalChangeStateToEdit\0"
    "signalPrepareSdnController\0signalPrepareHost\0"
    "signalPrepareSwitch\0signalPrepareLink\0"
    "signalPrepareTextLabel\0signalShowPorts\0"
    "signalShowBandwidth\0signalShowDelay\0"
    "signalShowPacketLossRate\0"
    "signalCreateMininetScript\0"
    "signalCreateWeightMatrix\0loadRoutes\0"
    "showRoute\0hideRoute\0signalSaveNetworkMap\0"
    "signalLoadNetworkMap\0on_actionNew_triggered\0"
    "on_actionMake_Full_Connection_triggered\0"
    "on_actionSdnController_triggered\0"
    "on_actionHost_triggered\0"
    "on_actionSwitch_triggered\0"
    "on_actionLink_triggered\0on_actionText_triggered\0"
    "on_actionEdit_triggered\0"
    "mouseLeftButtonReleaseEventOccured\0"
    "cursorPosition\0mouseLeftButtonPressEventOccured\0"
    "mouseMoveEventOccured\0"
    "mouseDoubleClickEventOccured\0"
    "on_actionShowPorts_triggered\0checked\0"
    "on_actionDisplayDelay_triggered\0"
    "on_actionDisplayBandwidth_triggered\0"
    "on_actionDisplayPacketLoss_triggered\0"
    "on_actionSaveAs_triggered\0"
    "on_actionSave_triggered\0on_actionOpen_triggered\0"
    "on_actionCreateMnDataFile_triggered\0"
    "on_actionExit_triggered\0"
    "on_actionWeights_Matrix_triggered\0"
    "on_actionRun_Ant_Colony_triggered\0"
    "refreshNetworkMapView\0showMessage\0"
    "message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      49,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      24,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  259,    2, 0x06 /* Public */,
       3,    0,  260,    2, 0x06 /* Public */,
       4,    1,  261,    2, 0x06 /* Public */,
       5,    1,  264,    2, 0x06 /* Public */,
       6,    1,  267,    2, 0x06 /* Public */,
       7,    1,  270,    2, 0x06 /* Public */,
       8,    0,  273,    2, 0x06 /* Public */,
       9,    0,  274,    2, 0x06 /* Public */,
      10,    0,  275,    2, 0x06 /* Public */,
      11,    0,  276,    2, 0x06 /* Public */,
      12,    0,  277,    2, 0x06 /* Public */,
      13,    0,  278,    2, 0x06 /* Public */,
      14,    0,  279,    2, 0x06 /* Public */,
      15,    1,  280,    2, 0x06 /* Public */,
      16,    0,  283,    2, 0x06 /* Public */,
      17,    0,  284,    2, 0x06 /* Public */,
      18,    0,  285,    2, 0x06 /* Public */,
      19,    1,  286,    2, 0x06 /* Public */,
      20,    1,  289,    2, 0x06 /* Public */,
      21,    1,  292,    2, 0x06 /* Public */,
      22,    1,  295,    2, 0x06 /* Public */,
      23,    1,  298,    2, 0x06 /* Public */,
      24,    1,  301,    2, 0x06 /* Public */,
      25,    1,  304,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      26,    0,  307,    2, 0x08 /* Private */,
      27,    0,  308,    2, 0x08 /* Private */,
      28,    0,  309,    2, 0x08 /* Private */,
      29,    0,  310,    2, 0x08 /* Private */,
      30,    0,  311,    2, 0x08 /* Private */,
      31,    0,  312,    2, 0x08 /* Private */,
      32,    0,  313,    2, 0x08 /* Private */,
      33,    0,  314,    2, 0x08 /* Private */,
      34,    1,  315,    2, 0x08 /* Private */,
      36,    1,  318,    2, 0x08 /* Private */,
      37,    1,  321,    2, 0x08 /* Private */,
      38,    1,  324,    2, 0x08 /* Private */,
      39,    1,  327,    2, 0x08 /* Private */,
      41,    0,  330,    2, 0x08 /* Private */,
      42,    0,  331,    2, 0x08 /* Private */,
      43,    0,  332,    2, 0x08 /* Private */,
      44,    0,  333,    2, 0x08 /* Private */,
      45,    0,  334,    2, 0x08 /* Private */,
      46,    0,  335,    2, 0x08 /* Private */,
      47,    0,  336,    2, 0x08 /* Private */,
      48,    0,  337,    2, 0x08 /* Private */,
      49,    0,  338,    2, 0x08 /* Private */,
      50,    0,  339,    2, 0x08 /* Private */,
      51,    1,  340,    2, 0x0a /* Public */,
      52,    1,  343,    2, 0x0a /* Public */,

 // signals: parameters
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
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   35,
    QMetaType::Void, QMetaType::QPoint,   35,
    QMetaType::Void, QMetaType::QPoint,   35,
    QMetaType::Void, QMetaType::QPoint,   35,
    QMetaType::Void, QMetaType::Bool,   40,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void, QMetaType::QString,   53,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalConnectSdnController(); break;
        case 1: _t->signalClearNetworkMap(); break;
        case 2: _t->signalHandleMouseReleaseEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 3: _t->signalHandleMousePressEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: _t->signalHandleMouseMoveEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: _t->signalHandleDoubleClickEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 6: _t->signalHandleKeyDeletePressEvent(); break;
        case 7: _t->signalChangeStateToEdit(); break;
        case 8: _t->signalPrepareSdnController(); break;
        case 9: _t->signalPrepareHost(); break;
        case 10: _t->signalPrepareSwitch(); break;
        case 11: _t->signalPrepareLink(); break;
        case 12: _t->signalPrepareTextLabel(); break;
        case 13: _t->signalShowPorts((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->signalShowBandwidth(); break;
        case 15: _t->signalShowDelay(); break;
        case 16: _t->signalShowPacketLossRate(); break;
        case 17: _t->signalCreateMininetScript((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->signalCreateWeightMatrix((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->loadRoutes((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->showRoute((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->hideRoute((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->signalSaveNetworkMap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->signalLoadNetworkMap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: _t->on_actionNew_triggered(); break;
        case 25: _t->on_actionMake_Full_Connection_triggered(); break;
        case 26: _t->on_actionSdnController_triggered(); break;
        case 27: _t->on_actionHost_triggered(); break;
        case 28: _t->on_actionSwitch_triggered(); break;
        case 29: _t->on_actionLink_triggered(); break;
        case 30: _t->on_actionText_triggered(); break;
        case 31: _t->on_actionEdit_triggered(); break;
        case 32: _t->mouseLeftButtonReleaseEventOccured((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 33: _t->mouseLeftButtonPressEventOccured((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 34: _t->mouseMoveEventOccured((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 35: _t->mouseDoubleClickEventOccured((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 36: _t->on_actionShowPorts_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 37: _t->on_actionDisplayDelay_triggered(); break;
        case 38: _t->on_actionDisplayBandwidth_triggered(); break;
        case 39: _t->on_actionDisplayPacketLoss_triggered(); break;
        case 40: _t->on_actionSaveAs_triggered(); break;
        case 41: _t->on_actionSave_triggered(); break;
        case 42: _t->on_actionOpen_triggered(); break;
        case 43: _t->on_actionCreateMnDataFile_triggered(); break;
        case 44: _t->on_actionExit_triggered(); break;
        case 45: _t->on_actionWeights_Matrix_triggered(); break;
        case 46: _t->on_actionRun_Ant_Colony_triggered(); break;
        case 47: _t->refreshNetworkMapView((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 48: _t->showMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalConnectSdnController)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalClearNetworkMap)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalHandleMouseReleaseEvent)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalHandleMousePressEvent)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalHandleMouseMoveEvent)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalHandleDoubleClickEvent)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalHandleKeyDeletePressEvent)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalChangeStateToEdit)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalPrepareSdnController)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalPrepareHost)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalPrepareSwitch)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalPrepareLink)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalPrepareTextLabel)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalShowPorts)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalShowBandwidth)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalShowDelay)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalShowPacketLossRate)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalCreateMininetScript)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalCreateWeightMatrix)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::loadRoutes)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::showRoute)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::hideRoute)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalSaveNetworkMap)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalLoadNetworkMap)) {
                *result = 23;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 49)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 49;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 49)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 49;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signalConnectSdnController()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::signalClearNetworkMap()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::signalHandleMouseReleaseEvent(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::signalHandleMousePressEvent(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::signalHandleMouseMoveEvent(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::signalHandleDoubleClickEvent(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::signalHandleKeyDeletePressEvent()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MainWindow::signalChangeStateToEdit()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void MainWindow::signalPrepareSdnController()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void MainWindow::signalPrepareHost()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void MainWindow::signalPrepareSwitch()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void MainWindow::signalPrepareLink()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void MainWindow::signalPrepareTextLabel()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void MainWindow::signalShowPorts(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void MainWindow::signalShowBandwidth()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void MainWindow::signalShowDelay()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void MainWindow::signalShowPacketLossRate()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void MainWindow::signalCreateMininetScript(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void MainWindow::signalCreateWeightMatrix(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void MainWindow::loadRoutes(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void MainWindow::showRoute(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void MainWindow::hideRoute(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void MainWindow::signalSaveNetworkMap(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void MainWindow::signalLoadNetworkMap(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
