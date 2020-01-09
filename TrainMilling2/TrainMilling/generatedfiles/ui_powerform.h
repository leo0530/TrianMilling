/********************************************************************************
** Form generated from reading ui file 'powerform.ui'
**
** Created: Mon Dec 16 11:05:07 2019
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_POWERFORM_H
#define UI_POWERFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include "slgfwdialogform.h"

QT_BEGIN_NAMESPACE

class Ui_PowerFormUi
{
public:

    void setupUi(SlGfwDialogForm *PowerFormUi)
    {
        if (PowerFormUi->objectName().isEmpty())
            PowerFormUi->setObjectName(QString::fromUtf8("PowerFormUi"));
        PowerFormUi->resize(459, 256);

        retranslateUi(PowerFormUi);

        QMetaObject::connectSlotsByName(PowerFormUi);
    } // setupUi

    void retranslateUi(SlGfwDialogForm *PowerFormUi)
    {
        Q_UNUSED(PowerFormUi);
    } // retranslateUi

};

namespace Ui {
    class PowerFormUi: public Ui_PowerFormUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POWERFORM_H
