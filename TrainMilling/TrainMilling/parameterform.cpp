///////////////////////////////////////////////////////////////////////////////
/*! \file	parameterform.cpp
 *  \author
 *  \date
 *  \brief	Implementation file for class parameterform
 *
 *  This file is part of the HMI Solutionline GUI Framework.
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////
#include "parameterform.h"
#include "QDesktopWidget.h"
#include "QDateTime.h"
#include "GlobalVar.h"

///////////////////////////////////////////////////////////////////////////////
// CREATORS
///////////////////////////////////////////////////////////////////////////////

ParameterForm::ParameterForm(QWidget* pParent, const QString& rszName)
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

	m_nMillingModuleSelect = 4;
	g->m_bHighSpindleSpeed = true;
	MillingModuleSelect( );
	AxisSpeedSelect( );

}// <-- parameterform::parameterform ()


ParameterForm::~ParameterForm(void)
{
	if(m_tmrToggle.isActive())
		m_tmrToggle.stop();
} // <-- ::~ ()

void ParameterForm::attachedToScreen(const QString& rszScreenName)
{
	if(g->m_bIsLogin==false){
		dialog()->switchToScreen("MainScreen",NULL);
		return;
	}

	g->m_HighSpindleSpeed = 3.14159*0.8*g->m_HighAxisAngularSpeed;
	g->m_LowerSpindleSpeed = 3.14159*0.8*g->m_LowAxisAngularSpeed;

	if(g->m_bIsLogin==true)
		setStatusBarElementText(g_pIni->m_strLogin, 1);
	else
		setStatusBarElementText(g_pIni->m_strNotLogin, 1);
	setStatusBarElementText("",0);

	if( g->IsWorkingState() )
	{
		setSoftkeyDisable(2, true);
		setSoftkeyDisable(3, true);
		setSoftkeyDisable(4, true);
		setSoftkeyDisable(5, true);
		setSoftkeyDisable(6, true);
		setSoftkeyDisable(7, true);
		setLineEditReadOnly(true);
	}
	else
	{
		//Method1:-------------------m_bIsRepairLogin or Not Enale Key---------------------
		/*
		setSoftkeyDisable(2, false);
		setSoftkeyDisable(3, false);
		setSoftkeyDisable(4, false);
		setSoftkeyDisable(5, false);
		setSoftkeyDisable(6, false);
		setSoftkeyDisable(7, false);
		setLineEditReadOnly(false);
		*/
		//Method2:------------m_bIsRepairLogin is True,Then Disable the Key----------------
		setSoftkeyDisable(2, g->m_bIsRepairLogin);
		setSoftkeyDisable(3, g->m_bIsRepairLogin);
		setSoftkeyDisable(4, g->m_bIsRepairLogin);
		setSoftkeyDisable(5, g->m_bIsRepairLogin);
		setSoftkeyDisable(6, g->m_bIsRepairLogin);
		setSoftkeyDisable(7, g->m_bIsRepairLogin);
		setLineEditReadOnly(g->m_bIsRepairLogin);
		//End:-----------------------------End End End End---------------------------------
	}
	//Method1:-------------------m_bIsRepairLogin or Not Enale Key---------------------
	/*
	this->LV_PowerControlLineEdit->setReadOnly(!g->m_bPowerControlMode);
	this->RV_PowerControlLineEdit->setReadOnly(!g->m_bPowerControlMode);
	*/
	//Method2:------------m_bIsRepairLogin is True,Then Disable the Key----------------
	this->LV_PowerControlLineEdit->setReadOnly(g->m_bIsRepairLogin || !g->m_bPowerControlMode);
	this->RV_PowerControlLineEdit->setReadOnly(g->m_bIsRepairLogin || !g->m_bPowerControlMode);
	//End:-----------------------------End End End End---------------------------------

	this->PowerControlSelectCheckBox->setChecked(g->m_bPowerControlMode);

	RefreshWorkingParameters( );

	g_pParameterForm = this;
    // don't forget to call the standard implementation
    SlGfwDialogForm::attachedToScreen(rszScreenName);
}


void ParameterForm::detachedFromScreen(const QString& rszScreenName)
{
	g_pParameterForm = 0;
    // don't forget to call the standard implementation
    SlGfwDialogForm::detachedFromScreen(rszScreenName);
}

void ParameterForm::PowerControlSelect( )//恒功率铣削选择
{
	g->m_bPowerControlMode = !g->m_bPowerControlMode;
	this->LV_PowerControlLineEdit->setReadOnly(!g->m_bPowerControlMode);
	this->RV_PowerControlLineEdit->setReadOnly(!g->m_bPowerControlMode);
	this->PowerControlSelectCheckBox->setChecked(g->m_bPowerControlMode);
	if(g->m_bPowerControlMode)//恒功率模式
	{
		this->PowerControlSelectLineEdit->setValue(readText("PowerControlSelectTrue","Parameter"));
		this->setStatusBarElementText(readText("FullKnifeTooth","Parameter"),0);//恒功率模式下，确保刀盘满齿
	}
	else
	{
		this->PowerControlSelectLineEdit->setValue(readText("PowerControlSelectFalse","Parameter"));
		this->setStatusBarElementText("",0);
	}
}

void ParameterForm::MillingModuleSelect( )//车辆组合选择
{
	//if(g->m_bLockState == true)
	{
		m_nMillingModuleSelect++;
		if(m_nMillingModuleSelect >= 4)
			m_nMillingModuleSelect = 0;

		switch(m_nMillingModuleSelect)
		{
		case 0:
			g->m_L_bEnableUnit = false;
			g->m_R_bEnableUnit = false;
			this->MillingModuleLineEdit->setValue(g_pIni->m_strNone);//无
			break;
		case 1:
			g->m_L_bEnableUnit = true;
			g->m_R_bEnableUnit = false;
			this->MillingModuleLineEdit->setValue(g_pIni->m_strLeft);//左
			break;
		case 2:
			g->m_L_bEnableUnit = false;
			g->m_R_bEnableUnit = true;
			this->MillingModuleLineEdit->setValue(g_pIni->m_strRight);//右
			break;
		case 3:
			g->m_L_bEnableUnit = true;
			g->m_R_bEnableUnit = true;
			this->MillingModuleLineEdit->setValue(g_pIni->m_strLeftAndRight);//左、右
			break;
		default:
			break;
		}
	}
}

void ParameterForm::AxisSpeedSelect( )//高低速选择
{
	if(g->m_bHighSpindleSpeed == true){
		g->m_bHighSpindleSpeed = false;
		this->AxisLineSpeedLineEdit->setValue(g->double2double(g->m_LowerSpindleSpeed));//切线削速度 低速
	}
	else{
		g->m_bHighSpindleSpeed = true;
		this->AxisLineSpeedLineEdit->setValue(g->double2double(g->m_HighSpindleSpeed)); //切线削速度 高速
	}
}

void ParameterForm::TrainSpeedPlus( )
{
	if( !g->IsWorkingState() ){
		g->m_DstTrainSpeed += 0.1;
		if(g->m_DstTrainSpeed > 2.0)
			g->m_DstTrainSpeed = 2.0;
		
		this->TrainSpeedLineEdit->setValue(QString::number(g->m_DstTrainSpeed,'f',1));//小数点后保留一位 ligy 20190927
		

		//QString str = QString::number(g->m_DstTrainSpeed, 'f', 3);
		//this->TrainSpeedLineEdit->setValue(str);
	}
}

void ParameterForm::TrainSpeedMinus( )
{
	if( !g->IsWorkingState() ){
		g->m_DstTrainSpeed -= 0.1;
		if(g->m_DstTrainSpeed < 0.1)
			g->m_DstTrainSpeed = 0.1;
		this->TrainSpeedLineEdit->setValue(QString::number(g->m_DstTrainSpeed,'f',1));

		//QString str = QString::number(g->m_DstTrainSpeed, 'f', 3);
		//this->TrainSpeedLineEdit->setValue(str);

	}
}

///////////////////////////////////////////////////////////////////////////////
// public SLOTS - system overrides
///////////////////////////////////////////////////////////////////////////////
void ParameterForm::onFunction (const QString& rsFunction,
                                    const QString& rsArgs,
                                    bool& rbHandled)
{
	// check null pointer
	if ( "TrainSpeedPlus" == rsFunction )
	{
		TrainSpeedPlus( );//车速+
		rbHandled = true;
	}
	else if ( "TrainSpeedMinus" == rsFunction )
	{
		TrainSpeedMinus( );//车速-
		rbHandled = true;
	}
	else if ( "AxisSpeedSelect" == rsFunction )
	{
		AxisSpeedSelect( );//高低速选择
		rbHandled = true;
	}
	else if ( "MillingModuleSelect" == rsFunction )
	{
		MillingModuleSelect( );//车辆组合选择
		rbHandled = true;
	}
	else if ( "PowerControlSelect" == rsFunction )
	{
		PowerControlSelect( );//恒功率铣削选择
		rbHandled = true;
	}
	else if ( "SaveParameter" == rsFunction )//保存参数
	{
		if(checkValid())
		{
			WriteWorkingParametersToIni( );
			WriteWorkingParametersToCNC( );
			setSoftkeyDisable(2, true);
			setSoftkeyDisable(3, true);
			setSoftkeyDisable(4, true);
			setSoftkeyDisable(5, true);
			setSoftkeyDisable(6, true);
			setSoftkeyDisable(7, true);
			setLineEditReadOnly(true);
			setStatusBarElementText(readText("ok_Save","Parameter"),0);

			if (g->m_bIsLogin)//ligy 20200213 add.添加日志 系统参数保存
			{
				g->m_StreamLog<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss")
					<<","<<g->m_strNowUserName
					<<","<< g_pIni->m_strLog_WorkParamSave <<endl;
				g->m_StreamLog.flush();//ligy 20200213 add.
			}	
		}
		rbHandled = true;
	}
	// need to call the base class
	if ( false == rbHandled )
		SlGfwDialogForm::onFunction(rsFunction, rsArgs, rbHandled);
} // <-- parameterform::onFunction ()


///////////////////////////////////////////////////////////////////////////////
// private methods
///////////////////////////////////////////////////////////////////////////////
void ParameterForm::TimeoutSlot()
{
	/*
	// read toggle-item
	QDateTime current_date_time =QDateTime::currentDateTime();
	QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss ddd");
	setCaptionBarElementText(current_date,1);
	*/
}

void ParameterForm::RefreshWorkingParameters()
{
	this->LH_CuttingDepthLineEdit->setValue(g->m_LH_CutDepth);//横向切深 左铣削单元
	this->LV_CuttingDepthLineEdit->setValue(g->m_LV_CutDepth);//垂向切深 左铣削单元
	this->RH_CuttingDepthLineEdit->setValue(g->m_RH_CutDepth);//横向切深 右铣削单元
	this->RV_CuttingDepthLineEdit->setValue(g->m_RV_CutDepth);//垂向切深 右铣削单元
	this->H_DeviceIniPosLineEdit->setValue(g->m_H_DeviceIniPos);//装置横向初始位
	this->V_DeviceIniPosLineEdit->setValue(g->m_V_DeviceIniPos);//装置纵向初始位
	this->H_WorkIniPosLineEdit->setValue(g->m_H_WorkIniPos);    //作业横向初始位
	this->V_WorkIniPosLineEdit->setValue(g->m_V_WorkIniPos);    //作业垂向初始位
	this->TrainSpeedLineEdit->setValue(QString::number(g->m_DstTrainSpeed,'f',1));     //车速
	this->TrainSpdDiffLineEdit->setValue(g->m_DstTrainSpeedDiff);//ligy 20190908 add 速度超差范围
	this->TrainSpdDiffTimeLineEdit->setValue(g->m_DstTrainSpeedDiffTime);//ligy 20190910 add.速度超差监控时间
	this->SlopeLengthLineEdit->setValue(g->m_SlopeLength);       //顺坡长度
	if(g->m_bHighSpindleSpeed == true){
		this->AxisLineSpeedLineEdit->setValue(g->double2double(g->m_HighSpindleSpeed));//切线削速度
	}
	else{
		this->AxisLineSpeedLineEdit->setValue(g->double2double(g->m_LowerSpindleSpeed));//切线削速度
	}
	this->LV_PowerControlLineEdit->setValue(g->m_LV_PowerControlValue);//恒功率铣削 左铣削单元 %
	this->RV_PowerControlLineEdit->setValue(g->m_RV_PowerControlValue);//恒功率铣削 右铣削单元 %
	if(g->m_bPowerControlMode)
	{
		this->PowerControlSelectLineEdit->setValue(readText("PowerControlSelectTrue","Parameter"));
		this->setStatusBarElementText(readText("FullKnifeTooth","Parameter"),0);
	}
	else
	{
		this->PowerControlSelectLineEdit->setValue(readText("PowerControlSelectFalse","Parameter"));
		this->setStatusBarElementText("",0);
	}
}

void ParameterForm::WriteWorkingParametersToIni( )
{
	g->m_LH_CutDepth = this->LH_CuttingDepthLineEdit->value().toDouble();
	g->m_LV_CutDepth = this->LV_CuttingDepthLineEdit->value().toDouble();
	g->m_RH_CutDepth = this->RH_CuttingDepthLineEdit->value().toDouble();
	g->m_RV_CutDepth = this->RV_CuttingDepthLineEdit->value().toDouble();
	g->m_H_DeviceIniPos = this->H_DeviceIniPosLineEdit->value().toDouble();
	g->m_V_DeviceIniPos = this->V_DeviceIniPosLineEdit->value().toDouble();
	g->m_H_WorkIniPos = this->H_WorkIniPosLineEdit->value().toDouble();
	g->m_V_WorkIniPos = this->V_WorkIniPosLineEdit->value().toDouble();
	g->m_DstTrainSpeed = this->TrainSpeedLineEdit->value().toDouble();
	g->m_DstTrainSpeedDiff = this->TrainSpdDiffLineEdit->value().toDouble();
	g->m_DstTrainSpeedDiffTime = this->TrainSpdDiffTimeLineEdit->value().toDouble();//速度超差监控时间 ligy 20190910 add
	g->m_SlopeLength = this->SlopeLengthLineEdit->value().toDouble();
	g->m_LV_PowerControlValue = this->LV_PowerControlLineEdit->value().toDouble();
	g->m_RV_PowerControlValue = this->RV_PowerControlLineEdit->value().toDouble();
	g_pIni->SaveWorkParameters( );
}

void ParameterForm::WriteWorkingParametersToCNC( )
{
	QVector<SlCapWriteSpecType>	vecWriteSpec;

	if( g_pIni == 0  )
		return;
#ifdef PARA_TO_NCU
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
#endif

/*
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_LEnableUnit, QVariant(g->m_L_bEnableUnit)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_REnableUnit, QVariant(g->m_R_bEnableUnit)) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrPlc_AxisHighSpeedFlag, QVariant(g->m_bHighSpindleSpeed)) );
*/
	bool LV_CutDepth_Flag = g->m_LV_CutDepth >= 1 ? true : false;//横向切深≥1mm时，标志置位；否则，标志复位
	bool RV_CutDepth_Flag = g->m_RV_CutDepth >= 1 ? true : false;//垂向切深≥1mm时，标志置位；否则，标志复位

	vecWriteSpec.append( SlCapWriteSpecType(szItem_LEnableUnit_Bit, QVariant(g->m_L_bEnableUnit)) );
	vecWriteSpec.append( SlCapWriteSpecType(szItem_REnableUnit_Bit, QVariant(g->m_R_bEnableUnit)) );
	if(g->m_bHighSpindleSpeed == true){
		vecWriteSpec.append( SlCapWriteSpecType(szItem_L_SpindleSpeed, QVariant(g->m_HighAxisAngularSpeed)) );
		vecWriteSpec.append( SlCapWriteSpecType(szItem_R_SpindleSpeed, QVariant(g->m_HighAxisAngularSpeed)) );
	}
	else{
		vecWriteSpec.append( SlCapWriteSpecType(szItem_L_SpindleSpeed, QVariant(g->m_LowAxisAngularSpeed)) );
		vecWriteSpec.append( SlCapWriteSpecType(szItem_R_SpindleSpeed, QVariant(g->m_LowAxisAngularSpeed)) );
	}
	vecWriteSpec.append( SlCapWriteSpecType(szItem_LV_CutDepth_Bit, QVariant(LV_CutDepth_Flag)) );
	vecWriteSpec.append( SlCapWriteSpecType(szItem_RV_CutDepth_Bit, QVariant(RV_CutDepth_Flag)) );

	// initialize result specification
	QVector<SlCapWriteResultType> vecWriteResult;

	// write data
	SlCapErrorEnum eError = m_capServer.multiWrite(vecWriteSpec, &vecWriteResult);

	// write success or error to the status bar
	handleRetVal(eError);

	//Send Speed to Tcu
	//g->TcuSetTrainSpeedProc( g->m_DstTrainSpeed );//弃用 ligy 20190906 add

	return;
}

void ParameterForm::handleRetVal(SlCapErrorEnum eError)
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

void ParameterForm::setLineEditReadOnly(bool bReadOnly)
{
	this->LH_CuttingDepthLineEdit->setReadOnly(bReadOnly);
	this->LV_CuttingDepthLineEdit->setReadOnly(bReadOnly);
	this->RH_CuttingDepthLineEdit->setReadOnly(bReadOnly);
	this->RV_CuttingDepthLineEdit->setReadOnly(bReadOnly);
	this->H_DeviceIniPosLineEdit->setReadOnly(bReadOnly);
	this->V_DeviceIniPosLineEdit->setReadOnly(bReadOnly);
	this->H_WorkIniPosLineEdit->setReadOnly(bReadOnly);
	this->V_WorkIniPosLineEdit->setReadOnly(bReadOnly);
	this->TrainSpeedLineEdit->setReadOnly(bReadOnly);
	this->SlopeLengthLineEdit->setReadOnly(bReadOnly);
	this->LV_PowerControlLineEdit->setReadOnly(bReadOnly);
	this->RV_PowerControlLineEdit->setReadOnly(bReadOnly);
}

void ParameterForm::setSoftkeyDisable(int nSoftkey, bool bDisabled)
{
	// get pointer to screen
	SlGfwScreen* pScreen = dialog()->screenRef("ParameterScreen");

	if ( 0 != pScreen )
	{
		// get pointer to softkey
		SlGfwSoftKey* pSoftkey = pScreen->menuSoftkey("ParameterVr", nSoftkey);
		
		// enable/disable softkey
		if ( 0 != pSoftkey )
			pSoftkey->setDisabled(bDisabled);
	}
}

bool ParameterForm::checkValid()
{
	QVariant LH_CuttingDepth = LH_CuttingDepthLineEdit->value();
	if(LH_CuttingDepth.toDouble()<-10||LH_CuttingDepth.toDouble()>6)//(-10-3mm) 
	{
		setStatusBarElementText(readText("err_LH_CutDepth","Parameter"),0);
		this->LH_CuttingDepthLineEdit->setValue(0);
		return false;
	}
	QVariant LV_CuttingDepth = LV_CuttingDepthLineEdit->value();
	if(LV_CuttingDepth.toDouble()<-10||LV_CuttingDepth.toDouble()>9)//(-10-2mm)//modified by luo 1030 2->4
	{
		setStatusBarElementText(readText("err_LV_CutDepth","Parameter"),0);
		this->LV_CuttingDepthLineEdit->setValue(0);
		return false;
	}
	QVariant RH_CuttingDepth = RH_CuttingDepthLineEdit->value();
	if(RH_CuttingDepth.toDouble()<-10||RH_CuttingDepth.toDouble()>3)//(-10-3mm)
	{
		setStatusBarElementText(readText("err_RH_CutDepth","Parameter"),0);
		this->RH_CuttingDepthLineEdit->setValue(0);
		return false;
	}
	QVariant RV_CuttingDepth = RV_CuttingDepthLineEdit->value();
	if(RV_CuttingDepth.toDouble()<-10||RV_CuttingDepth.toDouble()>4)//(-10-2mm)//modified by luo 0921 2->4
	{
		setStatusBarElementText(readText("err_RV_CutDepth","Parameter"),0);
		this->RV_CuttingDepthLineEdit->setValue(0);
		return false;
	}

	QVariant H_DeviceIniPos = H_DeviceIniPosLineEdit->value();
	if(H_DeviceIniPos.toDouble()<2||H_DeviceIniPos.toDouble()>15)//×°ÖÃºáÏò³õÊ¼Î» (5-15mm) 
	{
		setStatusBarElementText(readText("err_H_DeviceIniPos","Parameter"),0);
		this->H_DeviceIniPosLineEdit->setValue(0);
		return false;
	}
	QVariant V_DeviceIniPos = V_DeviceIniPosLineEdit->value();
	if(V_DeviceIniPos.toDouble()<2||V_DeviceIniPos.toDouble()>30)//×°ÖÃ´¹Ïò³õÊ¼Î»  (20-30mm) 
	{
		setStatusBarElementText(readText("err_V_DeviceIniPos","Parameter"),0);
		this->V_DeviceIniPosLineEdit->setValue(0);
		return false;
	}
	QVariant H_WorkIniPos = H_WorkIniPosLineEdit->value();
	if(H_WorkIniPos.toDouble()<2||H_WorkIniPos.toDouble()>6)//×÷ÒµºáÏò³õÊ¼Î»ÖÃ (2-5mm)
	{
		setStatusBarElementText(readText("err_H_WorkIniPos","Parameter"),0);
		this->H_WorkIniPosLineEdit->setValue(0);
		return false;
	}
	QVariant V_WorkIniPos = V_WorkIniPosLineEdit->value();
	if(V_WorkIniPos.toDouble()<2||V_WorkIniPos.toDouble()>6)//×÷Òµ´¹Ïò³õÊ¼Î»ÖÃ  (2-5mm)
	{
		setStatusBarElementText(readText("err_V_WorkIniPos","Parameter"),0);
		this->V_WorkIniPosLineEdit->setValue(0);
		return false;
	}

	QVariant TrainSpeed = TrainSpeedLineEdit->value();
	if(TrainSpeed.toDouble()<0.100||TrainSpeed.toDouble()>2.500)//³µËÙ(500-2500)
	{
		setStatusBarElementText(readText("err_TrainSpeed","Parameter"),0);
		this->TrainSpeedLineEdit->setValue(0);
		return false;
	}

	QVariant SlopeLength = SlopeLengthLineEdit->value();
	if(SlopeLength.toDouble()<100||SlopeLength.toDouble()>2000)//Ë³ÆÂ³¤¶È(0.3-2)
	{
		setStatusBarElementText(readText("err_SlopeLength","Parameter"),0);
		this->SlopeLengthLineEdit->setValue(0);
		return false;
	}
	QVariant m_LV_PowerControlValue = LV_PowerControlLineEdit->value();
	if(m_LV_PowerControlValue.toDouble()<5||m_LV_PowerControlValue.toDouble()>80)//Ë³ÆÂ³¤¶È(0.3-2)
	{
		setStatusBarElementText(readText("err_LV_PowerControlValue","Parameter"),0);
		this->LV_PowerControlLineEdit->setValue(0);
		return false;
	}
	QVariant m_RV_PowerControlValue = RV_PowerControlLineEdit->value();
	if(m_RV_PowerControlValue.toDouble()<5||m_RV_PowerControlValue.toDouble()>80)//Ë³ÆÂ³¤¶È(0.3-2)
	{
		setStatusBarElementText(readText("err_RV_PowerControlValue","Parameter"),0);
		this->RV_PowerControlLineEdit->setValue(0);
		return false;
	}
	return true;
}