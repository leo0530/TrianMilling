///////////////////////////////////////////////////////////////////////////////
/*! \file	parameterform.h
 *  \author
 *  \date
 *  \brief	Definition file for class parameterform
 *
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef PARAMETERFORM_H_INCLUDED
#define PARAMETERFORM_H_INCLUDED

#include "ui_parameterform.h" //vom UIC erzeugte Header-Datei
#include "slgfwdialogform.h"
#include <QtCore/QTimer>
#include "slqcap.h"
#include "OperateIni.h"
#include "slgfwhmidialog.h"
#include "slgfwscreen.h"
#include "slgfwsoftkey.h"
#include "SlGfwLineEdit.h"
/*! \class parameterform：作业参数
 *  \brief
*/
class ParameterForm : public SlGfwDialogForm,
					public Ui::ParameterFormUi
{
    Q_OBJECT

public:
    ParameterForm(QWidget* pParent = 0, const QString& rszName = QString::null);
    virtual ~ParameterForm(void);

public slots:
	void			TimeoutSlot();
	virtual void	onFunction (const QString& rszFunction, const QString& rszArgs, bool& rbHandled);

private:
	QTimer			m_tmrToggle;
	int				m_nMillingModuleSelect;
	SlQCap			m_capServer;

///////////////////////////////////////////////////////////////////////////////
// private METHODS
///////////////////////////////////////////////////////////////////////////////
public:
	void			WriteWorkingParametersToCNC();
private:
	void			WriteWorkingParametersToIni();
	void			handleRetVal(SlCapErrorEnum eError);
    void			attachedToScreen(const QString& rszScreenName);
    void			detachedFromScreen(const QString& rszScreenName);
	void			setLineEditReadOnly(bool bReadOnly);
	void			setSoftkeyDisable(int nSoftkey, bool bDisabled);
	void			MillingModuleSelect( );
	void			PowerControlSelect( );
	void			AxisSpeedSelect( );
	void			TrainSpeedPlus( );
	void			TrainSpeedMinus( );
	bool			checkValid();
public:
	void			RefreshWorkingParameters( );
};

#endif // PARAMETERFORM_H_INCLUDED
