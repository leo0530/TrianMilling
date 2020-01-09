/********************************************************************************
** Form generated from reading ui file 'operatemanualform.ui'
**
** Created: Wed Jan 8 15:11:25 2020
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_OPERATEMANUALFORM_H
#define UI_OPERATEMANUALFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include "slgfwdialogform.h"
#include "slgfwlabel.h"

QT_BEGIN_NAMESPACE

class Ui_OperateManualFormUi
{
public:
    SlGfwLabel *label;

    void setupUi(SlGfwDialogForm *OperateManualFormUi)
    {
        if (OperateManualFormUi->objectName().isEmpty())
            OperateManualFormUi->setObjectName(QString::fromUtf8("OperateManualFormUi"));
        OperateManualFormUi->resize(599, 373);
        label = new SlGfwLabel(OperateManualFormUi);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 20, 599, 353));

        retranslateUi(OperateManualFormUi);

        QMetaObject::connectSlotsByName(OperateManualFormUi);
    } // setupUi

    void retranslateUi(SlGfwDialogForm *OperateManualFormUi)
    {
        Q_UNUSED(OperateManualFormUi);
    } // retranslateUi

};

namespace Ui {
    class OperateManualFormUi: public Ui_OperateManualFormUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATEMANUALFORM_H
