///////////////////////////////////////////////////////////////////////////////
/*! \file	statusform.cpp
 *  \author
 *  \date
 *  \brief	Implementation file for class StatusForm
 *
 *  This file is part of the HMI Solutionline GUI Framework.
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////
#include "statusform.h"
#include "QDateTime.h"


///////////////////////////////////////////////////////////////////////////////
// CREATORS
///////////////////////////////////////////////////////////////////////////////

StatusForm::StatusForm(QWidget* pParent, const QString& rszName)
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

}// <-- StatusForm::StatusForm ()


StatusForm::~StatusForm(void)
{

} // <-- ::~ ()


///////////////////////////////////////////////////////////////////////////////
// Overrides
///////////////////////////////////////////////////////////////////////////////

void StatusForm::attachedToScreen(const QString& rszScreenName)
{
	if(g->m_bIsLogin==false){
		dialog()->switchToScreen("MainScreen",NULL);
		return;
	}

	if(g->m_bIsLogin==true)
		setStatusBarElementText(g_pIni->m_strLogin, 1);
	else
		setStatusBarElementText(g_pIni->m_strNotLogin, 1);

	if(g->m_bPowerControlMode)
		this->ControlModeLabel->setText(readText("PowerControlMode","Status"));
	else
		this->ControlModeLabel->setText(readText("NoPowerControlMode","Status"));

	RefreshData( ); //���¸�����������ֵ
	RefreshState( );//����״ָ̬ʾ��
	RefreshBias( );  
	RefreshWorkState(true);

	g_pStatusForm = this;
    // don't forget to call the standard implementation
    SlGfwDialogForm::attachedToScreen(rszScreenName);
}


void StatusForm::detachedFromScreen(const QString& rszScreenName)
{
	g_pStatusForm = 0;
    // don't forget to call the standard implementation
    SlGfwDialogForm::detachedFromScreen(rszScreenName);
}

void StatusForm::ShowSendData()
{
	QString sss = QString::number(g_iAddr40001) +","+QString::number(g_iAddr40002) +","+QString::number(g_iAddr40003)+","+QString::number(g_iAddr40004)+","+QString::number(g_iAddr40005)+","+QString::number(g_iAddr40006)+","+QString::number(g_iAddr40007);
	setStatusBarElementText(sss,0);
}

///////////////////////////////////////////////////////////////////////////////
// public SLOTS - system overrides
///////////////////////////////////////////////////////////////////////////////
void StatusForm::onFunction (const QString& rsFunction,
                                    const QString& rsArgs,
                                    bool& rbHandled)
{
	if ( "InputState" == rsFunction )
	{
		g->m_nStatusListChosen = 1;
		dialog()->switchToScreen("StatusListScreen",rsArgs);
		rbHandled = true;
	}
	if ( "OutputState" == rsFunction )
	{
		g->m_nStatusListChosen = 2;
		dialog()->switchToScreen("StatusListScreen",rsArgs);
		rbHandled = true;
	}
	if ( "HydraulicState" == rsFunction )
	{
		g->m_nStatusListChosen = 3;
		dialog()->switchToScreen("StatusListScreen",rsArgs);
		rbHandled = true;
	}
	if ( "CollectorBinState" == rsFunction )
	{
		g->m_nStatusListChosen = 4;
		dialog()->switchToScreen("StatusListScreen",rsArgs);
		rbHandled = true;
	}
	if ( "GrindState" == rsFunction )
	{
		g->m_nStatusListChosen = 5;
		dialog()->switchToScreen("StatusListScreen",rsArgs);
		rbHandled = true;
	}
	if ( "SMWAndLockState" == rsFunction )
	{
		g->m_nStatusListChosen = 6;
		dialog()->switchToScreen("StatusListScreen",rsArgs);
		rbHandled = true;
	}
	if ( "BogyState" == rsFunction )
	{
		g->m_nStatusListChosen = 7;
		dialog()->switchToScreen("StatusListScreen",rsArgs);
		rbHandled = true;
	}
	// need to call the base class
	if ( false == rbHandled )
		SlGfwDialogForm::onFunction(rsFunction, rsArgs, rbHandled);
} // <-- StatusForm::onFunction ()


void StatusForm::RefreshData( )
{
	L_PowerProgressBar->setValue( g->double2double(g->m_L_Power) );//��๦��
	R_PowerProgressBar->setValue( g->double2double(g->m_R_Power) );//�Ҳ๦��
	L_TemparatureLineEdit->setValue( g->double2double(g->m_L_Temparature) );//����¶�
	R_TemparatureLineEdit->setValue( g->double2double(g->m_R_Temparature) );//�Ҳ��¶�

	L_HydraulicTransmitterLineEdit->setValue( g->double2double(g->m_L_HydraulicTransmitter) );//Һѹ������ ��
	R_HydraulicTransmitterLineEdit->setValue( g->double2double(g->m_R_HydraulicTransmitter) );//Һѹ������ ��

	L_SMWSpeedLineEdit->setValue( g->double2double(g->m_L_SMWCurSpeed) );//������V ��
	R_SMWSpeedLineEdit->setValue( g->double2double(g->m_R_SMWCurSpeed) );//������V ��

	L_SMWPosLineEdit->setValue( g->double2double(g->m_L_SMWCurPos) );//������P ��
	R_SMWPosLineEdit->setValue( g->double2double(g->m_R_SMWCurPos) );//������P ��
	//L_HydraulicPValveLineEdit->setValue( g->m_L_HydraulicPValve );
	//R_HydraulicPValveLineEdit->setValue( g->m_R_HydraulicPValve );

	LH_MotorCurPosLineEdit->setValue( g->double2double(g->m_LH_MotorCurPos) );//������ֵ ��
	LV_MotorCurPosLineEdit->setValue( g->double2double(g->m_LV_MotorCurPos) );//������ֵ ��
	RH_MotorCurPosLineEdit->setValue( g->double2double(g->m_RH_MotorCurPos) );//������ֵ ��
	RV_MotorCurPosLineEdit->setValue( g->double2double(g->m_RV_MotorCurPos) );//������ֵ ��

	L_AxisAngularSpeedLineEdit->setValue( fabs(g->double2double(g->m_L_AxisAngularSpeed)) );//����ת�� ��
	R_AxisAngularSpeedLineEdit->setValue( fabs(g->double2double(g->m_R_AxisAngularSpeed)) );//����ת�� ��
	
	LH_SensorValueLineEdit1->setValue( g->double2double(g->m_LH_SensorCurValue1) );//���򴫸���1-��
	LH_SensorValueLineEdit2->setValue( g->double2double(g->m_LH_SensorCurValue2) );//���򴫸���2-��
	LV_SensorValueLineEdit1->setValue( g->double2double(g->m_LV_SensorCurValue1) );//���򴫸���1-��
	LV_SensorValueLineEdit2->setValue( g->double2double(g->m_LV_SensorCurValue2) );//���򴫸���2-��
	RH_SensorValueLineEdit1->setValue( g->double2double(g->m_RH_SensorCurValue1) );//���򴫸���1-��
	RH_SensorValueLineEdit2->setValue( g->double2double(g->m_RH_SensorCurValue2) );//���򴫸���2-��
	RV_SensorValueLineEdit1->setValue( g->double2double(g->m_RV_SensorCurValue1) );//���򴫸���1-��
	RV_SensorValueLineEdit2->setValue( g->double2double(g->m_RV_SensorCurValue2) );//���򴫸���2-��
	
	LH_SoftShoeLineEdit->setValue( g->double2double(g->m_LH_CurData.SensorValue) );//�������ѥ ��
	LV_SoftShoeLineEdit->setValue( g->double2double(g->m_LV_CurData.SensorValue) );//�������ѥ ��
	RH_SoftShoeLineEdit->setValue( g->double2double(g->m_RH_CurData.SensorValue) );//�������ѥ ��
	RV_SoftShoeLineEdit->setValue( g->double2double(g->m_RV_CurData.SensorValue) );//�������ѥ ��

	LH_TargetValueLineEdit->setValue( g->double2double(g->m_LH_SensorDstValue) );//����Ŀ��ֵ ��
	LV_TargetValueLineEdit->setValue( g->double2double(g->m_LV_SensorDstValue) );//����Ŀ��ֵ ��
	RH_TargetValueLineEdit->setValue( g->double2double(g->m_RH_SensorDstValue) );//����Ŀ��ֵ ��
	RV_TargetValueLineEdit->setValue( g->double2double(g->m_RV_SensorDstValue) );//����Ŀ��ֵ ��

	LH_MotorDistToGoLineEdit->setValue( g->double2double(g->m_LH_MotorDistToGo) );//��������� ��
	LV_MotorDistToGoLineEdit->setValue( g->double2double(g->m_LV_MotorDistToGo) );//��������� ��
	RH_MotorDistToGoLineEdit->setValue( g->double2double(g->m_RH_MotorDistToGo) );//��������� ��
	RV_MotorDistToGoLineEdit->setValue( g->double2double(g->m_RV_MotorDistToGo) );//��������� ��

	L_MillingLengthLineEdit->setValue( g->double2double(g->m_L_SMWWorkMileage) );//�ӹ����� ��
	R_MillingLengthLineEdit->setValue( g->double2double(g->m_R_SMWWorkMileage) );//�ӹ����� ��
}

void StatusForm::RefreshBias( )
{
	/*
	QString LH_str = QString::number(g->m_LH_CutBias, 'f', 1);
	QString LV_str = QString::number(g->m_LV_CutBias, 'f', 1);
	QString RH_str = QString::number(g->m_RH_CutBias, 'f', 1);
	QString RV_str = QString::number(g->m_RV_CutBias, 'f', 1);
	LH_CutBiasLineEdit->setValue( LH_str );
	LV_CutBiasLineEdit->setValue( LV_str );
	RH_CutBiasLineEdit->setValue( RH_str );
	RV_CutBiasLineEdit->setValue( RV_str );
	*/

	/*
	if( !g->m_bPowerControlMode )
	{
		LH_CutBiasLineEdit->setValue( double2double(g->m_LH_CutBias) );
		LV_CutBiasLineEdit->setValue( double2double(g->m_LV_CutBias) );
		RH_CutBiasLineEdit->setValue( double2double(g->m_RH_CutBias) );
		RV_CutBiasLineEdit->setValue( double2double(g->m_RV_CutBias) );
	}
	else
	{
		LH_CutBiasLineEdit->setValue( double2double(g->m_LH_CutBias) );
		LV_CutBiasLineEdit->setValue( double2double(g->m_LV_CutBiasStep) );
		RH_CutBiasLineEdit->setValue( double2double(g->m_RH_CutBias) );
		RV_CutBiasLineEdit->setValue( double2double(g->m_RV_CutBiasStep) );
	}
	*/
	LH_CutBiasLineEdit->setValue( double2double(g->m_LH_CutBiasStep) );//LY 
	LV_CutBiasLineEdit->setValue( double2double(g->m_LV_CutBiasStep) );//LZ
	RH_CutBiasLineEdit->setValue( double2double(g->m_RH_CutBiasStep) );//RY
	RV_CutBiasLineEdit->setValue( double2double(g->m_RV_CutBiasStep) );//RZ
}

double StatusForm::double2double(double input_d)
{
	double r_double = 0;
	input_d*=100.000;
	int tmp = input_d;
	r_double = tmp/100.000;
	return r_double;
}

void StatusForm::RefreshState( )
{
	if( g->m_LH_bSensorStatus1 ){//�������Y1����
		LH_SensorLabel1->setStyleSheet(szRedStyle);//���
		//LH_SensorValueLineEdit1->setStyleSheet(szRedColor);
	}
	else if( g->m_LH_bSensorChoose1 ){
		LH_SensorLabel1->setStyleSheet(szGreenStyle);//�̵�
		//LH_SensorValueLineEdit1->setStyleSheet(szGreyColor);
	}
	else{
		LH_SensorLabel1->setStyleSheet(szYellowStyle);//�Ƶ�
		//LH_SensorValueLineEdit1->setStyleSheet(szDarkGreyColor);
	}

	if( g->m_LV_bSensorStatus1 )//�������Z1����
		LV_SensorLabel1->setStyleSheet(szRedStyle);
	else if(g->m_LV_bSensorChoose1)
		LV_SensorLabel1->setStyleSheet(szGreenStyle);
	else
		LV_SensorLabel1->setStyleSheet(szYellowStyle);

	if( g->m_RH_bSensorStatus1 )//�Ҳ�����Y3����
		RH_SensorLabel1->setStyleSheet(szRedStyle);
	else if(g->m_RH_bSensorChoose1)
		RH_SensorLabel1->setStyleSheet(szGreenStyle);
	else
		RH_SensorLabel1->setStyleSheet(szYellowStyle);

	if( g->m_RV_bSensorStatus1 )//�Ҳ�����Z3����
		RV_SensorLabel1->setStyleSheet(szRedStyle);
	else if(g->m_RV_bSensorChoose1)
		RV_SensorLabel1->setStyleSheet(szGreenStyle);
	else
		RV_SensorLabel1->setStyleSheet(szYellowStyle);

	if( g->m_LH_bSensorStatus2 )//�������Y2����
		LH_SensorLabel2->setStyleSheet(szRedStyle);
	else if(g->m_LH_bSensorChoose2)
		LH_SensorLabel2->setStyleSheet(szGreenStyle);
	else
		LH_SensorLabel2->setStyleSheet(szYellowStyle);

	if( g->m_LV_bSensorStatus2 )//�������Z2����
		LV_SensorLabel2->setStyleSheet(szRedStyle);
	else if(g->m_LV_bSensorChoose2)
		LV_SensorLabel2->setStyleSheet(szGreenStyle);
	else
		LV_SensorLabel2->setStyleSheet(szYellowStyle);

	if( g->m_RH_bSensorStatus2 )//�Ҳ�����Y4����
		RH_SensorLabel2->setStyleSheet(szRedStyle);
	else if(g->m_RH_bSensorChoose2)
		RH_SensorLabel2->setStyleSheet(szGreenStyle);
	else
		RH_SensorLabel2->setStyleSheet(szYellowStyle);

	if( g->m_RV_bSensorStatus2 )//�Ҳ�����Z4����
		RV_SensorLabel2->setStyleSheet(szRedStyle);
	else if(g->m_RV_bSensorChoose2)
		RV_SensorLabel2->setStyleSheet(szGreenStyle);
	else
		RV_SensorLabel2->setStyleSheet(szYellowStyle);
	//-------------------------------------------------------------
	//end of Sensorchoose
	//-------------------------------------------------------------
	if(g->m_L_bCollectorBinState)
		L_CollectorBinLabel->setStyleSheet(szRedStyle);//��м�� ���
	else
		L_CollectorBinLabel->setStyleSheet(szGreenStyle);//��м�� �̵�

	if(g->m_R_bCollectorBinState)
		R_CollectorBinLabel->setStyleSheet(szRedStyle);//�Ҽ�м�� ���
	else
		R_CollectorBinLabel->setStyleSheet(szGreenStyle);//�Ҽ�м�� �̵�

	//ͨ��1NC״̬
	if(g->m_bCH1NCState)
		CH1NCLabel->setStyleSheet(szGreenStyle);
	else
		CH1NCLabel->setStyleSheet(szRedStyle);

	if(g->m_bBogyState)//����֧��״̬
		BogyLabel->setStyleSheet(szGreenStyle);
	else
		BogyLabel->setStyleSheet(szRedStyle);

	if(g->m_bTrainCommState)//����ͨѶ״̬
		TrainCommLabel->setStyleSheet(szGreenStyle);
	else
		TrainCommLabel->setStyleSheet(szRedStyle);

	if(g->m_bGrindState)//��ĥװ��״̬
		GrindLabel->setStyleSheet(szGreenStyle);
	else
		GrindLabel->setStyleSheet(szRedStyle);

	//װ������״̬
	if(g->m_bLockState0 && !g->m_bLockState1)
		LockLabel->setStyleSheet(szGreenStyle);
	if(!g->m_bLockState0 && g->m_bLockState1)
		LockLabel->setStyleSheet(szGreyStyle);
	if(!g->m_bLockState0 && !g->m_bLockState1)
		LockLabel->setStyleSheet(szYellowStyle);

	//ͨ��2NC״̬
	if(g->m_bCH2NCState)
		CH2NCLabel->setStyleSheet(szGreenStyle);
	else
		CH2NCLabel->setStyleSheet(szRedStyle);

	//-------------------------------------------------------------
	//end of State
	//-------------------------------------------------------------
	if(g->m_L_bPressShoeStatus)//��ѹѥ״̬
		L_PressShoeLabel->setStyleSheet(szGreenStyle);
	else
		L_PressShoeLabel->setStyleSheet(szGreyStyle);

	if(g->m_R_bPressShoeStatus)//��ѹѥ״̬
		R_PressShoeLabel->setStyleSheet(szGreenStyle);
	else
		R_PressShoeLabel->setStyleSheet(szGreyStyle);
}

void StatusForm::RefreshWorkState( bool bForceFresh )
{
	if( g->m_nPLCWorkState != PLC_WORKSTATE_STARTWORK   && g->m_nPLCWorkState != PLC_WORKSTATE_STOPWORK && 
		g->m_nPLCWorkState != PLC_WORKSTATE_STARTTRAIN1 && g->m_nPLCWorkState != PLC_WORKSTATE_STARTTRAIN2 )
		RefreshWorkState_PLC(bForceFresh);
	else
		RefreshWorkState_PCU(bForceFresh);
}

void StatusForm::RefreshWorkState_PLC( bool bForceFresh  )
{
	if( (g->m_nPLCWorkState != g->m_nPrePLCWorkState) || bForceFresh)
	{
		switch(g->m_nPLCWorkState)
		{
		case PLC_WORKSTATE_WAITING:
			WorkStatusLineEdit->setValue(g_pIni->m_strStateWaiting);//��ҵ�ȴ�
			break;
		case PLC_WORKSTATE_READY:
			WorkStatusLineEdit->setValue(g_pIni->m_strStateReady);//��ҵ׼��
			break;
		case PLC_WORKSTATE_SCAN:
			WorkStatusLineEdit->setValue(g_pIni->m_strStateScan);//����ɨ��
			break;
		case PLC_WORKSTATE_LOADDOWN1:
			WorkStatusLineEdit->setValue(g_pIni->m_strStateLoadDown1);//װ���½�1
			break;
		case PLC_WORKSTATE_STARTTRAIN1:
			WorkStatusLineEdit->setValue(g_pIni->m_strStateStartTrain1);//�г�����1
			break;
		case PLC_WORKSTATE_STARTTRAIN2:
			WorkStatusLineEdit->setValue(g_pIni->m_strStateStartTrain2);//�г�����2
			break;
		case PLC_WORKSTATE_STARTWORK:
			WorkStatusLineEdit->setValue(g_pIni->m_strStateStartWork);//ϳ����ҵ
			break;
		case PLC_WORKSTATE_STOPWORK:
			WorkStatusLineEdit->setValue(g_pIni->m_strStateStopWork);//��ҵֹͣ
			break;
		case PLC_WORKSTATE_STOPTRAIN:
			WorkStatusLineEdit->setValue(g_pIni->m_strStateStopTrain);//�г�ֹͣ
			break;
		case PLC_WORKSTATE_LOADDOWN2:
			WorkStatusLineEdit->setValue(g_pIni->m_strStateLoadDown2);//װ���½�2
			break;
		case PLC_WORKSTATE_DEVICEUP:
			WorkStatusLineEdit->setValue(g_pIni->m_strStateDeviceUp);//װ������
			break;
		case PLC_WORKSTATE_EMERGENCY:
			WorkStatusLineEdit->setValue(g_pIni->m_strStateEmergency);//��������
			break;
		case PLC_WORKSTATE_REPAIR:
			WorkStatusLineEdit->setValue(g_pIni->m_strStateRepair);//����
			break;
		default:
			WorkStatusLineEdit->setValue("");
			break;
		}
	}
}

void StatusForm::RefreshShineState_PLC( bool bForceFresh  )//ligy 20190928 add ��ĥ״̬
{
	if( (g->m_nPLCShineState != g->m_nPrePLCShineState) || bForceFresh)
	{
		switch(g->m_nPLCShineState)
		{
		case PLC_SHINESTATE_WATING:
			ShineStatusLineEdit->setValue(g_pIni->m_strStateShineWaiting);//��ĥ�ȴ�
			break;
		case PLC_SHINESTATE_READY:	
			ShineStatusLineEdit->setValue(g_pIni->m_strStateShineReady);//��ĥ׼��
			break;
		case PLC_SHINESTATE_DOWN1:
			ShineStatusLineEdit->setValue(g_pIni->m_strStateShineDown1);//��ĥ�½�1
			break;
		case PLC_SHINESTATE_DOWN2:
			ShineStatusLineEdit->setValue(g_pIni->m_strStateShineDown2);//��ĥ�½�2
			break;
		case PLC_SHINESTATE_START:
			ShineStatusLineEdit->setValue(g_pIni->m_strStateShineStart);//��ʼ��ĥ
			break;
		case PLC_SHINESTATE_END:
			ShineStatusLineEdit->setValue(g_pIni->m_strStateShineEnd);//ֹͣ��ĥ
			break;
		case PLC_SHINESTATE_UP:
			ShineStatusLineEdit->setValue(g_pIni->m_strStateShineUp);//��ĥ����
			break;
		case PLC_SHINESTATE_ESTOP:
			ShineStatusLineEdit->setValue(g_pIni->m_strStateShineEmgencyStop);//��ĥ��ͣ
			break;
		default:
			ShineStatusLineEdit->setValue("undefine");//��ĥ��ͣ
			break;
		}
	}
}

void StatusForm::RefreshWorkState_PCU( bool bForceFresh )
{
	if( (g->m_nWorkState != g->m_nPreWorkState) || bForceFresh)
	{
		switch(g->m_nWorkState)
		{
		case WORKSTATE_STARTFELLOW_INI:
		case WORKSTATE_STARTFELLOW:
		case WORKSTATE_ADJUST_INI:
		case WORKSTATE_ADJUST:
		case WORKSTATE_YFELLOW_INI:
		case WORKSTATE_YFELLOW:
			WorkStatusLineEdit->setValue(g_pIni->m_strStateYFellow);//��ʼ����
			break;
		case WORKSTATE_WORKIN_INI:
		case WORKSTATE_WORKIN:
		case WORKSTATE_CUTIN_INI:
		case WORKSTATE_CUTIN:
			WorkStatusLineEdit->setValue(g_pIni->m_strStateCutIn);//˳������
			break;
		case WORKSTATE_MILLING_INI:
		case WORKSTATE_MILLING:
			WorkStatusLineEdit->setValue(g_pIni->m_strStateMilling);//ϳ����ҵ
			break;
		case WORKSTATE_CUTOUT_INI:
		case WORKSTATE_CUTOUT:
		case WORKSTATE_WORKOUT_INI:
		case WORKSTATE_WORKOUT:
			WorkStatusLineEdit->setValue(g_pIni->m_strStateCutOut);//˳���г�
			break;
		case WORKSTATE_YFELLOW2_INI:
		case WORKSTATE_YFELLOW2:
		case WORKSTATE_ENDFELLOW_INI:
		case WORKSTATE_ENDFELLOW:
			WorkStatusLineEdit->setValue(g_pIni->m_strStateEndFellow);//ֹͣ����
			break;
		default:
			WorkStatusLineEdit->setValue("");
			break;
		}
	}
}
