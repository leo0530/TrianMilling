///////////////////////////////////////////////////////////////////////////////
/*! \file	systemform.cpp
 *  \author
 *  \date
 *  \brief	Implementation file for class SystemForm
 *
 *  This file is part of the HMI Solutionline GUI Framework.
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////
#include "systemform.h"
#include "QDateTime.h"
#include "GlobalVar.h"

///////////////////////////////////////////////////////////////////////////////
// CREATORS
///////////////////////////////////////////////////////////////////////////////

SystemForm::SystemForm(QWidget* pParent, const QString& rszName)
	: SlGfwDialogForm(pParent, rszName)
{
	setupUi(this);
	// initialize timer for toggle R-Parameter
	m_tmrToggle.setSingleShot(false);
	m_tmrToggle.setInterval(1000);

	// signal/slot connection for QTimer
	QObject::connect( &m_tmrToggle,SIGNAL(timeout()),this,SLOT(TimeoutSlot()) );
	// start timer
	//m_tmrToggle.start();

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

}// <-- SystemForm::SystemForm ()


SystemForm::~SystemForm(void)
{
	if(m_tmrToggle.isActive())
		m_tmrToggle.stop();


} // <-- ::~ ()


// will be called by the framework, if the form is attached to screen rszScreenName
void SystemForm::attachedToScreen(const QString& rszScreenName)
{
	if(g->m_bIsLogin==false){
		dialog()->switchToScreen("MainScreen",NULL);
		return;
	}

	if(g->m_bIsLogin==true)
		setStatusBarElementText(g_pIni->m_strLogin, 1);
	else
		setStatusBarElementText(g_pIni->m_strNotLogin, 1);
	setStatusBarElementText("",0);

	if( g->IsWorkingState() )
	{
		setSoftkeyDisable(7, true);
		setLineEditReadOnly(true);
	}
	else
	{
		setSoftkeyDisable(7, g->m_bIsRepairLogin);
		setLineEditReadOnly(g->m_bIsRepairLogin);
	}

	DisplaySystemParameters( );
	g_pSystemForm = this;
}

///////////////////////////////////////////////////////////////////////////////
// will be called by the framework, if the form is detached from screen rszScreenName
void SystemForm::detachedFromScreen(const QString& rszScreenName)
{
	g_pSystemForm = 0;
}

///////////////////////////////////////////////////////////////////////////////
// public SLOTS - system overrides
///////////////////////////////////////////////////////////////////////////////
void SystemForm::onFunction (const QString& rsFunction,
                                    const QString& rsArgs,
                                    bool& rbHandled)
{
 	// check null pointer
	if ( "SaveParameter" == rsFunction )
	{
		if(checkValid())
		{
			WriteSystemParametersToIni( );
			//WriteSystemParametersToCNC();
			setSoftkeyDisable(7, true);
			setLineEditReadOnly(true);
			setStatusBarElementText(readText("ok_Save","systemPara"),0);
		}
		rbHandled = true;
	}
	// need to call the base class
	if ( false == rbHandled )
		SlGfwDialogForm::onFunction(rsFunction, rsArgs, rbHandled);
} // <-- SystemForm::onFunction ()

void SystemForm::DisplaySystemParameters( )
{
	this->LH_RailOffsetLineEdit->setValue(g->m_LH_RailOffset);//轨距修正 左
	this->LV_RailOffsetLineEdit->setValue(g->m_LV_RailOffset);//刀偏 左
	this->RH_RailOffsetLineEdit->setValue(g->m_RH_RailOffset);//轨距修正 右
	this->RV_RailOffsetLineEdit->setValue(g->m_RV_RailOffset);//刀偏 右
	this->LH_CalibPosLineEdit1->setValue(g->double2double(g->m_LH_SensorCalibPos1));//Y1标定(1)
	this->LV_CalibPosLineEdit1->setValue(g->double2double(g->m_LV_SensorCalibPos1));//Z1标定(1)
	this->RH_CalibPosLineEdit1->setValue(g->double2double(g->m_RH_SensorCalibPos1));//Y2标定(1)
	this->RV_CalibPosLineEdit1->setValue(g->double2double(g->m_RV_SensorCalibPos1));//Z2标定(1)
	this->LH_CalibPosLineEdit2->setValue(g->double2double(g->m_LH_SensorCalibPos2));//Y1标定(2)
	this->LV_CalibPosLineEdit2->setValue(g->double2double(g->m_LV_SensorCalibPos2));//Z1标定(2)
	this->RH_CalibPosLineEdit2->setValue(g->double2double(g->m_RH_SensorCalibPos2));//Y2标定(2)
	this->RV_CalibPosLineEdit2->setValue(g->double2double(g->m_RV_SensorCalibPos2));//Z2标定(2)
	this->AxisAngularLowerSpeedLineEdit->setValue(g->m_LowAxisAngularSpeed);//主轴低速模式
	this->AxisAngularHighSpeedLineEdit->setValue(g->m_HighAxisAngularSpeed);//主轴高速模式
	this->L_SMWDiameterLineEdit->setValue(g->m_L_SMWDiameter);//左测速轮直径
	this->R_SMWDiameterLineEdit->setValue(g->m_R_SMWDiameter);//右测速轮直径
	this->LiftCutterPowerLineEdit->setValue(g->m_LiftCutterPower);//峰值功率设置 功率
	this->LiftCutterTimeLineEdit->setValue(g->m_LiftCutterTime);  //峰值功率设置 时间
	this->EndCuttingPowerLineEdit->setValue(g->m_EndCuttingPower);//最大功率设置 功率
	this->EndCuttingTimeLineEdit->setValue(g->m_EndCuttingTime);  //最大功率设置 时间
	this->H_RapidMoveSpeedLineEdit->setValue(g->m_H_RapidSpeed);//横向快进速度
	this->V_RapidMoveSpeedLineEdit->setValue(g->m_V_RapidSpeed);//垂向快进速度
	this->OffsetSlopeLengthLineEdit->setValue(g->m_OffsetSlopeLength);//偏移顺坡长度

	this->LV_MotorCalibPosLineEdit->setValue(g->m_LV_MotorCalibPos);//垂向电机 左
	this->RV_MotorCalibPosLineEdit->setValue(g->m_RV_MotorCalibPos);//垂向电机 右

}

void SystemForm::WriteSystemParametersToIni( )
{
	g->m_LH_RailOffset = this->LH_RailOffsetLineEdit->value().toDouble();//左铣削单元轨距修正
	g->m_LV_RailOffset = this->LV_RailOffsetLineEdit->value().toDouble();//左铣削单元刀偏
	g->m_RH_RailOffset = this->RH_RailOffsetLineEdit->value().toDouble();//右铣削单元轨距修正
	g->m_RV_RailOffset = this->RV_RailOffsetLineEdit->value().toDouble();//右铣削单元刀偏
	g->m_LH_SensorCalibPos1 = this->LH_CalibPosLineEdit1->value().toDouble();//Y1标定(1)
	g->m_LV_SensorCalibPos1 = this->LV_CalibPosLineEdit1->value().toDouble();//Z1标定(1)
	g->m_RH_SensorCalibPos1 = this->RH_CalibPosLineEdit1->value().toDouble();//Y2标定(1)
	g->m_RV_SensorCalibPos1 = this->RV_CalibPosLineEdit1->value().toDouble();//Z2标定(1)
	g->m_LH_SensorCalibPos2 = this->LH_CalibPosLineEdit2->value().toDouble();//Y1标定(2)
	g->m_LV_SensorCalibPos2 = this->LV_CalibPosLineEdit2->value().toDouble();//Z1标定(2)
	g->m_RH_SensorCalibPos2 = this->RH_CalibPosLineEdit2->value().toDouble();//Y2标定(2)
	g->m_RV_SensorCalibPos2 = this->RV_CalibPosLineEdit2->value().toDouble();//Z2标定(2)
	g->m_LowAxisAngularSpeed = this->AxisAngularLowerSpeedLineEdit->value().toDouble();//主轴低速模式
	g->m_HighAxisAngularSpeed = this->AxisAngularHighSpeedLineEdit->value().toDouble();//主轴高速模式
	g->m_L_SMWDiameter = this->L_SMWDiameterLineEdit->value().toDouble();//左测速轮直径
	g->m_R_SMWDiameter = this->R_SMWDiameterLineEdit->value().toDouble();//右测速轮直径
	g->m_LiftCutterPower = this->LiftCutterPowerLineEdit->value().toDouble();//峰值功率设置 功率
	g->m_LiftCutterTime = this->LiftCutterTimeLineEdit->value().toDouble();  //峰值功率设置 时间
	g->m_EndCuttingPower = this->EndCuttingPowerLineEdit->value().toDouble();//最大设置功率 功率 ligy 20190910 add
	g->m_EndCuttingTime = this->EndCuttingTimeLineEdit->value().toDouble();  //最大设置功率 时间 ligy 20190910 add
	g->m_H_RapidSpeed = this->H_RapidMoveSpeedLineEdit->value().toDouble();  //横向快进速度
	g->m_V_RapidSpeed = this->V_RapidMoveSpeedLineEdit->value().toDouble();  //垂向快进速度
	g->m_OffsetSlopeLength = this->OffsetSlopeLengthLineEdit->value().toDouble();//偏移顺坡长度

	g->m_LV_MotorCalibPos = this->LV_MotorCalibPosLineEdit->value().toDouble();  //左铣削单元垂向电机
	g->m_RV_MotorCalibPos = this->RV_MotorCalibPosLineEdit->value().toDouble();  //右铣削单元垂向电机

	g_pIni->SaveSystemParameters();
}
///////////////////////////////////////////////////////////////////////////////
// private methods
///////////////////////////////////////////////////////////////////////////////
void SystemForm::TimeoutSlot()
{
	/*
	// read toggle-item
	QDateTime current_date_time =QDateTime::currentDateTime();
	QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss ddd");
	setCaptionBarElementText(current_date,1);
	*/
}
void SystemForm::WriteSystemParametersToCNC( )
{
#ifdef PARA_TO_NCU
	// fill multi read specification
	QVector<SlCapWriteSpecType>	vecWriteSpec;
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_LH_RailOffset,QVariant(g->m_LH_RailOffset) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_LV_RailOffset,QVariant(g->m_LV_RailOffset) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_RH_RailOffset,QVariant(g->m_RH_RailOffset) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_RV_RailOffset,QVariant(g->m_RV_RailOffset) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_LH_SensorCalibPos1,QVariant(g->m_LH_SensorCalibPos1) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_LV_SensorCalibPos1,QVariant(g->m_LV_SensorCalibPos1) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_RH_SensorCalibPos1,QVariant(g->m_RH_SensorCalibPos1) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_RV_SensorCalibPos1,QVariant(g->m_RV_SensorCalibPos1) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_LH_SensorCalibPos2,QVariant(g->m_LH_SensorCalibPos2) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_LV_SensorCalibPos2,QVariant(g->m_LV_SensorCalibPos2) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_RH_SensorCalibPos2,QVariant(g->m_RH_SensorCalibPos2) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_RV_SensorCalibPos2,QVariant(g->m_RV_SensorCalibPos2) ) );
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
	// initialize result specification
	QVector<SlCapWriteResultType> vecWriteResult;

	// write data
	SlCapErrorEnum eError = m_capServer.multiWrite(vecWriteSpec, &vecWriteResult);

	// write success or error to the status bar
	handleRetVal(eError);
#endif
}

void SystemForm::handleRetVal(SlCapErrorEnum eError)
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

void SystemForm::setLineEditReadOnly(bool bReadOnly)
{
	this->LH_RailOffsetLineEdit->setReadOnly(bReadOnly);
	this->LV_RailOffsetLineEdit->setReadOnly(bReadOnly);
	this->RH_RailOffsetLineEdit->setReadOnly(bReadOnly);
	this->RV_RailOffsetLineEdit->setReadOnly(bReadOnly);
	this->LH_CalibPosLineEdit1->setReadOnly(bReadOnly);
	this->LV_CalibPosLineEdit1->setReadOnly(bReadOnly);
	this->RH_CalibPosLineEdit1->setReadOnly(bReadOnly);
	this->RV_CalibPosLineEdit1->setReadOnly(bReadOnly);
	this->LH_CalibPosLineEdit2->setReadOnly(bReadOnly);
	this->LV_CalibPosLineEdit2->setReadOnly(bReadOnly);
	this->RH_CalibPosLineEdit2->setReadOnly(bReadOnly);
	this->RV_CalibPosLineEdit2->setReadOnly(bReadOnly);
	this->AxisAngularLowerSpeedLineEdit->setReadOnly(bReadOnly);
	this->AxisAngularHighSpeedLineEdit->setReadOnly(bReadOnly);
	this->L_SMWDiameterLineEdit->setReadOnly(bReadOnly);
	this->R_SMWDiameterLineEdit->setReadOnly(bReadOnly);
	this->LiftCutterPowerLineEdit->setReadOnly(bReadOnly);
	this->LiftCutterTimeLineEdit->setReadOnly(bReadOnly);
	this->EndCuttingPowerLineEdit->setReadOnly(bReadOnly);
	this->EndCuttingTimeLineEdit->setReadOnly(bReadOnly);
	this->H_RapidMoveSpeedLineEdit->setReadOnly(bReadOnly);
	this->V_RapidMoveSpeedLineEdit->setReadOnly(bReadOnly);
	this->OffsetSlopeLengthLineEdit->setReadOnly(bReadOnly);

	this->LV_MotorCalibPosLineEdit->setReadOnly(bReadOnly);
	this->RV_MotorCalibPosLineEdit->setReadOnly(bReadOnly);
}

void SystemForm::setSoftkeyDisable(int nSoftkey, bool bDisabled)
{
	// get pointer to screen
	SlGfwScreen* pScreen = dialog()->screenRef("SystemScreen");

	if ( 0 != pScreen )
	{
		// get pointer to softkey
		SlGfwSoftKey* pSoftkey = pScreen->menuSoftkey("SystemVr", nSoftkey);
		
		// enable/disable softkey
		if ( 0 != pSoftkey )
			pSoftkey->setDisabled(bDisabled);
	}
}

bool SystemForm::checkValid()
{
	QVariant LH_RailOffset = LH_RailOffsetLineEdit->value();
	if(LH_RailOffset.toDouble()<-5||LH_RailOffset.toDouble()>5)//(-5-5) 
	{
		setStatusBarElementText(readText("err_LH_RailOffset","systemPara"),0);
		this->LH_RailOffsetLineEdit->setValue(0);
		return false;
	}
	QVariant LV_RailOffset = LV_RailOffsetLineEdit->value();
	if(LV_RailOffset.toDouble()<-5||LV_RailOffset.toDouble()>5)//(-5-5) 
	{
		setStatusBarElementText(readText("err_LV_RailOffset","systemPara"),0);
		this->LV_RailOffsetLineEdit->setValue(0);
		return false;
	}

	QVariant H_RapidMoveSpeed = H_RapidMoveSpeedLineEdit->value();//横向快进速度
	if(H_RapidMoveSpeed.toDouble()<500||H_RapidMoveSpeed.toDouble()>2000)//(500-2000)
	{
		setStatusBarElementText(readText("err_H_RapidMoveSpeed","systemPara"),0);
		this->H_RapidMoveSpeedLineEdit->setValue(0);
		return false;
	}
	QVariant V_RapidMoveSpeed = V_RapidMoveSpeedLineEdit->value();//垂向快进速度
	if(V_RapidMoveSpeed.toDouble()<500||V_RapidMoveSpeed.toDouble()>2000)//(500-2000)
	{
		setStatusBarElementText(readText("err_V_RapidMoveSpeed","systemPara"),0);
		this->V_RapidMoveSpeedLineEdit->setValue(0);
		return false;
	}

	QVariant AxisAngularLowerSpeed = AxisAngularLowerSpeedLineEdit->value();//主轴低速
	if(AxisAngularLowerSpeed.toDouble()<0||AxisAngularLowerSpeed.toDouble()>80)//(40-42)
	{
		setStatusBarElementText(readText("err_AxisAngularLowerSpeed","systemPara"),0);
		this->AxisAngularLowerSpeedLineEdit->setValue(0);
		return false;
	}
	QVariant AxisAngularHighSpeed = AxisAngularHighSpeedLineEdit->value();//主轴高速
	if(AxisAngularHighSpeed.toDouble()<80||AxisAngularHighSpeed.toDouble()>150)
	{
		setStatusBarElementText(readText("err_AxisAngularHighSpeed","systemPara"),0);
		this->AxisAngularHighSpeedLineEdit->setValue(0);
		return false;
	}
	QVariant L_SMWDiameter = L_SMWDiameterLineEdit->value();//测速轮直径 
	if(L_SMWDiameter.toDouble()<0||L_SMWDiameter.toDouble()>350)//(130-140)
	{
		setStatusBarElementText(readText("err_L_SMWDiameter","systemPara"),0);
		this->L_SMWDiameterLineEdit->setValue(0);
		return false;
	}
	QVariant R_SMWDiameter = R_SMWDiameterLineEdit->value();//测速轮直径 
	if(R_SMWDiameter.toDouble()<0||R_SMWDiameter.toDouble()>350)//(130-140)
	{
		setStatusBarElementText(readText("err_R_SMWDiameter","systemPara"),0);
		this->R_SMWDiameterLineEdit->setValue(0);
		return false;
	}

	QVariant OffsetSlopeLength = OffsetSlopeLengthLineEdit->value();//偏移顺坡长度
	if(OffsetSlopeLength.toDouble()<100||OffsetSlopeLength.toDouble()>1000)//(100-1000)
	{
		setStatusBarElementText(readText("err_OffsetSlopeLength","systemPara"),0);
		this->OffsetSlopeLengthLineEdit->setValue(0);
		return false;
	}
	QVariant RH_RailOffset = RH_RailOffsetLineEdit->value();
	if(RH_RailOffset.toDouble()<-5||RH_RailOffset.toDouble()>5)
	{
		setStatusBarElementText(readText("err_RH_RailOffset","systemPara"),0);
		this->RH_RailOffsetLineEdit->setValue(0);
		return false;
	}
	QVariant RV_RailOffset = RV_RailOffsetLineEdit->value();
	if(RV_RailOffset.toDouble()<-5||RV_RailOffset.toDouble()>5)
	{
		setStatusBarElementText(readText("err_RV_RailOffset","systemPara"),0);
		this->RV_RailOffsetLineEdit->setValue(0);
		return false;
	}

	QVariant LiftCutterPower = LiftCutterPowerLineEdit->value();
	if(LiftCutterPower.toDouble()<60||LiftCutterPower.toDouble()>110)//(70-80)
	{
		setStatusBarElementText(readText("err_LiftCutterPower","systemPara"),0);
		this->LiftCutterPowerLineEdit->setValue(0);
		return false;
	}
	QVariant LiftCutterTime = LiftCutterTimeLineEdit->value();
	if(LiftCutterTime.toDouble()<100||LiftCutterTime.toDouble()>1000)//(5-10)
	{
		setStatusBarElementText(readText("err_LiftCutterTime","systemPara"),0);
		this->LiftCutterTimeLineEdit->setValue(0);
		return false;
	}
	QVariant EndCuttingPower = EndCuttingPowerLineEdit->value();
	if(EndCuttingPower.toDouble()<60||EndCuttingPower.toDouble()>80)//(80-100)
	{
		setStatusBarElementText(readText("err_EndCuttingPower","systemPara"),0);
		this->EndCuttingPowerLineEdit->setValue(0);
		return false;
	}
	QVariant EndCuttingTime = EndCuttingTimeLineEdit->value();
	if(EndCuttingTime.toDouble()<2000||EndCuttingTime.toDouble()>4000)//(1-3)
	{
		setStatusBarElementText(readText("err_EndCuttingTime","systemPara"),0);
		this->EndCuttingTimeLineEdit->setValue(0);
		return false;
	}
	return true;
	QVariant LH_CalibPos1 = LH_CalibPosLineEdit1->value();
	if(LH_CalibPos1.toDouble()<10||LH_CalibPos1.toDouble()>45)//(1-3)
	{
		setStatusBarElementText(readText("err_LH_CalibPos1","systemPara"),0);
		this->LH_CalibPosLineEdit1->setValue(0);
		return false;
	}
	QVariant LH_CalibPos2 = LH_CalibPosLineEdit2->value();
	if(LH_CalibPos2.toDouble()<10||LH_CalibPos2.toDouble()>45)//(1-3)
	{
		setStatusBarElementText(readText("err_LH_CalibPos2","systemPara"),0);
		this->LH_CalibPosLineEdit2->setValue(0);
		return false;
	}
	return true;
	QVariant LV_CalibPos1 = LV_CalibPosLineEdit1->value();
	if(LV_CalibPos1.toDouble()<10||LV_CalibPos1.toDouble()>45)//(1-3)
	{
		setStatusBarElementText(readText("err_LV_CalibPos1","systemPara"),0);
		this->LV_CalibPosLineEdit1->setValue(0);
		return false;
	}
	QVariant LV_CalibPos2 = LV_CalibPosLineEdit2->value();
	if(LV_CalibPos2.toDouble()<10||LV_CalibPos2.toDouble()>45)//(1-3)
	{
		setStatusBarElementText(readText("err_LV_CalibPos2","systemPara"),0);
		this->LV_CalibPosLineEdit2->setValue(0);
		return false;
	}
	return true;
	QVariant RH_CalibPos1 = RH_CalibPosLineEdit1->value();
	if(RH_CalibPos1.toDouble()<10||RH_CalibPos1.toDouble()>45)//(1-3)
	{
		setStatusBarElementText(readText("err_RH_CalibPos1","systemPara"),0);
		this->RH_CalibPosLineEdit1->setValue(0);
		return false;
	}
	QVariant RH_CalibPos2 = RH_CalibPosLineEdit2->value();
	if(RH_CalibPos2.toDouble()<10||RH_CalibPos2.toDouble()>45)//(1-3)
	{
		setStatusBarElementText(readText("err_RH_CalibPos2","systemPara"),0);
		this->RH_CalibPosLineEdit2->setValue(0);
		return false;
	}
	return true;
	QVariant RV_CalibPos1 = RV_CalibPosLineEdit1->value();
	if(RV_CalibPos1.toDouble()<10||RV_CalibPos1.toDouble()>45)//(1-3)
	{
		setStatusBarElementText(readText("err_RV_CalibPos1","systemPara"),0);
		this->RV_CalibPosLineEdit1->setValue(0);
		return false;
	}
	QVariant RV_CalibPos2 = RV_CalibPosLineEdit2->value();
	if(RV_CalibPos2.toDouble()<10||RV_CalibPos2.toDouble()>45)//(1-3)
	{
		setStatusBarElementText(readText("err_RV_CalibPos2","systemPara"),0);
		this->RV_CalibPosLineEdit2->setValue(0);
		return false;
	}
	return true;
}