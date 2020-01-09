/********************************************************************************
** Form generated from reading ui file 'debugmodeform.ui'
**
** Created: Mon Dec 16 11:31:03 2019
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DEBUGMODEFORM_H
#define UI_DEBUGMODEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include "slgfwdialogform.h"
#include "slgfwlabel.h"
#include "slgfwlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_DebugModeFormUi
{
public:
    SlGfwLabel *label_2;
    SlGfwLineEdit *DebugPwdLineEdit;
    SlGfwLabel *HintLabel;
    SlGfwLabel *DisplayLabel;

    void setupUi(SlGfwDialogForm *DebugModeFormUi)
    {
        if (DebugModeFormUi->objectName().isEmpty())
            DebugModeFormUi->setObjectName(QString::fromUtf8("DebugModeFormUi"));
        DebugModeFormUi->resize(487, 364);
        label_2 = new SlGfwLabel(DebugModeFormUi);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 40, 171, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Siemens AD CH Simplified"));
        font.setBold(false);
        font.setWeight(50);
        label_2->setFont(font);
        label_2->setAutoFillBackground(false);
        label_2->setHmiFontSize(-5);
        label_2->setAlignment(Qt::AlignCenter);
        DebugPwdLineEdit = new SlGfwLineEdit(DebugModeFormUi);
        DebugPwdLineEdit->setObjectName(QString::fromUtf8("DebugPwdLineEdit"));
        DebugPwdLineEdit->setGeometry(QRect(179, 120, 141, 30));
        DebugPwdLineEdit->setFont(font);
        DebugPwdLineEdit->setHmiFonts(true);
        DebugPwdLineEdit->setHmiFontSize(0);
        DebugPwdLineEdit->setEchoMode(SlGfwLineEdit::PASSWORD);
        DebugPwdLineEdit->setAlignment(Qt::AlignHCenter);
        HintLabel = new SlGfwLabel(DebugModeFormUi);
        HintLabel->setObjectName(QString::fromUtf8("HintLabel"));
        HintLabel->setGeometry(QRect(80, 120, 100, 30));
        HintLabel->setHmiFontSize(-5);
        DisplayLabel = new SlGfwLabel(DebugModeFormUi);
        DisplayLabel->setObjectName(QString::fromUtf8("DisplayLabel"));
        DisplayLabel->setGeometry(QRect(60, 200, 341, 50));
        DisplayLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(DebugModeFormUi);

        QMetaObject::connectSlotsByName(DebugModeFormUi);
    } // setupUi

    void retranslateUi(SlGfwDialogForm *DebugModeFormUi)
    {
        label_2->setStyleSheet(QApplication::translate("DebugModeFormUi", "background-color: rgb(255, 255, 0)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DebugModeFormUi", "\350\260\203\350\257\225\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        DebugPwdLineEdit->setValue(QString());
        HintLabel->setText(QApplication::translate("DebugModeFormUi", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(DebugModeFormUi);
    } // retranslateUi

};

namespace Ui {
    class DebugModeFormUi: public Ui_DebugModeFormUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGMODEFORM_H
