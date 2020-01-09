/****************************************************************************
** Meta object code from reading C++ file 'powerform.h'
**
** Created: Wed Jan 8 15:11:26 2020
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../powerform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'powerform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PowerForm[] = {

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
      55,   25,   10,   10, 0x0a,
     103,   89,   10,   10, 0x0a,
     129,   89,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PowerForm[] = {
    "PowerForm\0\0timeoutSlot()\0"
    "rszFunction,rszArgs,rbHandled\0"
    "onFunction(QString,QString,bool&)\0"
    "rszScreenName\0attachedToScreen(QString)\0"
    "detachedFromScreen(QString)\0"
};

const QMetaObject PowerForm::staticMetaObject = {
    { &SlGfwDialogForm::staticMetaObject, qt_meta_stringdata_PowerForm,
      qt_meta_data_PowerForm, 0 }
};

const QMetaObject *PowerForm::metaObject() const
{
    return &staticMetaObject;
}

void *PowerForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PowerForm))
        return static_cast<void*>(const_cast< PowerForm*>(this));
    if (!strcmp(_clname, "Ui::PowerFormUi"))
        return static_cast< Ui::PowerFormUi*>(const_cast< PowerForm*>(this));
    return SlGfwDialogForm::qt_metacast(_clname);
}

int PowerForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SlGfwDialogForm::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: timeoutSlot(); break;
        case 1: onFunction((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 2: attachedToScreen((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: detachedFromScreen((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
