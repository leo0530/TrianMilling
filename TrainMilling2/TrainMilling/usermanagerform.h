///////////////////////////////////////////////////////////////////////////////
/*! \file	usermanagerform.h
 *  \author
 *  \date
 *  \brief	Definition file for class UserManagerForm
 *
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef USERMANAGERFORM_H_INCLUDED
#define USERMANAGERFORM_H_INCLUDED

#include "ui_usermanagerform.h" //vom UIC erzeugte Header-Datei
#include "slgfwdialogform.h"
#include "OperateIni.h"
#include "GlobalVar.h"
#include <QtCore/QTimer>
#include "slgfwhmidialog.h"
#include "slgfwscreen.h"
#include "slgfwsoftkey.h"
/*! \class UserManagerForm
 *  \brief
*/
#define UserPwdUI		1
#define RepairPwdUI		2
#define DebugPwdUI		3

class UserManagerForm : public SlGfwDialogForm,
					public Ui::UserManagerFormUi
{
    Q_OBJECT


public:

    ///////////////////////////////////////////////////////////////////////////
    // CREATORS
    ///////////////////////////////////////////////////////////////////////////

    /*!
     *	\fn UserManagerForm(QWidget* pParent = 0, const QString& rszName = QString::null)
     *
     *  Constructor
    */
    UserManagerForm(QWidget* pParent = 0, const QString& rszName = QString::null);

    /*! \fn virtual ~UserManagerForm(void)
     *
     *  Destructor
    */
    virtual ~UserManagerForm(void);



///////////////////////////////////////////////////////////////////////////////
// Overrides
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// public ACCESSORS
///////////////////////////////////////////////////////////////////////////////
public:
	QTimer	m_tmrToggle;
	void	SaveUserPassword( );
	void	SaveRepairPassword( );
	void	SaveDebugPassword( );

	void	setSoftkeyDisable(int nSoftkey, bool bDisabled);
	void	setLineEditReadOnly(bool bReadOnly);
	int		m_UIType;
	void	setPwdUI(int nType);
	void	setUserName(int nType);

///////////////////////////////////////////////////////////////////////////////
// MANIPULATORS - system overrides
///////////////////////////////////////////////////////////////////////////////


public slots:
	void	TimeOutSlot( );
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


private:
	///////////////////////////////////////////////////////////////////////////////
	// member variables
	///////////////////////////////////////////////////////////////////////////////
	/*! \fn void attachedToScreen(const QString& rszScreenName)
     *  \param rszScreenName			name of the screen
     *
     *  will be called by the framework, if the form is attached to screen rszScreenName
    */
    void attachedToScreen(const QString& rszScreenName);

    /*! \fn void detachedFromScreen(const QString& rszScreenName)
     *  \param rszScreenName			name of the screen
     *
     *  will be called by the framework, if the form is detached from screen rszScreenName
    */
    void detachedFromScreen(const QString& rszScreenName);



///////////////////////////////////////////////////////////////////////////////
// private METHODS
///////////////////////////////////////////////////////////////////////////////



};

#endif // USERMANAGERFORM_H_INCLUDED
