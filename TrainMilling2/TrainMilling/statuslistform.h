///////////////////////////////////////////////////////////////////////////////
/*! \file	statuslistform.h
 *  \author
 *  \date
 *  \brief	Definition file for class StatusListForm
 *
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef STATUSLISTFORM_H_INCLUDED
#define STATUSLISTFORM_H_INCLUDED

#include "ui_statuslistform.h" //vom UIC erzeugte Header-Datei
#include "slgfwdialogform.h"
#include "QDateTime.h"
#include "GlobalVar.h"
#include "OperateIni.h"
#include <QtCore/QTimer>
#include "QMutex.h"
/*! \class StatusListForm
 *  \brief
*/
class StatusListForm : public SlGfwDialogForm,
					public Ui::StatusListFormUi
{
    Q_OBJECT


public:

	StatusListForm(QWidget* pParent = 0, const QString& rszName = QString::null);
	virtual ~StatusListForm(void);

	QStringList		m_Lineitems;
	void			ListIOItems( );
	void			UpdateIOItems( );
	void			RandomIOSignals( );
public:
	QTimer			m_tmrToggle;
	QMutex			m_Mutex;
public slots:
	void			TimeOutSlot( );
	virtual void	onFunction (const QString& rszFunction, const QString& rszArgs, bool& rbHandled);

private:
	void			attachedToScreen(const QString& rszScreenName);
    void			detachedFromScreen(const QString& rszScreenName);

};

#endif // STATUSLISTFORM_H_INCLUDED
