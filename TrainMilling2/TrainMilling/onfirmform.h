///////////////////////////////////////////////////////////////////////////////
/*! \file	onfirmform.h
 *  \author
 *  \date
 *  \brief	Definition file for class ConfirmForm
 *
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef CONFIRMFORM_H_INCLUDED
#define CONFIRMFORM_H_INCLUDED

#include "ui_confirmform.h" //vom UIC erzeugte Header-Datei
#include "slgfwdialogform.h"
#include "QDateTime.h"
#include "OperateIni.h"
#include "GlobalVar.h"
#include "slgfwhmidialog.h"

/*! \class ConfirmForm
 *  \brief
*/
class ConfirmForm : public SlGfwDialogForm,
					public Ui::ConfirmFormUi
{
    Q_OBJECT
public:
    ConfirmForm(QWidget* pParent = 0, const QString& rszName = QString::null);
    virtual ~ConfirmForm(void);

public slots:
	virtual void	onFunction (const QString& rszFunction, const QString& rszArgs, bool& rbHandled);

private:
	void			attachedToScreen(const QString& rszScreenName);
	void			detachedFromScreen(const QString& rszScreenName);
	void			YesFunction(const QString& rsArgs);
	void			NoFunction(const QString& rsArgs);

};

#endif // CONFIRMFORM_H_INCLUDED
