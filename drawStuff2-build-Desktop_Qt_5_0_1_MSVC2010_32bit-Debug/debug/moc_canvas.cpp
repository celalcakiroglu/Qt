/****************************************************************************
** Meta object code from reading C++ file 'canvas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../drawStuff/canvas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Canvas_t {
    QByteArrayData data[17];
    char stringdata[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Canvas_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Canvas_t qt_meta_stringdata_Canvas = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 10),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 5),
QT_MOC_LITERAL(4, 25, 5),
QT_MOC_LITERAL(5, 31, 8),
QT_MOC_LITERAL(6, 40, 5),
QT_MOC_LITERAL(7, 46, 5),
QT_MOC_LITERAL(8, 52, 9),
QT_MOC_LITERAL(9, 62, 13),
QT_MOC_LITERAL(10, 76, 17),
QT_MOC_LITERAL(11, 94, 9),
QT_MOC_LITERAL(12, 104, 12),
QT_MOC_LITERAL(13, 117, 12),
QT_MOC_LITERAL(14, 130, 12),
QT_MOC_LITERAL(15, 143, 15),
QT_MOC_LITERAL(16, 159, 15)
    },
    "Canvas\0setBgColor\0\0Farbe\0farbe\0setShape\0"
    "Shape\0shape\0drawShape\0clearLastLine\0"
    "clearLastPolyLine\0clearCSys\0polyLineDone\0"
    "undoLastPart\0redoLastPart\0assignLineColor\0"
    "assignLineWidth\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Canvas[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x0a,
       5,    1,   72,    2, 0x0a,
       8,    0,   75,    2, 0x0a,
       9,    0,   76,    2, 0x0a,
      10,    0,   77,    2, 0x0a,
      11,    0,   78,    2, 0x0a,
      12,    0,   79,    2, 0x0a,
      13,    0,   80,    2, 0x0a,
      14,    0,   81,    2, 0x0a,
      15,    0,   82,    2, 0x0a,
      16,    0,   83,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
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

void Canvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Canvas *_t = static_cast<Canvas *>(_o);
        switch (_id) {
        case 0: _t->setBgColor((*reinterpret_cast< Farbe(*)>(_a[1]))); break;
        case 1: _t->setShape((*reinterpret_cast< Shape(*)>(_a[1]))); break;
        case 2: _t->drawShape(); break;
        case 3: _t->clearLastLine(); break;
        case 4: _t->clearLastPolyLine(); break;
        case 5: _t->clearCSys(); break;
        case 6: _t->polyLineDone(); break;
        case 7: _t->undoLastPart(); break;
        case 8: _t->redoLastPart(); break;
        case 9: _t->assignLineColor(); break;
        case 10: _t->assignLineWidth(); break;
        default: ;
        }
    }
}

const QMetaObject Canvas::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Canvas.data,
      qt_meta_data_Canvas,  qt_static_metacall, 0, 0}
};


const QMetaObject *Canvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Canvas::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Canvas.stringdata))
        return static_cast<void*>(const_cast< Canvas*>(this));
    return QWidget::qt_metacast(_clname);
}

int Canvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
