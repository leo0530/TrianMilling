/****************************************************************************
** Meta object code from reading C++ file 'ErrorData.h'
**
** Created: Fri Nov 24 09:07:57 2017
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ErrorData.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ErrorData.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ErrorData[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      27,   10,   10,   10, 0x0a,
      56,   10,   10,   10, 0x0a,
      75,   10,   10,   10, 0x0a,
     100,   98,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ErrorData[] = {
    "ErrorData\0\0onListChanged()\0"
    "eventAcknowledged(SlAeEvent)\0"
    "cancelAlarms(long)\0cancelAlarmGroup(long)\0"
    ",\0alarmCanceled(long,SlAeEvent)\0"
};

const QMetaObject ErrorData::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ErrorData,
      qt_meta_data_ErrorData, 0 }
};

const QMetaObject *ErrorData::metaObject() const
{
    return &staticMetaObject;
}

void *ErrorData::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ErrorData))
        return static_cast<void*>(const_cast< ErrorData*>(this));
    return QWidget::qt_metacast(_clname);
}

int ErrorData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onListChanged(); break;
        case 1: eventAcknowledged((*reinterpret_cast< const SlAeEvent(*)>(_a[1]))); break;
        case 2: cancelAlarms((*reinterpret_cast< const long(*)>(_a[1]))); break;
        case 3: cancelAlarmGroup((*reinterpret_cast< const long(*)>(_a[1]))); break;
        case 4: alarmCanceled((*reinterpret_cast< const long(*)>(_a[1])),(*reinterpret_cast< const SlAeEvent(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
