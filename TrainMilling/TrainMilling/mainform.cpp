///////////////////////////////////////////////////////////////////////////////
/*! \file   mainform.cpp
 *  \author
 *  \date
 *  \brief  Implementation file for class MainForm
 *
 *  This file is part of the HMI Solutionline.
 *
 */
///////////////////////////////////////////////////////////////////////////////
#include "mainform.h"
#include "QTextCodec.h"
#include "QSettings.h"
#include "QDateTime.h"
#include "GlobalVar.h"


///////////////////////////////////////////////////////////////////////////////
// CREATORS
///////////////////////////////////////////////////////////////////////////////

MainForm::MainForm(QWidget* pParent, const QString& rszName)
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

	//Set The UserNameLineEdit UserName,and the name is only readable
	UserNameLineEdit->setValue(g_pIni->m_strUserName);

	//创建tcp服务器 ligy 20190903 add
	if (!TcpServerInit())
	{
		setStatusBarElementText("tcp server create failed!",0);
		m_bStartTcp = false;
	}
	else
	{
		m_bStartTcp = true;
	}

} // <-- MainForm::MainForm ()

MainForm::~MainForm (void)
{
	TcpServerClose();//关闭tcp服务器 ligy 20190903 add

} // <-- MainForm::~MainForm ()

///////////////////////////////////////////////////////////////////////////////
// MANIPULATORS - system overrides
///////////////////////////////////////////////////////////////////////////////
void MainForm::attachedToScreen(const QString& rszScreenName)
{
	
	//Start Timer
	m_tmrToggle.setSingleShot(false);
	m_tmrToggle.setInterval(1000);
	// signal/slot connection for QTimer
	QObject::connect( &m_tmrToggle,SIGNAL(timeout()),this,SLOT(TimeoutSlot()) );
	QObject::connect(this,SIGNAL(emitShowSendData()),dialog()->formRef("StatusForm"),SLOT(ShowSendData()));	
	// start timer
	//m_tmrToggle.start();

	if(g->m_bIsLogin){
		// disable/enable softkeys	
		UserNameLineEdit->setDisabled(true);
		PasswordLineEdit->setDisabled(true);

		//setVSoftkeyDisable(6, g->m_bIsLogin);
		//setVSoftkeyDisable(7, !g->m_bIsLogin);
		setVSoftkeyDisable(6, g->m_bIsLogin || (g->m_nPLCWorkState > PLC_WORKSTATE_READY && g->m_nPLCWorkState < PLC_WORKSTATE_REPAIR) || !g->m_bIsCertified);
		setVSoftkeyDisable(7, !g->m_bIsLogin || (g->m_nPLCWorkState > PLC_WORKSTATE_READY && g->m_nPLCWorkState < PLC_WORKSTATE_REPAIR) || !g->m_bIsCertified);
	}
	else{
		UserNameLineEdit->setDisabled(false);
		PasswordLineEdit->setDisabled(false);

		//setVSoftkeyDisable(6, g->m_bIsLogin);
		//setVSoftkeyDisable(7, !g->m_bIsLogin);
		setVSoftkeyDisable(6,  g->m_bIsLogin || (g->m_nPLCWorkState > PLC_WORKSTATE_READY && g->m_nPLCWorkState < PLC_WORKSTATE_REPAIR) || !g->m_bIsCertified);
		setVSoftkeyDisable(7, !g->m_bIsLogin || (g->m_nPLCWorkState > PLC_WORKSTATE_READY && g->m_nPLCWorkState < PLC_WORKSTATE_REPAIR) || !g->m_bIsCertified);
	}

	setHSoftkeyDisable(2, !g->m_bIsLogin);
	setHSoftkeyDisable(3, !g->m_bIsLogin);
	setHSoftkeyDisable(4, !g->m_bIsLogin);
	setHSoftkeyDisable(5, !g->m_bIsLogin);
	setHSoftkeyDisable(6, !g->m_bIsLogin);
	setHSoftkeyDisable(7, !g->m_bIsLogin);
	setHSoftkeyDisable(8, !g->m_bIsLogin);

	if(g->m_bIsLogin==true)
		setStatusBarElementText(g_pIni->m_strLogin, 1);
	else
		setStatusBarElementText(g_pIni->m_strNotLogin, 1);

	if(g->m_bIsCertified == true)
		showLoginUI();
	else
		hideLoginUI();

	g_pMainForm = this;
    // don't forget to call the standard implementation
    SlGfwDialogForm::attachedToScreen(rszScreenName);
}

void MainForm::setLoginOutKeyState( )
{
	setVSoftkeyDisable(6,  g->m_bIsLogin || (g->m_nPLCWorkState > PLC_WORKSTATE_READY && g->m_nPLCWorkState < PLC_WORKSTATE_REPAIR) || !g->m_bIsCertified);
	setVSoftkeyDisable(7, !g->m_bIsLogin || (g->m_nPLCWorkState > PLC_WORKSTATE_READY && g->m_nPLCWorkState < PLC_WORKSTATE_REPAIR) || !g->m_bIsCertified);
}

void MainForm::detachedFromScreen(const QString& rszScreenName)
{
	if(m_tmrToggle.isActive())
		m_tmrToggle.stop();

	g_pMainForm = 0;
    // don't forget to call the standard implementation
    SlGfwDialogForm::detachedFromScreen(rszScreenName);
}

void MainForm::Login()
{
	SlQCap nWriteServer;
	SlCapErrorEnum nError;
	if(g->m_bIsLogin == false){
		if( UserNameLineEdit->value().toString() != g_pIni->m_strUserName ){
			setStatusBarElementText(g_pIni->m_strNameError, 1);
		}
		else if( PasswordLineEdit->value().toString() != g_pIni->m_strPassword ){
			setStatusBarElementText(g_pIni->m_strPwdError, 1);
		}
		else{
			g->m_bIsLogin = true;
			g->m_strNowUserName = UserNameLineEdit->value().toString();
			setStatusBarElementText(g_pIni->m_strLogin, 1);

			PasswordLineEdit->clear();
			UserNameLineEdit->setDisabled(true);
			PasswordLineEdit->setDisabled(true);

			//setVSoftkeyDisable(6, g->m_bIsLogin);
			//setVSoftkeyDisable(7, !g->m_bIsLogin);
			setVSoftkeyDisable(6,  g->m_bIsLogin || (g->m_nPLCWorkState > PLC_WORKSTATE_READY && g->m_nPLCWorkState < PLC_WORKSTATE_REPAIR) || !g->m_bIsCertified);
			setVSoftkeyDisable(7, !g->m_bIsLogin || (g->m_nPLCWorkState > PLC_WORKSTATE_READY && g->m_nPLCWorkState < PLC_WORKSTATE_REPAIR) || !g->m_bIsCertified);

			/*
			UserNameLabel->hide();
			PasswordLabel->hide();
			UserNameLineEdit->hide();
			PasswordLineEdit->hide();
			dialog()->screenRef("MainScreen")->menuSoftkey("MainVr", 7)->clear();
			*/
			nError = nWriteServer.write(szItem_UserLogin_Bit,QVariant(true));
		}
	}
	setHSoftkeyDisable(2, !g->m_bIsLogin);
	setHSoftkeyDisable(3, !g->m_bIsLogin);
	setHSoftkeyDisable(4, !g->m_bIsLogin);
	setHSoftkeyDisable(5, !g->m_bIsLogin);
	setHSoftkeyDisable(6, !g->m_bIsLogin);
	setHSoftkeyDisable(7, !g->m_bIsLogin);
	setHSoftkeyDisable(8, !g->m_bIsLogin);
}

void MainForm::setHSoftkeyState()
{
	setHSoftkeyDisable(2, !g->m_bIsLogin);
	setHSoftkeyDisable(3, !g->m_bIsLogin);
	setHSoftkeyDisable(4, !g->m_bIsLogin);
	setHSoftkeyDisable(5, !g->m_bIsLogin);
	setHSoftkeyDisable(6, !g->m_bIsLogin);
	setHSoftkeyDisable(7, !g->m_bIsLogin);
	setHSoftkeyDisable(8, !g->m_bIsLogin);
}

void MainForm::Logoff(const QString& rsArgs)
{
	/*
	if(g->m_bIsLogin == true){
		g->m_bIsLogin = false;
		setStatusBarElementText(g_pIni->m_strNotLogin, 1);

		UserNameLineEdit->setDisabled(false);
		PasswordLineEdit->setDisabled(false);

		setVSoftkeyDisable(6, false);
		setVSoftkeyDisable(7, true);
	}
	setHSoftkeyDisable(2, !g->m_bIsLogin);
	setHSoftkeyDisable(3, !g->m_bIsLogin);
	setHSoftkeyDisable(4, !g->m_bIsLogin);
	setHSoftkeyDisable(5, !g->m_bIsLogin);
	setHSoftkeyDisable(6, !g->m_bIsLogin);
	setHSoftkeyDisable(7, !g->m_bIsLogin);
	setHSoftkeyDisable(8, !g->m_bIsLogin);
	*/
	if( g->m_nPLCWorkState > PLC_WORKSTATE_READY && g->m_nPLCWorkState < PLC_WORKSTATE_REPAIR )
		return;

	g->m_nConfirmType = CONFIRM_LOGOFF;
	dialog()->switchToScreen("ConfirmScreen",rsArgs);
}

void MainForm::Start( )
{
	//g->m_StartTestStatus = TESTSTATUS_START;
	//g_pErr->createPLCAlarm(TM_EVENTSOURCE_PLC_BASE_WAITING);
	//g_pErr->createPLCAlarm(TM_EVENTSOURCE_PLC_BASE_WAITING+100);

	//g_pErr->createLackSpaceAlarm();
	//g_pErr->createLicenseAlarm();
	//g_pErr->createTCUCOMAlarm();
	//g_pErr->createPCUCOMAlarm();
	//g_pErr->createStopWorkAlarm();

	//g->m_LH_Error |= REPORT_3_ERR;
	//g->m_LV_Error |= REPORT_3_ERR;
	//g->m_RH_Error |= REPORT_3_ERR;
	//g->m_RV_Error |= REPORT_3_ERR;
	//g_pErr->createPCUAlarms();

	//g->m_LH_Error |= REPORT_11_ERR;
	//g_pErr->createPCUAlarms();

	//g->TcuSetTrainSpeedProc( 0.3 );
	//g->TcuSetWorkMileageProc(161.732);
	//PostQuitMessage(0);
	//exit(0);

	//g->TcuSetTrainSpeedProc( g->m_DstTrainSpeed );
	//g->TcuEnableTrainProc( true );
	setVSoftkeyDisable(1, true);
	setVSoftkeyDisable(2, false);
}

void MainForm::Stop()
{
	//g->m_StartTestStatus = TESTSTATUS_END;
	//g_pErr->clearPLCAlarm(TM_EVENTSOURCE_PLC_BASE_WAITING);
	//g_pErr->clearTypePLCAlarms(0);

	//g_pErr->clearTypePCUAlarms();
	//g->TcuSetTrainSpeedProc( 0.0 );
	//g->TcuSetWorkMileageProc(0.0);

	//g->TcuEnableTrainProc( false );
	setVSoftkeyDisable(1, false);
	setVSoftkeyDisable(2, true);
}

void MainForm::OperateManual(const QString& rsArgs)
{
	dialog()->showHelp("trainmilling_help/index.html","");//html anchor can be added
	//dialog()->switchToScreen("OperateManualScreen",rsArgs);
}

void MainForm::OperateNotice(const QString& rsArgs)
{
	dialog()->switchToScreen("OperateManualScreen",rsArgs);
	//dialog()->switchToScreen("OperateNoticeSreen",rsArgs);
}

///////////////////////////////////////////////////////////////////////////////
// public SLOTS - system overrides
///////////////////////////////////////////////////////////////////////////////
void MainForm::onFunction (const QString& rsFunction,
                                    const QString& rsArgs,
                                    bool& rbHandled)
{
	/*QDateTime current_datetime = QDateTime::currentDateTime();
	QString current_date=current_datetime.toString("yyyy-MM-dd hh-mm-ss");*/

 	// check null pointer
	if ( "OperateManual" == rsFunction )
	{
		OperateManual(rsArgs);
		rbHandled = true;		
	}
	else if ( "OperateNotice" == rsFunction )
	{
		OperateNotice(rsArgs);
		rbHandled = true;
	}
	else if ( "Login" == rsFunction )
	{
		Login( );
		rbHandled = true;

		if (g->m_bIsLogin)//ligy 20200213 add.添加日志 登录
		{
			g->m_StreamLog<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss")
				<<","<<g->m_strNowUserName
				<<","<< g_pIni->m_strLog_Login <<endl;
			g->m_StreamLog.flush();//ligy 20200213 add.
		}
	}
	else if ( "Logoff" == rsFunction )
	{
		Logoff( rsArgs );
		rbHandled = true;

		if (g->m_bIsLogin)//ligy 20200213 add.添加日志 注销
		{
			g->m_StreamLog<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss")
				<<","<<g->m_strNowUserName
				<<","<< g_pIni->m_strLog_Logoff <<endl;
			g->m_StreamLog.flush();//ligy 20200213 add.
		}	
	}
	else if ( "Start" == rsFunction )
	{
		rbHandled = true;

		g_iAddr40007 = TRAIN_START;//启动列车 ligy 201090827 add
		setVSoftkeyDisable(1, true);
		setVSoftkeyDisable(2, false);
	}
	else if ( "Stop" == rsFunction )
	{
	//	Stop( );
		rbHandled = true;

		g_iAddr40006 = 0;//低恒速设置为0

		g_iAddr40007 = TRAIN_STOP;//停止列车 ligy 201090827 add
		setVSoftkeyDisable(1, false);
		setVSoftkeyDisable(2, true);
	}
	// need to call the base class
	if ( false == rbHandled )
		SlGfwDialogForm::onFunction(rsFunction, rsArgs, rbHandled);
} // <-- MainForm::onFunction ()

void MainForm::TimeOutSlot( )
{
	/*
	QDateTime current_date_time =QDateTime::currentDateTime();
	QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss ddd");
	setCaptionBarElementText(current_date,1);
	*/
}

void MainForm::setHSoftkeyDisable(int nSoftkey, bool bDisabled)
{
	// get pointer to screen
	SlGfwScreen* pScreen = dialog()->screenRef("MainScreen");

	if ( 0 != pScreen )
	{
		// get pointer to softkey
		SlGfwSoftKey* pSoftkey = pScreen->menuSoftkey("MainMenu", nSoftkey);
		
		// enable/disable softkey
		if ( 0 != pSoftkey )
			pSoftkey->setDisabled(bDisabled);
	}
}

void MainForm::setVSoftkeyDisable(int nSoftkey, bool bDisabled)
{
	// get pointer to screen
	SlGfwScreen* pScreen = dialog()->screenRef("MainScreen");

	if ( 0 != pScreen )
	{
		// get pointer to softkey
		SlGfwSoftKey* pSoftkey = pScreen->menuSoftkey("MainVr", nSoftkey);
		
		// enable/disable softkey
		if ( 0 != pSoftkey )
			pSoftkey->setDisabled(bDisabled);
	}
}

void MainForm::showLoginUI()
{
	//SpeedNameLabel->setVisible(true);//ligy 20190903 add 
	//SpeedLineEdit->setVisible(true);//ligy 20190903 add 
	UserNameLabel->setVisible(true);
	PasswordLabel->setVisible(true);
	UserNameLineEdit->setVisible(true);
	PasswordLineEdit->setVisible(true);
	//setVSoftkeyDisable(6, g->m_bIsLogin);
	//setVSoftkeyDisable(7, !g->m_bIsLogin);
	setVSoftkeyDisable(6,  g->m_bIsLogin || (g->m_nPLCWorkState > PLC_WORKSTATE_READY && g->m_nPLCWorkState < PLC_WORKSTATE_REPAIR) || !g->m_bIsCertified);
	setVSoftkeyDisable(7, !g->m_bIsLogin || (g->m_nPLCWorkState > PLC_WORKSTATE_READY && g->m_nPLCWorkState < PLC_WORKSTATE_REPAIR) || !g->m_bIsCertified);
}

void MainForm::hideLoginUI()
{
//	SpeedNameLabel->setVisible(false);//ligy 20190903 add 
//	SpeedLineEdit->setVisible(false);//ligy 20190903 add 
	UserNameLabel->setVisible(false);
	PasswordLabel->setVisible(false);
	UserNameLineEdit->setVisible(false);
	PasswordLineEdit->setVisible(false);
	//setVSoftkeyDisable(6, true);
	//setVSoftkeyDisable(7, true);
	setVSoftkeyDisable(6,  g->m_bIsLogin || (g->m_nPLCWorkState > PLC_WORKSTATE_READY && g->m_nPLCWorkState < PLC_WORKSTATE_REPAIR) || !g->m_bIsCertified);
	setVSoftkeyDisable(7, !g->m_bIsLogin || (g->m_nPLCWorkState > PLC_WORKSTATE_READY && g->m_nPLCWorkState < PLC_WORKSTATE_REPAIR) || !g->m_bIsCertified);
}

//客户端连接 ligy 20190808 add
void MainForm::NewConnectionSlot()
{
	currentClient = tcpServer->nextPendingConnection();
	tcpClient.append(currentClient);

	connect(currentClient, SIGNAL(readyRead()), this, SLOT(ReadDataSlot()));
	connect(currentClient, SIGNAL(emitDiconnectSlot()), this, SLOT(disconnectedSlot()));
}

void MainForm::disconnectedSlot()
{
	//由于disconnected信号并未提供SocketDescriptor，所以需要遍历寻找
	for(int i=0; i<tcpClient.length(); i++)
	{
		if(tcpClient[i]->state() == QAbstractSocket::UnconnectedState)
		{
			// 删除存储在tcpClient列表中的客户端信息
			//	tcpClient[i].detroyed();
			tcpClient[i]->close();
			tcpClient.removeAt(i);
		}
	}
}

// 客户端数据可读信号，对应的读数据槽函数  ligy 20190808 add
void MainForm::ReadDataSlot()
{
	//setStatusBarElementText("receive client data",0);
	if (!m_bStartTcp)
	{
		return;
	}
	//心跳包 ligy 20190912 add
	static int iHeartBeatCount = 0;
	iHeartBeatCount++;
	if (iHeartBeatCount%40 == 0)
	{
		g_iAddr40001 = 0;
	} 
	else if (iHeartBeatCount%80 == 0)
	{
		g_iAddr40001 = 1;
	}
	//ligy 20190827 add
	SlQCap nMultiRead;
	QVector<SlCapReadSpecType> nRsVector;
	QVector<SlCapReadResultType> nValues;
	nRsVector.append(SlCapReadSpecType(szItem_LockState0_Bit)); //到位信号锁定/未锁定  1
	nRsVector.append(SlCapReadSpecType(szItem_WorkStart_Bit)); //铣磨作业开始/停止    2
	nRsVector.append(SlCapReadSpecType(szItem_PCUEmergencyStop_Bit)); //装置紧急提升/正常    3
	nRsVector.append(SlCapReadSpecType("I42.0"));  //左侧高位开关        4
	nRsVector.append(SlCapReadSpecType("I45.3"));  //右侧高位开关        5
	nRsVector.append(SlCapReadSpecType(szItem_TrainStart_Bit));  //启动列车            6
	nRsVector.append(SlCapReadSpecType(szItem_TrainStop_Bit));  //停止列车            7
	SlCapErrorEnum eError2 = nMultiRead.multiRead (nRsVector, nValues);
	if (true/*SL_SUCCEEDED(eError2)*/)
	{
		//到位信号锁定/未锁定,M31.3 ,LB4001.0
		g_iAddr40002 =(nValues[0].m_vValue.toBool()?g_iAddr40002|0x1:g_iAddr40002&0xfffe);
		//铣磨作业开始/停止 , M30.5 , LB4001.1
		g_iAddr40002 =(nValues[1].m_vValue.toBool()?g_iAddr40002|0x2:g_iAddr40002&0xfffd);
		//装置紧急提升/正常,  M32.0 , LB4001.2
		g_iAddr40002 =(nValues[2].m_vValue.toBool()?g_iAddr40002|0x4:g_iAddr40002&0xfffb);
		//装置提升到位/未到位,左侧高位开关 i42.0, 右侧高位开关I45.3, LB4001.3
		g_iAddr40002 =((!nValues[3].m_vValue.toBool())&(!nValues[4].m_vValue.toBool())?g_iAddr40002|0x8:g_iAddr40002&0xfff7);
		//铣磨装置故障/解除   LB4001.4  
		if (0 != g_pErr->m_pQAlarmPtrList)
		{
			int nNrOfAlarms = g_pErr->m_pQAlarmPtrList->getList()->size();
			g_iAddr40002=(g_pErr->m_pQAlarmPtrList->getList()->size()>0)?g_iAddr40002|0x10:g_iAddr40002&0xffef;
		}

		g_iAddr40003 = (int)g->double2double(g->m_L_SMWWorkMileage+g->m_R_SMWWorkMileage);//本次作业里程.ligy 20190905 add
		g_iAddr40004 = (int)g->double2double(g->m_SMWTotalWorkMileage);//总作业里程
		g_iAddr40005 = 0;
		g_iAddr40006 = g->double2double(g->m_DstTrainSpeed)*1000;//铣磨行车速度 m/h(X1000)
	
		emit emitShowSendData();//作业状态界面显示pcu发送数据内容 ligy 20190906 add
	} 
	else
	{
		return;//读取变量失败，不发送
	}


	// 由于readyRead信号并未提供SocketDecriptor，所以需要遍历所有客户端
	for(int i=0; i<tcpClient.length(); i++)
	{
		QByteArray rxBuffer = tcpClient[i]->readAll();

		if(rxBuffer.isEmpty())
			continue;
		if(rxBuffer.size() != 12)
			continue;

		QByteArray txBuffer;
		txBuffer.resize(0);

		int index = 0;
		unsigned char iDeviceAddr = rxBuffer[6];//Device Address
		unsigned char iFuncCode   = rxBuffer[7];//Function Code
		unsigned char iStartAddrHi = rxBuffer[8];//Start Address Hi byte
		unsigned char iStartAddrLo = rxBuffer[9];//Start Address Lo byte
		unsigned char iNoOfRegisterHi = rxBuffer[10];//No. of registers Hi byte
		unsigned char iNoOfRegisterLo = rxBuffer[11];//No. of registers Lo byte

		WORD iStartAddress = MAKEWORD(rxBuffer[9],rxBuffer[8]);
		WORD iNoOfRegister = MAKEWORD(rxBuffer[11],rxBuffer[10]);

		//byte 0-4 对应接收数据的0-4
		for (index=0;index<5;index++)
		{
			txBuffer.push_back(rxBuffer[index]);
		}
		txBuffer.push_back(iNoOfRegister*2 + 3);//
		txBuffer.push_back(iDeviceAddr);//Device Address
		txBuffer.push_back(iFuncCode);//Function Code
		txBuffer.push_back(iNoOfRegister*2);//byte count

		if (iNoOfRegister == 1)
		{
			txBuffer.push_back(HIBYTE(g_iAddr40002));
			txBuffer.push_back(LOBYTE(g_iAddr40002));
		}
		else
		{
			txBuffer.push_back(HIBYTE(g_iAddr40001));//心跳包 高8位
			txBuffer.push_back(LOBYTE(g_iAddr40001));//心跳包 低8位
			txBuffer.push_back(HIBYTE(g_iAddr40002));//锁定、铣磨车作业启停等，高8位
			txBuffer.push_back(LOBYTE(g_iAddr40002));//锁定、铣磨车作业启停等，低8位
			txBuffer.push_back(HIBYTE(g_iAddr40003));//本次作业里程（高8位）m
			txBuffer.push_back(LOBYTE(g_iAddr40003));//本次作业里程（低8位）m
			txBuffer.push_back(HIBYTE(g_iAddr40004));//总作业里程（高8位）Km
			txBuffer.push_back(LOBYTE(g_iAddr40004));//总作业里程（低8位）Km
			txBuffer.push_back(HIBYTE(g_iAddr40005));//预留 高8位
			txBuffer.push_back(LOBYTE(g_iAddr40005));//预留 低8位
			txBuffer.push_back(HIBYTE(g_iAddr40006));//铣磨行车速度 m/h(X1000)
			txBuffer.push_back(LOBYTE(g_iAddr40006));//铣磨行车速度 m/h(X1000)
			txBuffer.push_back(HIBYTE(g_iAddr40007));//1:启动列车
			txBuffer.push_back(LOBYTE(g_iAddr40007));//2:停止列车
		}

		if (txBuffer.size()==0)
		{
			continue;
		}
		//根据机车启动状态判断是否发送？
		tcpClient[i]->write(txBuffer);//向客户端发送数据

	}
}


//创建tcp服务器并监听502端口 ligy 20190808 add
bool MainForm::TcpServerInit(void)
{
	//初始化QTcpServer,
	tcpServer = new QTcpServer(this);
	//每当新的客户端连接到服务器时，newConncetion()信号触发，NewConnectionSlot()是用户的槽函数
	connect(tcpServer, SIGNAL(newConnection()), this, SLOT(NewConnectionSlot()));
	//监听502端口
	bool ok = tcpServer->listen(QHostAddress::Any,502);


	return ok;
}
//关闭tcp服务器 ligy 20190808 add
void MainForm::TcpServerClose(void)
{
	//disconnectedSlot();
	emit emitDiconnectSlot();
	//	emit disconnected();
	for(int i=0; i<tcpClient.length(); i++)//断开所有连接
	{
		tcpClient[i]->disconnectFromHost();
		//bool ok = tcpClient[i]->waitForDisconnected(1000);
		//if(!ok)
		//{
		//	// 处理异常
		//}
		tcpClient.removeAt(i);  //从保存的客户端列表中取去除
	}
	if (tcpServer != NULL)
	{
		tcpServer->close();     //关闭tcp服务器
	}

}
///////////////////////////////////////////////////////////////////////////////
// private methods
///////////////////////////////////////////////////////////////////////////////
