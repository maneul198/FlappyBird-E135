/****************************************************************************
** Meta object code from reading C++ file 'productsmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../cmakeFlappy/productsmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'productsmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ProductsManager_t {
    QByteArrayData data[25];
    char stringdata0[273];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProductsManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProductsManager_t qt_meta_stringdata_ProductsManager = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ProductsManager"
QT_MOC_LITERAL(1, 16, 9), // "delivered"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "Product*"
QT_MOC_LITERAL(4, 36, 7), // "product"
QT_MOC_LITERAL(5, 44, 7), // "started"
QT_MOC_LITERAL(6, 52, 7), // "timeout"
QT_MOC_LITERAL(7, 60, 7), // "stopped"
QT_MOC_LITERAL(8, 68, 15), // "productsChanged"
QT_MOC_LITERAL(9, 84, 20), // "enabledLightsChanged"
QT_MOC_LITERAL(10, 105, 15), // "selectedChanged"
QT_MOC_LITERAL(11, 121, 11), // "busyChanged"
QT_MOC_LITERAL(12, 133, 15), // "spinTimeChanged"
QT_MOC_LITERAL(13, 149, 8), // "turnHook"
QT_MOC_LITERAL(14, 158, 4), // "hook"
QT_MOC_LITERAL(15, 163, 10), // "selectHook"
QT_MOC_LITERAL(16, 174, 13), // "unselectHooks"
QT_MOC_LITERAL(17, 188, 8), // "products"
QT_MOC_LITERAL(18, 197, 25), // "QQmlListProperty<Product>"
QT_MOC_LITERAL(19, 223, 6), // "sensor"
QT_MOC_LITERAL(20, 230, 4), // "busy"
QT_MOC_LITERAL(21, 235, 13), // "enabledLights"
QT_MOC_LITERAL(22, 249, 5), // "hooks"
QT_MOC_LITERAL(23, 255, 8), // "spinTime"
QT_MOC_LITERAL(24, 264, 8) // "selected"

    },
    "ProductsManager\0delivered\0\0Product*\0"
    "product\0started\0timeout\0stopped\0"
    "productsChanged\0enabledLightsChanged\0"
    "selectedChanged\0busyChanged\0spinTimeChanged\0"
    "turnHook\0hook\0selectHook\0unselectHooks\0"
    "products\0QQmlListProperty<Product>\0"
    "sensor\0busy\0enabledLights\0hooks\0"
    "spinTime\0selected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProductsManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       7,   92, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,
       6,    0,   78,    2, 0x06 /* Public */,
       7,    0,   79,    2, 0x06 /* Public */,
       8,    0,   80,    2, 0x06 /* Public */,
       9,    0,   81,    2, 0x06 /* Public */,
      10,    0,   82,    2, 0x06 /* Public */,
      11,    0,   83,    2, 0x06 /* Public */,
      12,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,   85,    2, 0x0a /* Public */,
      15,    1,   88,    2, 0x0a /* Public */,
      16,    0,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,   14,
    QMetaType::Void, QMetaType::UInt,   14,
    QMetaType::Void,

 // properties: name, type, flags
      17, 0x80000000 | 18, 0x00495009,
      19, QMetaType::Int, 0x00095103,
      20, QMetaType::Bool, 0x00495001,
      21, QMetaType::Bool, 0x00495103,
      22, QMetaType::Int, 0x00095001,
      23, QMetaType::Int, 0x00495103,
      24, QMetaType::Int, 0x00495001,

 // properties: notify_signal_id
       4,
       0,
       7,
       5,
       0,
       8,
       6,

       0        // eod
};

void ProductsManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProductsManager *_t = static_cast<ProductsManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->delivered((*reinterpret_cast< Product*(*)>(_a[1]))); break;
        case 1: _t->started(); break;
        case 2: _t->timeout(); break;
        case 3: _t->stopped(); break;
        case 4: _t->productsChanged(); break;
        case 5: _t->enabledLightsChanged(); break;
        case 6: _t->selectedChanged(); break;
        case 7: _t->busyChanged(); break;
        case 8: _t->spinTimeChanged(); break;
        case 9: _t->turnHook((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 10: _t->selectHook((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 11: _t->unselectHooks(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Product* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ProductsManager::*_t)(Product * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProductsManager::delivered)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ProductsManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProductsManager::started)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ProductsManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProductsManager::timeout)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ProductsManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProductsManager::stopped)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ProductsManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProductsManager::productsChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ProductsManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProductsManager::enabledLightsChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (ProductsManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProductsManager::selectedChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (ProductsManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProductsManager::busyChanged)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (ProductsManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProductsManager::spinTimeChanged)) {
                *result = 8;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ProductsManager *_t = static_cast<ProductsManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QQmlListProperty<Product>*>(_v) = _t->products(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->sensor(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->busy(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->enabledLights(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->countHooks(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->spinTime(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->selected(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ProductsManager *_t = static_cast<ProductsManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setSensor(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setEnabledLights(*reinterpret_cast< bool*>(_v)); break;
        case 5: _t->setSpinTime(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject ProductsManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ProductsManager.data,
      qt_meta_data_ProductsManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ProductsManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProductsManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ProductsManager.stringdata0))
        return static_cast<void*>(const_cast< ProductsManager*>(this));
    if (!strcmp(_clname, "QQmlParserStatus"))
        return static_cast< QQmlParserStatus*>(const_cast< ProductsManager*>(this));
    if (!strcmp(_clname, "org.qt-project.Qt.QQmlParserStatus"))
        return static_cast< QQmlParserStatus*>(const_cast< ProductsManager*>(this));
    return QObject::qt_metacast(_clname);
}

int ProductsManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ProductsManager::delivered(Product * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ProductsManager::started()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ProductsManager::timeout()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void ProductsManager::stopped()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void ProductsManager::productsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void ProductsManager::enabledLightsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void ProductsManager::selectedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void ProductsManager::busyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void ProductsManager::spinTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
