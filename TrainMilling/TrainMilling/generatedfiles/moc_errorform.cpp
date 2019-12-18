/****************************************************************************
** Meta object code from reading C++ file 'errorform.h'
**
** Created: Mon Dec 16 11:05:04 2019
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../errorform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'errorform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ErrorForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      27,   10,   10,   10, 0x0a,
      46,   41,   10,   10, 0x0a,
      64,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ErrorForm[] = {
    "ErrorForm\0\0onListChanged()\0TimeoutSlot()\0"
    "date\0SelectDate(QDate)\0SelectDate()\0"
};

const QMetaObject ErrorForm::staticMetaObject = {
    { &SlGfwDialogForm::staticMetaObject, qt_meta_stringdata_ErrorForm,
      qt_meta_data_ErrorForm, 0 }
};

const QMetaObject *ErrorForm::metaObject() const
{
    return &staticMetaObject;
}

void *ErrorForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ErrorForm))
        return static_cast<void*>(const_cast< ErrorForm*>(this));
    if (!strcmp(_clname, "Ui::ErrorFormUi"))
        return static_cast< Ui::ErrorFormUi*>(const_cast< ErrorForm*>(this));
    return SlGfwDialogForm::qt_metacast(_clname);
}

int ErrorForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SlGfwDialogForm::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onListChanged(); break;
        case 1: TimeoutSlot(); break;
        case 2: SelectDate((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 3: SelectDate(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
