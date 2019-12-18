/****************************************************************************
** Meta object code from reading C++ file 'recordform.h'
**
** Created: Mon Dec 16 11:05:03 2019
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../recordform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recordform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RecordForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      29,   26,   11,   11, 0x0a,
      69,   26,   11,   11, 0x0a,
     108,   26,   11,   11, 0x0a,
     148,   26,   11,   11, 0x0a,
     189,   26,   11,   11, 0x0a,
     229,   26,   11,   11, 0x0a,
     300,  270,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RecordForm[] = {
    "RecordForm\0\0timeoutSlot()\0,,\0"
    "RestorePressedSlot(int,QPoint,QWidget*)\0"
    "ZoomInPressedSlot(int,QPoint,QWidget*)\0"
    "ZoomOutPressedSlot(int,QPoint,QWidget*)\0"
    "RestoreReleasedSlot(int,QPoint,QWidget*)\0"
    "ZoomInReleasedSlot(int,QPoint,QWidget*)\0"
    "ZoomOutReleasedSlot(int,QPoint,QWidget*)\0"
    "rszFunction,rszArgs,rbHandled\0"
    "onFunction(QString,QString,bool&)\0"
};

const QMetaObject RecordForm::staticMetaObject = {
    { &SlGfwDialogForm::staticMetaObject, qt_meta_stringdata_RecordForm,
      qt_meta_data_RecordForm, 0 }
};

const QMetaObject *RecordForm::metaObject() const
{
    return &staticMetaObject;
}

void *RecordForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RecordForm))
        return static_cast<void*>(const_cast< RecordForm*>(this));
    if (!strcmp(_clname, "Ui::RecordFormUi"))
        return static_cast< Ui::RecordFormUi*>(const_cast< RecordForm*>(this));
    return SlGfwDialogForm::qt_metacast(_clname);
}

int RecordForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SlGfwDialogForm::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: timeoutSlot(); break;
        case 1: RestorePressedSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])),(*reinterpret_cast< QWidget*(*)>(_a[3]))); break;
        case 2: ZoomInPressedSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])),(*reinterpret_cast< QWidget*(*)>(_a[3]))); break;
        case 3: ZoomOutPressedSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])),(*reinterpret_cast< QWidget*(*)>(_a[3]))); break;
        case 4: RestoreReleasedSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])),(*reinterpret_cast< QWidget*(*)>(_a[3]))); break;
        case 5: ZoomInReleasedSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])),(*reinterpret_cast< QWidget*(*)>(_a[3]))); break;
        case 6: ZoomOutReleasedSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])),(*reinterpret_cast< QWidget*(*)>(_a[3]))); break;
        case 7: onFunction((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
