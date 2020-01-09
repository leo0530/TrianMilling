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
#define szItem_LEnableUnit_Bit			"M30.0" //��Ԫѡ���־
#define szItem_REnableUnit_Bit			"M30.1" //�ҵ�Ԫѡ���־
#define szItem_UserLogin_Bit			"M31.7" //�û�ϵͳ��¼��־
#define szItem_RepairEnable_Bit			"M31.4" //����ʹ�ܱ�־
#define szItem_RepairOver_Bit			"M32.5" //����ģʽ�˳������־

#define szItem_PCUEmergencyStop_Bit		"M32.0"	//�����������ϱ�־
#define szItem_ScanSave_Bit				"M31.1" //ɨ���Ʊ��趨��־
#define szItem_EndFellow_Bit			"M31.2" //�г�ֹͣ������ɱ�־
#define szItem_SpeedReached_Bit			"M30.4" //���١�����ת�ٴﵽ�趨ֵ�����Զ��������
#define szItem_EndSlopeOut_Bit			"M30.7" //˳���г���ɱ�־
#define szItem_EndSlopeIn_Bit			"M32.4" //˳��������ɱ�־
#define szItem_ScanBias_Bit				"M31.5"	//				//Reserved!!!

#define szItem_LV_CutDepth_Bit			"M35.0" //���ѹѥѹ���ֶα�־
#define szItem_RV_CutDepth_Bit			"M35.1" //�Ҳ�ѹѥѹ���ֶα�־
/*
#define szItem_LHigh_Bit				"I41.6"
#define szItem_RHigh_Bit				"I45.1"
*/
#define szItem_LH_MotorDstPos			"/channel/parameter/r[u1,31]"//������������λ��
#define szItem_LV_MotorDstPos			"/channel/parameter/r[u1,33]"//��ഹ��������λ��
#define szItem_RH_MotorDstPos			"/channel/parameter/r[u2,31]"//�Ҳ����������λ��
#define szItem_RV_MotorDstPos			"/channel/parameter/r[u2,33]"//�Ҳഹ��������λ��

#define szItem_LH_MotorDstSpeed			"/channel/parameter/r[u1,30]"//��ഹ���������ٶ�
#define szItem_LV_MotorDstSpeed			"/channel/parameter/r[u1,32]"//��ഹ���������ٶ�
#define szItem_RH_MotorDstSpeed			"/channel/parameter/r[u2,30]"//�Ҳ�����������ٶ�
#define szItem_RV_MotorDstSpeed			"/channel/parameter/r[u2,32]"//�Ҳഹ���������ٶ�

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
#define szItem_L_Scan					"PIW260"  //��༤��ɨ������
#define szItem_R_Scan					"PIW262"  //�Ҳ༤��ɨ������

#define szItem_L_HydraulicTransmitter	"PIW276"  //����͸�ѹ��������
#define szItem_R_HydraulicTransmitter	"PIW278"  //�Ҳ��͸�ѹ��������
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

#define szItem_PLCStatus_Word			"MW33"   //NCU��ҵ�׶�״̬��
#define szItem_PLCShineStatus_Word		"MW518"   //��ĥ״̬��
#define szItem_TrainStart_Bit			"M30.2"  //����������־
#define szItem_WorkStart_Bit			"M30.5"  //��ҵ��ʼ��־
#define szItem_WorkStop_Bit				"M30.6"  //��ҵֹͣ��־
#define szItem_TrainStop_Bit			"M30.3"  //����ֹͣ��־
#define szItem_ScanStart_Bit			"M31.0"  //ɨ����ͣ��־
#define szItem_PLCEmergencyStop_Bit		"M32.1"  //�����������ϱ�־
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
#define szItem_LCollectorBinState_Bit	"M200.6"      //��м��״̬
#define szItem_RCollectorBinState_Bit	"M200.7"      //�Ҽ�м��״̬
#define szItem_BogyState_Bit			"M32.7"       //����֧��״̬
#define szItem_LockState0_Bit			"M31.3"       //װ��������־
#define szItem_LockState1_Bit			"M32.6"       //װ�ý�����־
#define szItem_CH1NCState_Bit			"M32.2"       //ͨ��1 NC����״̬
#define szItem_CH2NCState_Bit			"M32.3"       //ͨ��2 NC����״̬

#define szItem_LH_ScanSave				"MD40"   //��ԪY��궨ֵ
#define szItem_LV_ScanSave				"MD44"   //��ԪZ��궨ֵ
#define szItem_RH_ScanSave				"MD48"   //�ҵ�ԪY��궨ֵ
#define szItem_RV_ScanSave				"MD52"   //�ҵ�ԪZ��궨ֵ

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
//NCU��ҵ�׶�״̬��
#define PLC_WORKSTATE_NULL			0
#define PLC_WORKSTATE_WAITING		1   //��ҵ�ȴ�
#define PLC_WORKSTATE_READY			2   //��ҵ׼��
#define PLC_WORKSTATE_SCAN			3   //����ɨ��
#define PLC_WORKSTATE_LOADDOWN1		4   //װ���½�1
#define PLC_WORKSTATE_STARTTRAIN1	5   //�г�����1
#define PLC_WORKSTATE_STARTTRAIN2	6   //�г�����2
#define PLC_WORKSTATE_STARTWORK		7   //ϳ����ҵ
#define PLC_WORKSTATE_STOPWORK		8   //��ҵ��ֹ
#define PLC_WORKSTATE_STOPTRAIN		9   //�г�ֹͣ
#define PLC_WORKSTATE_LOADDOWN2		10  //װ���½�2
#define PLC_WORKSTATE_DEVICEUP		11  //װ������
#define PLC_WORKSTATE_EMERGENCY		12  //��������
#define PLC_WORKSTATE_REPAIR		13  //����

//PLC ��ĥ״̬
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
#define TOTAL_SPINDLE_POWER			85.0  //���������

#define RET_OK						1
#define RET_TRAINSPDNOTREACH		-1  //����δ�ﵽ
#define RET_AXISSPDNOTREACH			-2  //����ת��δ�ﵽ
#define RET_NOTYFELLOW				-3  //û��Y�����

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
	double			m_LH_CutDepth;//�������� ��ϳ����Ԫ
	double			m_LV_CutDepth;//�������� ��ϳ����Ԫ
	double			m_RH_CutDepth;//�������� ��ϳ����Ԫ
	double			m_RV_CutDepth;//�������� ��ϳ����Ԫ
	double			m_LH_CutDepthOffset;//��������ƫ�� ��
	double			m_LV_CutDepthOffset;//��������ƫ�� ��
	double			m_RH_CutDepthOffset;//��������ƫ�� ��
	double			m_RV_CutDepthOffset;//��������ƫ�� ��
	double			m_H_DeviceIniPos;   //װ�ú����ʼλ
	double			m_V_DeviceIniPos;   //װ�ô����ʼλ
	double			m_H_WorkIniPos;     //��ҵ�����ʼλ
	double			m_V_WorkIniPos;     //��ҵ�����ʼλ
	double			m_DstTrainSpeed;    //����
	double			m_DstTrainSpeedDiff;//ligy 20190908 add �ٶȳ��Χ
	double			m_DstTrainSpeedDiffTime;//ligy 20190908 add �ٶȳ�����ʱ��
	double			m_SlopeLength;      //˳�³���
	double			m_HighSpindleSpeed; //�������ٶ� ����
	double			m_LowerSpindleSpeed;//�������ٶ� ����
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
	double			m_LH_RailOffset;//������� ��
	double			m_LV_RailOffset;//��ƫ ��
	double			m_RH_RailOffset;//������� ��
	double			m_RV_RailOffset;//��ƫ ��
	double			m_LH_SensorCalibPos1;			//Y1(1) //Y1����(1)
	double			m_LV_SensorCalibPos1;			//Z1(1) //Z1����(1)
	double			m_RH_SensorCalibPos1;			//Y2(1) //Y2����(1)
	double			m_RV_SensorCalibPos1;			//Z2(1) //Z2����(1)
	double			m_LH_SensorCalibPos2;			//Y1(2) //Y1����(2)
	double			m_LV_SensorCalibPos2;			//Z1(2) //Z1����(2)
	double			m_RH_SensorCalibPos2;			//Y2(2) //Y2����(2)
	double			m_RV_SensorCalibPos2;			//Z2(2) //Z2����(2)
	double			m_LH_SensorCalibPos;			
	double			m_LV_SensorCalibPos;			
	double			m_RH_SensorCalibPos;			
	double			m_RV_SensorCalibPos;			
	double			m_LowAxisAngularSpeed; //�������ģʽ
	double			m_HighAxisAngularSpeed;//�������ģʽ
	double			m_L_SMWDiameter;//�������ֱ��
	double			m_R_SMWDiameter;//�Ҳ�����ֱ��
	double			m_LiftCutterPower;//��ֵ�������� ����
	double			m_LiftCutterTime; //��ֵ�������� ʱ��
	double			m_EndCuttingPower;//��������� ����
	double			m_EndCuttingTime; //��������� ʱ��
	double			m_H_RapidSpeed;//�������ٶ�
	double			m_V_RapidSpeed;//�������ٶ�
	double			m_OffsetSlopeLength;//ƫ��˳�³���
	double			m_CutterDiameter;
	/*--------------------------------------------
	 *about the Repair form
	 *--------------------------------------------
	 */
	bool			m_bIsRepairLogin;
	bool			m_bIsDebugModeLogin;
	bool			m_bIsRepairOver;//����ģʽ�˳������־
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
	double			m_LH_MotorCalibPos;		//������ ��	
	double			m_LV_MotorCalibPos;		//������ ��	
	double			m_RH_MotorCalibPos;		//������ ��	
	double			m_RV_MotorCalibPos;		//������ ��	
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
	double			mf_L_Power; // ���� ��� (%)
	double			mf_R_Power; // ���� �Ҳ� (%)
	double			mf_L_Temparature; //�¶� ���
	double			mf_R_Temparature; //�¶� �Ҳ�

	double			m_L_AxisAngularSpeed;
	double			m_R_AxisAngularSpeed;
	double			mf_L_AxisAngularSpeed;
	double			mf_R_AxisAngularSpeed;

	bool			m_LH_bSensorStatus1;//I49.6  �������Y1����
	bool			m_LV_bSensorStatus1;//I50.0  �������Z1����
	bool			m_RH_bSensorStatus1;//I50.2  �Ҳ�����Y3����
	bool			m_RV_bSensorStatus1;//I50.4  �Ҳ�����Z3����
	bool			m_LH_bSensorStatus2;//I49.7  �������Y2����
	bool			m_LV_bSensorStatus2;//I50.1  �������Z2����
	bool			m_RH_bSensorStatus2;//I50.3  �Ҳ�����Y4����
	bool			m_RV_bSensorStatus2;//I50.5  �Ҳ�����Z4����

	bool			m_LH_bSensorPriority;
	bool			m_LV_bSensorPriority;
	bool			m_RH_bSensorPriority;
	bool			m_RV_bSensorPriority;

	bool			m_L_bCollectorBinState;//��м��״̬
	bool			m_R_bCollectorBinState;//�Ҽ�м��״̬
	bool			m_bCH1NCState;//ͨ��1NC״̬
	bool			m_bBogyState;//����֧�ű�־
	bool			m_bTrainCommState;//����ͨѶ״̬
	bool			m_bPreTrainCommState;
	bool			m_bPcuCommState;
	bool			m_bGrindState;//��ĥװ��
	bool			m_bLockState0;//װ��������־
	bool			m_bLockState1;//װ�ý�����־
	bool			m_bCH2NCState;//ͨ��2NC״̬

	bool			m_L_bPressShoeStatus;//I42.2  ���ѹѥ�����
	bool			m_R_bPressShoeStatus;//I45.5  �Ҳ�ѹѥ�����

	bool			m_bCurStartTrain;//�г�������־
	bool			m_bCurStartWork; //��ҵ������־
	bool			m_bCurStopWork;  //��ҵֹͣ��־
	bool			m_bCurStopTrain; //�г�ֹͣ��־
	bool			m_bCurStartScan; //ɨ����ͣ��־
	bool			m_bCurAlarmStopWork;//����ֹͣ��ҵ��־

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
	bool			m_CurIOSignals[IOBITCOUNT];//��ǰIO״̬
	bool			m_PreIOSignals[IOBITCOUNT];//֮ǰIO״̬
	/*--------------------------------------------
	 *about Hydraulic Parameters
	 *--------------------------------------------
	 */
	double			m_L_HydraulicTransmitter;
	double			m_R_HydraulicTransmitter;
	double			m_L_HydraulicPValve;
	double			m_R_HydraulicPValve;
	double			mf_L_HydraulicTransmitter;//Һѹ������ ���
	double			mf_R_HydraulicTransmitter;//Һѹ������ �Ҳ�
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

	double			m_LScannerToCutterOffset;//�������뵶�̺���ƫ�� ��
	double			m_RScannerToCutterOffset;//�������뵶�̺���ƫ�� ��
	double			m_H_SoftShoeLen;//�������ѥ����
	double			m_V_SoftShoeLen;//�������ѥ����
	double			m_H_SoftShoeAlph;//�������ѥ������
	double			m_V_SoftShoeAlph;//�������ѥ������
	int				m_H_SoftShoeLayer;//����ֲ����ѥ����
	int				m_V_SoftShoeLayer;//����ֲ����ѥ����
	int				m_H_SoftShoePoints;//�������ѥ����
	int				m_V_SoftShoePoints;//�������ѥ����
	bool			m_bSoftShoeDir;
	double			m_LH_SensorRatio;//�����򴫸���1->2����,����
	double			m_LV_SensorRatio;//��ഹ�򴫸���1->2����,����
	double			m_RH_SensorRatio;//�Ҳ���򴫸���1->2����,����
	double			m_RV_SensorRatio;//�Ҳഹ�򴫸���1->2����,����
	double			m_H_SoftShoeDirRatio1;//�����������ѥ����1
	double			m_H_SoftShoeDirRatio2;//�����������ѥ����2
	double			m_V_SoftShoeDirRatio1;//�����������ѥ����1
	double			m_V_SoftShoeDirRatio2;//�����������ѥ����2

	bool			m_H_bLowPassFilter;//��ͨ�˲� ����
	bool			m_V_bLowPassFilter;//��ͨ�˲� ����

	double			m_LH_SensorCurValue1;
	double			m_LV_SensorCurValue1;
	double			m_RH_SensorCurValue1;
	double			m_RV_SensorCurValue1;
	double			m_LH_SensorCurValue2;
	double			m_LV_SensorCurValue2;
	double			m_RH_SensorCurValue2;
	double			m_RV_SensorCurValue2;

	double			mf_LH_SensorCurValue1;//���򴫸���1 ���
	double			mf_LV_SensorCurValue1;//���򴫸���1 ���
	double			mf_RH_SensorCurValue1;//���򴫸���1 �Ҳ�
	double			mf_RV_SensorCurValue1;//���򴫸���1 �Ҳ�
	double			mf_LH_SensorCurValue2;//���򴫸���2 ���
	double			mf_LV_SensorCurValue2;//���򴫸���2 ���
	double			mf_RH_SensorCurValue2;//���򴫸���2 �Ҳ�
	double			mf_RV_SensorCurValue2;//���򴫸���2 �Ҳ�

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

	double			mf_LH_MotorCurPos;//������ֵ ���
	double			mf_LV_MotorCurPos;//������ֵ ���
	double			mf_RH_MotorCurPos;//������ֵ �Ҳ�
	double			mf_RV_MotorCurPos;//������ֵ �Ҳ�
	double			m_LH_MotorDistToGo;
	double			m_LV_MotorDistToGo;
	double			m_RH_MotorDistToGo;
	double			m_RV_MotorDistToGo;

	double			mf_LH_MotorDistToGo;//��������� ���
	double			mf_LV_MotorDistToGo;//��������� ���
	double			mf_RH_MotorDistToGo;//��������� �Ҳ�
	double			mf_RV_MotorDistToGo;//��������� �Ҳ�

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

	double			mf_L_SMWCurPos;//������P ���
	double			mf_R_SMWCurPos;//������P �Ҳ�
	double			mf_L_SMWCurSpeed;//�������ٶ�V ���
	double			mf_R_SMWCurSpeed;//�������ٶ�V �Ҳ�

	//QVector<GD>	m_LH_GroupData;
	//QVector<GD>	m_LV_GroupData;
	//QVector<GD>	m_RH_GroupData;
	//QVector<GD>	m_RV_GroupData;
	RingBuffer<GDB>	m_LH_GroupData;
	RingBuffer<GDB>	m_LV_GroupData;
	RingBuffer<GDB>	m_RH_GroupData;
	RingBuffer<GDB>	m_RV_GroupData;
	GDB				m_LH_CurData;//�������ѥ ��
	GDB				m_LV_CurData;//�������ѥ ��
	GDB				m_RH_CurData;//�������ѥ ��
	GDB				m_RV_CurData;//�������ѥ ��
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
	double			m_LH_MotorPosHigh;//����������λ ��
	double			m_LH_MotorPosLow; //����������λ ��
	double			m_LV_MotorPosHigh;//����������λ ��
	double			m_LV_MotorPosLow; //����������λ ��
	double			m_RH_MotorPosHigh;//����������λ ��
	double			m_RH_MotorPosLow; //����������λ ��
	double			m_RV_MotorPosHigh;//����������λ ��
	double			m_RV_MotorPosLow; //����������λ ��
	double			m_LH_CutterProtect;//����������� ��
	double			m_LV_CutterProtect;//����������� ��
	double			m_RH_CutterProtect;//����������� ��
	double			m_RV_CutterProtect;//����������� ��
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

	bool			m_L_bHighSignal;//LHigh ���Z��Һѹ�ϼ��޿���
	bool			m_R_bHighSignal;//LHigh �Ҳ�Z��Һѹ�ϼ��޿���

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

	double			m_H_CutBiasStep;//����ֲ�����ֵ
	double			m_V_CutBiasStep;//����ֲ�����ֵ
	double			m_H_MinCutStep;//������С������
	double			m_V_MinCutStep;//������С������

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
	double			m_LV_PowerControlValue;//�㹦��ϳ�� ��ϳ����Ԫ %
	double			m_RV_PowerControlValue;//�㹦��ϳ�� ��ϳ����Ԫ %
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
	void			TcuSetWorkMileageProc(double fWorkMileage);//��̿���
	void			TcuSetTrainSpeedProc(double fSpeed);       //�г��ٶ�����
	void			TcuSetDeviceLockState(bool bLocked);
	void			TcuSetEmergencyState(bool bEmergency);
	void			TcuSetDeviceHighState(bool bHigh);
	void			TcuSetDeviceErrState(bool bErr);
	SlCapErrorEnum	TcuSendData( );
	SlCapErrorEnum	HandleTcuErrProc( );

};

#define TRAIN_STOP 0
#define TRAIN_START 1
extern  WORD g_iAddr40001;//40001,������
extern  WORD g_iAddr40002;//40002,��λ�ź�����/δ����:2.0,ϳĥ��ҵ��ʼ/ֹͣ:2.1,װ�ý�������/����:2.2,װ��������λ/δ��λ:2.3,ϳĥװ�ù���/���:2.4
extern  WORD g_iAddr40003;//40003:������ҵ��̣���16λ��m
extern  WORD g_iAddr40004;//40004:����ҵ��̣�16λ��Km
extern  WORD g_iAddr40005;//40005:Ԥ��
extern  WORD g_iAddr40006;//40006:ϳĥ�г��ٶ� m/h(X1000)
extern  WORD g_iAddr40007;//40007:1 �����г���2 ֹͣ�г�,

#endif // GLOBALDATA_H_INCLUDED