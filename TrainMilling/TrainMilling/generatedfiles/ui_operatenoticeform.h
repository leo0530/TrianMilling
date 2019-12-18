/********************************************************************************
** Form generated from reading ui file 'operatenoticeform.ui'
**
** Created: Mon Dec 16 11:05:07 2019
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_OPERATENOTICEFORM_H
#define UI_OPERATENOTICEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include "slgfwdialogform.h"
#include "slgfwlabel.h"

QT_BEGIN_NAMESPACE

class Ui_OperateNoticeFormUi
{
public:
    SlGfwLabel *label;

    void setupUi(SlGfwDialogForm *OperateNoticeFormUi)
    {
        if (OperateNoticeFormUi->objectName().isEmpty())
            OperateNoticeFormUi->setObjectName(QString::fromUtf8("OperateNoticeFormUi"));
        OperateNoticeFormUi->resize(599, 373);
        label = new SlGfwLabel(OperateNoticeFormUi);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 20, 599, 353));

        retranslateUi(OperateNoticeFormUi);

        QMetaObject::connectSlotsByName(OperateNoticeFormUi);
    } // setupUi

    void retranslateUi(SlGfwDialogForm *OperateNoticeFormUi)
    {
        label->setStyleSheet(QApplication::translate("OperateNoticeFormUi", "border-image:url(C:/scr/OperateNotice.jpg)", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(OperateNoticeFormUi);
    } // retranslateUi

};

namespace Ui {
    class OperateNoticeFormUi: public Ui_OperateNoticeFormUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATENOTICEFORM_H
