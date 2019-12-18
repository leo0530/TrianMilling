///////////////////////////////////////////////////////////////////////////////
/*! \file	onfirmform.cpp
 *  \author
 *  \date
 *  \brief	Implementation file for class ConfirmForm
 *
 *  This file is part of the HMI Solutionline GUI Framework.
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////
#include "onfirmform.h"


///////////////////////////////////////////////////////////////////////////////
// CREATORS
///////////////////////////////////////////////////////////////////////////////

ConfirmForm::ConfirmForm(QWidget* pParent, const QString& rszName)
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

}// <-- ConfirmForm::ConfirmForm ()


ConfirmForm::~ConfirmForm(void)
{

} // <-- ::~ ()

///////////////////////////////////////////////////////////////////////////////
// public SLOTS - system overrides
///////////////////////////////////////////////////////////////////////////////
void ConfirmForm::onFunction (const QString& rsFunction,
                                    const QString& rsArgs,
                                    bool& rbHandled)
{
  	// check null pointer
	if ( "Yes" == rsFunction )
	{
		YesFunction( rsArgs );
		rbHandled = true;
	}
	else if ( "No" == rsFunction )
	{
		NoFunction( rsArgs );
		rbHandled = true;
	}
	// need to call the base class
	if ( false == rbHandled )
		SlGfwDialogForm::onFunction(rsFunction, rsArgs, rbHandled);
} // <-- ConfirmForm::onFunction ()


void ConfirmForm::YesFunction( const QString& rsArgs )
{
	SlQCap nWriteServer;
	SlCapErrorEnum nError;
	if(g->m_nConfirmType == CONFIRM_LOGOFF)
	{
		g->m_bIsLogin = false;
		g->m_strNowUserName = "";
		nError = nWriteServer.write(szItem_UserLogin_Bit,QVariant(false));
		dialog()->switchToScreen("MainScreen",rsArgs);
	}
	else if(g->m_nConfirmType == CONFIRM_SETDEFAULT)
	{
		g->m_bIsSetDefault = true;
		dialog()->switchToScreen("DebugScreen",rsArgs);
	}
	else if(g->m_nConfirmType == COMFIRM_REPAIRLOGOFF)
	{
		g->m_bIsRepairLogin = false;
		nError = nWriteServer.write(szItem_RepairEnable_Bit,QVariant(false));
		dialog()->switchToScreen("DeviceRepairSreen",rsArgs);
	}
}

void ConfirmForm::NoFunction( const QString& rsArgs )
{
	if(g->m_nConfirmType == CONFIRM_LOGOFF)
	{
		dialog()->switchToScreen("MainScreen",rsArgs);
	}
	else if(g->m_nConfirmType == CONFIRM_SETDEFAULT)
	{
		dialog()->switchToScreen("DebugScreen",rsArgs);
	}
	else if(g->m_nConfirmType == COMFIRM_REPAIRLOGOFF)
	{
		dialog()->switchToScreen("DeviceRepairSreen",rsArgs);
	}

}

///////////////////////////////////////////////////////////////////////////////
// private methods
///////////////////////////////////////////////////////////////////////////////
void ConfirmForm::attachedToScreen(const QString& rszScreenName)
{
	if(g->m_bIsLogin==true)
		setStatusBarElementText(g_pIni->m_strLogin, 1);
	else
		setStatusBarElementText(g_pIni->m_strNotLogin, 1);

	if(g->m_nConfirmType == CONFIRM_LOGOFF)
	{
		ShowTextLabel->setText(g_pIni->m_strLogoffName);
		//ShowTextLabel->setText(g_pIni->m_strLogin);
	}
	else if(g->m_nConfirmType == CONFIRM_SETDEFAULT)
	{
		ShowTextLabel->setText(g_pIni->m_strSetDefault);
		//ShowTextLabel->setText(g_pIni->m_strLogin);
	}
	else if(g->m_nConfirmType == COMFIRM_REPAIRLOGOFF)
	{
		ShowTextLabel->setText(g_pIni->m_strRepairLogoff);
	}

	g_pConfirmForm = this;
    // don't forget to call the standard implementation
    SlGfwDialogForm::attachedToScreen(rszScreenName);
}

void ConfirmForm::detachedFromScreen(const QString& rszScreenName)
{
	g_pConfirmForm = 0;
    // don't forget to call the standard implementation
    SlGfwDialogForm::detachedFromScreen(rszScreenName);
}