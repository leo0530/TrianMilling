/****************************************************************************
** Meta object code from reading C++ file 'operatemanualform.h'
**
** Created: Mon Dec 16 11:05:04 2019
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../operatemanualform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'operatemanualform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OperateManualForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x0a,
      63,   33,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_OperateManualForm[] = {
    "OperateManualForm\0\0TimeoutSlot()\0"
    "rszFunction,rszArgs,rbHandled\0"
    "onFunction(QString,QString,bool&)\0"
};

const QMetaObject OperateManualForm::staticMetaObject = {
    { &SlGfwDialogForm::staticMetaObject, qt_meta_stringdata_OperateManualForm,
      qt_meta_data_OperateManualForm, 0 }
};

const QMetaObject *OperateManualForm::metaObject() const
{
    return &staticMetaObject;
}

void *OperateManualForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OperateManualForm))
        return static_cast<void*>(const_cast< OperateManualForm*>(this));
    if (!strcmp(_clname, "Ui::OperateManualFormUi"))
        return static_cast< Ui::OperateManualFormUi*>(const_cast< OperateManualForm*>(this));
    return SlGfwDialogForm::qt_metacast(_clname);
}

int OperateManualForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SlGfwDialogForm::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: TimeoutSlot(); break;
        case 1: onFunction((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
