/****************************************************************************
** Meta object code from reading C++ file 'digitaloutput.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../digitaloutput.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'digitaloutput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DPX__DigitalOutput_t {
    QByteArrayData data[10];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DPX__DigitalOutput_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DPX__DigitalOutput_t qt_meta_stringdata_DPX__DigitalOutput = {
    {
QT_MOC_LITERAL(0, 0, 18), // "DPX::DigitalOutput"
QT_MOC_LITERAL(1, 19, 5), // "write"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "port"
QT_MOC_LITERAL(4, 31, 3), // "pin"
QT_MOC_LITERAL(5, 35, 5), // "value"
QT_MOC_LITERAL(6, 41, 4), // "read"
QT_MOC_LITERAL(7, 46, 8), // "readPort"
QT_MOC_LITERAL(8, 55, 4), // "line"
QT_MOC_LITERAL(9, 60, 9) // "DPX::Line"

    },
    "DPX::DigitalOutput\0write\0\0port\0pin\0"
    "value\0read\0readPort\0line\0DPX::Line"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DPX__DigitalOutput[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x0a /* Public */,
       1,    1,   66,    2, 0x0a /* Public */,
       3,    0,   69,    2, 0x0a /* Public */,
       4,    0,   70,    2, 0x0a /* Public */,
       6,    0,   71,    2, 0x0a /* Public */,
       6,    2,   72,    2, 0x0a /* Public */,
       7,    0,   77,    2, 0x0a /* Public */,
       7,    1,   78,    2, 0x0a /* Public */,
       8,    0,   81,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Int, QMetaType::UInt, QMetaType::UInt, QMetaType::Bool,    3,    4,    5,
    QMetaType::Int, QMetaType::Bool,    5,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::UInt, QMetaType::UInt,    3,    4,
    QMetaType::Int,
    QMetaType::Int, QMetaType::UInt,    3,
    0x80000000 | 9,

       0        // eod
};

void DPX::DigitalOutput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DigitalOutput *_t = static_cast<DigitalOutput *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->write((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { int _r = _t->write((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { int _r = _t->port();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->pin();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->read();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->read((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { int _r = _t->readPort();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: { int _r = _t->readPort((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 8: { DPX::Line _r = _t->line();
            if (_a[0]) *reinterpret_cast< DPX::Line*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject DPX::DigitalOutput::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DPX__DigitalOutput.data,
      qt_meta_data_DPX__DigitalOutput,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DPX::DigitalOutput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DPX::DigitalOutput::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DPX__DigitalOutput.stringdata0))
        return static_cast<void*>(const_cast< DigitalOutput*>(this));
    return QObject::qt_metacast(_clname);
}

int DPX::DigitalOutput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
