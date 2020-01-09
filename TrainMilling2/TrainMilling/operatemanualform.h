///////////////////////////////////////////////////////////////////////////////
/*! \file	operatemanualform.h
 *  \author
 *  \date
 *  \brief	Definition file for class OperateManualForm
 *
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef OPERATEMANUALFORM_H_INCLUDED
#define OPERATEMANUALFORM_H_INCLUDED

#include "ui_operatemanualform.h" //vom UIC erzeugte Header-Datei
#include "slgfwdialogform.h"
#include "GlobalVar.h"
#include <QtCore/QTimer>
#include "slgfwhmidialog.h"
#include "slgfwsoftkey.h"
#include "OperateIni.h"
/*! \class OperateManualForm
 *  \brief
*/
class OperateManualForm : public SlGfwDialogForm,
					public Ui::OperateManualFormUi
{
    Q_OBJECT


public:

    ///////////////////////////////////////////////////////////////////////////
    // CREATORS
    ///////////////////////////////////////////////////////////////////////////

    /*!
     *	\fn OperateManualForm(QWidget* pParent = 0, const QString& rszName = QString::null)
     *
     *  Constructor
    */
    OperateManualForm(QWidget* pParent = 0, const QString& rszName = QString::null);

    /*! \fn virtual ~OperateManualForm(void)
     *
     *  Destructor
    */
    virtual ~OperateManualForm(void);



///////////////////////////////////////////////////////////////////////////////
// Overrides
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// public ACCESSORS
///////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////
// MANIPULATORS - system overrides
///////////////////////////////////////////////////////////////////////////////


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


private:

///////////////////////////////////////////////////////////////////////////////
// member variables
///////////////////////////////////////////////////////////////////////////////
    void attachedToScreen(const QString& rszScreenName);
    void detachedFromScreen(const QString& rszScreenName);
	void setSoftkeyDisable(int nSoftkey, bool bDisabled);


///////////////////////////////////////////////////////////////////////////////
// private METHODS
///////////////////////////////////////////////////////////////////////////////
	QTimer		m_tmrToggle;
	QStringList m_PicNameList;
	int			m_PicIndex;

};

#endif // OPERATEMANUALFORM_H_INCLUDED