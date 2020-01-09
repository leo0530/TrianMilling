///////////////////////////////////////////////////////////////////////////////
/*! \file	poffsetform.h
 *  \author
 *  \date
 *  \brief	Definition file for class CPOffsetForm
 *
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef CPOFFSETFORM_H_INCLUDED
#define CPOFFSETFORM_H_INCLUDED

#include "ui_cpoffsetform.h" //vom UIC erzeugte Header-Datei
#include "slgfwdialogform.h"
#include "OperateIni.h"
#include "QDateTime.h"
#include "GlobalVar.h"
#include "slqcap.h"
#include "slgfwhmidialog.h"
#include "slgfwscreen.h"
#include "slgfwsoftkey.h"
/*! \class CPOffsetForm：传感器及 软件靴设置
 *  \brief
*/
class CPOffsetForm : public SlGfwDialogForm,
					public Ui::CPOffsetFormUi
{
    Q_OBJECT


public:

    ///////////////////////////////////////////////////////////////////////////
    // CREATORS
    ///////////////////////////////////////////////////////////////////////////

    /*!
     *	\fn CPOffsetForm(QWidget* pParent = 0, const QString& rszName = QString::null)
     *
     *  Constructor
    */
    CPOffsetForm(QWidget* pParent = 0, const QString& rszName = QString::null);

    /*! \fn virtual ~CPOffsetForm(void)
     *
     *  Destructor
    */
    virtual ~CPOffsetForm(void);

public:
	/*! SlQCap server for data access */
	SlQCap			m_capServer;

	void setLineEditReadOnly(bool bReadOnly);
	void setSoftkeyDisable(int nSoftkey, bool bDisabled);
	void DisplayCPOffsetParameters();
	void SaveParametersToIni();
	void SaveParametersToCNC();
	void handleRetVal(SlCapErrorEnum eError);

public slots:
	//void H_LowPassFilterStateChanged(int);
	//void V_LowPassFilterStateChanged(int);
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

#endif // CPOFFSETFORM_H_INCLUDED
