/****************************************************************************
** Meta object code from reading C++ file 'statuslistform.h'
**
** Created: Mon Dec 16 11:05:02 2019
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../statuslistform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'statuslistform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StatusListForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      60,   30,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_StatusListForm[] = {
    "StatusListForm\0\0TimeOutSlot()\0"
    "rszFunction,rszArgs,rbHandled\0"
    "onFunction(QString,QString,bool&)\0"
};

const QMetaObject StatusListForm::staticMetaObject = {
    { &SlGfwDialogForm::staticMetaObject, qt_meta_stringdata_StatusListForm,
      qt_meta_data_StatusListForm, 0 }
};

const QMetaObject *StatusListForm::metaObject() const
{
    return &staticMetaObject;
}

void *StatusListForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StatusListForm))
        return static_cast<void*>(const_cast< StatusListForm*>(this));
    if (!strcmp(_clname, "Ui::StatusListFormUi"))
        return static_cast< Ui::StatusListFormUi*>(const_cast< StatusListForm*>(this));
    return SlGfwDialogForm::qt_metacast(_clname);
}

int StatusListForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SlGfwDialogForm::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: TimeOutSlot(); break;
        case 1: onFunction((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
