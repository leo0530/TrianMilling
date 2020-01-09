///////////////////////////////////////////////////////////////////////////////
/*! \file	railcalibform.h
 *  \author
 *  \date
 *  \brief	Definition file for class RailCalibForm
 *
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef RAILCALIBFORM_H_INCLUDED
#define RAILCALIBFORM_H_INCLUDED

#include "ui_railcalibform.h" //vom UIC erzeugte Header-Datei
#include "slgfwdialogform.h"
#include "OperateIni.h"
#include "slqcap.h"
#include "slgfwhmidialog.h"
#include "slgfwsoftkey.h"
/*! \class RailCalibForm£∫µ∂≈Ã∂‘µ∂
 *  \brief
*/
class RailCalibForm : public SlGfwDialogForm,
					public Ui::RailCalibFormUi
{
    Q_OBJECT
public:

    RailCalibForm(QWidget* pParent = 0, const QString& rszName = QString::null);
    virtual ~RailCalibForm(void);
public:
	SlQCap	m_capServer;
	bool	m_bStopFresh;
public:
	void	setSoftkeyDisable(int nSoftkey, bool bDisabled);
	void	FreshParameters( );
	void	DisplayIniParameters( );
	void	SaveParametersToIni( int nType );
	void	SaveParametersToCNC( );
	void	handleRetVal(SlCapErrorEnum eError);

public slots:

	virtual void onFunction (const QString& rszFunction, const QString& rszArgs, bool& rbHandled);

    virtual void attachedToScreen(const QString& rszScreenName);
    virtual void detachedFromScreen(const QString& rszScreenName);

private:

};

#endif // RAILCALIBFORM_H_INCLUDED
