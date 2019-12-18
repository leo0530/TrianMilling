///////////////////////////////////////////////////////////////////////////////
/*! \file	systemform.h
 *  \author
 *  \date
 *  \brief	Definition file for class SystemForm
 *
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef SYSTEMFORM_H_INCLUDED
#define SYSTEMFORM_H_INCLUDED

#include "ui_systemform.h" //vom UIC erzeugte Header-Datei
#include "slgfwdialogform.h"
#include <QtCore/QTimer>
#include "slqcap.h"
#include "OperateIni.h"
#include "slgfwhmidialog.h"
#include "slgfwscreen.h"
#include "slgfwsoftkey.h"
/*! \class SystemForm：系统参数
 *  \brief
*/
class SystemForm : public SlGfwDialogForm,
					public Ui::SystemFormUi
{
    Q_OBJECT


public:

    ///////////////////////////////////////////////////////////////////////////
    // CREATORS
    ///////////////////////////////////////////////////////////////////////////

    /*!
     *	\fn SystemForm(QWidget* pParent = 0, const QString& rszName = QString::null)
     *
     *  Constructor
    */
    SystemForm(QWidget* pParent = 0, const QString& rszName = QString::null);

    /*! \fn virtual ~SystemForm(void)
     *
     *  Destructor
    */
    virtual ~SystemForm(void);

public slots:
	void TimeoutSlot();
///////////////////////////////////////////////////////////////////////////////
// public SLOTS - system overrides
///////////////////////////////////////////////////////////////////////////////
/*!
*  \fn virtual void onFunction(const QString& rszFunction, const QString& rszArgs, bool& rbHandled);
*
*  Will be called by the framework, if a function should be executed, e.g. if a softkey
*  should execute a command
*/
virtual void onFunction (const QString& rszFunction, const QString& rszArgs, bool& rbHandled);

///////////////////////////////////////////////////////////////////////////////
// member variables
///////////////////////////////////////////////////////////////////////////////
private:
	QTimer	m_tmrToggle;



	/*! SlQCap server for data access */
	SlQCap			m_capServer;
///////////////////////////////////////////////////////////////////////////////
// private METHODS
///////////////////////////////////////////////////////////////////////////////
private:
	void DisplaySystemParameters();
	void WriteSystemParametersToIni();
	void WriteSystemParametersToCNC();
	void handleRetVal(SlCapErrorEnum eError);
    void attachedToScreen(const QString& rszScreenName);
    void detachedFromScreen(const QString& rszScreenName);
	void setLineEditReadOnly(bool bReadOnly);
	void setSoftkeyDisable(int nSoftkey, bool bDisabled);
	bool checkValid();
};

#endif // SYSTEMFORM_H_INCLUDED
