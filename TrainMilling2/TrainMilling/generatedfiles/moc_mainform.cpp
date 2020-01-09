/****************************************************************************
** Meta object code from reading C++ file 'mainform.h'
**
** Created: Mon Dec 16 11:05:04 2019
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      30,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,    9,    9,    9, 0x0a,
      63,    9,    9,    9, 0x0a,
      83,    9,    9,    9, 0x0a,
     102,    9,    9,    9, 0x0a,
     147,  117,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainForm[] = {
    "MainForm\0\0emitDiconnectSlot()\0"
    "emitShowSendData()\0TimeOutSlot()\0"
    "NewConnectionSlot()\0disconnectedSlot()\0"
    "ReadDataSlot()\0rszFunction,rszArgs,rbHandled\0"
    "onFunction(QString,QString,bool&)\0"
};

const QMetaObject MainForm::staticMetaObject = {
    { &SlGfwDialogForm::staticMetaObject, qt_meta_stringdata_MainForm,
      qt_meta_data_MainForm, 0 }
};

const QMetaObject *MainForm::metaObject() const
{
    return &staticMetaObject;
}

void *MainForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainForm))
        return static_cast<void*>(const_cast< MainForm*>(this));
    if (!strcmp(_clname, "Ui::MainFormUi"))
        return static_cast< Ui::MainFormUi*>(const_cast< MainForm*>(this));
    return SlGfwDialogForm::qt_metacast(_clname);
}

int MainForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SlGfwDialogForm::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: emitDiconnectSlot(); break;
        case 1: emitShowSendData(); break;
        case 2: TimeOutSlot(); break;
        case 3: NewConnectionSlot(); break;
        case 4: disconnectedSlot(); break;
        case 5: ReadDataSlot(); break;
        case 6: onFunction((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MainForm::emitDiconnectSlot()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MainForm::emitShowSendData()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
