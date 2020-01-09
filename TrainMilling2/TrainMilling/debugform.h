///////////////////////////////////////////////////////////////////////////////
/*! \file	debugform.h
 *  \author
 *  \date
 *  \brief	Definition file for class DebugForm
 *
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef DEBUGFORM_H_INCLUDED
#define DEBUGFORM_H_INCLUDED

#include "ui_debugform.h" //vom UIC erzeugte Header-Datei
#include "slgfwdialogform.h"
#include "slqcap.h"
#include "QTimer.h"
#include "GlobalVar.h"
#include "OperateIni.h"
#include "NNScreen.h"
#include "slgfwhmidialog.h"
#include "slgfwscreen.h"
#include "slgfwsoftkey.h"
#include "QFile.h"
#include "QTextStream.h"
#include "QTextCodec.h"
#include "OperateIni.h"
#include "CSendMail.h"
#include <QtCore/QTextStream>
#include <sstream>
/*! \class DebugForm
 *  \brief
*/
class DebugForm : public SlGfwDialogForm,
					public Ui::DebugFormUi
{
    Q_OBJECT


public:

    ///////////////////////////////////////////////////////////////////////////
    // CREATORS
    ///////////////////////////////////////////////////////////////////////////

    /*!
     *	\fn DebugForm(QWidget* pParent = 0, const QString& rszName = QString::null)
     *
     *  Constructor
    */
    DebugForm(QWidget* pParent = 0, const QString& rszName = QString::null);

    /*! \fn virtual ~DebugForm(void)
     *
     *  Destructor
    */
    virtual ~DebugForm(void);



///////////////////////////////////////////////////////////////////////////////
// Overrides
///////////////////////////////////////////////////////////////////////////////
public:

///////////////////////////////////////////////////////////////////////////////
// public ACCESSORS
///////////////////////////////////////////////////////////////////////////////

public:
	QTimer	m_tmrToggle;
	bool	m_bDebugLogin;
	bool	m_bStartRemoteControl;
	SlQCap	m_capServer;

public:
	QString		m_strIP;
	HWND		m_hWndVideo;
	QString		m_strStatus;
	QString		m_strID;
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


private:

///////////////////////////////////////////////////////////////////////////////
// member variables
///////////////////////////////////////////////////////////////////////////////
    void attachedToScreen(const QString& rszScreenName);
    void detachedFromScreen(const QString& rszScreenName);
///////////////////////////////////////////////////////////////////////////////
// private METHODS
///////////////////////////////////////////////////////////////////////////////
private:
	void setSoftkeyDisable(int nSoftkey, bool bDisabled);
	void CreateScreenIni();
	void CreateScreenEnd();
	void SwitchGui(bool bFlag=true);
	void SaveResetParametersToCNC();
	bool sendMail(char* name, LPCSTR id);
	void handleRetVal(SlCapErrorEnum eError);

};

#endif // DEBUGFORM_H_INCLUDED
