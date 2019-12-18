///////////////////////////////////////////////////////////////////////////////
/*! \file	usermanagerform.cpp
 *  \author
 *  \date
 *  \brief	Implementation file for class UserManagerForm
 *
 *  This file is part of the HMI Solutionline GUI Framework.
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////
#include "usermanagerform.h"
#include "QDateTime.h"


///////////////////////////////////////////////////////////////////////////////
// CREATORS
///////////////////////////////////////////////////////////////////////////////

UserManagerForm::UserManagerForm(QWidget* pParent, const QString& rszName)
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
	setStatusBarElementAlignment(Qt::AlignRight,0);
	setStatusBarVisible(true);

	//Set The UserNameLineEdit UserName,and the name is only readable
	m_UIType = UserPwdUI;
	setPwdUI(UserPwdUI);
	// signal/slot connection for QTimer
	QObject::connect( &m_tmrToggle,SIGNAL(timeout()),this,SLOT(TimeOutSlot()) );
}// <-- UserManagerForm::UserManagerForm ()


UserManagerForm::~UserManagerForm(void)
{
	if(m_tmrToggle.isActive())
		m_tmrToggle.stop();
} // <-- ::~ ()

///////////////////////////////////////////////////////////////////////////////
// public SLOTS - system overrides
///////////////////////////////////////////////////////////////////////////////
void UserManagerForm::onFunction (const QString& rsFunction,
                                    const QString& rsArgs,
                                    bool& rbHandled)
{
      //call base class
 	if ( "UserPwd" == rsFunction )
	{
		m_UIType = UserPwdUI;
		setPwdUI(UserPwdUI);
		setSoftkeyDisable(7, false);
		setLineEditReadOnly(false);
		rbHandled = true;
	}
 	if ( "RepairPwd" == rsFunction )
	{
		m_UIType = RepairPwdUI;
		setPwdUI(RepairPwdUI);
		setSoftkeyDisable(7, false);
		setLineEditReadOnly(false);
		rbHandled = true;
	}
 	if ( "DebugPwd" == rsFunction )
	{
		m_UIType = DebugPwdUI;
		setPwdUI(DebugPwdUI);
		setSoftkeyDisable(7, false);
		setLineEditReadOnly(false);
		rbHandled = true;
	}
 	if ( "SavePassword" == rsFunction )
	{
		switch(m_UIType){
			case UserPwdUI:
				SaveUserPassword( );
				break;
			case RepairPwdUI:
				SaveRepairPassword( );
				break;
			case DebugPwdUI:
				SaveDebugPassword( );
				break;
			default:
				break;
		}
		rbHandled = true;
	}

	// need to call the base class
	if ( false == rbHandled )
		SlGfwDialogForm::onFunction(rsFunction, rsArgs, rbHandled);

} // <-- UserManagerForm::onFunction ()

void UserManagerForm::SaveUserPassword( )
{
	QString OldPsw  = OldPasswordLineEdit->value().toString();
	QString NewPsw1 = NewPasswordLineEdit->value().toString();
	QString NewPsw2 = NewPasswordAgainLineEdit->value().toString();

	OldPasswordLineEdit->clear( );
	NewPasswordLineEdit->clear( );
	NewPasswordAgainLineEdit->clear( );

	if(OldPsw != g_pIni->m_strPassword){
		InformationLabel->setText(g_pIni->m_strPwdError);
		//Start Timer
		m_tmrToggle.setSingleShot(true);
		m_tmrToggle.setInterval(4000);
		m_tmrToggle.start();
		return;
	}
	if(NewPsw1 == NewPsw2){
		g_pIni->SaveUserPassword( NewPsw1);
		InformationLabel->setText(g_pIni->m_strModifySuccess);
		//Start Timer
		m_tmrToggle.setSingleShot(true);
		m_tmrToggle.setInterval(4000);
		m_tmrToggle.start();

		setSoftkeyDisable(7, true);
		setLineEditReadOnly(true);
	}
	else{
		InformationLabel->setText(g_pIni->m_strModifyFailed);
		//Start Timer
		m_tmrToggle.setSingleShot(true);
		m_tmrToggle.setInterval(4000);
		m_tmrToggle.start();
	}
}

void UserManagerForm::SaveRepairPassword( )
{
	QString OldPsw  = OldRepairPwdLineEdit->value().toString();
	QString NewPsw1 = NewRepairPwdLineEdit->value().toString();
	QString NewPsw2 = NewRepairPwdAgainLineEdit->value().toString();

	OldRepairPwdLineEdit->clear( );
	NewRepairPwdLineEdit->clear( );
	NewRepairPwdAgainLineEdit->clear( );

	if(OldPsw != g_pIni->m_strRepairPwd){
		InformationLabel->setText(g_pIni->m_strPwdError);
		//Start Timer
		m_tmrToggle.setSingleShot(true);
		m_tmrToggle.setInterval(4000);
		m_tmrToggle.start();
		return;
	}
	if(NewPsw1 == NewPsw2){
		g_pIni->SaveRepairPassword( NewPsw1);
		InformationLabel->setText(g_pIni->m_strModifySuccess);
		//Start Timer
		m_tmrToggle.setSingleShot(true);
		m_tmrToggle.setInterval(4000);
		m_tmrToggle.start();

		setSoftkeyDisable(7, true);
		setLineEditReadOnly(true);
	}
	else{
		InformationLabel->setText(g_pIni->m_strModifyFailed);
		//Start Timer
		m_tmrToggle.setSingleShot(true);
		m_tmrToggle.setInterval(4000);
		m_tmrToggle.start();
	}
}

void UserManagerForm::SaveDebugPassword( )
{
	QString OldPsw  = OldDebugPwdLineEdit->value().toString();
	QString NewPsw1 = NewDebugPwdLineEdit->value().toString();
	QString NewPsw2 = NewDebugPwdAgainLineEdit->value().toString();

	OldDebugPwdLineEdit->clear( );
	NewDebugPwdLineEdit->clear( );
	NewDebugPwdAgainLineEdit->clear( );

	if(OldPsw != g_pIni->m_strDebugPsw){
		InformationLabel->setText(g_pIni->m_strPwdError);
		//Start Timer
		m_tmrToggle.setSingleShot(true);
		m_tmrToggle.setInterval(4000);
		m_tmrToggle.start();
		return;
	}
	if(NewPsw1 == NewPsw2){
		g_pIni->SaveDebugPassword( NewPsw1);
		InformationLabel->setText(g_pIni->m_strModifySuccess);
		//Start Timer
		m_tmrToggle.setSingleShot(true);
		m_tmrToggle.setInterval(4000);
		m_tmrToggle.start();

		setSoftkeyDisable(7, true);
		setLineEditReadOnly(true);
	}
	else{
		InformationLabel->setText(g_pIni->m_strModifyFailed);
		//Start Timer
		m_tmrToggle.setSingleShot(true);
		m_tmrToggle.setInterval(4000);
		m_tmrToggle.start();
	}
}

///////////////////////////////////////////////////////////////////////////////
// private methods
///////////////////////////////////////////////////////////////////////////////
void UserManagerForm::attachedToScreen(const QString& rszScreenName)
{
	setLineEditReadOnly(false);
	InformationLabel->setText("");
	if(g->m_bIsLogin==true)
		setStatusBarElementText(g_pIni->m_strLogin, 0);
	else
		setStatusBarElementText(g_pIni->m_strNotLogin, 0);

	g_pUserManagerForm = this;
    // don't forget to call the standard implementation
    SlGfwDialogForm::attachedToScreen(rszScreenName);
}


void UserManagerForm::detachedFromScreen(const QString& rszScreenName)
{
	if(m_tmrToggle.isActive())
		m_tmrToggle.stop();

	g_pUserManagerForm = 0;
    // don't forget to call the standard implementation
    SlGfwDialogForm::detachedFromScreen(rszScreenName);
}

void UserManagerForm::TimeOutSlot( )
{
	InformationLabel->setText("");
	/*
	QDateTime current_date_time =QDateTime::currentDateTime();
	QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss ddd");
	setCaptionBarElementText(current_date,1);
	*/
}


void UserManagerForm::setSoftkeyDisable(int nSoftkey, bool bDisabled)
{
	// get pointer to screen
	SlGfwScreen* pScreen = dialog()->screenRef("UserManagerSreen");

	if ( 0 != pScreen )
	{
		// get pointer to softkey
		SlGfwSoftKey* pSoftkey = pScreen->menuSoftkey("UserManagerVr", nSoftkey);
		
		// enable/disable softkey
		if ( 0 != pSoftkey )
			pSoftkey->setDisabled(bDisabled);
	}
}

void UserManagerForm::setLineEditReadOnly(bool bReadOnly)
{
	switch(m_UIType){
		case UserPwdUI:
			this->OldPasswordLineEdit->setReadOnly(bReadOnly);
			this->NewPasswordLineEdit->setReadOnly(bReadOnly);
			this->NewPasswordAgainLineEdit->setReadOnly(bReadOnly);
			break;
		case RepairPwdUI:
			this->OldRepairPwdLineEdit->setReadOnly(bReadOnly);
			this->NewRepairPwdLineEdit->setReadOnly(bReadOnly);
			this->NewRepairPwdAgainLineEdit->setReadOnly(bReadOnly);
			break;
		case DebugPwdUI:
			this->OldDebugPwdLineEdit->setReadOnly(bReadOnly);
			this->NewDebugPwdLineEdit->setReadOnly(bReadOnly);
			this->NewDebugPwdAgainLineEdit->setReadOnly(bReadOnly);
			break;
		default:
			break;
	}
}

void UserManagerForm::setPwdUI(int nType)
{
	switch(nType){
		case UserPwdUI:
			UserPwdGroupBox->setVisible(true);
			RepairPwdGroupBox->setVisible(false);
			DebugPwdGroupBox->setVisible(false);
			setUserName(UserPwdUI);
			break;
		case RepairPwdUI:
			UserPwdGroupBox->setVisible(false);
			RepairPwdGroupBox->setVisible(true);
			DebugPwdGroupBox->setVisible(false);
			setUserName(RepairPwdUI);
			break;
		case DebugPwdUI:
			UserPwdGroupBox->setVisible(false);
			RepairPwdGroupBox->setVisible(false);
			DebugPwdGroupBox->setVisible(true);
			setUserName(DebugPwdUI);
			break;
		default:
			break;
	}
}

void UserManagerForm::setUserName(int nType)
{
	switch(nType){
		case UserPwdUI:
			UserNameLineEdit->setValue(g_pIni->m_strUserName);
			break;
		case RepairPwdUI:
			RepairNameLineEdit->setValue("Repair");
			break;
		case DebugPwdUI:
			DebugNameLineEdit->setValue("Debug");
			break;
		default:
			break;
	}
}
