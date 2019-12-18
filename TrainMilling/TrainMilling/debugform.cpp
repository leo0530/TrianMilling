///////////////////////////////////////////////////////////////////////////////
/*! \file	debugform.cpp
 *  \author
 *  \date
 *  \brief	Implementation file for class DebugForm
 *
 *  This file is part of the HMI Solutionline GUI Framework.
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////
#include "debugform.h"
#include "QDateTime.h"
#include "QLibrary.h"
///////////////////////////////////////////////////////////////////////////////
// CREATORS
///////////////////////////////////////////////////////////////////////////////
DebugForm::DebugForm(QWidget* pParent, const QString& rszName)
	: SlGfwDialogForm(pParent, rszName) 
{
	setupUi(this);

	// initialize status bar
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

	// signal/slot connection for QTimer
	QObject::connect( &m_tmrToggle,SIGNAL(timeout()),this,SLOT(timeoutSlot()) );

	m_bDebugLogin = false;
	m_bStartRemoteControl = false;
	SwitchGui(true);
	m_strIP = "www.enen6.com";

}// <-- DebugForm::DebugForm ()


DebugForm::~DebugForm(void)
{
	if(m_tmrToggle.isActive())
		m_tmrToggle.stop();
	CreateScreenEnd( );
} // <-- ::~ ()


void DebugForm::attachedToScreen(const QString& rszScreenName)
{
	if(g->m_bIsLogin==false){
		dialog()->switchToScreen("MainScreen",NULL);
		return;
	}

	if(	m_bDebugLogin == false)
	{
		setSoftkeyDisable(4, m_bDebugLogin);
		setSoftkeyDisable(5, !m_bDebugLogin);
		setSoftkeyDisable(6, !m_bDebugLogin);
		setSoftkeyDisable(7, !m_bDebugLogin);
	}
	else{
		setSoftkeyDisable(4, m_bDebugLogin);
		setSoftkeyDisable(5, m_bStartRemoteControl);
		setSoftkeyDisable(6, !m_bStartRemoteControl);
		setSoftkeyDisable(7, !m_bDebugLogin);
	}
	if(g->m_bIsLogin==true)
		setStatusBarElementText(g_pIni->m_strLogin, 1);
	else
		setStatusBarElementText(g_pIni->m_strNotLogin, 1);

	//Need SetDfault
	if(g->m_bIsSetDefault==true)
	{
		g->m_bIsSetDefault = false;
		g_pIni->ResetAllParameters();
		SaveResetParametersToCNC();
	}

	g_pDebugForm = this;
    // don't forget to call the standard implementation
    SlGfwDialogForm::attachedToScreen(rszScreenName);
}


void DebugForm::detachedFromScreen(const QString& rszScreenName)
{
	g_pDebugForm = 0;
    // don't forget to call the standard implementation
    SlGfwDialogForm::detachedFromScreen(rszScreenName);
}

///////////////////////////////////////////////////////////////////////////////
// public SLOTS - system overrides
///////////////////////////////////////////////////////////////////////////////
void DebugForm::onFunction (const QString& rsFunction,
                                    const QString& rsArgs,
                                    bool& rbHandled)
{
	if ( "Confirm" == rsFunction )
	{
		if(m_bDebugLogin == false){
			if( DebugPwdLineEdit->value().toString() == g_pIni->m_strDebugPsw){
				DebugPwdLineEdit->clear();
				DebugPwdLineEdit->setReadOnly(true);

				m_bDebugLogin = true;
				setSoftkeyDisable(4, m_bDebugLogin);
				setSoftkeyDisable(5, m_bStartRemoteControl);
				setSoftkeyDisable(6, !m_bStartRemoteControl);
				setSoftkeyDisable(7, !m_bDebugLogin);
				setStatusBarElementText("", 0);
			}
			else
				setStatusBarElementText(g_pIni->m_strPwdError, 0);
		}
		rbHandled = true;
	}
	if ( "StartRemoteControl" == rsFunction )
	{
		SwitchGui(false);
		m_bStartRemoteControl = true;
		setSoftkeyDisable(5, m_bStartRemoteControl);
		setSoftkeyDisable(6, !m_bStartRemoteControl);
		DisplayLabel->setText(g_pIni->m_strWaitForRemote);
		CreateScreenIni( );
		rbHandled = true;
	}
	if ( "StopRemoteControl" == rsFunction )
	{
		CreateScreenEnd( );
		DisplayLabel->setText("");
		SwitchGui(true);
		m_bStartRemoteControl = false;
		setSoftkeyDisable(5, m_bStartRemoteControl);
		setSoftkeyDisable(6, !m_bStartRemoteControl);
		rbHandled = true;
	}
	if ( "SystemReset" == rsFunction )
	{
		// set that the event was handled by this function
		/*
		g_pIni->ResetAllParameters();
		SaveResetParametersToCNC();
		*/
		g->m_nConfirmType = CONFIRM_SETDEFAULT;
		dialog()->switchToScreen("ConfirmScreen",rsArgs);

		rbHandled = true;
	}
	// need to call the base class
	if ( false == rbHandled )
		SlGfwDialogForm::onFunction(rsFunction, rsArgs, rbHandled);
} // <-- DebugForm::onFunction ()


void DebugForm::CreateScreenIni()
{
	m_strID = "";
	HWND hwnd = GetDesktopWindow();
	m_hWndVideo = NNSCreateWindow( hwnd );
	if(m_hWndVideo){
		HWND hCtrlWnd = (HWND)NNSInitVideoDevice( hwnd,1 );
	}
	else{

	}
	NNSSetDevice(16);		//High Quality(16 Bit)
	NNSSetDevice(1);		//control totally

	if(m_hWndVideo){
		//Start Timer
		m_tmrToggle.setSingleShot(false);
		m_tmrToggle.setInterval(1200);
		m_tmrToggle.start();

		NNSLogin(m_strIP.toLocal8Bit().constData(),"ENEN6-VCHAT-DEMO2.0");
		m_strStatus = QString::fromLocal8Bit(NNSGetStatus(NNTYPE_CURRENT));
	}
}

void DebugForm::CreateScreenEnd( )
{
	NNSDestory( );
	m_hWndVideo = NULL;
	if( m_tmrToggle.isActive( ) )
		m_tmrToggle.stop( );
}

void DebugForm::setSoftkeyDisable(int nSoftkey, bool bDisabled)
{
	// get pointer to screen
	SlGfwScreen* pScreen = dialog()->screenRef("DebugScreen");

	if ( 0 != pScreen )
	{
		// get pointer to softkey
		SlGfwSoftKey* pSoftkey = pScreen->menuSoftkey("vr", nSoftkey);
		
		// enable/disable softkey
		if ( 0 != pSoftkey )
			pSoftkey->setDisabled(bDisabled);
	}
}


void DebugForm::timeoutSlot( )
{
	QString str = QString::fromLocal8Bit(NNSGetStatus(NNTYPE_CURRENT));
	if(str!=m_strStatus)
	{
		if(m_strID.isEmpty())						//to get ID
		{
			m_strID = QString::fromLocal8Bit(NNSGetStatus(NNTYPE_ID));
			if(m_strID.isEmpty())					//Login Failed!
			{
				DisplayLabel->setText(g_pIni->m_strLoginFailed);
			}
			else									//Login Success!
			{
				DisplayLabel->setText(g_pIni->m_strLoginSuccess);
				int pos=m_strID.indexOf('@');
				if(pos != -1)
				{
					//This is the m_strID
					DisplayLabel->setText( g_pIni->m_strLoginPreID + m_strID );
					bool sMailmark = sendMail("beijing subway",m_strID.toLocal8Bit().constData());

				}
			}
		}
		else
		{
			if( str == "连接成功！" )				//Connect Sucess!
			{
				DisplayLabel->setText(g_pIni->m_strConnectSuccess);
				if(NNSIsFromServer())
				{
					//txtOutput << "Connect Sucess : converse" << endl;
				}
				else
				{
					//txtOutput << "Connect Sucess : direct" << endl;
				}
				m_strStatus=str;
				return;
			}
			else if( str == "停止!" )				//Stop		
			{
				DisplayLabel->setText(g_pIni->m_strStop);
			}
			else if( str == "不在线" )				//disconnect from serve!
			{
				DisplayLabel->setText(g_pIni->m_strOffLine);
			}
			else if(str.indexOf("连接失败") != -1)	//connect failed!
			{
				DisplayLabel->setText(g_pIni->m_strConnectFailed);
			}
		}
		m_strStatus=str;
	}
}

void DebugForm::SaveResetParametersToCNC()
{
#ifdef PARA_TO_NCU

	if( g_pIni == 0  )
		return;
	QVector<SlCapWriteSpecType>	vecWriteSpec;
	//--------------------- Working Parameters(lack high speed or low speed)-----------------------//
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_LH_CuttingDepth, QVariant(g->m_LH_CutDepth)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_LV_CuttingDepth, QVariant(g->m_LV_CutDepth)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_RH_CuttingDepth, QVariant(g->m_RH_CutDepth)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_RV_CuttingDepth, QVariant(g->m_RV_CutDepth)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_H_DeviceIniPos_ch1, QVariant(g->m_H_DeviceIniPos)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_H_DeviceIniPos_ch2, QVariant(g->m_H_DeviceIniPos)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_V_DeviceIniPos_ch1, QVariant(g->m_V_DeviceIniPos)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_V_DeviceIniPos_ch2, QVariant(g->m_V_DeviceIniPos)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_H_WorkIniPos_ch1, QVariant(g->m_H_WorkIniPos)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_H_WorkIniPos_ch2, QVariant(g->m_H_WorkIniPos)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_V_WorkIniPos_ch1, QVariant(g->m_V_WorkIniPos)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_V_WorkIniPos_ch2, QVariant(g->m_V_WorkIniPos)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_TrainSpeed_ch1, QVariant(g->m_DstTrainSpeed)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_TrainSpeed_ch2, QVariant(g->m_DstTrainSpeed)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_SlopeLength_ch1, QVariant(g->m_SlopeLength)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_SlopeLength_ch2, QVariant(g->m_SlopeLength)) );

	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_LH_CuttingDepth, QVariant(g->m_LH_CutDepth)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_LV_CuttingDepth, QVariant(g->m_LV_CutDepth)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_RH_CuttingDepth, QVariant(g->m_RH_CutDepth)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_RV_CuttingDepth, QVariant(g->m_RV_CutDepth)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_H_DeviceIniPos, QVariant(g->m_H_DeviceIniPos)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_V_DeviceIniPos, QVariant(g->m_V_DeviceIniPos)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_H_WorkIniPos, QVariant(g->m_H_WorkIniPos)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_V_WorkIniPos, QVariant(g->m_V_WorkIniPos)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_TrainSpeed, QVariant(g->m_DstTrainSpeed)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_SlopeLength, QVariant(g->m_SlopeLength)) );

	//--------------------- Working Parameters(lack Cutter Diameters)-----------------------//
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_LH_RailOffset,QVariant(g->m_LH_RailOffset) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_LV_RailOffset,QVariant(g->m_LV_RailOffset) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_RH_RailOffset,QVariant(g->m_RH_RailOffset) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_RV_RailOffset,QVariant(g->m_RV_RailOffset) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_AxisAngularLowerSpeed_ch1,QVariant(g->m_LowAxisAngularSpeed) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_AxisAngularLowerSpeed_ch2,QVariant(g->m_LowAxisAngularSpeed) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_AxisAngularHighSpeed_ch1,QVariant(g->m_HighAxisAngularSpeed) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_AxisAngularHighSpeed_ch2,QVariant(g->m_HighAxisAngularSpeed) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_H_RapidMoveSpeed_ch1,QVariant(g->m_H_RapidSpeed) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_H_RapidMoveSpeed_ch2,QVariant(g->m_H_RapidSpeed) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_V_RapidMoveSpeed_ch1,QVariant(g->m_V_RapidSpeed) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_V_RapidMoveSpeed_ch2,QVariant(g->m_V_RapidSpeed) ) );

	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_LH_RailOffset,QVariant(g->m_LH_RailOffset) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_LV_RailOffset,QVariant(g->m_LV_RailOffset) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_RH_RailOffset,QVariant(g->m_RH_RailOffset) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_RV_RailOffset,QVariant(g->m_RV_RailOffset) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_AxisAngularLowerSpeed,QVariant(g->m_LowAxisAngularSpeed) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_AxisAngularHighSpeed,QVariant(g->m_HighAxisAngularSpeed) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_L_SMWDiameter,QVariant(g->m_L_SMWDiameter) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_R_SMWDiameter,QVariant(g->m_R_SMWDiameter) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_LiftCutterPower,QVariant(g->m_LiftCutterPower) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_LiftCutterTime,QVariant(g->m_LiftCutterTime) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_EndCuttingPower,QVariant(g->m_EndCuttingPower) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_EndCuttingTime,QVariant(g->m_EndCuttingTime) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_H_RapidMoveSpeed,QVariant(g->m_H_RapidSpeed) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_V_RapidMoveSpeed,QVariant(g->m_V_RapidSpeed) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_OffsetSlopeLength,QVariant(g->m_OffsetSlopeLength) ) );

	//-----------------------CPOffset Parameters(8 parameters)---------------------//
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_LH_CPOffset1,QVariant(g->m_LH_CPOffset1) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_LV_CPOffset1,QVariant(g->m_LV_CPOffset1) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_RH_CPOffset1,QVariant(g->m_RH_CPOffset1) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_RV_CPOffset1,QVariant(g->m_RV_CPOffset1) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_LH_CPOffset2,QVariant(g->m_LH_CPOffset2) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_LV_CPOffset2,QVariant(g->m_LV_CPOffset2) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_RH_CPOffset2,QVariant(g->m_RH_CPOffset2) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_RV_CPOffset2,QVariant(g->m_RV_CPOffset2) ) );

	// initialize result specification
	QVector<SlCapWriteResultType> vecWriteResult;

	// write data
	SlCapErrorEnum eError = m_capServer.multiWrite(vecWriteSpec, &vecWriteResult);
#endif
}

void DebugForm::handleRetVal(SlCapErrorEnum eError)
{
	// evaluate return value
	if( SL_CAP_OK != eError )
	{
		// write error in status bar
		QString szHexErrorNr = QString("%1").arg(eError,0,16).right(8);
		setStatusBarElementText(ACCESS_ERROR.arg(szHexErrorNr), 0); 
		g_pErr->m_nErrorCode |= g_pErr->m_nCNCConnectionError;

		//Inner communication Error
		g->m_bPcuCommState = false;
		g_pErr->createPCUCOMAlarm();
	}
}

void DebugForm::SwitchGui(bool bFlag)
{
	if(bFlag){
		DebugPwdLineEdit->show();
		HintLabel->show();
		DisplayLabel->hide();
	}
	else{
		DebugPwdLineEdit->hide();
		HintLabel->hide();
		DisplayLabel->show();
	}
}

bool DebugForm::sendMail(char* name, LPCSTR id)
{
	ostringstream ostr;
	ostr<<name<<":"<<id;
	string sendstr = ostr.str();
	int len = sendstr.length();
	char* context = (char *)malloc((len+1)*sizeof(char));
	memset(context,0,sizeof(char)*(len+1));
	sendstr.copy(context,len,0);

	CSendMail mail;
	sMailInfo info;
	info.mail_server_name="smtp.sina.com";
	info.mailbox_receiver = "13717791138@163.com";
	info.mailbox_sender = "hqyue@sina.com";
	info.mailbox_user_name = "hqyue";
	info.mailbox_user_pwd = "sina98184225";
	info.mailbox_sender_show_name = name;
	info.mail_title = "远程连接";
	info.mail_body = context;
	//mail.AddFilePath("c:\\Download History.log");
	bool mailed = mail.BeginSendMail(info);
	delete context;
	return mailed;
}
