///////////////////////////////////////////////////////////////////////////////
/*! \file	devicerepair.cpp
 *  \author
 *  \date
 *  \brief	Implementation file for class DeviceRepair
 *
 *  This file is part of the HMI Solutionline GUI Framework.
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////
#include "devicerepair.h"


///////////////////////////////////////////////////////////////////////////////
// CREATORS
///////////////////////////////////////////////////////////////////////////////

DeviceRepair::DeviceRepair(QWidget* pParent, const QString& rszName)
	: SlGfwDialogForm(pParent, rszName)
{
	setupUi(this);

	QDateTime current_date_time =QDateTime::currentDateTime();
	QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss ddd");
	//Create The CaptionBar
	setCaptionBarElementCount(2);
	setCaptionBarElementAlignment(Qt::AlignLeft,0);
	setCaptionBarElementText(g_pIni->m_strProductInfo,0);
	setCaptionBarElementAlignment(Qt::AlignRight,1);
	setCaptionBarElementText(current_date,1);
	setCaptionBarVisible(true);

	// set the text of the main widget
	setStatusBarElementCount(2); 
	setStatusBarElementAlignment(Qt::AlignCenter,0);
	setStatusBarElementAlignment(Qt::AlignRight,1);
	setStatusBarVisible(true);
}// <-- DeviceRepair::DeviceRepair ()


DeviceRepair::~DeviceRepair(void)
{

} // <-- ::~ ()



void DeviceRepair::onFunction (const QString& rsFunction,
                                    const QString& rsArgs,
                                    bool& rbHandled)
{
	if ( "RepairLogin" == rsFunction )
	{
		RepairLogin();
	}
	if ( "RepairLogoff" == rsFunction )
	{
		g->m_nConfirmType = COMFIRM_REPAIRLOGOFF;
		dialog()->switchToScreen("ConfirmScreen",rsArgs);
	}
	else if("DebugLogin" == rsFunction)
	{
		QString TheInputPwd = RepairPwdLineEdit->value().toString();

		if(TheInputPwd == g_pIni->m_strDebugPwd)
		{
			g->m_bIsRepairLogin = true;
			dialog()->switchToScreen("DebugModeSreen",rsArgs);
		}
		else
		{
			g->m_bIsRepairLogin = false;
			setVSoftkeyDisable(3, g->m_bIsRepairLogin);
			setVSoftkeyDisable(4, !g->m_bIsRepairLogin);
			setVSoftkeyDisable(5, g->m_bIsRepairLogin);

			DisplayLabel->setText(g_pIni->m_strDebugPwdError);
		}
	}
	// need to call the base class
	if ( false == rbHandled )
		SlGfwDialogForm::onFunction(rsFunction, rsArgs, rbHandled);
} // <-- DeviceRepair::onFunction ()


void DeviceRepair::RepairLogin( )
{
	SlQCap nWriteServer;
	SlCapErrorEnum nError;
	QString TheInputPwd = RepairPwdLineEdit->value().toString();

	if(TheInputPwd == g_pIni->m_strRepairPwd)
	{
		g->m_bIsRepairLogin = true;

		RepairPwdLineEdit->clear();
		RepairPwdLineEdit->setReadOnly(true);
		DisplayLabel->setText(g_pIni->m_strRepairLogin);
		setVSoftkeyDisable(3, g->m_bIsRepairLogin);
		setVSoftkeyDisable(4, !g->m_bIsRepairLogin);
		setVSoftkeyDisable(5, g->m_bIsRepairLogin);

		nError = nWriteServer.write(szItem_RepairEnable_Bit,QVariant(true));//M31.4:检修使能标志
	}
	else
	{
		g->m_bIsRepairLogin = false;
		setVSoftkeyDisable(3, g->m_bIsRepairLogin);
		setVSoftkeyDisable(4, !g->m_bIsRepairLogin);
		setVSoftkeyDisable(5, g->m_bIsRepairLogin);
	
		DisplayLabel->setText(g_pIni->m_strRepairPwdError);
	}
}

void DeviceRepair::ShowRepairGui( )
{
	RepairPwdLineEdit->clear();
	RepairPwdLineEdit->setReadOnly(g->m_bIsRepairLogin);//根据登录与否设置密码输入框只读与否 ligy 20190918 add
	if(g->m_bIsRepairLogin)
		DisplayLabel->setText(g_pIni->m_strRepairLogin);
	else
		DisplayLabel->setText("");
	setVSoftkeyDisable(3, g->m_bIsRepairLogin);
	setVSoftkeyDisable(4, !g->m_bIsRepairLogin);
	setVSoftkeyDisable(5, g->m_bIsRepairLogin);

}

void DeviceRepair::setLoginOutKeyState()
{
	setVSoftkeyDisable(7, !g->m_bIsRepairLogin || !g->m_bIsRepairOver);
}

void DeviceRepair::attachedToScreen(const QString& rszScreenName)
{
	if(g->m_bIsLogin==false){
		dialog()->switchToScreen("MainScreen",NULL);
		return;
	}

	if(g->m_bIsLogin==true)
		setStatusBarElementText(g_pIni->m_strLogin, 1);
	else
		setStatusBarElementText(g_pIni->m_strNotLogin, 1);

	ShowRepairGui();

	g_pDeviceRepairForm = this;
    // don't forget to call the standard implementation
    SlGfwDialogForm::attachedToScreen(rszScreenName);
}

void DeviceRepair::detachedFromScreen(const QString& rszScreenName)
{
	g_pDeviceRepairForm = 0;
    // don't forget to call the standard implementation
    SlGfwDialogForm::detachedFromScreen(rszScreenName);
}

void DeviceRepair::setVSoftkeyDisable(int nSoftkey, bool bDisabled)
{
	// get pointer to screen
	SlGfwScreen* pScreen = dialog()->screenRef("DeviceRepairSreen");

	if ( 0 != pScreen )
	{
		// get pointer to softkey
		SlGfwSoftKey* pSoftkey = pScreen->menuSoftkey("DeviceRepairVr", nSoftkey);
		
		// enable/disable softkey
		if ( 0 != pSoftkey )
			pSoftkey->setDisabled(bDisabled);
	}
}