/********************************************************************************
** Form generated from reading ui file 'railcalibform.ui'
**
** Created: Wed Jan 8 15:11:25 2020
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_RAILCALIBFORM_H
#define UI_RAILCALIBFORM_H

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

class Ui_RailCalibFormUi
{
public:
    SlGfwLabel *label;
    SlGfwGroupBox *groupBox;
    SlGfwLabel *label_2;
    SlGfwLabel *label_6;
    SlGfwLineEdit *LH_MotorCalibPosLineEdit;
    SlGfwLabel *label_7;
    SlGfwLineEdit *LV_MotorCalibPosLineEdit;
    SlGfwLabel *label_8;
    SlGfwLabel *label_9;
    SlGfwLabel *label_30;
    SlGfwLabel *label_31;
    SlGfwLabel *label_32;
    SlGfwLabel *label_33;
    SlGfwLineEdit *LV_SensorCalibPosLineEdit1;
    SlGfwLineEdit *LH_SensorCalibPosLineEdit1;
    SlGfwLabel *label_37;
    SlGfwLineEdit *LV_SensorCalibPosLineEdit2;
    SlGfwLabel *label_38;
    SlGfwLineEdit *LH_SensorCalibPosLineEdit2;
    SlGfwLabel *label_39;
    SlGfwLabel *label_40;
    SlGfwLabel *label_14;
    SlGfwLineEdit *L_ScannerToCutterOffsetLineEdit;
    SlGfwLabel *label_15;
    SlGfwLineEdit *LH_CuttingDepthOffsetLineEdit;
    SlGfwLabel *label_18;
    SlGfwLabel *label_19;
    SlGfwLabel *label_22;
    SlGfwLineEdit *LV_CuttingDepthOffsetLineEdit;
    SlGfwLabel *label_23;
    SlGfwGroupBox *groupBox_2;
    SlGfwLabel *label_3;
    SlGfwLabel *label_10;
    SlGfwLineEdit *RH_MotorCalibPosLineEdit;
    SlGfwLabel *label_11;
    SlGfwLineEdit *RV_MotorCalibPosLineEdit;
    SlGfwLabel *label_12;
    SlGfwLabel *label_13;
    SlGfwLabel *label_34;
    SlGfwLabel *label_35;
    SlGfwLabel *label_36;
    SlGfwLineEdit *RV_SensorCalibPosLineEdit1;
    SlGfwLabel *label_49;
    SlGfwLineEdit *RH_SensorCalibPosLineEdit1;
    SlGfwLabel *label_50;
    SlGfwLineEdit *RH_SensorCalibPosLineEdit2;
    SlGfwLabel *label_41;
    SlGfwLineEdit *RV_SensorCalibPosLineEdit2;
    SlGfwLabel *label_42;
    SlGfwLabel *label_43;
    SlGfwLineEdit *R_ScannerToCutterOffsetLineEdit;
    SlGfwLabel *label_16;
    SlGfwLabel *label_17;
    SlGfwLineEdit *RH_CuttingDepthOffsetLineEdit;
    SlGfwLabel *label_20;
    SlGfwLabel *label_21;
    SlGfwLineEdit *RV_CuttingDepthOffsetLineEdit;
    SlGfwLabel *label_24;
    SlGfwLabel *label_25;

    void setupUi(SlGfwDialogForm *RailCalibFormUi)
    {
        if (RailCalibFormUi->objectName().isEmpty())
            RailCalibFormUi->setObjectName(QString::fromUtf8("RailCalibFormUi"));
        RailCalibFormUi->resize(599, 378);
        RailCalibFormUi->setFocusPolicy(Qt::NoFocus);
        label = new SlGfwLabel(RailCalibFormUi);
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
        groupBox = new SlGfwGroupBox(RailCalibFormUi);
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
        label_2->setGeometry(QRect(20, 0, 100, 21));
        label_2->setFont(font);
        label_2->setAutoFillBackground(false);
        label_2->setHmiFonts(true);
        label_2->setHmiColors(true);
        label_2->setHmiFontSize(-5);
        label_2->setInverseColors(true);
        label_6 = new SlGfwLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(68, 125, 81, 31));
        label_6->setHmiFontSize(-5);
        LH_MotorCalibPosLineEdit = new SlGfwLineEdit(groupBox);
        LH_MotorCalibPosLineEdit->setObjectName(QString::fromUtf8("LH_MotorCalibPosLineEdit"));
        LH_MotorCalibPosLineEdit->setGeometry(QRect(187, 125, 51, 27));
        LH_MotorCalibPosLineEdit->setHmiFonts(true);
        LH_MotorCalibPosLineEdit->setHmiFontSize(0);
        LH_MotorCalibPosLineEdit->setAlignment(Qt::AlignHCenter);
        LH_MotorCalibPosLineEdit->setReadOnly(true);
        label_7 = new SlGfwLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(245, 125, 31, 31));
        label_7->setHmiFontSize(-5);
        LV_MotorCalibPosLineEdit = new SlGfwLineEdit(groupBox);
        LV_MotorCalibPosLineEdit->setObjectName(QString::fromUtf8("LV_MotorCalibPosLineEdit"));
        LV_MotorCalibPosLineEdit->setGeometry(QRect(187, 157, 51, 27));
        LV_MotorCalibPosLineEdit->setHmiFonts(true);
        LV_MotorCalibPosLineEdit->setHmiFontSize(0);
        LV_MotorCalibPosLineEdit->setAlignment(Qt::AlignHCenter);
        LV_MotorCalibPosLineEdit->setReadOnly(true);
        label_8 = new SlGfwLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(68, 155, 81, 31));
        label_8->setHmiFontSize(-5);
        label_9 = new SlGfwLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(245, 155, 31, 31));
        label_9->setHmiFontSize(-5);
        label_30 = new SlGfwLabel(groupBox);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(245, 188, 31, 31));
        label_30->setHmiFontSize(-5);
        label_31 = new SlGfwLabel(groupBox);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(68, 188, 81, 31));
        label_31->setHmiFontSize(-5);
        label_32 = new SlGfwLabel(groupBox);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(68, 246, 81, 31));
        label_32->setHmiFontSize(-5);
        label_33 = new SlGfwLabel(groupBox);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(245, 246, 31, 31));
        label_33->setHmiFontSize(-5);
        LV_SensorCalibPosLineEdit1 = new SlGfwLineEdit(groupBox);
        LV_SensorCalibPosLineEdit1->setObjectName(QString::fromUtf8("LV_SensorCalibPosLineEdit1"));
        LV_SensorCalibPosLineEdit1->setGeometry(QRect(187, 249, 51, 27));
        LV_SensorCalibPosLineEdit1->setHmiFonts(true);
        LV_SensorCalibPosLineEdit1->setHmiFontSize(0);
        LV_SensorCalibPosLineEdit1->setAlignment(Qt::AlignHCenter);
        LV_SensorCalibPosLineEdit1->setReadOnly(true);
        LH_SensorCalibPosLineEdit1 = new SlGfwLineEdit(groupBox);
        LH_SensorCalibPosLineEdit1->setObjectName(QString::fromUtf8("LH_SensorCalibPosLineEdit1"));
        LH_SensorCalibPosLineEdit1->setGeometry(QRect(187, 188, 51, 27));
        LH_SensorCalibPosLineEdit1->setHmiFonts(true);
        LH_SensorCalibPosLineEdit1->setHmiFontSize(0);
        LH_SensorCalibPosLineEdit1->setAlignment(Qt::AlignHCenter);
        LH_SensorCalibPosLineEdit1->setReadOnly(true);
        label_37 = new SlGfwLabel(groupBox);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(245, 218, 31, 31));
        label_37->setHmiFontSize(-5);
        LV_SensorCalibPosLineEdit2 = new SlGfwLineEdit(groupBox);
        LV_SensorCalibPosLineEdit2->setObjectName(QString::fromUtf8("LV_SensorCalibPosLineEdit2"));
        LV_SensorCalibPosLineEdit2->setGeometry(QRect(187, 280, 51, 27));
        LV_SensorCalibPosLineEdit2->setHmiFonts(true);
        LV_SensorCalibPosLineEdit2->setHmiFontSize(0);
        LV_SensorCalibPosLineEdit2->setAlignment(Qt::AlignHCenter);
        LV_SensorCalibPosLineEdit2->setReadOnly(true);
        label_38 = new SlGfwLabel(groupBox);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(245, 277, 31, 31));
        label_38->setHmiFontSize(-5);
        LH_SensorCalibPosLineEdit2 = new SlGfwLineEdit(groupBox);
        LH_SensorCalibPosLineEdit2->setObjectName(QString::fromUtf8("LH_SensorCalibPosLineEdit2"));
        LH_SensorCalibPosLineEdit2->setGeometry(QRect(187, 218, 51, 27));
        LH_SensorCalibPosLineEdit2->setHmiFonts(true);
        LH_SensorCalibPosLineEdit2->setHmiFontSize(0);
        LH_SensorCalibPosLineEdit2->setAlignment(Qt::AlignHCenter);
        LH_SensorCalibPosLineEdit2->setReadOnly(true);
        label_39 = new SlGfwLabel(groupBox);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(68, 277, 81, 31));
        label_39->setHmiFontSize(-5);
        label_40 = new SlGfwLabel(groupBox);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(68, 218, 81, 31));
        label_40->setHmiFontSize(-5);
        label_14 = new SlGfwLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(245, 93, 31, 31));
        label_14->setHmiFontSize(-5);
        L_ScannerToCutterOffsetLineEdit = new SlGfwLineEdit(groupBox);
        L_ScannerToCutterOffsetLineEdit->setObjectName(QString::fromUtf8("L_ScannerToCutterOffsetLineEdit"));
        L_ScannerToCutterOffsetLineEdit->setEnabled(true);
        L_ScannerToCutterOffsetLineEdit->setGeometry(QRect(187, 94, 51, 27));
        L_ScannerToCutterOffsetLineEdit->setAcceptDrops(true);
        L_ScannerToCutterOffsetLineEdit->setHmiFonts(true);
        L_ScannerToCutterOffsetLineEdit->setHmiFontSize(0);
        L_ScannerToCutterOffsetLineEdit->setAlignment(Qt::AlignHCenter);
        L_ScannerToCutterOffsetLineEdit->setReadOnly(false);
        label_15 = new SlGfwLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 96, 171, 21));
        label_15->setHmiFontSize(-5);
        LH_CuttingDepthOffsetLineEdit = new SlGfwLineEdit(groupBox);
        LH_CuttingDepthOffsetLineEdit->setObjectName(QString::fromUtf8("LH_CuttingDepthOffsetLineEdit"));
        LH_CuttingDepthOffsetLineEdit->setEnabled(true);
        LH_CuttingDepthOffsetLineEdit->setGeometry(QRect(187, 32, 51, 27));
        LH_CuttingDepthOffsetLineEdit->setAcceptDrops(true);
        LH_CuttingDepthOffsetLineEdit->setHmiFonts(true);
        LH_CuttingDepthOffsetLineEdit->setHmiFontSize(0);
        LH_CuttingDepthOffsetLineEdit->setAlignment(Qt::AlignHCenter);
        LH_CuttingDepthOffsetLineEdit->setReadOnly(false);
        label_18 = new SlGfwLabel(groupBox);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(20, 34, 171, 21));
        label_18->setHmiFontSize(-5);
        label_18->setAlignment(Qt::AlignCenter);
        label_19 = new SlGfwLabel(groupBox);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(245, 31, 31, 31));
        label_19->setHmiFontSize(-5);
        label_22 = new SlGfwLabel(groupBox);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(20, 65, 171, 21));
        label_22->setHmiFontSize(-5);
        label_22->setAlignment(Qt::AlignCenter);
        LV_CuttingDepthOffsetLineEdit = new SlGfwLineEdit(groupBox);
        LV_CuttingDepthOffsetLineEdit->setObjectName(QString::fromUtf8("LV_CuttingDepthOffsetLineEdit"));
        LV_CuttingDepthOffsetLineEdit->setEnabled(true);
        LV_CuttingDepthOffsetLineEdit->setGeometry(QRect(187, 63, 51, 27));
        LV_CuttingDepthOffsetLineEdit->setAcceptDrops(true);
        LV_CuttingDepthOffsetLineEdit->setHmiFonts(true);
        LV_CuttingDepthOffsetLineEdit->setHmiFontSize(0);
        LV_CuttingDepthOffsetLineEdit->setAlignment(Qt::AlignHCenter);
        LV_CuttingDepthOffsetLineEdit->setReadOnly(false);
        label_23 = new SlGfwLabel(groupBox);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(245, 62, 31, 31));
        label_23->setHmiFontSize(-5);
        groupBox_2 = new SlGfwGroupBox(RailCalibFormUi);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(291, 65, 301, 313));
        groupBox_2->setAutoFillBackground(false);
        groupBox_2->setHmiFontSize(-5);
        groupBox_2->setCheckable(false);
        label_3 = new SlGfwLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(172, 0, 100, 21));
        label_3->setAutoFillBackground(false);
        label_3->setHmiFontSize(-5);
        label_3->setInverseColors(true);
        label_10 = new SlGfwLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(70, 125, 81, 31));
        label_10->setHmiFontSize(-5);
        RH_MotorCalibPosLineEdit = new SlGfwLineEdit(groupBox_2);
        RH_MotorCalibPosLineEdit->setObjectName(QString::fromUtf8("RH_MotorCalibPosLineEdit"));
        RH_MotorCalibPosLineEdit->setGeometry(QRect(181, 125, 51, 27));
        RH_MotorCalibPosLineEdit->setFont(font);
        RH_MotorCalibPosLineEdit->setHmiFonts(true);
        RH_MotorCalibPosLineEdit->setHmiFontSize(0);
        RH_MotorCalibPosLineEdit->setAlignment(Qt::AlignHCenter);
        RH_MotorCalibPosLineEdit->setReadOnly(true);
        label_11 = new SlGfwLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(239, 125, 31, 31));
        label_11->setHmiFontSize(-5);
        RV_MotorCalibPosLineEdit = new SlGfwLineEdit(groupBox_2);
        RV_MotorCalibPosLineEdit->setObjectName(QString::fromUtf8("RV_MotorCalibPosLineEdit"));
        RV_MotorCalibPosLineEdit->setGeometry(QRect(181, 157, 51, 27));
        RV_MotorCalibPosLineEdit->setHmiFonts(true);
        RV_MotorCalibPosLineEdit->setHmiFontSize(0);
        RV_MotorCalibPosLineEdit->setAlignment(Qt::AlignHCenter);
        RV_MotorCalibPosLineEdit->setReadOnly(true);
        label_12 = new SlGfwLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(70, 155, 81, 31));
        label_12->setHmiFontSize(-5);
        label_13 = new SlGfwLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(239, 155, 31, 31));
        label_13->setHmiFontSize(-5);
        label_34 = new SlGfwLabel(groupBox_2);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(240, 244, 31, 31));
        label_34->setHmiFontSize(-5);
        label_35 = new SlGfwLabel(groupBox_2);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(239, 187, 31, 31));
        label_35->setHmiFontSize(-5);
        label_36 = new SlGfwLabel(groupBox_2);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(70, 187, 81, 31));
        label_36->setHmiFontSize(-5);
        RV_SensorCalibPosLineEdit1 = new SlGfwLineEdit(groupBox_2);
        RV_SensorCalibPosLineEdit1->setObjectName(QString::fromUtf8("RV_SensorCalibPosLineEdit1"));
        RV_SensorCalibPosLineEdit1->setGeometry(QRect(181, 247, 51, 27));
        RV_SensorCalibPosLineEdit1->setHmiFonts(true);
        RV_SensorCalibPosLineEdit1->setHmiFontSize(0);
        RV_SensorCalibPosLineEdit1->setAlignment(Qt::AlignHCenter);
        RV_SensorCalibPosLineEdit1->setReadOnly(true);
        label_49 = new SlGfwLabel(groupBox_2);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(71, 244, 81, 31));
        label_49->setHmiFontSize(-5);
        RH_SensorCalibPosLineEdit1 = new SlGfwLineEdit(groupBox_2);
        RH_SensorCalibPosLineEdit1->setObjectName(QString::fromUtf8("RH_SensorCalibPosLineEdit1"));
        RH_SensorCalibPosLineEdit1->setGeometry(QRect(181, 187, 51, 27));
        RH_SensorCalibPosLineEdit1->setHmiFonts(true);
        RH_SensorCalibPosLineEdit1->setHmiFontSize(0);
        RH_SensorCalibPosLineEdit1->setAlignment(Qt::AlignHCenter);
        RH_SensorCalibPosLineEdit1->setReadOnly(true);
        label_50 = new SlGfwLabel(groupBox_2);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(71, 275, 81, 31));
        label_50->setHmiFontSize(-5);
        RH_SensorCalibPosLineEdit2 = new SlGfwLineEdit(groupBox_2);
        RH_SensorCalibPosLineEdit2->setObjectName(QString::fromUtf8("RH_SensorCalibPosLineEdit2"));
        RH_SensorCalibPosLineEdit2->setGeometry(QRect(181, 216, 51, 27));
        RH_SensorCalibPosLineEdit2->setHmiFonts(true);
        RH_SensorCalibPosLineEdit2->setHmiFontSize(0);
        RH_SensorCalibPosLineEdit2->setAlignment(Qt::AlignHCenter);
        RH_SensorCalibPosLineEdit2->setReadOnly(true);
        label_41 = new SlGfwLabel(groupBox_2);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(70, 216, 81, 31));
        label_41->setHmiFontSize(-5);
        RV_SensorCalibPosLineEdit2 = new SlGfwLineEdit(groupBox_2);
        RV_SensorCalibPosLineEdit2->setObjectName(QString::fromUtf8("RV_SensorCalibPosLineEdit2"));
        RV_SensorCalibPosLineEdit2->setGeometry(QRect(181, 278, 51, 27));
        RV_SensorCalibPosLineEdit2->setHmiFonts(true);
        RV_SensorCalibPosLineEdit2->setHmiFontSize(0);
        RV_SensorCalibPosLineEdit2->setAlignment(Qt::AlignHCenter);
        RV_SensorCalibPosLineEdit2->setReadOnly(true);
        label_42 = new SlGfwLabel(groupBox_2);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(239, 216, 31, 31));
        label_42->setHmiFontSize(-5);
        label_43 = new SlGfwLabel(groupBox_2);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(240, 275, 31, 31));
        label_43->setHmiFontSize(-5);
        R_ScannerToCutterOffsetLineEdit = new SlGfwLineEdit(groupBox_2);
        R_ScannerToCutterOffsetLineEdit->setObjectName(QString::fromUtf8("R_ScannerToCutterOffsetLineEdit"));
        R_ScannerToCutterOffsetLineEdit->setGeometry(QRect(181, 92, 51, 27));
        R_ScannerToCutterOffsetLineEdit->setFont(font);
        R_ScannerToCutterOffsetLineEdit->setHmiFonts(true);
        R_ScannerToCutterOffsetLineEdit->setHmiFontSize(0);
        R_ScannerToCutterOffsetLineEdit->setAlignment(Qt::AlignHCenter);
        R_ScannerToCutterOffsetLineEdit->setReadOnly(false);
        label_16 = new SlGfwLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 92, 161, 31));
        label_16->setHmiFontSize(-5);
        label_17 = new SlGfwLabel(groupBox_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(239, 91, 31, 31));
        label_17->setHmiFontSize(-5);
        RH_CuttingDepthOffsetLineEdit = new SlGfwLineEdit(groupBox_2);
        RH_CuttingDepthOffsetLineEdit->setObjectName(QString::fromUtf8("RH_CuttingDepthOffsetLineEdit"));
        RH_CuttingDepthOffsetLineEdit->setGeometry(QRect(181, 32, 51, 27));
        RH_CuttingDepthOffsetLineEdit->setFont(font);
        RH_CuttingDepthOffsetLineEdit->setHmiFonts(true);
        RH_CuttingDepthOffsetLineEdit->setHmiFontSize(0);
        RH_CuttingDepthOffsetLineEdit->setAlignment(Qt::AlignHCenter);
        RH_CuttingDepthOffsetLineEdit->setReadOnly(false);
        label_20 = new SlGfwLabel(groupBox_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 32, 161, 31));
        label_20->setHmiFontSize(-5);
        label_20->setAlignment(Qt::AlignCenter);
        label_21 = new SlGfwLabel(groupBox_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(239, 31, 31, 31));
        label_21->setHmiFontSize(-5);
        RV_CuttingDepthOffsetLineEdit = new SlGfwLineEdit(groupBox_2);
        RV_CuttingDepthOffsetLineEdit->setObjectName(QString::fromUtf8("RV_CuttingDepthOffsetLineEdit"));
        RV_CuttingDepthOffsetLineEdit->setGeometry(QRect(181, 62, 51, 27));
        RV_CuttingDepthOffsetLineEdit->setFont(font);
        RV_CuttingDepthOffsetLineEdit->setHmiFonts(true);
        RV_CuttingDepthOffsetLineEdit->setHmiFontSize(0);
        RV_CuttingDepthOffsetLineEdit->setAlignment(Qt::AlignHCenter);
        RV_CuttingDepthOffsetLineEdit->setReadOnly(false);
        label_24 = new SlGfwLabel(groupBox_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(239, 61, 31, 31));
        label_24->setHmiFontSize(-5);
        label_25 = new SlGfwLabel(groupBox_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 62, 161, 31));
        label_25->setHmiFontSize(-5);
        label_25->setAlignment(Qt::AlignCenter);
        QWidget::setTabOrder(LH_MotorCalibPosLineEdit, LV_MotorCalibPosLineEdit);
        QWidget::setTabOrder(LV_MotorCalibPosLineEdit, LH_SensorCalibPosLineEdit1);
        QWidget::setTabOrder(LH_SensorCalibPosLineEdit1, LH_SensorCalibPosLineEdit2);
        QWidget::setTabOrder(LH_SensorCalibPosLineEdit2, LV_SensorCalibPosLineEdit1);
        QWidget::setTabOrder(LV_SensorCalibPosLineEdit1, LV_SensorCalibPosLineEdit2);
        QWidget::setTabOrder(LV_SensorCalibPosLineEdit2, RH_MotorCalibPosLineEdit);
        QWidget::setTabOrder(RH_MotorCalibPosLineEdit, RV_MotorCalibPosLineEdit);
        QWidget::setTabOrder(RV_MotorCalibPosLineEdit, RH_SensorCalibPosLineEdit1);
        QWidget::setTabOrder(RH_SensorCalibPosLineEdit1, RH_SensorCalibPosLineEdit2);
        QWidget::setTabOrder(RH_SensorCalibPosLineEdit2, RV_SensorCalibPosLineEdit1);
        QWidget::setTabOrder(RV_SensorCalibPosLineEdit1, RV_SensorCalibPosLineEdit2);

        retranslateUi(RailCalibFormUi);

        QMetaObject::connectSlotsByName(RailCalibFormUi);
    } // setupUi

    void retranslateUi(SlGfwDialogForm *RailCalibFormUi)
    {
        label->setStyleSheet(QApplication::translate("RailCalibFormUi", "background-color: rgb(255, 255, 0)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RailCalibFormUi", "\345\210\200\347\233\230\345\257\271\345\210\200", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label_2->setStyleSheet(QApplication::translate("RailCalibFormUi", "background-color: rgb(0, 0, 0);", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RailCalibFormUi", "\345\267\246\351\223\243\345\211\212\345\215\225\345\205\203", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("RailCalibFormUi", "\346\250\252\345\220\221\347\224\265\346\234\272", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("RailCalibFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("RailCalibFormUi", "\345\236\202\345\220\221\347\224\265\346\234\272", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("RailCalibFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("RailCalibFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("RailCalibFormUi", "Y1\350\257\273\346\225\260(1)", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("RailCalibFormUi", "Z1\350\257\273\346\225\260(1)", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("RailCalibFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("RailCalibFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("RailCalibFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("RailCalibFormUi", "Z1\350\257\273\346\225\260(2)", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("RailCalibFormUi", "Y1\350\257\273\346\225\260(2)", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("RailCalibFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("RailCalibFormUi", "\350\275\250\345\273\223\344\273\252\344\270\216\345\210\200\347\233\230\346\250\252\345\220\221\345\201\217\347\247\273", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("RailCalibFormUi", "\346\250\252\345\220\221\345\210\207\346\267\261\345\201\217\347\247\273", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("RailCalibFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("RailCalibFormUi", "\345\236\202\345\220\221\345\210\207\346\267\261\345\201\217\347\247\273", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("RailCalibFormUi", "mm", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        label_3->setStyleSheet(QApplication::translate("RailCalibFormUi", "background-color: rgb(0, 0, 0);", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("RailCalibFormUi", "\345\217\263\351\223\243\345\211\212\345\215\225\345\205\203", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("RailCalibFormUi", "\346\250\252\345\220\221\347\224\265\346\234\272", 0, QApplication::UnicodeUTF8));
        RH_MotorCalibPosLineEdit->setValue(QString());
        label_11->setText(QApplication::translate("RailCalibFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("RailCalibFormUi", "\345\236\202\345\220\221\347\224\265\346\234\272", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("RailCalibFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("RailCalibFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("RailCalibFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("RailCalibFormUi", "Y2\350\257\273\346\225\260(1)", 0, QApplication::UnicodeUTF8));
        label_49->setText(QApplication::translate("RailCalibFormUi", "Z2\350\257\273\346\225\260(1)", 0, QApplication::UnicodeUTF8));
        label_50->setText(QApplication::translate("RailCalibFormUi", "Z2\350\257\273\346\225\260(2)", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("RailCalibFormUi", "Y2\350\257\273\346\225\260(2)", 0, QApplication::UnicodeUTF8));
        label_42->setText(QApplication::translate("RailCalibFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_43->setText(QApplication::translate("RailCalibFormUi", "mm", 0, QApplication::UnicodeUTF8));
        R_ScannerToCutterOffsetLineEdit->setValue(QString());
        label_16->setText(QApplication::translate("RailCalibFormUi", "\350\275\250\345\273\223\344\273\252\344\270\216\345\210\200\347\233\230\346\250\252\345\220\221\345\201\217\347\247\273", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("RailCalibFormUi", "mm", 0, QApplication::UnicodeUTF8));
        RH_CuttingDepthOffsetLineEdit->setValue(QString());
        label_20->setText(QApplication::translate("RailCalibFormUi", "\346\250\252\345\220\221\345\210\207\346\267\261\345\201\217\347\247\273", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("RailCalibFormUi", "mm", 0, QApplication::UnicodeUTF8));
        RV_CuttingDepthOffsetLineEdit->setValue(QString());
        label_24->setText(QApplication::translate("RailCalibFormUi", "mm", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("RailCalibFormUi", "\345\236\202\345\220\221\345\210\207\346\267\261\345\201\217\347\247\273", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(RailCalibFormUi);
    } // retranslateUi

};

namespace Ui {
    class RailCalibFormUi: public Ui_RailCalibFormUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAILCALIBFORM_H
