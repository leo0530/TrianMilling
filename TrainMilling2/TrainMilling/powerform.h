///////////////////////////////////////////////////////////////////////////////
/*! \file	powerform.h
 *  \author
 *  \date
 *  \brief	Definition file for class PowerForm
 *
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////
#pragma once
#ifndef POWERFORM_H_INCLUDED
#define POWERFORM_H_INCLUDED

#include "ui_powerform.h" //vom UIC erzeugte Header-Datei
#include "slgfwdialogform.h"
#include "SlGfwTreeWidget.h"
#include "slqcap.h"
#include <QtCore/QTimer>
#include "GlobalVar.h"
#include "OperateIni.h"

#define POWER_COL_DEVICE		0
#define POWER_COL_CURPOWER		1
#define POWER_COL_ENERGYINPUT	2
#define POWER_COL_REGENERGY		3
#define POWER_COL_TOTALENERGY	4
#define POWER_COL_MAX			POWER_COL_TOTALENERGY

/*! \class PowerForm
 *  \brief
*/
class PowerForm : public SlGfwDialogForm,
					public Ui::PowerFormUi
{
    Q_OBJECT


public:

    ///////////////////////////////////////////////////////////////////////////
    // CREATORS
    ///////////////////////////////////////////////////////////////////////////

    /*!
     *	\fn PowerForm(QWidget* pParent = 0, const QString& rszName = QString::null)
     *
     *  Constructor
    */
    PowerForm(QWidget* pParent = 0, const QString& rszName = QString::null);

    /*! \fn virtual ~PowerForm(void)
     *
     *  Destructor
    */
    virtual ~PowerForm(void);

	void handleRetVal(SlCapErrorEnum eError);


///////////////////////////////////////////////////////////////////////////////
// Overrides
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// public ACCESSORS
///////////////////////////////////////////////////////////////////////////////
public:
    SlGfwTreeWidget*			m_pTreeWidget;
public:
	QTimer						m_tmrToggle;
///////////////////////////////////////////////////////////////////////////////
// MANIPULATORS - system overrides
///////////////////////////////////////////////////////////////////////////////
public slots:
	void timeoutSlot( );
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

	virtual void attachedToScreen(const QString& rszScreenName);

	/*! \fn virtual void detachedFromScreen(const QString& rszScreenName)
	 *  \param rszScreenName			name of the screen
	 *
	 *  will be called by the framework, if the form is detached from screen rszScreenName
	*/
	virtual void detachedFromScreen(const QString& rszScreenName);
private:

///////////////////////////////////////////////////////////////////////////////
// member variables
///////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////
// private METHODS
///////////////////////////////////////////////////////////////////////////////



};

#endif // POWERFORM_H_INCLUDED
