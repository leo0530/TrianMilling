/********************************************************************************
** Form generated from reading ui file 'softlimitform.ui'
**
** Created: Wed Jan 8 15:11:24 2020
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SOFTLIMITFORM_H
#define UI_SOFTLIMITFORM_H

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

class Ui_SoftLimitFormUi
{
public:
    SlGfwLabel *label;
    SlGfwGroupBox *groupBox;
    SlGfwLabel *label_2;
    SlGfwLabel *label_6;
    SlGfwLineEdit *LH_MotorLimitPosHighLineEdit;
    SlGfwLabel *label_7;
    SlGfwLineEdit *LH_MotorLimitPosLowLineEdit;
    SlGfwLabel *label_8;
    SlGfwLabel *label_9;
    SlGfwLabel *label_30;
    SlGfwLabel *label_31;
    SlGfwLineEdit *LV_MotorLimitPosHighLineEdit;
    SlGfwLabel *label_37;
    SlGfwLineEdit *LV_MotorLimitPosLowLineEdit;
    SlGfwLabel *label_40;
    SlGfwLabel *label_14;
    SlGfwLabel *label_15;
    SlGfwLineEdit *LH_CutterProtectLineEdit;
    SlGfwLabel *label_16;
    SlGfwLabel *label_17;
    SlGfwLineEdit *LV_CutterProtectLineEdit;
    SlGfwLabel *label_22;
    SlGfwLineEdit *H_CutBiasStepLineEdit;
    SlGfwLabel *label_23;
    SlGfwLineEdit *H_MinCutStepLineEdit;
    SlGfwLabel *label_26;
    SlGfwLabel *label_27;
    SlGfwGroupBox *groupBox_2;
    SlGfwLabel *label_3;
    SlGfwLabel *label_10;
    SlGfwLineEdit *RH_MotorLimitPosHighLineEdit;
    SlGfwLabel *label_11;
    SlGfwLineEdit *RH_MotorLimitPosLowLineEdit;
    SlGfwLabel *label_12;
    SlGfwLabel *label_13;
    SlGfwLabel *label_35;
    SlGfwLabel *label_36;
    SlGfwLineEdit *RV_MotorLimitPosHighLineEdit;
    SlGfwLineEdit *RV_MotorLimitPosLowLineEdit;
    SlGfwLabel *label_41;
    SlGfwLabel *label_42;
    SlGfwLineEdit *RH_CutterProtectLineEdit;
    SlGfwLabel *label_18;
    SlGfwLabel *label_19;
    SlGfwLineEdit *RV_CutterProtectLineEdit;
    SlGfwLabel *label_20;
    SlGfwLabel *label_21;
    SlGfwLabel *label_24;
    SlGfwLineEdit *V_CutBiasStepLineEdit;
    SlGfwLabel *label_25;
    SlGfwLineEdit *V_MinCutStepLineEdit;
    SlGfwLabel *label_28;
    SlGfwLabel *label_29;

    void setupUi(SlGfwDialogForm *SoftLimitFormUi)
    {
        if (SoftLimitFormUi->objectName().isEmpty())
            SoftLimitFormUi->setObjectName(QString::fromUtf8("SoftLimitFormUi"));
        SoftLimitFormUi->resize(599, 378);
        label = new SlGfwLabel(SoftLimitFormUi);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 24, 171, 38));
        QFont font;
        font.setFamily(QString::fromUtf8("Siemens AD CH Simplified"));
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setHmiFontSize(-5);
        label->setAlignment(Qt::AlignCenter);
        groupBox = new SlGfwGroupBox(SoftLimitFormUi);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(-8, 65, 301, 313));
        groupBox->setAutoFillBackground(false);
        groupBox->setHmiFonts(true);
        groupBox->setHmiColors(true);
        groupBox->setNavigationMode(true);
        groupBox->setHmiUseBigFont(false);
        groupBox->setHmiFontSize(-5);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        label_2 = new SlGfwLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(16, 0, 100, 21));
        label_2->setFont(font);
        label_2->setAutoFillBackground(false);
        label_2->setHmiFonts(true);
        label_2->setHmiColors(true);
        label_2->setHmiFontSize(-5);
        label_2->setInverseColors(true);
        label_6 = new SlGfwLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 47, 120, 31));
        label_6->setHmiFontSize(-5);
        LH_MotorLimitPosHighLineEdit = new SlGfwLineEdit(groupBox);
        LH_MotorLimitPosHighLineEdit->setObjectName(QString::fromUtf8("LH_MotorLimitPosHighLineEdit"));
        LH_MotorLimitPosHighLineEdit->setGeometry(QRect(160, 47, 65, 27));
        LH_MotorLimitPosHighLineEdit->setHmiFonts(true);
        LH_MotorLimitPosHighLineEdit->setHmiFontSize(0);
        LH_MotorLimitPosHighLineEdit->setAlignment(Qt::AlignHCenter);
        LH_MotorLimitPosHighLineEdit->setReadOnly(false);
        label_7 = new SlGfwLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(230, 47, 31, 31));
        label_7->setHmiFontSize(-5);
        LH_MotorLimitPosLowLineEdit = new SlGfwLineEdit(groupBox);
        LH_MotorLimitPosLowLineEdit->setObjectName(QString::fromUtf8("LH_MotorLimitPosLowLineEdit"));
        LH_MotorLimitPosLowLineEdit->setGeometry(QRect(160, 79, 65, 27));
        LH_MotorLimitPosLowLineEdit->setHmiFonts(true);
        LH_MotorLimitPosLowLineEdit->setHmiFontSize(0);
        LH_MotorLimitPosLowLineEdit->setAlignment(Qt::AlignHCenter);
        LH_MotorLimitPosLowLineEdit->setReadOnly(false);
        label_8 = new SlGfwLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 77, 120, 31));
        label_8->setHmiFontSize(-5);
        label_9 = new SlGfwLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(230, 77, 31, 31));
        label_9->setHmiFontSize(-5);
        label_30 = new SlGfwLabel(groupBox);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(230, 110, 31, 31));
        label_30->setHmiFontSize(-5);
        label_31 = new SlGfwLabel(groupBox);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(40, 110, 120, 31));
        label_31->setHmiFontSize(-5);
        LV_MotorLimitPosHighLineEdit = new SlGfwLineEdit(groupBox);
        LV_MotorLimitPosHighLineEdit->setObjectName(QString::fromUtf8("LV_MotorLimitPosHighLineEdit"));
        LV_MotorLimitPosHighLineEdit->setGeometry(QRect(160, 110, 65, 27));
        LV_MotorLimitPosHighLineEdit->setHmiFonts(true);
        LV_MotorLimitPosHighLineEdit->setHmiFontSize(0);
        LV_MotorLimitPosHighLineEdit->setAlignment(Qt::AlignHCenter);
        LV_MotorLimitPosHighLineEdit->setReadOnly(false);
        label_37 = new SlGfwLabel(groupBox);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(230, 140, 31, 31));
        label_37->setHmiFontSize(-5);
        LV_MotorLimitPosLowLineEdit = new SlGfwLineEdit(groupBox);
        LV_MotorLimitPosLowLineEdit->setObjectName(QString::fromUtf8("LV_MotorLimitPosLowLineEdit"));
        LV_MotorLimitPosLowLineEdit->setGeometry(QRect(160, 140, 65, 27));
        LV_MotorLimitPosLowLineEdit->setHmiFonts(true);
        LV_MotorLimitPosLowLineEdit->setHmiFontSize(0);
        LV_MotorLimitPosLowLineEdit->setAlignment(Qt::AlignHCenter);
        LV_MotorLimitPosLowLineEdit->setReadOnly(false);
        label_40 = new SlGfwLabel(groupBox);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(40, 140, 120, 31));
        label_40->setHmiFontSize(-5);
        label_14 = new SlGfwLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(40, 170, 120, 31));
        label_14->setHmiFontSize(-5);
        label_14->setAlignment(Qt::AlignCenter);
        label_15 = new SlGfwLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(230, 170, 31, 31));
        label_15->setHmiFontSize(-5);
        LH_CutterProtectLineEdit = new SlGfwLineEdit(groupBox);
        LH_CutterProtectLineEdit->setObjectName(QString::fromUtf8("LH_CutterProtectLineEdit"));
        LH_CutterProtectLineEdit->setGeometry(QRect(160, 170, 65, 27));
        LH_CutterProtectLineEdit->setHmiFonts(true);
        LH_CutterProtectLineEdit->setHmiFontSize(0);
        LH_CutterProtectLineEdit->setAlignment(Qt::AlignHCenter);
        LH_CutterProtectLineEdit->setReadOnly(false);
        label_16 = new SlGfwLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(230, 200, 31, 31));
        label_16->setHmiFontSize(-5);
        label_17 = new SlGfwLabel(groupBox);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(40, 200, 120, 31));
        label_17->setHmiFontSize(-5);
        label_17->setAlignment(Qt::AlignCenter);
        LV_CutterProtectLineEdit = new SlGfwLineEdit(groupBox);
        LV_CutterProtectLineEdit->setObjectName(QString::fromUtf8("LV_CutterProtectLineEdit"));
        LV_CutterProtectLineEdit->setGeometry(QRect(160, 200, 65, 27));
        LV_CutterProtectLineEdit->setHmiFonts(true);
        LV_CutterProtectLineEdit->setHmiFontSize(0);
        LV_CutterProtectLineEdit->setAlignment(Qt::AlignHCenter);
        LV_CutterProtectLineEdit->setReadOnly(false);
        label_22 = new SlGfwLabel(groupBox);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(40, 230, 120, 31));
        label_22->setHmiFontSize(-5);
        label_22->setAlignment(Qt::AlignCenter);
        H_CutBiasStepLineEdit = new SlGfwLineEdit(groupBox);
        H_CutBiasStepLineEdit->setObjectName(QString::fromUtf8("H_CutBiasStepLineEdit"));
        H_CutBiasStepLineEdit->setGeometry(QRect(160, 230, 65, 27));
        H_CutBiasStepLineEdit->setHmiFonts(true);
        H_CutBiasStepLineEdit->setHmiFontSize(0);
        H_CutBiasStepLineEdit->setAlignment(Qt::AlignHCenter);
        H_CutBiasStepLineEdit->setReadOnly(false);
        label_23 = new SlGfwLabel(groupBox);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(230, 230, 31, 31));
        label_23->setHmiFontSize(-5);
        H_MinCutStepLineEdit = new SlGfwLineEdit(groupBox);
        H_MinCutStepLineEdit->setObjectName(QString::fromUtf8("H_MinCutStepLineEdit"));
        H_MinCutStepLineEdit->setGeometry(QRect(160, 260, 65, 27));
        H_MinCutStepLineEdit->setHmiFonts(true);
        H_MinCutStepLineEdit->setHmiFontSize(0);
        H_MinCutStepLineEdit->setAlignment(Qt::AlignHCenter);
        H_MinCutStepLineEdit->setReadOnly(false);
        label_26 = new SlGfwLabel(groupBox);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(230, 260, 31, 31));
        label_26->setHmiFontSize(-5);
        label_27 = new SlGfwLabel(groupBox);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(40, 260, 120, 31));
        label_27->setHmiFontSize(-5);
        label_27->setAlignment(Qt::AlignCenter);
        groupBox_2 = new SlGfwGroupBox(SoftLimitFormUi);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(291, 65, 301, 313));
        groupBox_2->setAutoFillBackground(false);
        groupBox_2->setHmiFontSize(-5);
        groupBox_2->setCheckable(false);
        label_3 = new SlGfwLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(168, 0, 100, 21));
        label_3->setAutoFillBackground(false);
        label_3->setHmiFontSize(-5);
        label_3->setInverseColors(true);
        label_10 = new SlGfwLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(40, 52, 120, 31));
        label_10->setHmiFontSize(-5);
        RH_MotorLimitPosHighLineEdit = new SlGfwLineEdit(groupBox_2);
        RH_MotorLimitPosHighLineEdit->setObjectName(QString::fromUtf8("RH_MotorLimitPosHighLineEdit"));
        RH_MotorLimitPosHighLineEdit->setGeometry(QRect(162, 52, 65, 27));
        RH_MotorLimitPosHighLineEdit->setFont(font);
        RH_MotorLimitPosHighLineEdit->setHmiFonts(true);
        RH_MotorLimitPosHighLineEdit->setHmiFontSize(0);
        RH_MotorLimitPosHighLineEdit->setAlignment(Qt::AlignHCenter);
        RH_MotorLimitPosHighLineEdit->setReadOnly(false);
        label_11 = new SlGfwLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(230, 52, 31, 31));
        label_11->setHmiFontSize(-5);
        RH_MotorLimitPosLowLineEdit = new SlGfwLineEdit(groupBox_2);
        RH_MotorLimitPosLowLineEdit->setObjectName(QString::fromUtf8("RH_MotorLimitPosLowLineEdit"));
        RH_MotorLimitPosLowLineEdit->setGeometry(QRect(162, 84, 65, 27));
        RH_MotorLimitPosLowLineEdit->setHmiFonts(true);
        RH_MotorLimitPosLowLineEdit->setHmiFontSize(0);
        RH_MotorLimitPosLowLineEdit->setAlignment(Qt::AlignHCenter);
        RH_MotorLimitPosLowLineEdit->setReadOnly(false);
        label_12 = new SlGfwLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(40, 82, 120, 31));
        label_12->setHmiFontSize(-5);
        label_13 = new SlGfwLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(230, 82, 31, 31));
        label_13->setHmiFontSize(-5);
        label_35 = new SlGfwLabel(groupBox_2);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(230, 114, 31, 31));
        label_35->setHmiFontSize(-5);
        label_36 = new SlGfwLabel(groupBox_2);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(40, 114, 120, 31));
        label_36->setHmiFontSize(-5);
        RV_MotorLimitPosHighLineEdit = new SlGfwLineEdit(groupBox_2);
        RV_MotorLimitPosHighLineEdit->setObjectName(QString::fromUtf8("RV_MotorLimitPosHighLineEdit"));
        RV_MotorLimitPosHighLineEdit->setGeometry(QRect(162, 114, 65, 27));
        RV_MotorLimitPosHighLineEdit->setHmiFonts(true);
        RV_MotorLimitPosHighLineEdit->setHmiFontSize(0);
        RV_MotorLimitPosHighLineEdit->setAlignment(Qt::AlignHCenter);
        RV_MotorLimitPosHighLineEdit->setReadOnly(false);
        RV_MotorLimitPosLowLineEdit = new SlGfwLineEdit(groupBox_2);
        RV_MotorLimitPosLowLineEdit->setObjectName(QString::fromUtf8("RV_MotorLimitPosLowLineEdit"));
        RV_MotorLimitPosLowLineEdit->setGeometry(QRect(162, 143, 65, 27));
        RV_MotorLimitPosLowLineEdit->setHmiFonts(true);
        RV_MotorLimitPosLowLineEdit->setHmiFontSize(0);
        RV_MotorLimitPosLowLineEdit->setAlignment(Qt::AlignHCenter);
        RV_MotorLimitPosLowLineEdit->setReadOnly(false);
        label_41 = new SlGfwLabel(groupBox_2);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(40, 143, 120, 31));
        label_41->setHmiFontSize(-5);
        label_42 = new SlGfwLabel(groupBox_2);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(230, 143, 31, 31));
        label_42->setHmiFontSize(-5);
        RH_CutterProtectLineEdit = new SlGfwLineEdit(groupBox_2);
        RH_CutterProtectLineEdit->setObjectName(QString::fromUtf8("RH_CutterProtectLineEdit"));
        RH_CutterProtectLineEdit->setGeometry(QRect(162, 173, 65, 27));
        RH_CutterProtectLineEdit->setHmiFonts(true);
        RH_CutterProtectLineEdit->setHmiFontSize(0);
        RH_CutterProtectLineEdit->setAlignment(Qt::AlignHCenter);
        RH_CutterProtectLineEdit->setReadOnly(false);
        label_18 = new SlGfwLabel(groupBox_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(230, 171, 31, 31));
        label_18->setHmiFontSize(-5);
        label_19 = new SlGfwLabel(groupBox_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(40, 171, 120, 31));
        label_19->setHmiFontSize(-5);
        label_19->setAlignment(Qt::AlignCenter);
        RV_CutterProtectLineEdit = new SlGfwLineEdit(groupBox_2);
        RV_CutterProtectLineEdit->setObjectName(QString::fromUtf8("RV_CutterProtectLineEdit"));
        RV_CutterProtectLineEdit->setGeometry(QRect(162, 202, 65, 27));
        RV_CutterProtectLineEdit->setHmiFonts(true);
        RV_CutterProtectLineEdit->setHmiFontSize(0);
        RV_CutterProtectLineEdit->setAlignment(Qt::AlignHCenter);
        RV_CutterProtectLineEdit->setReadOnly(false);
        label_20 = new SlGfwLabel(groupBox_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(230, 200, 31, 31));
        label_20->setHmiFontSize(-5);
        label_21 = new SlGfwLabel(groupBox_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(40, 200, 120, 31));
        label_21->setHmiFontSize(-5);
        label_21->setAlignment(Qt::AlignCenter);
        label_24 = new SlGfwLabel(groupBox_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(40, 230, 120, 31));
        label_24->setHmiFontSize(-5);
        label_24->setAlignment(Qt::AlignCenter);
        V_CutBiasStepLineEdit = new SlGfwLineEdit(groupBox_2);
        V_CutBiasStepLineEdit->setObjectName(QString::fromUtf8("V_CutBiasStepLineEdit"));
        V_CutBiasStepLineEdit->setGeometry(QRect(162, 232, 65, 27));
        V_CutBiasStepLineEdit->setHmiFonts(true);
        V_CutBiasStepLineEdit->setHmiFontSize(0);
        V_CutBiasStepLineEdit->setAlignment(Qt::AlignHCenter);
        V_CutBiasStepLineEdit->setReadOnly(false);
        label_25 = new SlGfwLabel(groupBox_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(230, 230, 31, 31));
        label_25->setHmiFontSize(-5);
        V_MinCutStepLineEdit = new SlGfwLineEdit(groupBox_2);
        V_MinCutStepLineEdit->setObjectName(QString::fromUtf8("V_MinCutStepLineEdit"));
        V_MinCutStepLineEdit->setGeometry(QRect(162, 262, 65, 27));
        V_MinCutStepLineEdit->setHmiFonts(true);
        V_MinCutStepLineEdit->setHmiFontSize(0);
        V_MinCutStepLineEdit->setAlignment(Qt::AlignHCenter);
        V_MinCutStepLineEdit->setReadOnly(false);
        label_28 = new SlGfwLabel(groupBox_2);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(40, 260, 120, 31));
        label_28->setHmiFontSize(-5);
        label_28->setAlignment(Qt::AlignCenter);
        label_29 = new SlGfwLabel(groupBox_2);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(230, 260, 31, 31));
        label_29->setHmiFontSize(-5);

        retranslateUi(SoftLimitFormUi);

        QMetaObject::connectSlotsByName(SoftLimitFormUi);
    } // setupUi

    void retranslateUi(SlGfwDialogForm *SoftLimitFormUi)
    {
        label->setStyleSheet(QApplication::translate("SoftLimitFormUi", "background-color: rgb(255, 255, 0)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SoftLimitFormUi", "\347\224\265\346\234\272\350\275\257\346\236\201\351\231\220", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label_2->setStyleSheet(QApplication::translate("SoftLimitFormUi", "background-color: rgb(0, 0, 0);", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SoftLimitFormUi", "\345\267\246\351\223\243\345\211\212\345\215\225\345\205\203", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SoftLimitFormUi", "\346\250\252\345\220\221\347\224\265\346\234\272\344\270\212\351\231\220\344\275\215", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SoftLimitFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SoftLimitFormUi", "\346\250\252\345\220\221\347\224\265\346\234\272\344\270\213\351\231\220\344\275\215", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SoftLimitFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("SoftLimitFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("SoftLimitFormUi", "\345\236\202\345\220\221\347\224\265\346\234\272\344\270\212\351\231\220\344\275\215", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("SoftLimitFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("SoftLimitFormUi", "\345\236\202\345\220\221\347\224\265\346\234\272\344\270\213\351\231\220\344\275\215", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("SoftLimitFormUi", "\346\250\252\345\220\221\350\277\233\345\210\200\344\277\235\346\212\244", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("SoftLimitFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("SoftLimitFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("SoftLimitFormUi", "\345\236\202\345\220\221\350\277\233\345\210\200\344\277\235\346\212\244", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("SoftLimitFormUi", "\346\250\252\345\220\221\345\210\206\346\255\245\350\277\233\345\210\200\345\200\274", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("SoftLimitFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("SoftLimitFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("SoftLimitFormUi", "\346\250\252\345\220\221\346\234\200\345\260\217\350\277\233\345\210\200\351\207\217", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        label_3->setStyleSheet(QApplication::translate("SoftLimitFormUi", "background-color: rgb(0, 0, 0);", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SoftLimitFormUi", "\345\217\263\351\223\243\345\211\212\345\215\225\345\205\203", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("SoftLimitFormUi", "\346\250\252\345\220\221\347\224\265\346\234\272\344\270\212\351\231\220\344\275\215", 0, QApplication::UnicodeUTF8));
        RH_MotorLimitPosHighLineEdit->setValue(QString());
        label_11->setText(QApplication::translate("SoftLimitFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("SoftLimitFormUi", "\346\250\252\345\220\221\347\224\265\346\234\272\344\270\213\351\231\220\344\275\215", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("SoftLimitFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("SoftLimitFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("SoftLimitFormUi", "\345\236\202\345\220\221\347\224\265\346\234\272\344\270\212\351\231\220\344\275\215", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("SoftLimitFormUi", "\345\236\202\345\220\221\347\224\265\346\234\272\344\270\213\351\231\220\344\275\215", 0, QApplication::UnicodeUTF8));
        label_42->setText(QApplication::translate("SoftLimitFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("SoftLimitFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("SoftLimitFormUi", "\346\250\252\345\220\221\350\277\233\345\210\200\344\277\235\346\212\244", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("SoftLimitFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("SoftLimitFormUi", "\345\236\202\345\220\221\350\277\233\345\210\200\344\277\235\346\212\244", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("SoftLimitFormUi", "\345\236\202\345\220\221\345\210\206\346\255\245\350\277\233\345\210\200\345\200\274", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("SoftLimitFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("SoftLimitFormUi", "\345\236\202\345\220\221\346\234\200\345\260\217\350\277\233\345\210\200\351\207\217", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("SoftLimitFormUi", "mm", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(SoftLimitFormUi);
    } // retranslateUi

};

namespace Ui {
    class SoftLimitFormUi: public Ui_SoftLimitFormUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOFTLIMITFORM_H
