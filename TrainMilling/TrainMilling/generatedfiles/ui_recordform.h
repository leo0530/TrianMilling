/********************************************************************************
** Form generated from reading ui file 'recordform.ui'
**
** Created: Mon Dec 16 11:05:06 2019
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_RECORDFORM_H
#define UI_RECORDFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <plotwidget2.h>
#include "slgfwdialogform.h"
#include "slgfwlabel.h"
#include "slgfwlineedit.h"
#include "slgfwtouchbutton.h"

QT_BEGIN_NAMESPACE

class Ui_RecordFormUi
{
public:
    SlGfwLabel *label;
    SlGfwLineEdit *WorkMileageLineEdit;
    SlGfwLabel *label_29;
    SlGfwLabel *label_30;
    SlGfwTouchButton *RestoreTouchButton;
    SlGfwTouchButton *ZoomInTouchButton;
    SlGfwTouchButton *ZoomOutTouchButton;
    PlotWidget2 *drawWidget;
    SlGfwLabel *CreateTimeLabel;
    SlGfwLabel *CurvePosLabel;
    SlGfwLabel *CurvePosText;
    SlGfwLabel *CreateTimeText;
    SlGfwLabel *label_31;
    SlGfwLineEdit *TrainMileageLineEdit;
    SlGfwLabel *label_32;

    void setupUi(SlGfwDialogForm *RecordFormUi)
    {
        if (RecordFormUi->objectName().isEmpty())
            RecordFormUi->setObjectName(QString::fromUtf8("RecordFormUi"));
        RecordFormUi->resize(599, 373);
        RecordFormUi->setFocusPolicy(Qt::NoFocus);
        label = new SlGfwLabel(RecordFormUi);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 30, 171, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Siemens AD CH Simplified"));
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setAlignment(Qt::AlignCenter);
        WorkMileageLineEdit = new SlGfwLineEdit(RecordFormUi);
        WorkMileageLineEdit->setObjectName(QString::fromUtf8("WorkMileageLineEdit"));
        WorkMileageLineEdit->setGeometry(QRect(482, 70, 51, 27));
        WorkMileageLineEdit->setAlignment(Qt::AlignLeading);
        WorkMileageLineEdit->setReadOnly(true);
        label_29 = new SlGfwLabel(RecordFormUi);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(390, 70, 81, 31));
        label_30 = new SlGfwLabel(RecordFormUi);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(540, 70, 31, 31));
        RestoreTouchButton = new SlGfwTouchButton(RecordFormUi);
        RestoreTouchButton->setObjectName(QString::fromUtf8("RestoreTouchButton"));
        RestoreTouchButton->setGeometry(QRect(130, 336, 80, 40));
        RestoreTouchButton->setPressed(false);
        RestoreTouchButton->setAnimationPressed(false);
        ZoomInTouchButton = new SlGfwTouchButton(RecordFormUi);
        ZoomInTouchButton->setObjectName(QString::fromUtf8("ZoomInTouchButton"));
        ZoomInTouchButton->setGeometry(QRect(251, 336, 80, 40));
        ZoomInTouchButton->setPressed(false);
        ZoomInTouchButton->setAnimationPressed(false);
        ZoomOutTouchButton = new SlGfwTouchButton(RecordFormUi);
        ZoomOutTouchButton->setObjectName(QString::fromUtf8("ZoomOutTouchButton"));
        ZoomOutTouchButton->setGeometry(QRect(372, 336, 80, 40));
        ZoomOutTouchButton->setPressed(false);
        ZoomOutTouchButton->setAnimationPressed(false);
        drawWidget = new PlotWidget2(RecordFormUi);
        drawWidget->setObjectName(QString::fromUtf8("drawWidget"));
        drawWidget->setGeometry(QRect(9, 100, 545, 231));
        CreateTimeLabel = new SlGfwLabel(RecordFormUi);
        CreateTimeLabel->setObjectName(QString::fromUtf8("CreateTimeLabel"));
        CreateTimeLabel->setGeometry(QRect(18, 40, 65, 31));
        CurvePosLabel = new SlGfwLabel(RecordFormUi);
        CurvePosLabel->setObjectName(QString::fromUtf8("CurvePosLabel"));
        CurvePosLabel->setGeometry(QRect(18, 70, 65, 31));
        CurvePosText = new SlGfwLabel(RecordFormUi);
        CurvePosText->setObjectName(QString::fromUtf8("CurvePosText"));
        CurvePosText->setGeometry(QRect(88, 70, 117, 31));
        CreateTimeText = new SlGfwLabel(RecordFormUi);
        CreateTimeText->setObjectName(QString::fromUtf8("CreateTimeText"));
        CreateTimeText->setGeometry(QRect(88, 40, 117, 31));
        label_31 = new SlGfwLabel(RecordFormUi);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(390, 41, 81, 31));
        TrainMileageLineEdit = new SlGfwLineEdit(RecordFormUi);
        TrainMileageLineEdit->setObjectName(QString::fromUtf8("TrainMileageLineEdit"));
        TrainMileageLineEdit->setGeometry(QRect(482, 41, 51, 27));
        TrainMileageLineEdit->setAlignment(Qt::AlignLeading);
        TrainMileageLineEdit->setReadOnly(true);
        label_32 = new SlGfwLabel(RecordFormUi);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(540, 41, 31, 31));

        retranslateUi(RecordFormUi);

        QMetaObject::connectSlotsByName(RecordFormUi);
    } // setupUi

    void retranslateUi(SlGfwDialogForm *RecordFormUi)
    {
        label->setStyleSheet(QApplication::translate("RecordFormUi", "background-color: rgb(255, 255, 0)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RecordFormUi", "\344\275\234\344\270\232\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("RecordFormUi", "\345\212\240\345\267\245\346\200\273\351\207\214\347\250\213", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("RecordFormUi", "km", 0, QApplication::UnicodeUTF8));
        RestoreTouchButton->setText(QApplication::translate("RecordFormUi", "\350\277\230\345\216\237\350\247\206\345\233\276", 0, QApplication::UnicodeUTF8));
        ZoomInTouchButton->setText(QApplication::translate("RecordFormUi", "\346\224\276\345\244\247", 0, QApplication::UnicodeUTF8));
        ZoomOutTouchButton->setText(QApplication::translate("RecordFormUi", "\347\274\251\345\260\217", 0, QApplication::UnicodeUTF8));
        CreateTimeLabel->setText(QApplication::translate("RecordFormUi", "\345\210\233\345\273\272\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        CurvePosLabel->setText(QApplication::translate("RecordFormUi", "\346\233\262\347\272\277\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
        CurvePosText->setText(QString());
        CreateTimeText->setText(QString());
        label_31->setText(QApplication::translate("RecordFormUi", "\350\241\214\351\251\266\346\200\273\351\207\214\347\250\213", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("RecordFormUi", "km", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(RecordFormUi);
    } // retranslateUi

};

namespace Ui {
    class RecordFormUi: public Ui_RecordFormUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDFORM_H
