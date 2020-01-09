/********************************************************************************
** Form generated from reading ui file 'usermanagerform.ui'
**
** Created: Mon Dec 16 11:05:05 2019
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_USERMANAGERFORM_H
#define UI_USERMANAGERFORM_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include "slgfwdialogform.h"
#include "slgfwgroupbox.h"
#include "slgfwlabel.h"
#include "slgfwlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_UserManagerFormUi
{
public:
    SlGfwLabel *InformationLabel;
    SlGfwGroupBox *UserPwdGroupBox;
    SlGfwLabel *NewPasswordLabel;
    SlGfwLineEdit *NewPasswordAgainLineEdit;
    SlGfwLineEdit *UserNameLineEdit;
    SlGfwLabel *OldPasswordLabel;
    SlGfwLabel *NewPasswordAgainLabel;
    SlGfwLabel *label;
    SlGfwLabel *UserNameLabel;
    SlGfwLineEdit *OldPasswordLineEdit;
    SlGfwLineEdit *NewPasswordLineEdit;
    SlGfwGroupBox *RepairPwdGroupBox;
    SlGfwLabel *NewPasswordLabel_2;
    SlGfwLineEdit *NewRepairPwdAgainLineEdit;
    SlGfwLineEdit *RepairNameLineEdit;
    SlGfwLabel *OldPasswordLabel_2;
    SlGfwLabel *NewPasswordAgainLabel_2;
    SlGfwLabel *label_2;
    SlGfwLabel *UserNameLabel_2;
    SlGfwLineEdit *OldRepairPwdLineEdit;
    SlGfwLineEdit *NewRepairPwdLineEdit;
    SlGfwGroupBox *DebugPwdGroupBox;
    SlGfwLabel *NewPasswordLabel_3;
    SlGfwLineEdit *NewDebugPwdAgainLineEdit;
    SlGfwLineEdit *DebugNameLineEdit;
    SlGfwLabel *OldPasswordLabel_3;
    SlGfwLabel *NewPasswordAgainLabel_3;
    SlGfwLabel *label_3;
    SlGfwLabel *UserNameLabel_3;
    SlGfwLineEdit *OldDebugPwdLineEdit;
    SlGfwLineEdit *NewDebugPwdLineEdit;

    void setupUi(SlGfwDialogForm *UserManagerFormUi)
    {
        if (UserManagerFormUi->objectName().isEmpty())
            UserManagerFormUi->setObjectName(QString::fromUtf8("UserManagerFormUi"));
        UserManagerFormUi->resize(599, 373);
        UserManagerFormUi->setFocusPolicy(Qt::NoFocus);
        InformationLabel = new SlGfwLabel(UserManagerFormUi);
        InformationLabel->setObjectName(QString::fromUtf8("InformationLabel"));
        InformationLabel->setGeometry(QRect(90, 280, 393, 51));
        InformationLabel->setAutoFillBackground(false);
        InformationLabel->setInverseColors(false);
        InformationLabel->setAlignment(Qt::AlignCenter);
        UserPwdGroupBox = new SlGfwGroupBox(UserManagerFormUi);
        UserPwdGroupBox->setObjectName(QString::fromUtf8("UserPwdGroupBox"));
        UserPwdGroupBox->setGeometry(QRect(-10, 0, 670, 251));
        UserPwdGroupBox->setFlat(true);
        NewPasswordLabel = new SlGfwLabel(UserPwdGroupBox);
        NewPasswordLabel->setObjectName(QString::fromUtf8("NewPasswordLabel"));
        NewPasswordLabel->setGeometry(QRect(293, 155, 120, 20));
        NewPasswordLabel->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        NewPasswordLabel->setDisplayMode(SlGfwFunctions::ANY_MODE);
        NewPasswordLabel->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        NewPasswordAgainLineEdit = new SlGfwLineEdit(UserPwdGroupBox);
        NewPasswordAgainLineEdit->setObjectName(QString::fromUtf8("NewPasswordAgainLineEdit"));
        NewPasswordAgainLineEdit->setGeometry(QRect(413, 210, 105, 25));
        NewPasswordAgainLineEdit->setEchoMode(SlGfwLineEdit::PASSWORD);
        NewPasswordAgainLineEdit->setAlignment(Qt::AlignLeading);
        NewPasswordAgainLineEdit->setInputMode(SlGfwFunctions::ANY_MODE);
        UserNameLineEdit = new SlGfwLineEdit(UserPwdGroupBox);
        UserNameLineEdit->setObjectName(QString::fromUtf8("UserNameLineEdit"));
        UserNameLineEdit->setEnabled(true);
        UserNameLineEdit->setGeometry(QRect(168, 155, 102, 25));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(6);
        sizePolicy.setHeightForWidth(UserNameLineEdit->sizePolicy().hasHeightForWidth());
        UserNameLineEdit->setSizePolicy(sizePolicy);
        UserNameLineEdit->setAlignment(Qt::AlignHCenter);
        UserNameLineEdit->setReadOnly(true);
        OldPasswordLabel = new SlGfwLabel(UserPwdGroupBox);
        OldPasswordLabel->setObjectName(QString::fromUtf8("OldPasswordLabel"));
        OldPasswordLabel->setGeometry(QRect(294, 90, 120, 25));
        OldPasswordLabel->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        OldPasswordLabel->setDisplayMode(SlGfwFunctions::ANY_MODE);
        OldPasswordLabel->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        NewPasswordAgainLabel = new SlGfwLabel(UserPwdGroupBox);
        NewPasswordAgainLabel->setObjectName(QString::fromUtf8("NewPasswordAgainLabel"));
        NewPasswordAgainLabel->setGeometry(QRect(293, 210, 120, 25));
        NewPasswordAgainLabel->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        NewPasswordAgainLabel->setDisplayMode(SlGfwFunctions::ANY_MODE);
        NewPasswordAgainLabel->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label = new SlGfwLabel(UserPwdGroupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(238, 30, 171, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Siemens AD CH Simplified"));
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setAlignment(Qt::AlignCenter);
        UserNameLabel = new SlGfwLabel(UserPwdGroupBox);
        UserNameLabel->setObjectName(QString::fromUtf8("UserNameLabel"));
        UserNameLabel->setGeometry(QRect(110, 155, 54, 25));
        UserNameLabel->setAutoFillBackground(false);
        UserNameLabel->setInverseColors(false);
        OldPasswordLineEdit = new SlGfwLineEdit(UserPwdGroupBox);
        OldPasswordLineEdit->setObjectName(QString::fromUtf8("OldPasswordLineEdit"));
        OldPasswordLineEdit->setGeometry(QRect(413, 90, 105, 25));
        OldPasswordLineEdit->setEchoMode(SlGfwLineEdit::PASSWORD);
        OldPasswordLineEdit->setAlignment(Qt::AlignLeading);
        OldPasswordLineEdit->setInputMode(SlGfwFunctions::ANY_MODE);
        NewPasswordLineEdit = new SlGfwLineEdit(UserPwdGroupBox);
        NewPasswordLineEdit->setObjectName(QString::fromUtf8("NewPasswordLineEdit"));
        NewPasswordLineEdit->setGeometry(QRect(413, 150, 105, 25));
        NewPasswordLineEdit->setEchoMode(SlGfwLineEdit::PASSWORD);
        NewPasswordLineEdit->setAlignment(Qt::AlignLeading);
        NewPasswordLineEdit->setInputMode(SlGfwFunctions::ANY_MODE);
        RepairPwdGroupBox = new SlGfwGroupBox(UserManagerFormUi);
        RepairPwdGroupBox->setObjectName(QString::fromUtf8("RepairPwdGroupBox"));
        RepairPwdGroupBox->setGeometry(QRect(-10, 0, 670, 251));
        RepairPwdGroupBox->setFlat(true);
        NewPasswordLabel_2 = new SlGfwLabel(RepairPwdGroupBox);
        NewPasswordLabel_2->setObjectName(QString::fromUtf8("NewPasswordLabel_2"));
        NewPasswordLabel_2->setGeometry(QRect(293, 155, 120, 20));
        NewPasswordLabel_2->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        NewPasswordLabel_2->setDisplayMode(SlGfwFunctions::ANY_MODE);
        NewPasswordLabel_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        NewRepairPwdAgainLineEdit = new SlGfwLineEdit(RepairPwdGroupBox);
        NewRepairPwdAgainLineEdit->setObjectName(QString::fromUtf8("NewRepairPwdAgainLineEdit"));
        NewRepairPwdAgainLineEdit->setGeometry(QRect(413, 210, 105, 25));
        NewRepairPwdAgainLineEdit->setEchoMode(SlGfwLineEdit::PASSWORD);
        NewRepairPwdAgainLineEdit->setAlignment(Qt::AlignLeading);
        NewRepairPwdAgainLineEdit->setInputMode(SlGfwFunctions::ANY_MODE);
        RepairNameLineEdit = new SlGfwLineEdit(RepairPwdGroupBox);
        RepairNameLineEdit->setObjectName(QString::fromUtf8("RepairNameLineEdit"));
        RepairNameLineEdit->setEnabled(true);
        RepairNameLineEdit->setGeometry(QRect(168, 155, 102, 25));
        sizePolicy.setHeightForWidth(RepairNameLineEdit->sizePolicy().hasHeightForWidth());
        RepairNameLineEdit->setSizePolicy(sizePolicy);
        RepairNameLineEdit->setAlignment(Qt::AlignHCenter);
        RepairNameLineEdit->setReadOnly(true);
        OldPasswordLabel_2 = new SlGfwLabel(RepairPwdGroupBox);
        OldPasswordLabel_2->setObjectName(QString::fromUtf8("OldPasswordLabel_2"));
        OldPasswordLabel_2->setGeometry(QRect(294, 90, 120, 25));
        OldPasswordLabel_2->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        OldPasswordLabel_2->setDisplayMode(SlGfwFunctions::ANY_MODE);
        OldPasswordLabel_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        NewPasswordAgainLabel_2 = new SlGfwLabel(RepairPwdGroupBox);
        NewPasswordAgainLabel_2->setObjectName(QString::fromUtf8("NewPasswordAgainLabel_2"));
        NewPasswordAgainLabel_2->setGeometry(QRect(293, 210, 120, 25));
        NewPasswordAgainLabel_2->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        NewPasswordAgainLabel_2->setDisplayMode(SlGfwFunctions::ANY_MODE);
        NewPasswordAgainLabel_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_2 = new SlGfwLabel(RepairPwdGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(238, 30, 171, 41));
        label_2->setFont(font);
        label_2->setAutoFillBackground(false);
        label_2->setAlignment(Qt::AlignCenter);
        UserNameLabel_2 = new SlGfwLabel(RepairPwdGroupBox);
        UserNameLabel_2->setObjectName(QString::fromUtf8("UserNameLabel_2"));
        UserNameLabel_2->setGeometry(QRect(110, 155, 54, 25));
        UserNameLabel_2->setAutoFillBackground(false);
        UserNameLabel_2->setInverseColors(false);
        OldRepairPwdLineEdit = new SlGfwLineEdit(RepairPwdGroupBox);
        OldRepairPwdLineEdit->setObjectName(QString::fromUtf8("OldRepairPwdLineEdit"));
        OldRepairPwdLineEdit->setGeometry(QRect(413, 90, 105, 25));
        OldRepairPwdLineEdit->setEchoMode(SlGfwLineEdit::PASSWORD);
        OldRepairPwdLineEdit->setAlignment(Qt::AlignLeading);
        OldRepairPwdLineEdit->setInputMode(SlGfwFunctions::ANY_MODE);
        NewRepairPwdLineEdit = new SlGfwLineEdit(RepairPwdGroupBox);
        NewRepairPwdLineEdit->setObjectName(QString::fromUtf8("NewRepairPwdLineEdit"));
        NewRepairPwdLineEdit->setGeometry(QRect(413, 150, 105, 25));
        NewRepairPwdLineEdit->setEchoMode(SlGfwLineEdit::PASSWORD);
        NewRepairPwdLineEdit->setAlignment(Qt::AlignLeading);
        NewRepairPwdLineEdit->setInputMode(SlGfwFunctions::ANY_MODE);
        DebugPwdGroupBox = new SlGfwGroupBox(UserManagerFormUi);
        DebugPwdGroupBox->setObjectName(QString::fromUtf8("DebugPwdGroupBox"));
        DebugPwdGroupBox->setGeometry(QRect(-10, 0, 670, 251));
        DebugPwdGroupBox->setFlat(true);
        NewPasswordLabel_3 = new SlGfwLabel(DebugPwdGroupBox);
        NewPasswordLabel_3->setObjectName(QString::fromUtf8("NewPasswordLabel_3"));
        NewPasswordLabel_3->setGeometry(QRect(293, 155, 120, 20));
        NewPasswordLabel_3->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        NewPasswordLabel_3->setDisplayMode(SlGfwFunctions::ANY_MODE);
        NewPasswordLabel_3->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        NewDebugPwdAgainLineEdit = new SlGfwLineEdit(DebugPwdGroupBox);
        NewDebugPwdAgainLineEdit->setObjectName(QString::fromUtf8("NewDebugPwdAgainLineEdit"));
        NewDebugPwdAgainLineEdit->setGeometry(QRect(413, 210, 105, 25));
        NewDebugPwdAgainLineEdit->setEchoMode(SlGfwLineEdit::PASSWORD);
        NewDebugPwdAgainLineEdit->setAlignment(Qt::AlignLeading);
        NewDebugPwdAgainLineEdit->setInputMode(SlGfwFunctions::ANY_MODE);
        DebugNameLineEdit = new SlGfwLineEdit(DebugPwdGroupBox);
        DebugNameLineEdit->setObjectName(QString::fromUtf8("DebugNameLineEdit"));
        DebugNameLineEdit->setEnabled(true);
        DebugNameLineEdit->setGeometry(QRect(168, 155, 102, 25));
        sizePolicy.setHeightForWidth(DebugNameLineEdit->sizePolicy().hasHeightForWidth());
        DebugNameLineEdit->setSizePolicy(sizePolicy);
        DebugNameLineEdit->setAlignment(Qt::AlignHCenter);
        DebugNameLineEdit->setReadOnly(true);
        OldPasswordLabel_3 = new SlGfwLabel(DebugPwdGroupBox);
        OldPasswordLabel_3->setObjectName(QString::fromUtf8("OldPasswordLabel_3"));
        OldPasswordLabel_3->setGeometry(QRect(294, 90, 120, 25));
        OldPasswordLabel_3->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        OldPasswordLabel_3->setDisplayMode(SlGfwFunctions::ANY_MODE);
        OldPasswordLabel_3->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        NewPasswordAgainLabel_3 = new SlGfwLabel(DebugPwdGroupBox);
        NewPasswordAgainLabel_3->setObjectName(QString::fromUtf8("NewPasswordAgainLabel_3"));
        NewPasswordAgainLabel_3->setGeometry(QRect(293, 210, 120, 25));
        NewPasswordAgainLabel_3->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        NewPasswordAgainLabel_3->setDisplayMode(SlGfwFunctions::ANY_MODE);
        NewPasswordAgainLabel_3->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_3 = new SlGfwLabel(DebugPwdGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(238, 30, 171, 41));
        label_3->setFont(font);
        label_3->setAutoFillBackground(false);
        label_3->setAlignment(Qt::AlignCenter);
        UserNameLabel_3 = new SlGfwLabel(DebugPwdGroupBox);
        UserNameLabel_3->setObjectName(QString::fromUtf8("UserNameLabel_3"));
        UserNameLabel_3->setGeometry(QRect(110, 155, 54, 25));
        UserNameLabel_3->setAutoFillBackground(false);
        UserNameLabel_3->setInverseColors(false);
        OldDebugPwdLineEdit = new SlGfwLineEdit(DebugPwdGroupBox);
        OldDebugPwdLineEdit->setObjectName(QString::fromUtf8("OldDebugPwdLineEdit"));
        OldDebugPwdLineEdit->setGeometry(QRect(413, 90, 105, 25));
        OldDebugPwdLineEdit->setEchoMode(SlGfwLineEdit::PASSWORD);
        OldDebugPwdLineEdit->setAlignment(Qt::AlignLeading);
        OldDebugPwdLineEdit->setInputMode(SlGfwFunctions::ANY_MODE);
        NewDebugPwdLineEdit = new SlGfwLineEdit(DebugPwdGroupBox);
        NewDebugPwdLineEdit->setObjectName(QString::fromUtf8("NewDebugPwdLineEdit"));
        NewDebugPwdLineEdit->setGeometry(QRect(413, 150, 105, 25));
        NewDebugPwdLineEdit->setEchoMode(SlGfwLineEdit::PASSWORD);
        NewDebugPwdLineEdit->setAlignment(Qt::AlignLeading);
        NewDebugPwdLineEdit->setInputMode(SlGfwFunctions::ANY_MODE);

        retranslateUi(UserManagerFormUi);

        QMetaObject::connectSlotsByName(UserManagerFormUi);
    } // setupUi

    void retranslateUi(SlGfwDialogForm *UserManagerFormUi)
    {
        InformationLabel->setText(QString());
        NewPasswordLabel->setText(QApplication::translate("UserManagerFormUi", "\346\226\260\345\257\206\347\240\201:", 0, QApplication::UnicodeUTF8));
        NewPasswordAgainLineEdit->setInputMask(QString());
        OldPasswordLabel->setText(QApplication::translate("UserManagerFormUi", "\347\263\273\347\273\237\347\216\260\345\234\250\345\257\206\347\240\201:", 0, QApplication::UnicodeUTF8));
        NewPasswordAgainLabel->setText(QApplication::translate("UserManagerFormUi", "\345\206\215\346\254\241\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201:", 0, QApplication::UnicodeUTF8));
        label->setStyleSheet(QApplication::translate("UserManagerFormUi", "background-color: rgb(255, 255, 0)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("UserManagerFormUi", "\350\256\276\345\256\232\347\224\250\346\210\267\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        UserNameLabel->setText(QApplication::translate("UserManagerFormUi", "\347\224\250\346\210\267\345\220\215:", 0, QApplication::UnicodeUTF8));
        OldPasswordLineEdit->setInputMask(QString());
        NewPasswordLineEdit->setInputMask(QString());
        NewPasswordLabel_2->setText(QApplication::translate("UserManagerFormUi", "\346\226\260\345\257\206\347\240\201:", 0, QApplication::UnicodeUTF8));
        NewRepairPwdAgainLineEdit->setInputMask(QString());
        OldPasswordLabel_2->setText(QApplication::translate("UserManagerFormUi", "\347\263\273\347\273\237\347\216\260\345\234\250\345\257\206\347\240\201:", 0, QApplication::UnicodeUTF8));
        NewPasswordAgainLabel_2->setText(QApplication::translate("UserManagerFormUi", "\345\206\215\346\254\241\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201:", 0, QApplication::UnicodeUTF8));
        label_2->setStyleSheet(QApplication::translate("UserManagerFormUi", "background-color: rgb(255, 255, 0)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("UserManagerFormUi", "\350\256\276\345\256\232\346\243\200\344\277\256\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        UserNameLabel_2->setText(QApplication::translate("UserManagerFormUi", "\347\224\250\346\210\267\345\220\215:", 0, QApplication::UnicodeUTF8));
        OldRepairPwdLineEdit->setInputMask(QString());
        NewRepairPwdLineEdit->setInputMask(QString());
        NewPasswordLabel_3->setText(QApplication::translate("UserManagerFormUi", "\346\226\260\345\257\206\347\240\201:", 0, QApplication::UnicodeUTF8));
        NewDebugPwdAgainLineEdit->setInputMask(QString());
        OldPasswordLabel_3->setText(QApplication::translate("UserManagerFormUi", "\347\263\273\347\273\237\347\216\260\345\234\250\345\257\206\347\240\201:", 0, QApplication::UnicodeUTF8));
        NewPasswordAgainLabel_3->setText(QApplication::translate("UserManagerFormUi", "\345\206\215\346\254\241\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201:", 0, QApplication::UnicodeUTF8));
        label_3->setStyleSheet(QApplication::translate("UserManagerFormUi", "background-color: rgb(255, 255, 0)", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("UserManagerFormUi", "\350\256\276\345\256\232\350\260\203\350\257\225\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        UserNameLabel_3->setText(QApplication::translate("UserManagerFormUi", "\347\224\250\346\210\267\345\220\215:", 0, QApplication::UnicodeUTF8));
        OldDebugPwdLineEdit->setInputMask(QString());
        NewDebugPwdLineEdit->setInputMask(QString());
        Q_UNUSED(UserManagerFormUi);
    } // retranslateUi

};

namespace Ui {
    class UserManagerFormUi: public Ui_UserManagerFormUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGERFORM_H
