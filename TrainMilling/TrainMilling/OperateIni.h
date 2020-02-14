#pragma once

#ifndef OPERATEINI_H_INCLUDED
#define OPERATEINI_H_INCLUDED

#include "QString.h"
#include "QTextCodec.h"
#include "QSettings.h"
#include "QStringList.h"
#include "QFile.h"
#include "QTextStream.h"

#define IniQStringListToQString(list) list.size() > 1 ? list.join(","):list.at(0)

#define STATIC_SAVE		1
#define DYNAMIC_SAVE	2

class OperateIni
{
public:
	OperateIni(void);
	~OperateIni(void);
public:
	void ReadInfoParameters();
	void ReadNNScreenParameters();
	void ReadRepairParameters();
	void ReadWorkStateParameters();
	void ReadShineStateParameters();
	void ReadSoftLimitParameters();
	void SaveSoftLimitParameters();
	void ReadDebugParameters();
	void ReadWorkParameters( );
	void SaveWorkParameters( );
	void ReadMileageParameters( );
	void SaveMileageParameters( );
	void ReadSystemParameters( );
	void SaveSystemParameters( bool bRest = false);
	void ReadRailCalibParameters( );
	void SaveRailCalibParameters( int nType);
	void ReadCPOffsetParameters( );
	void SaveCPOffsetParameters( );
	void ReadLoginParameters( );
	void SaveUserPassword( QString NewPassword );
	void SaveRepairPassword( QString NewPassword );
	void SaveDebugPassword( QString NewPassword );
	void ReadProductParameters( );
	void ReadErrorListHeaders( );
	void ReadStatusListHeaders( );
	void ReadInitialize( );
	void ReadFinalize( );
	void ResetAllParameters( );
public:
	//---------------------------------------------------
	//Reading Parameters
	//---------------------------------------------------
	QTextCodec	*m_pcodec;			//GBK gbk 	
	QSettings	*m_pconfigIniRead;  
	//---------------------------------------------------
	//For Workling Parameters
	//---------------------------------------------------
	QString m_strLeftAndRight;
	QString m_strLeft;
	QString m_strRight;
	QString m_strNone;

	QString	mstrNcu_LH_CuttingDepth;
	QString	mstrNcu_LV_CuttingDepth;
	QString	mstrNcu_RH_CuttingDepth;
	QString	mstrNcu_RV_CuttingDepth;
	QString	mstrNcu_H_DeviceIniPos_ch1;
	QString	mstrNcu_H_DeviceIniPos_ch2;
	QString	mstrNcu_V_DeviceIniPos_ch1;
	QString	mstrNcu_V_DeviceIniPos_ch2;
	QString	mstrNcu_H_WorkIniPos_ch1;
	QString	mstrNcu_H_WorkIniPos_ch2;
	QString	mstrNcu_V_WorkIniPos_ch1;
	QString	mstrNcu_V_WorkIniPos_ch2;
	QString	mstrNcu_TrainSpeed_ch1;
	QString	mstrNcu_TrainSpeed_ch2;
	QString	mstrNcu_SlopeLength_ch1;
	QString	mstrNcu_SlopeLength_ch2;

	QString	mstrPlc_LH_CuttingDepth;
	QString	mstrPlc_LV_CuttingDepth;
	QString	mstrPlc_RH_CuttingDepth;
	QString	mstrPlc_RV_CuttingDepth;
	QString	mstrPlc_H_DeviceIniPos;
	QString	mstrPlc_V_DeviceIniPos;
	QString	mstrPlc_H_WorkIniPos;
	QString	mstrPlc_V_WorkIniPos;
	QString	mstrPlc_TrainSpeed;
	QString	mstrPlc_SlopeLength;
/*
	QString	mstrPlc_LEnableUnit;
	QString	mstrPlc_REnableUnit;
	QString	mstrPlc_AxisHighSpeedFlag;

	QString	mstrPlc_AutoMillingFlag;
	QString	mstrPlc_UnitLockedFlag;
	QString	mstrPlc_AxisSpeed;
*/
	//---------------------------------------------------
	//For System Parameters
	//---------------------------------------------------
	QString	mstrNcu_LH_RailOffset;
	QString	mstrNcu_LV_RailOffset;
	QString	mstrNcu_RH_RailOffset;
	QString	mstrNcu_RV_RailOffset;
	QString	mstrNcu_LH_SensorCalibPos1;
	QString	mstrNcu_LV_SensorCalibPos1;
	QString	mstrNcu_RH_SensorCalibPos1;
	QString	mstrNcu_RV_SensorCalibPos1;
	QString	mstrNcu_LH_SensorCalibPos2;
	QString	mstrNcu_LV_SensorCalibPos2;
	QString	mstrNcu_RH_SensorCalibPos2;
	QString	mstrNcu_RV_SensorCalibPos2;
	QString	mstrNcu_AxisAngularLowerSpeed_ch1;
	QString	mstrNcu_AxisAngularLowerSpeed_ch2;
	QString	mstrNcu_AxisAngularHighSpeed_ch1;
	QString	mstrNcu_AxisAngularHighSpeed_ch2;
	QString	mstrNcu_H_RapidMoveSpeed_ch1;
	QString	mstrNcu_H_RapidMoveSpeed_ch2;
	QString	mstrNcu_V_RapidMoveSpeed_ch1;
	QString	mstrNcu_V_RapidMoveSpeed_ch2;

	QString	mstrPlc_LH_RailOffset;
	QString	mstrPlc_LV_RailOffset;
	QString	mstrPlc_RH_RailOffset;
	QString	mstrPlc_RV_RailOffset;
	QString	mstrPlc_AxisAngularLowerSpeed;
	QString	mstrPlc_AxisAngularHighSpeed;
	QString	mstrPlc_L_SMWDiameter;
	QString	mstrPlc_R_SMWDiameter;
	QString	mstrPlc_LiftCutterPower;
	QString	mstrPlc_LiftCutterTime;
	QString	mstrPlc_EndCuttingPower;
	QString	mstrPlc_EndCuttingTime;
	QString	mstrPlc_H_RapidMoveSpeed;
	QString	mstrPlc_V_RapidMoveSpeed;
	QString	mstrPlc_OffsetSlopeLength;
	//---------------------------------------------------
	//For RailCalib Parameters
	//---------------------------------------------------
	QString	mstrNcu_LH_MotorCalibPos;
	QString	mstrNcu_LV_MotorCalibPos;
	QString	mstrNcu_RH_MotorCalibPos;
	QString	mstrNcu_RV_MotorCalibPos;
	//---------------------------------------------------
	//For CPOffset Parameters
	//---------------------------------------------------
	QString	mstrNcu_LH_CPOffset1;
	QString	mstrNcu_LV_CPOffset1;
	QString	mstrNcu_RH_CPOffset1;
	QString	mstrNcu_RV_CPOffset1;
	QString	mstrNcu_LH_CPOffset2;
	QString	mstrNcu_LV_CPOffset2;
	QString	mstrNcu_RH_CPOffset2;
	QString	mstrNcu_RV_CPOffset2;
	//---------------------------------------------------
	//For Login Parameters
	//---------------------------------------------------
	QString m_strUserName;
	QString m_strPassword;
	QString m_strNameError;
	QString m_strPwdError;
	QString m_strLogin;
	QString m_strNotLogin;
	QString m_strLoginName;
	QString m_strLogoffName;
	QString m_strModifySuccess;
	QString m_strModifyFailed;
	//---------------------------------------------------
	//For Product Type
	//---------------------------------------------------
	QString	m_strProductInfo;
	//---------------------------------------------------
	//For Error List Headers
	//---------------------------------------------------
	QString m_strErrorNumber;
	QString m_strErrorTime;
	QString m_strErrorState;
	QString m_strErrorText;
	QString m_strErrorWorkState;

	//---------------------------------------------------
	//For Status List Headers
	//---------------------------------------------------
	QString m_strStatusListControlUnit;
	QString m_strStatusListAddress;
	QString m_strStatusListStatus;

	//---------------------------------------------------
	//For NNScreen
	//---------------------------------------------------
	QString m_strDebugPsw;
	QString m_strWaitForRemote;
	QString m_strLoginSuccess;
	QString m_strLoginFailed;
	QString m_strLoginPreID;	
	QString m_strConnectSuccess;
	QString m_strStop;
	QString m_strOffLine;
	QString m_strConnectFailed;

	//---------------------------------------------------
	//For NNScreen
	//---------------------------------------------------
	QString m_strSetDefault;

	//---------------------------------------------------
	//about DeviceRepairForm
	//---------------------------------------------------
	QString m_strRepairPwd;
	QString m_strRepairPwdError;
	QString m_strRepairLogin;
	QString m_strRepairLogoff;

	QString m_strDebugPwd;
	QString m_strDebugPwdError;
	QString m_strDebugLogin;
	QString m_strDebugLogoff;
	//QString m_strRepairLogoff;
	//---------------------------------------------------
	//about Information Tips
	//---------------------------------------------------
	QString m_strTrainSpdNotReach;
	QString m_strAxisSpdNotReach;
	QString m_strDiskSpaceLow;
	QString m_strDiskSpaceAlarm;
	//---------------------------------------------------
	//about WorkState Info
	//---------------------------------------------------
	QString m_strStateUnkown;
	QString m_strStateYFellow;
	QString m_strStateCutIn;
	QString m_strStateMilling;
	QString m_strStateCutOut;
	QString m_strStateEndFellow;
	QString m_strStateWaiting;
	QString m_strStateReady;
	QString m_strStateScan;
	QString m_strStateLoadDown1;
	QString m_strStateStartTrain1;
	QString m_strStateStartTrain2;
	QString m_strStateStartWork;
	QString m_strStateStopWork;
	QString m_strStateStopTrain;
	QString m_strStateLoadDown2;
	QString m_strStateDeviceUp;
	QString m_strStateEmergency;
	QString m_strStateRepair;
	///////////////////////////////////////////////
	//about shine status ligy 20190928 add
	////////////////////////打磨状态///////////////////////
	QString m_strStateShineUnkown;//未知
	QString m_strStateShineWaiting;//打磨等待
	QString m_strStateShineReady;//打磨准备
	QString m_strStateShineDown1;//打磨下降1
	QString m_strStateShineDown2;//打磨下降2
	QString m_strStateShineStart;//打磨开始
	QString m_strStateShineEnd;  //打磨结束
	QString m_strStateShineUp;   //打磨上升
	QString m_strStateShineEmgencyStop;   //打磨上升
	//////////////////////保存参数/////////////////////////
	QString m_strSaveDataParam1;
	QString m_strSaveDataParam2;
	QString m_strSaveDataParam3;
	QString m_strSaveDataParam4;
	QString m_strSaveDataParam5;
	QString m_strSaveDataParam6;
	QString m_strSaveDataParam7;
	QString m_strSaveDataParam8;
	QString m_strSaveDataParam9;
	QString m_strSaveDataParam10;
	QString m_strSaveDataParam11;
	QString m_strSaveDataParam12;
	QString m_strSaveDataParam13;
	QString m_strSaveDataParam14;
	QString m_strSaveDataParam15;
	QString m_strSaveDataParam16;
	QString m_strSaveDataParam17;
	QString m_strSaveDataParam18;
	QString m_strSaveDataParam19;
	QString m_strSaveDataParam20;
	QString m_strSaveDataParam21;
	QString m_strSaveDataParam22;
	QString m_strSaveDataParam23;
	QString m_strSaveDataParam24;
	QString m_strSaveDataParam25;
	QString m_strSaveDataParam26;
	QString m_strSaveDataParam27;

	QString m_strLog_OperateTime;//操作时间
	QString m_strLog_Operator;//操作人
	QString m_strLog_OperateType;//操作类型

	QString m_strLog_Login;//登陆
	QString m_strLog_Logoff;//注销
	QString m_strLog_SysParamSave;//系统参数保存
	QString m_strLog_WorkParamSave;//作业参数保存
	QString m_strLog_ScanParamSave;//轨廓扫描参数保存
	QString m_strLog_BodyStart;//刚性支撑启动
	QString m_strLog_BodyStop;//刚性支撑解除
	QString m_strLog_HydraulicStart;//液压启动
	QString m_strLog_HydraulicStop;//液压停止
	QString m_strLog_ChipStart;//集屑启动
	QString m_strLog_ChipStop;//集屑停止
	QString m_strLog_SpeedWheelStart;//测速轮启动
	QString m_strLog_SpeedWheelStop;//测速轮停止
	QString m_strLog_StartTrain; //启动列车
	QString m_strLog_StopTrain;	//停止列车
	QString m_strLog_StartWork;	//开始作业
	QString m_strLog_StopWork;	//停止作业
	QString m_strLog_DeviceUp;	//装置上升
	QString m_strLog_DeviceDown;//装置下降
};

#endif // OPERATEINI_H_INCLUDED