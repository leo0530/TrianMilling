/****************************************************************************
** Meta object code from reading C++ file 'softlimitform.h'
**
** Created: Mon Dec 16 11:05:02 2019
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../softlimitform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'softlimitform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SoftLimitForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      45,   15,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SoftLimitForm[] = {
    "SoftLimitForm\0\0rszFunction,rszArgs,rbHandled\0"
    "onFunction(QString,QString,bool&)\0"
};

const QMetaObject SoftLimitForm::staticMetaObject = {
    { &SlGfwDialogForm::staticMetaObject, qt_meta_stringdata_SoftLimitForm,
      qt_meta_data_SoftLimitForm, 0 }
};

const QMetaObject *SoftLimitForm::metaObject() const
{
    return &staticMetaObject;
}

void *SoftLimitForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SoftLimitForm))
        return static_cast<void*>(const_cast< SoftLimitForm*>(this));
    if (!strcmp(_clname, "Ui::SoftLimitFormUi"))
        return static_cast< Ui::SoftLimitFormUi*>(const_cast< SoftLimitForm*>(this));
    return SlGfwDialogForm::qt_metacast(_clname);
}

int SoftLimitForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SlGfwDialogForm::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onFunction((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE