/********************************************************************************
** Form generated from reading ui file 'debugform.ui'
**
** Created: Wed Jan 8 15:11:25 2020
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DEBUGFORM_H
#define UI_DEBUGFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include "slgfwdialogform.h"
#include "slgfwlabel.h"
#include "slgfwlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_DebugFormUi
{
public:
    SlGfwLabel *label;
    SlGfwLabel *HintLabel;
    SlGfwLineEdit *DebugPwdLineEdit;
    SlGfwLabel *DisplayLabel;

    void setupUi(SlGfwDialogForm *DebugFormUi)
    {
        if (DebugFormUi->objectName().isEmpty())
            DebugFormUi->setObjectName(QString::fromUtf8("DebugFormUi"));
        DebugFormUi->resize(599, 373);
        DebugFormUi->setFocusPolicy(Qt::TabFocus);
        label = new SlGfwLabel(DebugFormUi);
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
        HintLabel = new SlGfwLabel(DebugFormUi);
        HintLabel->setObjectName(QString::fromUtf8("HintLabel"));
        HintLabel->setGeometry(QRect(180, 170, 100, 30));
        HintLabel->setHmiFontSize(-5);
        DebugPwdLineEdit = new SlGfwLineEdit(DebugFormUi);
        DebugPwdLineEdit->setObjectName(QString::fromUtf8("DebugPwdLineEdit"));
        DebugPwdLineEdit->setGeometry(QRect(279, 170, 141, 30));
        DebugPwdLineEdit->setFont(font);
        DebugPwdLineEdit->setHmiFonts(true);
        DebugPwdLineEdit->setHmiFontSize(0);
        DebugPwdLineEdit->setEchoMode(SlGfwLineEdit::PASSWORD);
        DebugPwdLineEdit->setAlignment(Qt::AlignHCenter);
        DisplayLabel = new SlGfwLabel(DebugFormUi);
        DisplayLabel->setObjectName(QString::fromUtf8("DisplayLabel"));
        DisplayLabel->setGeometry(QRect(130, 160, 341, 50));
        DisplayLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(DebugFormUi);

        QMetaObject::connectSlotsByName(DebugFormUi);
    } // setupUi

    void retranslateUi(SlGfwDialogForm *DebugFormUi)
    {
        label->setStyleSheet(QApplication::translate("DebugFormUi", "background-color: rgb(255, 255, 0)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DebugFormUi", "\350\260\203\350\257\225\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        HintLabel->setText(QApplication::translate("DebugFormUi", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        DebugPwdLineEdit->setValue(QString());
        Q_UNUSED(DebugFormUi);
    } // retranslateUi

};

namespace Ui {
    class DebugFormUi: public Ui_DebugFormUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGFORM_H
