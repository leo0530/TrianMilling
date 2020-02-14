///////////////////////////////////////////////////////////////////////////////
/*! \file	scanform.cpp
 *  \author
 *  \date
 *  \brief	Implementation file for class ScanForm
 *
 *  This file is part of the HMI Solutionline GUI Framework.
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////
#include "scanform.h"
#include "PlotWidget.h"
#include "GlobalVar.h"
#include "QDateTime.h"


///////////////////////////////////////////////////////////////////////////////
// CREATORS
///////////////////////////////////////////////////////////////////////////////

ScanForm::ScanForm(QWidget* pParent, const QString& rszName)
	: SlGfwDialogForm(pParent, rszName)
{
	setupUi(this);
	//TestScanData();
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

	//TestScanData();
	//ReadScanData( );
}// <-- ScanForm::ScanForm ()


ScanForm::~ScanForm(void)
{
	if(m_tmrToggle.isActive())
		m_tmrToggle.stop();
} // <-- ::~ ()


void ScanForm::attachedToScreen(const QString& rszScreenName)
{
	if(g->m_bIsLogin==false){
		dialog()->switchToScreen("MainScreen",NULL);
		return;
	}

	if(g->m_bIsLogin==true)
		setStatusBarElementText(g_pIni->m_strLogin, 1);
	else
		setStatusBarElementText(g_pIni->m_strNotLogin, 1);

	g_pScanForm = this;
	
	PlotDrawing( );
	setSaveKeyState( );//设置保存菜单状态
    // don't forget to call the standard implementation
    SlGfwDialogForm::attachedToScreen(rszScreenName);
}


void ScanForm::detachedFromScreen(const QString& rszScreenName)
{
	g_pScanForm = NULL;
    // don't forget to call the standard implementation
    SlGfwDialogForm::detachedFromScreen(rszScreenName);
}


///////////////////////////////////////////////////////////////////////////////
// Overrides
///////////////////////////////////////////////////////////////////////////////

void ScanForm::TestScanData()
{
	double x,y;
	g->m_L_ScanDataX.clear();
	g->m_L_ScanDataY.clear();
	g->m_R_ScanDataX.clear();
	g->m_R_ScanDataY.clear();
	g->m_ScannerChoose = ScannerChoose::Left;

    for (int i=100; i>=0; i--)
    {
		x = i/50.0 - 1;						// x goes from -1 to 1
		y = 300*x*x;						// let's plot a quadratic function
		g->m_L_ScanDataX.append(x);
		g->m_L_ScanDataY.append(y);
    }

    for (int i=100; i>=0; i--)
    {
		x = i/50.0 - 1;						// x goes from -1 to 1
		y = 300*fabs(sin(x*3.1415));		// let's plot a quadratic function
		g->m_R_ScanDataX.append(x);
		g->m_R_ScanDataY.append(y);
    }
	//Sorted Data......
	g->SortedScanData( );
}

void ScanForm::ReadScanData( )
{
	g->m_L_ScanDataX.clear();
	g->m_L_ScanDataY.clear();
	g->m_R_ScanDataX.clear();
	g->m_R_ScanDataY.clear();
	g->m_ScannerChoose = ScannerChoose::Left;

	QFile fin("C:/scr/ScanData.csv");
	if(!fin.open(QIODevice::ReadOnly | QIODevice::Text ))
	{
		//qDebug()<<"OPEN FILE FAILED";  
	}
	QTextStream txtinput(&fin);
	QStringList m_Lineitems = txtinput.readAll().split("\n");
	int TotalLines = m_Lineitems.count() - 1;
	for(int i = 0 ; i < TotalLines ; i++)
	{ 
		QStringList Unititem = m_Lineitems.at(i).split(",");
		double LX = Unititem.at(0).toDouble();
		double LY = Unititem.at(1).toDouble();
		double RX = Unititem.at(2).toDouble();
		double RY = Unititem.at(3).toDouble();
		g->m_L_ScanDataX.append(LX);
		g->m_L_ScanDataY.append(LY);
		g->m_R_ScanDataX.append(RX);
		g->m_R_ScanDataY.append(RY);
	}
	fin.close();
	g->SortedScanData( );
}

void ScanForm::PlotDrawing( )
{
	int index;
	double minX,maxX,minY,maxY;

	if(g_pDialog->m_bIsScanning){
		LeftPlotWidget->clearData();
		RightPlotWidget->clearData();
		LeftPlotWidget->repaint();
		RightPlotWidget->repaint();

		g->m_L_ScanCurPosX = 0;
		g->m_L_ScanCalibPosX = 0;
		g->m_R_ScanCurPosX = 0;
		g->m_R_ScanCalibPosX = 0;
		LeftCurPosLineEdit->setValue(g->m_L_ScanCurPosX);
		LeftCalibPosLineEdit->setValue(g->m_L_ScanCalibPosX);
		RightCurPosLineEdit->setValue(g->m_R_ScanCurPosX);
		RightCalibPosLineEdit->setValue(g->m_R_ScanCalibPosX);
		L_MotorRealPosLineEdit->setValue(QVariant(0));
		R_MotorRealPosLineEdit->setValue(QVariant(0));
		return;
	}

	int n1 = g->m_L_ScanDataX.size();
	int n2 = g->m_L_ScanDataY.size();
	int n3 = g->m_R_ScanDataX.size();
	int n4 = g->m_R_ScanDataY.size();
	if( n1==0 || n2==0 || n3==0 || n4==0 || !g_pDialog->m_bIsNewScanData)
		return;

	g_pDialog->m_bIsNewScanData = false;
	// create graph and assign data to it:
	LeftPlotWidget->setData(g->m_L_ScanDataX, g->m_L_ScanDataY);
	// set axes ranges, so we see all data:
	minY = 0;
	maxY = g->m_L_ScanDataMaxY;
	minX = g->m_L_ScanDataX[0];
	maxX = g->m_L_ScanDataX[n1-1];
	/*
	minX = minX > 0 ? ceil(minX) : minX;
	minX = minX < 0 ? floor(minX) : minX;
	maxX = maxX > 0 ? ceil(maxX) : maxX;
	maxX = maxX < 0 ? floor(maxX) : maxX;
	*/
	minX = minX > 0 ? floor(minX) : minX;
	minX = minX < 0 ? floor(minX) : minX;
	maxX = maxX > 0 ? ceil(maxX) : maxX;
	maxX = maxX < 0 ? ceil(maxX) : maxX;

	LeftPlotWidget->setXRange(minX, maxX);
	LeftPlotWidget->setYRange(minY, maxY);     
	LeftPlotWidget->setDisplayMode(DisplayMode_SolidLabel);
	LeftPlotWidget->setBKColor(QColor(192,192,192));

	index = LeftPlotWidget->GetLabelIndex();
	if( -1 != index ){
		g->m_L_ScanCalibPosX = g->m_L_ScanCurPosX = g->m_L_ScanDataX.at(index);
		LeftCurPosLineEdit->setValue(g->m_L_ScanCurPosX);
		LeftCalibPosLineEdit->setValue(g->m_L_ScanCalibPosX);
	}

	// create graph and assign data to it:
	RightPlotWidget->setData(g->m_R_ScanDataX, g->m_R_ScanDataY);
	// set axes ranges, so we see all data:
	minY = 0;
	maxY = g->m_R_ScanDataMaxY;
	minX = g->m_R_ScanDataX[0];
	maxX = g->m_R_ScanDataX[n1-1];
	/*
	minX = minX > 0 ? ceil(minX) : minX;
	minX = minX < 0 ? floor(minX) : minX;
	maxX = maxX > 0 ? ceil(maxX) : maxX;
	maxX = maxX < 0 ? floor(maxX) : maxX;
	*/
	minX = minX > 0 ? floor(minX) : minX;
	minX = minX < 0 ? floor(minX) : minX;
	maxX = maxX > 0 ? ceil(maxX) : maxX;
	maxX = maxX < 0 ? ceil(maxX) : maxX;

	RightPlotWidget->setXRange(minX, maxX);
	RightPlotWidget->setYRange(minY, maxY);
	RightPlotWidget->setDisplayMode(DisplayMode_DashLabel);
	RightPlotWidget->ClearBKColor();

	index = RightPlotWidget->GetLabelIndex();
	if( -1 != index ){
		g->m_R_ScanCalibPosX = g->m_R_ScanCurPosX = g->m_R_ScanDataX.at(index);
		RightCurPosLineEdit->setValue(g->m_R_ScanCurPosX);
		RightCalibPosLineEdit->setValue(g->m_R_ScanCalibPosX);
	}
	LeftPlotWidget->repaint();
	RightPlotWidget->repaint();
}

void ScanForm::SwitchScanner( )//轨道切换
{
	if(g->m_ScannerChoose == ScannerChoose::Left)
		g->m_ScannerChoose = ScannerChoose::Right;
	else if(g->m_ScannerChoose == ScannerChoose::Right)
		g->m_ScannerChoose = ScannerChoose::Left;
	switch(g->m_ScannerChoose)
	{
	case ScannerChoose::Left:
		LeftPlotWidget->setDisplayMode(DisplayMode_SolidLabel);
		LeftPlotWidget->setBKColor(QColor(192,192,192));
		RightPlotWidget->setDisplayMode(DisplayMode_DashLabel);
		RightPlotWidget->ClearBKColor();
		LeftPlotWidget->repaint();
		RightPlotWidget->repaint();
		break;
	case ScannerChoose::Right:
		LeftPlotWidget->setDisplayMode(DisplayMode_DashLabel);
		LeftPlotWidget->ClearBKColor();
		RightPlotWidget->setDisplayMode(DisplayMode_SolidLabel);
		RightPlotWidget->setBKColor(QColor(192,192,192));
		LeftPlotWidget->repaint();
		RightPlotWidget->repaint();
		break;
	default:
		break;
	}
}

void ScanForm::Increase( )
{
	if(LeftPlotWidget->IsEmpty())
		return;

	int index;
	switch(g->m_ScannerChoose)
	{
	case ScannerChoose::Left:
		index = LeftPlotWidget->IncreaseLabel();
		g->m_L_ScanCurPosX = g->m_L_ScanDataX.at(index);
		LeftCurPosLineEdit->setValue(g->m_L_ScanCurPosX);
		LeftPlotWidget->repaint();
		break;
	case ScannerChoose::Right:
		index = RightPlotWidget->IncreaseLabel();
		g->m_R_ScanCurPosX = g->m_R_ScanDataX.at(index);
		RightCurPosLineEdit->setValue(g->m_R_ScanCurPosX);
		RightPlotWidget->repaint();
		break;
	default:
		break;
	}
}

void ScanForm::Decrease()
{
	if(LeftPlotWidget->IsEmpty())
		return;

	int index;
	switch(g->m_ScannerChoose)
	{
	case ScannerChoose::Left:
		index = LeftPlotWidget->DecreaseLabel();
		g->m_L_ScanCurPosX = g->m_L_ScanDataX.at(index);
		LeftCurPosLineEdit->setValue(g->m_L_ScanCurPosX);
		LeftPlotWidget->repaint();
		break;
	case ScannerChoose::Right:
		index = RightPlotWidget->DecreaseLabel();
		g->m_R_ScanCurPosX = g->m_R_ScanDataX.at(index);
		RightCurPosLineEdit->setValue(g->m_R_ScanCurPosX);
		RightPlotWidget->repaint();
		break;
	default:
		break;
	}
}
void ScanForm::QuickIncrease()
{
	if(LeftPlotWidget->IsEmpty())
		return;

	int index;
	switch(g->m_ScannerChoose)
	{
	case ScannerChoose::Left:
		index = LeftPlotWidget->QuickIncreaseLabel();
		g->m_L_ScanCurPosX = g->m_L_ScanDataX.at(index);
		LeftCurPosLineEdit->setValue(g->m_L_ScanCurPosX);
		LeftPlotWidget->repaint();
		break;
	case ScannerChoose::Right:
		index = RightPlotWidget->QuickIncreaseLabel();
		g->m_R_ScanCurPosX = g->m_R_ScanDataX.at(index);
		RightCurPosLineEdit->setValue(g->m_R_ScanCurPosX);
		RightPlotWidget->repaint();
		break;
	default:
		break;
	}
}
void ScanForm::QuickDecrease()
{
	if(LeftPlotWidget->IsEmpty())
		return;

	int index;
	switch(g->m_ScannerChoose)
	{
	case ScannerChoose::Left:
		index = LeftPlotWidget->QuickDecreaseLabel();
		g->m_L_ScanCurPosX = g->m_L_ScanDataX.at(index);
		LeftCurPosLineEdit->setValue(g->m_L_ScanCurPosX);
		LeftPlotWidget->repaint();
		break;
	case ScannerChoose::Right:
		index = RightPlotWidget->QuickDecreaseLabel();
		g->m_R_ScanCurPosX = g->m_R_ScanDataX.at(index);
		RightCurPosLineEdit->setValue(g->m_R_ScanCurPosX);
		RightPlotWidget->repaint();
		break;
	default:
		break;
	}
}

void ScanForm::setSaveKeyState( )//ligy 20190908 add。单元被选中才能保存参数
{
	bool L_UnitOk = g->m_L_bEnableUnit && !LeftPlotWidget->IsEmpty();
	bool R_UnitOk = g->m_R_bEnableUnit && !RightPlotWidget->IsEmpty();
	if( !L_UnitOk && !R_UnitOk )
		setSoftkeyDisable(7, true);
	else
		setSoftkeyDisable(7, false);
}

bool ScanForm::Save( )
{
	bool bConnectFailed = false;
	double LH_Pos,LV_Pos,RH_Pos,RV_Pos;

	bool L_UnitOk = g->m_L_bEnableUnit && !LeftPlotWidget->IsEmpty();
	bool R_UnitOk = g->m_R_bEnableUnit && !RightPlotWidget->IsEmpty();
	if( !L_UnitOk && !R_UnitOk )
		return false;

	g->m_L_ScanCalibPosX = g->m_L_ScanCurPosX;
	LeftCalibPosLineEdit->setValue(g->m_L_ScanCalibPosX);//左铣削单元Y轴标定位置
	g->m_R_ScanCalibPosX = g->m_R_ScanCurPosX;
	RightCalibPosLineEdit->setValue(g->m_R_ScanCalibPosX);//右铣削单元Y轴标定位置

	LH_Pos = g->m_L_ScanCalibPosX-g->m_LH_RailOffset-g->m_H_DeviceIniPos-g->m_LScannerToCutterOffset;
	RH_Pos = g->m_R_ScanCalibPosX-g->m_RH_RailOffset-g->m_H_DeviceIniPos-g->m_RScannerToCutterOffset;
	LV_Pos = g->m_LV_MotorCalibPos-g->m_LV_RailOffset-g->m_V_DeviceIniPos;
	RV_Pos = g->m_RV_MotorCalibPos-g->m_RV_RailOffset-g->m_V_DeviceIniPos;

	L_MotorRealPosLineEdit->setValue(LH_Pos);//左铣削单元Y电机实际位置
	R_MotorRealPosLineEdit->setValue(RH_Pos);//右铣削单元Y电机实际位置

	LH_Pos *= 100;
	RH_Pos *= 100;
	LV_Pos *= 100;
	RV_Pos *= 100;

	SlQCap nMultiWrite;
	QVector<SlCapWriteSpecType> nSysParaArray;
	nSysParaArray.append(SlCapWriteSpecType(szItem_LH_ScanSave,QVariant(LH_Pos)));//左单元Y轴标定值
	nSysParaArray.append(SlCapWriteSpecType(szItem_RH_ScanSave,QVariant(RH_Pos)));//右单元Y轴标定值
	nSysParaArray.append(SlCapWriteSpecType(szItem_LV_ScanSave,QVariant(LV_Pos)));//左单元Z轴标定值
	nSysParaArray.append(SlCapWriteSpecType(szItem_RV_ScanSave,QVariant(RV_Pos)));//右单元Z轴标定值

	SlCapErrorEnum nError = nMultiWrite.multiWrite(nSysParaArray);
	if(SL_SUCCEEDED(nError))
	{
		SlQCap nWriteServer;
		nError = nWriteServer.write(szItem_ScanSave_Bit,QVariant(true));//M31.1:扫描后黄标设定标志
		if(!SL_SUCCEEDED(nError)){
			bConnectFailed = true;
			g->m_bPcuCommState = false;
			g_pErr->createPCUCOMAlarm();
		}
	}
	else{
		bConnectFailed = true;
		g->m_bPcuCommState = false;
		g_pErr->createPCUCOMAlarm();
	}
	return true;
}
///////////////////////////////////////////////////////////////////////////////
// public ACCESSORS
///////////////////////////////////////////////////////////////////////////////

void ScanForm::TimeoutSlot()
{
	/*
	QDateTime current_date_time =QDateTime::currentDateTime();
	QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss ddd");
	setCaptionBarElementText(current_date,1);
	*/
}

///////////////////////////////////////////////////////////////////////////////
// public SLOTS - system overrides
///////////////////////////////////////////////////////////////////////////////
void ScanForm::onFunction (const QString& rsFunction,
                                    const QString& rsArgs,
                                    bool& rbHandled)
{
	if ( "SatrtScan" == rsFunction )
	{
		if(0 != g_pDialog)
			g_pDialog->StartScan( );
	}
	if ( "StopScan" == rsFunction )
	{
		if(0 != g_pDialog)
			g_pDialog->StopScan( );
	}

	if ( "SwitchScanner" == rsFunction )
	{
		SwitchScanner( );
		rbHandled = true;
	}
	else if ( "Increase" == rsFunction )
	{
		Increase( );
		rbHandled = true;
	}
	else if ( "Decrease" == rsFunction )
	{
		Decrease( );
		rbHandled = true;
	}
	else if ( "QuickIncrease" == rsFunction )
	{
		QuickIncrease( );
		rbHandled = true;
	}

	else if ( "QuickDecrease" == rsFunction )
	{
		QuickDecrease( );
		rbHandled = true;
	}
	else if ( "ChangeScannerMode" == rsFunction )
	{

		rbHandled = true;
	}
	else if ( "Save" == rsFunction ) //ligy 20190908 add
	{
		bool bSaveOK = Save( );
		if( bSaveOK ){
			setSoftkeyDisable(1, true);
			setSoftkeyDisable(2, true);
			setSoftkeyDisable(3, true);
			setSoftkeyDisable(4, true);
			setSoftkeyDisable(5, true);
			setSoftkeyDisable(6, true);
			setSoftkeyDisable(7, true);
		}

		if (bSaveOK)
		{
			if (g->m_bIsLogin)//ligy 20200213 add.添加日志 轨廓扫描参数保存
			{
				g->m_StreamLog<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss")
					<<","<<g->m_strNowUserName
					<<","<< g_pIni->m_strLog_ScanParamSave <<endl;
				g->m_StreamLog.flush();//ligy 20200213 add.
			}	
		}
		rbHandled = true;
	}
	// need to call the base class
	if ( false == rbHandled )
		SlGfwDialogForm::onFunction(rsFunction, rsArgs, rbHandled);
} // <-- ScanForm::onFunction ()

///////////////////////////////////////////////////////////////////////////////
// private methods
///////////////////////////////////////////////////////////////////////////////
void ScanForm::setSoftkeyDisable(int nSoftkey, bool bDisabled)
{
	// get pointer to screen
	SlGfwScreen* pScreen = dialog()->screenRef("ScanScreen");

	if ( 0 != pScreen )
	{
		// get pointer to softkey
		SlGfwSoftKey* pSoftkey = pScreen->menuSoftkey("ScanVr", nSoftkey);
		
		// enable/disable softkey
		if ( 0 != pSoftkey )
			pSoftkey->setDisabled(bDisabled);
	}
}