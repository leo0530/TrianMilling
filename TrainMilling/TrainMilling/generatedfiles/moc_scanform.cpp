/****************************************************************************
** Meta object code from reading C++ file 'scanform.h'
**
** Created: Wed Jan 8 15:11:26 2020
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scanform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scanform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ScanForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      54,   24,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ScanForm[] = {
    "ScanForm\0\0TimeoutSlot()\0"
    "rszFunction,rszArgs,rbHandled\0"
    "onFunction(QString,QString,bool&)\0"
};

const QMetaObject ScanForm::staticMetaObject = {
    { &SlGfwDialogForm::staticMetaObject, qt_meta_stringdata_ScanForm,
      qt_meta_data_ScanForm, 0 }
};

const QMetaObject *ScanForm::metaObject() const
{
    return &staticMetaObject;
}

void *ScanForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScanForm))
        return static_cast<void*>(const_cast< ScanForm*>(this));
    if (!strcmp(_clname, "Ui::ScanFormUi"))
        return static_cast< Ui::ScanFormUi*>(const_cast< ScanForm*>(this));
    return SlGfwDialogForm::qt_metacast(_clname);
}

int ScanForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
