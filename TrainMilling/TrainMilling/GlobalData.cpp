#include "GlobalData.h"

//ligy 20190904 add
WORD g_iAddr40001 = 0;//40001,心跳包
WORD g_iAddr40002 = 0;//40002,到位信号锁定/未锁定:2.0,铣磨作业开始/停止:2.1,装置紧急提升/正常:2.2,装置提升到位/未到位:2.3,铣磨装置故障/解除:2.4
WORD g_iAddr40003 = 0;//40003:本次作业里程（低16位）m
WORD g_iAddr40004 = 0;//40004:总作业里程（16位）Km
WORD g_iAddr40005 = 0;//40005:预留
WORD g_iAddr40006 = 0;//40006:铣磨行车速度 m/h(X1000)
WORD g_iAddr40007 = TRAIN_STOP;//40007:1 启动列车，2 停止列车,

GlobalData::GlobalData(void)
{
	m_bHighSpindleSpeed = false;
	/*--------------------------------------------
	 *about the Confirm Form
	 *--------------------------------------------
	 */
	m_nConfirmType = 0;
	/*--------------------------------------------
	 *about the Error Codes
	 *--------------------------------------------
	 */
	m_nNoError = 0x0000;
	m_LH_Error = m_nNoError;
	m_LV_Error = m_nNoError;
	m_RH_Error = m_nNoError;
	m_RV_Error = m_nNoError;
	/*--------------------------------------------
	 *about the main form
	 *--------------------------------------------
	 */
	m_bIsLogin = false; 
	m_bIsCertified = false;//是否授权，检测序列号
	m_strNowUserName = "";
	m_StartTestStatus = TESTSTATUS_NULL;
	/*--------------------------------------------
	 *about the Device Repair form
	 *--------------------------------------------
	 */
	m_bIsRepairLogin = false;
	m_bIsRepairOver = true;
	/*--------------------------------------------
	 *about the Debug form
	 *--------------------------------------------
	 */
	m_bIsSetDefault = false;
	/*--------------------------------------------
	 *about Scanner Parameters
	 *--------------------------------------------
	 */
	m_ScannerChoose = ScannerChoose::Left;
	/*--------------------------------------------
	 *about Status Parameters
	 *--------------------------------------------
	 */
	m_nStatusListChosen = 0; 
	/*--------------------------------------------
	 *about MillingAlgorithm Parameters
	 *--------------------------------------------
	 */
	m_nPreWorkState = WORKSTATE_NULL;
	m_nWorkState = WORKSTATE_NULL;

	m_nPLCWorkState = PLC_WORKSTATE_NULL;
	m_nPrePLCWorkState = PLC_WORKSTATE_NULL;

	m_nPLCShineState = PLC_SHINESTATE_NULL;//ligy 20190928 add
	m_nPrePLCShineState = PLC_SHINESTATE_NULL;//ligy 20190928 add

	m_bIsEmgyStop = false;
	m_LH_IsActionOver = true;
	m_LV_IsActionOver = true;
	m_RH_IsActionOver = true;
	m_RV_IsActionOver = true;

	m_LH_SensorCurValue1 = 0;
	m_LV_SensorCurValue1 = 0;
	m_RH_SensorCurValue1 = 0;
	m_RV_SensorCurValue1 = 0;
	m_LH_SensorCurValue2 = 0;
	m_LV_SensorCurValue2 = 0;
	m_RH_SensorCurValue2 = 0;
	m_RV_SensorCurValue2 = 0;

	mf_LH_SensorCurValue1 = 0;
	mf_LV_SensorCurValue1 = 0;
	mf_RH_SensorCurValue1 = 0;
	mf_RV_SensorCurValue1 = 0;
	mf_LH_SensorCurValue2 = 0;
	mf_LV_SensorCurValue2 = 0;
	mf_RH_SensorCurValue2 = 0;
	mf_RV_SensorCurValue2 = 0;

	m_L_Power = 0;
	m_R_Power = 0;
	m_L_Temparature = 0;
	m_R_Temparature = 0;
	mf_L_Temparature = 0;
	mf_R_Temparature = 0;

	m_L_HydraulicTransmitter = 0;
	m_R_HydraulicTransmitter = 0;
	m_L_HydraulicPValve = 0;
	m_R_HydraulicPValve = 0;

	mf_L_HydraulicTransmitter = 0;
	mf_R_HydraulicTransmitter = 0;
	mf_L_HydraulicPValve = 0;
	mf_R_HydraulicPValve = 0;

	m_L_AxisAngularSpeed = 0;
	m_R_AxisAngularSpeed = 0;
	mf_L_AxisAngularSpeed = 0;
	mf_R_AxisAngularSpeed = 0;

	m_LH_MotorCurPos = 0;
	m_LV_MotorCurPos = 0;
	m_RH_MotorCurPos = 0;
	m_RV_MotorCurPos = 0;

	mf_LH_MotorCurPos = 0;
	mf_LV_MotorCurPos = 0;
	mf_RH_MotorCurPos = 0;
	mf_RV_MotorCurPos = 0;

	m_LH_SensorDstValue = SENSORDST_NOFELLOW;
	m_LV_SensorDstValue = SENSORDST_NOFELLOW;
	m_RH_SensorDstValue = SENSORDST_NOFELLOW;
	m_RV_SensorDstValue = SENSORDST_NOFELLOW;

	m_LH_MotorDistToGo = 0;
	m_LV_MotorDistToGo = 0;
	m_RH_MotorDistToGo = 0;
	m_RV_MotorDistToGo = 0;

	mf_LH_MotorDistToGo = 0;
	mf_LV_MotorDistToGo = 0;
	mf_RH_MotorDistToGo = 0;
	mf_RV_MotorDistToGo = 0;

	m_L_AxisAngularSpeed = 0;
	m_R_AxisAngularSpeed = 0;
	m_LH_PreCutBias = m_LH_CutBias = 0;
	m_LV_PreCutBias = m_LV_CutBias = 0;
	m_RH_PreCutBias = m_RH_CutBias = 0;
	m_RV_PreCutBias = m_RV_CutBias = 0;
	m_LH_CutBiasStep = 0;
	m_LV_CutBiasStep = 0;
	m_RH_CutBiasStep = 0;
	m_RV_CutBiasStep = 0;

	m_L_SMWWorkMileage = 0;
	m_R_SMWWorkMileage = 0;
	m_ReportWorkMileage = 0;
	m_L_SMWCurSpeed = 0;
	m_R_SMWCurSpeed = 0;

	memset(&m_LH_CurData,0,sizeof(m_LH_CurData));
	memset(&m_LV_CurData,0,sizeof(m_LV_CurData));
	memset(&m_RH_CurData,0,sizeof(m_RH_CurData));
	memset(&m_RV_CurData,0,sizeof(m_RV_CurData));

	memset(m_CurIOSignals,false,sizeof(m_CurIOSignals));
	memset(m_PreIOSignals,false,sizeof(m_PreIOSignals));

	m_bCurTrainSpeedPlus = false;
	m_bCurTrainSpeedMinus = false;
	m_bPreTrainSpeedPlus = false;
	m_bPreTrainSpeedMinus = false;

	m_L_bCollectorBinState = true;
	m_R_bCollectorBinState = true;
	m_bCH1NCState = true;
	m_bBogyState = true;
	m_bPreBogyState = true;
	m_bTrainCommState = true;
	m_bPreTrainCommState = true;
	m_bPcuCommState = true;
	m_bGrindState = true;
	m_bLockState0 = true;
	m_bLockState1 = false;
	m_bCH2NCState = true;

	m_L_bPressShoeStatus = true;
	m_R_bPressShoeStatus = true;

	m_L_bEnableUnit = false;
	m_R_bEnableUnit = false;

	m_bSpeedReached = false;
	m_CurTrainSpeed = 0;

	m_L_SMWCurPos = 0;
	m_R_SMWCurPos = 0;
	mf_L_SMWCurPos = 0;
	mf_R_SMWCurPos = 0;
	mf_L_SMWCurSpeed = 0;
	mf_R_SMWCurSpeed = 0;

	m_bCurStartTrain = false;
	m_bCurStartWork = false;
	m_bCurStopWork = false;
	m_bCurStopTrain = false;
	m_bCurStartScan = false;

	m_bPreStartTrain = false;
	m_bPreStartWork = false;
	m_bPreStopWork = false;
	m_bPreStopTrain = false;
	m_bPreStartScan = false;

	m_LH_bSensorPriority = true;
	m_LV_bSensorPriority = true;
	m_RH_bSensorPriority = true;
	m_RV_bSensorPriority = true;

	m_LH_bSensorStatus1 = false;
	m_LH_bSensorStatus2 = false;
	m_LV_bSensorStatus1 = false;
	m_LV_bSensorStatus2 = false;
	m_RH_bSensorStatus1 = false;
	m_RH_bSensorStatus2 = false;
	m_RV_bSensorStatus1 = false;
	m_RV_bSensorStatus2 = false;

	//ligy 20200214 add.监控标志变量初始化
	m_bCurStartTrainSign = false;
	m_bCurStopTrainSign = false;
	m_bCurStartWorkSign = false;
	m_bCurStopWorkSign = false;
	m_bCurDeviceUpSign = false;
	m_bCurDeviceDownSign = false;
	m_bCurHydraulicStartSign = false;
	m_bCurHydraulicStopSign = false;
	m_bCurChipStartSign = false;
	m_bCurChipStopSign = false;
	m_bCurSpeedWheelUpSign = false;
	m_bCurSpeedWheelDownSign = false;
	m_bCurBodySupportSign = false;
	m_bCurBodyReleaseSign = false;

	//m_strfileRecord = "..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\workrecord\\workrecord 2018-05-11 11-32-03 Operator.csv";
	m_strfileRecord = "";
}

GlobalData::~GlobalData(void)
{
	m_L_ScanDataX.clear();
	m_L_ScanDataY.clear();
	m_R_ScanDataX.clear();
	m_R_ScanDataY.clear();
}

void GlobalData::PowerMonitorIni( )
{
	//ligy 20190910 add
	m_L_LastOverLiftTime = QTime::currentTime();//峰值功率设置_时间 左铣削单元 
	m_R_LastOverLiftTime = QTime::currentTime();//峰值功率设置_时间 右铣削单元 
	m_L_LastEndCutTime = QTime::currentTime();  //最大功率设置_时间 左铣削单元 
	m_R_LastEndCutTime = QTime::currentTime();  //最大功率设置_时间 右铣削单元 

	m_L_bIsLastOverLift = false;                //峰值功率设置_功率 左铣削单元 
	m_R_bIsLastOverLift = false;                //峰值功率设置_功率 右铣削单元 
	m_L_bIsLastOverEndCut = false;              //最大功率设置_功率 左铣削单元 
	m_R_bIsLastOverEndCut = false;              //最大功率设置_功率 右铣削单元 
}

bool GlobalData::IsLOverEndPowered( )           //左铣削单元 实时功率是否超过最大功率？
{
	if( m_L_bIsLastOverEndCut ){
		if(m_L_Power > m_EndCuttingPower){
			QTime now = QTime::currentTime();
			//over power
			if( abs(now.msecsTo(m_L_LastEndCutTime)) > m_EndCuttingTime )
				return true;
		}
		else
			m_L_bIsLastOverEndCut = false;
	}
	else {
		if( m_L_Power > m_EndCuttingPower ){
			m_L_LastEndCutTime = QTime::currentTime();
			m_L_bIsLastOverEndCut = true;
		}
	}
	return false;
}

bool GlobalData::IsROverEndPowered( ) //右铣削单元 实时功率是否超过最大功率？
{
	if( m_R_bIsLastOverEndCut ){
		if(m_R_Power > m_EndCuttingPower){
			QTime now = QTime::currentTime();
			//over power
			if( abs(now.msecsTo(m_R_LastEndCutTime)) > m_EndCuttingTime )
				return true;
		}
		else
			m_R_bIsLastOverEndCut = false;
	}
	else {
		if( m_R_Power > m_EndCuttingPower ){
			m_R_LastEndCutTime = QTime::currentTime();
			m_R_bIsLastOverEndCut = true;
		}
	}
	return false;
}

bool GlobalData::IsLOverLiftPowered( )
{
	if( m_L_bIsLastOverLift ){
		if(m_L_Power > m_LiftCutterPower){
			QTime now = QTime::currentTime();
			//over power
			if( abs(now.msecsTo(m_L_LastOverLiftTime)) > m_LiftCutterTime )  //now.msecsTo:返回当前时间对象到所指定的时间对象之间的毫秒数
				return true;
		}
		else
			m_L_bIsLastOverLift = false;
	}
	else {
		if( m_L_Power > m_LiftCutterPower ){
			m_L_LastOverLiftTime = QTime::currentTime();
			m_L_bIsLastOverLift = true;
		}
	}
	return false;
}

bool GlobalData::IsROverLiftPowered( )
{
	if( m_R_bIsLastOverLift ){
		if(m_R_Power > m_LiftCutterPower){
			QTime now = QTime::currentTime();
			//over power
			if( abs(now.msecsTo(m_R_LastOverLiftTime)) > m_LiftCutterTime )
				return true;
		}
		else
			m_R_bIsLastOverLift = false;
	}
	else {
		if( m_R_Power > m_LiftCutterPower ){
			m_R_LastOverLiftTime = QTime::currentTime();
			m_R_bIsLastOverLift = true;
		}
	}
	return false;
}

void GlobalData::DataProcessTest_ReadSensorFile( )
{
	QTime Time;
	Time.start();

	g->DataProcessTest_WriteFileIni();

	QFile fin("C:/scr/sensordata.csv");
	if(!fin.open(QIODevice::ReadOnly | QIODevice::Text ))
	{
		//qDebug()<<"OPEN FILE FAILED";  
	}
	QTextStream txtinput(&fin);
	QStringList m_Lineitems = txtinput.readAll().split("\n");
	for(int i = 0 ; i < m_Lineitems.count() - 1 ; i++)
	{ 
		QStringList Unititem = m_Lineitems.at(i).split(",");
		m_L_SMWCurPos = Unititem.at(0).toDouble();
		m_LH_SensorCurValue1 = Unititem.at(1).toDouble();
		m_LH_SensorCurValue2 = Unititem.at(2).toDouble();
		m_LV_SensorCurValue1 = Unititem.at(3).toDouble();
		m_LV_SensorCurValue2 = Unititem.at(4).toDouble();
		m_R_SMWCurPos = Unititem.at(5).toDouble();
		m_RH_SensorCurValue1 = Unititem.at(6).toDouble();
		m_RH_SensorCurValue2 = Unititem.at(7).toDouble();
		m_RV_SensorCurValue1 = Unititem.at(8).toDouble();
		m_RV_SensorCurValue2 = Unititem.at(9).toDouble();

		m_LH_MotorCurPos = 0;
		m_LV_MotorCurPos = 0;
		m_RH_MotorCurPos = 0;
		m_RV_MotorCurPos = 0;
		/*
		m_LH_MotorCurPos = Unititem.at(10).toDouble();
		m_LV_MotorCurPos = Unititem.at(11).toDouble();
		m_RH_MotorCurPos = Unititem.at(12).toDouble();
		m_RV_MotorCurPos = Unititem.at(13).toDouble();
		*/

		if(i==0)
		{
			m_LH_PreData = m_LH_CurData;
			m_LV_PreData = m_LV_CurData;
			m_RH_PreData = m_RH_CurData;
			m_RV_PreData = m_RV_CurData;
		}
		//SetPCUWorkState(WORKSTATE_STARTFELLOW_INI);

		//PushDataToBuf( );
		//ProcessData( );
		PopDataFromBuf_SoftShoe_HV( );

		g->DataProcessTest_WriteFile();
	}
	fin.close();
	g->DataProcessTest_WriteFileFini();
	int mmsec = Time.elapsed();
}

void GlobalData::DataProcessTest_QVector()
{
	QVector<int> testVector;
	QFile file("C:/scr/TestData.csv");
	if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
		return;  
	QTextStream stream(&file);

	testVector.append(1);	//0
	testVector.append(2);	//1
	testVector.append(3);	//2
	testVector.append(4);	//3
	testVector.append(5);	//4
	testVector.append(6);	//5
	testVector.append(7);	//6
	testVector.append(8);	//7
	testVector.append(9);	//8

	stream<<"Total Length is :" <<QString::number(testVector.size())<<endl;
	for(int i=0;i<testVector.size();i++)
		stream << QString::number(testVector.at(i))<<","; 
	stream <<endl;
	stream.flush();

	//Test 1: Remove Specified Data
	testVector.remove(5);
	stream<<"Total Length is :" <<QString::number(testVector.size())<<endl;
	for(int i=0;i<testVector.size();i++)
		stream << QString::number(testVector.at(i))<<","; 
	stream <<endl;
	stream.flush();

	//Test 2: Remove 2 Specified Datas
	testVector.remove(0,2);
	stream<<"Total Length is :" <<QString::number(testVector.size())<<endl;
	for(int i=0;i<testVector.size();i++)
		stream << QString::number(testVector.at(i))<<","; 
	stream <<endl;
	stream.flush();

	//Test 3: Remove 2 Specified Datas
	testVector.remove(3,2);
	stream<<"Total Length is :" <<QString::number(testVector.size())<<endl;
	for(int i=0;i<testVector.size();i++)
		stream << QString::number(testVector.at(i))<<","; 
	stream <<endl;
	stream.flush();

	file.close();
}

void GlobalData::DataProcessTest_RingBuffer( )
{	
	double iRet1,iRet2;
	double testDouble1[10] = {3,6,2,1,9,8,0,4,5,7 };
	double testDouble2[10] = {7,6,2,1,9,8,0,4,5,3 };
	qQuickMedianGroup(testDouble1,testDouble2,10,iRet1,iRet2);
	return;
	
	RingBuffer<int> testRingBuffer(10);
	QFile file("C:/scr/TestData.csv");
	if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
		return;  
	QTextStream stream(&file);

	testRingBuffer.append(1);	//0
	testRingBuffer.append(2);	//1
	testRingBuffer.append(3);	//2
	testRingBuffer.append(4);	//3
	testRingBuffer.append(5);	//4
	testRingBuffer.append(6);	//5
	testRingBuffer.append(7);	//6
	testRingBuffer.append(8);	//7
	testRingBuffer.append(9);	//8
	
	stream<<"Total Length is :" <<QString::number(testRingBuffer.size())<<endl;
	for(int i=0;i<testRingBuffer.size();i++)
		stream << QString::number(testRingBuffer.at(i))<<","; 
	stream <<endl;
	stream.flush();

	//Test 1: Remove Specified Data
	testRingBuffer.remove(5);
	stream<<"Total Length is :" <<QString::number(testRingBuffer.size())<<endl;
	for(int i=0;i<testRingBuffer.size();i++)
		stream << QString::number(testRingBuffer.at(i))<<","; 
	stream <<endl;
	stream.flush();
	
	//Test 2: Remove 2 Specified Datas
	testRingBuffer.remove(0,3);
	stream<<"Total Length is :" <<QString::number(testRingBuffer.size())<<endl;
	for(int i=0;i<testRingBuffer.size();i++)
		stream << QString::number(testRingBuffer.at(i))<<","; 
	stream <<endl;
	stream.flush();

	//Test 3: Remove 2 Specified Datas
	testRingBuffer.remove(3,2);
	stream<<"Total Length is :" <<QString::number(testRingBuffer.size())<<endl;
	for(int i=0;i<testRingBuffer.size();i++)
		stream << QString::number(testRingBuffer.at(i))<<","; 
	stream <<endl;
	stream.flush();
	
	file.close();
}

void GlobalData::DataProcessTest_ReadMSFile( )
{
	QFile fin("C:/scr/TestMillingData.csv");
	if(!fin.open(QIODevice::ReadOnly | QIODevice::Text ))
	{
		//qDebug()<<"OPEN FILE FAILED";  
	}

	QTextStream txtinput(&fin);
	QStringList m_Lineitems = txtinput.readAll().split("\n");
	for(int i = 0 ; i < m_Lineitems.count() - 1 ; i++)
	{ 
		QStringList Unititem = m_Lineitems.at(i).split(",");
		m_L_SMWCurPos = Unititem.at(0).toDouble();
		m_LH_MotorCurPos = Unititem.at(1).toDouble();
		m_LH_SensorCurValue1 = Unititem.at(2).toDouble();
		m_LH_SensorCurValue2 = Unititem.at(3).toDouble();
		m_LV_MotorCurPos = Unititem.at(4).toDouble();
		m_LV_SensorCurValue1 = Unititem.at(5).toDouble();
		m_LV_SensorCurValue2 = Unititem.at(6).toDouble();
		m_R_SMWCurPos = Unititem.at(7).toDouble();
		m_RH_MotorCurPos = Unititem.at(8).toDouble();
		m_RH_SensorCurValue1 = Unititem.at(9).toDouble();
		m_RH_SensorCurValue2 = Unititem.at(10).toDouble();
		m_RV_MotorCurPos = Unititem.at(11).toDouble();
		m_RV_SensorCurValue1 = Unititem.at(12).toDouble();
		m_RV_SensorCurValue2 = Unititem.at(13).toDouble();

		if(i == 0)
			StartTrainProc( );

		SlCapErrorEnum eError = SL_CAP_OK;
		eError = TrainMillingProc( );
	}
	fin.close();
}

void GlobalData::DataProcessTest_WriteFileIni()
{
	m_LH_GroupData.clear();
	m_LV_GroupData.clear();
	m_RH_GroupData.clear();
	m_RV_GroupData.clear();

	ChooseSensor( );

	QDateTime current_datetime = QDateTime::currentDateTime();
	QString sDateTime=current_datetime.toString("yyyy-MM-dd hh-mm-ss");
	QString fileRecordPath1 = "..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\SensorData\\SensorData"+sDateTime+"_1.csv";
	QString fileRecordPath2 = "..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\SensorData\\SensorData"+sDateTime+"_2.csv";
	m_TestfileRecord1.setFileName(fileRecordPath1);
	m_TestfileRecord2.setFileName(fileRecordPath2);
	//ligy 20200210 add 打开文件
	if(!m_TestfileRecord1.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
	{
		//qDebug()<<"OPEN FILE FAILED";  
	}
	if(!m_TestfileRecord2.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
	{
		//qDebug()<<"OPEN FILE FAILED";  
	}
	m_TestStreamRecord1.setDevice(&m_TestfileRecord1);
	m_TestStreamRecord2.setDevice(&m_TestfileRecord2);
}

void GlobalData::DataProcessTest_WriteSaveDataIni()//ligy 20200211 add 保存数据文件初始化
{
	QDateTime current_datetime = QDateTime::currentDateTime();
	//QString sDateTime=current_datetime.toString("yyyy-MM-dd hh-mm-ss");
	QString sDateTime=current_datetime.toString("yyyy-MM-dd");
	QString fileRecordPath = "..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\SaveData\\"+sDateTime+".csv";
	
	//判断文件是否存在
	bool bFileExist = false;
	QFileInfo fi(fileRecordPath);
	if (fi.isFile())//ligy 20200211 add.判断文件是否存在
	{
		bFileExist = true;
	}

	m_TestfileRecordData.setFileName(fileRecordPath);
	//ligy 20200211 add 打开文件
	if(!m_TestfileRecordData.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
	{
		//qDebug()<<"OPEN FILE FAILED";  
		return;
	}

	m_TestStreamRecordData.setDevice(&m_TestfileRecordData);

	if (!bFileExist)//如果文件不存在就写入文件头
	{
		//写入文件头
		m_TestStreamRecordData << g_pIni->m_strSaveDataParam1 
			<<"," << g_pIni->m_strSaveDataParam2 //"当前阶段(主控制流程)" 
			<<"," << g_pIni->m_strSaveDataParam3 //"当前阶段(作业流程)" 
			<<"," << g_pIni->m_strSaveDataParam4 //"作业速度(左测速轮)" 
			<<"," << g_pIni->m_strSaveDataParam5 //"作业速度(右测速轮)"
			<<"," << g_pIni->m_strSaveDataParam6 //"作业位置(左测速轮)" 
			<<"," << g_pIni->m_strSaveDataParam7 //"作业位置(右测速轮)"
			<<"," << g_pIni->m_strSaveDataParam8 //"垂向传感器1值(左)"
			<<"," << g_pIni->m_strSaveDataParam9 //"垂向传感器1值(右)" 
			<<"," << g_pIni->m_strSaveDataParam10 //"垂向传感器2值(左)"
			<<"," << g_pIni->m_strSaveDataParam11 //"垂向传感器2值(右)" 
			<<"," << g_pIni->m_strSaveDataParam12 //"横向传感器1值(左)" 
			<<"," << g_pIni->m_strSaveDataParam13 //"横向传感器1值(右)" 
			<<"," << g_pIni->m_strSaveDataParam14 //"横向传感器2值(左)" 
			<<"," << g_pIni->m_strSaveDataParam15 //"横向传感器2值(右)" 
			<<"," << g_pIni->m_strSaveDataParam16 //"垂向电机值(左)"
			<<"," << g_pIni->m_strSaveDataParam17 //"垂向电机值(右)"
			<<"," << g_pIni->m_strSaveDataParam18 //"横向电机值(左)"
			<<"," << g_pIni->m_strSaveDataParam19 //"横向电机值(右)"
			<<"," << g_pIni->m_strSaveDataParam20 //"垂向目标值(左)" 
			<<"," << g_pIni->m_strSaveDataParam21 //"垂向目标值(右)" 
			<<"," << g_pIni->m_strSaveDataParam22 //"横向目标值(左)" 
			<<"," << g_pIni->m_strSaveDataParam23 //"横向目标值(右)" 
			<<"," << g_pIni->m_strSaveDataParam24 //"垂向软件靴值(左)" 
			<<"," << g_pIni->m_strSaveDataParam25 //"垂向软件靴值(右)" 
			<<"," << g_pIni->m_strSaveDataParam26 //"横向软件靴值(左)" 
			<<"," << g_pIni->m_strSaveDataParam27 //"横向软件靴值(右)" 
			<<endl;
		m_TestStreamRecordData.flush();
	}

}

void GlobalData::DataProcessTest_WriteSaveData()//ligy 20200211 add 写需要存储的数据
{
	QDateTime current_date_time =QDateTime::currentDateTime();
	QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss zzz");

	QString plcWorkStatus;
	//判断当前工作状态,主控制流程
	switch(g->m_nPLCWorkState)
	{
	case PLC_WORKSTATE_WAITING:
		plcWorkStatus = g_pIni->m_strStateWaiting;//作业等待
		break;
	case PLC_WORKSTATE_READY:
		plcWorkStatus = g_pIni->m_strStateReady;//作业准备
		break;
	case PLC_WORKSTATE_SCAN:
		plcWorkStatus = g_pIni->m_strStateScan;//轨廓扫描
		break;
	case PLC_WORKSTATE_LOADDOWN1:
		plcWorkStatus = g_pIni->m_strStateLoadDown1;//装置下降1
		break;
	case PLC_WORKSTATE_STARTTRAIN1:
		plcWorkStatus = g_pIni->m_strStateStartTrain1;//列车启动1
		break;
	case PLC_WORKSTATE_STARTTRAIN2:
		plcWorkStatus = g_pIni->m_strStateStartTrain2;//列车启动2
		break;
	case PLC_WORKSTATE_STARTWORK:
		plcWorkStatus = g_pIni->m_strStateStartWork;//铣削作业
		break;
	case PLC_WORKSTATE_STOPWORK:
		plcWorkStatus = g_pIni->m_strStateStopWork;//作业停止
		break;
	case PLC_WORKSTATE_STOPTRAIN:
		plcWorkStatus = g_pIni->m_strStateStopTrain;//列车停止
		break;
	case PLC_WORKSTATE_LOADDOWN2:
		plcWorkStatus = g_pIni->m_strStateLoadDown2;//装置下降2
		break;
	case PLC_WORKSTATE_DEVICEUP:
		plcWorkStatus = g_pIni->m_strStateDeviceUp;//装置上升
		break;
	case PLC_WORKSTATE_EMERGENCY:
		plcWorkStatus = g_pIni->m_strStateEmergency;//紧急提升
		break;
	case PLC_WORKSTATE_REPAIR:
		plcWorkStatus = g_pIni->m_strStateRepair;//检修
		break;
	default:
		break;
	}

	QString workStatus;
	switch(m_nWorkState)
	{
	case WORKSTATE_STARTFELLOW_INI:
	case WORKSTATE_STARTFELLOW:
		workStatus = "开始跟随";
		break;
	case WORKSTATE_ADJUST_INI:
	case WORKSTATE_ADJUST :
		workStatus = "";
		break;
	case WORKSTATE_YFELLOW_INI :
	case WORKSTATE_YFELLOW  :
		workStatus = "Y向跟随";
		break;
	case WORKSTATE_WORKIN_INI  :
	case WORKSTATE_WORKIN   :
		workStatus = "开始铣削";
		break;
	case WORKSTATE_CUTIN_INI   :
	case WORKSTATE_CUTIN   :
		workStatus = "顺坡切入";
		break;
	case WORKSTATE_MILLING_INI    :
	case WORKSTATE_MILLING  :
		workStatus = "铣削作业";
		break;
	case WORKSTATE_CUTOUT_INI     :
	case WORKSTATE_CUTOUT  :
		workStatus = "顺坡切出";
		break;
	case WORKSTATE_WORKOUT_INI      :
	case WORKSTATE_WORKOUT   :
		workStatus = "停止铣削";
		break;
	case WORKSTATE_YFELLOW2_INI       :
	case WORKSTATE_YFELLOW2    :
		workStatus = "停止Y向跟随";
		break;
	case WORKSTATE_ENDFELLOW_INI        :
	case WORKSTATE_ENDFELLOW     :
		workStatus = "停止跟随";
		break;
	case WORKSTATE_EMERGENCY_PCU        :
	case WORKSTATE_EMERGENCY_PLC     :
		workStatus = "急停";
		break;
	default:
		workStatus = "";
		break;
	}
	m_TestStreamRecordData << current_date               //当前时间
		<<"," << workStatus                              //"当前阶段(主控制流程)" 
		<<"," << plcWorkStatus                           //"当前阶段(作业流程)" 开始跟随等状态
		<<"," << QString::number(g->m_L_SMWCurSpeed)     //"作业速度(左测速轮)" 
		<<"," << QString::number(g->m_R_SMWCurSpeed)     //"作业速度(右测速轮)" 
		<<"," << QString::number(g->m_L_SMWCurPos)       //"作业位置(左测速轮)" 
		<<"," << QString::number(g->m_R_SMWCurPos)       //"作业位置(右测速轮)" 
		<<"," << QString::number(g->m_LV_SensorCurValue1)//"垂向传感器1值(左)"  
		<<"," << QString::number(g->m_RV_SensorCurValue1)//"垂向传感器1值(右)"  
		<<"," << QString::number(g->m_LV_SensorCurValue2)//"垂向传感器2值(左)"  
		<<"," << QString::number(g->m_RV_SensorCurValue2)//"垂向传感器2值(右)"  
		<<"," << QString::number(g->m_LH_SensorCurValue1)//"横向传感器1值(左)"  
		<<"," << QString::number(g->m_RH_SensorCurValue1)//"横向传感器1值(右)"  
		<<"," << QString::number(g->m_LH_SensorCurValue2)//"横向传感器2值(左)"  
		<<"," << QString::number(g->m_RH_SensorCurValue2)//"横向传感器2值(右)"  
		<<"," << QString::number(g->m_LV_MotorCurPos)    //"垂向电机值(左)"     
		<<"," << QString::number(g->m_RV_MotorCurPos)    //"垂向电机值(右)"     
		<<"," << QString::number(g->m_LH_MotorCurPos)    //"横向电机值(左)"     
		<<"," << QString::number(g->m_RH_MotorCurPos)    //"横向电机值(右)"     
		<<"," << QString::number(g->m_LV_SensorDstValue) //"垂向目标值(左)"    
		<<"," << QString::number(g->m_RV_SensorDstValue) //"垂向目标值(右)"     
		<<"," << QString::number(g->m_LH_SensorDstValue) //"横向目标值(左)"     
		<<"," << QString::number(g->m_RH_SensorDstValue) //"横向目标值(右)"     
		<<"," << QString::number(g->m_LV_CurData.SensorValue)//"垂向软件靴值(左)"   
		<<"," << QString::number(m_RV_CurData.SensorValue)   //"垂向软件靴值(右)"   
		<<"," << QString::number(g->m_LH_CurData.SensorValue)//"横向软件靴值(左)"   
		<<"," << QString::number(g->m_RH_CurData.SensorValue)//"横向软件靴值(右)"   
		<<endl;
	m_TestStreamRecordData.flush();
}
void GlobalData::DataProcessTest_WriteFile()
{
	QDateTime current_date_time =QDateTime::currentDateTime();
	QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss zzz");

	PushDataToBuf( );
	//ProcessData( );
	PopDataFromBuf_SoftShoe_HV( );
	//PopDataFromBuf_Directly( );

	m_TestStreamRecord1 << current_date 
		<<"," << QString::number(m_L_SMWCurPos) 
		<<"," << QString::number(m_LH_SensorCurValue1) 
		<<"," << QString::number(m_LH_SensorCurValue2) 
		<<"," << QString::number(m_LV_SensorCurValue1)
		<<"," << QString::number(m_LV_SensorCurValue2) 
		<<"," << QString::number(m_R_SMWCurPos)
		<<"," << QString::number(m_RH_SensorCurValue1) 
		<<"," << QString::number(m_RH_SensorCurValue2) 
		<<"," << QString::number(m_RV_SensorCurValue1)
		<<"," << QString::number(m_RV_SensorCurValue2) 
		<<endl;
	m_TestStreamRecord1.flush();

	m_TestStreamRecord2 << current_date 
		<<"," << QString::number(m_LH_CurData.SMWPos) 
		<<"," << QString::number(m_LH_CurData.PureValue) 
		/*
		<<"," << QString::number(m_LH_SensorCurValue1) 
		<<"," << QString::number(m_LH_SensorCurValue2) 
		<<"," << QString::number(m_LH_CurData.SensorValue1) 
		<<"," << QString::number(m_LH_CurData.SensorValue2) 
		<<"," << QString::number(m_LH_CurData.SensorValue) 
		<<"," << QString::number(m_LH_CurData.RealPos1) 
		*/
		<<"," << QString::number(m_LV_CurData.SMWPos) 
		<<"," << QString::number(m_LV_CurData.PureValue)
		/*
		<<"," << QString::number(m_LV_SensorCurValue1)
		<<"," << QString::number(m_LV_SensorCurValue2) 
		<<"," << QString::number(m_LV_CurData.SensorValue1)
		<<"," << QString::number(m_LV_CurData.SensorValue2) 
		<<"," << QString::number(m_LV_CurData.SensorValue)
		<<"," << QString::number(m_LV_CurData.RealPos1) 
		*/
		<<"," << QString::number(m_RH_CurData.SMWPos)
		<<"," << QString::number(m_RH_CurData.PureValue) 
		/*
		<<"," << QString::number(m_RH_SensorCurValue1) 
		<<"," << QString::number(m_RH_SensorCurValue2) 
		<<"," << QString::number(m_RH_CurData.SensorValue1) 
		<<"," << QString::number(m_RH_CurData.SensorValue2) 
		<<"," << QString::number(m_RH_CurData.SensorValue) 
		<<"," << QString::number(m_RH_CurData.RealPos1) 
		*/
		<<"," << QString::number(m_RV_CurData.SMWPos)
		<<"," << QString::number(m_RV_CurData.PureValue)
		/*
		<<"," << QString::number(m_RV_SensorCurValue1)
		<<"," << QString::number(m_RV_SensorCurValue2) 
		<<"," << QString::number(m_RV_CurData.SensorValue1) 
		<<"," << QString::number(m_RV_CurData.SensorValue2)
		<<"," << QString::number(m_RV_CurData.SensorValue) 
		<<"," << QString::number(m_RV_CurData.RealPos1) 
		*/
		<<endl;
	m_TestStreamRecord2.flush();

	m_LH_PreData = m_LH_CurData;
	m_LV_PreData = m_LV_CurData;
	m_RH_PreData = m_RH_CurData;
	m_RV_PreData = m_RV_CurData;
}

void GlobalData::DataProcessTest_WriteFileFini()
{
	//ligy 20200210 add 关闭文件
	m_TestfileRecord1.close();
	m_TestfileRecord2.close();
}

void GlobalData::DataProcessTest_WriteSaveDataFini()
{
	//ligy 20200211 add 关闭文件
	m_TestfileRecordData.close();
}

void GlobalData::PushDataToBuf( )
{
	/*
	// read data
	SlCapErrorEnum eError = m_capGDServerRead.multiRead(m_vecGDReadSpec, m_vecGDReadResult);
	// write success or error to the status bar
	handleRetVal(eError);

	m_LH_SensorCurValue1 = m_vecGDReadResult[0].m_vValue.toDouble();
	m_LV_SensorCurValue1 = m_vecGDReadResult[1].m_vValue.toDouble();
	m_LH_SensorCurValue2 = m_vecGDReadResult[2].m_vValue.toDouble();
	m_LV_SensorCurValue2 = m_vecGDReadResult[3].m_vValue.toDouble();
	m_LH_MotorCurPos = m_vecGDReadResult[4].m_vValue.toDouble();
	m_LV_MotorCurPos = m_vecGDReadResult[5].m_vValue.toDouble();
	m_L_SMWCurPos = m_vecGDReadResult[6].m_vValue.toDouble();

	m_RH_SensorCurValue1 = m_vecGDReadResult[7].m_vValue.toDouble();
	m_RV_SensorCurValue1 = m_vecGDReadResult[8].m_vValue.toDouble();
	m_RH_SensorCurValue2 = m_vecGDReadResult[9].m_vValue.toDouble();
	m_RV_SensorCurValue2 = m_vecGDReadResult[10].m_vValue.toDouble();
	m_RH_MotorCurPos = m_vecGDReadResult[11].m_vValue.toDouble();
	m_RV_MotorCurPos = m_vecGDReadResult[12].m_vValue.toDouble();
	m_R_SMWCurPos = m_vecGDReadResult[13].m_vValue.toDouble();
	*/
	GDB	LH_GroupData,LV_GroupData,RH_GroupData,RV_GroupData;

	LH_GroupData.SensorValue1 = m_LH_SensorCurValue1;
	LH_GroupData.SensorValue2 = m_LH_SensorCurValue2;
	//LH_GroupData.bEdgeMark1 = fabs(m_LH_EdgeMark1) < 1E-10 ? false:true;
	//LH_GroupData.bEdgeMark2 = fabs(m_LH_EdgeMark2) < 1E-10 ? false:true;
	//LH_GroupData.EdgeIndex = m_LH_EdgeIndex;
	LH_GroupData.SMWPos = m_L_SMWCurPos;
	LH_GroupData.nWorkState = m_nWorkState;
	LH_GroupData.SensorValue = m_LH_SensorCurValue1*m_LH_SensorRatio+m_LH_SensorCurValue2*(1-m_LH_SensorRatio);
	LH_GroupData.PureValue = LH_GroupData.SensorValue;
	LH_GroupData.Org_SensorValue = LH_GroupData.SensorValue;
	LH_GroupData.MotorPos = m_LH_MotorCurPos;
	LH_GroupData.RealPos1 = -(LH_GroupData.MotorPos + LH_GroupData.SensorValue1);
	LH_GroupData.RealPos2 = -(LH_GroupData.MotorPos + LH_GroupData.SensorValue2);

	LV_GroupData.SensorValue1 = m_LV_SensorCurValue1;
	LV_GroupData.SensorValue2 = m_LV_SensorCurValue2;
	//LV_GroupData.bEdgeMark1 = fabs(m_LV_EdgeMark1) < 1E-10 ? false:true;
	//LV_GroupData.bEdgeMark2 = fabs(m_LV_EdgeMark2) < 1E-10 ? false:true;
	//LV_GroupData.EdgeIndex = m_LV_EdgeIndex;
	LV_GroupData.SMWPos = m_L_SMWCurPos;
	LV_GroupData.nWorkState = m_nWorkState;
	LV_GroupData.SensorValue = m_LV_SensorCurValue1*m_LV_SensorRatio+m_LV_SensorCurValue2*(1-m_LV_SensorRatio);
	LV_GroupData.PureValue = LV_GroupData.SensorValue;
	LV_GroupData.Org_SensorValue = LV_GroupData.SensorValue;
	LV_GroupData.MotorPos = m_LV_MotorCurPos;
	LV_GroupData.RealPos1 = -(LV_GroupData.MotorPos + LV_GroupData.SensorValue1);
	LV_GroupData.RealPos2 = -(LV_GroupData.MotorPos + LV_GroupData.SensorValue2);

	RH_GroupData.SensorValue1 = m_RH_SensorCurValue1;
	RH_GroupData.SensorValue2 = m_RH_SensorCurValue2;
	//RH_GroupData.bEdgeMark1 = fabs(m_RH_EdgeMark1) < 1E-10 ? false:true;
	//RH_GroupData.bEdgeMark2 = fabs(m_RH_EdgeMark2) < 1E-10 ? false:true;
	//RH_GroupData.EdgeIndex = m_RH_EdgeIndex;
	RH_GroupData.SMWPos = m_R_SMWCurPos;
	RH_GroupData.nWorkState = m_nWorkState;
	RH_GroupData.SensorValue = m_RH_SensorCurValue1*m_RH_SensorRatio+m_RH_SensorCurValue2*(1-m_RH_SensorRatio);
	RH_GroupData.PureValue = RH_GroupData.SensorValue;
	RH_GroupData.Org_SensorValue = RH_GroupData.SensorValue;
	RH_GroupData.MotorPos = m_RH_MotorCurPos;
	RH_GroupData.RealPos1 = -(RH_GroupData.MotorPos + RH_GroupData.SensorValue1);
	RH_GroupData.RealPos2 = -(RH_GroupData.MotorPos + RH_GroupData.SensorValue2);

	RV_GroupData.SensorValue1 = m_RV_SensorCurValue1;
	RV_GroupData.SensorValue2 = m_RV_SensorCurValue2;
	//RV_GroupData.bEdgeMark1 = fabs(m_RV_EdgeMark1) < 1E-10 ? false:true;
	//RV_GroupData.bEdgeMark2 = fabs(m_RV_EdgeMark2) < 1E-10 ? false:true;
	//RV_GroupData.EdgeIndex = m_RV_EdgeIndex;
	RV_GroupData.SMWPos = m_R_SMWCurPos;
	RV_GroupData.nWorkState = m_nWorkState;
	RV_GroupData.SensorValue = m_RV_SensorCurValue1*m_RV_SensorRatio+m_RV_SensorCurValue2*(1-m_RV_SensorRatio);
	RV_GroupData.PureValue = RV_GroupData.SensorValue;
	RV_GroupData.Org_SensorValue = RV_GroupData.SensorValue;
	RV_GroupData.MotorPos = m_RV_MotorCurPos;
	RV_GroupData.RealPos1 = -(RV_GroupData.MotorPos + RV_GroupData.SensorValue1);
	RV_GroupData.RealPos2 = -(RV_GroupData.MotorPos + RV_GroupData.SensorValue2);

	m_LH_GroupData.append(LH_GroupData);
	m_LV_GroupData.append(LV_GroupData);
	m_RH_GroupData.append(RH_GroupData);
	m_RV_GroupData.append(RV_GroupData);
}

bool GlobalData::PopDataFromBuf_Directly( )
{
	int LH_Index=0 , LV_Index=0 , RH_Index=0 , RV_Index=0 ;
	int LH_Len = 0 , LV_Len = 0 , RH_Len = 0 , RV_Len = 0 ;
	int LH_Back= 8 , LV_Back= 8 , RH_Back= 8 , RV_Back= 8 ;
	int LH_iVectorSize = m_LH_GroupData.count( );
	int LV_iVectorSize = m_LV_GroupData.count( );
	int RH_iVectorSize = m_RH_GroupData.count( );
	int RV_iVectorSize = m_RV_GroupData.count( );

	//---------------------------------------------------------------------
	//LH_Back,RH_Back,LV_Back,RV_Back,Same as PopDataFromBuf_SoftShoe_HV( )
	//---------------------------------------------------------------------
	int LV_HalfSoftShoe, RV_HalfSoftShoe,LH_HalfSoftShoe, RH_HalfSoftShoe;
	//double iHalfSoftShoeLen_H = 0.07;
	//double iHalfSoftShoeLen_V = 0.15;
	int iTmpSoftShoeLen_H = int(m_H_SoftShoeLen/1000/m_DstTrainSpeed*3600/1000*20) ;
	int iTmpSoftShoeLen_V = int(m_V_SoftShoeLen/1000/m_DstTrainSpeed*3600/1000*20) ;

	LH_HalfSoftShoe = RH_HalfSoftShoe = iTmpSoftShoeLen_H < 5 ? 5 : iTmpSoftShoeLen_H;
	LV_HalfSoftShoe = RV_HalfSoftShoe = iTmpSoftShoeLen_V < 5 ? 5 : iTmpSoftShoeLen_V;
	LH_Back = RH_Back = LH_HalfSoftShoe + 5;
	LV_Back = RV_Back = LV_HalfSoftShoe + 5;

	//-------------------LH Unit----------------------
	if( LH_iVectorSize > 1 ){
		//Step1:Generated!
		m_LH_CurData = m_LH_GroupData.at(LH_iVectorSize-1);
		LH_Index = LH_iVectorSize-1;
		//Step2:Deleted!
		LH_Len = ( LH_Index - LH_Back  < 0 ) ? 0 : LH_Index - LH_Back;
		if(LH_Len > 0)
			m_LH_GroupData.remove(0,LH_Len);
	}
	else if(LH_iVectorSize == 1){
		m_LH_CurData = m_LH_GroupData.at(0);
		LH_Index = 0;
	}
	else{
		return false;
	}
	//-------------------LV Unit----------------------
	if( LV_iVectorSize > 1 ){
		//Step1:Generated!
		m_LV_CurData = m_LV_GroupData.at(LV_iVectorSize-1);
		LV_Index = LV_iVectorSize-1;
		//Step2:Deleted!
		LV_Len = ( LV_Index - LV_Back  < 0 ) ? 0 : LV_Index - LV_Back;
		if(LV_Len > 0)
			m_LV_GroupData.remove(0,LV_Len);
	}
	else if( LV_iVectorSize == 1 ){
		m_LV_CurData = m_LV_GroupData.at(0);
		LV_Index = 0;
	}
	else{
		return false;
	}
	//-------------------RH Unit----------------------
	if( RH_iVectorSize > 1 ){
		//Step1:Generated!
		m_RH_CurData = m_RH_GroupData.at(RH_iVectorSize-1);
		RH_Index = RH_iVectorSize-1;
		//Step2:Deleted!
		RH_Len = ( RH_Index - RH_Back  < 0 ) ? 0 : RH_Index - RH_Back;
		if(RH_Len > 0)
			m_RH_GroupData.remove(0,RH_Len);
	}
	else if( RH_iVectorSize == 1 ){
		m_RH_CurData = m_RH_GroupData.at(0);
		RH_Index = 0;
	}
	else{
		return false;
	}
	//-------------------RV Unit----------------------
	if( RV_iVectorSize > 1 ){
		//Step1:Generated!
		m_RV_CurData = m_RV_GroupData.at(RV_iVectorSize-1);
		RV_Index = RV_iVectorSize-1;
		//Step2:Deleted!
		RV_Len = ( RV_Index - RV_Back  < 0 ) ? 0 : RV_Index - RV_Back;
		if(RV_Len > 0)
			m_RV_GroupData.remove(0,RV_Len);
	}
	else if( RV_iVectorSize == 1 ){
		m_RV_CurData = m_RV_GroupData.at(0);
		RV_Index = 0;
	}
	else{
		return false;
	}
	return true;
}

bool GlobalData::PopDataFromBuf_SoftShoe_HV( )
{
	int LH_Index=0 , LV_Index=0 , RH_Index=0 , RV_Index=0 ;
	int LH_Len = 0 , LV_Len = 0 , RH_Len = 0 , RV_Len = 0 ;
	int LH_Back= 6 , LV_Back= 15, RH_Back= 6 , RV_Back= 15 ;
	int LH_iVectorSize = m_LH_GroupData.count( );
	int LV_iVectorSize = m_LV_GroupData.count( );
	int RH_iVectorSize = m_RH_GroupData.count( );
	int RV_iVectorSize = m_RV_GroupData.count( );
	//---------------------------------------------------------------------
	//LH_Back,RH_Back,LV_Back,RV_Back,Same as PopDataFromBuf_SoftShoe_HV( )
	//---------------------------------------------------------------------
	int LV_HalfSoftShoe, RV_HalfSoftShoe,LH_HalfSoftShoe, RH_HalfSoftShoe;
	int iTmpSoftShoeLen_H = m_H_SoftShoePoints;		//int(m_H_SoftShoeLen/1000/m_DstTrainSpeed*3600/1000*20) ;
	int iTmpSoftShoeLen_V = m_V_SoftShoePoints;		//int(m_V_SoftShoeLen/1000/m_DstTrainSpeed*3600/1000*20) ;
	double SensorValueF1,SensorValueR1,SensorValueF2,SensorValueR2;
	double *LH_FMaxVal1,*LH_RMaxVal1,*LH_FMaxVal2,*LH_RMaxVal2;
	double *RH_FMaxVal1,*RH_RMaxVal1,*RH_FMaxVal2,*RH_RMaxVal2;
	double *LV_FMaxVal1,*LV_RMaxVal1,*LV_FMaxVal2,*LV_RMaxVal2;
	double *RV_FMaxVal1,*RV_RMaxVal1,*RV_FMaxVal2,*RV_RMaxVal2;

	double *LH_FilterData1,*LH_FilterData2,*LV_FilterData1,*LV_FilterData2;
	double *RH_FilterData1,*RH_FilterData2,*RV_FilterData1,*RV_FilterData2;
	double f_Midean1,f_Midean2;

	LH_HalfSoftShoe = RH_HalfSoftShoe = iTmpSoftShoeLen_H < 5 ? 5 : iTmpSoftShoeLen_H;
	LV_HalfSoftShoe = RV_HalfSoftShoe = iTmpSoftShoeLen_V < 5 ? 5 : iTmpSoftShoeLen_V;
	LH_Back = RH_Back = LH_HalfSoftShoe + 5;
	LV_Back = RV_Back = LV_HalfSoftShoe + 5;

	int MAX_VECTOR_LEN = 256;
	//-------------------LH Unit----------------------
	if( LH_iVectorSize > m_H_SoftShoeLayer ){
		//------------------------------------------------------
		//Step1:Generated!
		if( m_H_bLowPassFilter )
		{
			int i = LH_iVectorSize-1;
			m_LH_CurData = m_LH_GroupData.at(i);
			int iStart = i-LH_HalfSoftShoe < 0 ? 0 : i-LH_HalfSoftShoe;
			int iEnd = i+LH_HalfSoftShoe > LH_iVectorSize-1 ? LH_iVectorSize-1 : i+LH_HalfSoftShoe;

			int iLen = iEnd - iStart + 1;
			LH_FilterData1 = new double[iLen];
			LH_FilterData2 = new double[iLen];
			int k = 0;
			for(int j=iStart; j<=iEnd ; j++)
			{
				LH_FilterData1[k] = m_LH_GroupData.at(j).RealPos1;
				LH_FilterData2[k] = m_LH_GroupData.at(j).RealPos2;
				k++;
			}
			//f_Midean1 = qQuickMedian(LH_FilterData1,iLen);
			//f_Midean2 = qQuickMedian(LH_FilterData2,iLen);
			qQuickMedianGroup( LH_FilterData1, LH_FilterData2, iLen,f_Midean1,f_Midean2 );

			m_LH_CurData.SensorValue1 = m_LH_CurData.SensorValue1 - (f_Midean1 - m_LH_CurData.RealPos1);
			m_LH_CurData.SensorValue2 = m_LH_CurData.SensorValue2 - (f_Midean2 - m_LH_CurData.RealPos2);
			m_LH_CurData.SensorValue = m_LH_CurData.SensorValue1*m_LH_SensorRatio+m_LH_CurData.SensorValue2*(1-m_LH_SensorRatio);
			m_LH_CurData.PureValue = m_LH_CurData.SensorValue;

			LH_Index = i;
			//Important!!!!,Smoth the SensorValue
			m_LH_CurData.SensorValue = m_LH_CurData.SensorValue*m_H_SoftShoeAlph+m_LH_PreData.SensorValue*(1-m_H_SoftShoeAlph);

			//-----End----
			delete [] LH_FilterData1;		LH_FilterData1 = NULL;
			delete [] LH_FilterData2;		LH_FilterData2 = NULL;
		}
		else
		{
			LH_FMaxVal1 = new double[m_H_SoftShoeLayer];
			LH_RMaxVal1 = new double[m_H_SoftShoeLayer];
			LH_FMaxVal2 = new double[m_H_SoftShoeLayer];
			LH_RMaxVal2 = new double[m_H_SoftShoeLayer];

			int i = LH_iVectorSize-1;
			m_LH_CurData = m_LH_GroupData.at(i);
			int iStart = i-LH_HalfSoftShoe < 0 ? 0 : i-LH_HalfSoftShoe;
			int iEnd = i+LH_HalfSoftShoe > LH_iVectorSize-1 ? LH_iVectorSize-1 : i+LH_HalfSoftShoe;
			//int EdgeIndex = m_LH_CurData.EdgeIndex;

			int iStep = m_H_SoftShoeLayer;
			for(int k=0 ; k<iStep ; k++){
				LH_FMaxVal1[k] = -1E10;
				LH_RMaxVal1[k] = 1E10;
				LH_FMaxVal2[k] = -1E10;
				LH_RMaxVal2[k] = 1E10;
				for(int j=iStart+k ; j<=iEnd ; j+=iStep){
					//if( EdgeIndex == m_LH_GroupData.at(j).EdgeIndex )
					{
						double RealPos1 = m_LH_GroupData.at(j).RealPos1;
						double RealPos2 = m_LH_GroupData.at(j).RealPos2;
						if(LH_FMaxVal1[k] < RealPos1)
							LH_FMaxVal1[k] = RealPos1;
						if(LH_RMaxVal1[k] > RealPos1)
							LH_RMaxVal1[k] = RealPos1;
						if(LH_FMaxVal2[k] < RealPos2)
							LH_FMaxVal2[k] = RealPos2;
						if(LH_RMaxVal2[k] > RealPos2)
							LH_RMaxVal2[k] = RealPos2;
					}
				}
			}
			double FMinVal1 = 1E10;
			double RMinVal1 = -1E10;
			double FMinVal2 = 1E10;
			double RMinVal2 = -1E10;
			for(int k=0 ; k<iStep ; k++){
				if(FMinVal1 > LH_FMaxVal1[k])
					FMinVal1 = LH_FMaxVal1[k];
				if(RMinVal1 < LH_RMaxVal1[k])
					RMinVal1 = LH_RMaxVal1[k];
				if(FMinVal2 > LH_FMaxVal2[k])
					FMinVal2 = LH_FMaxVal2[k];
				if(RMinVal2 < LH_RMaxVal2[k])
					RMinVal2 = LH_RMaxVal2[k];
			}

			SensorValueF1 = m_LH_CurData.SensorValue1 - (FMinVal1 - m_LH_CurData.RealPos1);
			SensorValueR1 = m_LH_CurData.SensorValue1 - (RMinVal1 - m_LH_CurData.RealPos1);
			SensorValueF2 = m_LH_CurData.SensorValue2 - (FMinVal2 - m_LH_CurData.RealPos2);
			SensorValueR2 = m_LH_CurData.SensorValue2 - (RMinVal2 - m_LH_CurData.RealPos2);
			
			m_LH_CurData.SensorValue1 = SensorValueF1*m_H_SoftShoeDirRatio1+SensorValueR1*(1-m_H_SoftShoeDirRatio1);
			m_LH_CurData.SensorValue2 = SensorValueF2*m_H_SoftShoeDirRatio2+SensorValueR2*(1-m_H_SoftShoeDirRatio2);
			m_LH_CurData.SensorValue = m_LH_CurData.SensorValue1*m_LH_SensorRatio+m_LH_CurData.SensorValue2*(1-m_LH_SensorRatio);
			m_LH_CurData.PureValue = m_LH_CurData.SensorValue;

			LH_Index = i;
			//Important!!!!,Smoth the SensorValue
			m_LH_CurData.SensorValue = m_LH_CurData.SensorValue*m_H_SoftShoeAlph+m_LH_PreData.SensorValue*(1-m_H_SoftShoeAlph);

			//-----End----
			delete [] LH_FMaxVal1;		LH_FMaxVal1 = NULL;
			delete [] LH_RMaxVal1;		LH_RMaxVal1 = NULL;
			delete [] LH_FMaxVal2;		LH_FMaxVal2 = NULL;
			delete [] LH_RMaxVal2;		LH_RMaxVal2 = NULL;
		}
		//------------------------------------------------------
		//Step2:Deleted!
		if(LH_Index != 0){
			LH_Len = ( LH_Index - LH_Back  < 0 ) ? 0 : LH_Index - LH_Back;
			if(LH_Len > 0)
				m_LH_GroupData.remove(0,LH_Len);
		}
		else{
			//LH_Index = LH_iVectorSize-1;
			LH_Index = 0;
			m_LH_CurData = m_LH_GroupData.at(LH_Index);
			//MaxVector Length Limited!
			if( LH_iVectorSize > MAX_VECTOR_LEN ){
				m_LH_GroupData.remove(0,LH_iVectorSize-MAX_VECTOR_LEN);
			}
		}
		//------------------------------------------------------
	}
	else if(LH_iVectorSize >= 1){
		m_LH_CurData = m_LH_GroupData.at(LH_iVectorSize-1);
		LH_Index = LH_iVectorSize-1;
	}
	else{
		return false;
	}
	
	//-------------------LV Unit----------------------
	if( LV_iVectorSize > m_V_SoftShoeLayer ){
		//------------------------------------------------------
		//Step1:Generated!
		if( m_V_bLowPassFilter )
		{
			int i = LV_iVectorSize-1;
			m_LV_CurData = m_LV_GroupData.at(i);
			int iStart = i-LV_HalfSoftShoe < 0 ? 0 : i-LV_HalfSoftShoe;
			int iEnd = i+LV_HalfSoftShoe > LV_iVectorSize-1 ? LV_iVectorSize-1 : i+LV_HalfSoftShoe;

			int iLen = iEnd - iStart + 1;
			LV_FilterData1 = new double[iLen];
			LV_FilterData2 = new double[iLen];
			int k = 0;
			for(int j=iStart; j<=iEnd ; j++)
			{
				LV_FilterData1[k] = m_LV_GroupData.at(j).RealPos1;
				LV_FilterData2[k] = m_LV_GroupData.at(j).RealPos2;
				k++;
			}
			//f_Midean1 = qQuickMedian(LV_FilterData1,iLen);
			//f_Midean2 = qQuickMedian(LV_FilterData2,iLen);
			qQuickMedianGroup( LV_FilterData1, LV_FilterData2, iLen,f_Midean1,f_Midean2 );

			m_LV_CurData.SensorValue1 = m_LV_CurData.SensorValue1 - (f_Midean1 - m_LV_CurData.RealPos1);
			m_LV_CurData.SensorValue2 = m_LV_CurData.SensorValue2 - (f_Midean2 - m_LV_CurData.RealPos2);
			m_LV_CurData.SensorValue = m_LV_CurData.SensorValue1*m_LV_SensorRatio+m_LV_CurData.SensorValue2*(1-m_LV_SensorRatio);
			m_LV_CurData.PureValue = m_LV_CurData.SensorValue;

			LV_Index = i;
			//Important!!!!,Smoth the SensorValue
			m_LV_CurData.SensorValue = m_LV_CurData.SensorValue*m_V_SoftShoeAlph+m_LV_PreData.SensorValue*(1-m_V_SoftShoeAlph);

			//-----End----
			delete [] LV_FilterData1;		LV_FilterData1 = NULL;
			delete [] LV_FilterData2;		LV_FilterData2 = NULL;
		}
		else
		{
			LV_FMaxVal1 = new double[m_V_SoftShoeLayer];
			LV_RMaxVal1 = new double[m_V_SoftShoeLayer];
			LV_FMaxVal2 = new double[m_V_SoftShoeLayer];
			LV_RMaxVal2 = new double[m_V_SoftShoeLayer];

			int i = LV_iVectorSize-1;
			m_LV_CurData = m_LV_GroupData.at(i);
			int iStart = i-LV_HalfSoftShoe < 0 ? 0 : i-LV_HalfSoftShoe;
			int iEnd = i+LV_HalfSoftShoe > LV_iVectorSize-1 ? LV_iVectorSize-1 : i+LV_HalfSoftShoe;
			//int EdgeIndex = m_LV_CurData.EdgeIndex;

			int iStep = m_V_SoftShoeLayer;
			for(int k=0 ; k<iStep ; k++){
				LV_FMaxVal1[k] = -1E10;
				LV_RMaxVal1[k] = 1E10;
				LV_FMaxVal2[k] = -1E10;
				LV_RMaxVal2[k] = 1E10;
				for(int j=iStart+k ; j<=iEnd ; j+=iStep){
					//if( EdgeIndex == m_LV_GroupData.at(j).EdgeIndex )
					{
						double RealPos1 = m_LV_GroupData.at(j).RealPos1;
						double RealPos2 = m_LV_GroupData.at(j).RealPos2;
						if(LV_FMaxVal1[k] < RealPos1)
							LV_FMaxVal1[k] = RealPos1;
						if(LV_RMaxVal1[k] > RealPos1)
							LV_RMaxVal1[k] = RealPos1;
						if(LV_FMaxVal2[k] < RealPos2)
							LV_FMaxVal2[k] = RealPos2;
						if(LV_RMaxVal2[k] > RealPos2)
							LV_RMaxVal2[k] = RealPos2;
					}
				}
			}
			double FMinVal1 = 1E10;
			double RMinVal1 = -1E10;
			double FMinVal2 = 1E10;
			double RMinVal2 = -1E10;
			for(int k=0 ; k<iStep ; k++){
				if(FMinVal1 > LV_FMaxVal1[k])
					FMinVal1 = LV_FMaxVal1[k];
				if(RMinVal1 < LV_RMaxVal1[k])
					RMinVal1 = LV_RMaxVal1[k];
				if(FMinVal2 > LV_FMaxVal2[k])
					FMinVal2 = LV_FMaxVal2[k];
				if(RMinVal2 < LV_RMaxVal2[k])
					RMinVal2 = LV_RMaxVal2[k];
			}

			SensorValueF1 = m_LV_CurData.SensorValue1 - (FMinVal1 - m_LV_CurData.RealPos1);
			SensorValueR1 = m_LV_CurData.SensorValue1 - (RMinVal1 - m_LV_CurData.RealPos1);
			SensorValueF2 = m_LV_CurData.SensorValue2 - (FMinVal2 - m_LV_CurData.RealPos2);
			SensorValueR2 = m_LV_CurData.SensorValue2 - (RMinVal2 - m_LV_CurData.RealPos2);
			
			m_LV_CurData.SensorValue1 = SensorValueF1*m_V_SoftShoeDirRatio1+SensorValueR1*(1-m_V_SoftShoeDirRatio1);
			m_LV_CurData.SensorValue2 = SensorValueF2*m_V_SoftShoeDirRatio2+SensorValueR2*(1-m_V_SoftShoeDirRatio2);
			m_LV_CurData.SensorValue = m_LV_CurData.SensorValue1*m_LV_SensorRatio+m_LV_CurData.SensorValue2*(1-m_LV_SensorRatio);
			m_LV_CurData.PureValue = m_LV_CurData.SensorValue;

			LV_Index = i;
			//Important!!!!,Smoth the SensorValue
			m_LV_CurData.SensorValue = m_LV_CurData.SensorValue*m_V_SoftShoeAlph+m_LV_PreData.SensorValue*(1-m_V_SoftShoeAlph);

			//-----End----
			delete [] LV_FMaxVal1;		LV_FMaxVal1 = NULL;
			delete [] LV_RMaxVal1;		LV_RMaxVal1 = NULL;
			delete [] LV_FMaxVal2;		LV_FMaxVal2 = NULL;
			delete [] LV_RMaxVal2;		LV_RMaxVal2 = NULL;
		}
		//------------------------------------------------------
		//Step2:Deleted!
		if(LV_Index != 0){
			LV_Len = ( LV_Index - LV_Back  < 0 ) ? 0 : LV_Index - LV_Back;
			if(LV_Len > 0)
				m_LV_GroupData.remove(0,LV_Len);
		}
		else{
			//LV_Index = LV_iVectorSize-1;
			LV_Index = 0;
			m_LV_CurData = m_LV_GroupData.at(LV_Index);
			//MaxVector Length Limited!
			if( LV_iVectorSize > MAX_VECTOR_LEN ){
				m_LV_GroupData.remove(0,LV_iVectorSize-MAX_VECTOR_LEN);
			}
		}
		//------------------------------------------------------
	}
	else if( LV_iVectorSize >= 1 ){
		m_LV_CurData = m_LV_GroupData.at(LV_iVectorSize-1);
		LV_Index = LV_iVectorSize-1;
	}
	else{
		return false;
	}
	
	//-------------------RH Unit----------------------
	if( RH_iVectorSize > m_H_SoftShoeLayer ){
		//------------------------------------------------------
		//Step1:Generated!
		if( m_H_bLowPassFilter )
		{
			int i = RH_iVectorSize-1;
			m_RH_CurData = m_RH_GroupData.at(i);
			int iStart = i-RH_HalfSoftShoe < 0 ? 0 : i-RH_HalfSoftShoe;
			int iEnd = i+RH_HalfSoftShoe > RH_iVectorSize-1 ? RH_iVectorSize-1 : i+RH_HalfSoftShoe;

			int iLen = iEnd - iStart + 1;
			RH_FilterData1 = new double[iLen];
			RH_FilterData2 = new double[iLen];
			int k = 0;
			for(int j=iStart; j<=iEnd ; j++)
			{
				RH_FilterData1[k] = m_RH_GroupData.at(j).RealPos1;
				RH_FilterData2[k] = m_RH_GroupData.at(j).RealPos2;
				k++;
			}
			//f_Midean1 = qQuickMedian(RH_FilterData1,iLen);
			//f_Midean2 = qQuickMedian(RH_FilterData2,iLen);
			qQuickMedianGroup( RH_FilterData1, RH_FilterData2, iLen,f_Midean1,f_Midean2 );

			m_RH_CurData.SensorValue1 = m_RH_CurData.SensorValue1 - (f_Midean1 - m_RH_CurData.RealPos1);
			m_RH_CurData.SensorValue2 = m_RH_CurData.SensorValue2 - (f_Midean2 - m_RH_CurData.RealPos2);
			m_RH_CurData.SensorValue = m_RH_CurData.SensorValue1*m_RH_SensorRatio+m_RH_CurData.SensorValue2*(1-m_RH_SensorRatio);
			m_RH_CurData.PureValue = m_RH_CurData.SensorValue;

			RH_Index = i;
			//Important!!!!,Smoth the SensorValue
			m_RH_CurData.SensorValue = m_RH_CurData.SensorValue*m_H_SoftShoeAlph+m_RH_PreData.SensorValue*(1-m_H_SoftShoeAlph);

			//-----End----
			delete [] RH_FilterData1;		RH_FilterData1 = NULL;
			delete [] RH_FilterData2;		RH_FilterData2 = NULL;
		}
		else
		{
			RH_FMaxVal1 = new double[m_H_SoftShoeLayer];
			RH_RMaxVal1 = new double[m_H_SoftShoeLayer];
			RH_FMaxVal2 = new double[m_H_SoftShoeLayer];
			RH_RMaxVal2 = new double[m_H_SoftShoeLayer];

			int i = RH_iVectorSize-1;
			m_RH_CurData = m_RH_GroupData.at(i);
			int iStart = i-RH_HalfSoftShoe < 0 ? 0 : i-RH_HalfSoftShoe;
			int iEnd = i+RH_HalfSoftShoe > RH_iVectorSize-1 ? RH_iVectorSize-1 : i+RH_HalfSoftShoe;
			//int EdgeIndex = m_RH_CurData.EdgeIndex;

			int iStep = m_H_SoftShoeLayer;
			for(int k=0 ; k<iStep ; k++){
				RH_FMaxVal1[k] = -1E10;
				RH_RMaxVal1[k] = 1E10;
				RH_FMaxVal2[k] = -1E10;
				RH_RMaxVal2[k] = 1E10;
				for(int j=iStart+k ; j<=iEnd ; j+=iStep){
					//if( EdgeIndex == m_RH_GroupData.at(j).EdgeIndex )
					{
						double RealPos1 = m_RH_GroupData.at(j).RealPos1;
						double RealPos2 = m_RH_GroupData.at(j).RealPos2;
						if(RH_FMaxVal1[k] < RealPos1)
							RH_FMaxVal1[k] = RealPos1;
						if(RH_RMaxVal1[k] > RealPos1)
							RH_RMaxVal1[k] = RealPos1;
						if(RH_FMaxVal2[k] < RealPos2)
							RH_FMaxVal2[k] = RealPos2;
						if(RH_RMaxVal2[k] > RealPos2)
							RH_RMaxVal2[k] = RealPos2;
					}
				}
			}
			double FMinVal1 = 1E10;
			double RMinVal1 = -1E10;
			double FMinVal2 = 1E10;
			double RMinVal2 = -1E10;
			for(int k=0 ; k<iStep ; k++){
				if(FMinVal1 > RH_FMaxVal1[k])
					FMinVal1 = RH_FMaxVal1[k];
				if(RMinVal1 < RH_RMaxVal1[k])
					RMinVal1 = RH_RMaxVal1[k];
				if(FMinVal2 > RH_FMaxVal2[k])
					FMinVal2 = RH_FMaxVal2[k];
				if(RMinVal2 < RH_RMaxVal2[k])
					RMinVal2 = RH_RMaxVal2[k];
			}

			SensorValueF1 = m_RH_CurData.SensorValue1 - (FMinVal1 - m_RH_CurData.RealPos1);
			SensorValueR1 = m_RH_CurData.SensorValue1 - (RMinVal1 - m_RH_CurData.RealPos1);
			SensorValueF2 = m_RH_CurData.SensorValue2 - (FMinVal2 - m_RH_CurData.RealPos2);
			SensorValueR2 = m_RH_CurData.SensorValue2 - (RMinVal2 - m_RH_CurData.RealPos2);
			
			m_RH_CurData.SensorValue1 = SensorValueF1*m_H_SoftShoeDirRatio1+SensorValueR1*(1-m_H_SoftShoeDirRatio1);
			m_RH_CurData.SensorValue2 = SensorValueF2*m_H_SoftShoeDirRatio2+SensorValueR2*(1-m_H_SoftShoeDirRatio2);
			m_RH_CurData.SensorValue = m_RH_CurData.SensorValue1*m_RH_SensorRatio+m_RH_CurData.SensorValue2*(1-m_RH_SensorRatio);
			m_RH_CurData.PureValue = m_RH_CurData.SensorValue;

			RH_Index = i;
			//Important!!!!,Smoth the SensorValue
			m_RH_CurData.SensorValue = m_RH_CurData.SensorValue*m_H_SoftShoeAlph+m_RH_PreData.SensorValue*(1-m_H_SoftShoeAlph);

			//-----End----
			delete [] RH_FMaxVal1;		RH_FMaxVal1 = NULL;
			delete [] RH_RMaxVal1;		RH_RMaxVal1 = NULL;
			delete [] RH_FMaxVal2;		RH_FMaxVal2 = NULL;
			delete [] RH_RMaxVal2;		RH_RMaxVal2 = NULL;
		}
		//------------------------------------------------------
		//Step2:Deleted!
		if(RH_Index != 0){
			RH_Len = ( RH_Index - RH_Back  < 0 ) ? 0 : RH_Index - RH_Back;
			if(RH_Len > 0)
				m_RH_GroupData.remove(0,RH_Len);
		}
		else{
			//RH_Index = RH_iVectorSize-1;
			RH_Index = 0;
			m_RH_CurData = m_RH_GroupData.at(RH_Index);
			//MaxVector Length Limited!
			if( RH_iVectorSize > MAX_VECTOR_LEN ){
				m_RH_GroupData.remove(0,RH_iVectorSize-MAX_VECTOR_LEN);
			}
		}
		//------------------------------------------------------
	}
	else if( RH_iVectorSize >= 1 ){
		m_RH_CurData = m_RH_GroupData.at(RH_iVectorSize-1);
		RH_Index = RH_iVectorSize-1;
	}
	else{
		return false;
	}
	
	//-------------------RV Unit----------------------
	if( RV_iVectorSize > m_V_SoftShoeLayer ){
		//------------------------------------------------------
		//Step1:Generated!
		if( m_V_bLowPassFilter )
		{
			int i = RV_iVectorSize-1;
			m_RV_CurData = m_RV_GroupData.at(i);
			int iStart = i-RV_HalfSoftShoe < 0 ? 0 : i-RV_HalfSoftShoe;
			int iEnd = i+RV_HalfSoftShoe > RV_iVectorSize-1 ? RV_iVectorSize-1 : i+RV_HalfSoftShoe;

			int iLen = iEnd - iStart + 1;
			RV_FilterData1 = new double[iLen];
			RV_FilterData2 = new double[iLen];
			int k = 0;
			for(int j=iStart; j<=iEnd ; j++)
			{
				RV_FilterData1[k] = m_RV_GroupData.at(j).RealPos1;
				RV_FilterData2[k] = m_RV_GroupData.at(j).RealPos2;
				k++;
			}
			//f_Midean1 = qQuickMedian(RV_FilterData1,iLen);
			//f_Midean2 = qQuickMedian(RV_FilterData2,iLen);
			qQuickMedianGroup( RV_FilterData1, RV_FilterData2, iLen,f_Midean1,f_Midean2 );

			m_RV_CurData.SensorValue1 = m_RV_CurData.SensorValue1 - (f_Midean1 - m_RV_CurData.RealPos1);
			m_RV_CurData.SensorValue2 = m_RV_CurData.SensorValue2 - (f_Midean2 - m_RV_CurData.RealPos2);
			m_RV_CurData.SensorValue = m_RV_CurData.SensorValue1*m_RV_SensorRatio+m_RV_CurData.SensorValue2*(1-m_RV_SensorRatio);
			m_RV_CurData.PureValue = m_RV_CurData.SensorValue;

			RV_Index = i;
			//Important!!!!,Smoth the SensorValue
			m_RV_CurData.SensorValue = m_RV_CurData.SensorValue*m_V_SoftShoeAlph+m_RV_PreData.SensorValue*(1-m_V_SoftShoeAlph);

			//-----End----
			delete [] RV_FilterData1;		RV_FilterData1 = NULL;
			delete [] RV_FilterData2;		RV_FilterData2 = NULL;
		}
		else //滤波 ligy  20190906 add
		{
			RV_FMaxVal1 = new double[m_V_SoftShoeLayer];
			RV_RMaxVal1 = new double[m_V_SoftShoeLayer];
			RV_FMaxVal2 = new double[m_V_SoftShoeLayer];
			RV_RMaxVal2 = new double[m_V_SoftShoeLayer];

			int i = RV_iVectorSize-1;
			m_RV_CurData = m_RV_GroupData.at(i);
			int iStart = i-RV_HalfSoftShoe < 0 ? 0 : i-RV_HalfSoftShoe;
			int iEnd = i+RV_HalfSoftShoe > RV_iVectorSize-1 ? RV_iVectorSize-1 : i+RV_HalfSoftShoe;
			//int EdgeIndex = m_RV_CurData.EdgeIndex;

			int iStep = m_V_SoftShoeLayer;
			for(int k=0 ; k<iStep ; k++){
				RV_FMaxVal1[k] = -1E10;
				RV_RMaxVal1[k] = 1E10;
				RV_FMaxVal2[k] = -1E10;
				RV_RMaxVal2[k] = 1E10;
				for(int j=iStart+k ; j<=iEnd ; j+=iStep){
					//if( EdgeIndex == m_RV_GroupData.at(j).EdgeIndex )
					{
						double RealPos1 = m_RV_GroupData.at(j).RealPos1;
						double RealPos2 = m_RV_GroupData.at(j).RealPos2;
						if(RV_FMaxVal1[k] < RealPos1)
							RV_FMaxVal1[k] = RealPos1;
						if(RV_RMaxVal1[k] > RealPos1)
							RV_RMaxVal1[k] = RealPos1;
						if(RV_FMaxVal2[k] < RealPos2)
							RV_FMaxVal2[k] = RealPos2;
						if(RV_RMaxVal2[k] > RealPos2)
							RV_RMaxVal2[k] = RealPos2;
					}
				}
			}
			double FMinVal1 = 1E10;
			double RMinVal1 = -1E10;
			double FMinVal2 = 1E10;
			double RMinVal2 = -1E10;
			for(int k=0 ; k<iStep ; k++){
				if(FMinVal1 > RV_FMaxVal1[k])
					FMinVal1 = RV_FMaxVal1[k];
				if(RMinVal1 < RV_RMaxVal1[k])
					RMinVal1 = RV_RMaxVal1[k];
				if(FMinVal2 > RV_FMaxVal2[k])
					FMinVal2 = RV_FMaxVal2[k];
				if(RMinVal2 < RV_RMaxVal2[k])
					RMinVal2 = RV_RMaxVal2[k];
			}

			SensorValueF1 = m_RV_CurData.SensorValue1 - (FMinVal1 - m_RV_CurData.RealPos1);
			SensorValueR1 = m_RV_CurData.SensorValue1 - (RMinVal1 - m_RV_CurData.RealPos1);
			SensorValueF2 = m_RV_CurData.SensorValue2 - (FMinVal2 - m_RV_CurData.RealPos2);
			SensorValueR2 = m_RV_CurData.SensorValue2 - (RMinVal2 - m_RV_CurData.RealPos2);
			
			m_RV_CurData.SensorValue1 = SensorValueF1*m_V_SoftShoeDirRatio1+SensorValueR1*(1-m_V_SoftShoeDirRatio1);
			m_RV_CurData.SensorValue2 = SensorValueF2*m_V_SoftShoeDirRatio2+SensorValueR2*(1-m_V_SoftShoeDirRatio2);
			m_RV_CurData.SensorValue = m_RV_CurData.SensorValue1*m_RV_SensorRatio+m_RV_CurData.SensorValue2*(1-m_RV_SensorRatio);
			m_RV_CurData.PureValue = m_RV_CurData.SensorValue;

			RV_Index = i;
			//Important!!!!,Smoth the SensorValue
			m_RV_CurData.SensorValue = m_RV_CurData.SensorValue*m_V_SoftShoeAlph+m_RV_PreData.SensorValue*(1-m_V_SoftShoeAlph);

			//-----End----
			delete [] RV_FMaxVal1;		RV_FMaxVal1 = NULL;
			delete [] RV_RMaxVal1;		RV_RMaxVal1 = NULL;
			delete [] RV_FMaxVal2;		RV_FMaxVal2 = NULL;
			delete [] RV_RMaxVal2;		RV_RMaxVal2 = NULL;
		}
		//------------------------------------------------------
		//Step2:Deleted!
		if(RV_Index != 0){
			RV_Len = ( RV_Index - RV_Back  < 0 ) ? 0 : RV_Index - RV_Back;
			if(RV_Len > 0)
				m_RV_GroupData.remove(0,RV_Len);
		}
		else{
			//RV_Index = RV_iVectorSize-1;
			RV_Index = 0;
			m_RV_CurData = m_RV_GroupData.at(RV_Index);
			//MaxVector Length Limited!
			if( RV_iVectorSize > MAX_VECTOR_LEN ){
				m_RV_GroupData.remove(0,RV_iVectorSize-MAX_VECTOR_LEN);
			}
		}
		//------------------------------------------------------
	}
	else if( RV_iVectorSize >= 1 ){
		m_RV_CurData = m_RV_GroupData.at(RV_iVectorSize-1);
		RV_Index = RV_iVectorSize-1;
	}
	else{
		return false;
	}
	return true;
}

SlCapErrorEnum GlobalData::TrainMillingProc( ) //铣磨车工作过程 ligy 20190904 add.定时器调用，周期50ms
{
	bool iRet;
	SlQCap nWriteServer;
	SlCapErrorEnum eError = SL_CAP_OK;
	getValues( );
	SpeedReachedProc( );
	//TcuHeartBeatProc( ); //弃用 ligy 20190906 add
	//DeviceLockStateProc( );//弃用 ligy 20190906 add
	//DeviceHighStateProc( );//弃用 ligy 20190906 add

	if( m_bIsEmgyStop == true || m_nWorkState == WORKSTATE_NULL)
		return eError;
	//WorkMileageProc( );//ligy 20190906 add

	PushDataToBuf( );
	iRet = PopDataFromBuf_SoftShoe_HV( );
	/*
	PushDataToBuf( );
	iRet = PopDataFromBuf_Directly( );
	*/
	/*
	if( m_nWorkState == WORKSTATE_MILLING_INI || m_nWorkState == WORKSTATE_MILLING ||
		m_nWorkState == WORKSTATE_CUTOUT_INI || m_nWorkState == WORKSTATE_CUTOUT ||
		m_nWorkState == WORKSTATE_CUTIN_INI || m_nWorkState == WORKSTATE_CUTIN){
		PushDataToBuf( );
		iRet = PopDataFromBuf_SoftShoe_HV( );
	}
	else{
		PushDataToBuf( );
		iRet = PopDataFromBuf_Directly( );
	}
	*/
	if(iRet == false){
		return eError;
	}

	if( CheckSensorState( ) == false )//检测传感器状态
	{
		SetPCUWorkState(WORKSTATE_EMERGENCY_PCU);
		eError = EmergencyStopProc( WORKSTATE_EMERGENCY_PCU );
		return eError;
	}

	if( (IsLOverEndPowered( ) == true)  || (IsLOverLiftPowered( ) == true) )//左铣削单元最大功率、峰值功率是否超范围
	{
		m_LH_Error |= REPORT_7_ERR;
		SetPCUWorkState(WORKSTATE_EMERGENCY_PCU);
		eError = EmergencyStopProc( WORKSTATE_EMERGENCY_PCU );
		return eError;
	}
	if( (IsROverEndPowered( ) == true) ||  (IsROverLiftPowered( ) == true) )//右铣削单元最大功率、峰值功率是否超范围
	{
		bool bIniFlag = false;

		if (!bIniFlag)
		{
			DataProcessTest_WriteSaveData();   //ligy 20200211 add  写需要保存的数据到文件
		}

		m_RH_Error |= REPORT_7_ERR;
		SetPCUWorkState(WORKSTATE_EMERGENCY_PCU);
		eError = EmergencyStopProc( WORKSTATE_EMERGENCY_PCU );
		return eError;
	}
	//1st mode:Start follow mode ( Start Train )
	else if( m_nWorkState == WORKSTATE_STARTFELLOW_INI || m_nWorkState == WORKSTATE_STARTFELLOW )
	{	
		bool bIniFlag = false;

		if (!bIniFlag)
		{
			DataProcessTest_WriteSaveData();   //ligy 20200211 add  写需要保存的数据到文件
		}
		//Step1:--------------Initialize--------------
		if( m_nWorkState == WORKSTATE_STARTFELLOW_INI )
		{
			sensorFollowingIni( WORKSTATE_STARTFELLOW );
			SetPCUWorkState( WORKSTATE_STARTFELLOW );//设置PCU工作状态：开始跟随
			bIniFlag = true;
		}
		if( m_nWorkState == WORKSTATE_STARTFELLOW )
		{
			//Step2:--------------IsStateActionOver--------------
			if( !bIniFlag && IsStateActionOver(WORKSTATE_STARTFELLOW) ){
				SetPCUWorkState( WORKSTATE_ADJUST_INI );
				return eError;
			}
			//Step3:--------------IsSuddenChange--------------
			sensorFollowing(WORKSTATE_STARTFELLOW);
			if( IsSuddenChange( WORKSTATE_STARTFELLOW ) == false )//车速是否突然变化？
			{
				CutterSoftProtect( WORKSTATE_STARTFELLOW );
				eError = SendPosAndSpeed( WORKSTATE_STARTFELLOW,bIniFlag);
			}
			else
			{
				SetPCUWorkState( WORKSTATE_EMERGENCY_PCU );
				eError = EmergencyStopProc( WORKSTATE_EMERGENCY_PCU );
				return eError;
			}
		}
		//Step4:--------------Is Emergency from PLC--------------
		if( m_nWorkState == WORKSTATE_EMERGENCY_PLC ){
			EmergencyStopProc( WORKSTATE_EMERGENCY_PLC );
			return eError;
		}
	}
	//2st mode:Adjust To DeviceIniPos Mode ( Start Train )
	else if( m_nWorkState == WORKSTATE_ADJUST_INI || m_nWorkState == WORKSTATE_ADJUST )
	{	
		bool bIniFlag = false;

		if (!bIniFlag)
		{
			DataProcessTest_WriteSaveData();   //写需要保存的数据到文件 ligy 20200211 add
		}
		//Step1:--------------Initialize--------------
		if( m_nWorkState == WORKSTATE_ADJUST_INI )
		{
			sensorFollowingIni( WORKSTATE_ADJUST );
			SetPCUWorkState( WORKSTATE_ADJUST );
			bIniFlag = true;
		}
		if( m_nWorkState == WORKSTATE_ADJUST )
		{
			//Step2:--------------IsStateActionOver--------------
			if(  !bIniFlag && IsStateActionOver(WORKSTATE_ADJUST) ){
				SetPCUWorkState( WORKSTATE_YFELLOW_INI );
				return eError;
			}
			//Step3:--------------IsSuddenChange--------------
			sensorFollowing(WORKSTATE_ADJUST);
			if( IsSuddenChange( WORKSTATE_ADJUST ) == false )
			{
				CutterSoftProtect( WORKSTATE_ADJUST );
				eError = SendPosAndSpeed( WORKSTATE_ADJUST,bIniFlag );
			}
			else
			{
				SetPCUWorkState( WORKSTATE_EMERGENCY_PCU );
				eError = EmergencyStopProc( WORKSTATE_EMERGENCY_PCU );
				return eError;
			}
		}
		//Step4:--------------Is Emergency from PLC--------------
		if( m_nWorkState == WORKSTATE_EMERGENCY_PLC ){
			EmergencyStopProc( WORKSTATE_EMERGENCY_PLC );
			return eError;
		}
	}
	//3st mode:follow mode ( Start Train )
	else if( m_nWorkState == WORKSTATE_YFELLOW_INI || m_nWorkState == WORKSTATE_YFELLOW )//Y向跟随
	{	
		bool bIniFlag = false;
		if (!bIniFlag)
		{
			DataProcessTest_WriteSaveData();   //写需要保存的数据到文件 ligy 20200211 add
		}
		//Step1:--------------Initialize--------------
		if( m_nWorkState == WORKSTATE_YFELLOW_INI )
		{
			sensorFollowingIni( WORKSTATE_YFELLOW );
			SetPCUWorkState( WORKSTATE_YFELLOW );
			bIniFlag = true;
		}
		if( m_nWorkState == WORKSTATE_YFELLOW )
		{
			//Step2:--------------IsSuddenChange--------------
			sensorFollowing(WORKSTATE_YFELLOW);
			if( IsSuddenChange( WORKSTATE_YFELLOW ) == false )
			{
				CutterSoftProtect( WORKSTATE_YFELLOW );
				eError = SendPosAndSpeed( WORKSTATE_YFELLOW,bIniFlag );
			}
			else
			{
				SetPCUWorkState( WORKSTATE_EMERGENCY_PCU );
				eError = EmergencyStopProc( WORKSTATE_EMERGENCY_PCU );
				return eError;
			}
		}
		//Step3:--------------Is Emergency from PLC--------------
		if( m_nWorkState == WORKSTATE_EMERGENCY_PLC ){
			EmergencyStopProc( WORKSTATE_EMERGENCY_PLC );
			return eError;
		}
	}
	//4nd mode:Rapid to WorkIniPos Speed=Rapid Speed
	else if( m_nWorkState == WORKSTATE_WORKIN_INI || m_nWorkState == WORKSTATE_WORKIN )//作业状态
	{
		bool bIniFlag = false;

		if (!bIniFlag)
		{
			DataProcessTest_WriteSaveData();   //写需要保存的数据到文件 ligy 20200211 add
		}

		//Step1:--------------Initialize--------------
		if( (m_nWorkState == WORKSTATE_WORKIN_INI) && IsStateActionOver(WORKSTATE_YFELLOW) )
		{
			sensorFollowingIni( WORKSTATE_WORKIN );
			SetPCUWorkState( WORKSTATE_WORKIN );
			bIniFlag = true;
		}
		if( m_nWorkState == WORKSTATE_WORKIN )
		{
			//Step2:--------------IsStateActionOver--------------
			if(  !bIniFlag && IsStateActionOver(WORKSTATE_WORKIN) ){
				SetPCUWorkState( WORKSTATE_CUTIN_INI );
				return eError;
			}
			//Step3:--------------IsSuddenChange--------------
			sensorFollowing( WORKSTATE_WORKIN );
			if( IsSuddenChange( WORKSTATE_WORKIN ) == false )
			{
				CutterSoftProtect( WORKSTATE_WORKIN );
				eError = SendPosAndSpeed( WORKSTATE_WORKIN,bIniFlag );
			}
			else
			{
				SetPCUWorkState( WORKSTATE_EMERGENCY_PCU );
				eError = EmergencyStopProc( WORKSTATE_EMERGENCY_PCU );
				return eError;
			}
		}
		//Step4:--------------Is Emergency from PLC--------------
		if( m_nWorkState == WORKSTATE_EMERGENCY_PLC ){
			EmergencyStopProc( WORKSTATE_EMERGENCY_PLC );
			return eError;
		}
	}
	//5nd mode:Slope to Cut Point
	else if( m_nWorkState == WORKSTATE_CUTIN_INI || m_nWorkState == WORKSTATE_CUTIN)//顺坡切入
	{
		bool bIniFlag = false;

		if (!bIniFlag)
		{
			DataProcessTest_WriteSaveData();   //写需要保存的数据到文件 ligy 20200211 add
		}

		//Step1:--------------Initialize--------------
		if( m_nWorkState == WORKSTATE_CUTIN_INI )
		{
			sensorFollowingIni( WORKSTATE_CUTIN );
			SetPCUWorkState( WORKSTATE_CUTIN );
			bIniFlag = true;
		}
		if(m_nWorkState == WORKSTATE_CUTIN)
		{
			//Step2:--------------IsStateActionOver--------------
			if(  !bIniFlag && IsStateActionOver(WORKSTATE_CUTIN) ){//每次进来，bIniFlag都为false
				SetPCUWorkState( WORKSTATE_MILLING_INI );
				return eError;
			}
			//Step3:--------------IsSuddenChange--------------
			sensorFollowing(WORKSTATE_CUTIN);
			if( IsSuddenChange( WORKSTATE_CUTIN ) == false )
			{
				CutterSoftProtect( WORKSTATE_CUTIN );
				eError = SendPosAndSpeed( WORKSTATE_CUTIN,bIniFlag );
			}
			else
			{
				SetPCUWorkState( WORKSTATE_EMERGENCY_PCU );
				eError = EmergencyStopProc( WORKSTATE_EMERGENCY_PCU );
				return eError;
			}
		}
		//Step4:--------------Is Emergency from PLC--------------
		if( m_nWorkState == WORKSTATE_EMERGENCY_PLC ){
			EmergencyStopProc( WORKSTATE_EMERGENCY_PLC );
			return eError;
		}
	}
	//6nd mode:Auto Milling
	else if(m_nWorkState == WORKSTATE_MILLING_INI || m_nWorkState == WORKSTATE_MILLING)
	{
		bool bIniFlag = false;

		if (!bIniFlag)
		{
			DataProcessTest_WriteSaveData();   //写需要保存的数据到文件 ligy 20200211 add
		}

		//Step1:--------------Initialize--------------
		if( m_nWorkState == WORKSTATE_MILLING_INI )
		{
			sensorFollowingIni( WORKSTATE_MILLING );
			ScanCutBiasIni( );
			PowerControlIni( );
			SetPCUWorkState( WORKSTATE_MILLING );
			bIniFlag = true;
		}
		if(m_nWorkState == WORKSTATE_MILLING)
		{
			//Step2:--------------IsSuddenChange--------------
			sensorFollowing(WORKSTATE_MILLING);
			if( IsSuddenChange( WORKSTATE_MILLING ) == false )
			{
				CutterSoftProtect( WORKSTATE_MILLING );
				eError = SendPosAndSpeed( WORKSTATE_MILLING,bIniFlag );
			}
			else
			{
				SetPCUWorkState( WORKSTATE_EMERGENCY_PCU );
				eError = EmergencyStopProc( WORKSTATE_EMERGENCY_PCU );
				return eError;
			}
			//Step3:--------------Scan Bias--------------
			PowerControlProc( );
			ScanCutBias( );
			LimitCutBias( );
			CutBiasStep( );
		}
		//Step4:--------------Is Emergency from PLC--------------
		if( m_nWorkState == WORKSTATE_EMERGENCY_PLC ){
			EmergencyStopProc( WORKSTATE_EMERGENCY_PLC );
			return eError;
		}
	}
	//7nd mode:Rapid to CutIniPos Speed=Rapid Speed
	else if( m_nWorkState == WORKSTATE_CUTOUT_INI || m_nWorkState == WORKSTATE_CUTOUT )
	{
		bool bIniFlag = false;

		if (!bIniFlag)
		{
			DataProcessTest_WriteSaveData();   //写需要保存的数据到文件 ligy 20200211 add
		}

		//Step1:--------------Initialize--------------
		if( m_nWorkState == WORKSTATE_CUTOUT_INI && IsStateActionOver(WORKSTATE_MILLING)  )
		{
			sensorFollowingIni( WORKSTATE_CUTOUT );
			SetPCUWorkState( WORKSTATE_CUTOUT );
			bIniFlag = true;
		}
		if(m_nWorkState == WORKSTATE_CUTOUT)
		{
			//Step2:--------------IsStateActionOver--------------
			if(  !bIniFlag && IsStateActionOver(WORKSTATE_CUTOUT) ){
				SetPCUWorkState( WORKSTATE_WORKOUT_INI );
				return eError;
			}
			//Step3:--------------IsSuddenChange--------------
			sensorFollowing(WORKSTATE_CUTOUT);
			if( IsSuddenChange( WORKSTATE_CUTOUT ) == false )
			{
				CutterSoftProtect( WORKSTATE_CUTOUT );
				eError = SendPosAndSpeed( WORKSTATE_CUTOUT,bIniFlag );
			}
			else
			{
				SetPCUWorkState( WORKSTATE_EMERGENCY_PCU );
				eError = EmergencyStopProc( WORKSTATE_EMERGENCY_PCU );
				return eError;
			}
		}
		//Step4:--------------Is Emergency from PLC--------------
		if( m_nWorkState == WORKSTATE_EMERGENCY_PLC ){
			EmergencyStopProc( WORKSTATE_EMERGENCY_PLC );
			return eError;
		}
	}
	//8nd mode:Rapid to WorkIniPos Speed=Rapid Speed
	else if( m_nWorkState == WORKSTATE_WORKOUT_INI || m_nWorkState == WORKSTATE_WORKOUT )
	{	
		bool bIniFlag = false;

		if (!bIniFlag)
		{
			DataProcessTest_WriteSaveData();   //写需要保存的数据到文件 ligy 20200211 add
		}

		//Step1:--------------Initialize--------------
		if( m_nWorkState == WORKSTATE_WORKOUT_INI )
		{
			sensorFollowingIni( WORKSTATE_WORKOUT );
			SetPCUWorkState( WORKSTATE_WORKOUT );
			bIniFlag = true;
		}
		if(m_nWorkState == WORKSTATE_WORKOUT)
		{
			//Step2:--------------IsStateActionOver--------------
			if(  !bIniFlag && IsStateActionOver(WORKSTATE_WORKOUT) ){
				SetPCUWorkState( WORKSTATE_YFELLOW2_INI );
				return eError;
			}
			//Step3:--------------IsSuddenChange--------------
			sensorFollowing(WORKSTATE_WORKOUT);
			if( IsSuddenChange( WORKSTATE_WORKOUT ) == false )
			{
				CutterSoftProtect( WORKSTATE_WORKOUT );
				eError = SendPosAndSpeed( WORKSTATE_WORKOUT,bIniFlag );
			}
			else
			{
				SetPCUWorkState( WORKSTATE_EMERGENCY_PCU );
				eError = EmergencyStopProc( WORKSTATE_EMERGENCY_PCU );
				return eError;
			}
		}
		//Step4:--------------Is Emergency from PLC--------------
		if( m_nWorkState == WORKSTATE_EMERGENCY_PLC ){
			EmergencyStopProc( WORKSTATE_EMERGENCY_PLC );
			return eError;
		}
	}
	//9nd mode:WORKSTATE_YFELLOW2 State
	else if( m_nWorkState == WORKSTATE_YFELLOW2_INI || m_nWorkState == WORKSTATE_YFELLOW2 )
	{	
		bool bIniFlag = false;

		if (!bIniFlag)
		{
			DataProcessTest_WriteSaveData();   //写需要保存的数据到文件 ligy 20200211 add
		}

		//Step1:--------------Initialize--------------
		if( m_nWorkState == WORKSTATE_YFELLOW2_INI )
		{
			sensorFollowingIni( WORKSTATE_YFELLOW2 );
			SetPCUWorkState( WORKSTATE_YFELLOW2 );
			bIniFlag = true;
		}
		if( m_nWorkState == WORKSTATE_YFELLOW2 )
		{
			//Step2:--------------IsSuddenChange--------------
			sensorFollowing(WORKSTATE_YFELLOW2);
			if( IsSuddenChange( WORKSTATE_YFELLOW2 ) == false )
			{
				CutterSoftProtect( WORKSTATE_YFELLOW2 );
				eError = SendPosAndSpeed( WORKSTATE_YFELLOW2,bIniFlag );
			}
			else
			{
				SetPCUWorkState( WORKSTATE_EMERGENCY_PCU );
				eError = EmergencyStopProc( WORKSTATE_EMERGENCY_PCU );
				return eError;
			}
		}
		//Step3:--------------Is Emergency from PLC--------------
		if( m_nWorkState == WORKSTATE_EMERGENCY_PLC ){
			EmergencyStopProc( WORKSTATE_EMERGENCY_PLC );
			return eError;
		}
	}
	//10th mode:WORKSTATE_ENDFELLOW_INI State
	else if( m_nWorkState == WORKSTATE_ENDFELLOW_INI || m_nWorkState == WORKSTATE_ENDFELLOW )
	{	
		bool bIniFlag = false;

		if (!bIniFlag)
		{
			DataProcessTest_WriteSaveData();   //写需要保存的数据到文件 ligy 20200211 add
		}

		//Step1:--------------Initialize--------------
		if( m_nWorkState == WORKSTATE_ENDFELLOW_INI  && IsStateActionOver(WORKSTATE_YFELLOW2) )
		{
			sensorFollowingIni( WORKSTATE_ENDFELLOW );
			SetPCUWorkState( WORKSTATE_ENDFELLOW );
			bIniFlag = true;
		}
		if(m_nWorkState == WORKSTATE_ENDFELLOW)
		{
			//Step2:--------------IsStateActionOver--------------
			if(  !bIniFlag && IsStateActionOver(WORKSTATE_ENDFELLOW) ){

				eError = nWriteServer.write(szItem_EndFellow_Bit,QVariant(true));
				SetPCUWorkState( WORKSTATE_NULL );
				StopRecordData( );

				m_LH_CutBias = 0;
				m_LV_CutBias = 0;
				m_RH_CutBias = 0;
				m_RV_CutBias = 0;
				m_LH_PreCutBias = 0;
				m_LV_PreCutBias = 0;
				m_RH_PreCutBias = 0;
				m_RV_PreCutBias = 0;
				m_LH_CutBiasStep = 0;
				m_LV_CutBiasStep = 0;
				m_RH_CutBiasStep = 0;
				m_RV_CutBiasStep = 0;
				m_LH_SensorDstValue = SENSORDST_NOFELLOW;
				m_LV_SensorDstValue = SENSORDST_NOFELLOW;
				m_RH_SensorDstValue = SENSORDST_NOFELLOW;
				m_RV_SensorDstValue = SENSORDST_NOFELLOW;
				memset(&m_LH_CurData,0,sizeof(m_LH_CurData));
				memset(&m_LV_CurData,0,sizeof(m_LV_CurData));
				memset(&m_RH_CurData,0,sizeof(m_RH_CurData));
				memset(&m_RV_CurData,0,sizeof(m_RV_CurData));
				memset(&m_LH_PreData,0,sizeof(m_LH_PreData));
				memset(&m_LV_PreData,0,sizeof(m_LV_PreData));
				memset(&m_RH_PreData,0,sizeof(m_RH_PreData));
				memset(&m_RV_PreData,0,sizeof(m_RV_PreData));

				return eError;
			}
			//Step3:--------------IsSuddenChange--------------
			sensorFollowing(WORKSTATE_ENDFELLOW);
			if( IsSuddenChange( WORKSTATE_ENDFELLOW ) == false )
			{
				CutterSoftProtect( WORKSTATE_ENDFELLOW );
				eError = SendPosAndSpeed( WORKSTATE_ENDFELLOW,bIniFlag );
			}
			else
			{
				SetPCUWorkState( WORKSTATE_EMERGENCY_PCU );
				eError = EmergencyStopProc( WORKSTATE_EMERGENCY_PCU );
				return eError;
			}
		}
		//Step4:--------------Is Emergency from PLC--------------
		if( m_nWorkState == WORKSTATE_EMERGENCY_PLC ){
			EmergencyStopProc( WORKSTATE_EMERGENCY_PLC );
			return eError;
		}
	}	
	//10th mode:Emergency Stop
	if( m_nWorkState == WORKSTATE_EMERGENCY_PCU || m_nWorkState == WORKSTATE_EMERGENCY_PLC )
	{
		bool bIniFlag = false;

		if (!bIniFlag)
		{
			bIniFlag = true;
			DataProcessTest_WriteSaveData();   //写需要保存的数据到文件 ligy 20200211 add
		}

		eError = EmergencyStopProc( m_nWorkState );
	}

	//11th : PCU COM Alarm
	if( !m_bPcuCommState ){
		m_bPcuCommState = true;

		SetPCUWorkState( WORKSTATE_EMERGENCY_PCU );
		eError = EmergencyStopProc( m_nWorkState );
		//will be created in handleRetVal
		//g_pErr->createPCUCOMAlarm();
	}
	return eError;
}

void GlobalData::SetPLCWorkState( int nWorkState )//ligy 20190928 add
{
	m_nPrePLCWorkState = m_nPLCWorkState;
	m_nPLCWorkState = nWorkState;
}

void GlobalData::SetPLCShineState( int nShineState )//ligy 20200108 modify
{
	m_nPrePLCShineState = m_nPLCShineState;
	m_nPLCShineState = nShineState;
}


void GlobalData::SetPCUWorkState( int nWorkState )
{
	m_nPreWorkState = m_nWorkState;
	m_nWorkState = nWorkState;
}

bool GlobalData::IsStateActionOver(int nWorkState) //current state execute finished.
{
	bool bStateActionOver = false;
	switch(nWorkState)
	{
	case WORKSTATE_STARTFELLOW:
		if( (!m_L_bEnableUnit||fabs(m_LH_MotorCurPos-m_LH_MotorPreDstPos)<0.01) && 
			(!m_R_bEnableUnit||fabs(m_RH_MotorCurPos-m_RH_MotorPreDstPos)<0.01) &&
			fabs(m_CurTrainSpeed) > 0.08 )
			bStateActionOver = true;
		else
			bStateActionOver = false;
		break;
	case WORKSTATE_ADJUST:
		if( (!m_L_bEnableUnit||fabs(m_LH_MotorCurPos-m_LH_MotorPreDstPos)<0.01) && 
			(!m_R_bEnableUnit||fabs(m_RH_MotorCurPos-m_RH_MotorPreDstPos)<0.01) )		//0.01--->0.03
			bStateActionOver = true;
		else
			bStateActionOver = false;
		break;
	case WORKSTATE_YFELLOW:
	case WORKSTATE_YFELLOW2:
		if( (!m_L_bEnableUnit||fabs(m_LH_MotorCurPos-m_LH_MotorPreDstPos)<0.01) && 
			(!m_R_bEnableUnit||fabs(m_RH_MotorCurPos-m_RH_MotorPreDstPos)<0.01) )		//0.01--->0.03
			bStateActionOver = true;
		else
			bStateActionOver = false;
		break;
	case WORKSTATE_WORKIN:
		if( (!m_L_bEnableUnit||fabs(m_LH_MotorCurPos-m_LH_MotorPreDstPos)<0.01) && 
			(!m_R_bEnableUnit||fabs(m_RH_MotorCurPos-m_RH_MotorPreDstPos)<0.01) && 
			(!m_L_bEnableUnit||fabs(m_LV_MotorCurPos-m_LV_MotorPreDstPos)<0.01) && 
			(!m_R_bEnableUnit||fabs(m_RV_MotorCurPos-m_RV_MotorPreDstPos)<0.01) )		//0.01--->0.03
			bStateActionOver = true;
		else
			bStateActionOver = false;
		break;
	case WORKSTATE_CUTIN:
		if( (!m_L_bEnableUnit||fabs(m_L_SMWCurPos-m_L_SMWInit)>(m_SlopeLength)) && 
			(!m_R_bEnableUnit||fabs(m_R_SMWCurPos-m_R_SMWInit)>(m_SlopeLength)) && 
			(!m_L_bEnableUnit||fabs(m_L_SMWCurPos-m_L_SMWInit)>(m_SlopeLength)) && 
			(!m_R_bEnableUnit||fabs(m_R_SMWCurPos-m_R_SMWInit)>(m_SlopeLength)) && 
			(!m_L_bEnableUnit||fabs(m_LH_MotorCurPos-m_LH_MotorPreDstPos)<0.01) && 
			(!m_R_bEnableUnit||fabs(m_RH_MotorCurPos-m_RH_MotorPreDstPos)<0.01) &&
			(!m_L_bEnableUnit||fabs(m_LV_MotorCurPos-m_LV_MotorPreDstPos)<0.01) && 
			(!m_R_bEnableUnit||fabs(m_RV_MotorCurPos-m_RV_MotorPreDstPos)<0.01) )
			bStateActionOver = true;
		else
			bStateActionOver = false;
		break;
	case WORKSTATE_MILLING:
		if( (!m_L_bEnableUnit||fabs(m_LH_MotorCurPos-m_LH_MotorPreDstPos)<0.01) && 
			(!m_R_bEnableUnit||fabs(m_RH_MotorCurPos-m_RH_MotorPreDstPos)<0.01) && 
			(!m_L_bEnableUnit||fabs(m_LV_MotorCurPos-m_LV_MotorPreDstPos)<0.01) && 
			(!m_R_bEnableUnit||fabs(m_RV_MotorCurPos-m_RV_MotorPreDstPos)<0.01) )		//0.01--->0.03
			bStateActionOver = true;
		else
			bStateActionOver = false;
		break;
	case WORKSTATE_CUTOUT:
		if( (!m_L_bEnableUnit||fabs(m_L_SMWCurPos-m_L_SMWInit)>(m_SlopeLength)) && 
			(!m_R_bEnableUnit||fabs(m_R_SMWCurPos-m_R_SMWInit)>(m_SlopeLength)) && 
			(!m_L_bEnableUnit||fabs(m_L_SMWCurPos-m_L_SMWInit)>(m_SlopeLength)) && 
			(!m_R_bEnableUnit||fabs(m_R_SMWCurPos-m_R_SMWInit)>(m_SlopeLength)) && 
			(!m_L_bEnableUnit||fabs(m_LH_MotorCurPos-m_LH_MotorPreDstPos)<0.01) && 
			(!m_R_bEnableUnit||fabs(m_RH_MotorCurPos-m_RH_MotorPreDstPos)<0.01) &&
			(!m_L_bEnableUnit||fabs(m_LV_MotorCurPos-m_LV_MotorPreDstPos)<0.01) && 
			(!m_R_bEnableUnit||fabs(m_RV_MotorCurPos-m_RV_MotorPreDstPos)<0.01) )
			bStateActionOver = true;
		else
			bStateActionOver = false;
		break;
	case WORKSTATE_WORKOUT:
		if( (!m_L_bEnableUnit||fabs(m_LH_MotorCurPos-m_LH_MotorPreDstPos)<0.01) && 
			(!m_R_bEnableUnit||fabs(m_RH_MotorCurPos-m_RH_MotorPreDstPos)<0.01) && 
			(!m_L_bEnableUnit||fabs(m_LV_MotorCurPos-m_LV_MotorPreDstPos)<0.01) && 
			(!m_R_bEnableUnit||fabs(m_RV_MotorCurPos-m_RV_MotorPreDstPos)<0.01) )		//0.01--->0.03
			bStateActionOver = true;
		else
			bStateActionOver = false;
		break;
	case WORKSTATE_ENDFELLOW:
		if( (!m_L_bEnableUnit||fabs(m_LH_MotorCurPos-m_LH_MotorPreDstPos)<0.01) && 
			(!m_R_bEnableUnit||fabs(m_RH_MotorCurPos-m_RH_MotorPreDstPos)<0.01) &&
			IsTrainStopMove( ) )		//0.01--->0.03
			bStateActionOver = true;
		else
			bStateActionOver = false;
		break;
	}
	return bStateActionOver;
}

bool GlobalData::IsSuddenChange( int nWorkState )//ligy 20190910 add.判断速度是否骤然变化
{
	QTime now;
	bool bSuddenChange = false;
	double LH_SensorCurValue = m_LH_CurData.SensorValue;
	double LV_SensorCurValue = m_LV_CurData.SensorValue;
	double RH_SensorCurValue = m_RH_CurData.SensorValue;
	double RV_SensorCurValue = m_RV_CurData.SensorValue;
	double LH_SensorPreValue = m_LH_PreData.SensorValue;
	double LV_SensorPreValue = m_LV_PreData.SensorValue;
	double RH_SensorPreValue = m_RH_PreData.SensorValue;
	double RV_SensorPreValue = m_RV_PreData.SensorValue;

	double p_LH_SensorCurValue = m_LH_CurData.PureValue;
	double p_LV_SensorCurValue = m_LV_CurData.PureValue;
	double p_RH_SensorCurValue = m_RH_CurData.PureValue;
	double p_RV_SensorCurValue = m_RV_CurData.PureValue;
	double p_LH_SensorPreValue = m_LH_PreData.PureValue;
	double p_LV_SensorPreValue = m_LV_PreData.PureValue;
	double p_RH_SensorPreValue = m_RH_PreData.PureValue;
	double p_RV_SensorPreValue = m_RV_PreData.PureValue;

	bool bTrainStopMove = (m_L_SMWCurSpeed < 1E-2 && m_R_SMWCurSpeed < 1E-2);
	//车速在±30超差范围内，视为正常，否则视为异常
	bool bTrainSpeedNormal = ( m_CurTrainSpeed > (1-m_DstTrainSpeedDiff/100.0)/*0.7*/ * fabs(m_DstTrainSpeed) ) && ( m_CurTrainSpeed < (1+m_DstTrainSpeedDiff/100.0)/*1.3*/ * fabs(m_DstTrainSpeed) );//设置速度超差范围 ligy 20190908 add
	/*
	double LH_SensorCalibPos = (m_LH_bSensorChoose == true) ?
			m_LH_SensorCalibPos1 : m_LH_SensorCalibPos2;
	double LV_SensorCalibPos = (m_LV_bSensorChoose == true) ?
			m_LV_SensorCalibPos1 : m_LV_SensorCalibPos2;
	double RH_SensorCalibPos = (m_RH_bSensorChoose == true) ?
			m_RH_SensorCalibPos1 : m_RH_SensorCalibPos2;
	double RV_SensorCalibPos = (m_RV_bSensorChoose == true) ?
			m_RV_SensorCalibPos1 : m_RV_SensorCalibPos2;
	*/

	/*Method 1:using the Sensor Values;
	m_LH_MotorDistToGo = m_LH_SensorDstValue - LH_SensorCurValue;
	m_LV_MotorDistToGo = m_LV_SensorDstValue - LV_SensorCurValue;
	m_RH_MotorDistToGo = m_RH_SensorDstValue - RH_SensorCurValue;
	m_RV_MotorDistToGo = m_RV_SensorDstValue - RV_SensorCurValue;
	*/
	/*Method 2:using the Motor Values;
	m_LH_MotorDistToGo = m_LH_MotorPreDstPos - m_LH_MotorCurPos;
	m_LV_MotorDistToGo = m_LV_MotorPreDstPos - m_LV_MotorCurPos;
	m_RH_MotorDistToGo = m_RH_MotorPreDstPos - m_RH_MotorCurPos;
	m_RV_MotorDistToGo = m_RV_MotorPreDstPos - m_RV_MotorCurPos;
	*/
	bool bReportSensorErr = false;
	if(m_bSensorErr == false){
		if( m_L_bEnableUnit ){
			if( ( m_LH_bSensorChoose1 && ((fabs(m_LH_SensorCurValue1-50) < 1) || (fabs(m_LH_SensorCurValue1-25) < 1))) || 
				( m_LH_bSensorChoose2 && ((fabs(m_LH_SensorCurValue2-50) < 1) || (fabs(m_LH_SensorCurValue2-25) < 1))) ){
					m_LH_Error |= REPORT_8_ERR;
					m_bSensorErr = true;
					bReportSensorErr = true;
			}
			if( ( m_LV_bSensorChoose1 && ((fabs(m_LV_SensorCurValue1-50) < 1) || (fabs(m_LV_SensorCurValue1-25) < 1))) || 
				( m_LV_bSensorChoose2 && ((fabs(m_LV_SensorCurValue2-50) < 1) || (fabs(m_LV_SensorCurValue2-25) < 1))) ){
					m_LV_Error |= REPORT_8_ERR;
					m_bSensorErr = true;
					bReportSensorErr = true;
			}
		}
		if( m_R_bEnableUnit ){
			if( ( m_RH_bSensorChoose1 && ((fabs(m_RH_SensorCurValue1-50) < 1) || (fabs(m_RH_SensorCurValue1-25) < 1))) || 
				( m_RH_bSensorChoose2 && ((fabs(m_RH_SensorCurValue2-50) < 1) || (fabs(m_RH_SensorCurValue2-25) < 1))) ){
					m_RH_Error |= REPORT_8_ERR;
					m_bSensorErr = true;
					bReportSensorErr = true;
			}
			if( ( m_RV_bSensorChoose1 && ((fabs(m_RV_SensorCurValue1-50) < 1) || (fabs(m_RV_SensorCurValue1-25) < 1))) || 
				( m_RV_bSensorChoose2 && ((fabs(m_RV_SensorCurValue2-50) < 1) || (fabs(m_RV_SensorCurValue2-25) < 1))) ){
					m_RV_Error |= REPORT_8_ERR;
					m_bSensorErr = true;
					bReportSensorErr = true;
			}
		}
	}

	int iMonitorTimes = (int)(m_DstTrainSpeedDiffTime/50.0);//ligy 20190912 add.
	switch(nWorkState)
	{
	case WORKSTATE_ADJUST:
		now = QTime::currentTime();
		//over 3s
		if( abs(now.msecsTo(m_LastSensorAdjustTime)) > 1500 ){
			m_LH_Error |= REPORT_5_ERR;
			m_RH_Error |= REPORT_5_ERR;
		}
		if( (m_L_SMWCurSpeed < 1E-2 && m_R_SMWCurSpeed > 0.3) || bTrainStopMove )
			m_L_nErr6Times++;
		else
			m_L_nErr6Times=0;

		if( (m_R_SMWCurSpeed < 1E-2 && m_L_SMWCurSpeed > 0.3) || bTrainStopMove )
			m_R_nErr6Times++;
		else
			m_R_nErr6Times=0;	

		if(m_L_nErr6Times >= 2){
			m_LH_Error |= REPORT_6_ERR;
			m_L_nErr6Times=0;
		}
		if(m_R_nErr6Times >= 2){
			m_RH_Error |= REPORT_6_ERR;
			m_R_nErr6Times=0;	
		}

		if(m_LH_Error == REPORT_NO_ERR && m_RH_Error == REPORT_NO_ERR)
			bSuddenChange = false;
		else
			bSuddenChange = true;
		break;
	case WORKSTATE_STARTFELLOW:
		if( bReportSensorErr ){
			g_pErr->createPCUAlarms( );
			m_LH_Error &= (~REPORT_8_ERR);
			m_LV_Error &= (~REPORT_8_ERR);
			m_RH_Error &= (~REPORT_8_ERR);
			m_RV_Error &= (~REPORT_8_ERR);
		}

		now = QTime::currentTime();
		if(m_L_bEnableUnit && fabs(m_LH_MotorDstPos-m_LH_MotorCurPos) > 3 )
			m_LH_Error |= REPORT_1_ERR;
		if(m_R_bEnableUnit && fabs(m_RH_MotorDstPos-m_RH_MotorCurPos) > 3 )
			m_RH_Error |= REPORT_1_ERR;
		if(m_L_bEnableUnit && fabs(m_LH_MotorDstPos-m_LH_MotorPreDstPos) > 3 )
			m_LH_Error |= REPORT_2_ERR;
		if(m_R_bEnableUnit && fabs(m_RH_MotorDstPos-m_RH_MotorPreDstPos) > 3 )
			m_RH_Error |= REPORT_2_ERR;
		if(m_L_bEnableUnit && fabs(p_LH_SensorCurValue-p_LH_SensorPreValue) > 2 )
			m_LH_Error |= REPORT_3_ERR;
		if(m_R_bEnableUnit && fabs(p_RH_SensorCurValue-p_RH_SensorPreValue) > 2 ) 
			m_RH_Error |= REPORT_3_ERR;
		if(m_L_bEnableUnit && fabs(LH_SensorCurValue-m_LH_SensorDstValue) > 3 )
			m_LH_Error |= REPORT_4_ERR;
		if(m_R_bEnableUnit && fabs(RH_SensorCurValue-m_RH_SensorDstValue) > 3 )
			m_RH_Error |= REPORT_4_ERR;

		if( abs(now.msecsTo(m_LastStartFellowTime)) > 1000 && (m_L_SMWCurSpeed < 1E-2 && m_R_SMWCurSpeed > 0.3))
			m_L_nErr6Times++;
		else
			m_L_nErr6Times=0;

		if( abs(now.msecsTo(m_LastStartFellowTime)) > 1000 && (m_R_SMWCurSpeed < 1E-2 && m_L_SMWCurSpeed > 0.3))
			m_R_nErr6Times++;
		else
			m_R_nErr6Times=0;	

		if(m_L_nErr6Times >= 3){
			m_LH_Error |= REPORT_6_ERR;
			m_L_nErr6Times=0;
		}
		if(m_R_nErr6Times >= 3){
			m_RH_Error |= REPORT_6_ERR;
			m_R_nErr6Times=0;	
		}

		if(m_LH_Error == REPORT_NO_ERR && m_RH_Error == REPORT_NO_ERR)
			bSuddenChange = false;
		else
			bSuddenChange = true;
		break;
	case WORKSTATE_YFELLOW2:
		if( bTrainSpeedNormal == false )
			m_nErr11Times++;
		else
			m_nErr11Times=0;

		//if( m_nErr11Times >= 3 ){ //	速度监控时间为3*50ms ligy 20190910 add
		//	m_LH_Error |= REPORT_11_ERR;
		//	m_nErr11Times = 0;
		//}

		if( m_nErr11Times >= iMonitorTimes ){ //	速度监控时间为m_DstTrainSpeedDiffTime除以定时器时间(50ms) ligy 20190910 add
			m_LH_Error |= REPORT_11_ERR;
			m_nErr11Times = 0;
		}

	case WORKSTATE_YFELLOW:
		if( bTrainStopMove ){
			m_L_nErr6Times++;
			m_R_nErr6Times++;
		}
		else{
			m_L_nErr6Times=0;
			m_R_nErr6Times=0;
		}
	case WORKSTATE_ENDFELLOW:
		if(m_L_bEnableUnit && fabs(m_LH_MotorDstPos-m_LH_MotorCurPos) > 3 )
			m_LH_Error |= REPORT_1_ERR;
		if(m_R_bEnableUnit && fabs(m_RH_MotorDstPos-m_RH_MotorCurPos) > 3 )
			m_RH_Error |= REPORT_1_ERR;
		if(m_L_bEnableUnit && fabs(m_LH_MotorDstPos-m_LH_MotorPreDstPos) > 3 )
			m_LH_Error |= REPORT_2_ERR;
		if(m_R_bEnableUnit && fabs(m_RH_MotorDstPos-m_RH_MotorPreDstPos) > 3 )
			m_RH_Error |= REPORT_2_ERR;
		if(m_L_bEnableUnit && fabs(p_LH_SensorCurValue-p_LH_SensorPreValue) > 2 )
			m_LH_Error |= REPORT_3_ERR;
		if(m_R_bEnableUnit && fabs(p_RH_SensorCurValue-p_RH_SensorPreValue) > 2 ) 
			m_RH_Error |= REPORT_3_ERR;
		if(m_L_bEnableUnit && fabs(LH_SensorCurValue-m_LH_SensorDstValue) > 3 )
			m_LH_Error |= REPORT_4_ERR;
		if(m_R_bEnableUnit && fabs(RH_SensorCurValue-m_RH_SensorDstValue) > 3 )
			m_RH_Error |= REPORT_4_ERR;

		if(m_L_SMWCurSpeed < 1E-2 && m_R_SMWCurSpeed > 0.3)
			m_L_nErr6Times++;
		else
			m_L_nErr6Times=0;

		if(m_R_SMWCurSpeed < 1E-2 && m_L_SMWCurSpeed > 0.3)
			m_R_nErr6Times++;
		else
			m_R_nErr6Times=0;	

		if(m_L_nErr6Times >= iMonitorTimes){
			m_LH_Error |= REPORT_6_ERR;
			m_L_nErr6Times=0;
		}
		if(m_R_nErr6Times >= iMonitorTimes){
			m_RH_Error |= REPORT_6_ERR;
			m_R_nErr6Times=0;	
		}

		if(m_LH_Error == REPORT_NO_ERR && m_RH_Error == REPORT_NO_ERR)
			bSuddenChange = false;
		else
			bSuddenChange = true;
		break;
	case WORKSTATE_WORKIN:
	case WORKSTATE_WORKOUT:
		if( (m_L_SMWCurSpeed < 1E-2 && m_R_SMWCurSpeed > 0.3) || bTrainStopMove )
			m_L_nErr6Times++;
		else
			m_L_nErr6Times=0;

		if( (m_R_SMWCurSpeed < 1E-2 && m_L_SMWCurSpeed > 0.3) || bTrainStopMove )
			m_R_nErr6Times++;
		else
			m_R_nErr6Times=0;	

		if(m_L_nErr6Times >= 2){
			m_LH_Error |= REPORT_6_ERR;
			m_L_nErr6Times=0;
		}
		if(m_R_nErr6Times >= 2){
			m_RH_Error |= REPORT_6_ERR;
			m_R_nErr6Times=0;	
		}
		if(m_LH_Error == REPORT_NO_ERR && m_RH_Error == REPORT_NO_ERR)
			bSuddenChange = false;
		else
			bSuddenChange = true;
		break;
	case WORKSTATE_CUTIN:
	case WORKSTATE_CUTOUT:
		if(m_L_bEnableUnit && fabs(m_LH_MotorDstPos-m_LH_MotorCurPos) > 3 ) 
			m_LH_Error |= REPORT_1_ERR;
		if(m_L_bEnableUnit && fabs(m_LV_MotorDstPos-m_LV_MotorCurPos) > 3 ) 
			m_LV_Error |= REPORT_1_ERR;
		if(m_R_bEnableUnit && fabs(m_RH_MotorDstPos-m_RH_MotorCurPos) > 3 ) 
			m_RH_Error |= REPORT_1_ERR;
		if(m_R_bEnableUnit && fabs(m_RV_MotorDstPos-m_RV_MotorCurPos) > 3 ) 
			m_RV_Error |= REPORT_1_ERR;
		if(m_L_bEnableUnit && fabs(m_LH_MotorDstPos-m_LH_MotorPreDstPos) > 3 )
			m_LH_Error |= REPORT_2_ERR;
		if(m_R_bEnableUnit && fabs(m_RH_MotorDstPos-m_RH_MotorPreDstPos) > 3 )
			m_RH_Error |= REPORT_2_ERR;
		if(m_L_bEnableUnit && fabs(m_LV_MotorDstPos-m_LV_MotorPreDstPos) > 3 )
			m_LV_Error |= REPORT_2_ERR;
		if(m_R_bEnableUnit && fabs(m_RV_MotorDstPos-m_RV_MotorPreDstPos) > 3 )
			m_RV_Error |= REPORT_2_ERR;
		if(m_L_bEnableUnit && fabs(p_LH_SensorCurValue-p_LH_SensorPreValue) > 1.5 )
			m_LH_Error |= REPORT_3_ERR;
		if(m_R_bEnableUnit && fabs(p_RH_SensorCurValue-p_RH_SensorPreValue) > 1.5 ) 
			m_RH_Error |= REPORT_3_ERR;
		if( (m_L_SMWCurSpeed < 1E-2 && m_R_SMWCurSpeed > 0.3) || bTrainStopMove )
			m_L_nErr6Times++;
		else
			m_L_nErr6Times=0;

		if( (m_R_SMWCurSpeed < 1E-2 && m_L_SMWCurSpeed > 0.3) || bTrainStopMove )
			m_R_nErr6Times++;
		else
			m_R_nErr6Times=0;	

		if(m_L_nErr6Times >= 2){
			m_LH_Error |= REPORT_6_ERR;
			m_L_nErr6Times=0;
		}
		if(m_R_nErr6Times >= 2){
			m_RH_Error |= REPORT_6_ERR;
			m_R_nErr6Times=0;	
		}

		if( m_LH_Error == REPORT_NO_ERR && m_LV_Error == REPORT_NO_ERR && 
			m_RH_Error == REPORT_NO_ERR && m_RV_Error == REPORT_NO_ERR )
			bSuddenChange = false;
		else
			bSuddenChange = true;
		break;
	case WORKSTATE_MILLING:   // 铣削作业状态
		if(m_L_bEnableUnit && fabs(m_LH_MotorDstPos-m_LH_MotorCurPos) > 3 ) 
			m_LH_Error |= REPORT_1_ERR;
		if(m_L_bEnableUnit && fabs(m_LV_MotorDstPos-m_LV_MotorCurPos) > 3 ) 
			m_LV_Error |= REPORT_1_ERR;
		if(m_R_bEnableUnit && fabs(m_RH_MotorDstPos-m_RH_MotorCurPos) > 3 ) 
			m_RH_Error |= REPORT_1_ERR;
		if(m_R_bEnableUnit && fabs(m_RV_MotorDstPos-m_RV_MotorCurPos) > 3 ) 
			m_RV_Error |= REPORT_1_ERR;
		if(m_L_bEnableUnit && fabs(m_LH_MotorDstPos-m_LH_MotorPreDstPos) > 3 )
			m_LH_Error |= REPORT_2_ERR;
		if(m_R_bEnableUnit && fabs(m_RH_MotorDstPos-m_RH_MotorPreDstPos) > 3 )
			m_RH_Error |= REPORT_2_ERR;
		if(m_L_bEnableUnit && fabs(m_LV_MotorDstPos-m_LV_MotorPreDstPos) > 3 )
			m_LV_Error |= REPORT_2_ERR;
		if(m_R_bEnableUnit && fabs(m_RV_MotorDstPos-m_RV_MotorPreDstPos) > 3 )
			m_RV_Error |= REPORT_2_ERR;
		if(m_L_bEnableUnit && fabs(p_LH_SensorCurValue-p_LH_SensorPreValue) > 1 )
			m_LH_Error |= REPORT_3_ERR;
		if(m_L_bEnableUnit && fabs(p_LV_SensorCurValue-p_LV_SensorPreValue) > 1 )
			m_LV_Error |= REPORT_3_ERR;
		if(m_R_bEnableUnit && fabs(p_RH_SensorCurValue-p_RH_SensorPreValue) > 1 ) 
			m_RH_Error |= REPORT_3_ERR;
		if(m_R_bEnableUnit && fabs(p_RV_SensorCurValue-p_RV_SensorPreValue) > 1 ) 
			m_RV_Error |= REPORT_3_ERR;
		/*
		if(m_L_bEnableUnit && fabs(LH_SensorCurValue-LH_SensorCalibPos) > 3 )
			m_LH_Error |= REPORT_4_ERR;
		if(m_L_bEnableUnit && fabs(LV_SensorCurValue-LV_SensorCalibPos) > 3 )
			m_LV_Error |= REPORT_4_ERR;
		if(m_R_bEnableUnit && fabs(RH_SensorCurValue-RH_SensorCalibPos) > 3 )
			m_RH_Error |= REPORT_4_ERR;
		if(m_R_bEnableUnit && fabs(RV_SensorCurValue-RV_SensorCalibPos) > 3 )
			m_RV_Error |= REPORT_4_ERR;
		*/
		if(m_L_bEnableUnit && fabs(LH_SensorCurValue-m_LH_SensorDstValue) > 3 )
			m_LH_Error |= REPORT_4_ERR;
		if(m_L_bEnableUnit && fabs(LV_SensorCurValue-m_LV_SensorDstValue) > 3 )
			m_LV_Error |= REPORT_4_ERR;
		if(m_R_bEnableUnit && fabs(RH_SensorCurValue-m_RH_SensorDstValue) > 3 )
			m_RH_Error |= REPORT_4_ERR;
		if(m_R_bEnableUnit && fabs(RV_SensorCurValue-m_RV_SensorDstValue) > 3 )
			m_RV_Error |= REPORT_4_ERR;	
		if( (m_L_SMWCurSpeed < 1E-2 && m_R_SMWCurSpeed > 0.3) || bTrainStopMove )
			m_L_nErr6Times++;
		else
			m_L_nErr6Times=0;

		if( (m_R_SMWCurSpeed < 1E-2 && m_L_SMWCurSpeed > 0.3) || bTrainStopMove )
			m_R_nErr6Times++;
		else
			m_R_nErr6Times=0;	

		if(m_L_nErr6Times >= 2){
			m_LH_Error |= REPORT_6_ERR;
			m_L_nErr6Times=0;
		}
		if(m_R_nErr6Times >= 2){
			m_RH_Error |= REPORT_6_ERR;
			m_R_nErr6Times=0;	
		}

		if( bTrainSpeedNormal == false )
			m_nErr11Times++;//
		else
			m_nErr11Times=0;

		//if( m_nErr11Times >= 3 ){	//	速度监控时间为3*50ms ligy 20190910 add
		//	m_LH_Error |= REPORT_11_ERR;
		//	m_nErr11Times = 0;
		//}
		if( m_nErr11Times >= iMonitorTimes ){ //	速度监控时间为m_DstTrainSpeedDiffTime除以定时器时间(50ms) ligy 20190910 add
			m_LH_Error |= REPORT_11_ERR;
			m_nErr11Times = 0;
		}

		if( m_LH_Error == REPORT_NO_ERR && m_LV_Error == REPORT_NO_ERR && 
			m_RH_Error == REPORT_NO_ERR && m_RV_Error == REPORT_NO_ERR )
			bSuddenChange = false;
		else
			bSuddenChange = true;
		break;
	default:
		break;
	}
	m_LH_PreData = m_LH_CurData;
	m_LV_PreData = m_LV_CurData;
	m_RH_PreData = m_RH_CurData;
	m_RV_PreData = m_RV_CurData;
	return bSuddenChange;
}

void GlobalData::sensorFollowingIni( int nWorkState )
{
	SlQCap nWriteServer;
	SlCapErrorEnum nError;
	double LV_Belta,RV_Belta;

	switch(nWorkState)
	{
	case WORKSTATE_ADJUST:
		m_bMillingProcessed = true;
		m_LastSensorAdjustTime = QTime::currentTime();
		break;
	case WORKSTATE_STARTFELLOW:
		m_LastStartFellowTime = QTime::currentTime();
		m_L_nErr6Times = 0;
		m_R_nErr6Times = 0;
		m_nErr11Times = 0;
		m_bMillingProcessed = false;

		m_LH_YFollowIniPos = m_LH_CurData.SensorValue;
		m_LV_YFollowIniPos = m_LV_CurData.SensorValue;
		m_RH_YFollowIniPos = m_RH_CurData.SensorValue;
		m_RV_YFollowIniPos = m_RV_CurData.SensorValue;
		//this is very important!!!
		m_LH_MotorPreDstPos = m_LH_MotorCurPos;
		m_LV_MotorPreDstPos = m_LV_MotorCurPos;
		m_RH_MotorPreDstPos = m_RH_MotorCurPos;
		m_RV_MotorPreDstPos = m_RV_MotorCurPos;
		m_LH_SensorPreDstValue = m_LH_CurData.SensorValue;
		m_LV_SensorPreDstValue = m_LV_CurData.SensorValue;
		m_RH_SensorPreDstValue = m_RH_CurData.SensorValue;
		m_RV_SensorPreDstValue = m_RV_CurData.SensorValue;
		m_LH_PreData = m_LH_CurData;
		m_LV_PreData = m_LV_CurData;
		m_RH_PreData = m_RH_CurData;
		m_RV_PreData = m_RV_CurData;
		m_LH_SensorCalibPos = m_LH_SensorCalibPos1*m_LH_SensorRatio+m_LH_SensorCalibPos2*(1-m_LH_SensorRatio);
		m_LV_SensorCalibPos = m_LV_SensorCalibPos1*m_LV_SensorRatio+m_LV_SensorCalibPos2*(1-m_LV_SensorRatio);
		m_RH_SensorCalibPos = m_RH_SensorCalibPos1*m_RH_SensorRatio+m_RH_SensorCalibPos2*(1-m_RH_SensorRatio);
		m_RV_SensorCalibPos = m_RV_SensorCalibPos1*m_RV_SensorRatio+m_RV_SensorCalibPos2*(1-m_RV_SensorRatio);
		LV_Belta = 2-m_LV_SensorRatio;
		RV_Belta = 2-m_RV_SensorRatio;
		LV_Belta = LV_Belta < 1 ? 1 : LV_Belta;
		RV_Belta = RV_Belta < 1 ? 1 : RV_Belta;
		m_LH_CutDepth_R = (m_LH_CutDepth+m_LH_CutDepthOffset);
		m_LV_CutDepth_R = (m_LV_CutDepth+m_LV_CutDepthOffset)/LV_Belta;
		m_RH_CutDepth_R = (m_RH_CutDepth+m_RH_CutDepthOffset);
		m_RV_CutDepth_R = (m_RV_CutDepth+m_RV_CutDepthOffset)/RV_Belta;
		break;
	case WORKSTATE_YFELLOW2:
		nError = nWriteServer.write(szItem_EndSlopeOut_Bit,QVariant(true));//M30.7:顺坡切出完成
	case WORKSTATE_YFELLOW:
		m_LH_YFollowIniPos = m_LH_CurData.SensorValue;
		m_LV_YFollowIniPos = m_LV_CurData.SensorValue;
		m_RH_YFollowIniPos = m_RH_CurData.SensorValue;
		m_RV_YFollowIniPos = m_RV_CurData.SensorValue;
		break;
	case WORKSTATE_ENDFELLOW:
		/*
		m_LH_YFollowIniPos = (m_LH_bSensorChoose == true) ? 
			m_LH_SensorCurValue1 : m_LH_SensorCurValue2;
		m_LV_YFollowIniPos = (m_LV_bSensorChoose == true) ? 
			m_LV_SensorCurValue1 : m_LV_SensorCurValue2;
		m_RH_YFollowIniPos = (m_RH_bSensorChoose == true) ? 
			m_RH_SensorCurValue1 : m_RH_SensorCurValue2;
		m_RV_YFollowIniPos = (m_RV_bSensorChoose == true) ? 
			m_RV_SensorCurValue1 : m_RV_SensorCurValue2;
		*/
		m_LH_YFollowIniPos = m_LH_CurData.SensorValue;
		m_LV_YFollowIniPos = m_LV_CurData.SensorValue;
		m_RH_YFollowIniPos = m_RH_CurData.SensorValue;
		m_RV_YFollowIniPos = m_RV_CurData.SensorValue;
		break;
	case WORKSTATE_WORKIN:
		m_LH_CutBias = 0;
		m_LV_CutBias = 0;
		m_RH_CutBias = 0;
		m_RV_CutBias = 0;
		m_LH_PreCutBias = 0;
		m_LV_PreCutBias = 0;
		m_RH_PreCutBias = 0;
		m_RV_PreCutBias = 0;
		m_LH_CutBiasStep = 0;
		m_LV_CutBiasStep = 0;
		m_RH_CutBiasStep = 0;
		m_RV_CutBiasStep = 0;
		break;
	case WORKSTATE_WORKOUT:
		m_LH_CutBias = 0;
		m_LV_CutBias = 0;
		m_RH_CutBias = 0;
		m_RV_CutBias = 0;
		m_LH_PreCutBias = 0;
		m_LV_PreCutBias = 0;
		m_RH_PreCutBias = 0;
		m_RV_PreCutBias = 0;
		m_LH_CutBiasStep = 0;
		m_LV_CutBiasStep = 0;
		m_RH_CutBiasStep = 0;
		m_RV_CutBiasStep = 0;
		break;
	case WORKSTATE_CUTIN:
		m_L_SMWInit = m_L_SMWCurPos;
		m_R_SMWInit = m_R_SMWCurPos; 
		break;
	case WORKSTATE_CUTOUT:
		m_L_SMWInit = m_L_SMWCurPos;
		m_R_SMWInit = m_R_SMWCurPos; 
		break;
	case WORKSTATE_MILLING:
		nError = nWriteServer.write(szItem_EndSlopeIn_Bit,QVariant(true));
		break;
	default:
		break;
	}
	m_LH_IsActionOver = true;
	m_LV_IsActionOver = true;
	m_RH_IsActionOver = true;
	m_RV_IsActionOver = true;
}

void GlobalData::sensorFollowing(int nWorkState)
{
	if(nWorkState == WORKSTATE_STARTFELLOW){
		sensorFollowing(m_LH_YFollowIniPos, m_H_RapidSpeed,
						m_RH_YFollowIniPos, m_H_RapidSpeed,
						m_LV_YFollowIniPos, m_V_RapidSpeed,
						m_RV_YFollowIniPos, m_V_RapidSpeed
						);
	}
	else if(nWorkState == WORKSTATE_ADJUST){
		sensorFollowing(m_LH_SensorCalibPos + m_LH_RailOffset + m_H_DeviceIniPos, m_H_RapidSpeed/3,
						m_RH_SensorCalibPos + m_RH_RailOffset + m_H_DeviceIniPos, m_H_RapidSpeed/3,
						m_LV_SensorCalibPos + m_LV_RailOffset + m_V_DeviceIniPos, m_V_RapidSpeed/3,
						m_RV_SensorCalibPos + m_RV_RailOffset + m_V_DeviceIniPos, m_V_RapidSpeed/3 
						);
	}
	else if(nWorkState == WORKSTATE_YFELLOW){
		sensorFollowing(m_LH_SensorCalibPos + m_LH_RailOffset + m_H_DeviceIniPos, m_H_RapidSpeed,
						m_RH_SensorCalibPos + m_RH_RailOffset + m_H_DeviceIniPos, m_H_RapidSpeed,
						m_LV_SensorCalibPos + m_LV_RailOffset + m_V_DeviceIniPos, m_V_RapidSpeed,
						m_RV_SensorCalibPos + m_RV_RailOffset + m_V_DeviceIniPos, m_V_RapidSpeed 
						);
	}
	else if(nWorkState == WORKSTATE_WORKIN){
		sensorFollowing(m_LH_SensorCalibPos + m_LH_RailOffset + m_H_WorkIniPos, m_H_RapidSpeed/3,
						m_RH_SensorCalibPos + m_RH_RailOffset + m_H_WorkIniPos, m_H_RapidSpeed/3,
						m_LV_SensorCalibPos + m_LV_RailOffset + m_V_WorkIniPos, m_V_RapidSpeed/3,
						m_RV_SensorCalibPos + m_RV_RailOffset + m_V_WorkIniPos, m_V_RapidSpeed/3
						);
	}
	else if(nWorkState == WORKSTATE_CUTIN){
		double LH_CutInDepth = m_H_WorkIniPos+ m_LH_CutDepth_R;
		double LV_CutInDepth = m_V_WorkIniPos+ m_LV_CutDepth_R;
		double RH_CutInDepth = m_H_WorkIniPos+ m_RH_CutDepth_R;
		double RV_CutInDepth = m_V_WorkIniPos+ m_RV_CutDepth_R;
		double LH_Temp = LH_CutInDepth*(m_L_SMWCurPos-m_L_SMWInit)/m_SlopeLength;
		double LV_Temp = LV_CutInDepth*(m_L_SMWCurPos-m_L_SMWInit)/m_SlopeLength;
		double RH_Temp = RH_CutInDepth*(m_R_SMWCurPos-m_R_SMWInit)/m_SlopeLength;
		double RV_Temp = RV_CutInDepth*(m_R_SMWCurPos-m_R_SMWInit)/m_SlopeLength;
		LH_Temp = LH_Temp > LH_CutInDepth ? LH_CutInDepth : LH_Temp;
		LV_Temp = LV_Temp > LV_CutInDepth ? LV_CutInDepth : LV_Temp;
		RH_Temp = RH_Temp > RH_CutInDepth ? RH_CutInDepth : RH_Temp;
		RV_Temp = RV_Temp > RV_CutInDepth ? RV_CutInDepth : RV_Temp;
		LH_Temp = LH_Temp < 0 ? 0 : LH_Temp;
		LV_Temp = LV_Temp < 0 ? 0 : LV_Temp;
		RH_Temp = RH_Temp < 0 ? 0 : RH_Temp;
		RV_Temp = RV_Temp < 0 ? 0 : RV_Temp;
		sensorFollowing(m_LH_SensorCalibPos + m_LH_RailOffset + m_H_WorkIniPos - LH_Temp, m_H_RapidSpeed,
						m_RH_SensorCalibPos + m_RH_RailOffset + m_H_WorkIniPos - RH_Temp, m_H_RapidSpeed,
						m_LV_SensorCalibPos + m_LV_RailOffset + m_V_WorkIniPos - LV_Temp, m_V_RapidSpeed,
						m_RV_SensorCalibPos + m_RV_RailOffset + m_V_WorkIniPos - RV_Temp, m_V_RapidSpeed
						);
		/*
		sensorFollowing(m_LH_SensorCalibPos + m_LH_RailOffset + m_LH_CutDepth_R,
						m_RH_SensorCalibPos + m_RH_RailOffset + m_RH_CutDepth_R,
						m_LV_SensorCalibPos + m_LV_RailOffset + m_LV_CutDepth_R,
						m_RV_SensorCalibPos + m_RV_RailOffset + m_RV_CutDepth_R,
						m_SlopeLength );
		*/
	}
	else if(nWorkState == WORKSTATE_MILLING){
		sensorFollowing(m_LH_SensorCalibPos + m_LH_RailOffset - m_LH_CutDepth_R - m_LH_CutBiasStep,m_H_RapidSpeed,
						m_RH_SensorCalibPos + m_RH_RailOffset - m_RH_CutDepth_R - m_RH_CutBiasStep,m_H_RapidSpeed,
						m_LV_SensorCalibPos + m_LV_RailOffset - m_LV_CutDepth_R - m_LV_CutBiasStep,m_V_RapidSpeed,
						m_RV_SensorCalibPos + m_RV_RailOffset - m_RV_CutDepth_R - m_RV_CutBiasStep,m_V_RapidSpeed
						);
						//m_OffsetSlopeLength );
	}
	else if(nWorkState == WORKSTATE_CUTOUT){
		double LH_CutOutDepth = m_H_WorkIniPos+m_LH_CutDepth_R+m_LH_CutBiasStep;
		double LV_CutOutDepth = m_V_WorkIniPos+m_LV_CutDepth_R+m_LV_CutBiasStep;
		double RH_CutOutDepth = m_H_WorkIniPos+m_RH_CutDepth_R+m_RH_CutBiasStep;
		double RV_CutOutDepth = m_V_WorkIniPos+m_RV_CutDepth_R+m_RV_CutBiasStep;
		double LH_Temp = LH_CutOutDepth*(m_L_SMWCurPos-m_L_SMWInit)/m_SlopeLength;
		double LV_Temp = LV_CutOutDepth*(m_L_SMWCurPos-m_L_SMWInit)/m_SlopeLength;
		double RH_Temp = RH_CutOutDepth*(m_R_SMWCurPos-m_R_SMWInit)/m_SlopeLength;
		double RV_Temp = RV_CutOutDepth*(m_R_SMWCurPos-m_R_SMWInit)/m_SlopeLength;
		LH_Temp = LH_Temp > LH_CutOutDepth ? LH_CutOutDepth : LH_Temp;
		LV_Temp = LV_Temp > LV_CutOutDepth ? LV_CutOutDepth : LV_Temp;
		RH_Temp = RH_Temp > RH_CutOutDepth ? RH_CutOutDepth : RH_Temp;
		RV_Temp = RV_Temp > RV_CutOutDepth ? RV_CutOutDepth : RV_Temp;
		LH_Temp = LH_Temp < 0 ? 0 : LH_Temp;
		LV_Temp = LV_Temp < 0 ? 0 : LV_Temp;
		RH_Temp = RH_Temp < 0 ? 0 : RH_Temp;
		RV_Temp = RV_Temp < 0 ? 0 : RV_Temp;
		sensorFollowing(m_LH_SensorCalibPos + m_LH_RailOffset - m_LH_CutDepth_R - m_LH_CutBiasStep + LH_Temp, m_H_RapidSpeed,
						m_RH_SensorCalibPos + m_RH_RailOffset - m_RH_CutDepth_R - m_RH_CutBiasStep + RH_Temp, m_H_RapidSpeed,
						m_LV_SensorCalibPos + m_LV_RailOffset - m_LV_CutDepth_R - m_LV_CutBiasStep + LV_Temp, m_V_RapidSpeed,
						m_RV_SensorCalibPos + m_RV_RailOffset - m_RV_CutDepth_R - m_RV_CutBiasStep + RV_Temp, m_V_RapidSpeed
						);
	}
	else if(nWorkState == WORKSTATE_WORKOUT){
		sensorFollowing(m_LH_SensorCalibPos + m_LH_RailOffset + m_H_DeviceIniPos, m_H_RapidSpeed/3,
						m_RH_SensorCalibPos + m_RH_RailOffset + m_H_DeviceIniPos, m_H_RapidSpeed/3,
						m_LV_SensorCalibPos + m_LV_RailOffset + m_V_DeviceIniPos, m_V_RapidSpeed/3,
						m_RV_SensorCalibPos + m_RV_RailOffset + m_V_DeviceIniPos, m_V_RapidSpeed/3 
						);
	}
	else if(nWorkState == WORKSTATE_YFELLOW2){
		sensorFollowing(m_LH_SensorCalibPos + m_LH_RailOffset + m_H_DeviceIniPos, m_H_RapidSpeed,
						m_RH_SensorCalibPos + m_RH_RailOffset + m_H_DeviceIniPos, m_H_RapidSpeed,
						m_LV_SensorCalibPos + m_LV_RailOffset + m_V_DeviceIniPos, m_V_RapidSpeed,
						m_RV_SensorCalibPos + m_RV_RailOffset + m_V_DeviceIniPos, m_V_RapidSpeed 
						);
	}
	else if(nWorkState == WORKSTATE_ENDFELLOW){
		if( m_bMillingProcessed ){
			sensorFollowing(m_LH_SensorCalibPos + m_LH_RailOffset + m_H_DeviceIniPos, m_H_RapidSpeed,
							m_RH_SensorCalibPos + m_RH_RailOffset + m_H_DeviceIniPos, m_H_RapidSpeed,
							m_LV_SensorCalibPos + m_LV_RailOffset + m_V_DeviceIniPos, m_V_RapidSpeed,
							m_RV_SensorCalibPos + m_RV_RailOffset + m_V_DeviceIniPos, m_V_RapidSpeed 
							);
		}
		else{
			sensorFollowing(m_LH_YFollowIniPos, m_H_RapidSpeed,
							m_RH_YFollowIniPos, m_H_RapidSpeed,
							m_LV_YFollowIniPos, m_V_RapidSpeed,
							m_RV_YFollowIniPos, m_V_RapidSpeed
							);
		}
	}
}

void GlobalData::sensorFollowing(double LH_SensorDstValue,double LH_DstSpeed,
								 double RH_SensorDstValue,double RH_DstSpeed,
								 double LV_SensorDstValue,double LV_DstSpeed,
								 double RV_SensorDstValue,double RV_DstSpeed,
								 double H_Dif			 ,double V_Dif )
{
	double LH_MinDiffPos=H_Dif , LV_MinDiffPos=V_Dif;
	double RH_MinDiffPos=H_Dif , RV_MinDiffPos=V_Dif;

	double LH_MaxDiff=0.40 , LV_MaxDiff=0.40;
	double RH_MaxDiff=0.40 , RV_MaxDiff=0.40;

	if( m_nWorkState == WORKSTATE_STARTFELLOW_INI || m_nWorkState == WORKSTATE_STARTFELLOW ||
		m_nWorkState == WORKSTATE_YFELLOW_INI || m_nWorkState == WORKSTATE_YFELLOW ||
		m_nWorkState == WORKSTATE_YFELLOW2_INI || m_nWorkState == WORKSTATE_YFELLOW2 ||
		m_nWorkState == WORKSTATE_ENDFELLOW_INI || m_nWorkState == WORKSTATE_ENDFELLOW
		)
	{
		LH_MaxDiff=0.50 , LV_MaxDiff=0.50;
		RH_MaxDiff=0.50 , RV_MaxDiff=0.50;
	}

	if(m_L_bEnableUnit){
		if( m_LH_IsActionOver == true ){
			m_LH_SensorDstValue = LH_SensorDstValue;
			double	LH_SensorDiffValue = m_LH_CurData.SensorValue - m_LH_SensorDstValue;
			m_LH_MotorDstPos = LH_SensorDiffValue + m_LH_MotorCurPos;			//m_LH_CurData.MotorPos;
			m_LH_MotorDstSpeed = LH_DstSpeed;
			m_LH_IsActionOver = false;
		}
		else{
			double	LH_MotorDiffPos = m_LH_MotorPreDstPos - m_LH_MotorCurPos;
			if( fabs(LH_MotorDiffPos) < LH_MinDiffPos ){
				m_LH_IsActionOver = true;	
			}
			// Add By XiangTing's Advice
			else if( !(m_nWorkState == WORKSTATE_ADJUST_INI || m_nWorkState == WORKSTATE_ADJUST ||
					   m_nWorkState == WORKSTATE_WORKIN_INI || m_nWorkState == WORKSTATE_WORKIN ||
					   m_nWorkState == WORKSTATE_WORKOUT_INI|| m_nWorkState == WORKSTATE_WORKOUT) ){
				double	LH_SensorDiffValue = m_LH_CurData.SensorValue - m_LH_SensorDstValue;
				double	f_LH_MotorDstPos = LH_SensorDiffValue + m_LH_MotorCurPos;	//m_LH_CurData.MotorPos;
				if( fabs(f_LH_MotorDstPos - m_LH_MotorPreDstPos) > LH_MaxDiff ){
					m_LH_MotorDstPos = f_LH_MotorDstPos;
					m_LH_MotorDstSpeed = LH_DstSpeed;
					m_LH_IsActionOver = false;
				}
			}
		}
		if( m_LV_IsActionOver == true ){
			m_LV_SensorDstValue = LV_SensorDstValue;
			double	LV_SensorDiffValue = m_LV_CurData.SensorValue - m_LV_SensorDstValue;
			m_LV_MotorDstPos = LV_SensorDiffValue + m_LV_MotorCurPos;			//m_LV_CurData.MotorPos;
			m_LV_MotorDstSpeed = LV_DstSpeed;
			m_LV_IsActionOver = false;
		}
		else{
			double	LV_MotorDiffPos = m_LV_MotorPreDstPos - m_LV_MotorCurPos;
			if( fabs(LV_MotorDiffPos) < LV_MinDiffPos ){
				m_LV_IsActionOver = true;
			}
			// Add By XiangTing's Advice
			else if( !(m_nWorkState == WORKSTATE_ADJUST_INI || m_nWorkState == WORKSTATE_ADJUST ||
					   m_nWorkState == WORKSTATE_WORKIN_INI || m_nWorkState == WORKSTATE_WORKIN ||
					   m_nWorkState == WORKSTATE_WORKOUT_INI|| m_nWorkState == WORKSTATE_WORKOUT) ){
				double	LV_SensorDiffValue = m_LV_CurData.SensorValue - m_LV_SensorDstValue ;
				double	f_LV_MotorDstPos = LV_SensorDiffValue + m_LV_MotorCurPos;	//m_LV_CurData.MotorPos;
				if( fabs(f_LV_MotorDstPos - m_LV_MotorPreDstPos) > LV_MaxDiff ){
					m_LV_MotorDstPos = f_LV_MotorDstPos;
					m_LV_MotorDstSpeed = LV_DstSpeed;
					m_LV_IsActionOver = false;
				}
			}
		}
	}
	if(m_R_bEnableUnit){
		if( m_RH_IsActionOver == true ){
			m_RH_SensorDstValue = RH_SensorDstValue;
			double  RH_SensorDiffValue = m_RH_CurData.SensorValue - m_RH_SensorDstValue;
			m_RH_MotorDstPos = RH_SensorDiffValue + m_RH_MotorCurPos;			//m_RH_CurData.MotorPos;
			m_RH_MotorDstSpeed = RH_DstSpeed;
			m_RH_IsActionOver = false;
		}
		else{
			double  RH_MotorDiffPos = m_RH_MotorPreDstPos - m_RH_MotorCurPos;
			if( fabs(RH_MotorDiffPos) < RH_MinDiffPos ){
				m_RH_IsActionOver = true;
			}
			// Add By XiangTing's Advice
			else if( !(m_nWorkState == WORKSTATE_ADJUST_INI || m_nWorkState == WORKSTATE_ADJUST ||
					   m_nWorkState == WORKSTATE_WORKIN_INI || m_nWorkState == WORKSTATE_WORKIN ||
					   m_nWorkState == WORKSTATE_WORKOUT_INI|| m_nWorkState == WORKSTATE_WORKOUT) ){
				double	RH_SensorDiffValue = m_RH_CurData.SensorValue - m_RH_SensorDstValue;
				double	f_RH_MotorDstPos = RH_SensorDiffValue + m_RH_MotorCurPos;	//m_RH_CurData.MotorPos;
				if( fabs(f_RH_MotorDstPos - m_RH_MotorPreDstPos) > RH_MaxDiff ){
					m_RH_MotorDstPos = f_RH_MotorDstPos;
					m_RH_MotorDstSpeed = RH_DstSpeed;
					m_RH_IsActionOver = false;
				}
			}
		}	 
		if(m_RV_IsActionOver == true){
			m_RV_SensorDstValue = RV_SensorDstValue;
			double  RV_SensorDiffValue = m_RV_CurData.SensorValue - m_RV_SensorDstValue;
			m_RV_MotorDstPos = RV_SensorDiffValue + m_RV_MotorCurPos;			//m_RV_CurData.MotorPos;
			m_RV_MotorDstSpeed = RV_DstSpeed;
			m_RV_IsActionOver = false;
		}
		else{
			double  RV_MotorDiffPos = m_RV_MotorPreDstPos - m_RV_MotorCurPos;
			if( fabs(RV_MotorDiffPos) < RV_MinDiffPos ){
				m_RV_IsActionOver = true;
			}
			// Add By XiangTing's Advice
			else if( !(m_nWorkState == WORKSTATE_ADJUST_INI || m_nWorkState == WORKSTATE_ADJUST ||
					   m_nWorkState == WORKSTATE_WORKIN_INI || m_nWorkState == WORKSTATE_WORKIN ||
					   m_nWorkState == WORKSTATE_WORKOUT_INI|| m_nWorkState == WORKSTATE_WORKOUT) ){
				double	RV_SensorDiffValue = m_RV_CurData.SensorValue - m_RV_SensorDstValue;
				double	f_RV_MotorDstPos = RV_SensorDiffValue + m_RV_MotorCurPos;	//m_RV_CurData.MotorPos;
				if( fabs(f_RV_MotorDstPos - m_RV_MotorPreDstPos) > RV_MaxDiff ){
					m_RV_MotorDstPos = f_RV_MotorDstPos;
					m_RV_MotorDstSpeed = RV_DstSpeed;
					m_RV_IsActionOver = false;
				}
			}
		}
	}
}

void GlobalData::sensorFollowing(double LH_SensorDstValue,double RH_SensorDstValue,
								 double LV_SensorDstValue,double RV_SensorDstValue,
								 double SlopeLength,
								 double H_Dif			 ,double V_Dif )
{
	double LH_MinDiffPos=H_Dif , LV_MinDiffPos=V_Dif;
	double RH_MinDiffPos=H_Dif , RV_MinDiffPos=V_Dif;

	double LH_MaxDiff=0.40 , LV_MaxDiff=0.40;
	double RH_MaxDiff=0.40 , RV_MaxDiff=0.40;

	if( m_nWorkState == WORKSTATE_STARTFELLOW_INI || m_nWorkState == WORKSTATE_STARTFELLOW ||
		m_nWorkState == WORKSTATE_YFELLOW_INI || m_nWorkState == WORKSTATE_YFELLOW ||
		m_nWorkState == WORKSTATE_YFELLOW2_INI || m_nWorkState == WORKSTATE_YFELLOW2 ||
		m_nWorkState == WORKSTATE_ENDFELLOW_INI || m_nWorkState == WORKSTATE_ENDFELLOW
		)
	{
		LH_MaxDiff=0.50 , LV_MaxDiff=0.50;
		RH_MaxDiff=0.50 , RV_MaxDiff=0.50;
	}

	if(m_L_bEnableUnit){
		if( m_LH_IsActionOver == true ){
			m_LH_SensorDstValue = LH_SensorDstValue;
			double	LH_SensorDiffValue = m_LH_CurData.SensorValue - m_LH_SensorDstValue;
			m_LH_MotorDstPos = LH_SensorDiffValue + m_LH_MotorCurPos;			//m_LH_CurData.MotorPos;
			m_LH_MotorDstSpeed = fabs(m_LH_MotorDstPos)/SlopeLength/m_DstTrainSpeed;
			m_LH_IsActionOver = false;
		}
		else{
			double	LH_MotorDiffPos = m_LH_MotorPreDstPos - m_LH_MotorCurPos;
			if( fabs(LH_MotorDiffPos) < LH_MinDiffPos ){
				m_LH_IsActionOver = true;	
			}
			// Add By XiangTing's Advice
			else if( !(m_nWorkState == WORKSTATE_ADJUST_INI || m_nWorkState == WORKSTATE_ADJUST ||
					   m_nWorkState == WORKSTATE_WORKIN_INI || m_nWorkState == WORKSTATE_WORKIN ||
					   m_nWorkState == WORKSTATE_WORKOUT_INI|| m_nWorkState == WORKSTATE_WORKOUT) ){
				double	LH_SensorDiffValue = m_LH_CurData.SensorValue - m_LH_SensorDstValue;
				double	f_LH_MotorDstPos = LH_SensorDiffValue + m_LH_MotorCurPos;	//m_LH_CurData.MotorPos;
				if( fabs(f_LH_MotorDstPos - m_LH_MotorPreDstPos) > LH_MaxDiff ){
					m_LH_MotorDstPos = f_LH_MotorDstPos;
					m_LH_MotorDstSpeed = fabs(m_LH_MotorDstPos)/SlopeLength/m_DstTrainSpeed;
					m_LH_IsActionOver = false;
				}
			}
		}
		if( m_LV_IsActionOver == true ){
			m_LV_SensorDstValue = LV_SensorDstValue;
			double	LV_SensorDiffValue = m_LV_CurData.SensorValue - m_LV_SensorDstValue;
			m_LV_MotorDstPos = LV_SensorDiffValue + m_LV_MotorCurPos;			//m_LV_CurData.MotorPos;
			m_LV_MotorDstSpeed = fabs(m_LV_MotorDstPos)/SlopeLength/m_DstTrainSpeed;
			m_LV_IsActionOver = false;
		}
		else{
			double	LV_MotorDiffPos = m_LV_MotorPreDstPos - m_LV_MotorCurPos;
			if( fabs(LV_MotorDiffPos) < LV_MinDiffPos ){
				m_LV_IsActionOver = true;
			}
			// Add By XiangTing's Advice
			else if( !(m_nWorkState == WORKSTATE_ADJUST_INI || m_nWorkState == WORKSTATE_ADJUST ||
					   m_nWorkState == WORKSTATE_WORKIN_INI || m_nWorkState == WORKSTATE_WORKIN ||
					   m_nWorkState == WORKSTATE_WORKOUT_INI|| m_nWorkState == WORKSTATE_WORKOUT) ){
				double	LV_SensorDiffValue = m_LV_CurData.SensorValue - m_LV_SensorDstValue;
				double	f_LV_MotorDstPos = LV_SensorDiffValue + m_LV_MotorCurPos;	//m_LV_CurData.MotorPos;
				if( fabs(f_LV_MotorDstPos - m_LV_MotorPreDstPos) > LV_MaxDiff ){
					m_LV_MotorDstPos = f_LV_MotorDstPos;
					m_LV_MotorDstSpeed = fabs(m_LV_MotorDstPos)/SlopeLength/m_DstTrainSpeed;
					m_LV_IsActionOver = false;
				}
			}
		}
	}
	if(m_R_bEnableUnit){
		if( m_RH_IsActionOver == true ){
			m_RH_SensorDstValue = RH_SensorDstValue;
			double  RH_SensorDiffValue = m_RH_CurData.SensorValue - m_RH_SensorDstValue;
			m_RH_MotorDstPos = RH_SensorDiffValue + m_RH_MotorCurPos;			//m_RH_CurData.MotorPos;
			m_RH_MotorDstSpeed = fabs(m_RH_MotorDstPos)/SlopeLength/m_DstTrainSpeed;
			m_RH_IsActionOver = false;
		}
		else{
			double  RH_MotorDiffPos = m_RH_MotorPreDstPos - m_RH_MotorCurPos;
			if( fabs(RH_MotorDiffPos) < RH_MinDiffPos ){
				m_RH_IsActionOver = true;
			}
			// Add By XiangTing's Advice
			else if( !(m_nWorkState == WORKSTATE_ADJUST_INI || m_nWorkState == WORKSTATE_ADJUST ||
					   m_nWorkState == WORKSTATE_WORKIN_INI || m_nWorkState == WORKSTATE_WORKIN ||
					   m_nWorkState == WORKSTATE_WORKOUT_INI|| m_nWorkState == WORKSTATE_WORKOUT) ){
				double	RH_SensorDiffValue = m_RH_CurData.SensorValue - m_RH_SensorDstValue;
				double	f_RH_MotorDstPos = RH_SensorDiffValue + m_RH_MotorCurPos;	//m_RH_CurData.MotorPos;
				if( fabs(f_RH_MotorDstPos - m_RH_MotorPreDstPos) > RH_MaxDiff ){
					m_RH_MotorDstPos = f_RH_MotorDstPos;
					m_RH_MotorDstSpeed = fabs(m_RH_MotorDstPos)/SlopeLength/m_DstTrainSpeed;
					m_RH_IsActionOver = false;
				}
			}
		}	 
		if(m_RV_IsActionOver == true){
			m_RV_SensorDstValue = RV_SensorDstValue;
			double  RV_SensorDiffValue = m_RV_CurData.SensorValue - m_RV_SensorDstValue;
			m_RV_MotorDstPos = RV_SensorDiffValue + m_RV_MotorCurPos;			//m_RV_CurData.MotorPos;
			m_RV_MotorDstSpeed = fabs(m_RV_MotorDstPos)/SlopeLength/m_DstTrainSpeed;
			m_RV_IsActionOver = false;
		}
		else{
			double  RV_MotorDiffPos = m_RV_MotorPreDstPos - m_RV_MotorCurPos;
			if( fabs(RV_MotorDiffPos) < RV_MinDiffPos ){
				m_RV_IsActionOver = true;
			}
			// Add By XiangTing's Advice
			else if( !(m_nWorkState == WORKSTATE_ADJUST_INI || m_nWorkState == WORKSTATE_ADJUST ||
					   m_nWorkState == WORKSTATE_WORKIN_INI || m_nWorkState == WORKSTATE_WORKIN ||
					   m_nWorkState == WORKSTATE_WORKOUT_INI|| m_nWorkState == WORKSTATE_WORKOUT) ){
				double	RV_SensorDiffValue = m_RV_CurData.SensorValue - m_RV_SensorDstValue;
				double	f_RV_MotorDstPos = RV_SensorDiffValue + m_RV_MotorCurPos;	//m_RV_CurData.MotorPos;
				if( fabs(f_RV_MotorDstPos - m_RV_MotorPreDstPos) > RV_MaxDiff ){
					m_RV_MotorDstPos = f_RV_MotorDstPos;
					m_RV_MotorDstSpeed = fabs(m_RV_MotorDstPos)/SlopeLength/m_DstTrainSpeed;
					m_RV_IsActionOver = false;
				}
			}
		}
	}
}

void GlobalData::CutterSoftProtect( int nWorkState )
{
	switch(nWorkState)
	{
	case WORKSTATE_ADJUST:
		break;
	case WORKSTATE_STARTFELLOW:
	case WORKSTATE_YFELLOW:
	case WORKSTATE_YFELLOW2:
	case WORKSTATE_ENDFELLOW:
		if((m_LH_MotorDstPos - m_LH_MotorPreDstPos) > m_LH_CutterProtect)
			m_LH_MotorDstPos = m_LH_MotorPreDstPos + m_LH_CutterProtect;
		//if((m_LH_MotorDstPos - m_LH_MotorPreDstPos) < -0.5)
		//	m_LH_MotorDstPos = m_LH_MotorPreDstPos - 0.5;				
		if((m_RH_MotorDstPos - m_RH_MotorPreDstPos) > m_RH_CutterProtect)
			m_RH_MotorDstPos = m_RH_MotorPreDstPos + m_RH_CutterProtect;
		//if((m_RH_MotorDstPos - m_RH_MotorPreDstPos) < -0.5)
		//	m_RH_MotorDstPos = m_RH_MotorPreDstPos - 0.5;
		break;
	case WORKSTATE_WORKIN:
	case WORKSTATE_WORKOUT:
	case WORKSTATE_CUTIN:
	case WORKSTATE_CUTOUT:
		break;
	case WORKSTATE_MILLING:
		if((m_LH_MotorDstPos - m_LH_MotorPreDstPos) > m_LH_CutterProtect)
			m_LH_MotorDstPos = m_LH_MotorPreDstPos + m_LH_CutterProtect;
		//if((m_LH_MotorDstPos - m_LH_MotorPreDstPos) < -0.5)
		//	m_LH_MotorDstPos = m_LH_MotorPreDstPos - 0.5;				
		if((m_LV_MotorDstPos - m_LV_MotorPreDstPos) > m_LV_CutterProtect)
			m_LV_MotorDstPos = m_LV_MotorPreDstPos + m_LV_CutterProtect;
		//if((m_LV_MotorDstPos - m_LV_MotorPreDstPos) < -0.5)
		//	m_LV_MotorDstPos = m_LV_MotorPreDstPos - 0.5;
		if((m_RH_MotorDstPos - m_RH_MotorPreDstPos) > m_RH_CutterProtect)
			m_RH_MotorDstPos = m_RH_MotorPreDstPos + m_RH_CutterProtect;
		//if((m_RH_MotorDstPos - m_RH_MotorPreDstPos) < -0.5)
		//	m_RH_MotorDstPos = m_RH_MotorPreDstPos - 0.5;				
		if((m_RV_MotorDstPos - m_RV_MotorPreDstPos) > m_RV_CutterProtect)
			m_RV_MotorDstPos = m_RV_MotorPreDstPos + m_RV_CutterProtect;
		//if((m_RV_MotorDstPos - m_RV_MotorPreDstPos) < -0.5)
		//	m_RV_MotorDstPos = m_RV_MotorPreDstPos - 0.5;
		break;
	default:
		break;
	}

	bool bIsexceed = false;
	//Limit Protect!
	if( m_LH_MotorDstPos > m_LH_MotorPosHigh){
		bIsexceed = true;
		m_LH_MotorDstPos = m_LH_MotorPosHigh;
		if(m_L_bEnableUnit)
			m_LH_Error |= REPORT_9_ERR;
	}
	else if( m_LH_MotorDstPos < m_LH_MotorPosLow ){
		bIsexceed = true;
		m_LH_MotorDstPos = m_LH_MotorPosLow;
		if(m_L_bEnableUnit)
			m_LH_Error |= REPORT_9_ERR;
	}

	if( m_LV_MotorDstPos > m_LV_MotorPosHigh){
		bIsexceed = true;
		m_LV_MotorDstPos = m_LV_MotorPosHigh;
		if(m_L_bEnableUnit)
			m_LV_Error |= REPORT_9_ERR;
	}
	else if( m_LV_MotorDstPos < m_LV_MotorPosLow ){
		bIsexceed = true;
		m_LV_MotorDstPos = m_LV_MotorPosLow;
		if(m_L_bEnableUnit)
			m_LV_Error |= REPORT_9_ERR;
	}

	if( m_RH_MotorDstPos > m_RH_MotorPosHigh){
		bIsexceed = true;
		m_RH_MotorDstPos = m_RH_MotorPosHigh;
		if(m_R_bEnableUnit)
			m_RH_Error |= REPORT_9_ERR;
	}
	else if( m_RH_MotorDstPos < m_RH_MotorPosLow ){
		bIsexceed = true;
		m_RH_MotorDstPos = m_RH_MotorPosLow;
		if(m_R_bEnableUnit)
			m_RH_Error |= REPORT_9_ERR;
	}

	if( m_RV_MotorDstPos > m_RV_MotorPosHigh){
		bIsexceed = true;
		m_RV_MotorDstPos = m_RV_MotorPosHigh;
		if(m_R_bEnableUnit)
			m_RV_Error |= REPORT_9_ERR;
	}
	else if( m_RV_MotorDstPos < m_RV_MotorPosLow ){
		bIsexceed = true;
		m_RV_MotorDstPos = m_RV_MotorPosLow;
		if(m_R_bEnableUnit)
			m_RV_Error |= REPORT_9_ERR;
	}
	//return bIsexceed;
	return;
}


SlCapErrorEnum GlobalData::SendPosAndSpeed( int nWorkState ,bool bForceSend)
{
	double H_Dif,V_Dif;
	bool bEmergency = false;
	SlCapErrorEnum eError = SL_CAP_OK;
	switch(nWorkState)
	{
	case WORKSTATE_ADJUST:
		H_Dif = 0.08;
		V_Dif = 0.05;				//no use
		break;
	case WORKSTATE_STARTFELLOW:
	case WORKSTATE_YFELLOW:
	case WORKSTATE_YFELLOW2:
	case WORKSTATE_ENDFELLOW:
		H_Dif = 0.08;
		V_Dif = 0.05;				//no use
		break;
	case WORKSTATE_WORKIN:
		H_Dif = 0.01;
		V_Dif = 0.01;
		break;
	case WORKSTATE_CUTIN:
		H_Dif = 0.1;
		V_Dif = 0.1;
		break;
	case WORKSTATE_MILLING:
		H_Dif = m_H_MinCutStep;		//0.05
		V_Dif = m_V_MinCutStep;		//0.03
		break;
	case WORKSTATE_CUTOUT:
		H_Dif = 0.1;
		V_Dif = 0.1;
		break;
	case WORKSTATE_WORKOUT:
		H_Dif = 0.01;
		V_Dif = 0.01;
		break;
	case WORKSTATE_EMERGENCY_PCU:
		bEmergency = true;
		H_Dif = 1.00;
		V_Dif = 1.00;
		break;
	default:
		break;
	}
	if(bEmergency == false)
		eError = SendPosAndSpeed( H_Dif,V_Dif ,bForceSend);//发送位置和速度 ligy 20190910 add
	return eError;
}

SlCapErrorEnum GlobalData::SendPosAndSpeed(double H_Dif,double V_Dif ,bool bForceSend)
{
	QVector<SlCapWriteSpecType>	vecWriteSpec;
	SlCapErrorEnum eError = SL_CAP_OK;
	SlQCap	capServerWrite;
	bool is_LH_DstModify = false , is_LV_DstModify = false;
	bool is_RH_DstModify = false , is_RV_DstModify = false;
	bool isTouchRail = false;
	bool isYfellow = false;//Y向跟随
	bool isMillingState = false;//铣削状态

	isTouchRail = ((m_nWorkState == WORKSTATE_ADJUST_INI)||(m_nWorkState == WORKSTATE_ADJUST))?
		true:false;
	isYfellow = ((m_nWorkState == WORKSTATE_YFELLOW_INI)||(m_nWorkState == WORKSTATE_YFELLOW) ||
				 (m_nWorkState == WORKSTATE_STARTFELLOW_INI)||(m_nWorkState == WORKSTATE_STARTFELLOW) ||
				 (m_nWorkState == WORKSTATE_YFELLOW2_INI)||(m_nWorkState == WORKSTATE_YFELLOW2) ||
				 (m_nWorkState == WORKSTATE_ENDFELLOW_INI)||(m_nWorkState == WORKSTATE_ENDFELLOW) )?
		true:false;
	isMillingState = ((m_nWorkState == WORKSTATE_MILLING_INI)||(m_nWorkState == WORKSTATE_MILLING))?
		true:false;

	if(m_L_bEnableUnit){//左铣削单元
		if( fabs(m_LH_MotorPreDstPos-m_LH_MotorDstPos) > H_Dif || bForceSend){
			is_LH_DstModify = true;
			vecWriteSpec.append( SlCapWriteSpecType(szItem_LH_MotorDstPos, QVariant(m_LH_MotorDstPos)) );
			vecWriteSpec.append( SlCapWriteSpecType(szItem_LH_MotorDstSpeed, QVariant(m_LH_MotorDstSpeed)) );
		}
		if( (fabs(m_LV_MotorPreDstPos-m_LV_MotorDstPos) > V_Dif  || bForceSend) && !isTouchRail && !isYfellow){
			is_LV_DstModify = true;
			vecWriteSpec.append( SlCapWriteSpecType(szItem_LV_MotorDstPos, QVariant(m_LV_MotorDstPos)) );
			vecWriteSpec.append( SlCapWriteSpecType(szItem_LV_MotorDstSpeed, QVariant(m_LV_MotorDstSpeed)) );
		}
	}
	if(m_R_bEnableUnit){//右铣削单元
		if( fabs(m_RH_MotorPreDstPos-m_RH_MotorDstPos) > H_Dif || bForceSend){
			is_RH_DstModify = true;
			vecWriteSpec.append( SlCapWriteSpecType(szItem_RH_MotorDstPos, QVariant(m_RH_MotorDstPos)) );
			vecWriteSpec.append( SlCapWriteSpecType(szItem_RH_MotorDstSpeed, QVariant(m_RH_MotorDstSpeed)) );
		}
		if( (fabs(m_RV_MotorPreDstPos-m_RV_MotorDstPos) > V_Dif || bForceSend) && !isTouchRail && !isYfellow ){
			is_RV_DstModify = true;
			vecWriteSpec.append( SlCapWriteSpecType(szItem_RV_MotorDstPos, QVariant(m_RV_MotorDstPos)) );
			vecWriteSpec.append( SlCapWriteSpecType(szItem_RV_MotorDstSpeed, QVariant(m_RV_MotorDstSpeed)) );
		}
	}
	if( is_LH_DstModify || is_LV_DstModify || is_RH_DstModify || is_RV_DstModify){
		// initialize result specification
		QVector<SlCapWriteResultType> vecWriteResult;
		// write data
		eError = capServerWrite.multiWrite(vecWriteSpec, &vecWriteResult);
		// write success or error to the status bar
	}
	if( is_LH_DstModify ){
		m_LH_SensorPreDstValue = m_LH_SensorDstValue;
		m_LH_MotorPreDstPos = m_LH_MotorDstPos;

		if(isMillingState)
			m_LH_PreCutBias = m_LH_CutBias;
	}

	if( is_LV_DstModify ){
		m_LV_SensorPreDstValue = m_LV_SensorDstValue;
		m_LV_MotorPreDstPos = m_LV_MotorDstPos;

		if(isMillingState)
			m_LV_PreCutBias = m_LV_CutBias;
	}

	if( is_RH_DstModify ){
		m_RH_SensorPreDstValue = m_RH_SensorDstValue;
		m_RH_MotorPreDstPos = m_RH_MotorDstPos;

		if(isMillingState)
			m_RH_PreCutBias = m_RH_CutBias;
	}

	if( is_RV_DstModify ){
		m_RV_SensorPreDstValue = m_RV_SensorDstValue;
		m_RV_MotorPreDstPos = m_RV_MotorDstPos;

		if(isMillingState)
			m_RV_PreCutBias = m_RV_CutBias;
	}
	//if( is_LH_DstModify || is_LV_DstModify || is_RH_DstModify || is_RV_DstModify){
	//	RecordData( );
	//}
	RecordData( );
	return eError;
}

void GlobalData::StartTrainProc( ) // call by trainmillingdialog.cpp
{
	if( ChooseSensor( ) == true )
	{
		m_bIsEmgyStop = false;
		m_bSensorErr = false;

		/*if( !m_bTrainCommState )
			TcuConnectProc( );//弃用 ligy 20190906 add
		*/
		m_bPcuCommState = true;

		m_LH_GroupData.clear();
		m_LV_GroupData.clear();
		m_RH_GroupData.clear();
		m_RV_GroupData.clear();

		m_L_SMWStartTrain = m_L_SMWCurPos;
		m_R_SMWStartTrain = m_R_SMWCurPos;

		m_LH_MotorPreDstPos = m_LH_MotorCurPos;
		m_LV_MotorPreDstPos = m_LV_MotorCurPos;
		m_RH_MotorPreDstPos = m_RH_MotorCurPos;
		m_RV_MotorPreDstPos = m_RV_MotorCurPos;

		//g_pErr->clearTypePCUAlarms();

		m_LH_Error = REPORT_NO_ERR; 
		m_LV_Error = REPORT_NO_ERR;
		m_RH_Error = REPORT_NO_ERR; 
		m_RV_Error = REPORT_NO_ERR; 

		StartRecordData( );
		PowerMonitorIni( );
		CalVSoftShoeLayer( );
		CalSoftShoePoints( );

		SetPCUWorkState(WORKSTATE_STARTFELLOW_INI);  //ligy 20190905 add.设置开始跟随

		g_iAddr40007 = TRAIN_START;//启动列车.  ligy 20190904 add
		//TCU TcuSetDeviceErrState & TcuSetEmergencyState
	//	TcuSetDeviceErrState( false );
	//	TcuSetEmergencyState( false );
		
	}
}

int GlobalData::StartWorkProc( ) // call by trainmillingdialog.cpp
{
	int RetVal = RET_OK;
	if( (m_nWorkState == WORKSTATE_YFELLOW_INI || m_nWorkState == WORKSTATE_YFELLOW) ||
		(m_nWorkState == WORKSTATE_YFELLOW2_INI || m_nWorkState == WORKSTATE_YFELLOW2) )
	{
		m_L_SMWWorkMileage = 0;
		m_R_SMWWorkMileage = 0;
		m_ReportWorkMileage = 0;
		m_L_SMWStartWork=m_L_SMWCurPos;
		m_R_SMWStartWork=m_R_SMWCurPos;
		SetPCUWorkState(WORKSTATE_WORKIN_INI);

		//TCU StartWorkProc
		//TcuSetWorkStateProc( true );

		RetVal = RET_OK;
	}
	return RetVal;
}

void GlobalData::StopWorkProc( )
{
	/*
	SlQCap nWriteServer;
	SlCapErrorEnum nError;
	nError = nWriteServer.write(szItem_SpeedReached_Bit,QVariant(false));
	*/
	if( m_nWorkState == WORKSTATE_MILLING_INI || m_nWorkState == WORKSTATE_MILLING )
	{
		SetPCUWorkState(WORKSTATE_CUTOUT_INI);
		m_SMWTotalWorkMileage += ((m_L_SMWWorkMileage+m_R_SMWWorkMileage)/2000);//unit:km

		//TCU StartWorkProc
		//TcuSetWorkStateProc( false );
	}
}

void GlobalData::AlarmStopWorkProc( )
{
	if( m_nWorkState == WORKSTATE_MILLING_INI || m_nWorkState == WORKSTATE_MILLING )
	{
		SetPCUWorkState(WORKSTATE_CUTOUT_INI);
		m_SMWTotalWorkMileage += ((m_L_SMWWorkMileage+m_R_SMWWorkMileage)/2000);

		//TCU StartWorkProc
		//TcuSetWorkStateProc( false );
		g_pErr->createStopWorkAlarm( );
	}
}

void GlobalData::StopTrainProc( )
{
	double L_TrainMileage = m_L_SMWCurPos - m_L_SMWStartTrain;
	double R_TrainMileage = m_R_SMWCurPos - m_R_SMWStartTrain;
	m_SMWTotalTrainMileage += ((L_TrainMileage + R_TrainMileage)/2000000);
	SetPCUWorkState(WORKSTATE_ENDFELLOW_INI);

	g_iAddr40007 = TRAIN_STOP;//停止列车.ligy 20190905 add

	//TCU StopTrainProc
	//TcuEnableTrainProc( false );
}

void GlobalData::SpeedReachedProc( )
{
	SlQCap nWriteServer;
	SlCapErrorEnum nError;
	bool bLAxisSpeedReachDst = IsLAxisSpeedReachDst();//是否达到主轴速度，左
	bool bRAxisSpeedReachDst = IsRAxisSpeedReachDst();//是否达到主轴速度，右

	bool bAxisSpeedReachDst = bLAxisSpeedReachDst && bRAxisSpeedReachDst;
	bool bTrainSpeedReachDst = IsTrainSpeedReachDst();
	bool bAxisStopMove = IsAxisStopMove();
	bool bTrainStopMove = IsTrainStopMove();

	/*
	1,AxisSpeedReached
	2,TrainSpeedReach
	3,m_nWorkState > WORKSTATE_YFELLOW_INI
	*/
	if( bAxisSpeedReachDst && bTrainSpeedReachDst && 
		(m_nWorkState == WORKSTATE_YFELLOW) && !m_bSpeedReached  ){
		m_bSpeedReached = true;
		nError = nWriteServer.write(szItem_SpeedReached_Bit,QVariant(true));//M30.0:车速、主轴转速到达设定值，且自动调整完成
	}
	/*
	if( (!bAxisSpeedReachDst || !bTrainSpeedReachDst) && m_bSpeedReached){
		m_bSpeedReached = false;
		nError = nWriteServer.write(szItem_SpeedReached_Bit,QVariant(false));
	}
	*/
	if( bAxisStopMove && bTrainStopMove && m_bSpeedReached){
		m_bSpeedReached = false;
		nError = nWriteServer.write(szItem_SpeedReached_Bit,QVariant(false));//M30.0:车速、主轴转速到达设定值，且自动调整完成
	}

	/*
	1,AxisSpeedReached
	2,m_nWorkState > WORKSTATE_YFELLOW_INI
	*/
	if( bAxisSpeedReachDst && ( (m_nWorkState == WORKSTATE_YFELLOW) )  ){
		//TCU StartTrainProc
		//TcuEnableTrainProc( true );
	}

	/*
	1,m_nWorkState >= WORKSTATE_WORKIN_INI && m_nWorkState <= WORKSTATE_WORKOUT
	2,bLAxisSpeedReachDst == false    m_LH_Error |= REPORT_10_ERR; 
	2,bRAxisSpeedReachDst == false    m_RH_Error |= REPORT_10_ERR; 
	*/
	if( (m_nWorkState >= WORKSTATE_WORKIN_INI) && (m_nWorkState <= WORKSTATE_WORKOUT) ) {
		if( !bLAxisSpeedReachDst )
			m_LH_Error |= REPORT_10_ERR; 
		if( !bRAxisSpeedReachDst )
			m_RH_Error |= REPORT_10_ERR; 
	}
}

SlCapErrorEnum GlobalData::EmergencyStopProc( int nWorkState )
{
	/*************/ 
	bool isEmergencyState = false;
	bool bConnectFailed = false;
	SlQCap nWriteServer;														//need work
	SlCapErrorEnum nError = SL_CAP_OK;

	isEmergencyState = ((nWorkState == WORKSTATE_EMERGENCY_PCU ) || (nWorkState == WORKSTATE_EMERGENCY_PLC ))?true:false;

	if( isEmergencyState )
	{
		if(nWorkState == WORKSTATE_EMERGENCY_PCU )
		{
			nError = nWriteServer.write(szItem_PCUEmergencyStop_Bit,QVariant(true));//M32.0:紧急提升故障标志
			if(!SL_SUCCEEDED(nError)){
				bConnectFailed = true;
			}
		}
		double L_TrainMileage = m_L_SMWCurPos - m_L_SMWStartTrain;//左铣削单元行驶里程
		double R_TrainMileage = m_R_SMWCurPos - m_R_SMWStartTrain;//右铣削单元行驶里程
		m_SMWTotalTrainMileage += ((L_TrainMileage + R_TrainMileage)/2000000);//总行驶里程 ligy 20190910 add

		if( m_nPreWorkState >= WORKSTATE_WORKIN_INI )
		{
			//double L_WorkMileage =  m_L_SMWCurPos - m_L_SMWStartWork;
			//double R_WorkMileage =  m_R_SMWCurPos - m_R_SMWStartWork;
			//m_SMWTotalWorkMileage += ((L_WorkMileage + R_WorkMileage)/2000000);
			m_SMWTotalWorkMileage += ((m_L_SMWWorkMileage+m_R_SMWWorkMileage)/2000);
		}
		else
			m_SMWTotalWorkMileage += 0;

		g_pErr->createPCUAlarms( );
		RecordData( );
		StopRecordData( );
		SetPCUWorkState( WORKSTATE_NULL );

		//Tcu TcuSetDeviceErrState&TcuSetEmergencyState
// 		TcuEnableTrainProc( false );
// 		TcuSetDeviceErrState( true );
// 		TcuSetEmergencyState( true );
		/*
		m_LH_Error = REPORT_NO_ERR; 
		m_LV_Error = REPORT_NO_ERR;
		m_RH_Error = REPORT_NO_ERR; 
		m_RV_Error = REPORT_NO_ERR; 
		*/

		m_LH_CutBias = 0;
		m_LV_CutBias = 0;
		m_RH_CutBias = 0;
		m_RV_CutBias = 0;
		m_LH_PreCutBias = 0;
		m_LV_PreCutBias = 0;
		m_RH_PreCutBias = 0;
		m_RV_PreCutBias = 0;
		m_LH_CutBiasStep = 0;
		m_LV_CutBiasStep = 0;
		m_RH_CutBiasStep = 0;
		m_RV_CutBiasStep = 0;
		m_LH_SensorDstValue = SENSORDST_NOFELLOW;
		m_LV_SensorDstValue = SENSORDST_NOFELLOW;
		m_RH_SensorDstValue = SENSORDST_NOFELLOW;
		m_RV_SensorDstValue = SENSORDST_NOFELLOW;
		memset(&m_LH_CurData,0,sizeof(m_LH_CurData));
		memset(&m_LV_CurData,0,sizeof(m_LV_CurData));
		memset(&m_RH_CurData,0,sizeof(m_RH_CurData));
		memset(&m_RV_CurData,0,sizeof(m_RV_CurData));
		memset(&m_LH_PreData,0,sizeof(m_LH_PreData));
		memset(&m_LV_PreData,0,sizeof(m_LV_PreData));
		memset(&m_RH_PreData,0,sizeof(m_RH_PreData));
		memset(&m_RV_PreData,0,sizeof(m_RV_PreData));

		m_bIsEmgyStop = true;
	}
	return nError;
}

void GlobalData::StartLogData( )//ligy 20200212 add.日志文件
{
	QDateTime current_datetime = QDateTime::currentDateTime();
	QString sDateTime=current_datetime.toString("yyyy-MM-dd");
	QString fileRecordPath = "..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\LogData\\"+QString("Log")+sDateTime+".csv";
	m_fileLog.setFileName(fileRecordPath);
	
	QFileInfo fi(fileRecordPath);
	bool bFileExist = false;

	if (fi.isFile())//判断文件是否存在
	{
		bFileExist = true;
	}
	
	if(!m_fileLog.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
	{
		//qDebug()<<"OPEN FILE FAILED";  
	}

	m_StreamLog.setDevice(&m_fileLog);

	if (!bFileExist)
	{
		//写文件头
		m_StreamLog << g_pIni->m_strLog_OperateTime //操作时间
			<<"," << g_pIni->m_strLog_Operator      //操作人
			<<","<<g_pIni->m_strLog_OperateType     //操作内容
			<<endl;
		m_StreamLog.flush();
	}
	
    //test code
	//m_StreamLog <<sDateTime
	//	<<","<<g_pIni->m_strLog_BodyStart
	//	<<","<<g_pIni->m_strLog_BodyStop
	//	<<","<<g_pIni->m_strLog_HydraulicStart
	//	<<","<<g_pIni->m_strLog_HydraulicStop
	//	<<","<<g_pIni->m_strLog_ChipStart
	//	<<","<<g_pIni->m_strLog_ChipStop
	//	<<","<<g_pIni->m_strLog_SpeedWheelStart
	//	<<","<<g_pIni->m_strLog_SpeedWheelStop
	//	<<","<<g_pIni->m_strLog_StartTrain
	//	<<","<<g_pIni->m_strLog_StopTrain
	//	<<","<<g_pIni->m_strLog_StartWork
	//	<<","<<g_pIni->m_strLog_StopWork
	//	<<","<<g_pIni->m_strLog_DeviceUp
	//	<<","<<g_pIni->m_strLog_DeviceDown
	//	<<endl;
	//m_StreamLog.flush();
	
}

void GlobalData::StartRecordData( )
{
	QDateTime current_datetime = QDateTime::currentDateTime();
	QString sDateTime=current_datetime.toString("yyyy-MM-dd hh-mm-ss");
	QString fileRecordPath = "..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\workrecord\\workrecord"+QString(" ")+sDateTime+QString(" ")+m_strNowUserName+".csv";
	QString H_fileCutDepth = "..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\workrecord\\workrecord_H_CutDepth"+QString(" ")+sDateTime+QString(" ")+m_strNowUserName+".csv";
	QString V_fileCutDepth = "..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\workrecord\\workrecord_V_CutDepth"+QString(" ")+sDateTime+QString(" ")+m_strNowUserName+".csv";
	m_fileRecord.setFileName(fileRecordPath);
	m_H_fileCutDepth.setFileName(H_fileCutDepth);
	m_V_fileCutDepth.setFileName(V_fileCutDepth);
	m_strfileRecord = fileRecordPath;
	if(!m_fileRecord.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
	{
		//qDebug()<<"OPEN FILE FAILED";  
	}
	if(!m_H_fileCutDepth.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
	{
		//qDebug()<<"OPEN FILE FAILED";  
	}
	if(!m_V_fileCutDepth.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
	{
		//qDebug()<<"OPEN FILE FAILED";  
	}
	m_StreamRecord.setDevice(&m_fileRecord);
	m_H_StreamCutDepth.setDevice(&m_H_fileCutDepth);
	m_V_StreamCutDepth.setDevice(&m_V_fileCutDepth);

	//Record The Settings of the Record
	m_StreamRecord << sDateTime 
		<<"," << QString::number(m_nWorkState) 
		<<"," << QString("LH_Sensor") 
		<<"," << QString::number(m_LH_bSensorChoose1) 
		<<"," << QString::number(m_LH_bSensorChoose2) 
		<<"," << QString("LV_Sensor") 
		<<"," << QString::number(m_LV_bSensorChoose1) 
		<<"," << QString::number(m_LV_bSensorChoose2) 
		<<"," << QString("RH_Sensor") 
		<<"," << QString::number(m_RH_bSensorChoose1) 
		<<"," << QString::number(m_RH_bSensorChoose2) 
		<<"," << QString("RV_Sensor") 
		<<"," << QString::number(m_RV_bSensorChoose1) 
		<<"," << QString::number(m_RV_bSensorChoose2) 
		<<endl;

	m_StreamRecord << sDateTime 
		<<"," << QString::number(m_nWorkState) 
		<<"," << QString("LH_SensorRatio") 
		<<"," << QString::number(m_LH_SensorRatio) 
		<<"," << QString("LV_SensorRatio") 
		<<"," << QString::number(m_LV_SensorRatio) 
		<<"," << QString("RH_SensorRatio") 
		<<"," << QString::number(m_RH_SensorRatio) 
		<<"," << QString("RV_SensorRatio") 
		<<"," << QString::number(m_RV_SensorRatio) 
		<<"," << QString("H_SoftShoeDirRatio1") 
		<<"," << QString::number(m_H_SoftShoeDirRatio1) 
		<<"," << QString("H_SoftShoeDirRatio2") 
		<<"," << QString::number(m_H_SoftShoeDirRatio2) 
		<<"," << QString("V_SoftShoeDirRatio1") 
		<<"," << QString::number(m_V_SoftShoeDirRatio1) 
		<<"," << QString("V_SoftShoeDirRatio2") 
		<<"," << QString::number(m_V_SoftShoeDirRatio2) 
		<<"," << QString("H_ShoeLen") 
		<<"," << QString::number(m_H_SoftShoeLen) 
		<<"," << QString("V_ShoeLen") 
		<<"," << QString::number(m_V_SoftShoeLen) 
		<<"," << QString("H_Shoe_alph") 
		<<"," << QString::number(m_H_SoftShoeAlph) 
		<<"," << QString("V_Shoe_alph") 
		<<"," << QString::number(m_V_SoftShoeAlph) 
		<<endl;

	m_StreamRecord << sDateTime 
		<<"," << QString::number(m_nWorkState) 
		<<"," << QString("H_DeviceIniPos") 
		<<"," << QString::number(m_H_DeviceIniPos) 
		<<"," << QString("H_WorkIniPos") 
		<<"," << QString::number(m_H_WorkIniPos) 
		<<"," << QString("V_DeviceIniPos") 
		<<"," << QString::number(m_V_DeviceIniPos) 
		<<"," << QString("V_WorkIniPos") 
		<<"," << QString::number(m_V_WorkIniPos) 
		<<"," << QString("LH_CutDepth") 
		<<"," << QString::number(m_LH_CutDepth) 
		<<"," << QString("RH_CutDepth") 
		<<"," << QString::number(m_RH_CutDepth) 
		<<"," << QString("LV_CutDepth") 
		<<"," << QString::number(m_LV_CutDepth) 
		<<"," << QString("RV_CutDepth") 
		<<"," << QString::number(m_RV_CutDepth) 
		<<"," << QString("LH_CutOffset") 
		<<"," << QString::number(m_LH_RailOffset) 
		<<"," << QString("LV_CutOffset") 
		<<"," << QString::number(m_LV_RailOffset) 
		<<"," << QString("RH_CutOffset") 
		<<"," << QString::number(m_RH_RailOffset) 
		<<"," << QString("RV_CutOffset") 
		<<"," << QString::number(m_RV_RailOffset) 
		<<endl;

	m_StreamRecord << sDateTime 
		<<"," << QString::number(m_nWorkState) 
		<<"," << QString("TrainSpeed") 
		<<"," << QString::number(m_DstTrainSpeed) 
		<<"," << QString("H_CutSpeed") 
		<<"," << QString::number(m_H_RapidSpeed) 
		<<"," << QString("V_CutSpeed") 
		<<"," << QString::number(m_V_RapidSpeed) 
		<<"," << QString("AxisSpeed") 
		<<"," << QString::number(m_bHighSpindleSpeed?m_HighAxisAngularSpeed:m_LowAxisAngularSpeed) 
		<<endl;

	m_StreamRecord.flush();
}

void GlobalData::RecordData( )
{
	QDateTime current_date_time =QDateTime::currentDateTime();
	QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss zzz");

	if( m_nWorkState == WORKSTATE_MILLING_INI || m_nWorkState == WORKSTATE_MILLING)
	{
		m_H_StreamCutDepth << current_date
			<<QString(",")<<QString::number(m_LH_CutDepth+m_LH_CutDepthOffset+m_LH_CutBias)
			<<QString(",")<<QString::number(m_RH_CutDepth+m_RH_CutDepthOffset+m_RH_CutBias)
			<<endl;
		m_H_StreamCutDepth.flush();

		m_V_StreamCutDepth << current_date
			<<QString(",")<<QString::number(m_LV_CutDepth+m_LV_CutDepthOffset+m_LV_CutBias)
			<<QString(",")<<QString::number(m_RV_CutDepth+m_RV_CutDepthOffset+m_RV_CutBias)
			<<endl;
		m_V_StreamCutDepth.flush();
	}

	m_StreamRecord << current_date 
		<<"," << QString::number(m_nWorkState) 
		<<"," << QString::number(m_LH_CurData.SMWPos) 
		//<<"," << QString::number(m_LH_bSensorChoose?1:2) 
		//<<"," << QString::number(m_LH_CurData.SensorValue1) 
		//<<"," << QString::number(m_LH_CurData.SensorValue2) 
		<<"," << QString::number(m_LH_SensorDstValue) 
		<<"," << QString::number(m_LH_CurData.SensorValue) 
		<<"," << QString::number(m_LH_CurData.Org_SensorValue) 
		<<"," << QString::number(m_LH_MotorCurPos/*m_LH_CurData.MotorPos*/) 
		<<"," << QString::number(m_LH_MotorDstPos) 
		<<"," << QString::number(m_LH_MotorPreDstPos) 
		<<"," << QString::number(m_LH_Error)
		<<"," << QString::number(m_LV_CurData.SMWPos) 
		//<<"," << QString::number(m_LV_bSensorChoose?1:2) 
		//<<"," << QString::number(m_LV_CurData.SensorValue1) 
		//<<"," << QString::number(m_LV_CurData.SensorValue2) 
		<<"," << QString::number(m_LV_SensorDstValue) 
		<<"," << QString::number(m_LV_CurData.SensorValue) 
		<<"," << QString::number(m_LV_SensorCurValue1) 
		<<"," << QString::number(m_LV_MotorCurPos/*m_LV_CurData.MotorPos*/) 
		<<"," << QString::number(m_LV_MotorDstPos)
		<<"," << QString::number(m_LV_MotorPreDstPos)
		<<"," << QString::number(m_LV_Error) 
		<<"," << QString::number(m_RH_CurData.SMWPos)
		//<<"," << QString::number(m_RH_bSensorChoose?1:2)
		//<<"," << QString::number(m_RH_CurData.SensorValue1)
		//<<"," << QString::number(m_RH_CurData.SensorValue2)
		<<"," << QString::number(m_RH_SensorDstValue) 
		<<"," << QString::number(m_RH_CurData.SensorValue) 
		<<"," << QString::number(m_RH_CurData.Org_SensorValue) 
		<<"," << QString::number(m_RH_MotorCurPos/*m_RH_CurData.MotorPos*/) 
		<<"," << QString::number(m_RH_MotorDstPos)
		<<"," << QString::number(m_RH_MotorPreDstPos)
		<<"," << QString::number(m_RH_Error) 
		<<"," << QString::number(m_RV_CurData.SMWPos)
		//<<"," << QString::number(m_RV_bSensorChoose?1:2)
		//<<"," << QString::number(m_RV_CurData.SensorValue1)
		//<<"," << QString::number(m_RV_CurData.SensorValue2)
		<<"," << QString::number(m_RV_SensorDstValue) 
		<<"," << QString::number(m_RV_CurData.SensorValue) 
		<<"," << QString::number(m_RV_SensorCurValue1) 
		<<"," << QString::number(m_RV_MotorCurPos/*m_RV_CurData.MotorPos*/) 
		<<"," << QString::number(m_RV_MotorDstPos) 
		<<"," << QString::number(m_RV_MotorPreDstPos) 
		<<"," << QString::number(m_RV_Error) 
		<<"," << QString::number(m_L_Power)
		<<"," << QString::number(m_R_Power) 
		<<"," << QString::number(m_LV_SensorCurValue2)
		<<"," << QString::number(m_RV_SensorCurValue2) 
		<<"," << QString::number(m_L_SMWCurSpeed)
		<<"," << QString::number(m_R_SMWCurSpeed) 
		<<endl;
	m_StreamRecord.flush();
}

void GlobalData::StopLogData( )//ligy 20200212 add.关闭日志文件
{
	m_fileLog.close();
}
void GlobalData::StopRecordData( )
{
	m_fileRecord.close();
	m_H_fileCutDepth.close();
	m_V_fileCutDepth.close();
}

void GlobalData::PowerControlIni()
{
	m_L_LastPowerControlPos = m_L_SMWCurPos;
	m_R_LastPowerControlPos = m_R_SMWCurPos;
	m_LV_CutBiasFollowed = true;
	m_RV_CutBiasFollowed = true;
	m_LH_CutBiasFollowed = true;
	m_RH_CutBiasFollowed = true;
	m_LV_pControlMoveForward = true;
	m_RV_pControlMoveForward = true;

	m_LV_PControlUnNormalStopped = false;
	m_RV_PControlUnNormalStopped = false;
	m_PowerControlLen = 1500;
	m_PowerControlHalfLen = 750;
	m_PowerControlQuarterLen = 375;
	m_L_PowerControlLen = m_PowerControlLen;
	m_R_PowerControlLen = m_PowerControlLen;
	m_PowerControlCutStep = 0.1;
	if( m_DstTrainSpeed < 0.60001 )
		m_PowerControlWidth = 6;
	else if(m_DstTrainSpeed < 1.00001 )
		m_PowerControlWidth = 9;
	else
		m_PowerControlWidth = 12;
}

void GlobalData::PowerControlProc()
{
	bool isMillingState = ( m_nWorkState == WORKSTATE_MILLING_INI) || (m_nWorkState == WORKSTATE_MILLING);

	if( m_bPowerControlMode && isMillingState)
	{
		if( m_L_bEnableUnit )
		{
			if( !m_LV_CutBiasFollowed )
			{
				if( ( m_LV_pControlMoveForward  && (m_L_Power >= m_LV_PowerControlValue - 2 ) ) ||
					( !m_LV_pControlMoveForward && (m_L_Power <= m_LV_PowerControlValue + 2 ) ) )
				{
					m_LV_PControlUnNormalStopped = true;
					m_LV_CutBias = m_LV_CutBiasStep;
					if( fabs(m_L_PowerControlLen - m_PowerControlLen) < 1E-5)
					{
						if( fabs(m_L_SMWCurPos - m_L_LastPowerControlPos) >= m_PowerControlHalfLen )
							m_L_PowerControlLen = m_PowerControlLen;
						else
							m_L_PowerControlLen = m_PowerControlHalfLen;
					}
					else if( fabs(m_L_PowerControlLen - m_PowerControlHalfLen) < 1E-5)
					{
						if( fabs(m_L_SMWCurPos - m_L_LastPowerControlPos) >= m_PowerControlQuarterLen )
							m_L_PowerControlLen = m_PowerControlLen;
						else
							m_L_PowerControlLen = m_PowerControlHalfLen;
					}
				}
			}
			else if( fabs(m_L_SMWCurPos - m_L_LastPowerControlPos) > m_L_PowerControlLen /*&&  m_LV_CutBiasFollowed*/)
			{
				if( fabs(m_LV_PowerControlValue - m_L_Power) > m_PowerControlWidth )
				{
					if( m_L_Power < m_LV_PowerControlValue )
					{
						if(m_LV_CutBias+m_LV_CutDepth+m_LV_CutDepthOffset<=2.9)
						{
							m_LV_CutBias += m_PowerControlCutStep;
							m_L_LastPowerControlPos = m_L_SMWCurPos;
							m_LV_pControlMoveForward = true;
							m_LV_CutBiasFollowed = false;
						}
					}
					else
					{
						m_LV_CutBias -= m_PowerControlCutStep;
						m_L_LastPowerControlPos = m_L_SMWCurPos;
						m_LV_pControlMoveForward = false;
						m_LV_CutBiasFollowed = false;
					}
				}
			}
		}
		if( m_R_bEnableUnit )
		{
			if( !m_RV_CutBiasFollowed )
			{
				if( ( m_RV_pControlMoveForward  && (m_R_Power >= m_RV_PowerControlValue - 2 ) ) || 
					( !m_RV_pControlMoveForward && (m_R_Power <= m_RV_PowerControlValue + 2 ) ) )
				{
					m_RV_PControlUnNormalStopped = true;
					m_RV_CutBias = m_RV_CutBiasStep;
					if( fabs(m_R_PowerControlLen - m_PowerControlLen) < 1E-5)
					{
						if( fabs(m_R_SMWCurPos - m_R_LastPowerControlPos) >= m_PowerControlHalfLen )
							m_R_PowerControlLen = m_PowerControlLen;
						else
							m_R_PowerControlLen = m_PowerControlHalfLen;
					}
					else if( fabs(m_R_PowerControlLen - m_PowerControlHalfLen) < 1E-5)
					{
						if( fabs(m_R_SMWCurPos - m_R_LastPowerControlPos) >= m_PowerControlQuarterLen )
							m_R_PowerControlLen = m_PowerControlLen;
						else
							m_R_PowerControlLen = m_PowerControlHalfLen;
					}
				}
			}
			else if( fabs(m_R_SMWCurPos - m_R_LastPowerControlPos) > m_R_PowerControlLen /*&& m_RV_CutBiasFollowed*/)
			{
				if( fabs(m_RV_PowerControlValue - m_R_Power) > m_PowerControlWidth )
				{
					if( m_R_Power < m_RV_PowerControlValue )
					{
						if(m_RV_CutBias+m_RV_CutDepth+m_RV_CutDepthOffset<=2.9)
						{
							m_RV_CutBias += m_PowerControlCutStep;
							m_R_LastPowerControlPos = m_R_SMWCurPos;
							m_RV_pControlMoveForward = true;
							m_RV_CutBiasFollowed = false;
						}
					}
					else
					{
						m_RV_CutBias -= m_PowerControlCutStep;
						m_R_LastPowerControlPos = m_R_SMWCurPos;
						m_RV_pControlMoveForward = false;
						m_RV_CutBiasFollowed = false;
					}
				}
			}
		}
	}
}

void GlobalData::ScanCutBiasIni( )
{
	m_LH_CBPreSignal1 = m_LH_CBCurSignal1;
	m_LH_CBPreSignal2 = m_LH_CBCurSignal2;
	m_LV_CBPreSignal1 = m_LV_CBCurSignal1;
	m_LV_CBPreSignal2 = m_LV_CBCurSignal2;
	m_RH_CBPreSignal1 = m_RH_CBCurSignal1;
	m_RH_CBPreSignal2 = m_RH_CBCurSignal2;
	m_RV_CBPreSignal1 = m_RV_CBCurSignal1;
	m_RV_CBPreSignal2 = m_RV_CBCurSignal2;

	m_LH_PreCutBias = m_LH_CutBias = 0;
	m_LV_PreCutBias = m_LV_CutBias = 0;
	m_RH_PreCutBias = m_RH_CutBias = 0;
	m_RV_PreCutBias = m_RV_CutBias = 0;

	m_LH_CutBiasStep = 0;
	m_LV_CutBiasStep = 0;
	m_RH_CutBiasStep = 0;
	m_RV_CutBiasStep = 0;

	m_LV_CutBiasFirstTimeFollowed = true;
	m_RV_CutBiasFirstTimeFollowed = true;

	CalCutBiasStep( );
}

void GlobalData::CalCutBiasStep( )
{
	m_H_CutBiasStep = m_DstTrainSpeed/100;
	if(m_bPowerControlMode)
		m_V_CutBiasStep = m_DstTrainSpeed/750;
	else
		m_V_CutBiasStep = m_DstTrainSpeed/250;
}

void GlobalData::CalVSoftShoeLayer( )  //计算垂向软件靴分层数
{
	/*
	//Method 1 : 500mm SoftShoeLen
	if( m_DstTrainSpeed < 0.10001 )
		m_V_SoftShoeLayer = 35;
	else if(m_DstTrainSpeed < 0.20001 )
		m_V_SoftShoeLayer = 30;
	else if(m_DstTrainSpeed < 0.30001 )
		m_V_SoftShoeLayer = 20;
	else if(m_DstTrainSpeed < 0.50001 )
		m_V_SoftShoeLayer = 13;
	else if(m_DstTrainSpeed < 0.80001 )
		m_V_SoftShoeLayer = 9;
	else if(m_DstTrainSpeed < 1.00001 )
		m_V_SoftShoeLayer = 7;
	else if(m_DstTrainSpeed < 1.50001 )
		m_V_SoftShoeLayer = 5;
	else if(m_DstTrainSpeed < 2.00001 )
		m_V_SoftShoeLayer = 4;
	else
		m_V_SoftShoeLayer = 3;
	*/
	//Method 2 : Dynamic SoftShoeLen
	double iShoeLen = m_V_SoftShoeLen * 0.16;
	iShoeLen = iShoeLen < 50 ? 50 : iShoeLen;
	iShoeLen = iShoeLen > 100 ? 100 : iShoeLen;
	double f = iShoeLen / 1000 / 1000/ m_DstTrainSpeed * 3600 * 1000 / 50;
	m_V_SoftShoeLayer = (int)( f + 0.5 );
	m_V_SoftShoeLayer = m_V_SoftShoeLayer < 3 ? 3 : m_V_SoftShoeLayer;//垂向软件靴分层数 ligy 20190906
}

void GlobalData::CalSoftShoePoints( )
{
	m_H_SoftShoePoints = int(m_H_SoftShoeLen/1000/m_DstTrainSpeed*3600/1000*20) ;
	m_V_SoftShoePoints = int(m_V_SoftShoeLen/1000/m_DstTrainSpeed*3600/1000*20) ;
}

void GlobalData::ScanCutBias( )
{
	if(m_L_bEnableUnit)
	{
		if( m_LH_CutBiasFollowed )
		{
			if(m_LH_CBCurSignal1 && m_LH_CutBias>-5 && !m_LH_CBPreSignal1 )	//Y1-
			{
				m_LH_CutBiasFollowed = false;
				m_LH_CutBias -= 0.1;
			}
			if(m_LH_CBCurSignal2 && m_LH_CutBias<5 && !m_LH_CBPreSignal2 )	//Y1+
			{
				if(m_LH_CutBias+m_LH_CutDepth+m_LH_CutDepthOffset<=2.9)
				{
					m_LH_CutBiasFollowed = false;
					m_LH_CutBias += 0.1;
				}
			}
		}
		if( !m_bPowerControlMode && m_LV_CutBiasFollowed )
		{
			if(m_LV_CBCurSignal1 && m_LV_CutBias>-5 && !m_LV_CBPreSignal1 )	//Z1-
			{
				m_LV_CutBiasFollowed = false;
				m_LV_CutBias -= 0.1;
			}
			if(m_LV_CBCurSignal2 && m_LV_CutBias<5 && !m_LV_CBPreSignal2 )	//Z1+
			{
				if(m_LV_CutBias+m_LV_CutDepth+m_LV_CutDepthOffset<=2.9)
				{
					m_LV_CutBiasFollowed = false;
					m_LV_CutBias += 0.1;
				}
			}
		}
	}
	if(m_R_bEnableUnit)
	{
		if( m_RH_CutBiasFollowed )
		{
			if(m_RH_CBCurSignal1 && m_RH_CutBias>-5 && !m_RH_CBPreSignal1 )	//Y2-
			{
				m_RH_CutBiasFollowed = false;
				m_RH_CutBias -= 0.1;
			}
			if(m_RH_CBCurSignal2 && m_RH_CutBias<5 && !m_RH_CBPreSignal2  )	//Y2+
			{
				if(m_RH_CutBias+m_RH_CutDepth+m_RH_CutDepthOffset<=2.9)
				{
					m_RH_CutBiasFollowed = false;
					m_RH_CutBias += 0.1;
				}
			}
		}
		if( !m_bPowerControlMode && m_RV_CutBiasFollowed )
		{
			if(m_RV_CBCurSignal1 && m_RV_CutBias>-5 && !m_RV_CBPreSignal1 )	//Z2-
			{
				m_RV_CutBiasFollowed = false;
				m_RV_CutBias -= 0.1;
			}
			if(m_RV_CBCurSignal2 && m_RV_CutBias<5 && !m_RV_CBPreSignal2 )	//Z2-
			{
				if(m_RV_CutBias+m_RV_CutDepth+m_RV_CutDepthOffset<=2.9)
				{
					m_RV_CutBiasFollowed = false;
					m_RV_CutBias += 0.1;
				}
			}
		}
	}
	/*
	if( fabs(m_LH_CutBias) < 1E-5 )
		m_LH_CutBias = 0;
	if( fabs(m_LV_CutBias) < 1E-5 )
		m_LV_CutBias = 0;
	if( fabs(m_RH_CutBias) < 1E-5 )
		m_RH_CutBias = 0;
	if( fabs(m_RV_CutBias) < 1E-5 )
		m_RV_CutBias = 0;
	*/
	m_LH_CBPreSignal1 = m_LH_CBCurSignal1;
	m_LH_CBPreSignal2 = m_LH_CBCurSignal2;
	m_LV_CBPreSignal1 = m_LV_CBCurSignal1;
	m_LV_CBPreSignal2 = m_LV_CBCurSignal2;
	m_RH_CBPreSignal1 = m_RH_CBCurSignal1;
	m_RH_CBPreSignal2 = m_RH_CBCurSignal2;
	m_RV_CBPreSignal1 = m_RV_CBCurSignal1;
	m_RV_CBPreSignal2 = m_RV_CBCurSignal2;
}

void GlobalData::LimitCutBias( )
{
	m_LH_CutBias = (m_LH_CutBias - m_LH_PreCutBias) > 0.2 ? (m_LH_PreCutBias + 0.2) : m_LH_CutBias;
	m_LV_CutBias = (m_LV_CutBias - m_LV_PreCutBias) > 0.2 ? (m_LV_PreCutBias + 0.2) : m_LV_CutBias;
	m_RH_CutBias = (m_RH_CutBias - m_RH_PreCutBias) > 0.2 ? (m_RH_PreCutBias + 0.2) : m_RH_CutBias;
	m_RV_CutBias = (m_RV_CutBias - m_RV_PreCutBias) > 0.2 ? (m_RV_PreCutBias + 0.2) : m_RV_CutBias;

	m_LH_CutBias = (m_LH_CutBias - m_LH_PreCutBias) < -0.2 ? (m_LH_PreCutBias - 0.2) : m_LH_CutBias;
	m_LV_CutBias = (m_LV_CutBias - m_LV_PreCutBias) < -0.2 ? (m_LV_PreCutBias - 0.2) : m_LV_CutBias;
	m_RH_CutBias = (m_RH_CutBias - m_RH_PreCutBias) < -0.2 ? (m_RH_PreCutBias - 0.2) : m_RH_CutBias;
	m_RV_CutBias = (m_RV_CutBias - m_RV_PreCutBias) < -0.2 ? (m_RV_PreCutBias - 0.2) : m_RV_CutBias;
}

void GlobalData::CutBiasStep( )
{
	double iStep;

	if(m_nWorkState == WORKSTATE_MILLING_INI || m_nWorkState == WORKSTATE_MILLING)
	{
		iStep = m_H_CutBiasStep;
		//iDelta = iStep - 1E-3;
		//phase 1:LH Part
		if( fabs( m_LH_CutBiasStep - m_LH_CutBias) >= iStep ){
			if( m_LH_CutBiasStep < m_LH_CutBias )
				m_LH_CutBiasStep += iStep;
			else if( m_LH_CutBiasStep > m_LH_CutBias )
				m_LH_CutBiasStep -= iStep;
		}
		else
		{
			m_LH_CutBiasFollowed = true;
			m_LH_CutBiasStep = m_LH_CutBias;
		}
		//phase 2:RH Part
		if( fabs(m_RH_CutBiasStep - m_RH_CutBias) >= iStep ){
			if( m_RH_CutBiasStep < m_RH_CutBias )
				m_RH_CutBiasStep += iStep;
			else if( m_RH_CutBiasStep > m_RH_CutBias)
				m_RH_CutBiasStep -= iStep;
		}
		else
		{
			m_RH_CutBiasFollowed = true;
			m_RH_CutBiasStep = m_RH_CutBias;
		}

		iStep = m_V_CutBiasStep;
		//iDelta = iStep - 1E-3;
		//phase 3:LV Part
		if(fabs( m_LV_CutBiasStep - m_LV_CutBias) >= iStep ){
			m_LV_CutBiasFirstTimeFollowed = false;
			if( m_LV_CutBiasStep < m_LV_CutBias )
				m_LV_CutBiasStep += iStep;
			else if( m_LV_CutBiasStep > m_LV_CutBias )
				m_LV_CutBiasStep -= iStep;
		}
		else
		{
			m_LV_CutBiasFollowed = true;
			m_LV_CutBiasStep = m_LV_CutBias;

			if( m_LV_CutBiasFirstTimeFollowed == false){
				m_LV_CutBiasFirstTimeFollowed = true;
				if( m_LV_PControlUnNormalStopped == false )
					m_L_PowerControlLen = m_PowerControlLen;
				else
					m_LV_PControlUnNormalStopped = false;
			}
		}
		//phase 4:RV Part
		if( fabs(m_RV_CutBiasStep - m_RV_CutBias) >= iStep ){
			m_RV_CutBiasFirstTimeFollowed = false;
			if( m_RV_CutBiasStep < m_RV_CutBias )
				m_RV_CutBiasStep += iStep;
			else if( m_RV_CutBiasStep > m_RV_CutBias )
				m_RV_CutBiasStep -= iStep;
		}
		else
		{
			m_RV_CutBiasFollowed = true;
			m_RV_CutBiasStep = m_RV_CutBias;

			if( m_RV_CutBiasFirstTimeFollowed == false){
				m_RV_CutBiasFirstTimeFollowed = true;
				if( m_RV_PControlUnNormalStopped == false )
					m_R_PowerControlLen = m_PowerControlLen;
				else
					m_RV_PControlUnNormalStopped = false;
			}
		}
	}
	/*
	if( fabs(m_LH_CutBiasStep) < 1E-5 )
		m_LH_CutBiasStep = 0;
	if( fabs(m_LV_CutBiasStep) < 1E-5 )
		m_LV_CutBiasStep = 0;
	if( fabs(m_RH_CutBiasStep) < 1E-5 )
		m_RH_CutBiasStep = 0;
	if( fabs(m_RV_CutBiasStep) < 1E-5 )
		m_RV_CutBiasStep = 0;
	*/
}

void GlobalData::SaveScanData( ) //save scan data to file 
{
	int n1 = m_L_ScanDataX.size();
	int n2 = m_L_ScanDataY.size();
	int n3 = m_R_ScanDataX.size();
	int n4 = m_R_ScanDataY.size();
	if( n1==0 || n2==0 ||n3==0 ||n4==0 )
		return;
	QDateTime current_datetime = QDateTime::currentDateTime();
	QString sDateTime=current_datetime.toString("yyyy-MM-dd hh-mm-ss");
	QString filePath = "..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\ScanData\\ScanData"+sDateTime+".csv";
	QFile file(filePath);
	file.open(QIODevice::WriteOnly);
	QTextStream stream(&file);
	/*
	QString outputData = "Y1 and ScanData \n";
	for(int i=0; i< n1 ; i++)
	{
		double LX = m_L_ScanDataX.at(i);
		double LY = m_L_ScanDataY.at(i);
		outputData += QString::number(LX) + "," + QString::number(LY) + "\n";
	}
	outputData += "Y2 and ScanData \n";
	for(int i=0; i< n3 ; i++)
	{
		double RX = m_R_ScanDataX.at(i);
		double RY = m_R_ScanDataY.at(i);
		outputData += QString::number(RX) + "," + QString::number(RY) + "\n";
	}
	stream<<outputData;
	*/
	for(int i=0 ; i<n1 ; i++)
	{
		double LX = m_L_ScanDataX.at(i);
		double LY = m_L_ScanDataY.at(i);
		double RX = m_R_ScanDataX.at(i);
		double RY = m_R_ScanDataY.at(i);
		stream 
			<<QString::number(LX)<<"," 
			<<QString::number(LY)<<"," 
			<<QString::number(RX)<<"," 
			<<QString::number(RY)
			<<endl;
		stream.flush();
	}
	file.close();
}

bool GlobalData::IsLAxisSpeedReachDst( )
{
	bool bRetVal = false;
	double Low_Threshold,High_Threshold;
	//Give The Value
	if(m_bHighSpindleSpeed == true){
		Low_Threshold = fabs(m_HighAxisAngularSpeed) * 0.9;
		High_Threshold = fabs(m_HighAxisAngularSpeed) * 1.1;
	}
	else{
		Low_Threshold = fabs(m_LowAxisAngularSpeed) * 0.9;
		High_Threshold = fabs(m_LowAxisAngularSpeed) * 1.1;
	}
	//Judge The Value
	if( ( !m_L_bEnableUnit || (fabs(m_L_AxisAngularSpeed) >= Low_Threshold && fabs(m_L_AxisAngularSpeed) <= High_Threshold) ) )
		bRetVal = true;
	else
		bRetVal = false;
	return bRetVal;
}

bool GlobalData::IsRAxisSpeedReachDst( )
{
	bool bRetVal = false;
	double Low_Threshold,High_Threshold;
	//Give The Value
	if(m_bHighSpindleSpeed == true){
		Low_Threshold = fabs(m_HighAxisAngularSpeed) * 0.9;
		High_Threshold = fabs(m_HighAxisAngularSpeed) * 1.1;
	}
	else{
		Low_Threshold = fabs(m_LowAxisAngularSpeed) * 0.9;
		High_Threshold = fabs(m_LowAxisAngularSpeed) * 1.1;
	}
	//Judge The Value
	if( ( !m_R_bEnableUnit || (fabs(m_R_AxisAngularSpeed) >= Low_Threshold && fabs(m_R_AxisAngularSpeed) <= High_Threshold) ) )
		bRetVal = true;
	else
		bRetVal = false;
	return bRetVal;
}

bool GlobalData::IsAxisSpeedReachDst( )
{
	bool bRetVal = false;
	double Low_Threshold,High_Threshold;
	//Give The Value
	if(m_bHighSpindleSpeed == true){
		Low_Threshold = fabs(m_HighAxisAngularSpeed) * 0.9;
		High_Threshold = fabs(m_HighAxisAngularSpeed) * 1.1;
	}
	else{
		Low_Threshold = fabs(m_LowAxisAngularSpeed) * 0.9;
		High_Threshold = fabs(m_LowAxisAngularSpeed) * 1.1;
	}
	//Judge The Value
	if( ( !m_L_bEnableUnit || (fabs(m_L_AxisAngularSpeed) >= Low_Threshold && fabs(m_L_AxisAngularSpeed) <= High_Threshold) ) && 
		( !m_R_bEnableUnit || (fabs(m_R_AxisAngularSpeed) >= Low_Threshold && fabs(m_R_AxisAngularSpeed) <= High_Threshold) ) )
		bRetVal = true;
	else
		bRetVal = false;
	return bRetVal;
}

bool GlobalData::IsTrainSpeedReachDst( )
{
	bool bRetVal = false;
	//double Low_Threshold = 0.8 * fabs(m_DstTrainSpeed);
	//double High_Threshold = 1.2 * fabs(m_DstTrainSpeed);
	double Low_Threshold  = (1-m_DstTrainSpeedDiff/100.0) * fabs(m_DstTrainSpeed);//车速超差范围可配置 ligy 20190912 add
	double High_Threshold = (1+m_DstTrainSpeedDiff/100.0) * fabs(m_DstTrainSpeed);

	if(m_CurTrainSpeed > Low_Threshold && m_CurTrainSpeed < High_Threshold)
		bRetVal = true;
	else
		bRetVal = false;
	return bRetVal;
}

bool GlobalData::IsAxisStopMove( )//主轴是否停止转动？
{
	bool bRetVal = false;
	double L_Dif = fabs( m_L_AxisAngularSpeed );
	double R_Dif = fabs( m_R_AxisAngularSpeed );

	//Judge The Value
	if( (!m_L_bEnableUnit || (L_Dif < 1E-1) ) && 
		(!m_R_bEnableUnit || (R_Dif < 1E-1) ) )
		bRetVal = true;
	else
		bRetVal = false;
	return bRetVal;
}

bool GlobalData::IsTrainStopMove( )//列车是否停止？
{
	bool bRetVal = fabs(m_CurTrainSpeed) < 0.05 ? true : false;
	return bRetVal;
}

bool GlobalData::ChooseSensor( )
{
	bool bSensorOk = true;

	//Step1:ChooseSensor
	m_LH_bSensorChoose1 = fabs(m_LH_SensorRatio) < 1E-5 ? false : true;
	m_LV_bSensorChoose1 = fabs(m_LV_SensorRatio) < 1E-5 ? false : true;
	m_RH_bSensorChoose1 = fabs(m_RH_SensorRatio) < 1E-5 ? false : true;
	m_RV_bSensorChoose1 = fabs(m_RV_SensorRatio) < 1E-5 ? false : true;
	m_LH_bSensorChoose2 = fabs(m_LH_SensorRatio - 1) < 1E-5 ? false : true;
	m_LV_bSensorChoose2 = fabs(m_LV_SensorRatio - 1) < 1E-5 ? false : true;
	m_RH_bSensorChoose2 = fabs(m_RH_SensorRatio - 1) < 1E-5 ? false : true;
	m_RV_bSensorChoose2 = fabs(m_RV_SensorRatio - 1) < 1E-5 ? false : true; 

	//Step2:Judge Errors
	if( ( m_LH_bSensorStatus1 && m_LH_bSensorChoose1 ) || ( m_LH_bSensorStatus2 && m_LH_bSensorChoose2 ) ){
		m_LH_Error |= REPORT_8_ERR;
		bSensorOk = false;
	}
	if( ( m_LV_bSensorStatus1 && m_LV_bSensorChoose1 ) || ( m_LV_bSensorStatus2 && m_LV_bSensorChoose2 ) ){
		m_LV_Error |= REPORT_8_ERR;
		bSensorOk = false;
	}
	if( ( m_RH_bSensorStatus1 && m_RH_bSensorChoose1 ) || ( m_RH_bSensorStatus2 && m_RH_bSensorChoose2 ) ){
		m_RH_Error |= REPORT_8_ERR;
		bSensorOk = false;
	}
	if( ( m_RV_bSensorStatus1 && m_RV_bSensorChoose1 ) || ( m_RV_bSensorStatus2 && m_RV_bSensorChoose2 ) ){
		m_RV_Error |= REPORT_8_ERR;
		bSensorOk = false;
	}

	//Step3:Handle Errors
	if( !bSensorOk ){
		//Only Report Errors
		g_pErr->createPCUAlarms( );
		m_LH_Error &= (~REPORT_8_ERR);
		m_LV_Error &= (~REPORT_8_ERR);
		m_RH_Error &= (~REPORT_8_ERR);
		m_RV_Error &= (~REPORT_8_ERR);
	}

	return bSensorOk;

	/*-------------------------------------------------------
	if( ( m_LH_bSensorStatus1 && m_LH_bSensorChoose1 ) ||
		( m_LV_bSensorStatus1 && m_LV_bSensorChoose1 ) ||
		( m_RH_bSensorStatus1 && m_RH_bSensorChoose1 ) ||
		( m_RV_bSensorStatus1 && m_RV_bSensorChoose1 ) ||
		( m_LH_bSensorStatus2 && m_LH_bSensorChoose2 ) ||
		( m_LV_bSensorStatus2 && m_LV_bSensorChoose2 ) ||
		( m_RH_bSensorStatus2 && m_RH_bSensorChoose2 ) ||
		( m_RV_bSensorStatus2 && m_RV_bSensorChoose2 ) )
		return false;
	return true;
	-------------------------------------------------------*/
}

bool GlobalData::CheckSensorState( )
{
	bool bSensorOk = true;
	if( ( m_LH_bSensorStatus1 && m_LH_bSensorChoose1 ) || ( m_LH_bSensorStatus2 && m_LH_bSensorChoose2 ) ){
		m_LH_Error |= REPORT_8_ERR;
		bSensorOk = false;
	}
	if( ( m_LV_bSensorStatus1 && m_LV_bSensorChoose1 ) || ( m_LV_bSensorStatus2 && m_LV_bSensorChoose2 ) ){
		m_LV_Error |= REPORT_8_ERR;
		bSensorOk = false;
	}
	if( ( m_RH_bSensorStatus1 && m_RH_bSensorChoose1 ) || ( m_RH_bSensorStatus2 && m_RH_bSensorChoose2 ) ){
		m_RH_Error |= REPORT_8_ERR;
		bSensorOk = false;
	}
	if( ( m_RV_bSensorStatus1 && m_RV_bSensorChoose1 ) || ( m_RV_bSensorStatus2 && m_RV_bSensorChoose2 ) ){
		m_RV_Error |= REPORT_8_ERR;
		bSensorOk = false;
	}
	return bSensorOk;
}

void GlobalData::SortedData(QVector<double> &xList, QVector<double> &yList) //bubble sort.冒泡排序
{
	int Len = xList.size();
	for(int i=0 ; i<Len ; i++){
		for(int j=i+1 ; j<Len ; j++){
			if(xList[i] > xList[j] ){
				double tmpX = xList[i];
				double tmpY = yList[i];
				xList[i] = xList[j];
				yList[i] = yList[j];
				xList[j] = tmpX;
				yList[j] = tmpY;
			}	
		}
	}
}

double GlobalData::qQuickMedian(double * bArray, int iFilterLen)
{
    double bTemp;
	//冒泡排序，降序
	for(int i=0 ; i<iFilterLen ; i++){
		for(int j=i+1 ; j<iFilterLen ; j++){
			if( bArray[i] < bArray[j] ){
                bTemp = bArray[i];
                bArray[i] = bArray[j];
                bArray[j] = bTemp;
			}	
		}
	}
	/*
    if ((iFilterLen & 1) > 0)
        bTemp = bArray[ ( iFilterLen - 1 )/2 ];
    else
        bTemp = bArray[iFilterLen/2 - 1];
	*/
	int idx = iFilterLen * 0.4;
	idx = idx < 0 ? 0 : idx;
	idx = idx > iFilterLen/2 ? iFilterLen/2 : idx;
    bTemp = bArray[idx];
    return bTemp;
}

void GlobalData::qQuickMedianGroup( double *bArray1, double *bArray2, int iFilterLen,double &iRet1,double &iRet2 )
{
    double bTemp1,bTemp2;
	
	for(int i=0 ; i<iFilterLen ; i++){
		for(int j=i+1 ; j<iFilterLen ; j++){
			if( bArray1[i] < bArray1[j] ){
                bTemp1 = bArray1[i];
                bArray1[i] = bArray1[j];
                bArray1[j] = bTemp1;
			}	
			if( bArray2[i] < bArray2[j] ){
                bTemp2 = bArray2[i];
                bArray2[i] = bArray2[j];
                bArray2[j] = bTemp2;
			}	
		}
	}
	/*
	if ((iFilterLen & 1) > 0){
        iRet1 = bArray1[ ( iFilterLen - 1 )/2 ];
        iRet2 = bArray2[ ( iFilterLen - 1 )/2 ];
	}
	else{
        iRet1 = bArray1[iFilterLen/2 - 1];
        iRet2 = bArray2[iFilterLen/2 - 1];
	}
	*/
	int idx = iFilterLen * 0.4;
	idx = idx < 0 ? 0 : idx;
	idx = idx > iFilterLen/2 ? iFilterLen/2 : idx;
    iRet1 = bArray1[idx];
    iRet2 = bArray2[idx];
}

void GlobalData::SortedScanData( )
{
	SortedData(m_L_ScanDataX, m_L_ScanDataY);
	SortedData(m_R_ScanDataX, m_R_ScanDataY);
	GetLScanDataMaxY( );
	GetRScanDataMaxY( );
}

void GlobalData::GetLScanDataMaxY( )
{
	int Len = m_L_ScanDataY.size();
	m_L_ScanDataMaxY = 1E-10;
	for(int i=0 ; i<Len ; i++){
		double value = m_L_ScanDataY.at(i);
		if( value > m_L_ScanDataMaxY ){
			m_L_ScanDataMaxY = value;
		}
	}

	if(m_L_ScanDataMaxY < 100)
		m_L_ScanDataMaxY = 100;
	else if(m_L_ScanDataMaxY < 150)
		m_L_ScanDataMaxY = 150;
	else if(m_L_ScanDataMaxY < 200)
		m_L_ScanDataMaxY = 200;
	else if(m_L_ScanDataMaxY < 250)
		m_L_ScanDataMaxY = 250;
	else
		m_L_ScanDataMaxY = 300;
}
void GlobalData::GetRScanDataMaxY( )
{
	int Len = m_R_ScanDataY.size();
	m_R_ScanDataMaxY = 1E-10;
	for(int i=0 ; i<Len ; i++){
		double value = m_R_ScanDataY.at(i);
		if( value > m_R_ScanDataMaxY ){
			m_R_ScanDataMaxY = value;
		}
	}

	if(m_R_ScanDataMaxY < 100)
		m_R_ScanDataMaxY = 100;
	else if(m_R_ScanDataMaxY < 150)
		m_R_ScanDataMaxY = 150;
	else if(m_R_ScanDataMaxY < 200)
		m_R_ScanDataMaxY = 200;
	else if(m_R_ScanDataMaxY < 250)
		m_R_ScanDataMaxY = 250;
	else
		m_R_ScanDataMaxY = 300;
}

void GlobalData::getValues( )
{
	QMutexLocker locker(&m_Mutex);  

	m_L_SMWCurPos = mf_L_SMWCurPos;
	m_R_SMWCurPos = mf_R_SMWCurPos;

	m_LH_MotorCurPos = mf_LH_MotorCurPos;
	m_LV_MotorCurPos = mf_LV_MotorCurPos;
	m_RH_MotorCurPos = mf_RH_MotorCurPos;
	m_RV_MotorCurPos = mf_RV_MotorCurPos;

	m_LH_SensorCurValue1 = mf_LH_SensorCurValue1;
	m_LV_SensorCurValue1 = mf_LV_SensorCurValue1;
	m_RH_SensorCurValue1 = mf_RH_SensorCurValue1;
	m_RV_SensorCurValue1 = mf_RV_SensorCurValue1;
	m_LH_SensorCurValue2 = mf_LH_SensorCurValue2;
	m_LV_SensorCurValue2 = mf_LV_SensorCurValue2;
	m_RH_SensorCurValue2 = mf_RH_SensorCurValue2;
	m_RV_SensorCurValue2 = mf_RV_SensorCurValue2;

	m_L_SMWCurSpeed = mf_L_SMWCurSpeed;
	m_R_SMWCurSpeed = mf_R_SMWCurSpeed;
	m_L_AxisAngularSpeed = mf_L_AxisAngularSpeed;
	m_R_AxisAngularSpeed = mf_R_AxisAngularSpeed;

	m_L_HydraulicTransmitter = mf_L_HydraulicTransmitter;
	m_R_HydraulicTransmitter = mf_R_HydraulicTransmitter;

	/*
	m_L_HydraulicPValve = mf_L_HydraulicPValve;
	m_R_HydraulicPValve = mf_R_HydraulicPValve;
	*/
	m_L_Power = mf_L_Power; 
	m_R_Power = mf_R_Power; 

	m_L_Temparature = mf_L_Temparature; 
	m_R_Temparature = mf_R_Temparature; 

	m_LH_MotorDistToGo = mf_LH_MotorDistToGo;
	m_LV_MotorDistToGo = mf_LV_MotorDistToGo;
	m_RH_MotorDistToGo = mf_RH_MotorDistToGo;
	m_RV_MotorDistToGo = mf_RV_MotorDistToGo;

	m_CurTrainSpeed = (m_L_SMWCurSpeed + m_R_SMWCurSpeed)/2;
}

void GlobalData::WorkMileageProc( )// 作业里程处理
{
	if( m_nWorkState >= WORKSTATE_WORKIN_INI && m_nWorkState <= WORKSTATE_WORKOUT)
	{
		m_L_SMWWorkMileage =  (m_L_SMWCurPos - m_L_SMWStartWork)/1000;
		m_R_SMWWorkMileage =  (m_R_SMWCurPos - m_R_SMWStartWork)/1000;

		double iWorkMileage  = (m_L_SMWWorkMileage+m_R_SMWWorkMileage)/2000;
		if( fabs(iWorkMileage - m_ReportWorkMileage) > 0.1){
			m_ReportWorkMileage = iWorkMileage;
			TcuSetWorkMileageProc(m_ReportWorkMileage);
		}
	}
}

double GlobalData::double2double(double input_d)
{
	double r_double = 0;
	input_d*=1000.000;
	int tmp = input_d;
	r_double = tmp/1000.000;
	return r_double;
}

bool GlobalData::IsWorkingState()
{
	bool retVal = false;
	if( m_nWorkState >= WORKSTATE_STARTFELLOW_INI && m_nWorkState <= WORKSTATE_ENDFELLOW)
		retVal = true;
	return retVal;
}

void GlobalData::DeviceLockStateProc( )
{
	//弃用 ligy 20190906 add
	/*if(m_bLockState0 && !m_bLockState1)
		TcuSetDeviceLockState(true);
	if(!m_bLockState0 && m_bLockState1)
		TcuSetDeviceLockState(false);
	if(!m_bLockState0 && !m_bLockState1)
		TcuSetDeviceLockState(false);*/
}
//判断两个浮点数 是否相等
bool GlobalData::isEqualFloat(double a,double b)
{
#define EPSILON 0.000001 //根据精度需要  
	if (fabs(a - b) < EPSILON)
	{
		return true;
	}
	else
	{
		return false;
	}

}
void GlobalData::DeviceHighStateProc( )
{
	/*if(g->m_L_bHighSignal && g->m_R_bHighSignal)
		TcuSetDeviceHighState(true);
	else
		TcuSetDeviceHighState(false);*/
}

/*--------------------------------------------------*/
//TCU Pro1 : TcuComConnect
/*--------------------------------------------------*/
void GlobalData::TcuConnectProc( )
{
	m_bPreTrainCommState = true;
	m_bTrainCommState = true;
	return;
	if ( 0 != g_pTcu ){
		int iLen = g_pTcu->TcuComDisConnect( );
		int Len = g_pTcu->TcuComConnect( );
		if( -1 == Len ){
			m_bPreTrainCommState = m_bTrainCommState;
			m_bTrainCommState = false;
		}
		else{
			m_bPreTrainCommState = true;
			m_bTrainCommState = true;
		}
	}
}

/*--------------------------------------------------*/
//TCU Pro2 : HeartBeatProc
/*--------------------------------------------------*/
void GlobalData::TcuHeartBeatProc( )
{
	if ( 0 != g_pTcu ){
		if( m_bTrainCommState ){
			g_pTcu->SetHeartBeat( );
		}
	}
}

/*--------------------------------------------------*/
//TCU Pro3 : TcuEnableTrain
/*--------------------------------------------------*/
void GlobalData::TcuEnableTrainProc(bool bEnable)
{
	if ( 0 != g_pTcu ){
		if( m_bTrainCommState ){
			g_pTcu->EnableTrain( bEnable );
		}
	}
}

/*--------------------------------------------------*/
//TCU Pro4 : TcuEnableTrain
/*--------------------------------------------------*/
void GlobalData::TcuSetWorkStateProc(bool bStart)
{
	if ( 0 != g_pTcu ){
		if( m_bTrainCommState ){
			g_pTcu->SetWorkStartState( bStart );
		}
	}
}

/*--------------------------------------------------*/
//TCU Pro5 : SetWorkMileage
/*--------------------------------------------------*/
void GlobalData::TcuSetWorkMileageProc(double fWorkMileage)
{
	if ( 0 != g_pTcu ){
		if( m_bTrainCommState ){
			g_pTcu->SetWorkMileage( fWorkMileage );
		}
	}
}

/*--------------------------------------------------*/
//TCU Pro6 : TcuSetTrainSpeedProc
/*--------------------------------------------------*/
void GlobalData::TcuSetTrainSpeedProc(double fSpeed)
{
	if ( 0 != g_pTcu ){
		if( m_bTrainCommState ){
			g_pTcu->SetTrainSpeed(fSpeed);
		}
	}
}

/*--------------------------------------------------*/
//TCU Pro7 : TcuSetDeviceLockState
/*--------------------------------------------------*/	
void GlobalData::TcuSetDeviceLockState(bool bLocked)
{
	if ( 0 != g_pTcu ){
		if( m_bTrainCommState ){
			g_pTcu->SetDeviceLockState(bLocked);
		}
	}
}

/*--------------------------------------------------*/
//TCU Pro8 : TcuSetEmergencyLiftState
/*--------------------------------------------------*/	
void GlobalData::TcuSetEmergencyState(bool bEmergency)
{
	if ( 0 != g_pTcu ){
		if( m_bTrainCommState ){
			g_pTcu->SetEmergencyState(bEmergency);
		}
	}
}

/*--------------------------------------------------*/
//TCU Pro9 : TcuSetDeviceHighState
/*--------------------------------------------------*/	
void GlobalData::TcuSetDeviceHighState(bool bHigh)
{
	if ( 0 != g_pTcu ){
		if( m_bTrainCommState ){
			g_pTcu->SetDeviceHighState(bHigh);
		}
	}
}

/*--------------------------------------------------*/
//TCU Pro10 : TcuSetDeviceErrState
/*--------------------------------------------------*/	
void GlobalData::TcuSetDeviceErrState(bool bErr)
{
	if ( 0 != g_pTcu ){
		if( m_bTrainCommState ){
			g_pTcu->SetDeviceErrState(bErr);
		}
	}
}

/*--------------------------------------------------*/
//TCU Pro11 : HandleTcuErrProc
/*--------------------------------------------------*/	
SlCapErrorEnum GlobalData::TcuSendData( )
{
	SlCapErrorEnum eError = SL_CAP_OK;
	if ( 0 != g_pTcu ){
		//Step1 : SendTcuData
		if( m_bTrainCommState ){
			int Len = g_pTcu->SendTcuData( );
			if( -1 == Len ){
				m_bPreTrainCommState = m_bTrainCommState;
				m_bTrainCommState = false;
			}
		}
		//Step2 : Error Proc
		if ( m_bPreTrainCommState && !m_bTrainCommState ){
			if( (m_nWorkState > WORKSTATE_NULL) && (m_nWorkState < WORKSTATE_EMERGENCY_PCU) ){
				SetPCUWorkState( WORKSTATE_EMERGENCY_PCU );
				eError = EmergencyStopProc( m_nWorkState );
			}
			g_pErr->createTCUCOMAlarm( );
			m_bPreTrainCommState = m_bTrainCommState;
		}
	}
	return eError;
}

/*--------------------------------------------------*/
//TCU Pro11 : HandleTcuErrProc
/*--------------------------------------------------*/	
SlCapErrorEnum GlobalData::HandleTcuErrProc( )
{
	SlCapErrorEnum eError = SL_CAP_OK;
	//Step2 : Error Proc
	if ( m_bPreTrainCommState && !m_bTrainCommState ){
		if( (m_nWorkState > WORKSTATE_NULL) && (m_nWorkState < WORKSTATE_EMERGENCY_PCU) ){
			SetPCUWorkState( WORKSTATE_EMERGENCY_PCU );
			eError = EmergencyStopProc( m_nWorkState );
		}
		g_pErr->createTCUCOMAlarm( );
	}
	m_bPreTrainCommState = m_bTrainCommState;
	return eError;
}
