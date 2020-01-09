/****************************************************************************
** Meta object code from reading C++ file 'railcalibform.h'
**
** Created: Wed Jan 8 15:11:26 2020
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../railcalibform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'railcalibform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RailCalibForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      45,   15,   14,   14, 0x0a,
      93,   79,   14,   14, 0x0a,
     119,   79,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RailCalibForm[] = {
    "RailCalibForm\0\0rszFunction,rszArgs,rbHandled\0"
    "onFunction(QString,QString,bool&)\0"
    "rszScreenName\0attachedToScreen(QString)\0"
    "detachedFromScreen(QString)\0"
};

const QMetaObject RailCalibForm::staticMetaObject = {
    { &SlGfwDialogForm::staticMetaObject, qt_meta_stringdata_RailCalibForm,
      qt_meta_data_RailCalibForm, 0 }
};

const QMetaObject *RailCalibForm::metaObject() const
{
    return &staticMetaObject;
}

void *RailCalibForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RailCalibForm))
        return static_cast<void*>(const_cast< RailCalibForm*>(this));
    if (!strcmp(_clname, "Ui::RailCalibFormUi"))
        return static_cast< Ui::RailCalibFormUi*>(const_cast< RailCalibForm*>(this));
    return SlGfwDialogForm::qt_metacast(_clname);
}

int RailCalibForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SlGfwDialogForm::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onFunction((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: attachedToScreen((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: detachedFromScreen((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
