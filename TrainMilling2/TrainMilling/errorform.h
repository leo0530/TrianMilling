///////////////////////////////////////////////////////////////////////////////
/*! \file	errorform.h
 *  \author
 *  \date
 *  \brief	Definition file for class ErrorForm
 *
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef ERRORFORM_H_INCLUDED
#define ERRORFORM_H_INCLUDED

#include "ui_errorform.h" //vom UIC erzeugte Header-Datei
#include "slgfwdialogform.h"
#include "slgfwhmidialog.h"
#include "slgfwscreen.h"
#include "slgfwsoftkey.h"
#include "SlGfwTreeWidget.h"
#include "SlAeQAlarmPtrList.h"
#include "SlAeQEventSource.h"
#include "slhmimakros.h"
#include <QtCore/QTimer>
#include "OperateIni.h"
#include "ErrorData.h"

#include "QFile.h"
#include "QDir.h"

// column 0 - alarm number
#define ALM_COL_NUMBER		0
// column 1 - timestamp in the local date time format
#define ALM_COL_TIMESTAMP   1
// column 2 - alarm state 
#define ALM_COL_STATE		2
// column 3 - alarm text
#define ALM_COL_TEXT		3
// column 3 - alarm text
#define ALM_COL_WORKSTATE	4
#define ALM_COL_MAX			ALM_COL_WORKSTATE


/*! \class ErrorForm£∫π ’œ–≈œ¢
 *  \brief
*/
class ErrorForm : public SlGfwDialogForm,
					public Ui::ErrorFormUi
{
    Q_OBJECT

public:

    ErrorForm(QWidget* pParent = 0, const QString& rszName = QString::null);
    virtual ~ErrorForm(void);

public slots:
    void onListChanged( );
	void TimeoutSlot();
	void SelectDate(const QDate &date);
	void SelectDate( );

public:
	void LoadErrFromDataBase( QString date );

public:
	void LoadErrFromAlarmList( );
	void setVSoftkeyDisable(int nSoftkey, bool bDisabled);
	void updateLabel(bool bTodayorHis);
	 ///////////////////////////////////////////////////////////////////////////
    // PRIVATE MEMBERS
    ///////////////////////////////////////////////////////////////////////////
private:
	QTimer		m_tmrToggle;
	bool		m_bTodayOrHis;
private:
	virtual void onFunction (const QString& rszFunction, const QString& rszArgs, bool& rbHandled);
    virtual void attachedToScreen(const QString& rszScreenName);
    virtual void detachedFromScreen(const QString& rszScreenName);
	virtual void onHelp(QString& rszDocument,QString& rszAnchor,bool& rbHandled);

private:


};

#endif // ERRORFORM_H_INCLUDED
