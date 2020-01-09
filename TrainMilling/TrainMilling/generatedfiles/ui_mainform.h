/********************************************************************************
** Form generated from reading ui file 'mainform.ui'
**
** Created: Wed Jan 8 15:11:25 2020
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>
#include "slgfwdialogform.h"
#include "slgfwlabel.h"
#include "slgfwlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_MainFormUi
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *framepanel;
    SlGfwLabel *PasswordLabel;
    SlGfwLabel *UserNameLabel;
    SlGfwLineEdit *PasswordLineEdit;
    SlGfwLineEdit *UserNameLineEdit;

    void setupUi(SlGfwDialogForm *MainFormUi)
    {
        if (MainFormUi->objectName().isEmpty())
            MainFormUi->setObjectName(QString::fromUtf8("MainFormUi"));
        MainFormUi->resize(599, 373);
        verticalLayout = new QVBoxLayout(MainFormUi);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        framepanel = new QFrame(MainFormUi);
        framepanel->setObjectName(QString::fromUtf8("framepanel"));
        framepanel->setFrameShadow(QFrame::Raised);
        PasswordLabel = new SlGfwLabel(framepanel);
        PasswordLabel->setObjectName(QString::fromUtf8("PasswordLabel"));
        PasswordLabel->setGeometry(QRect(383, 290, 38, 25));
        PasswordLabel->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        PasswordLabel->setDisplayMode(SlGfwFunctions::ANY_MODE);
        UserNameLabel = new SlGfwLabel(framepanel);
        UserNameLabel->setObjectName(QString::fromUtf8("UserNameLabel"));
        UserNameLabel->setGeometry(QRect(219, 290, 54, 25));
        UserNameLabel->setAutoFillBackground(false);
        UserNameLabel->setFrameShadow(QFrame::Raised);
        UserNameLabel->setInverseColors(false);
        PasswordLineEdit = new SlGfwLineEdit(framepanel);
        PasswordLineEdit->setObjectName(QString::fromUtf8("PasswordLineEdit"));
        PasswordLineEdit->setGeometry(QRect(425, 290, 102, 25));
        PasswordLineEdit->setFocusPolicy(Qt::StrongFocus);
        PasswordLineEdit->setEchoMode(SlGfwLineEdit::PASSWORD);
        PasswordLineEdit->setAlignment(Qt::AlignHCenter);
        PasswordLineEdit->setInputMode(SlGfwFunctions::ANY_MODE);
        UserNameLineEdit = new SlGfwLineEdit(framepanel);
        UserNameLineEdit->setObjectName(QString::fromUtf8("UserNameLineEdit"));
        UserNameLineEdit->setEnabled(true);
        UserNameLineEdit->setGeometry(QRect(277, 290, 102, 25));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(6);
        sizePolicy.setHeightForWidth(UserNameLineEdit->sizePolicy().hasHeightForWidth());
        UserNameLineEdit->setSizePolicy(sizePolicy);
        UserNameLineEdit->setAlignment(Qt::AlignHCenter);
        UserNameLineEdit->setReadOnly(true);

        verticalLayout->addWidget(framepanel);

        QWidget::setTabOrder(PasswordLineEdit, UserNameLineEdit);

        retranslateUi(MainFormUi);

        QMetaObject::connectSlotsByName(MainFormUi);
    } // setupUi

    void retranslateUi(SlGfwDialogForm *MainFormUi)
    {
        MainFormUi->setStyleSheet(QString());
        framepanel->setStyleSheet(QApplication::translate("MainFormUi", "QFrame#framepanel{border-image:url(C:/scr/background.png)}", 0, QApplication::UnicodeUTF8));
        PasswordLabel->setText(QApplication::translate("MainFormUi", "\345\257\206\347\240\201:", 0, QApplication::UnicodeUTF8));
        UserNameLabel->setText(QApplication::translate("MainFormUi", "\347\224\250\346\210\267\345\220\215:", 0, QApplication::UnicodeUTF8));
        PasswordLineEdit->setInputMask(QString());
        Q_UNUSED(MainFormUi);
    } // retranslateUi

};

namespace Ui {
    class MainFormUi: public Ui_MainFormUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
