/********************************************************************************
** Form generated from reading ui file 'devicerepair.ui'
**
** Created: Mon Dec 16 11:05:08 2019
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DEVICEREPAIR_H
#define UI_DEVICEREPAIR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include "slgfwdialogform.h"
#include "slgfwlabel.h"
#include "slgfwlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_DeviceRepairUi
{
public:
    SlGfwLabel *label;
    SlGfwLineEdit *RepairPwdLineEdit;
    SlGfwLabel *HintLabel;
    SlGfwLabel *DisplayLabel;

    void setupUi(SlGfwDialogForm *DeviceRepairUi)
    {
        if (DeviceRepairUi->objectName().isEmpty())
            DeviceRepairUi->setObjectName(QString::fromUtf8("DeviceRepairUi"));
        DeviceRepairUi->resize(599, 373);
        label = new SlGfwLabel(DeviceRepairUi);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 29, 171, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Siemens AD CH Simplified"));
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setHmiFontSize(-5);
        label->setAlignment(Qt::AlignCenter);
        RepairPwdLineEdit = new SlGfwLineEdit(DeviceRepairUi);
        RepairPwdLineEdit->setObjectName(QString::fromUtf8("RepairPwdLineEdit"));
        RepairPwdLineEdit->setGeometry(QRect(264, 170, 141, 30));
        RepairPwdLineEdit->setFont(font);
        RepairPwdLineEdit->setHmiFonts(true);
        RepairPwdLineEdit->setHmiFontSize(0);
        RepairPwdLineEdit->setEchoMode(SlGfwLineEdit::PASSWORD);
        RepairPwdLineEdit->setAlignment(Qt::AlignHCenter);
        HintLabel = new SlGfwLabel(DeviceRepairUi);
        HintLabel->setObjectName(QString::fromUtf8("HintLabel"));
        HintLabel->setGeometry(QRect(165, 170, 100, 30));
        HintLabel->setHmiFontSize(-5);
        DisplayLabel = new SlGfwLabel(DeviceRepairUi);
        DisplayLabel->setObjectName(QString::fromUtf8("DisplayLabel"));
        DisplayLabel->setGeometry(QRect(120, 230, 341, 50));
        DisplayLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(DeviceRepairUi);

        QMetaObject::connectSlotsByName(DeviceRepairUi);
    } // setupUi

    void retranslateUi(SlGfwDialogForm *DeviceRepairUi)
    {
        label->setStyleSheet(QApplication::translate("DeviceRepairUi", "background-color: rgb(255, 255, 0)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DeviceRepairUi", "\346\243\200\344\277\256\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        RepairPwdLineEdit->setValue(QString());
        HintLabel->setText(QApplication::translate("DeviceRepairUi", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(DeviceRepairUi);
    } // retranslateUi

};

namespace Ui {
    class DeviceRepairUi: public Ui_DeviceRepairUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEREPAIR_H
