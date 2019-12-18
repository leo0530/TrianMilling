/****************************************************************************
** Meta object code from reading C++ file 'QTcuCom.h'
**
** Created: Sun Nov 19 14:20:02 2017
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QTcuCom.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QTcuCom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QTcuCom[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QTcuCom[] = {
    "QTcuCom\0\0TimeOutSlot()\0"
};

const QMetaObject QTcuCom::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QTcuCom,
      qt_meta_data_QTcuCom, 0 }
};

const QMetaObject *QTcuCom::metaObject() const
{
    return &staticMetaObject;
}

void *QTcuCom::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QTcuCom))
        return static_cast<void*>(const_cast< QTcuCom*>(this));
    return QWidget::qt_metacast(_clname);
}

int QTcuCom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: TimeOutSlot(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
