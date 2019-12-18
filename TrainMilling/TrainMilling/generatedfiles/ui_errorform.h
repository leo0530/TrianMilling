/********************************************************************************
** Form generated from reading ui file 'errorform.ui'
**
** Created: Mon Dec 16 11:05:08 2019
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ERRORFORM_H
#define UI_ERRORFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QHeaderView>
#include "slgfwdialogform.h"
#include "slgfwlabel.h"
#include "slgfwtreeview.h"
#include "slgfwtreewidget.h"

QT_BEGIN_NAMESPACE

class Ui_ErrorFormUi
{
public:
    SlGfwLabel *TodayLabel;
    SlGfwTreeWidget *m_pTreeWidget;
    QCalendarWidget *calendarWidget;
    SlGfwLabel *HistoryLabel;

    void setupUi(SlGfwDialogForm *ErrorFormUi)
    {
        if (ErrorFormUi->objectName().isEmpty())
            ErrorFormUi->setObjectName(QString::fromUtf8("ErrorFormUi"));
        ErrorFormUi->resize(599, 375);
        TodayLabel = new SlGfwLabel(ErrorFormUi);
        TodayLabel->setObjectName(QString::fromUtf8("TodayLabel"));
        TodayLabel->setGeometry(QRect(210, 23, 171, 38));
        QFont font;
        font.setFamily(QString::fromUtf8("Siemens AD CH Simplified"));
        font.setBold(false);
        font.setWeight(50);
        TodayLabel->setFont(font);
        TodayLabel->setAutoFillBackground(false);
        TodayLabel->setHmiFontSize(-5);
        TodayLabel->setAlignment(Qt::AlignCenter);
        m_pTreeWidget = new SlGfwTreeWidget(ErrorFormUi);
        m_pTreeWidget->setObjectName(QString::fromUtf8("m_pTreeWidget"));
        m_pTreeWidget->setGeometry(QRect(0, 64, 555, 310));
        calendarWidget = new QCalendarWidget(ErrorFormUi);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(327, 220, 232, 148));
        HistoryLabel = new SlGfwLabel(ErrorFormUi);
        HistoryLabel->setObjectName(QString::fromUtf8("HistoryLabel"));
        HistoryLabel->setGeometry(QRect(210, 23, 171, 38));
        HistoryLabel->setFont(font);
        HistoryLabel->setAutoFillBackground(false);
        HistoryLabel->setHmiFontSize(-5);
        HistoryLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(ErrorFormUi);

        QMetaObject::connectSlotsByName(ErrorFormUi);
    } // setupUi

    void retranslateUi(SlGfwDialogForm *ErrorFormUi)
    {
        TodayLabel->setStyleSheet(QApplication::translate("ErrorFormUi", "background-color: rgb(255, 255, 0)", 0, QApplication::UnicodeUTF8));
        TodayLabel->setText(QApplication::translate("ErrorFormUi", "\344\273\212\346\227\245\346\225\205\351\232\234", 0, QApplication::UnicodeUTF8));
        HistoryLabel->setStyleSheet(QApplication::translate("ErrorFormUi", "background-color: rgb(255, 255, 0)", 0, QApplication::UnicodeUTF8));
        HistoryLabel->setText(QApplication::translate("ErrorFormUi", "\345\216\206\345\217\262\346\225\205\351\232\234", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(ErrorFormUi);
    } // retranslateUi

};

namespace Ui {
    class ErrorFormUi: public Ui_ErrorFormUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORFORM_H
