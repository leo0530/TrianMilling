///////////////////////////////////////////////////////////////////////////////
/*! \file	statusform.h
 *  \author
 *  \date
 *  \brief	Definition file for class StatusForm
 *
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef STATUSFORM_H_INCLUDED
#define STATUSFORM_H_INCLUDED

#include "ui_statusform.h" //vom UIC erzeugte Header-Datei
#include "slgfwdialogform.h"
#include "GlobalVar.h"
#include "slgfwhmidialog.h"
#include "OperateIni.h"

/*! \class StatusForm
 *  \brief
*/
class StatusForm : public SlGfwDialogForm,
					public Ui::StatusFormUi
{
    Q_OBJECT

public:
    StatusForm(QWidget* pParent = 0, const QString& rszName = QString::null);
    virtual ~StatusForm(void);

public slots:
	void ShowSendData();
	virtual void onFunction (const QString& rszFunction, const QString& rszArgs, bool& rbHandled);

public:
	void RefreshState( );
	void RefreshData( );
	void RefreshBias( );
	void RefreshWorkState( bool bForceFresh );
	void RefreshWorkState_PLC( bool bForceFresh );
	void RefreshWorkState_PCU( bool bForceFresh );
	void RefreshShineState_PLC( bool bForceFresh  );
private:
	double double2double(double input_d);
    void attachedToScreen(const QString& rszScreenName);
    void detachedFromScreen(const QString& rszScreenName);

};

#endif // STATUSFORM_H_INCLUDED
