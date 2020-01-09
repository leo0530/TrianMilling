/********************************************************************************
** Form generated from reading ui file 'confirmform.ui'
**
** Created: Wed Jan 8 15:11:25 2020
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CONFIRMFORM_H
#define UI_CONFIRMFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include "slgfwdialogform.h"

QT_BEGIN_NAMESPACE

class Ui_ConfirmFormUi
{
public:
    QLabel *ShowTextLabel;

    void setupUi(SlGfwDialogForm *ConfirmFormUi)
    {
        if (ConfirmFormUi->objectName().isEmpty())
            ConfirmFormUi->setObjectName(QString::fromUtf8("ConfirmFormUi"));
        ConfirmFormUi->resize(599, 373);
        ShowTextLabel = new QLabel(ConfirmFormUi);
        ShowTextLabel->setObjectName(QString::fromUtf8("ShowTextLabel"));
        ShowTextLabel->setGeometry(QRect(0, 120, 599, 141));
        ShowTextLabel->setHmiFonts(true);
        ShowTextLabel->setHmiColors(true);
        ShowTextLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(ConfirmFormUi);

        QMetaObject::connectSlotsByName(ConfirmFormUi);
    } // setupUi

    void retranslateUi(SlGfwDialogForm *ConfirmFormUi)
    {
        ShowTextLabel->setText(QString());
        Q_UNUSED(ConfirmFormUi);
    } // retranslateUi

};

namespace Ui {
    class ConfirmFormUi: public Ui_ConfirmFormUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMFORM_H
