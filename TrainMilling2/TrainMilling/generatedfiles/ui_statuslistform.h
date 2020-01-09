/********************************************************************************
** Form generated from reading ui file 'statuslistform.ui'
**
** Created: Mon Dec 16 11:05:06 2019
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_STATUSLISTFORM_H
#define UI_STATUSLISTFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include "slgfwdialogform.h"
#include "slgfwtreeview.h"
#include "slgfwtreewidget.h"

QT_BEGIN_NAMESPACE

class Ui_StatusListFormUi
{
public:
    SlGfwTreeWidget *m_pLeftTreeWidget;
    SlGfwTreeWidget *m_pRightTreeWidget;

    void setupUi(SlGfwDialogForm *StatusListFormUi)
    {
        if (StatusListFormUi->objectName().isEmpty())
            StatusListFormUi->setObjectName(QString::fromUtf8("StatusListFormUi"));
        StatusListFormUi->resize(559, 373);
        m_pLeftTreeWidget = new SlGfwTreeWidget(StatusListFormUi);
        m_pLeftTreeWidget->setObjectName(QString::fromUtf8("m_pLeftTreeWidget"));
        m_pLeftTreeWidget->setGeometry(QRect(0, 20, 280, 353));
        m_pRightTreeWidget = new SlGfwTreeWidget(StatusListFormUi);
        m_pRightTreeWidget->setObjectName(QString::fromUtf8("m_pRightTreeWidget"));
        m_pRightTreeWidget->setGeometry(QRect(280, 20, 280, 353));

        retranslateUi(StatusListFormUi);

        QMetaObject::connectSlotsByName(StatusListFormUi);
    } // setupUi

    void retranslateUi(SlGfwDialogForm *StatusListFormUi)
    {
        Q_UNUSED(StatusListFormUi);
    } // retranslateUi

};

namespace Ui {
    class StatusListFormUi: public Ui_StatusListFormUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUSLISTFORM_H
