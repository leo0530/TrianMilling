///////////////////////////////////////////////////////////////////////////////
/*! \file	debugmodeform.cpp
 *  \author
 *  \date
 *  \brief	Implementation file for class DebugModeForm
 *
 *  This file is part of the HMI Solutionline GUI Framework.
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////
#include "debugmodeform.h"



///////////////////////////////////////////////////////////////////////////////
// CREATORS
///////////////////////////////////////////////////////////////////////////////

DebugModeForm::DebugModeForm(QWidget* pParent, const QString& rszName)
	: SlGfwDialogForm(pParent, rszName)
{
	setupUi(this);

}// <-- DebugModeForm::DebugModeForm ()


DebugModeForm::~DebugModeForm(void)
{

} // <-- ::~ ()


///////////////////////////////////////////////////////////////////////////////
// Overrides
///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// public ACCESSORS
///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// MANIPULATORS - system overrides
///////////////////////////////////////////////////////////////////////////////

void DebugModeForm::attachedToScreen(const QString& rszScreenName)
{
	if(g->m_bIsLogin==false){
		dialog()->switchToScreen("MainScreen",NULL);
		return;
	}

	if(g->m_bIsLogin==true)
		setStatusBarElementText(g_pIni->m_strLogin, 1);
	else
		setStatusBarElementText(g_pIni->m_strNotLogin, 1);

	DebugPwdLineEdit->clear();
	DebugPwdLineEdit->setReadOnly(g->m_bIsRepairLogin);//根据登录与否设置密码输入框只读与否 ligy 20190918 add
	if(g->m_bIsRepairLogin)
		DisplayLabel->setText(g_pIni->m_strRepairLogin);
	else
		DisplayLabel->setText("");

	g_pDebugModeForm = this;
	// don't forget to call the standard implementation
	SlGfwDialogForm::attachedToScreen(rszScreenName);
}

void DebugModeForm::detachedFromScreen(const QString& rszScreenName)
{
	g_pDebugModeForm = 0;
	// don't forget to call the standard implementation
	SlGfwDialogForm::detachedFromScreen(rszScreenName);
}

///////////////////////////////////////////////////////////////////////////////
// public SLOTS - system overrides
///////////////////////////////////////////////////////////////////////////////
void DebugModeForm::onFunction (const QString& rsFunction,
                                    const QString& rsArgs,
                                    bool& rbHandled)
{
      //call base class
	if ("DebugLogoff" == rsFunction)
	{
		g->m_nConfirmType = COMFIRM_REPAIRLOGOFF;
		dialog()->switchToScreen("ConfirmScreen",rsArgs);
	}
      SlGfwDialogForm::onFunction(rsFunction, rsArgs, rbHandled);

} // <-- DebugModeForm::onFunction ()


///////////////////////////////////////////////////////////////////////////////
// private methods
///////////////////////////////////////////////////////////////////////////////
void DebugModeForm::setVSoftkeyDisable(int nSoftkey, bool bDisabled)
{
	// get pointer to screen
	SlGfwScreen* pScreen = dialog()->screenRef("DebugModeSreen");

	if ( 0 != pScreen )
	{
		// get pointer to softkey
		SlGfwSoftKey* pSoftkey = pScreen->menuSoftkey("DebugVr", nSoftkey);

		// enable/disable softkey
		if ( 0 != pSoftkey )
			pSoftkey->setDisabled(bDisabled);
	}
}

void DebugModeForm::DebugLogin( )
{
	QString TheInputPwd = DebugPwdLineEdit->value().toString();

	if(TheInputPwd == g_pIni->m_strRepairPwd)
	{
		g->m_bIsDebugModeLogin = true;

		DebugPwdLineEdit->clear();
		DebugPwdLineEdit->setReadOnly(true);
	//	DisplayLabel->setText(g_pIni->m_strRepairLogin);
		setVSoftkeyDisable(3, g->m_bIsDebugModeLogin);
		setVSoftkeyDisable(4, !g->m_bIsDebugModeLogin);
		setVSoftkeyDisable(5, !g->m_bIsDebugModeLogin);
		setVSoftkeyDisable(6, !g->m_bIsDebugModeLogin);
		setVSoftkeyDisable(7, !g->m_bIsDebugModeLogin || !g->m_bIsRepairOver);
		setVSoftkeyDisable(8, g->m_bIsDebugModeLogin);

		//nError = nWriteServer.write(szItem_RepairEnable_Bit,QVariant(true));//M31.4:检修使能标志
	}
	else
	{
		g->m_bIsDebugModeLogin = false;
		setVSoftkeyDisable(3, g->m_bIsDebugModeLogin);
		setVSoftkeyDisable(4, !g->m_bIsDebugModeLogin);
		setVSoftkeyDisable(5, !g->m_bIsDebugModeLogin);
		setVSoftkeyDisable(6, !g->m_bIsDebugModeLogin);
		setVSoftkeyDisable(7, !g->m_bIsDebugModeLogin || !g->m_bIsRepairOver);
		setVSoftkeyDisable(8, !g->m_bIsDebugModeLogin);
	//	DisplayLabel->setText(g_pIni->m_strRepairPwdError);
	}
}