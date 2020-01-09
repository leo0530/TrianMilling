/********************************************************************************
** Form generated from reading ui file 'scanform.ui'
**
** Created: Mon Dec 16 11:05:06 2019
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SCANFORM_H
#define UI_SCANFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <plotwidget.h>
#include "slgfwdialogform.h"
#include "slgfwlabel.h"
#include "slgfwlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_ScanFormUi
{
public:
    PlotWidget *LeftPlotWidget;
    PlotWidget *RightPlotWidget;
    SlGfwLabel *label;
    SlGfwLabel *label_2;
    SlGfwLabel *label_43;
    SlGfwLineEdit *R_MotorRealPosLineEdit;
    SlGfwLabel *label_44;
    SlGfwLineEdit *RightCalibPosLineEdit;
    SlGfwLabel *label_45;
    SlGfwLineEdit *RightCurPosLineEdit;
    SlGfwLineEdit *LeftCalibPosLineEdit;
    SlGfwLineEdit *LeftCurPosLineEdit;
    SlGfwLabel *label_46;
    SlGfwLabel *label_47;
    SlGfwLineEdit *L_MotorRealPosLineEdit;
    SlGfwLabel *label_48;

    void setupUi(SlGfwDialogForm *ScanFormUi)
    {
        if (ScanFormUi->objectName().isEmpty())
            ScanFormUi->setObjectName(QString::fromUtf8("ScanFormUi"));
        ScanFormUi->resize(559, 372);
        ScanFormUi->setFocusPolicy(Qt::NoFocus);
        LeftPlotWidget = new PlotWidget(ScanFormUi);
        LeftPlotWidget->setObjectName(QString::fromUtf8("LeftPlotWidget"));
        LeftPlotWidget->setGeometry(QRect(0, 48, 559, 126));
        RightPlotWidget = new PlotWidget(ScanFormUi);
        RightPlotWidget->setObjectName(QString::fromUtf8("RightPlotWidget"));
        RightPlotWidget->setGeometry(QRect(0, 223, 559, 126));
        label = new SlGfwLabel(ScanFormUi);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 23, 171, 24));
        QFont font;
        font.setFamily(QString::fromUtf8("Siemens AD CH Simplified"));
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new SlGfwLabel(ScanFormUi);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(210, 198, 171, 24));
        label_2->setFont(font);
        label_2->setAutoFillBackground(false);
        label_2->setAlignment(Qt::AlignCenter);
        label_43 = new SlGfwLabel(ScanFormUi);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(40, 353, 105, 18));
        R_MotorRealPosLineEdit = new SlGfwLineEdit(ScanFormUi);
        R_MotorRealPosLineEdit->setObjectName(QString::fromUtf8("R_MotorRealPosLineEdit"));
        R_MotorRealPosLineEdit->setGeometry(QRect(149, 353, 51, 15));
        R_MotorRealPosLineEdit->setReadOnly(true);
        label_44 = new SlGfwLabel(ScanFormUi);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(229, 353, 91, 15));
        RightCalibPosLineEdit = new SlGfwLineEdit(ScanFormUi);
        RightCalibPosLineEdit->setObjectName(QString::fromUtf8("RightCalibPosLineEdit"));
        RightCalibPosLineEdit->setGeometry(QRect(319, 353, 51, 15));
        RightCalibPosLineEdit->setReadOnly(true);
        label_45 = new SlGfwLabel(ScanFormUi);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(421, 353, 81, 15));
        RightCurPosLineEdit = new SlGfwLineEdit(ScanFormUi);
        RightCurPosLineEdit->setObjectName(QString::fromUtf8("RightCurPosLineEdit"));
        RightCurPosLineEdit->setGeometry(QRect(505, 353, 51, 15));
        RightCurPosLineEdit->setReadOnly(true);
        LeftCalibPosLineEdit = new SlGfwLineEdit(ScanFormUi);
        LeftCalibPosLineEdit->setObjectName(QString::fromUtf8("LeftCalibPosLineEdit"));
        LeftCalibPosLineEdit->setGeometry(QRect(319, 178, 51, 15));
        LeftCalibPosLineEdit->setReadOnly(true);
        LeftCurPosLineEdit = new SlGfwLineEdit(ScanFormUi);
        LeftCurPosLineEdit->setObjectName(QString::fromUtf8("LeftCurPosLineEdit"));
        LeftCurPosLineEdit->setGeometry(QRect(508, 178, 51, 15));
        LeftCurPosLineEdit->setReadOnly(true);
        label_46 = new SlGfwLabel(ScanFormUi);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(229, 179, 91, 15));
        label_47 = new SlGfwLabel(ScanFormUi);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(419, 180, 91, 15));
        L_MotorRealPosLineEdit = new SlGfwLineEdit(ScanFormUi);
        L_MotorRealPosLineEdit->setObjectName(QString::fromUtf8("L_MotorRealPosLineEdit"));
        L_MotorRealPosLineEdit->setGeometry(QRect(149, 178, 51, 15));
        L_MotorRealPosLineEdit->setReadOnly(true);
        label_48 = new SlGfwLabel(ScanFormUi);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(40, 179, 105, 18));
        QWidget::setTabOrder(LeftCurPosLineEdit, LeftCalibPosLineEdit);
        QWidget::setTabOrder(LeftCalibPosLineEdit, L_MotorRealPosLineEdit);
        QWidget::setTabOrder(L_MotorRealPosLineEdit, RightCurPosLineEdit);
        QWidget::setTabOrder(RightCurPosLineEdit, RightCalibPosLineEdit);
        QWidget::setTabOrder(RightCalibPosLineEdit, R_MotorRealPosLineEdit);

        retranslateUi(ScanFormUi);

        QMetaObject::connectSlotsByName(ScanFormUi);
    } // setupUi

    void retranslateUi(SlGfwDialogForm *ScanFormUi)
    {
        label->setStyleSheet(QApplication::translate("ScanFormUi", "background-color: rgb(255, 255, 0)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ScanFormUi", "\345\267\246\351\223\243\345\211\212\345\215\225\345\205\203", 0, QApplication::UnicodeUTF8));
        label_2->setStyleSheet(QApplication::translate("ScanFormUi", "background-color: rgb(255, 255, 0)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ScanFormUi", "\345\217\263\351\223\243\345\211\212\345\215\225\345\205\203", 0, QApplication::UnicodeUTF8));
        label_43->setText(QApplication::translate("ScanFormUi", "Y\347\224\265\346\234\272\345\256\236\351\231\205\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
        label_44->setText(QApplication::translate("ScanFormUi", "Y\346\240\207\345\256\232\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
        label_45->setText(QApplication::translate("ScanFormUi", "Y\345\275\223\345\211\215\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
        label_46->setText(QApplication::translate("ScanFormUi", "Y\346\240\207\345\256\232\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
        label_47->setText(QApplication::translate("ScanFormUi", "Y\345\275\223\345\211\215\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
        label_48->setText(QApplication::translate("ScanFormUi", "Y\347\224\265\346\234\272\345\256\236\351\231\205\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(ScanFormUi);
    } // retranslateUi

};

namespace Ui {
    class ScanFormUi: public Ui_ScanFormUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANFORM_H
