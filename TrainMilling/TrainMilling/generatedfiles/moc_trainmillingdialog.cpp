/****************************************************************************
** Meta object code from reading C++ file 'trainmillingdialog.h'
**
** Created: Mon Dec 16 11:05:01 2019
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../trainmillingdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trainmillingdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TrainMillingdialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      34,   19,   19,   19, 0x0a,
      55,   19,   19,   19, 0x0a,
      75,   73,   19,   19, 0x0a,
     143,   73,   19,   19, 0x0a,
     214,   73,   19,   19, 0x0a,
     277,   73,   19,   19, 0x0a,
     340,   73,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TrainMillingdialog[] = {
    "TrainMillingdialog\0\0TimeoutSlot()\0"
    "MillingTimeoutSlot()\0ScanTimeoutSlot()\0"
    ",\0FreshMillingDataSlot(SlCapErrorEnum,QVector<SlCapAdviseResultType>)\0"
    "FreshMillingControlSlot(SlCapErrorEnum,QVector<SlCapAdviseResultType>)\0"
    "FreshStatusSlot(SlCapErrorEnum,QVector<SlCapAdviseResultType>)\0"
    "FreshIOListSlot(SlCapErrorEnum,QVector<SlCapAdviseResultType>)\0"
    "FreshErrListSlot(SlCapErrorEnum,QVector<SlCapAdviseResultType>)\0"
};

const QMetaObject TrainMillingdialog::staticMetaObject = {
    { &SlGfwHmiDialog::staticMetaObject, qt_meta_stringdata_TrainMillingdialog,
      qt_meta_data_TrainMillingdialog, 0 }
};

const QMetaObject *TrainMillingdialog::metaObject() const
{
    return &staticMetaObject;
}

void *TrainMillingdialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TrainMillingdialog))
        return static_cast<void*>(const_cast< TrainMillingdialog*>(this));
    return SlGfwHmiDialog::qt_metacast(_clname);
}

int TrainMillingdialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SlGfwHmiDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: TimeoutSlot(); break;
        case 1: MillingTimeoutSlot(); break;
        case 2: ScanTimeoutSlot(); break;
        case 3: FreshMillingDataSlot((*reinterpret_cast< SlCapErrorEnum(*)>(_a[1])),(*reinterpret_cast< const QVector<SlCapAdviseResultType>(*)>(_a[2]))); break;
        case 4: FreshMillingControlSlot((*reinterpret_cast< SlCapErrorEnum(*)>(_a[1])),(*reinterpret_cast< const QVector<SlCapAdviseResultType>(*)>(_a[2]))); break;
        case 5: FreshStatusSlot((*reinterpret_cast< SlCapErrorEnum(*)>(_a[1])),(*reinterpret_cast< const QVector<SlCapAdviseResultType>(*)>(_a[2]))); break;
        case 6: FreshIOListSlot((*reinterpret_cast< SlCapErrorEnum(*)>(_a[1])),(*reinterpret_cast< const QVector<SlCapAdviseResultType>(*)>(_a[2]))); break;
        case 7: FreshErrListSlot((*reinterpret_cast< SlCapErrorEnum(*)>(_a[1])),(*reinterpret_cast< const QVector<SlCapAdviseResultType>(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
