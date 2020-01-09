#pragma once

#ifndef GLOBALDATA_H_INCLUDED
#define GLOBALDATA_H_INCLUDED

#include "QVector.h"
//#include <qvector.h>
#include "QDateTime.h"
#include "QFile.h"
#include "QTextStream.h"
#include "SlQCap.h"
#include "slhmimakros.h"
#include "QMath.h"
#include "QStringList.h"
#include "ErrorData.h"
#include "RingBuffer.h"
#include "QMutex.h"
#include "QTcuCom.h"

//#define PARA_TO_NCU

typedef struct  GroupData  
{
	int		nWorkState;
	double	SensorValue1;
	double	SensorValue2;
	double	MotorPos;
	double	RealPos;
	//int	EdgeIndex;
	//bool	bEdgeMark1;
	//bool	bEdgeMark2;
	double	SensorValue;
	double	PureValue;
	double	SensorValueF;
	double	SensorValueR;
	double	SMWPos;
}GD; 

typedef struct  GroupDataB  
{
	int		nWorkState;
	double	SensorValue1;
	double	SensorValue2;
	double	MotorPos;
	double	RealPos1;
	double	RealPos2;
	//int	EdgeIndex;
	//bool	bEdgeMark1;
	//bool	bEdgeMark2;
	double	SensorValue;
	double	Org_SensorValue;
	double	PureValue;
	double	SMWPos;
}GDB; 

///////////////////////////////////////////////////////////////////////////////
// DEFINES / CONSTS
///////////////////////////////////////////////////////////////////////////////
const QString ACCESS_ERROR	      = "errorNr: %1";

/****
*****abot the Emergrncy Stop
****/
#define szItem_InvalidPress_Bit			"M200.1"
#define szItem_LEnableUnit_Bit			"M30.0" //左单元选择标志
#define szItem_REnableUnit_Bit			"M30.1" //右单元选择标志
#define szItem_UserLogin_Bit			"M31.7" //用户系统登录标志
#define szItem_RepairEnable_Bit			"M31.4" //检修使能标志
#define szItem_RepairOver_Bit			"M32.5" //检修模式退出允许标志

#define szItem_PCUEmergencyStop_Bit		"M32.0"	//紧急提升故障标志
#define szItem_ScanSave_Bit				"M31.1" //扫描后黄标设定标志
#define szItem_EndFellow_Bit			"M31.2" //列车停止跟随完成标志
#define szItem_SpeedReached_Bit			"M30.4" //车速、主轴转速达到设定值，且自动调整完成
#define szItem_EndSlopeOut_Bit			"M30.7" //顺坡切出完成标志
#define szItem_EndSlopeIn_Bit			"M32.4" //顺坡切入完成标志
#define szItem_ScanBias_Bit				"M31.5"	//				//Reserved!!!

#define szItem_LV_CutDepth_Bit			"M35.0" //左侧压靴压力分段标志
#define szItem_RV_CutDepth_Bit			"M35.1" //右侧压靴压力分段标志
/*
#define szItem_LHigh_Bit				"I41.6"
#define szItem_RHigh_Bit				"I45.1"
*/
#define szItem_LH_MotorDstPos			"/channel/parameter/r[u1,31]"//左侧横向电机设置位置
#define szItem_LV_MotorDstPos			"/channel/parameter/r[u1,33]"//左侧垂向电机设置位置
#define szItem_RH_MotorDstPos			"/channel/parameter/r[u2,31]"//右侧横向电机设置位置
#define szItem_RV_MotorDstPos			"/channel/parameter/r[u2,33]"//右侧垂向电机设置位置

#define szItem_LH_MotorDstSpeed			"/channel/parameter/r[u1,30]"//左侧垂向电机设置速度
#define szItem_LV_MotorDstSpeed			"/channel/parameter/r[u1,32]"//左侧垂向电机设置速度
#define szItem_RH_MotorDstSpeed			"/channel/parameter/r[u2,30]"//右侧横向电机设置速度
#define szItem_RV_MotorDstSpeed			"/channel/parameter/r[u2,32]"//右侧垂向电机设置速度

#define szItem_L_SpindleSpeed			"/channel/parameter/r[u1,34]"  
#define szItem_R_SpindleSpeed			"/channel/parameter/r[u2,34]"  

#define szItem_LH_MotorPos				"/channel/MachineAxis/actToolBasePos[u1,1]"
#define szItem_LV_MotorPos				"/channel/MachineAxis/actToolBasePos[u1,2]"
#define szItem_L_SMWPos					"/channel/MachineAxis/actToolBasePos[u1,4]"
#define szItem_RH_MotorPos				"/channel/MachineAxis/actToolBasePos[u2,1]"
#define szItem_RV_MotorPos				"/channel/MachineAxis/actToolBasePos[u2,2]"
#define szItem_R_SMWPos					"/channel/MachineAxis/actToolBasePos[u2,4]"

#define szItem_LH_SensorValue1			"/Nck/State/analogInpVal[1]"		//"PIW512"//
#define szItem_LH_SensorValue2			"/Nck/State/analogInpVal[2]"		//"PIW514"//
#define szItem_LV_SensorValue1			"/Nck/State/analogInpVal[3]"		//"PIW516"//
#define szItem_LV_SensorValue2			"/Nck/State/analogInpVal[4]"		//"PIW518"//
#define szItem_RH_SensorValue1			"/Nck/State/analogInpVal[5]"		//"PIW520"//
#define szItem_RH_SensorValue2			"/Nck/State/analogInpVal[6]"		//"PIW522"//
#define szItem_RV_SensorValue1			"/Nck/State/analogInpVal[7]"		//"PIW524"//
#define szItem_RV_SensorValue2			"/Nck/State/analogInpVal[8]"		//"PIW526"//

#define szItem_LH_DistToGo				"/Nck/MachineAxis/toolBaseDistToGo[1]"
#define szItem_LV_DistToGo				"/Nck/MachineAxis/toolBaseDistToGo[2]"
#define szItem_RH_DistToGo				"/Nck/MachineAxis/toolBaseDistToGo[4]"
#define szItem_RV_DistToGo				"/Nck/MachineAxis/toolBaseDistToGo[5]"
/*
#define szItem_LH_EdgeMark1				"/channel/parameter/r[u1,1]"
#define szItem_LH_EdgeMark2				"/channel/parameter/r[u1,2]"
#define szItem_LV_EdgeMark1				"/channel/parameter/r[u1,3]"
#define szItem_LV_EdgeMark2				"/channel/parameter/r[u1,4]"
#define szItem_RH_EdgeMark1				"/channel/parameter/r[u2,1]"
#define szItem_RH_EdgeMark2				"/channel/parameter/r[u2,2]"
#define szItem_RV_EdgeMark1				"/channel/parameter/r[u2,3]"
#define szItem_RV_EdgeMark2				"/channel/parameter/r[u2,4]"
*/
#define szItem_L_Scan					"PIW260"  //左侧激光扫描测距仪
#define szItem_R_Scan					"PIW262"  //右侧激光扫描测距仪

#define szItem_L_HydraulicTransmitter	"PIW276"  //左侧油缸压力变送器
#define szItem_R_HydraulicTransmitter	"PIW278"  //右侧油缸压力变送器
#define szItem_L_HydraulicPValve		"PQW260"
#define szItem_R_HydraulicPValve		"PQW262"

#define szItem_L_Power_1				"/channel/Spindle/driveLoad[u1]"		//"/channel/Spindle/driveLoad[u1,1]"			//"/DriveHsa/State/load[u1]"
#define szItem_R_Power_1				"/channel/Spindle/driveLoad[u2]"		//"/channel/Spindle/driveLoad[u2,1]"			//"/DriveHsa/State/load[u2]"
#define szItem_L_Power					"MW56"//"MD56"//"/channel/Spindle/driveLoad[u1]"		//"/channel/Spindle/driveLoad[u1,1]"			//"/DriveHsa/State/load[u1]"
#define szItem_R_Power					"MW62"//"MD68"//"/channel/Spindle/driveLoad[u2]"		//"/channel/Spindle/driveLoad[u2,1]"			//"/DriveHsa/State/load[u2]"
#define szItem_L_Temparature			"MW60"//"MD64"//"/channel/Spindle/motorTemperature[u1]"	//"/DriveHsa/State/motorTemperature[u1]"
#define szItem_R_Temparature			"MW66"//"MD76"//"/channel/Spindle/motorTemperature[u2]"	//"/DriveHsa/State/motorTemperature[u2]"
#define szItem_LAxisAngularSpeed		"/channel/Spindle/actSpeed[u1]"		
#define szItem_RAxisAngularSpeed		"/channel/Spindle/actSpeed[u2]"		
#define szItem_L_SMWSpeed				"/channel/MachineAxis/actFeedRate[u1,4]"
#define szItem_R_SMWSpeed				"/channel/MachineAxis/actFeedRate[u2,4]"

#define szItem_PLCStatus_Word			"MW33"   //NCU作业阶段状态字
#define szItem_PLCShineStatus_Word		"MW518"   //打磨状态字
#define szItem_TrainStart_Bit			"M30.2"  //机车启动标志
#define szItem_WorkStart_Bit			"M30.5"  //作业开始标志
#define szItem_WorkStop_Bit				"M30.6"  //作业停止标志
#define szItem_TrainStop_Bit			"M30.3"  //机车停止标志
#define szItem_ScanStart_Bit			"M31.0"  //扫描启停标志
#define szItem_PLCEmergencyStop_Bit		"M32.1"  //紧急提升故障标志
#define szItem_LoadDown_Bit				"M31.5"					//Reserved!!!

#define szItem_AlarmWorkStop_Bit		"M31.6"

#define szItem_LH_bSensorStatus1		"I49.6"					//Reserved!!!
#define szItem_LV_bSensorStatus1		"I50.0"					//Reserved!!!
#define szItem_RH_bSensorStatus1		"I50.2"					//Reserved!!!
#define szItem_RV_bSensorStatus1		"I50.4"					//Reserved!!!
#define szItem_LH_bSensorStatus2		"I49.7"					//Reserved!!!
#define szItem_LV_bSensorStatus2		"I50.1"					//Reserved!!!
#define szItem_RH_bSensorStatus2		"I50.3"					//Reserved!!!
#define szItem_RV_bSensorStatus2		"I50.5"					//Reserved!!!

#define szItem_GrindState_Bit			"M542.6"
#define szItem_LCollectorBinState_Bit	"M200.6"      //左集屑仓状态
#define szItem_RCollectorBinState_Bit	"M200.7"      //右集屑仓状态
#define szItem_BogyState_Bit			"M32.7"       //刚性支撑状态
#define szItem_LockState0_Bit			"M31.3"       //装置锁定标志
#define szItem_LockState1_Bit			"M32.6"       //装置解锁标志
#define szItem_CH1NCState_Bit			"M32.2"       //通道1 NC运行状态
#define szItem_CH2NCState_Bit			"M32.3"       //通道2 NC运行状态

#define szItem_LH_ScanSave				"MD40"   //左单元Y轴标定值
#define szItem_LV_ScanSave				"MD44"   //左单元Z轴标定值
#define szItem_RH_ScanSave				"MD48"   //右单元Y轴标定值
#define szItem_RV_ScanSave				"MD52"   //右单元Z轴标定值

//No Use
#define szItem_LH_ScanBias				"/channel/parameter/r[u1,108]"	//No Used!!!
#define szItem_LV_ScanBias				"/channel/parameter/r[u1,109]"	//No Used!!!
#define szItem_RH_ScanBias				"/channel/parameter/r[u2,108]"	//No Used!!!
#define szItem_RV_ScanBias				"/channel/parameter/r[u2,109]"	//No Used!!!

/****
*****abot the Confirm Type
****/
#define CONFIRM_LOGOFF				1
#define CONFIRM_SETDEFAULT			2
#define COMFIRM_REPAIRLOGOFF		3
#define COMFIRM_DEBUGLOGOFF		    4
/****
*****abot the Work State
****/
#define WORKSTATE_NULL				0
#define WORKSTATE_STARTFELLOW_INI	1
#define WORKSTATE_STARTFELLOW		2
#define WORKSTATE_ADJUST_INI		3
#define WORKSTATE_ADJUST			4
#define WORKSTATE_YFELLOW_INI		5
#define WORKSTATE_YFELLOW			6
#define WORKSTATE_WORKIN_INI		7
#define WORKSTATE_WORKIN			8
#define WORKSTATE_CUTIN_INI			9
#define WORKSTATE_CUTIN				10
#define WORKSTATE_MILLING_INI		11
#define WORKSTATE_MILLING			12
#define WORKSTATE_CUTOUT_INI		13
#define WORKSTATE_CUTOUT			14
#define WORKSTATE_WORKOUT_INI		15
#define WORKSTATE_WORKOUT			16
#define WORKSTATE_YFELLOW2_INI		17
#define WORKSTATE_YFELLOW2			18
#define WORKSTATE_ENDFELLOW_INI		19
#define WORKSTATE_ENDFELLOW			20
#define WORKSTATE_EMERGENCY_PCU		21
#define WORKSTATE_EMERGENCY_PLC		22
//NCU作业阶段状态字
#define PLC_WORKSTATE_NULL			0
#define PLC_WORKSTATE_WAITING		1   //作业等待
#define PLC_WORKSTATE_READY			2   //作业准备
#define PLC_WORKSTATE_SCAN			3   //轨廓扫描
#define PLC_WORKSTATE_LOADDOWN1		4   //装置下降1
#define PLC_WORKSTATE_STARTTRAIN1	5   //列车启动1
#define PLC_WORKSTATE_STARTTRAIN2	6   //列车启动2
#define PLC_WORKSTATE_STARTWORK		7   //铣削作业
#define PLC_WORKSTATE_STOPWORK		8   //作业终止
#define PLC_WORKSTATE_STOPTRAIN		9   //列车停止
#define PLC_WORKSTATE_LOADDOWN2		10  //装置下降2
#define PLC_WORKSTATE_DEVICEUP		11  //装置上升
#define PLC_WORKSTATE_EMERGENCY		12  //紧急提升
#define PLC_WORKSTATE_REPAIR		13  //检修

//PLC 打磨状态
#define PLC_SHINESTATE_NULL			0
#define PLC_SHINESTATE_WATING		1
#define PLC_SHINESTATE_READY		2
#define PLC_SHINESTATE_DOWN1		3
#define PLC_SHINESTATE_DOWN2		4
#define PLC_SHINESTATE_START		5
#define PLC_SHINESTATE_END			6
#define PLC_SHINESTATE_UP			7
#define PLC_SHINESTATE_ESTOP		8

#define REPORT_NO_ERR				0x0000
#define REPORT_1_ERR				0x0001
#define	REPORT_2_ERR				0x0002
#define	REPORT_3_ERR				0x0004
#define	REPORT_4_ERR				0x0008
#define REPORT_5_ERR				0x0010
#define REPORT_6_ERR				0x0020
#define REPORT_7_ERR				0x0040
#define REPORT_8_ERR				0x0080
#define REPORT_9_ERR				0x0100
#define REPORT_10_ERR				0x0200
#define REPORT_11_ERR				0x0400

#define IOBITCOUNT					368
#define TOTAL_SPINDLE_POWER			85.0  //主轴最大功率

#define RET_OK						1
#define RET_TRAINSPDNOTREACH		-1  //车速未达到
#define RET_AXISSPDNOTREACH			-2  //主轴转速未达到
#define RET_NOTYFELLOW				-3  //没有Y向跟随

#define RET_DISKSPACEALARM			-1
#define RET_DISKSPACELOW			-2

#define TESTSTATUS_NULL				0
#define TESTSTATUS_START			1
#define TESTSTATUS_WORK				2
#define TESTSTATUS_END				3

#define SENSORDST_NOFELLOW			0

namespace ScannerChoose
{
    enum ScannerChoose {
        Left,
        Right
    };
};


class GlobalData
{
public:
	GlobalData(void);
	~GlobalData(void);
public:
	/*--------------------------------------------
	 *about the Confirm Form
	 *--------------------------------------------
	 */
	int				m_nConfirmType;
	/*--------------------------------------------
	 *about the Error Codes
	 *--------------------------------------------
	 */
	long			m_nNoError;
	int				m_LH_Error;
	int				m_LV_Error;
	int				m_RH_Error;
	int				m_RV_Error;
	/*--------------------------------------------
	 *about the main form
	 *--------------------------------------------
	 */
	bool			m_bIsLogin; 
	int				m_StartTestStatus;
	QString			m_strNowUserName;
	/*--------------------------------------------
	 *about the Debug form
	 *--------------------------------------------
	 */
	bool			m_bIsSetDefault; 
	/*--------------------------------------------
	 *about Scanner Parameters
	 *--------------------------------------------
	 */
	int			    m_ScannerChoose; 
	/*--------------------------------------------
	 *about Status Parameters
	 *--------------------------------------------
	 */
	int				m_nStatusListChosen; 
	/*--------------------------------------------
	 *about MillingAlgorithm Parameters
	 *--------------------------------------------
	 */
	int				m_nWorkState;
	int				m_nPreWorkState;
	int				m_nPLCWorkState;
	int				m_nPrePLCShineState;//ligy 20190928 add
	int				m_nPLCShineState;
	int				m_nPrePLCWorkState;
	bool			m_LH_IsActionOver;
	bool			m_LV_IsActionOver;
	bool			m_RH_IsActionOver;
	bool			m_RV_IsActionOver;
	bool			m_bIsEmgyStop;
	/*--------------------------------------------
	 *about Working Parameters
	 *--------------------------------------------
	 */
	double			m_LH_CutDepth;//横向切深 左铣削单元
	double			m_LV_CutDepth;//垂向切深 左铣削单元
	double			m_RH_CutDepth;//横向切深 右铣削单元
	double			m_RV_CutDepth;//垂向切深 右铣削单元
	double			m_LH_CutDepthOffset;//横向切深偏移 左
	double			m_LV_CutDepthOffset;//垂向切深偏移 左
	double			m_RH_CutDepthOffset;//横向切深偏移 右
	double			m_RV_CutDepthOffset;//垂向切深偏移 右
	double			m_H_DeviceIniPos;   //装置横向初始位
	double			m_V_DeviceIniPos;   //装置垂向初始位
	double			m_H_WorkIniPos;     //作业横向初始位
	double			m_V_WorkIniPos;     //作业横向初始位
	double			m_DstTrainSpeed;    //车速
	double			m_DstTrainSpeedDiff;//ligy 20190908 add 速度超差范围
	double			m_DstTrainSpeedDiffTime;//ligy 20190908 add 速度超差监控时间
	double			m_SlopeLength;      //顺坡长度
	double			m_HighSpindleSpeed; //切线削速度 高速
	double			m_LowerSpindleSpeed;//切线削速度 低速
	bool			m_L_bEnableUnit;
	bool			m_R_bEnableUnit;
	bool			m_bHighSpindleSpeed;				//false for lowspeed,high for highspeed
	double			m_CurTrainSpeed;
	//double		m_AXisSpeed;
	//bool			m_bAutoMilling;
	//bool			m_bUnitLocked;
	double			m_LH_CutDepth_R;
	double			m_LV_CutDepth_R;
	double			m_RH_CutDepth_R;
	double			m_RV_CutDepth_R;
	/*--------------------------------------------
	 *about System Parameters
	 *--------------------------------------------
	 */
	double			m_LH_RailOffset;//轨距修正 左
	double			m_LV_RailOffset;//刀偏 左
	double			m_RH_RailOffset;//轨距修正 右
	double			m_RV_RailOffset;//刀偏 右
	double			m_LH_SensorCalibPos1;			//Y1(1) //Y1读数(1)
	double			m_LV_SensorCalibPos1;			//Z1(1) //Z1读数(1)
	double			m_RH_SensorCalibPos1;			//Y2(1) //Y2读数(1)
	double			m_RV_SensorCalibPos1;			//Z2(1) //Z2读数(1)
	double			m_LH_SensorCalibPos2;			//Y1(2) //Y1读数(2)
	double			m_LV_SensorCalibPos2;			//Z1(2) //Z1读数(2)
	double			m_RH_SensorCalibPos2;			//Y2(2) //Y2读数(2)
	double			m_RV_SensorCalibPos2;			//Z2(2) //Z2读数(2)
	double			m_LH_SensorCalibPos;			
	double			m_LV_SensorCalibPos;			
	double			m_RH_SensorCalibPos;			
	double			m_RV_SensorCalibPos;			
	double			m_LowAxisAngularSpeed; //主轴低速模式
	double			m_HighAxisAngularSpeed;//主轴高速模式
	double			m_L_SMWDiameter;//左测速轮直径
	double			m_R_SMWDiameter;//右测速轮直径
	double			m_LiftCutterPower;//峰值功率设置 功率
	double			m_LiftCutterTime; //峰值功率设置 时间
	double			m_EndCuttingPower;//最大功率设置 功率
	double			m_EndCuttingTime; //最大功率设置 时间
	double			m_H_RapidSpeed;//横向快进速度
	double			m_V_RapidSpeed;//垂向快进速度
	double			m_OffsetSlopeLength;//偏移顺坡长度
	double			m_CutterDiameter;
	/*--------------------------------------------
	 *about the Repair form
	 *--------------------------------------------
	 */
	bool			m_bIsRepairLogin;
	bool			m_bIsDebugModeLogin;
	bool			m_bIsRepairOver;//检修模式退出允许标志
	bool			m_bIsCertified;
	/*--------------------------------------------
	 *about RailCalib Parameters
	 *--------------------------------------------
	 */
	//double		m_LH_SensorCalibPos1;			//Y1( already defined! )
	//double		m_LV_SensorCalibPos1;			//Z1( already defined! )
	//double		m_RH_SensorCalibPos1;			//Y2( already defined! )
	//double		m_RV_SensorCalibPos1;			//Z2( already defined! )
	//double		m_LH_SensorCalibPos2;			//Y1( already defined! )
	//double		m_LV_SensorCalibPos2;			//Z1( already defined! )
	//double		m_RH_SensorCalibPos2;			//Y2( already defined! )
	//double		m_RV_SensorCalibPos2;			//Z2( already defined! )
	double			m_LH_MotorCalibPos;		//横向电机 左	
	double			m_LV_MotorCalibPos;		//垂向电机 左	
	double			m_RH_MotorCalibPos;		//横向电机 右	
	double			m_RV_MotorCalibPos;		//垂向电机 右	
	/*--------------------------------------------
	 *about Scanner Parameters
	 *--------------------------------------------
	 */
	QVector<double> m_L_ScanDataX;
	QVector<double> m_L_ScanDataY; 
	QVector<double> m_R_ScanDataX;
	QVector<double> m_R_ScanDataY; 

	double			m_L_ScanDataMaxY;
	double			m_R_ScanDataMaxY;

	double			m_L_ScanCurPosX; 
	double			m_L_ScanCalibPosX; 
	double			m_R_ScanCurPosX; 
	double			m_R_ScanCalibPosX; 
	/*--------------------------------------------
	 *about Power Monitor Parameters
	 *--------------------------------------------
	 */
	QTime			m_L_LastOverLiftTime;
	QTime			m_R_LastOverLiftTime;
	bool			m_L_bIsLastOverLift;
	bool			m_R_bIsLastOverLift;

	QTime			m_L_LastEndCutTime;
	QTime			m_R_LastEndCutTime;
	bool			m_L_bIsLastOverEndCut;
	bool			m_R_bIsLastOverEndCut;
	/*--------------------------------------------
	 *about SWM Parameters
	 *--------------------------------------------
	 */
	double			m_L_SMWStartWork;
	double			m_R_SMWStartWork;
	double			m_L_SMWStartTrain;
	double			m_R_SMWStartTrain;

	double			m_L_SMWInit;
	double			m_R_SMWInit; 

	double			m_L_SMWWorkMileage;
	double			m_R_SMWWorkMileage;
	double			m_ReportWorkMileage;

	double			m_SMWTotalWorkMileage;
	double			m_SMWTotalTrainMileage;
	double			m_SMWLastRSTWorkMileage;
	double			m_SMWLastRSTTrainMileage;
	QDateTime		m_SMWLastResetTime;

public:
	void			WorkMileageProc();		
	void			DeviceLockStateProc( );
	void			DeviceHighStateProc( );
	/*--------------------------------------------
	 *about Status Parameters
	 *--------------------------------------------
	 */
	double			m_L_Power; 
	double			m_R_Power; 
	double			m_L_Temparature; 
	double			m_R_Temparature; 
	double			mf_L_Power; // 功率 左侧 (%)
	double			mf_R_Power; // 功率 右侧 (%)
	double			mf_L_Temparature; //温度 左侧
	double			mf_R_Temparature; //温度 右侧

	double			m_L_AxisAngularSpeed;
	double			m_R_AxisAngularSpeed;
	double			mf_L_AxisAngularSpeed;
	double			mf_R_AxisAngularSpeed;

	bool			m_LH_bSensorStatus1;//I49.6  左侧测距仪Y1故障
	bool			m_LV_bSensorStatus1;//I50.0  左侧测距仪Z1故障
	bool			m_RH_bSensorStatus1;//I50.2  右侧测距仪Y3故障
	bool			m_RV_bSensorStatus1;//I50.4  右侧测距仪Z3故障
	bool			m_LH_bSensorStatus2;//I49.7  左侧测距仪Y2故障
	bool			m_LV_bSensorStatus2;//I50.1  左侧测距仪Z2故障
	bool			m_RH_bSensorStatus2;//I50.3  右侧测距仪Y4故障
	bool			m_RV_bSensorStatus2;//I50.5  右侧测距仪Z4故障

	bool			m_LH_bSensorPriority;
	bool			m_LV_bSensorPriority;
	bool			m_RH_bSensorPriority;
	bool			m_RV_bSensorPriority;

	bool			m_L_bCollectorBinState;//左集屑仓状态
	bool			m_R_bCollectorBinState;//右集屑仓状态
	bool			m_bCH1NCState;//通道1NC状态
	bool			m_bBogyState;//刚性支撑标志
	bool			m_bTrainCommState;//机车通讯状态
	bool			m_bPreTrainCommState;
	bool			m_bPcuCommState;
	bool			m_bGrindState;//打磨装置
	bool			m_bLockState0;//装置锁定标志
	bool			m_bLockState1;//装置解锁标志
	bool			m_bCH2NCState;//通道2NC状态

	bool			m_L_bPressShoeStatus;//I42.2  左侧压靴落轨检测
	bool			m_R_bPressShoeStatus;//I45.5  右侧压靴落轨检测

	bool			m_bCurStartTrain;//列车启动标志
	bool			m_bCurStartWork; //作业启动标志
	bool			m_bCurStopWork;  //作业停止标志
	bool			m_bCurStopTrain; //列车停止标志
	bool			m_bCurStartScan; //扫描启停标志
	bool			m_bCurAlarmStopWork;//报警停止作业标志

	bool			m_bPreStartTrain;
	bool			m_bPreStartWork;
	bool			m_bPreStopWork;
	bool			m_bPreStopTrain;
	bool			m_bPreStartScan;
	bool			m_bPreAlarmStopWork;

	/*--------------------------------------------
	 *about StatusList Parameters
	 *--------------------------------------------
	 */
	bool			m_CurIOSignals[IOBITCOUNT];//当前IO状态
	bool			m_PreIOSignals[IOBITCOUNT];//之前IO状态
	/*--------------------------------------------
	 *about Hydraulic Parameters
	 *--------------------------------------------
	 */
	double			m_L_HydraulicTransmitter;
	double			m_R_HydraulicTransmitter;
	double			m_L_HydraulicPValve;
	double			m_R_HydraulicPValve;
	double			mf_L_HydraulicTransmitter;//液压变送器 左侧
	double			mf_R_HydraulicTransmitter;//液压变送器 右侧
	double			mf_L_HydraulicPValve;
	double			mf_R_HydraulicPValve;
	/*--------------------------------------------
	 *about MillingAlgorithm Parameters
	 *--------------------------------------------
	 */
	QTime			m_LastSensorAdjustTime;
	QTime			m_LastStartFellowTime;

	double			m_LH_CPOffset1;
	double			m_LV_CPOffset1;
	double			m_RH_CPOffset1;
	double			m_RV_CPOffset1;
	double			m_LH_CPOffset2;
	double			m_LV_CPOffset2;
	double			m_RH_CPOffset2;
	double			m_RV_CPOffset2;

	double			m_LScannerToCutterOffset;//轨廓仪与刀盘横向偏移 左
	double			m_RScannerToCutterOffset;//轨廓仪与刀盘横向偏移 右
	double			m_H_SoftShoeLen;//横向软件靴长度
	double			m_V_SoftShoeLen;//垂向软件靴长度
	double			m_H_SoftShoeAlph;//横向软件靴惯性量
	double			m_V_SoftShoeAlph;//垂向软件靴惯性量
	int				m_H_SoftShoeLayer;//横向分层软件靴数量
	int				m_V_SoftShoeLayer;//垂向分层软件靴数量
	int				m_H_SoftShoePoints;//横向软件靴点数
	int				m_V_SoftShoePoints;//垂向软件靴点数
	bool			m_bSoftShoeDir;
	double			m_LH_SensorRatio;//左侧横向传感器1->2比重,横向
	double			m_LV_SensorRatio;//左侧垂向传感器1->2比重,垂向
	double			m_RH_SensorRatio;//右侧横向传感器1->2比重,横向
	double			m_RV_SensorRatio;//右侧垂向传感器1->2比重,横向
	double			m_H_SoftShoeDirRatio1;//横向正反软件靴比重1
	double			m_H_SoftShoeDirRatio2;//横向正反软件靴比重2
	double			m_V_SoftShoeDirRatio1;//垂向正反软件靴比重1
	double			m_V_SoftShoeDirRatio2;//垂向正反软件靴比重2

	bool			m_H_bLowPassFilter;//低通滤波 横向
	bool			m_V_bLowPassFilter;//低通滤波 垂向

	double			m_LH_SensorCurValue1;
	double			m_LV_SensorCurValue1;
	double			m_RH_SensorCurValue1;
	double			m_RV_SensorCurValue1;
	double			m_LH_SensorCurValue2;
	double			m_LV_SensorCurValue2;
	double			m_RH_SensorCurValue2;
	double			m_RV_SensorCurValue2;

	double			mf_LH_SensorCurValue1;//横向传感器1 左侧
	double			mf_LV_SensorCurValue1;//垂向传感器1 左侧
	double			mf_RH_SensorCurValue1;//横向传感器1 右侧
	double			mf_RV_SensorCurValue1;//垂向传感器1 右侧
	double			mf_LH_SensorCurValue2;//横向传感器2 左侧
	double			mf_LV_SensorCurValue2;//垂向传感器2 左侧
	double			mf_RH_SensorCurValue2;//横向传感器2 右侧
	double			mf_RV_SensorCurValue2;//垂向传感器2 右侧

	bool			m_LH_bSensorChoose1;
	bool			m_LV_bSensorChoose1;
	bool			m_RH_bSensorChoose1;
	bool			m_RV_bSensorChoose1;
	bool			m_LH_bSensorChoose2;
	bool			m_LV_bSensorChoose2;
	bool			m_RH_bSensorChoose2;
	bool			m_RV_bSensorChoose2;
	bool			m_bSensorErr;
	bool			m_bMillingProcessed;

	double			m_LH_MotorCurPos;
	double			m_LV_MotorCurPos;
	double			m_RH_MotorCurPos;
	double			m_RV_MotorCurPos;

	double			mf_LH_MotorCurPos;//横向电机值 左侧
	double			mf_LV_MotorCurPos;//纵向电机值 左侧
	double			mf_RH_MotorCurPos;//横向电机值 右侧
	double			mf_RV_MotorCurPos;//纵向电机值 右侧
	double			m_LH_MotorDistToGo;
	double			m_LV_MotorDistToGo;
	double			m_RH_MotorDistToGo;
	double			m_RV_MotorDistToGo;

	double			mf_LH_MotorDistToGo;//横向电机余程 左侧
	double			mf_LV_MotorDistToGo;//垂向电机余程 左侧
	double			mf_RH_MotorDistToGo;//横向电机余程 右侧
	double			mf_RV_MotorDistToGo;//垂向电机余程 右侧

	double			m_LH_YFollowIniPos;				//Y follow
	double			m_LV_YFollowIniPos;				//Y follow
	double			m_RH_YFollowIniPos;				//Y follow
	double			m_RV_YFollowIniPos;				//Y follow

	double			m_CurCuttingPower;
	double			m_CurLiftCutterTime;
	double			m_CurEndCuttingTime;

	double			m_LH_SensorDstValue;
	double			m_LV_SensorDstValue;
	double			m_RH_SensorDstValue;
	double			m_RV_SensorDstValue;

	double			m_LH_SensorPreDstValue;
	double			m_LV_SensorPreDstValue;
	double			m_RH_SensorPreDstValue;
	double			m_RV_SensorPreDstValue;

	double			m_LH_MotorDstPos;
	double			m_LV_MotorDstPos;
	double			m_RH_MotorDstPos;
	double			m_RV_MotorDstPos;

	double			m_LH_MotorPreDstPos;
	double			m_LV_MotorPreDstPos;
	double			m_RH_MotorPreDstPos;
	double			m_RV_MotorPreDstPos;

	double			m_LH_MotorDstSpeed;
	double			m_LV_MotorDstSpeed;
	double			m_RH_MotorDstSpeed;
	double			m_RV_MotorDstSpeed;

	double			m_L_SMWCurPos;
	double			m_R_SMWCurPos;
	double			m_L_SMWCurSpeed;
	double			m_R_SMWCurSpeed;
	int				m_L_nErr6Times;
	int				m_R_nErr6Times;
	int				m_nErr11Times;

	double			mf_L_SMWCurPos;//测速轮P 左侧
	double			mf_R_SMWCurPos;//测速轮P 右侧
	double			mf_L_SMWCurSpeed;//测速轮速度V 左侧
	double			mf_R_SMWCurSpeed;//测速轮速度V 右侧

	//QVector<GD>	m_LH_GroupData;
	//QVector<GD>	m_LV_GroupData;
	//QVector<GD>	m_RH_GroupData;
	//QVector<GD>	m_RV_GroupData;
	RingBuffer<GDB>	m_LH_GroupData;
	RingBuffer<GDB>	m_LV_GroupData;
	RingBuffer<GDB>	m_RH_GroupData;
	RingBuffer<GDB>	m_RV_GroupData;
	GDB				m_LH_CurData;//横向软件靴 左
	GDB				m_LV_CurData;//垂向软件靴 左
	GDB				m_RH_CurData;//横向软件靴 右
	GDB				m_RV_CurData;//垂向软件靴 右
	GDB				m_LH_PreData;
	GDB				m_LV_PreData;
	GDB				m_RH_PreData;
	GDB				m_RV_PreData;

public:
	SlCapErrorEnum	TrainMillingProc();
public:
	void			PowerMonitorIni( );
	bool			IsLOverEndPowered( );
	bool			IsROverEndPowered( );
	bool			IsLOverLiftPowered( );
	bool			IsROverLiftPowered( );
	bool			IsWorkingState();

public:
	void			PushDataToBuf( );
	bool			PopDataFromBuf_SoftShoe_HV( );
	bool			PopDataFromBuf_Directly( );

public:
	QFile			m_TestfileRecord1;
	QFile			m_TestfileRecord2;
	QTextStream		m_TestStreamRecord1;
	QTextStream		m_TestStreamRecord2;
	void			DataProcessTest_ReadSensorFile();
	void			DataProcessTest_ReadMSFile();
	void			DataProcessTest_WriteFileIni();
	void			DataProcessTest_WriteFile();
	void			DataProcessTest_WriteFileFini();
	void			DataProcessTest_QVector();
	void			DataProcessTest_RingBuffer();

public:
	QFile			m_fileRecord;
	QFile			m_H_fileCutDepth;
	QFile			m_V_fileCutDepth;
	QTextStream		m_StreamRecord;
	QTextStream		m_H_StreamCutDepth;
	QTextStream		m_V_StreamCutDepth;
	QString			m_strfileRecord;
	void			StartRecordData( );
	void			RecordData( );
	void			StopRecordData( );
public:
	void			SaveScanData( );
public:
	double			m_LH_MotorPosHigh;//横向电机上限位 左
	double			m_LH_MotorPosLow; //横向电机下限位 左
	double			m_LV_MotorPosHigh;//垂向电机上限位 左
	double			m_LV_MotorPosLow; //垂向电机下限位 左
	double			m_RH_MotorPosHigh;//横向电机上限位 右
	double			m_RH_MotorPosLow; //横向电机下限位 右
	double			m_RV_MotorPosHigh;//垂向电机上限位 右
	double			m_RV_MotorPosLow; //垂向电机下限位 右
	double			m_LH_CutterProtect;//横向进刀保护 左
	double			m_LV_CutterProtect;//垂向进刀保护 左
	double			m_RH_CutterProtect;//横向进刀保护 右
	double			m_RV_CutterProtect;//垂向进刀保护 右
	void			CutterSoftProtect( int nWorkState );
public:
	void			SetPLCWorkState( int nWorkState );//nWorkState
	void            SetPLCShineState( int nShineState );//ligy 20190928 add
	void			SetPCUWorkState( int nWorkState );
	bool			IsSuddenChange( int nWorkState );
	bool			IsStateActionOver(int nWorkState);
	SlCapErrorEnum	EmergencyStopProc( int nWorkState );
	SlCapErrorEnum	SendPosAndSpeed( double H_Dif=0.05,double V_Dif=0.05 ,bool bForceSend=false );
	SlCapErrorEnum	SendPosAndSpeed( int nWorkState ,bool bForceSend );

public:
	bool			m_bCurTrainSpeedPlus; //V+0.1
	bool			m_bCurTrainSpeedMinus;//V-0.1
	bool			m_bPreTrainSpeedPlus;
	bool			m_bPreTrainSpeedMinus;

	bool			m_L_bHighSignal;//LHigh 左侧Z轴液压上极限开关
	bool			m_R_bHighSignal;//LHigh 右侧Z轴液压上极限开关

	bool			m_LH_CBCurSignal1;//Y1-
	bool			m_LH_CBCurSignal2;//Y1+
	bool			m_LV_CBCurSignal1;//Z1-
	bool			m_LV_CBCurSignal2;//Z1+
	bool			m_RH_CBCurSignal1;//Y2-
	bool			m_RH_CBCurSignal2;//Y2+
	bool			m_RV_CBCurSignal1;//Z2-
	bool			m_RV_CBCurSignal2;//Z2+

	bool			m_LH_CBPreSignal1;
	bool			m_LH_CBPreSignal2;
	bool			m_LV_CBPreSignal1;
	bool			m_LV_CBPreSignal2;
	bool			m_RH_CBPreSignal1;
	bool			m_RH_CBPreSignal2;
	bool			m_RV_CBPreSignal1;
	bool			m_RV_CBPreSignal2;

	double			m_LH_CutBias;
	double			m_LV_CutBias;
	double			m_RH_CutBias;
	double			m_RV_CutBias;
	double			m_LH_PreCutBias;
	double			m_LV_PreCutBias;
	double			m_RH_PreCutBias;
	double			m_RV_PreCutBias;
	double			m_LH_CutBiasStep;
	double			m_LV_CutBiasStep;
	double			m_RH_CutBiasStep;
	double			m_RV_CutBiasStep;

	double			m_H_CutBiasStep;//横向分步进刀值
	double			m_V_CutBiasStep;//垂向分步进刀值
	double			m_H_MinCutStep;//横向最小进刀量
	double			m_V_MinCutStep;//垂向最小进刀量

	bool			m_LV_CutBiasFollowed;
	bool			m_RV_CutBiasFollowed;
	bool			m_LH_CutBiasFollowed;
	bool			m_RH_CutBiasFollowed;

	void			ScanCutBiasIni();
	void			ScanCutBias();
	void			LimitCutBias();
	void			CutBiasStep();

public:
	void			CalCutBiasStep();
	void			CalVSoftShoeLayer();
	void			CalSoftShoePoints();

public:
	bool			m_LV_CutBiasFirstTimeFollowed;
	bool			m_RV_CutBiasFirstTimeFollowed;
	bool			m_LV_PControlUnNormalStopped;
	bool			m_RV_PControlUnNormalStopped;
	double			m_PowerControlLen;
	double			m_PowerControlHalfLen;
	double			m_PowerControlQuarterLen;
	double			m_L_PowerControlLen;
	double			m_R_PowerControlLen;
	double			m_PowerControlWidth;
	double			m_PowerControlCutStep;
	double			m_LV_PowerControlValue;//恒功率铣削 左铣削单元 %
	double			m_RV_PowerControlValue;//恒功率铣削 右铣削单元 %
	bool			m_bPowerControlMode;
	double			m_L_LastPowerControlPos;
	double			m_R_LastPowerControlPos;
	bool			m_LV_pControlMoveForward;
	bool			m_RV_pControlMoveForward;
	void			PowerControlIni();
	void			PowerControlProc();

public:
	bool			ChooseSensor( );
	bool			CheckSensorState( );

public:
	bool			m_bSpeedReached;
	void			SpeedReachedProc();

public:
	void			StartTrainProc();
	int				StartWorkProc();
	void			StopWorkProc();
	void			AlarmStopWorkProc();
	void			StopTrainProc();

public:
	void			sensorFollowingIni( int nWorkState );
	void			sensorFollowing(int nWorkState);
	void			sensorFollowing(double LH_SensorDstValue,double LH_DstSpeed,
									double RH_SensorDstValue,double RH_DstSpeed,
									double LV_SensorDstValue,double LV_DstSpeed,
									double RV_SensorDstValue,double RV_DstSpeed,
									double H_Dif=0.01		,double V_Dif=0.01);
	void			sensorFollowing(double LH_SensorDstValue,double RH_SensorDstValue,
									double LV_SensorDstValue,double RV_SensorDstValue,
									double SlopeLength ,
									double H_Dif=0.01		,double V_Dif=0.01);
public:
	bool			IsLAxisSpeedReachDst( );
	bool			IsRAxisSpeedReachDst( );
	bool			IsAxisSpeedReachDst( );
	bool			IsTrainSpeedReachDst( );
	bool			IsAxisStopMove( );
	bool			IsTrainStopMove( );

public:
	void			SortedData(QVector<double> &x, QVector<double> &y);
	double			qQuickMedian(double * bArray, int iFilterLen);
	void			qQuickMedianGroup(double * bArray1, double * bArray2, int iFilterLen,double &iRet1,double &iRet2);
	void			SortedScanData();
	void			GetLScanDataMaxY();
	void			GetRScanDataMaxY();

public:
	QMutex			m_Mutex;
	void			getValues();
	double			double2double(double input_d);

public:
	void			TcuConnectProc( );
	void			TcuHeartBeatProc( );
	void			TcuEnableTrainProc(bool bEnable);
	void			TcuSetWorkStateProc(bool bStart);
	void			TcuSetWorkMileageProc(double fWorkMileage);//里程控制
	void			TcuSetTrainSpeedProc(double fSpeed);       //列车速度设置
	void			TcuSetDeviceLockState(bool bLocked);
	void			TcuSetEmergencyState(bool bEmergency);
	void			TcuSetDeviceHighState(bool bHigh);
	void			TcuSetDeviceErrState(bool bErr);
	SlCapErrorEnum	TcuSendData( );
	SlCapErrorEnum	HandleTcuErrProc( );

};

#define TRAIN_STOP 0
#define TRAIN_START 1
extern  WORD g_iAddr40001;//40001,心跳包
extern  WORD g_iAddr40002;//40002,到位信号锁定/未锁定:2.0,铣磨作业开始/停止:2.1,装置紧急提升/正常:2.2,装置提升到位/未到位:2.3,铣磨装置故障/解除:2.4
extern  WORD g_iAddr40003;//40003:本次作业里程（低16位）m
extern  WORD g_iAddr40004;//40004:总作业里程（16位）Km
extern  WORD g_iAddr40005;//40005:预留
extern  WORD g_iAddr40006;//40006:铣磨行车速度 m/h(X1000)
extern  WORD g_iAddr40007;//40007:1 启动列车，2 停止列车,

#endif // GLOBALDATA_H_INCLUDED