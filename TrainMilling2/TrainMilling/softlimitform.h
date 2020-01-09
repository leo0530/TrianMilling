///////////////////////////////////////////////////////////////////////////////
/*! \file	softlimitform.h
 *  \author
 *  \date
 *  \brief	Definition file for class SoftLimitForm
 *
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef SOFTLIMITFORM_H_INCLUDED
#define SOFTLIMITFORM_H_INCLUDED

#include "ui_softlimitform.h" //vom UIC erzeugte Header-Datei
#include "slgfwdialogform.h"
#include "QDateTime.h"
#include "OperateIni.h"
#include "GlobalVar.h"
#include "slgfwhmidialog.h"
#include "slgfwsoftkey.h"

/*! \class SoftLimitForm：电机软限位
 *  \brief
*/
class SoftLimitForm : public SlGfwDialogForm,
					public Ui::SoftLimitFormUi
{
    Q_OBJECT


public:


    SoftLimitForm(QWidget* pParent = 0, const QString& rszName = QString::null);
    virtual ~SoftLimitForm(void);

public slots:

	virtual void onFunction (const QString& rszFunction, const QString& rszArgs, bool& rbHandled);


private:
    void attachedToScreen(const QString& rszScreenName);
    void detachedFromScreen(const QString& rszScreenName);

	void SaveParametersToIni( );
	void RefreshParameters( );
	void setSoftkeyDisable(int nSoftkey, bool bDisabled);
	void setLineEditReadOnly(bool bReadOnly);
	double double2double(double input_d);

};

#endif // SOFTLIMITFORM_H_INCLUDED
