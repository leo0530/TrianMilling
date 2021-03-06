///////////////////////////////////////////////////////////////////////////////
/*! \file   trainmillingdialog.cpp
 *  \author
 *  \date
 *  \brief  Implementation file for class TrainMillingdialog
 *
 *  This file is part of the HMI Solutionline.
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////
#include "trainmillingdialog.h"
#include "GlobalVar.h"

///////////////////////////////////////////////////////////////////////////////
// CREATORS
///////////////////////////////////////////////////////////////////////////////

TrainMillingdialog::TrainMillingdialog(QObject* pParent , const QString& rsName )
{
	g = new GlobalData();
	g_pIni = new OperateIni();
	g_pTcu = new QTcuCom();
	g_pErr = new ErrorData();
	// initialize Hotlink
	//IniHotlink( );
	//IniGDReadParameter( );
	//IniGDWriteParameter( );
	//---------------------------------------------------------------------------------
	// initialize timer for toggle R-Parameter
	m_tmrToggle.setSingleShot(false);
	m_tmrToggle.setInterval(1000);

	// signal/slot connection for QTimer
	QObject::connect( &m_tmrToggle,SIGNAL(timeout()),this,SLOT(TimeoutSlot()) );

	// start timer
	m_tmrToggle.start();

	//---------------------------------------------------------------------------------
	// initialize timer for toggle Scanning
	m_tmrScan.setSingleShot(false);
	m_tmrScan.setInterval(20);

	// signal/slot connection for QTimer
	QObject::connect( &m_tmrScan,SIGNAL(timeout()),this,SLOT(ScanTimeoutSlot()) );//轨廓扫描定时器，周期20ms
	// start timer
	//m_tmrScan.start();

	//---------------------------------------------------------------------------------
	// initialize timer for Milling Timer
	m_tmrMilling.setSingleShot(false);
	m_tmrMilling.setInterval(50);

	// signal/slot connection for QTimer
	QObject::connect( &m_tmrMilling,SIGNAL(timeout()),this,SLOT(MillingTimeoutSlot()) );//铣削作业定时器，周期50ms

	// start timer
	m_tmrMilling.start();

	//---------------------------------------------------------------------------------
	deleteDirectoryFiles("..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\log");
	deleteDirectoryFiles("..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\workrecord");
	deleteDirectoryFiles("..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\ScanData");
	deleteDirectoryFiles("..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\SensorData");
	deleteDirectoryFiles("..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\SaveData");//ligy 20200211 add
	
	StartRecordData( );

	g->DataProcessTest_WriteSaveDataIni();//ligy 20200211 add 保存数据文件初始化
	g->StartLogData();//ligy 20200212 add.打开日志文件
	//Scanner
	m_bIsScanning = false;
	m_bIsNewScanData = false;
	m_bIsTrainSpeedIni = true;
	m_bIsInitial = true;
	g_pDialog = this;

} // <-- TrainMillingdialog::TrainMillingdialog ()


TrainMillingdialog::~TrainMillingdialog (void)
{
	m_MillingDataHotlink.unadvise(m_MillingDataHandleHotlink);
	m_MillingControlHotlink.unadvise(m_MillingControlHandleHotlink);
	m_StatusHotlink.unadvise(m_StatusHandleHotlink);
	m_IOListHotlink.unadvise(m_IOListHandleHotlink);
	m_ErrListHotlink.unadvise(m_ErrListHandleHotlink);
	if( NULL != g ){
		delete g;				g = NULL;
	}
	if( NULL != g_pIni ){
		delete g_pIni;			g_pIni = NULL;
	}
	if( NULL != g_pTcu ){
		delete g_pTcu;			g_pTcu = NULL;
	}
	if( NULL != g_pErr ){
		delete g_pErr;			g_pErr = NULL;
	}

	if(m_tmrToggle.isActive())
		m_tmrToggle.stop();
	if(m_tmrMilling.isActive())
		m_tmrMilling.stop();
	if(m_tmrScan.isActive())
		m_tmrScan.stop();

	StopRecordData( );

	g->DataProcessTest_WriteSaveDataFini();//ligy 20200211 add 关闭保存数据文件
	g->StopLogData();//ligy 20200212 add.关闭日志文件

} // <-- TrainMillingdialog::~TrainMillingdialog ()


void TrainMillingdialog::IniHotlink( )//初始化hotlink ligy 20190904 add
{
	//-----------------Milling Data need in the Milling algorithm
	// fill multi read specification
	QVector<SlCapAdviseSpecType> vecMillingDataAdviseSpec;
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_L_SMWPos,SlQCap::highUpdateRate() ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_R_SMWPos,SlQCap::highUpdateRate() ) );
	
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_LH_MotorPos,SlQCap::highUpdateRate() ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_LV_MotorPos,SlQCap::highUpdateRate() ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_RH_MotorPos,SlQCap::highUpdateRate() ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_RV_MotorPos,SlQCap::highUpdateRate() ) );

	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_LH_SensorValue1,SlQCap::highUpdateRate() ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_LH_SensorValue2,SlQCap::highUpdateRate() ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_LV_SensorValue1,SlQCap::highUpdateRate() ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_LV_SensorValue2,SlQCap::highUpdateRate() ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_RH_SensorValue1,SlQCap::highUpdateRate() ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_RH_SensorValue2,SlQCap::highUpdateRate() ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_RV_SensorValue1,SlQCap::highUpdateRate() ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_RV_SensorValue2,SlQCap::highUpdateRate() ) );

	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_L_SMWSpeed ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_R_SMWSpeed ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_LAxisAngularSpeed ) );			//g->m_L_AxisAngularSpeed
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_RAxisAngularSpeed ) );			//g->m_R_AxisAngularSpeed

	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_L_HydraulicTransmitter) );		//g->m_L_HydraulicTransmitter
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_R_HydraulicTransmitter) );		//g->m_R_HydraulicTransmitter

	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_L_Power) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_R_Power) );

	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_LH_DistToGo ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_LV_DistToGo ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_RH_DistToGo ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_RV_DistToGo ) );

	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_L_Temparature) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_R_Temparature) );

	/*
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_L_Power_1) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_R_Power_1) );
	//--------This Value is Not Needed!!!!s
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_L_HydraulicPValve) );			//g->m_L_HydraulicPValve
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_R_HydraulicPValve) );			//g->m_R_HydraulicPValve

	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_LH_EdgeMark1,SlQCap::highUpdateRate() ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_LV_EdgeMark1,SlQCap::highUpdateRate() ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_RH_EdgeMark1,SlQCap::highUpdateRate() ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_RV_EdgeMark1,SlQCap::highUpdateRate() ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_LH_EdgeMark2,SlQCap::highUpdateRate() ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_LV_EdgeMark2,SlQCap::highUpdateRate() ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_RH_EdgeMark2,SlQCap::highUpdateRate() ) );
	vecMillingDataAdviseSpec.append( SlCapAdviseSpecType(szItem_RV_EdgeMark2,SlQCap::highUpdateRate() ) );
	*/
	// advise data
	SlCapErrorEnum eError = m_MillingDataHotlink.multiAdvise(vecMillingDataAdviseSpec, m_MillingDataHandleHotlink);
	// write success or error to the status bar
	handleRetVal(eError);

	//-----------------Milling Control Data need in the Milling algorithm
	QVector<SlCapAdviseSpecType> vecMillingControlAdviseSpec;
	vecMillingControlAdviseSpec.append( SlCapAdviseSpecType(szItem_TrainStart_Bit) );//列车启动
	vecMillingControlAdviseSpec.append( SlCapAdviseSpecType(szItem_WorkStart_Bit) );//作业开始
	vecMillingControlAdviseSpec.append( SlCapAdviseSpecType(szItem_WorkStop_Bit) ); //作业停止
	vecMillingControlAdviseSpec.append( SlCapAdviseSpecType(szItem_TrainStop_Bit) );//列车停止
	vecMillingControlAdviseSpec.append( SlCapAdviseSpecType(szItem_ScanStart_Bit) );//扫描启停标志
	vecMillingControlAdviseSpec.append( SlCapAdviseSpecType(szItem_PLCStatus_Word) );//NCU作业阶段状态字	
	vecMillingControlAdviseSpec.append( SlCapAdviseSpecType(szItem_AlarmWorkStop_Bit) );	
	vecMillingControlAdviseSpec.append( SlCapAdviseSpecType(szItem_PLCShineStatus_Word) );//打磨状态字
	//vecMillingControlAdviseSpec.append( SlCapAdviseSpecType(szItem_LoadDown_Bit) );	//Reserved!!!
	// advise data
	eError = m_MillingControlHotlink.multiAdvise(vecMillingControlAdviseSpec, m_MillingControlHandleHotlink);
	// write success or error to the status bar
	handleRetVal(eError);

	//-----------------Status need in the Milling algorithm
	QVector<SlCapAdviseSpecType> vecStatusAdviseSpec;
	/*-------this part of content is placed in IOList------------------
	vecStatusAdviseSpec.append( SlCapAdviseSpecType(szItem_LH_bSensorStatus1) );
	vecStatusAdviseSpec.append( SlCapAdviseSpecType(szItem_LV_bSensorStatus1) );
	vecStatusAdviseSpec.append( SlCapAdviseSpecType(szItem_RH_bSensorStatus1) );
	vecStatusAdviseSpec.append( SlCapAdviseSpecType(szItem_RV_bSensorStatus1) );
	vecStatusAdviseSpec.append( SlCapAdviseSpecType(szItem_LH_bSensorStatus2) );
	vecStatusAdviseSpec.append( SlCapAdviseSpecType(szItem_LV_bSensorStatus2) );
	vecStatusAdviseSpec.append( SlCapAdviseSpecType(szItem_RH_bSensorStatus2) );
	vecStatusAdviseSpec.append( SlCapAdviseSpecType(szItem_RV_bSensorStatus2) );
	*/
	vecStatusAdviseSpec.append( SlCapAdviseSpecType(szItem_LockState0_Bit) );
	vecStatusAdviseSpec.append( SlCapAdviseSpecType(szItem_LockState1_Bit) );
	vecStatusAdviseSpec.append( SlCapAdviseSpecType(szItem_CH1NCState_Bit) );
	vecStatusAdviseSpec.append( SlCapAdviseSpecType(szItem_CH2NCState_Bit) );
	vecStatusAdviseSpec.append( SlCapAdviseSpecType(szItem_RepairOver_Bit) );
	vecStatusAdviseSpec.append( SlCapAdviseSpecType(szItem_LCollectorBinState_Bit) );//
	vecStatusAdviseSpec.append( SlCapAdviseSpecType(szItem_RCollectorBinState_Bit) );//
	vecStatusAdviseSpec.append( SlCapAdviseSpecType(szItem_BogyState_Bit) );
	/*
	vecStatusAdviseSpec.append( SlCapAdviseSpecType(szItem_GrindState_Bit) );
	*/
	// advise data
	eError = m_StatusHotlink.multiAdvise(vecStatusAdviseSpec, m_StatusHandleHotlink);
	// write success or error to the status bar
	handleRetVal(eError);

	//-----------------IOList need in the Milling algorithm
	QVector<SlCapAdviseSpecType> vecIOListAdviseSpec;
    QStringList IOList = (QStringList() <<"I32"<<"I33"<<"I34"<<"I35"<<"I36"<<"I37"<<"I38"<<"I39"
										<<"I40"<<"I41"<<"I42"<<"I43"<<"I44"<<"I45"<<"I46"<<"I47"
										<<"I48"<<"I49"<<"I50"<<"I51"<<"I52"<<"I64"<<"I65"<<"I66"
										<<"I67"<<"I68"<<"Q32"<<"Q33"<<"Q34"<<"Q36"<<"Q37"<<"Q38"
										<<"Q39"<<"Q40"<<"Q41"<<"Q42"<<"Q43"<<"Q44"<<"Q45"<<"Q64"
										<<"Q65"<<"Q66"<<"Q67"<<"Q68"<<"Q69"<<"Q35"	);
	int IOListCount = IOList.count();
	for(int i=0 ; i<IOListCount ; i++ )
	{
		QString IOAddr = IOList.at(i);
		for(int j=0 ; j<8 ; j++ )
		{
			QString IOBit = IOAddr+"."+QString::number(j);
			vecIOListAdviseSpec.append( SlCapAdviseSpecType(IOBit) );
		}
	}
	// advise data
	eError = m_IOListHotlink.multiAdvise(vecIOListAdviseSpec, m_IOListHandleHotlink);
	//-----------------ErrList need in the Milling algorithm
	QVector<SlCapAdviseSpecType> vecErrListAdviseSpec;
    QStringList ErrList = (QStringList() <<"M200");
	int ErrListCount = ErrList.count();
	for(int i=0 ; i<ErrListCount ; i++ )
	{
		QString ErrAddr = ErrList.at(i);
		for(int j=0 ; j<8 ; j++ )
		{
			QString ErrBit = ErrAddr+"."+QString::number(j);
			vecErrListAdviseSpec.append( SlCapAdviseSpecType(ErrBit) );
		}
	}
	// advise data
	eError = m_ErrListHotlink.multiAdvise(vecErrListAdviseSpec, m_ErrListHandleHotlink);
	// write success or error to the status bar
	handleRetVal(eError);

	// signal/slot connection for SlQCap
	QObject::connect(&m_MillingDataHotlink,
	 				 SIGNAL(multiAdviseData(SlCapErrorEnum, const QVector<SlCapAdviseResultType>&)),
					 this,
					 SLOT(FreshMillingDataSlot(SlCapErrorEnum, const QVector<SlCapAdviseResultType>&)));
	QObject::connect(&m_MillingControlHotlink,
	 				 SIGNAL(multiAdviseData(SlCapErrorEnum, const QVector<SlCapAdviseResultType>&)),
					 this,
					 SLOT(FreshMillingControlSlot(SlCapErrorEnum, const QVector<SlCapAdviseResultType>&)));
	QObject::connect(&m_StatusHotlink,
 					 SIGNAL(multiAdviseData(SlCapErrorEnum, const QVector<SlCapAdviseResultType>&)),
					 this,
					 SLOT(FreshStatusSlot(SlCapErrorEnum, const QVector<SlCapAdviseResultType>&)));
	QObject::connect(&m_IOListHotlink,
	 				 SIGNAL(multiAdviseData(SlCapErrorEnum, const QVector<SlCapAdviseResultType>&)),
					 this,
					 SLOT(FreshIOListSlot(SlCapErrorEnum, const QVector<SlCapAdviseResultType>&)));
	QObject::connect(&m_ErrListHotlink,
	 				 SIGNAL(multiAdviseData(SlCapErrorEnum, const QVector<SlCapAdviseResultType>&)),
					 this,
					 SLOT(FreshErrListSlot(SlCapErrorEnum, const QVector<SlCapAdviseResultType>&)));
}

void TrainMillingdialog::TimeoutSlot()
{
//	g_pIni->ReadWorkStateParameters();
	QDateTime current_date_time =QDateTime::currentDateTime();
	QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss ddd");

	if(m_bIsInitial == true){
		m_bIsInitial = false;
		//Step1 : checkBothSerialNumber
		//genBothSerialNumber();
		g->m_bIsCertified = true;//checkBothSerialNumber();
		if(g->m_bIsCertified == true && 0 != g_pMainForm )
			g_pMainForm->showLoginUI();
		if(g->m_bIsCertified == false && 0 != g_pMainForm ){
			g_pMainForm->hideLoginUI();
		}
		if(g->m_bIsCertified == false){
			g_pErr->createLicenseAlarm();
		}

		//Step2 : checkDiskSpace
		int retVal = checkDiskSpace( );
		if(retVal != RET_OK){
			g_pErr->createLackSpaceAlarm();
		}

		//Step3 :IniHotlink
		IniHotlink();

		//Step4 : IniTcuCom
		///g->TcuConnectProc( );//弃用 ligy 20190906 add

		/*		
		g_pTcu->EnableTrain(true);
		g_pTcu->SendTcuData( );

		g_pTcu->EnableTrain(false);
		g_pTcu->SendTcuData( );

		g_pTcu->SetTrainSpeed(0.3);
		g_pTcu->SendTcuData( );

		g_pTcu->SetWorkMileage(0.3);
		g_pTcu->SendTcuData( );

		g_pTcu->SetDeviceLockState(true);
		g_pTcu->SendTcuData( );

		g_pTcu->SetDeviceLockState(false);
		g_pTcu->SendTcuData( );

		g_pTcu->SetWorkStartState(true);
		g_pTcu->SendTcuData( );

		g_pTcu->SetWorkStartState(false);
		g_pTcu->SendTcuData( );

		g_pTcu->SetEmergencyState(true);
		g_pTcu->SendTcuData( );

		g_pTcu->SetEmergencyState(false);
		g_pTcu->SendTcuData( );

		g_pTcu->SetDeviceHighState(true);
		g_pTcu->SendTcuData( );

		g_pTcu->SetDeviceHighState(false);
		g_pTcu->SendTcuData( );

		g_pTcu->SetDeviceErrState(true);
		g_pTcu->SendTcuData( );

		g_pTcu->SetDeviceErrState(false);
		g_pTcu->SendTcuData( );
		*/
	}

	if ( 0 != g_pMainForm )
		g_pMainForm->setCaptionBarElementText(current_date,1);
	if ( 0 != g_pParameterForm )
		g_pParameterForm->setCaptionBarElementText(current_date,1);
	if ( 0 != g_pScanForm )
		g_pScanForm->setCaptionBarElementText(current_date,1);
	if ( 0 != g_pStatusForm )
		g_pStatusForm->setCaptionBarElementText(current_date,1);
	if ( 0 != g_pSystemForm )
		g_pSystemForm->setCaptionBarElementText(current_date,1);
	if ( 0 != g_pErrorForm )
		g_pErrorForm->setCaptionBarElementText(current_date,1);
	if ( 0 != g_pOperateManualForm )
		g_pOperateManualForm->setCaptionBarElementText(current_date,1);
	if ( 0 != g_pPowerForm )
		g_pPowerForm->setCaptionBarElementText(current_date,1);
	if ( 0 != g_pRecordForm )
		g_pRecordForm->setCaptionBarElementText(current_date,1);
	if ( 0 != g_pDebugForm )
		g_pDebugForm->setCaptionBarElementText(current_date,1);	
	if ( 0 != g_pStatusListForm )
		g_pStatusListForm->setCaptionBarElementText(current_date,1);	
	if ( 0 != g_pRailCalibForm )
		g_pRailCalibForm->setCaptionBarElementText(current_date,1);	
	if ( 0 != g_pUserManagerForm )
		g_pUserManagerForm->setCaptionBarElementText(current_date,1);	
	if ( 0 != g_pOperateNoticeForm )
		g_pOperateNoticeForm->setCaptionBarElementText(current_date,1);	
	if ( 0 != g_pCPOffsetForm )
		g_pCPOffsetForm->setCaptionBarElementText(current_date,1);	
	if ( 0 != g_pConfirmForm )
		g_pConfirmForm->setCaptionBarElementText(current_date,1);	
}

///////////////////////////////////////////////////////////////////////////////
// Overrides
///////////////////////////////////////////////////////////////////////////////
void TrainMillingdialog::IniGDReadParameter( )
{
	// fill multi read specification
	/*
	m_vecGDReadSpec.clear();
	m_vecGDReadSpec.append( SlCapReadSpecType(szItem_LH_SensorValue1) );
	m_vecGDReadSpec.append( SlCapReadSpecType(szItem_LV_SensorValue1) );
	m_vecGDReadSpec.append( SlCapReadSpecType(szItem_LH_SensorValue2) );
	m_vecGDReadSpec.append( SlCapReadSpecType(szItem_LV_SensorValue2) );
	m_vecGDReadSpec.append( SlCapReadSpecType(szItem_LH_MotorPos) );
	m_vecGDReadSpec.append( SlCapReadSpecType(szItem_LV_MotorPos) );	
	m_vecGDReadSpec.append( SlCapReadSpecType(szItem_L_SMWPos) );

	m_vecGDReadSpec.append( SlCapReadSpecType(szItem_RH_SensorValue1) );
	m_vecGDReadSpec.append( SlCapReadSpecType(szItem_RV_SensorValue1) );
	m_vecGDReadSpec.append( SlCapReadSpecType(szItem_RH_SensorValue2) );
	m_vecGDReadSpec.append( SlCapReadSpecType(szItem_RV_SensorValue2) );
	m_vecGDReadSpec.append( SlCapReadSpecType(szItem_RH_MotorPos) );
	m_vecGDReadSpec.append( SlCapReadSpecType(szItem_RV_MotorPos) );	
	m_vecGDReadSpec.append( SlCapReadSpecType(szItem_R_SMWPos) );
	*/
}

void TrainMillingdialog::IniGDWriteParameter( )
{

}

void TrainMillingdialog::EmergencyStopProc( )
{
	g_pIni->SaveMileageParameters( );

	//g->m_DstTrainSpeed = 0;//设置速度为0  ligy 20190904 add
	g_iAddr40006 = 0;
	g_iAddr40007 = TRAIN_STOP;//机车停止
}

void TrainMillingdialog::MillingTimeoutSlot( )//定时器
{

	SlCapErrorEnum eError1 = g->TrainMillingProc( );
//	SlCapErrorEnum eError2 = g->TcuSendData( );  
	handleRetVal(eError1);
//	handleRetVal(eError2);
	if(g->m_bIsEmgyStop)
	{
		EmergencyStopProc( );//ligy 20190904 add  紧急提升
	}
	if ( 0 != g_pStatusForm )
	{
		g_pStatusForm->RefreshBias( );
		g_pStatusForm->RefreshWorkState( false );
		g_pStatusForm->RefreshState( );
		g_pStatusForm->RefreshData( );
		g_pStatusForm->RefreshShineState_PLC(false);//ligy 20190928 add
	}
	if ( 0 != g_pRailCalibForm )
		g_pRailCalibForm->FreshParameters( );	
	if ( 0 != g_pStatusListForm )
		g_pStatusListForm->UpdateIOItems( );
	if ( 0 != g_pDeviceRepairForm )
		g_pDeviceRepairForm->setLoginOutKeyState( );
	if ( 0 != g_pMainForm ){
		g_pMainForm->setLoginOutKeyState( );
		g_pMainForm->setHSoftkeyState( );
	}

	//g->DataProcessTest_ReadMSFile( );
	//g->DataProcessTest_ReadSensorFile();
	//g->DataProcessTest_RingBuffer();
	/*
	switch(g->m_StartTestStatus){
		case TESTSTATUS_START:
			g->DataProcessTest_WriteFileIni();
			g->m_StartTestStatus = TESTSTATUS_WORK;
			break;
		case TESTSTATUS_WORK:
			g->DataProcessTest_WriteFile();
			break;
		case TESTSTATUS_END:
			g->DataProcessTest_WriteFileFini();
			g->m_StartTestStatus = TESTSTATUS_NULL;
			break;
		case TESTSTATUS_NULL:
			break;
		default:
			break;
	}
	*/
}

void TrainMillingdialog::handleRetVal(SlCapErrorEnum eError)
{
	QString szInfo;
	// evaluate return value
	if( SL_CAP_OK != eError )
	{
		// write error in status bar
		QString szHexErrorNr = QString("%1").arg(eError,0,16).right(8);
		szInfo = ACCESS_ERROR.arg(szHexErrorNr);
		//setStatusBarElementText(ACCESS_ERROR.arg(szHexErrorNr), 0); 
		//----------------------------------------------------------------
		ShowInformation(szInfo);

		//Inner communication Error
		g->m_bPcuCommState = false;
		g_pErr->createPCUCOMAlarm();
	}
}

void TrainMillingdialog::ShowInformation(QString szInfo)
{
	if ( 0 != g_pMainForm )
		g_pMainForm->setStatusBarElementText(szInfo,0);
	if ( 0 != g_pParameterForm )
		g_pParameterForm->setStatusBarElementText(szInfo,0);
	if ( 0 != g_pScanForm )
		g_pScanForm->setStatusBarElementText(szInfo,0);
	if ( 0 != g_pStatusForm )
		g_pStatusForm->setStatusBarElementText(szInfo,0);
	if ( 0 != g_pSystemForm )
		g_pSystemForm->setStatusBarElementText(szInfo,0);
	if ( 0 != g_pErrorForm )
		g_pErrorForm->setStatusBarElementText(szInfo,0);
	if ( 0 != g_pOperateManualForm )
		g_pOperateManualForm->setStatusBarElementText(szInfo,0);
	if ( 0 != g_pPowerForm )
		g_pPowerForm->setStatusBarElementText(szInfo,0);
	if ( 0 != g_pRecordForm )
		g_pRecordForm->setStatusBarElementText(szInfo,0);
	if ( 0 != g_pDebugForm )
		g_pDebugForm->setStatusBarElementText(szInfo,0);	
	if ( 0 != g_pStatusListForm )
		g_pStatusListForm->setStatusBarElementText(szInfo,0);	
	if ( 0 != g_pRailCalibForm )
		g_pRailCalibForm->setStatusBarElementText(szInfo,0);	
	if ( 0 != g_pDeviceRepairForm )
		g_pDeviceRepairForm->setStatusBarElementText(szInfo,0);	
	if ( 0 != g_pDeviceRepairForm ) //ligy 20191205 add
		g_pDeviceRepairForm->setStatusBarElementText(szInfo,0);	
	if ( 0 != g_pSoftLimitFormForm )
		g_pSoftLimitFormForm->setStatusBarElementText(szInfo,0);
}

int TrainMillingdialog::checkDiskSpace( )
{
	int RetVal = RET_OK;
	_ULARGE_INTEGER freespace,totalspace,userspace;						//检查硬盘容量
	if(::GetDiskFreeSpaceEx("c:",&userspace,&totalspace,&freespace))	//盘符
	{
		double freevolume = double(freespace.QuadPart)/1024/1024/1024;	//单位GB
		if(freevolume<1)
			RetVal = RET_DISKSPACELOW;
		else if(freevolume<3)
			RetVal = RET_DISKSPACEALARM;
	}
	return RetVal;
}

bool TrainMillingdialog::checkBothSerialNumber()
{
	QString newserialNum;
    QString strMacAddr = getHostMacAddress( );  
	QString serialNum = getSerialNumber();
	newserialNum = strMacAddr + serialNum;

    QString md5;
	QByteArray byte_array = newserialNum.toLatin1(); 
    QCryptographicHash hash(QCryptographicHash::Md5);  
    hash.addData(byte_array);
    QByteArray result_byte_array = hash.result();
	md5.append( result_byte_array.toHex() );

	bool serialStatue = true;
	QFile file("..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\serialnum.ini");//    ..\\trainmilling\\serialnum.ini
	if(file.open(QIODevice::ReadOnly))
	{
		QTextStream stream(&file);
		QString line = stream.readAll();

		if(line!=md5){
			serialStatue=false;
		}
	}
	else{
		serialStatue=false;
	}
	file.close();
	return serialStatue;
}

void TrainMillingdialog::genBothSerialNumber()
{
	QString newserialNum;
    QString strMacAddr = getHostMacAddress( ); 
	QString serialNum = getSerialNumber();
	newserialNum = strMacAddr + serialNum;

    QString md5;
	QByteArray byte_array = newserialNum.toLatin1(); 
    QCryptographicHash hash(QCryptographicHash::Md5);  
    hash.addData(byte_array);
    QByteArray result_byte_array = hash.result();
	md5.append( result_byte_array.toHex() );

	QFile file("..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\serialnum.ini");//    ..\\trainmilling\\serialnum.ini
	if(file.open(QIODevice::WriteOnly))
	{
		QTextStream stream(&file);
		stream <<md5;
		stream.flush();
	}
	file.close();
}

bool TrainMillingdialog::checkHostMacAddress( )
{
    QString strMacAddr = getHostMacAddress( );  

	bool serialStatue = true;
	QFile file("..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\serialnum.ini");//    ..\\trainmilling\\serialnum.ini
	if(file.open(QIODevice::ReadOnly))
	{
		QTextStream stream(&file);
		QString line = stream.readAll();

		if(line!=strMacAddr){
			serialStatue=false;
		}
	}
	else{
		serialStatue=false;
	}
	file.close();
	return serialStatue;
}


void TrainMillingdialog::genHostMacAddress( )
{
    QString strMacAddr = getHostMacAddress( );  

	QFile file("..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\serialnum.ini");//    ..\\trainmilling\\serialnum.ini
	if(file.open(QIODevice::WriteOnly))
	{
		QTextStream stream(&file);
		stream <<strMacAddr;
		stream.flush();
	}
	file.close();
}

QString	TrainMillingdialog::getHostMacAddress( )
{
	/*
	QString strMacAddr1;
    QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();// 获取所有网络接口列表  
    int nCnt = nets.count();  
	QNetworkInterface thisNet;      //所要使用的网卡  
	for(int i = 0; i < nCnt; i++)  
    {  
        // 如果此网络接口被激活并且正在运行并且不是回环地址，则就是我们需要找的Mac地址  
        if(nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning) && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))  
        {  
            thisNet = nets[i];  
            break;  
        }  
    }
	strMacAddr1 = thisNet.hardwareAddress();
	*/
	char mac[200];
	QString strMacAddr;
	bool iRet = GetMAC(mac);
	if( iRet )
		strMacAddr = QString(QLatin1String(mac));
	else
		strMacAddr = "127.0.0.1";

    QString md5;
	QByteArray byte_array = strMacAddr.toLatin1(); 
    QCryptographicHash hash(QCryptographicHash::Md5);  
    hash.addData(byte_array);
    QByteArray result_byte_array = hash.result();
	md5.append(	result_byte_array.toHex() );

    return md5;
}

bool TrainMillingdialog::GetMAC(LPTSTR lpszMAC)
{
	//ASSERT(lpszMAC);
	char mac[200]={0};
	NCB ncb;
	typedef struct _ASTAT_
	{
		ADAPTER_STATUS   adapt;
		NAME_BUFFER   NameBuff   [30];
	}ASTAT,*PASTAT;

	ASTAT Adapter;

	typedef struct _LANA_ENUM
	{
		UCHAR   length;
		UCHAR   lana[MAX_LANA];
	}LANA_ENUM;

	LANA_ENUM lana_enum;
	UCHAR uRetCode;
	memset(&ncb, 0, sizeof(ncb));
	memset(&lana_enum, 0, sizeof(lana_enum));
	ncb.ncb_command = NCBENUM;
	ncb.ncb_buffer = (unsigned char *)&lana_enum;
	ncb.ncb_length = sizeof(LANA_ENUM);
	uRetCode = Netbios(&ncb);

	if(uRetCode != NRC_GOODRET)
		return false;    

	for(int lana=0; lana<lana_enum.length; lana++)
	{
		ncb.ncb_command = NCBRESET;
		ncb.ncb_lana_num = lana_enum.lana[lana];
		uRetCode = Netbios(&ncb);
		if(uRetCode == NRC_GOODRET)
			break;
	}

	if(uRetCode != NRC_GOODRET)
		return false;

	memset(&ncb, 0, sizeof(ncb));
	ncb.ncb_command = NCBASTAT;
	ncb.ncb_lana_num = lana_enum.lana[0];
	strcpy((char*)ncb.ncb_callname, "*");
	ncb.ncb_buffer = (unsigned char *)&Adapter;
	ncb.ncb_length = sizeof(Adapter);
	uRetCode = Netbios(&ncb);

	if(uRetCode != NRC_GOODRET)
		return false;

	sprintf(mac,"%02X:%02X:%02X:%02X:%02X:%02X",
		Adapter.adapt.adapter_address[0],
		Adapter.adapt.adapter_address[1],
		Adapter.adapt.adapter_address[2],
		Adapter.adapt.adapter_address[3],
		Adapter.adapt.adapter_address[4],
		Adapter.adapt.adapter_address[5]);
	strcpy(lpszMAC,mac);
	//log_printf("Get local mac address!");
	return true;
}

QString TrainMillingdialog::getSerialNumber()
{
	QString serialNum;
	SYSTEM_INFO info;
	GetSystemInfo(&info);
	DWORD sysInfo = info.dwNumberOfProcessors;
	unsigned int iSysInfo = sysInfo;
	QByteArray abyte;
	abyte.resize(4);
	abyte[0] = (uchar)(0x000000ff&iSysInfo);
	abyte[1] = (uchar)((0x000000ff&iSysInfo)>>8);
	abyte[2] = (uchar)((0x000000ff&iSysInfo)>>16);
	abyte[3] = (uchar)((0x000000ff&iSysInfo)>>24);
	QByteArray qba = QCryptographicHash::hash(abyte, QCryptographicHash::Md5);
	serialNum.append(qba.toHex());
	return serialNum;
}

void TrainMillingdialog::genSerialNumber()
{
	QString serialNum;
	QFile file("..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\serialnum.ini");//    ..\\trainmilling\\serialnum.ini
	if(file.open(QIODevice::WriteOnly))
	{
		QTextStream stream(&file);

		SYSTEM_INFO info;
		GetSystemInfo(&info);
		DWORD sysInfo = info.dwNumberOfProcessors;
		unsigned int iSysInfo = sysInfo;
		QByteArray abyte;
		abyte.resize(4);
		abyte[0] = (uchar)(0x000000ff&iSysInfo);
		abyte[1] = (uchar)((0x000000ff&iSysInfo)>>8);
		abyte[2] = (uchar)((0x000000ff&iSysInfo)>>16);
		abyte[3] = (uchar)((0x000000ff&iSysInfo)>>24);
		QByteArray qba = QCryptographicHash::hash(abyte, QCryptographicHash::Md5);
		serialNum.append(qba.toHex());

		stream <<serialNum;
		stream.flush();
	}
	file.close();
}

bool TrainMillingdialog::checkSerialNumber()
{
	bool serialStatue = true;
	QString serialNum;
	QFile file("..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\serialnum.ini");//    ..\\trainmilling\\serialnum.ini
	if(file.open(QIODevice::ReadOnly))
	{
		QTextStream stream(&file);
		QString line = stream.readAll();

		SYSTEM_INFO info;
		GetSystemInfo(&info);
		DWORD sysInfo = info.dwNumberOfProcessors;
		unsigned int iSysInfo = sysInfo;
		QByteArray abyte;
		abyte.resize(4);
		abyte[0] = (uchar)(0x000000ff&iSysInfo);
		abyte[1] = (uchar)((0x000000ff&iSysInfo)>>8);
		abyte[2] = (uchar)((0x000000ff&iSysInfo)>>16);
		abyte[3] = (uchar)((0x000000ff&iSysInfo)>>24);
		QByteArray qba = QCryptographicHash::hash(abyte, QCryptographicHash::Md5);
		serialNum.append(qba.toHex());
		//this->lineEdit3->setValue(serialNum);
		if(line!=serialNum){
			serialStatue=false;
		}
	}
	else{
		serialStatue=false;
	}
	file.close();
	return serialStatue;
}

void TrainMillingdialog::FreshMillingDataSlot(SlCapErrorEnum eError, const QVector<SlCapAdviseResultType>& adviseResult)
{
	if(SL_SUCCEEDED(eError))
	{
		QMutexLocker locker(&g->m_Mutex); 

		g->mf_L_SMWCurPos = adviseResult[0].m_vValue.toDouble();//测速轮P 左侧
		g->mf_R_SMWCurPos = adviseResult[1].m_vValue.toDouble();//测速轮P 右侧

		g->mf_LH_MotorCurPos = adviseResult[2].m_vValue.toDouble();//横向电机值 左侧
		g->mf_LV_MotorCurPos = adviseResult[3].m_vValue.toDouble();//纵向电机值 左侧
		g->mf_RH_MotorCurPos = adviseResult[4].m_vValue.toDouble();//横向电机值 右侧
		g->mf_RV_MotorCurPos = adviseResult[5].m_vValue.toDouble();//纵向电机值 右侧

		qint16 LH_SensorCurValue1 = adviseResult[6].m_vValue.toInt();
		qint16 LH_SensorCurValue2 = adviseResult[7].m_vValue.toInt();
		qint16 LV_SensorCurValue1 = adviseResult[8].m_vValue.toInt();
		qint16 LV_SensorCurValue2 = adviseResult[9].m_vValue.toInt();
		qint16 RH_SensorCurValue1 = adviseResult[10].m_vValue.toInt();
		qint16 RH_SensorCurValue2 = adviseResult[11].m_vValue.toInt();
		qint16 RV_SensorCurValue1 = adviseResult[12].m_vValue.toInt();
		qint16 RV_SensorCurValue2 = adviseResult[13].m_vValue.toInt();

		g->mf_L_SMWCurSpeed = adviseResult[14].m_vValue.toDouble();//测速轮速度V 左侧
		g->mf_R_SMWCurSpeed = adviseResult[15].m_vValue.toDouble();//测速轮速度V 右侧
		g->mf_L_AxisAngularSpeed =adviseResult[16].m_vValue.toDouble();//主轴转速 左侧
		g->mf_R_AxisAngularSpeed =adviseResult[17].m_vValue.toDouble();//主轴转速 右侧
		g->mf_L_SMWCurSpeed = fabs(g->mf_L_SMWCurSpeed)*0.00006;			//convert m/min to Km/h
		g->mf_R_SMWCurSpeed = fabs(g->mf_R_SMWCurSpeed)*0.00006;			//convert m/min to Km/h

		qint16 L_HydraulicTransmitter = adviseResult[18].m_vValue.toInt();//液压传送器 左侧
		qint16 R_HydraulicTransmitter = adviseResult[19].m_vValue.toInt();//液压传送器 右侧
		/*
		g->mf_L_Power = adviseResult[20].m_vValue.toInt();
		g->mf_R_Power = adviseResult[21].m_vValue.toInt();
		*/
		qint16 T_L_Power = adviseResult[20].m_vValue.toInt();
		qint16 T_R_Power = adviseResult[21].m_vValue.toInt();
		g->mf_L_Power = T_L_Power;
		g->mf_R_Power = T_R_Power;

		g->mf_L_Power = g->mf_L_Power < 0 ? 0 : g->mf_L_Power;
		g->mf_R_Power = g->mf_R_Power < 0 ? 0 : g->mf_R_Power;
		g->mf_L_Power = g->mf_L_Power/TOTAL_SPINDLE_POWER;// 功率 左侧 (%)
		g->mf_R_Power = g->mf_R_Power/TOTAL_SPINDLE_POWER;// 功率 右侧 (%)

		g->mf_LH_MotorDistToGo = adviseResult[22].m_vValue.toDouble();//横向电机余程 左侧
		g->mf_LV_MotorDistToGo = adviseResult[23].m_vValue.toDouble();//垂向电机余程 左侧
		g->mf_RH_MotorDistToGo = adviseResult[24].m_vValue.toDouble();//横向电机余程 右侧
		g->mf_RV_MotorDistToGo = adviseResult[25].m_vValue.toDouble();//垂向电机余程 右侧

		qint16 T_L_Temparature = adviseResult[26].m_vValue.toInt();
		qint16 T_R_Temparature = adviseResult[27].m_vValue.toInt();
		g->mf_L_Temparature = T_L_Temparature;//温度 左侧
		g->mf_R_Temparature = T_R_Temparature;//温度 右侧

		g->mf_L_Temparature = g->mf_L_Temparature/100;
		g->mf_R_Temparature = g->mf_R_Temparature/100;

		LH_SensorCurValue1 = LH_SensorCurValue1 < 0 ? 0 : LH_SensorCurValue1;
		LH_SensorCurValue2 = LH_SensorCurValue2 < 0 ? 0 : LH_SensorCurValue2;
		LV_SensorCurValue1 = LV_SensorCurValue1 < 0 ? 0 : LV_SensorCurValue1;
		LV_SensorCurValue2 = LV_SensorCurValue2 < 0 ? 0 : LV_SensorCurValue2;
		RH_SensorCurValue1 = RH_SensorCurValue1 < 0 ? 0 : RH_SensorCurValue1;
		RH_SensorCurValue2 = RH_SensorCurValue2 < 0 ? 0 : RH_SensorCurValue2;
		RV_SensorCurValue1 = RV_SensorCurValue1 < 0 ? 0 : RV_SensorCurValue1;
		RV_SensorCurValue2 = RV_SensorCurValue2 < 0 ? 0 : RV_SensorCurValue2;

		//模拟量满量程对应27648
		LH_SensorCurValue1 = LH_SensorCurValue1 > 27648 ? 27648 : LH_SensorCurValue1;
		LH_SensorCurValue2 = LH_SensorCurValue2 > 27648 ? 27648 : LH_SensorCurValue2;
		LV_SensorCurValue1 = LV_SensorCurValue1 > 27648 ? 27648 : LV_SensorCurValue1;
		LV_SensorCurValue2 = LV_SensorCurValue2 > 27648 ? 27648 : LV_SensorCurValue2;
		RH_SensorCurValue1 = RH_SensorCurValue1 > 27648 ? 27648 : RH_SensorCurValue1;
		RH_SensorCurValue2 = RH_SensorCurValue2 > 27648 ? 27648 : RH_SensorCurValue2;
		RV_SensorCurValue1 = RV_SensorCurValue1 > 27648 ? 27648 : RV_SensorCurValue1;
		RV_SensorCurValue2 = RV_SensorCurValue2 > 27648 ? 27648 : RV_SensorCurValue2;

		g->mf_LH_SensorCurValue1 = 25 + (double)LH_SensorCurValue1/27648*25;//横向传感器1 左侧
		g->mf_LH_SensorCurValue2 = 25 + (double)LH_SensorCurValue2/27648*25;//横向传感器2 左侧
		g->mf_LV_SensorCurValue1 = 25 + (double)LV_SensorCurValue1/27648*25;//垂向传感器1 左侧
		g->mf_LV_SensorCurValue2 = 25 + (double)LV_SensorCurValue2/27648*25;//垂向传感器2 左侧
		g->mf_RH_SensorCurValue1 = 25 + (double)RH_SensorCurValue1/27648*25;//横向传感器1 右侧
		g->mf_RH_SensorCurValue2 = 25 + (double)RH_SensorCurValue2/27648*25;//横向传感器2 右侧
		g->mf_RV_SensorCurValue1 = 25 + (double)RV_SensorCurValue1/27648*25;//垂向传感器1 右侧
		g->mf_RV_SensorCurValue2 = 25 + (double)RV_SensorCurValue2/27648*25;//垂向传感器2 右侧

		int Temp_H,Temp_L;
		Temp_L = L_HydraulicTransmitter & 0X00FF;
		Temp_H = (L_HydraulicTransmitter >> 8) & 0X00FF;
		L_HydraulicTransmitter = Temp_H + (Temp_L << 8);
		
		Temp_L = R_HydraulicTransmitter & 0X00FF;
		Temp_H = (R_HydraulicTransmitter >> 8) & 0X00FF;
		R_HydraulicTransmitter = Temp_H + (Temp_L << 8);

		L_HydraulicTransmitter = L_HydraulicTransmitter < 1311 ? 1311 : L_HydraulicTransmitter;
		R_HydraulicTransmitter = R_HydraulicTransmitter < 1311 ? 1311 : R_HydraulicTransmitter;
		L_HydraulicTransmitter = L_HydraulicTransmitter > 6553 ? 6553 : L_HydraulicTransmitter;
		R_HydraulicTransmitter = R_HydraulicTransmitter > 6553 ? 6553 : R_HydraulicTransmitter;

		g->mf_L_HydraulicTransmitter = (double)(L_HydraulicTransmitter-1311)/(6553-1311)*250;//液压变送器 左侧
		g->mf_R_HydraulicTransmitter = (double)(R_HydraulicTransmitter-1311)/(6553-1311)*250;//液压变送器 右侧
	}
}

void TrainMillingdialog::readTPValues( )
{
	// get data from item table list
	QVector<QVariant> L_vntValues,R_vntValues;
	QStringList szItems = (QStringList() << "32" << "35" );	//------r32,r35------

	// read data
	long lAxisNumber = 3;
	long lDrvHandle = m_objSlQMd.getDrvHandle(lAxisNumber);
	long lRetVal	= m_objSlQMd.readDrvData(lDrvHandle, szItems, L_vntValues);
	
	if(lRetVal == 0){
		g->mf_L_Power = L_vntValues[0].toDouble();
		g->mf_L_Temparature = L_vntValues[1].toDouble();

		g->mf_L_Power = g->mf_L_Power < 0 ? 0 : g->mf_L_Power;
		g->mf_L_Power = g->mf_L_Power/TOTAL_SPINDLE_POWER*100;
	}
	else{
		//Inner communication Error
		g->m_bPcuCommState = false;
	}

	// read data
	lAxisNumber = 6;
	lDrvHandle = m_objSlQMd.getDrvHandle(lAxisNumber);
	lRetVal	= m_objSlQMd.readDrvData(lDrvHandle, szItems, R_vntValues);

	if(lRetVal == 0){
		g->mf_R_Power = R_vntValues[0].toDouble();
		g->mf_R_Temparature = R_vntValues[1].toDouble();

		g->mf_R_Power = g->mf_R_Power < 0 ? 0 : g->mf_R_Power;
		g->mf_R_Power = g->mf_R_Power/TOTAL_SPINDLE_POWER*100;
	}
	else{
		//Inner communication Error
		g->m_bPcuCommState = false;
	}
}

void TrainMillingdialog::PLCShineStateProc( )//ligy 20190928 add
{
	if ( 0 != g_pStatusForm )
		g_pStatusForm->RefreshShineState_PLC( false );
}
void TrainMillingdialog::PLCWorkStateProc( )
{
	SlQCap nWriteServer;
	SlCapErrorEnum eError;

	if ( 0 != g_pStatusForm )
		g_pStatusForm->RefreshWorkState( false );

	if(g->m_nPLCWorkState == PLC_WORKSTATE_EMERGENCY ){
		if( g->m_nWorkState != WORKSTATE_NULL )
			g->SetPCUWorkState(WORKSTATE_EMERGENCY_PLC);
	}

	if(g->m_nPLCWorkState != g->m_nPrePLCWorkState)
	{
		switch(g->m_nPrePLCWorkState)
		{
		case PLC_WORKSTATE_WAITING:
			break;
		case PLC_WORKSTATE_READY:
			break;
		case PLC_WORKSTATE_SCAN:
			eError = nWriteServer.write(szItem_ScanSave_Bit,QVariant(false));
			break;
		case PLC_WORKSTATE_LOADDOWN1:
			break;
		case PLC_WORKSTATE_STARTTRAIN1:
			break;
		case PLC_WORKSTATE_STARTTRAIN2:
			break;
		case PLC_WORKSTATE_STARTWORK:
			break;
		case PLC_WORKSTATE_STOPWORK:
			break;
		case PLC_WORKSTATE_STOPTRAIN:
			break;
		case PLC_WORKSTATE_LOADDOWN2:
			break;
		case PLC_WORKSTATE_DEVICEUP:
			break;
		case PLC_WORKSTATE_EMERGENCY:
			//eError = nWriteServer.write(szItem_PCUEmergencyStop_Bit,QVariant(false));
			break;
		case PLC_WORKSTATE_REPAIR:
			break;
		default:
			break;
		}
	}
}

void TrainMillingdialog::StartRecordData( )
{
	QDateTime current_datetime = QDateTime::currentDateTime();
	QString sDateTime=current_datetime.toString("yyyy-MM-dd hh-mm-ss");
	QString fileRecordPath = "..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\log\\log"+sDateTime+".csv";
	m_fileRecord.setFileName(fileRecordPath);
	if(!m_fileRecord.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
	{
		//qDebug()<<"OPEN FILE FAILED";  
	}
	m_StreamRecord.setDevice(&m_fileRecord);
}

void TrainMillingdialog::StopRecordData( )
{
	m_fileRecord.close();
}

void TrainMillingdialog::FreshMillingControlSlot(SlCapErrorEnum eError, const QVector<SlCapAdviseResultType>& adviseResult)
{
	if(SL_SUCCEEDED(eError))
	{
		QDateTime current_datetime = QDateTime::currentDateTime();
		QString current_date=current_datetime.toString("yyyy-MM-dd hh-mm-ss");

		g->m_bCurStartTrain = adviseResult[0].m_vValue.toBool();   //列车启动标志
		g->m_bCurStartWork = adviseResult[1].m_vValue.toBool();    //作业启动标志
		g->m_bCurStopWork = adviseResult[2].m_vValue.toBool();     //作业停止标志
		g->m_bCurStopTrain = adviseResult[3].m_vValue.toBool();    //列车停止标志
		g->m_bCurStartScan = adviseResult[4].m_vValue.toBool();    //扫描启停标志
		int nPLCWorkState = adviseResult[5].m_vValue.toInt();      //NCU作业状态字
		g->m_bCurAlarmStopWork = adviseResult[6].m_vValue.toBool();//报警停止标志
		int nPLCShineState = adviseResult[7].m_vValue.toInt();      //打磨状态字

		if(nPLCWorkState != g->m_nPLCWorkState){
			g->SetPLCWorkState(nPLCWorkState);
			PLCWorkStateProc( );
		}
		if (nPLCShineState != g->m_nPLCShineState)//ligy 20190928 add
		{
			g->SetPLCShineState(nPLCShineState);
			PLCShineStateProc();	//打磨状态处理	
		}

		if( !g->m_bPreStartTrain && g->m_bCurStartTrain){
			m_StreamRecord << current_date <<"," << "Start Training........." <<endl;
			m_StreamRecord.flush();
				
			g->StartTrainProc( );//ligy 20190905 add。启动列车处理函数
		}
		if( !g->m_bPreStartWork && g->m_bCurStartWork){
			m_StreamRecord << current_date <<"," << "Start Working........." <<endl;
			m_StreamRecord.flush();

			int RetVal = g->StartWorkProc( );// start work

			if( RetVal == RET_TRAINSPDNOTREACH )
				ShowInformation(g_pIni->m_strTrainSpdNotReach);//列车速度没有达到设定值
			else if(RetVal == RET_AXISSPDNOTREACH )
				ShowInformation(g_pIni->m_strAxisSpdNotReach); //主轴转速没有达到设定值
		}
		if( !g->m_bPreStopWork && g->m_bCurStopWork){
			m_StreamRecord << current_date <<"," << "Stop Working........." <<endl;
			m_StreamRecord.flush();

			g->StopWorkProc( );
		}
		if( !g->m_bPreAlarmStopWork && g->m_bCurAlarmStopWork){
			m_StreamRecord << current_date <<"," << "Alarm Stop Working........." <<endl;
			m_StreamRecord.flush();

			g->AlarmStopWorkProc( );
		}
		if( !g->m_bPreStopTrain && g->m_bCurStopTrain){
			m_StreamRecord << current_date <<"," << "Stop Training........." <<endl;
			m_StreamRecord.flush();

			g->StopTrainProc( );
			g_pIni->SaveMileageParameters( );
		}
		if( !g->m_bPreStartScan && g->m_bCurStartScan ){
			m_StreamRecord << current_date <<"," << "Start Scanning........." <<endl;
			m_StreamRecord.flush();

			StartScan( );//开始扫描
		}
		if( g->m_bPreStartScan && !g->m_bCurStartScan ){
			m_StreamRecord << current_date <<"," << "Stop Scanning........." <<endl;
			m_StreamRecord.flush();

			StopScan( );//停止扫描
		}

		g->m_bPreStartTrain = g->m_bCurStartTrain;
		g->m_bPreStartWork = g->m_bCurStartWork;
		g->m_bPreStopWork = g->m_bCurStopWork;
		g->m_bPreStopTrain = g->m_bCurStopTrain;
		g->m_bPreStartScan = g->m_bCurStartScan;
		g->m_bPreAlarmStopWork = g->m_bCurAlarmStopWork;
	}
}


void TrainMillingdialog::FreshStatusSlot(SlCapErrorEnum eError, const QVector<SlCapAdviseResultType>& adviseResult)
{
	if(SL_SUCCEEDED(eError))
	{
		/*-------this part of content is placed in IOList------------------
		g->m_LH_bSensorStatus1 = adviseResult[0].m_vValue.toBool();
		g->m_LV_bSensorStatus1 = adviseResult[1].m_vValue.toBool();
		g->m_RH_bSensorStatus1 = adviseResult[2].m_vValue.toBool();
		g->m_RV_bSensorStatus1 = adviseResult[3].m_vValue.toBool();
		g->m_LH_bSensorStatus2 = adviseResult[4].m_vValue.toBool();
		g->m_LV_bSensorStatus2 = adviseResult[5].m_vValue.toBool();
		g->m_RH_bSensorStatus2 = adviseResult[6].m_vValue.toBool();
		g->m_RV_bSensorStatus2 = adviseResult[7].m_vValue.toBool();
		*/
		g->m_bLockState0 = adviseResult[0].m_vValue.toBool();//装置锁定标志
		g->m_bLockState1 = adviseResult[1].m_vValue.toBool();//装置解锁标志
		g->m_bCH1NCState = adviseResult[2].m_vValue.toBool();//通道1NC状态
		g->m_bCH2NCState = adviseResult[3].m_vValue.toBool();//通道2NC状态
		g->m_bIsRepairOver = !(adviseResult[4].m_vValue.toBool());//检修模式退出允许标志
		g->m_L_bCollectorBinState = adviseResult[5].m_vValue.toBool();//左集屑仓状态
		g->m_R_bCollectorBinState = adviseResult[6].m_vValue.toBool();//右集屑仓状态
		g->m_bBogyState = adviseResult[7].m_vValue.toBool();//刚性支撑标志
	}
}

void TrainMillingdialog::FreshIOListSlot(SlCapErrorEnum eError, const QVector<SlCapAdviseResultType>& adviseResult)
{
	if(SL_SUCCEEDED(eError))
	{
		int IOBitCount = IOBITCOUNT;				
		for(int i=0 ; i<IOBitCount ; i++){
			g->m_CurIOSignals[i] =  adviseResult[i].m_vValue.toBool();
		}
		g->m_L_bHighSignal = g->m_CurIOSignals[78];			//("I41.6"));			//LHigh 左侧Z轴液压上极限开关
		g->m_R_bHighSignal = g->m_CurIOSignals[105];		//("I45.1"));			//RHigh 右侧Z轴液压上极限开关

		g->m_bCurTrainSpeedMinus =g->m_CurIOSignals[170];	//("I64.2"));			//V-0.1
		g->m_bCurTrainSpeedPlus = g->m_CurIOSignals[171];	//("I64.3"));			//V+0.1

		g->m_LH_CBCurSignal1 = g->m_CurIOSignals[172];		//("I64.4"));			//Y1-
		g->m_LH_CBCurSignal2 = g->m_CurIOSignals[173];		//("I64.5"));			//Y1+
		g->m_LV_CBCurSignal1 = g->m_CurIOSignals[174];		//("I64.6"));			//Z1-
		g->m_LV_CBCurSignal2 = g->m_CurIOSignals[175];		//("I64.7"));			//Z1+
		g->m_RH_CBCurSignal1 = g->m_CurIOSignals[180];		//("I65.4"));			//Y2-
		g->m_RH_CBCurSignal2 = g->m_CurIOSignals[181];		//("I65.5"));			//Y2+
		g->m_RV_CBCurSignal1 = g->m_CurIOSignals[182];		//("I65.6"));			//Z2-
		g->m_RV_CBCurSignal2 = g->m_CurIOSignals[183];		//("I65.7"));			//Z2+

		//--------------------------------------------------------------------------//
		//----------------import IOSignals to ErrSignals
		g_pErr->m_CurErrSignals[8]  = g->m_CurIOSignals[0];			//I32.0
		g_pErr->m_CurErrSignals[9]  = g->m_CurIOSignals[1];			//I32.1
		g_pErr->m_CurErrSignals[10] = g->m_CurIOSignals[2];			//I32.2
		g_pErr->m_CurErrSignals[11] = g->m_CurIOSignals[3];			//I32.3
		g_pErr->m_CurErrSignals[12] = g->m_CurIOSignals[4];			//I32.4
		g_pErr->m_CurErrSignals[13] = g->m_CurIOSignals[5];			//I32.5
		g_pErr->m_CurErrSignals[14] = g->m_CurIOSignals[6];			//I32.6
		g_pErr->m_CurErrSignals[15] = g->m_CurIOSignals[7];			//I32.7

		g_pErr->m_CurErrSignals[16] = g->m_CurIOSignals[8];			//I33.0
		g_pErr->m_CurErrSignals[17] = g->m_CurIOSignals[9];			//I33.1
		g_pErr->m_CurErrSignals[18] = g->m_CurIOSignals[10];		//I33.2
		g_pErr->m_CurErrSignals[19] = g->m_CurIOSignals[11];		//I33.3
		g_pErr->m_CurErrSignals[20] = g->m_CurIOSignals[12];		//I33.4
		g_pErr->m_CurErrSignals[21] = g->m_CurIOSignals[13];		//I33.5
		g_pErr->m_CurErrSignals[22] = g->m_CurIOSignals[14];		//I33.6
		g_pErr->m_CurErrSignals[23] = g->m_CurIOSignals[15];		//I33.7
	
		g_pErr->m_CurErrSignals[24] = g->m_CurIOSignals[16];		//I34.0
		g_pErr->m_CurErrSignals[25] = g->m_CurIOSignals[17];		//I34.1
		g_pErr->m_CurErrSignals[26] = g->m_CurIOSignals[18];		//I34.2
		g_pErr->m_CurErrSignals[27] = g->m_CurIOSignals[19];		//I34.3
		g_pErr->m_CurErrSignals[28] = g->m_CurIOSignals[20];		//I34.4
		g_pErr->m_CurErrSignals[29] = g->m_CurIOSignals[21];		//I34.5
		g_pErr->m_CurErrSignals[30] = g->m_CurIOSignals[23];		//I34.7
		g_pErr->m_CurErrSignals[31] = g->m_CurIOSignals[28];		//I35.4

		g_pErr->m_CurErrSignals[32] = g->m_CurIOSignals[29];		//I35.5
		g_pErr->m_CurErrSignals[33] = g->m_CurIOSignals[30];		//I35.6
		g_pErr->m_CurErrSignals[34] = g->m_CurIOSignals[37];		//I36.5
		g_pErr->m_CurErrSignals[35] = g->m_CurIOSignals[38];		//I36.6
		g_pErr->m_CurErrSignals[36] = g->m_CurIOSignals[39];		//I36.7
		g_pErr->m_CurErrSignals[37] = g->m_CurIOSignals[40];		//I37.0
		g_pErr->m_CurErrSignals[38] = g->m_CurIOSignals[50];		//I38.2
		g_pErr->m_CurErrSignals[39] = g->m_CurIOSignals[51];		//I38.3

		g_pErr->m_CurErrSignals[40] = g->m_CurIOSignals[52];		//I38.4
		g_pErr->m_CurErrSignals[41] = g->m_CurIOSignals[53];		//I38.5
		g_pErr->m_CurErrSignals[42] = g->m_CurIOSignals[54];		//I38.6
		g_pErr->m_CurErrSignals[43] = g->m_CurIOSignals[55];		//I38.7
		g_pErr->m_CurErrSignals[44] = g->m_CurIOSignals[83];		//I42.3
		g_pErr->m_CurErrSignals[45] = g->m_CurIOSignals[110];		//I45.6
		g_pErr->m_CurErrSignals[46] = g->m_CurIOSignals[115];		//I46.3
		g_pErr->m_CurErrSignals[47] = g->m_CurIOSignals[133];		//I48.5

		g_pErr->m_CurErrSignals[48] = g->m_CurIOSignals[141];		//I49.5
		g_pErr->m_CurErrSignals[49] = g->m_CurIOSignals[142];		//I49.6
		g_pErr->m_CurErrSignals[50] = g->m_CurIOSignals[143];		//I49.7
		g_pErr->m_CurErrSignals[51] = g->m_CurIOSignals[144];		//I50.0
		g_pErr->m_CurErrSignals[52] = g->m_CurIOSignals[145];		//I50.1
		g_pErr->m_CurErrSignals[53] = g->m_CurIOSignals[146];		//I50.2
		g_pErr->m_CurErrSignals[54] = g->m_CurIOSignals[147];		//I50.3
		g_pErr->m_CurErrSignals[55] = g->m_CurIOSignals[148];		//I50.4

		g_pErr->m_CurErrSignals[56] = g->m_CurIOSignals[149];		//I50.5
		g_pErr->m_CurErrSignals[57] = g->m_CurIOSignals[35];		//I36.3
		g_pErr->m_CurErrSignals[58] = g->m_CurIOSignals[41];		//I37.1
		g_pErr->m_CurErrSignals[59] = g->m_CurIOSignals[42];		//I37.2
		g_pErr->m_CurErrSignals[60] = g->m_CurIOSignals[56];		//I39.0
		g_pErr->m_CurErrSignals[61] = g->m_CurIOSignals[57];		//I39.1
		g_pErr->m_CurErrSignals[62] = g->m_CurIOSignals[59];		//I39.3
		g_pErr->m_CurErrSignals[63] = g->m_CurIOSignals[60];		//I39.4

		g_pErr->m_CurErrSignals[64] = g->m_CurIOSignals[66];		//I40.2
		g_pErr->m_CurErrSignals[65] = g->m_CurIOSignals[67];		//I40.3
		g_pErr->m_CurErrSignals[66] = g->m_CurIOSignals[35];		//I36.3

		//End of Import IOSignals to ErrSignals
		//--------------------------------------------------------------------------//

		//--------------------------------------------------------------------------//
		//Import Sensor Status Signals
		g->m_LH_bSensorStatus1 = g->m_CurIOSignals[142];	//I49.6  左侧测距仪Y1故障
		g->m_LV_bSensorStatus1 = g->m_CurIOSignals[144];	//I50.0  左侧测距仪Z1故障
		g->m_RH_bSensorStatus1 = g->m_CurIOSignals[146];	//I50.2  右侧测距仪Y3故障
		g->m_RV_bSensorStatus1 = g->m_CurIOSignals[148];	//I50.4  右侧测距仪Z3故障
		g->m_LH_bSensorStatus2 = g->m_CurIOSignals[143];	//I49.7  左侧测距仪Y2故障
		g->m_LV_bSensorStatus2 = g->m_CurIOSignals[145];	//I50.1  左侧测距仪Z2故障
		g->m_RH_bSensorStatus2 = g->m_CurIOSignals[147];	//I50.3  右侧测距仪Y4故障
		g->m_RV_bSensorStatus2 = g->m_CurIOSignals[149];	//I50.5  右侧测距仪Z4故障
		//End of Import Sensor Status Signals

		//Import PressShoe Signals
		g->m_L_bPressShoeStatus = g->m_CurIOSignals[82];	//I42.2  左侧压靴落轨检测
		g->m_R_bPressShoeStatus = g->m_CurIOSignals[109];	//I45.5  右侧压靴落轨检测
		//--------------------------------------------------------------------------//

		//-----------------------ligy 20200214 add 添加操作日志----------------------//
        g->m_bCurStartTrainSign = g->m_CurIOSignals[176];          //启动列车标志  I65.0
        g->m_bCurStopTrainSign  = g->m_CurIOSignals[177];;         //停止列车标志  I65.1
        g->m_bCurStartWorkSign  = g->m_CurIOSignals[178];;         //开始作业标志  I65.2
        g->m_bCurStopWorkSign   = g->m_CurIOSignals[179];;         //停止作业标志  I65.3
        g->m_bCurDeviceUpSign   = g->m_CurIOSignals[168];;         //装置上升标志  I64.0
        g->m_bCurDeviceDownSign = g->m_CurIOSignals[169];;         //装置下降标志  I64.1
        g->m_bCurHydraulicStartSign = g->m_CurIOSignals[185];;     //液压启动标志  I66.1
        g->m_bCurHydraulicStopSign  = g->m_CurIOSignals[186];;     //液压停止标志  I66.2
        g->m_bCurChipStartSign  = g->m_CurIOSignals[188];;         //集屑启动标志  I66.4
        g->m_bCurChipStopSign   = g->m_CurIOSignals[189];;         //集屑停止标志  I66.5
        g->m_bCurSpeedWheelUpSign   = g->m_CurIOSignals[190];;     //测速轮上升标志 I66.6
        g->m_bCurSpeedWheelDownSign = g->m_CurIOSignals[191];;     //测速轮下降标志 I66.7
        g->m_bCurBodySupportSign    = g->m_CurIOSignals[192];;     //刚性支撑标志   I67.0
        g->m_bCurBodyReleaseSign    = g->m_CurIOSignals[193];;     //支撑解除标志   I67.1

		//1
		if (g->m_bPreStartTrainSign != g->m_bCurStartTrainSign)
		{
			if (g->m_bCurStartTrainSign)
			{
				if (g->m_bIsLogin)//ligy 20200214 add.添加日志 启动列车
				{
					g->m_StreamLog<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss")
						<<","<<g->m_strNowUserName
						<<","<< g_pIni->m_strLog_StartTrain <<endl;
					g->m_StreamLog.flush();//ligy 20200214 add.
				}	
			} 
		} 
		//2
		if (g->m_bPreStopTrainSign != g->m_bCurStopTrainSign)
		{
			if (g->m_bCurStopTrainSign)
			{
				if (g->m_bIsLogin)//ligy 20200214 add.添加日志 停止列车
				{
					g->m_StreamLog<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss")
						<<","<<g->m_strNowUserName
						<<","<< g_pIni->m_strLog_StopTrain <<endl;
					g->m_StreamLog.flush();//ligy 20200214 add.
				}	
			}
		}
		//3
		if (g->m_bPreStartWorkSign != g->m_bCurStartWorkSign)
		{
			if (g->m_bCurStartWorkSign)
			{
				if (g->m_bIsLogin)//ligy 20200214 add.添加日志 开始作业
				{
					g->m_StreamLog<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss")
						<<","<<g->m_strNowUserName
						<<","<< g_pIni->m_strLog_StartWork <<endl;
					g->m_StreamLog.flush();//ligy 20200214 add.
				}	
			}
		}
		
		//4
		if (g->m_bPreStopWorkSign != g->m_bCurStopWorkSign)
		{
			if (g->m_bCurStopWorkSign)
			{
				if (g->m_bIsLogin)//ligy 20200214 add.添加日志 停止作业
				{
					g->m_StreamLog<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss")
						<<","<<g->m_strNowUserName
						<<","<< g_pIni->m_strLog_StopWork <<endl;
					g->m_StreamLog.flush();//ligy 20200214 add.
				}	
			}
		}

		//5
		if (g->m_bPreDeviceUpSign != g->m_bCurDeviceUpSign)
		{
			if (g->m_bCurDeviceUpSign)
			{
				if (g->m_bIsLogin)//ligy 20200214 add.添加日志 装置上升
				{
					g->m_StreamLog<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss")
						<<","<<g->m_strNowUserName
						<<","<< g_pIni->m_strLog_DeviceUp <<endl;
					g->m_StreamLog.flush();//ligy 20200214 add.
				}	
			}
		}

		//6
		if (g->m_bPreDeviceDownSign != g->m_bCurDeviceDownSign)
		{
			if (g->m_bCurDeviceDownSign)
			{
				if (g->m_bIsLogin)//ligy 20200214 add.添加日志 装置下降
				{
					g->m_StreamLog<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss")
						<<","<<g->m_strNowUserName
						<<","<< g_pIni->m_strLog_DeviceDown <<endl;
					g->m_StreamLog.flush();//ligy 20200214 add.
				}	
			}
		}

		//7
		if (g->m_bPreHydraulicStartSign != g->m_bCurHydraulicStartSign)
		{
			if (g->m_bCurHydraulicStartSign)
			{
				if (g->m_bIsLogin)//ligy 20200214 add.添加日志 液压上升
				{
					g->m_StreamLog<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss")
						<<","<<g->m_strNowUserName
						<<","<< g_pIni->m_strLog_HydraulicStart <<endl;
					g->m_StreamLog.flush();//ligy 20200214 add.
				}	
			}
		}

		//8
		if (g->m_bPreHydraulicStopSign != g->m_bCurHydraulicStopSign)
		{
			if (g->m_bCurHydraulicStopSign)
			{
				if (g->m_bIsLogin)//ligy 20200214 add.添加日志 液压停止
				{
					g->m_StreamLog<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss")
						<<","<<g->m_strNowUserName
						<<","<< g_pIni->m_strLog_HydraulicStart <<endl;
					g->m_StreamLog.flush();//ligy 20200214 add.
				}	
			}
		}
		//9
		if (g->m_bPreChipStartSign != g->m_bCurChipStartSign)
		{
			if (g->m_bCurChipStartSign)
			{
				if (g->m_bIsLogin)//ligy 20200214 add.添加日志 集屑启动
				{
					g->m_StreamLog<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss")
						<<","<<g->m_strNowUserName
						<<","<< g_pIni->m_strLog_ChipStart <<endl;
					g->m_StreamLog.flush();//ligy 20200214 add.
				}	
			}
		}
		//10
		if (g->m_bPreChipStopSign != g->m_bCurChipStopSign)
		{
			if (g->m_bCurChipStopSign)
			{
				if (g->m_bIsLogin)//ligy 20200214 add.添加日志 集屑停止
				{
					g->m_StreamLog<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss")
						<<","<<g->m_strNowUserName
						<<","<< g_pIni->m_strLog_ChipStop <<endl;
					g->m_StreamLog.flush();//ligy 20200214 add.
				}	
			}
		}

		//11
		if (g->m_bPreSpeedWheelUpSign != g->m_bCurSpeedWheelUpSign)
		{
			if (g->m_bCurSpeedWheelUpSign)
			{
				if (g->m_bIsLogin)//ligy 20200214 add.添加日志 测速轮上升
				{
					g->m_StreamLog<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss")
						<<","<<g->m_strNowUserName
						<<","<< g_pIni->m_strLog_SpeedWheelStart <<endl;
					g->m_StreamLog.flush();//ligy 20200214 add.
				}	
			}
		}

		//12
		if (g->m_bPreSpeedWheelDownSign != g->m_bCurSpeedWheelDownSign)
		{
			if (g->m_bCurSpeedWheelDownSign)
			{
				if (g->m_bIsLogin)//ligy 20200214 add.添加日志 测速轮下降
				{
					g->m_StreamLog<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss")
						<<","<<g->m_strNowUserName
						<<","<< g_pIni->m_strLog_SpeedWheelStop <<endl;
					g->m_StreamLog.flush();//ligy 20200214 add.
				}	
			}
		}

		//13
		if (g->m_bPreBodySupportSign != g->m_bCurBodySupportSign)
		{
			if (g->m_bCurBodySupportSign)
			{
				if (g->m_bIsLogin)//ligy 20200214 add.添加日志 刚性支撑
				{
					g->m_StreamLog<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss")
						<<","<<g->m_strNowUserName
						<<","<< g_pIni->m_strLog_BodyStart <<endl;
					g->m_StreamLog.flush();//ligy 20200214 add.
				}	
			}
		}

		//14
		if (g->m_bPreBodyReleaseSign != g->m_bCurBodyReleaseSign)
		{
			if (g->m_bCurBodyReleaseSign)
			{
				if (g->m_bIsLogin)//ligy 20200214 add.添加日志 支撑解除
				{
					g->m_StreamLog<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss")
						<<","<<g->m_strNowUserName
						<<","<< g_pIni->m_strLog_BodyStop <<endl;
					g->m_StreamLog.flush();//ligy 20200214 add.
				}	
			}
		}

		g->m_bPreStartTrainSign = g->m_bCurStartTrainSign;
		g->m_bPreStopTrainSign = g->m_bCurStopTrainSign;
		g->m_bPreStartWorkSign = g->m_bCurStartWorkSign;
		g->m_bPreStopWorkSign = g->m_bCurStopWorkSign;
		g->m_bPreDeviceUpSign = g->m_bCurDeviceUpSign;
		g->m_bPreDeviceDownSign = g->m_bCurDeviceDownSign;
		g->m_bPreHydraulicStartSign = g->m_bCurHydraulicStartSign;
		g->m_bPreHydraulicStopSign = g->m_bCurHydraulicStopSign;
		g->m_bPreChipStartSign = g->m_bCurChipStartSign;
		g->m_bPreChipStopSign = g->m_bCurChipStopSign;
		g->m_bPreSpeedWheelUpSign = g->m_bCurSpeedWheelUpSign;
		g->m_bPreSpeedWheelDownSign = g->m_bCurSpeedWheelDownSign;
		g->m_bPreBodySupportSign = g->m_bCurBodySupportSign;
		g->m_bPreBodyReleaseSign = g->m_bCurBodyReleaseSign;


		if ( 0 != g_pErr )
		{
			g_pErr->createPLCAlarms( );
			g_pErr->processPLCAlarms( );
			//memcpy(g_pErr->m_PreErrSignals,g_pErr->m_CurErrSignals,sizeof(g_pErr->m_CurErrSignals));
			for(int k=MEERBITCOUNT ; k<ERRBITCOUNT ; k++)
				g_pErr->m_PreErrSignals[k] = g_pErr->m_CurErrSignals[k];
		}
		//----End of ErrSignals Procecss

		if(m_bIsTrainSpeedIni == true){
			m_bIsTrainSpeedIni = false;
			TrainSpeedBtnProcIni( );
		}
		else
			TrainSpeedBtnProc( );

		/*
		if ( 0 != g_pStatusListForm )
			g_pStatusListForm->UpdateIOItems( );
		if ( 0 != g_pStatusForm )
			g_pStatusForm->RefreshState();
		*/
	}
}

void TrainMillingdialog::FreshErrListSlot(SlCapErrorEnum eError, const QVector<SlCapAdviseResultType>& adviseResult)
{
	if(SL_SUCCEEDED(eError))
	{
		int ErrBitCount = MEERBITCOUNT;				
		for(int i=0 ; i<ErrBitCount ; i++){
			g_pErr->m_CurErrSignals[i] =  adviseResult[i].m_vValue.toBool();
		}
		if ( 0 != g_pErr )
		{
			g_pErr->createPLCAlarms( );
			g_pErr->processPLCAlarms( );
			//memcpy(g_pErr->m_PreErrSignals,g_pErr->m_CurErrSignals,sizeof(g_pErr->m_CurErrSignals));
			for(int k=0 ; k<MEERBITCOUNT ; k++)
				g_pErr->m_PreErrSignals[k] = g_pErr->m_CurErrSignals[k];
		}
	}
}

void TrainMillingdialog::TrainSpeedBtnProcIni( )
{
	g->m_bPreTrainSpeedMinus = g->m_bCurTrainSpeedMinus;
	g->m_bPreTrainSpeedPlus = g->m_bCurTrainSpeedPlus;
}

void TrainMillingdialog::TrainSpeedBtnProc( )
{
	bool isSpeedChange = false;
	if( !g->IsWorkingState() ){
		if(g->m_bCurTrainSpeedMinus && !g->m_bPreTrainSpeedMinus){
			isSpeedChange = true;
			g->m_DstTrainSpeed -= 0.1;
			if(g->m_DstTrainSpeed < 0.1)
				g->m_DstTrainSpeed = 0.1;
		}
		if(g->m_bCurTrainSpeedPlus && !g->m_bPreTrainSpeedPlus){
			isSpeedChange = true;
			g->m_DstTrainSpeed += 0.1;
			if(g->m_DstTrainSpeed > 2.0)
				g->m_DstTrainSpeed = 2.0;
		}
	}
	if( isSpeedChange ){
		if( 0 != g_pParameterForm )
			g_pParameterForm->RefreshWorkingParameters( );
		//g_pIni->SaveWorkParameters( );

		//!!!important:Send Speed To TCU
		//Send Speed to Tcu
		//g->TcuSetTrainSpeedProc( g->m_DstTrainSpeed );
	}
	g->m_bPreTrainSpeedMinus = g->m_bCurTrainSpeedMinus;
	g->m_bPreTrainSpeedPlus = g->m_bCurTrainSpeedPlus;
}


void TrainMillingdialog::WriteWorkingParametersToCNC()
{
	QVector<SlCapWriteSpecType>	vecWriteSpec;
	SlQCap						ncapServer;

	bool LV_CutDepth_Flag = g->m_LV_CutDepth >= 1 ? true : false;
	bool RV_CutDepth_Flag = g->m_RV_CutDepth >= 1 ? true : false;

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
	SlCapErrorEnum eError = ncapServer.multiWrite(vecWriteSpec, &vecWriteResult);

	// write success or error to the status bar
	handleRetVal(eError);

	//Send Speed to Tcu
	//g->TcuSetTrainSpeedProc( g->m_DstTrainSpeed );

	return;
}

void TrainMillingdialog::StartScan( )
{
	//Force To Write Working Parameters To CNC
	//WriteWorkingParametersToCNC();
	if(m_bIsScanning == false){
		m_bIsScanning = true;
		g->m_L_ScanDataX.clear();
		g->m_L_ScanDataY.clear();
		g->m_R_ScanDataX.clear();
		g->m_R_ScanDataY.clear();
		g->m_ScannerChoose = ScannerChoose::Left;
		m_tmrScan.start();//启动扫描定时器
	}

	if ( 0 != g_pScanForm && m_bIsScanning ){
		g_pScanForm->setSoftkeyDisable(7, true);
		g_pScanForm->PlotDrawing( );
	}
}

void TrainMillingdialog::StopScan( )
{
	if(m_bIsScanning == true){
		m_bIsScanning = false;
		m_bIsNewScanData = true;
		if(m_tmrScan.isActive())
			m_tmrScan.stop();

		g->SortedScanData( );
		g->SaveScanData( );
		if ( 0 != g_pScanForm ){
			//g_pScanForm->setSoftkeyDisable(7, false);
			g_pScanForm->PlotDrawing( );
			g_pScanForm->setSaveKeyState( );
		}
	}
}

void TrainMillingdialog::ScanTimeoutSlot( )//outline scan timer
{
	SlQCap nMultiRead;
	QVector<SlCapReadSpecType> nRsArray;
	QVector<SlCapReadResultType> nRsValue;
	nRsArray.append(SlCapReadSpecType(szItem_LH_MotorPos));		//左侧横向电机位置						
	nRsArray.append(SlCapReadSpecType(szItem_RH_MotorPos));		//右侧横向电机位置					

	nRsArray.append(SlCapReadSpecType(szItem_L_Scan));			//扫描头1 左侧激光扫描测距仪
	nRsArray.append(SlCapReadSpecType(szItem_R_Scan));		    //扫描头2 右侧激光扫描测距仪
	SlCapErrorEnum nError = nMultiRead.multiRead(nRsArray,nRsValue);
	if(SL_SUCCEEDED(nError))
	{
		double X1 = nRsValue[0].m_vValue.toDouble();
		double X2 = nRsValue[1].m_vValue.toDouble();

		int scan1 = nRsValue[2].m_vValue.toInt();
		int scan2 = nRsValue[3].m_vValue.toInt();

		//scan1高、低8位互换位置（0xAABB->0xBBAA）
		int Temp_H,Temp_L;
		Temp_L = scan1 & 0X00FF;
		Temp_H = (scan1 >> 8) & 0X00FF;
		scan1 = Temp_H + (Temp_L << 8);
		
		Temp_L = scan2 & 0X00FF;
		Temp_H = (scan2 >> 8) & 0X00FF;
		scan2 = Temp_H + (Temp_L << 8);

		scan1 = scan1 < 0 ? 0 : scan1;
		scan1 = scan1 > 6581 ? 6581 : scan1;
		scan2 = scan2 < 0 ? 0 : scan2;
		scan2 = scan2 > 6581 ? 6581 : scan2;

		double Y1 = 50 + (double)scan1/6581 * 300;
		double Y2 = 50 + (double)scan2/6581 * 300;

		Y1 = 350 - Y1;
		Y2 = 350 - Y2;

		g->m_L_ScanDataX.append(X1);
		g->m_L_ScanDataY.append(Y1); 
		g->m_R_ScanDataX.append(X2);
		g->m_R_ScanDataY.append(Y2); 
	}
}

bool TrainMillingdialog::deleteDirectoryFiles(QString srcDir)
{
	QDir sourceDir(srcDir);
	QDateTime nowDatetime = QDateTime::currentDateTime();
	QDateTime borderDatetime = nowDatetime.addDays(-90);

	QFileInfoList fileInfoList = sourceDir.entryInfoList();
	foreach(QFileInfo fileInfo,fileInfoList)
	{
		if(fileInfo.fileName()=="."||fileInfo.fileName()=="..")
			continue;
		if(fileInfo.isDir())
		{
			if( !deleteDirectoryFiles( fileInfo.filePath() ) )
				return false;
			//QDir dirTemp(fileInfo.filePath());
			//dirTemp.rmdir(".");
		}
		else
		{
			QDateTime createDatetime = fileInfo.created();
			//QString cDateTime=createDatetime.toString("yyyy-MM-dd hh-mm-ss");
			//QString dDateTime=borderDatetime.toString("yyyy-MM-dd hh-mm-ss");
			if(createDatetime < borderDatetime) 
			{
				if(!QFile::remove(fileInfo.filePath()))
					return false;
			}
		}	
	}

	return true;
}
