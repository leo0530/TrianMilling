/********************************************************************************
** Form generated from reading ui file 'systemform.ui'
**
** Created: Wed Jan 8 15:11:25 2020
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SYSTEMFORM_H
#define UI_SYSTEMFORM_H

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

class Ui_SystemFormUi
{
public:
    SlGfwLabel *label;
    SlGfwGroupBox *groupBox;
    SlGfwLabel *label_2;
    SlGfwLabel *label_6;
    SlGfwLineEdit *LH_RailOffsetLineEdit;
    SlGfwLabel *label_7;
    SlGfwLineEdit *LV_RailOffsetLineEdit;
    SlGfwLabel *label_8;
    SlGfwLabel *label_9;
    SlGfwLabel *label_30;
    SlGfwLabel *label_31;
    SlGfwLabel *label_32;
    SlGfwLabel *label_33;
    SlGfwLineEdit *LV_CalibPosLineEdit1;
    SlGfwLineEdit *LH_CalibPosLineEdit1;
    SlGfwLabel *label_52;
    SlGfwLineEdit *LV_CalibPosLineEdit2;
    SlGfwLineEdit *LH_CalibPosLineEdit2;
    SlGfwLabel *label_53;
    SlGfwLabel *label_54;
    SlGfwLabel *label_55;
    SlGfwLabel *label_62;
    SlGfwLineEdit *LV_MotorCalibPosLineEdit;
    SlGfwLabel *label_63;
    SlGfwGroupBox *groupBox_2;
    SlGfwLabel *label_3;
    SlGfwLabel *label_10;
    SlGfwLineEdit *RH_RailOffsetLineEdit;
    SlGfwLabel *label_11;
    SlGfwLineEdit *RV_RailOffsetLineEdit;
    SlGfwLabel *label_12;
    SlGfwLabel *label_13;
    SlGfwLabel *label_34;
    SlGfwLabel *label_35;
    SlGfwLabel *label_36;
    SlGfwLineEdit *RV_CalibPosLineEdit1;
    SlGfwLabel *label_49;
    SlGfwLineEdit *RH_CalibPosLineEdit1;
    SlGfwLineEdit *RV_CalibPosLineEdit2;
    SlGfwLabel *label_56;
    SlGfwLabel *label_57;
    SlGfwLabel *label_58;
    SlGfwLineEdit *RH_CalibPosLineEdit2;
    SlGfwLabel *label_59;
    SlGfwLineEdit *RV_MotorCalibPosLineEdit;
    SlGfwLabel *label_64;
    SlGfwLabel *label_65;
    SlGfwGroupBox *groupBox_5;
    SlGfwLabel *label_37;
    SlGfwLabel *label_38;
    SlGfwLineEdit *V_RapidMoveSpeedLineEdit;
    SlGfwLabel *label_39;
    SlGfwLabel *label_40;
    SlGfwLineEdit *H_RapidMoveSpeedLineEdit;
    SlGfwLabel *label_41;
    SlGfwLabel *label_42;
    SlGfwLineEdit *AxisAngularLowerSpeedLineEdit;
    SlGfwLabel *label_43;
    SlGfwLineEdit *OffsetSlopeLengthLineEdit;
    SlGfwLabel *label_44;
    SlGfwLineEdit *L_SMWDiameterLineEdit;
    SlGfwLabel *label_45;
    SlGfwLabel *label_46;
    SlGfwLineEdit *AxisAngularHighSpeedLineEdit;
    SlGfwLabel *label_47;
    SlGfwLabel *label_48;
    SlGfwLineEdit *R_SMWDiameterLineEdit;
    SlGfwLabel *label_60;
    SlGfwLabel *label_61;
    SlGfwGroupBox *groupBox_6;
    SlGfwLabel *label_22;
    SlGfwLabel *label_23;
    SlGfwLineEdit *LiftCutterPowerLineEdit;
    SlGfwLabel *label_24;
    SlGfwLineEdit *LiftCutterTimeLineEdit;
    SlGfwLabel *label_25;
    SlGfwLabel *label_50;
    SlGfwGroupBox *groupBox_7;
    SlGfwLabel *label_26;
    SlGfwLabel *label_27;
    SlGfwLineEdit *EndCuttingPowerLineEdit;
    SlGfwLabel *label_28;
    SlGfwLineEdit *EndCuttingTimeLineEdit;
    SlGfwLabel *label_29;
    SlGfwLabel *label_51;

    void setupUi(SlGfwDialogForm *SystemFormUi)
    {
        if (SystemFormUi->objectName().isEmpty())
            SystemFormUi->setObjectName(QString::fromUtf8("SystemFormUi"));
        SystemFormUi->resize(599, 377);
        SystemFormUi->setFocusPolicy(Qt::NoFocus);
        SystemFormUi->setHmiFontSize(-10);
        label = new SlGfwLabel(SystemFormUi);
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
        groupBox = new SlGfwGroupBox(SystemFormUi);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(-8, 65, 301, 244));
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
        label_2->setGeometry(QRect(20, 0, 100, 21));
        label_2->setFont(font);
        label_2->setAutoFillBackground(false);
        label_2->setHmiFonts(true);
        label_2->setHmiColors(true);
        label_2->setHmiFontSize(-5);
        label_2->setInverseColors(true);
        label_6 = new SlGfwLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(22, 27, 81, 31));
        label_6->setHmiFontSize(-5);
        LH_RailOffsetLineEdit = new SlGfwLineEdit(groupBox);
        LH_RailOffsetLineEdit->setObjectName(QString::fromUtf8("LH_RailOffsetLineEdit"));
        LH_RailOffsetLineEdit->setGeometry(QRect(96, 28, 51, 27));
        LH_RailOffsetLineEdit->setHmiFonts(true);
        LH_RailOffsetLineEdit->setHmiFontSize(0);
        LH_RailOffsetLineEdit->setAlignment(Qt::AlignHCenter);
        label_7 = new SlGfwLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(154, 28, 31, 31));
        label_7->setHmiFontSize(-5);
        LV_RailOffsetLineEdit = new SlGfwLineEdit(groupBox);
        LV_RailOffsetLineEdit->setObjectName(QString::fromUtf8("LV_RailOffsetLineEdit"));
        LV_RailOffsetLineEdit->setGeometry(QRect(96, 58, 51, 27));
        LV_RailOffsetLineEdit->setHmiFonts(true);
        LV_RailOffsetLineEdit->setHmiFontSize(0);
        LV_RailOffsetLineEdit->setAlignment(Qt::AlignHCenter);
        label_8 = new SlGfwLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(22, 55, 81, 31));
        label_8->setHmiFontSize(-5);
        label_9 = new SlGfwLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(154, 56, 31, 31));
        label_9->setHmiFontSize(-5);
        label_30 = new SlGfwLabel(groupBox);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(154, 87, 31, 31));
        label_30->setHmiFontSize(-5);
        label_31 = new SlGfwLabel(groupBox);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(22, 87, 81, 31));
        label_31->setHmiFontSize(-5);
        label_32 = new SlGfwLabel(groupBox);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(22, 145, 81, 31));
        label_32->setHmiFontSize(-5);
        label_33 = new SlGfwLabel(groupBox);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(154, 145, 31, 31));
        label_33->setHmiFontSize(-5);
        LV_CalibPosLineEdit1 = new SlGfwLineEdit(groupBox);
        LV_CalibPosLineEdit1->setObjectName(QString::fromUtf8("LV_CalibPosLineEdit1"));
        LV_CalibPosLineEdit1->setGeometry(QRect(96, 148, 51, 27));
        LV_CalibPosLineEdit1->setHmiFonts(true);
        LV_CalibPosLineEdit1->setHmiFontSize(0);
        LV_CalibPosLineEdit1->setAlignment(Qt::AlignLeading);
        LH_CalibPosLineEdit1 = new SlGfwLineEdit(groupBox);
        LH_CalibPosLineEdit1->setObjectName(QString::fromUtf8("LH_CalibPosLineEdit1"));
        LH_CalibPosLineEdit1->setGeometry(QRect(96, 88, 51, 27));
        LH_CalibPosLineEdit1->setHmiFonts(true);
        LH_CalibPosLineEdit1->setHmiFontSize(0);
        LH_CalibPosLineEdit1->setAlignment(Qt::AlignLeading);
        label_52 = new SlGfwLabel(groupBox);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(154, 175, 31, 31));
        label_52->setHmiFontSize(-5);
        LV_CalibPosLineEdit2 = new SlGfwLineEdit(groupBox);
        LV_CalibPosLineEdit2->setObjectName(QString::fromUtf8("LV_CalibPosLineEdit2"));
        LV_CalibPosLineEdit2->setGeometry(QRect(96, 178, 51, 27));
        LV_CalibPosLineEdit2->setHmiFonts(true);
        LV_CalibPosLineEdit2->setHmiFontSize(0);
        LV_CalibPosLineEdit2->setAlignment(Qt::AlignLeading);
        LH_CalibPosLineEdit2 = new SlGfwLineEdit(groupBox);
        LH_CalibPosLineEdit2->setObjectName(QString::fromUtf8("LH_CalibPosLineEdit2"));
        LH_CalibPosLineEdit2->setGeometry(QRect(96, 118, 51, 27));
        LH_CalibPosLineEdit2->setHmiFonts(true);
        LH_CalibPosLineEdit2->setHmiFontSize(0);
        LH_CalibPosLineEdit2->setAlignment(Qt::AlignLeading);
        label_53 = new SlGfwLabel(groupBox);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(154, 117, 31, 20));
        label_53->setHmiFontSize(-5);
        label_54 = new SlGfwLabel(groupBox);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setGeometry(QRect(22, 117, 81, 31));
        label_54->setHmiFontSize(-5);
        label_55 = new SlGfwLabel(groupBox);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setGeometry(QRect(22, 175, 81, 31));
        label_55->setHmiFontSize(-5);
        label_62 = new SlGfwLabel(groupBox);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setGeometry(QRect(22, 205, 81, 31));
        label_62->setHmiFontSize(-5);
        LV_MotorCalibPosLineEdit = new SlGfwLineEdit(groupBox);
        LV_MotorCalibPosLineEdit->setObjectName(QString::fromUtf8("LV_MotorCalibPosLineEdit"));
        LV_MotorCalibPosLineEdit->setGeometry(QRect(96, 208, 51, 27));
        LV_MotorCalibPosLineEdit->setHmiFonts(true);
        LV_MotorCalibPosLineEdit->setHmiFontSize(0);
        LV_MotorCalibPosLineEdit->setAlignment(Qt::AlignLeading);
        label_63 = new SlGfwLabel(groupBox);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setGeometry(QRect(154, 205, 31, 31));
        label_63->setHmiFontSize(-5);
        groupBox_2 = new SlGfwGroupBox(SystemFormUi);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(291, 65, 301, 244));
        groupBox_2->setAutoFillBackground(false);
        groupBox_2->setHmiFontSize(-5);
        groupBox_2->setCheckable(false);
        label_3 = new SlGfwLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(170, 0, 100, 21));
        label_3->setAutoFillBackground(false);
        label_3->setHmiFontSize(-5);
        label_3->setInverseColors(true);
        label_10 = new SlGfwLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(109, 28, 81, 31));
        label_10->setHmiFontSize(-5);
        RH_RailOffsetLineEdit = new SlGfwLineEdit(groupBox_2);
        RH_RailOffsetLineEdit->setObjectName(QString::fromUtf8("RH_RailOffsetLineEdit"));
        RH_RailOffsetLineEdit->setGeometry(QRect(183, 28, 51, 27));
        RH_RailOffsetLineEdit->setFont(font);
        RH_RailOffsetLineEdit->setHmiFonts(true);
        RH_RailOffsetLineEdit->setHmiFontSize(0);
        RH_RailOffsetLineEdit->setAlignment(Qt::AlignHCenter);
        label_11 = new SlGfwLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(241, 28, 31, 31));
        label_11->setHmiFontSize(-5);
        RV_RailOffsetLineEdit = new SlGfwLineEdit(groupBox_2);
        RV_RailOffsetLineEdit->setObjectName(QString::fromUtf8("RV_RailOffsetLineEdit"));
        RV_RailOffsetLineEdit->setGeometry(QRect(183, 58, 51, 27));
        RV_RailOffsetLineEdit->setHmiFonts(true);
        RV_RailOffsetLineEdit->setHmiFontSize(0);
        RV_RailOffsetLineEdit->setAlignment(Qt::AlignHCenter);
        label_12 = new SlGfwLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(109, 56, 81, 31));
        label_12->setHmiFontSize(-5);
        label_13 = new SlGfwLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(241, 56, 271, 31));
        label_13->setHmiFontSize(-5);
        label_34 = new SlGfwLabel(groupBox_2);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(242, 145, 31, 31));
        label_34->setHmiFontSize(-5);
        label_35 = new SlGfwLabel(groupBox_2);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(242, 87, 31, 31));
        label_35->setHmiFontSize(-5);
        label_36 = new SlGfwLabel(groupBox_2);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(110, 87, 81, 31));
        label_36->setHmiFontSize(-5);
        RV_CalibPosLineEdit1 = new SlGfwLineEdit(groupBox_2);
        RV_CalibPosLineEdit1->setObjectName(QString::fromUtf8("RV_CalibPosLineEdit1"));
        RV_CalibPosLineEdit1->setGeometry(QRect(183, 148, 51, 27));
        RV_CalibPosLineEdit1->setHmiFonts(true);
        RV_CalibPosLineEdit1->setHmiFontSize(0);
        RV_CalibPosLineEdit1->setAlignment(Qt::AlignLeading);
        label_49 = new SlGfwLabel(groupBox_2);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(110, 145, 81, 31));
        label_49->setHmiFontSize(-5);
        RH_CalibPosLineEdit1 = new SlGfwLineEdit(groupBox_2);
        RH_CalibPosLineEdit1->setObjectName(QString::fromUtf8("RH_CalibPosLineEdit1"));
        RH_CalibPosLineEdit1->setGeometry(QRect(183, 88, 51, 27));
        RH_CalibPosLineEdit1->setHmiFonts(true);
        RH_CalibPosLineEdit1->setHmiFontSize(0);
        RH_CalibPosLineEdit1->setAlignment(Qt::AlignLeading);
        RV_CalibPosLineEdit2 = new SlGfwLineEdit(groupBox_2);
        RV_CalibPosLineEdit2->setObjectName(QString::fromUtf8("RV_CalibPosLineEdit2"));
        RV_CalibPosLineEdit2->setGeometry(QRect(183, 178, 51, 27));
        RV_CalibPosLineEdit2->setHmiFonts(true);
        RV_CalibPosLineEdit2->setHmiFontSize(0);
        RV_CalibPosLineEdit2->setAlignment(Qt::AlignLeading);
        label_56 = new SlGfwLabel(groupBox_2);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setGeometry(QRect(110, 175, 81, 31));
        label_56->setHmiFontSize(-5);
        label_57 = new SlGfwLabel(groupBox_2);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setGeometry(QRect(242, 117, 31, 31));
        label_57->setHmiFontSize(-5);
        label_58 = new SlGfwLabel(groupBox_2);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setGeometry(QRect(242, 175, 31, 31));
        label_58->setHmiFontSize(-5);
        RH_CalibPosLineEdit2 = new SlGfwLineEdit(groupBox_2);
        RH_CalibPosLineEdit2->setObjectName(QString::fromUtf8("RH_CalibPosLineEdit2"));
        RH_CalibPosLineEdit2->setGeometry(QRect(183, 118, 51, 27));
        RH_CalibPosLineEdit2->setHmiFonts(true);
        RH_CalibPosLineEdit2->setHmiFontSize(0);
        RH_CalibPosLineEdit2->setAlignment(Qt::AlignLeading);
        label_59 = new SlGfwLabel(groupBox_2);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setGeometry(QRect(110, 117, 81, 31));
        label_59->setHmiFontSize(-5);
        RV_MotorCalibPosLineEdit = new SlGfwLineEdit(groupBox_2);
        RV_MotorCalibPosLineEdit->setObjectName(QString::fromUtf8("RV_MotorCalibPosLineEdit"));
        RV_MotorCalibPosLineEdit->setGeometry(QRect(183, 208, 51, 27));
        RV_MotorCalibPosLineEdit->setHmiFonts(true);
        RV_MotorCalibPosLineEdit->setHmiFontSize(0);
        RV_MotorCalibPosLineEdit->setAlignment(Qt::AlignLeading);
        label_64 = new SlGfwLabel(groupBox_2);
        label_64->setObjectName(QString::fromUtf8("label_64"));
        label_64->setGeometry(QRect(242, 205, 31, 31));
        label_64->setHmiFontSize(-5);
        label_65 = new SlGfwLabel(groupBox_2);
        label_65->setObjectName(QString::fromUtf8("label_65"));
        label_65->setGeometry(QRect(110, 205, 81, 31));
        label_65->setHmiFontSize(-5);
        groupBox_5 = new SlGfwGroupBox(SystemFormUi);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(179, 83, 215, 215));
        groupBox_5->setMouseTracking(false);
        groupBox_5->setAutoFillBackground(true);
        groupBox_5->setHmiFontSize(-5);
        label_37 = new SlGfwLabel(groupBox_5);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(6, 36, 101, 31));
        label_37->setFont(font);
        label_37->setHmiFonts(true);
        label_37->setHmiFontSize(-3);
        label_38 = new SlGfwLabel(groupBox_5);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(160, 7, 51, 31));
        label_38->setFont(font);
        label_38->setHmiFonts(true);
        label_38->setHmiFontSize(-5);
        V_RapidMoveSpeedLineEdit = new SlGfwLineEdit(groupBox_5);
        V_RapidMoveSpeedLineEdit->setObjectName(QString::fromUtf8("V_RapidMoveSpeedLineEdit"));
        V_RapidMoveSpeedLineEdit->setGeometry(QRect(105, 36, 51, 27));
        V_RapidMoveSpeedLineEdit->setFont(font);
        V_RapidMoveSpeedLineEdit->setHmiFonts(true);
        V_RapidMoveSpeedLineEdit->setHmiFontSize(0);
        V_RapidMoveSpeedLineEdit->setAlignment(Qt::AlignHCenter);
        label_39 = new SlGfwLabel(groupBox_5);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(6, 7, 101, 31));
        label_39->setFont(font);
        label_39->setHmiFonts(true);
        label_39->setHmiFontSize(-3);
        label_40 = new SlGfwLabel(groupBox_5);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(160, 36, 51, 31));
        label_40->setFont(font);
        label_40->setHmiFonts(true);
        label_40->setHmiFontSize(-5);
        H_RapidMoveSpeedLineEdit = new SlGfwLineEdit(groupBox_5);
        H_RapidMoveSpeedLineEdit->setObjectName(QString::fromUtf8("H_RapidMoveSpeedLineEdit"));
        H_RapidMoveSpeedLineEdit->setGeometry(QRect(105, 7, 51, 27));
        H_RapidMoveSpeedLineEdit->setFont(font);
        H_RapidMoveSpeedLineEdit->setHmiFonts(true);
        H_RapidMoveSpeedLineEdit->setHmiFontSize(0);
        H_RapidMoveSpeedLineEdit->setAlignment(Qt::AlignHCenter);
        label_41 = new SlGfwLabel(groupBox_5);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(6, 65, 101, 31));
        label_41->setFont(font);
        label_41->setHmiFonts(true);
        label_41->setHmiFontSize(-3);
        label_42 = new SlGfwLabel(groupBox_5);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(160, 65, 41, 31));
        label_42->setFont(font);
        label_42->setHmiFonts(true);
        label_42->setHmiFontSize(-5);
        AxisAngularLowerSpeedLineEdit = new SlGfwLineEdit(groupBox_5);
        AxisAngularLowerSpeedLineEdit->setObjectName(QString::fromUtf8("AxisAngularLowerSpeedLineEdit"));
        AxisAngularLowerSpeedLineEdit->setGeometry(QRect(105, 65, 51, 27));
        AxisAngularLowerSpeedLineEdit->setFont(font);
        AxisAngularLowerSpeedLineEdit->setHmiFonts(true);
        AxisAngularLowerSpeedLineEdit->setHmiFontSize(0);
        AxisAngularLowerSpeedLineEdit->setAlignment(Qt::AlignHCenter);
        label_43 = new SlGfwLabel(groupBox_5);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(160, 123, 31, 31));
        label_43->setFont(font);
        label_43->setHmiFonts(true);
        label_43->setHmiFontSize(-5);
        OffsetSlopeLengthLineEdit = new SlGfwLineEdit(groupBox_5);
        OffsetSlopeLengthLineEdit->setObjectName(QString::fromUtf8("OffsetSlopeLengthLineEdit"));
        OffsetSlopeLengthLineEdit->setGeometry(QRect(105, 181, 51, 27));
        OffsetSlopeLengthLineEdit->setFont(font);
        OffsetSlopeLengthLineEdit->setHmiFonts(true);
        OffsetSlopeLengthLineEdit->setHmiFontSize(0);
        OffsetSlopeLengthLineEdit->setAlignment(Qt::AlignHCenter);
        label_44 = new SlGfwLabel(groupBox_5);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(6, 123, 101, 31));
        label_44->setFont(font);
        label_44->setHmiFonts(true);
        label_44->setHmiFontSize(-3);
        L_SMWDiameterLineEdit = new SlGfwLineEdit(groupBox_5);
        L_SMWDiameterLineEdit->setObjectName(QString::fromUtf8("L_SMWDiameterLineEdit"));
        L_SMWDiameterLineEdit->setGeometry(QRect(105, 123, 51, 27));
        L_SMWDiameterLineEdit->setFont(font);
        L_SMWDiameterLineEdit->setHmiFonts(true);
        L_SMWDiameterLineEdit->setHmiFontSize(0);
        L_SMWDiameterLineEdit->setAlignment(Qt::AlignHCenter);
        label_45 = new SlGfwLabel(groupBox_5);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(6, 181, 101, 31));
        label_45->setFont(font);
        label_45->setHmiFonts(true);
        label_45->setHmiFontSize(-3);
        label_46 = new SlGfwLabel(groupBox_5);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(6, 94, 101, 31));
        label_46->setFont(font);
        label_46->setHmiFonts(true);
        label_46->setHmiFontSize(-3);
        AxisAngularHighSpeedLineEdit = new SlGfwLineEdit(groupBox_5);
        AxisAngularHighSpeedLineEdit->setObjectName(QString::fromUtf8("AxisAngularHighSpeedLineEdit"));
        AxisAngularHighSpeedLineEdit->setGeometry(QRect(105, 94, 51, 27));
        AxisAngularHighSpeedLineEdit->setFont(font);
        AxisAngularHighSpeedLineEdit->setHmiFonts(true);
        AxisAngularHighSpeedLineEdit->setHmiFontSize(0);
        AxisAngularHighSpeedLineEdit->setAlignment(Qt::AlignHCenter);
        label_47 = new SlGfwLabel(groupBox_5);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(160, 181, 41, 31));
        label_47->setFont(font);
        label_47->setHmiFonts(true);
        label_47->setHmiFontSize(-5);
        label_48 = new SlGfwLabel(groupBox_5);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(160, 94, 40, 31));
        label_48->setFont(font);
        label_48->setHmiFonts(true);
        label_48->setHmiFontSize(-5);
        R_SMWDiameterLineEdit = new SlGfwLineEdit(groupBox_5);
        R_SMWDiameterLineEdit->setObjectName(QString::fromUtf8("R_SMWDiameterLineEdit"));
        R_SMWDiameterLineEdit->setGeometry(QRect(105, 152, 51, 27));
        R_SMWDiameterLineEdit->setFont(font);
        R_SMWDiameterLineEdit->setHmiFonts(true);
        R_SMWDiameterLineEdit->setHmiFontSize(0);
        R_SMWDiameterLineEdit->setAlignment(Qt::AlignHCenter);
        label_60 = new SlGfwLabel(groupBox_5);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setGeometry(QRect(160, 152, 31, 31));
        label_60->setFont(font);
        label_60->setHmiFonts(true);
        label_60->setHmiFontSize(-5);
        label_61 = new SlGfwLabel(groupBox_5);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setGeometry(QRect(6, 152, 101, 31));
        label_61->setFont(font);
        label_61->setHmiFonts(true);
        label_61->setHmiFontSize(-3);
        groupBox_6 = new SlGfwGroupBox(SystemFormUi);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(-8, 307, 301, 70));
        groupBox_6->setAutoFillBackground(false);
        groupBox_6->setHmiFontSize(-5);
        groupBox_6->setCheckable(false);
        label_22 = new SlGfwLabel(groupBox_6);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(20, 0, 121, 21));
        label_22->setAutoFillBackground(false);
        label_22->setHmiFontSize(-5);
        label_22->setInverseColors(true);
        label_23 = new SlGfwLabel(groupBox_6);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(70, 20, 41, 25));
        label_23->setHmiFontSize(-5);
        LiftCutterPowerLineEdit = new SlGfwLineEdit(groupBox_6);
        LiftCutterPowerLineEdit->setObjectName(QString::fromUtf8("LiftCutterPowerLineEdit"));
        LiftCutterPowerLineEdit->setGeometry(QRect(60, 42, 51, 24));
        LiftCutterPowerLineEdit->setHmiFonts(true);
        LiftCutterPowerLineEdit->setHmiFontSize(0);
        LiftCutterPowerLineEdit->setAlignment(Qt::AlignHCenter);
        label_24 = new SlGfwLabel(groupBox_6);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(120, 42, 31, 25));
        label_24->setHmiFontSize(-5);
        LiftCutterTimeLineEdit = new SlGfwLineEdit(groupBox_6);
        LiftCutterTimeLineEdit->setObjectName(QString::fromUtf8("LiftCutterTimeLineEdit"));
        LiftCutterTimeLineEdit->setGeometry(QRect(160, 42, 51, 24));
        LiftCutterTimeLineEdit->setHmiFonts(true);
        LiftCutterTimeLineEdit->setHmiFontSize(0);
        LiftCutterTimeLineEdit->setAlignment(Qt::AlignHCenter);
        label_25 = new SlGfwLabel(groupBox_6);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(167, 20, 41, 25));
        label_25->setHmiFontSize(-5);
        label_50 = new SlGfwLabel(groupBox_6);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(214, 41, 31, 25));
        label_50->setHmiFontSize(-5);
        groupBox_7 = new SlGfwGroupBox(SystemFormUi);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(291, 307, 301, 70));
        groupBox_7->setAutoFillBackground(false);
        groupBox_7->setHmiFontSize(-5);
        groupBox_7->setCheckable(false);
        label_26 = new SlGfwLabel(groupBox_7);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(150, 0, 121, 21));
        label_26->setAutoFillBackground(false);
        label_26->setHmiFontSize(-5);
        label_26->setInverseColors(true);
        label_27 = new SlGfwLabel(groupBox_7);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(70, 20, 41, 25));
        label_27->setHmiFontSize(-5);
        EndCuttingPowerLineEdit = new SlGfwLineEdit(groupBox_7);
        EndCuttingPowerLineEdit->setObjectName(QString::fromUtf8("EndCuttingPowerLineEdit"));
        EndCuttingPowerLineEdit->setGeometry(QRect(60, 42, 51, 24));
        EndCuttingPowerLineEdit->setHmiFonts(true);
        EndCuttingPowerLineEdit->setHmiFontSize(0);
        EndCuttingPowerLineEdit->setAlignment(Qt::AlignHCenter);
        label_28 = new SlGfwLabel(groupBox_7);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(120, 42, 31, 25));
        label_28->setHmiFontSize(-5);
        EndCuttingTimeLineEdit = new SlGfwLineEdit(groupBox_7);
        EndCuttingTimeLineEdit->setObjectName(QString::fromUtf8("EndCuttingTimeLineEdit"));
        EndCuttingTimeLineEdit->setGeometry(QRect(160, 42, 51, 24));
        EndCuttingTimeLineEdit->setHmiFonts(true);
        EndCuttingTimeLineEdit->setHmiFontSize(0);
        EndCuttingTimeLineEdit->setAlignment(Qt::AlignHCenter);
        label_29 = new SlGfwLabel(groupBox_7);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(169, 20, 41, 25));
        label_29->setHmiFontSize(-5);
        label_51 = new SlGfwLabel(groupBox_7);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(215, 42, 31, 25));
        label_51->setHmiFontSize(-5);
        QWidget::setTabOrder(LH_RailOffsetLineEdit, LV_RailOffsetLineEdit);
        QWidget::setTabOrder(LV_RailOffsetLineEdit, LH_CalibPosLineEdit1);
        QWidget::setTabOrder(LH_CalibPosLineEdit1, LH_CalibPosLineEdit2);
        QWidget::setTabOrder(LH_CalibPosLineEdit2, LV_CalibPosLineEdit1);
        QWidget::setTabOrder(LV_CalibPosLineEdit1, LV_CalibPosLineEdit2);
        QWidget::setTabOrder(LV_CalibPosLineEdit2, RH_RailOffsetLineEdit);
        QWidget::setTabOrder(RH_RailOffsetLineEdit, RV_RailOffsetLineEdit);
        QWidget::setTabOrder(RV_RailOffsetLineEdit, RH_CalibPosLineEdit1);
        QWidget::setTabOrder(RH_CalibPosLineEdit1, RH_CalibPosLineEdit2);
        QWidget::setTabOrder(RH_CalibPosLineEdit2, RV_CalibPosLineEdit1);
        QWidget::setTabOrder(RV_CalibPosLineEdit1, RV_CalibPosLineEdit2);
        QWidget::setTabOrder(RV_CalibPosLineEdit2, H_RapidMoveSpeedLineEdit);
        QWidget::setTabOrder(H_RapidMoveSpeedLineEdit, V_RapidMoveSpeedLineEdit);
        QWidget::setTabOrder(V_RapidMoveSpeedLineEdit, AxisAngularLowerSpeedLineEdit);
        QWidget::setTabOrder(AxisAngularLowerSpeedLineEdit, AxisAngularHighSpeedLineEdit);
        QWidget::setTabOrder(AxisAngularHighSpeedLineEdit, L_SMWDiameterLineEdit);
        QWidget::setTabOrder(L_SMWDiameterLineEdit, R_SMWDiameterLineEdit);
        QWidget::setTabOrder(R_SMWDiameterLineEdit, OffsetSlopeLengthLineEdit);
        QWidget::setTabOrder(OffsetSlopeLengthLineEdit, LiftCutterPowerLineEdit);
        QWidget::setTabOrder(LiftCutterPowerLineEdit, LiftCutterTimeLineEdit);
        QWidget::setTabOrder(LiftCutterTimeLineEdit, EndCuttingPowerLineEdit);
        QWidget::setTabOrder(EndCuttingPowerLineEdit, EndCuttingTimeLineEdit);

        retranslateUi(SystemFormUi);

        QMetaObject::connectSlotsByName(SystemFormUi);
    } // setupUi

    void retranslateUi(SlGfwDialogForm *SystemFormUi)
    {
        label->setStyleSheet(QApplication::translate("SystemFormUi", "background-color: rgb(255, 255, 0)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SystemFormUi", "\347\263\273\347\273\237\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label_2->setStyleSheet(QApplication::translate("SystemFormUi", "background-color: rgb(0, 0, 0);", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SystemFormUi", "\345\267\246\351\223\243\345\211\212\345\215\225\345\205\203", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SystemFormUi", "\350\275\250\350\267\235\344\277\256\346\255\243", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SystemFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SystemFormUi", "\345\210\200        \345\201\217", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SystemFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("SystemFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("SystemFormUi", "Y1\346\240\207\345\256\232(1)", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("SystemFormUi", "Z1\346\240\207\345\256\232(1)", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("SystemFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_52->setText(QApplication::translate("SystemFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_53->setText(QApplication::translate("SystemFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_54->setText(QApplication::translate("SystemFormUi", "Y1\346\240\207\345\256\232(2)", 0, QApplication::UnicodeUTF8));
        label_55->setText(QApplication::translate("SystemFormUi", "Z1\346\240\207\345\256\232(2)", 0, QApplication::UnicodeUTF8));
        label_62->setText(QApplication::translate("SystemFormUi", "\345\236\202\345\220\221\347\224\265\346\234\272", 0, QApplication::UnicodeUTF8));
        label_63->setText(QApplication::translate("SystemFormUi", "mm", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        label_3->setStyleSheet(QApplication::translate("SystemFormUi", "background-color: rgb(0, 0, 0);", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SystemFormUi", "\345\217\263\351\223\243\345\211\212\345\215\225\345\205\203", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("SystemFormUi", "\350\275\250\350\267\235\344\277\256\346\255\243", 0, QApplication::UnicodeUTF8));
        RH_RailOffsetLineEdit->setValue(QString());
        label_11->setText(QApplication::translate("SystemFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("SystemFormUi", "\345\210\200        \345\201\217", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("SystemFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("SystemFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("SystemFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("SystemFormUi", "Y2\346\240\207\345\256\232(1)", 0, QApplication::UnicodeUTF8));
        label_49->setText(QApplication::translate("SystemFormUi", "Z2\346\240\207\345\256\232(1)", 0, QApplication::UnicodeUTF8));
        label_56->setText(QApplication::translate("SystemFormUi", "Z2\346\240\207\345\256\232(2)", 0, QApplication::UnicodeUTF8));
        label_57->setText(QApplication::translate("SystemFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_58->setText(QApplication::translate("SystemFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_59->setText(QApplication::translate("SystemFormUi", "Y2\346\240\207\345\256\232(2)", 0, QApplication::UnicodeUTF8));
        label_64->setText(QApplication::translate("SystemFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_65->setText(QApplication::translate("SystemFormUi", "\345\236\202\345\220\221\347\224\265\346\234\272", 0, QApplication::UnicodeUTF8));
        groupBox_5->setStyleSheet(QString());
        label_37->setText(QApplication::translate("SystemFormUi", "\345\236\202\345\220\221\350\277\233\347\273\231\351\200\237\345\272\246", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("SystemFormUi", "mm/min", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("SystemFormUi", "\346\250\252\345\220\221\350\277\233\347\273\231\351\200\237\345\272\246", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("SystemFormUi", "mm/min", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("SystemFormUi", "\344\270\273\350\275\264\344\275\216\351\200\237\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        label_42->setText(QApplication::translate("SystemFormUi", "r/min", 0, QApplication::UnicodeUTF8));
        label_43->setText(QApplication::translate("SystemFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_44->setText(QApplication::translate("SystemFormUi", "\345\267\246\346\265\213\351\200\237\350\275\256\347\233\264\345\276\204", 0, QApplication::UnicodeUTF8));
        label_45->setText(QApplication::translate("SystemFormUi", "\345\201\217\347\247\273\351\241\272\345\235\241\351\225\277\345\272\246", 0, QApplication::UnicodeUTF8));
        label_46->setText(QApplication::translate("SystemFormUi", "\344\270\273\350\275\264\351\253\230\351\200\237\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        label_47->setText(QApplication::translate("SystemFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_48->setText(QApplication::translate("SystemFormUi", "r/min", 0, QApplication::UnicodeUTF8));
        label_60->setText(QApplication::translate("SystemFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_61->setText(QApplication::translate("SystemFormUi", "\345\217\263\346\265\213\351\200\237\350\275\256\347\233\264\345\276\204", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QString());
        label_22->setStyleSheet(QApplication::translate("SystemFormUi", "background-color: rgb(0, 0, 0);", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("SystemFormUi", "\345\263\260\345\200\274\345\212\237\347\216\207\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("SystemFormUi", "\345\212\237\347\216\207", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("SystemFormUi", "% \303\227", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("SystemFormUi", "\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_50->setText(QApplication::translate("SystemFormUi", "ms", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QString());
        label_26->setStyleSheet(QApplication::translate("SystemFormUi", "background-color: rgb(0, 0, 0);", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("SystemFormUi", "\346\234\200\345\244\247\345\212\237\347\216\207\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("SystemFormUi", "\345\212\237\347\216\207", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("SystemFormUi", "% \303\227", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("SystemFormUi", "\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_51->setText(QApplication::translate("SystemFormUi", "ms", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(SystemFormUi);
    } // retranslateUi

};

namespace Ui {
    class SystemFormUi: public Ui_SystemFormUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMFORM_H
