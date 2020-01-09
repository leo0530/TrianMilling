///////////////////////////////////////////////////////////////////////////////
/*! \file	devicerepair.h
 *  \author
 *  \date
 *  \brief	Definition file for class DeviceRepair
 *
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef DEVICEREPAIR_H_INCLUDED
#define DEVICEREPAIR_H_INCLUDED

#include "ui_devicerepair.h" //vom UIC erzeugte Header-Datei
#include "slgfwdialogform.h"
#include "OperateIni.h"
#include "QDateTime.h"
#include "GlobalVar.h"
#include "slgfwhmidialog.h"
#include "slgfwscreen.h"
#include "slgfwsoftkey.h"

/*! \class DeviceRepair:¼ìÐÞÄ£Ê½
 *  \brief 
*/
class DeviceRepair : public SlGfwDialogForm,
					public Ui::DeviceRepairUi
{
    Q_OBJECT

public:
    DeviceRepair(QWidget* pParent = 0, const QString& rszName = QString::null);
    virtual ~DeviceRepair(void);


public slots:
	virtual void	onFunction (const QString& rszFunction, const QString& rszArgs, bool& rbHandled);
    void			attachedToScreen(const QString& rszScreenName);
    void			detachedFromScreen(const QString& rszScreenName);

private:
	void			RepairLogin();
	void			ShowRepairGui();
	void			setVSoftkeyDisable(int nSoftkey, bool bDisabled);
public:
	void			setLoginOutKeyState();

};

#endif // DEVICEREPAIR_H_INCLUDED
