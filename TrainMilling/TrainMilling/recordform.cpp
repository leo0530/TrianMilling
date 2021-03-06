///////////////////////////////////////////////////////////////////////////////
/*! \file	recordform.cpp
 *  \author
 *  \date
 *  \brief	Implementation file for class RecordForm
 *
 *  This file is part of the HMI Solutionline GUI Framework.
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////
#include "recordform.h"
#include "QDateTime.h"
#include "slhmisettingsqt.h" 
#include <QtCore/QFileInfo>
#include <QtCore/QDir>
#include <QtCore/QTextCodec>
#include <QtCore/QTextStream>
#include <windows.h>  
#include "Winioctl.h"
#include <dbt.h>  
#include <stdio.h>  
#include "slgfwsoftkey.h"
///////////////////////////////////////////////////////////////////////////////
// CREATORS
///////////////////////////////////////////////////////////////////////////////

RecordForm::RecordForm(QWidget* pParent, const QString& rszName)
	: SlGfwDialogForm(pParent, rszName)
{
	setupUi(this);

	// initialize status bar
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

	RestoreTouchButton->setProperty("disabledFace",2);
	ZoomInTouchButton->setProperty("disabledFace",2);
	ZoomOutTouchButton->setProperty("disabledFace",2);

	//g->m_strfileRecord = "..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\workrecord\\workrecord 2019-09-06 18-06-09 Operator.csv";

	QObject::connect( RestoreTouchButton,SIGNAL(mouseButtonPressed(int, const QPoint&, QWidget*)),this,SLOT(RestorePressedSlot(int, const QPoint&, QWidget* )) );
	QObject::connect( ZoomInTouchButton,SIGNAL(mouseButtonPressed(int, const QPoint&, QWidget*)),this,SLOT(ZoomInPressedSlot(int, const QPoint&, QWidget* )) );
	QObject::connect( ZoomOutTouchButton,SIGNAL(mouseButtonPressed(int, const QPoint&, QWidget*)),this,SLOT(ZoomOutPressedSlot(int, const QPoint&, QWidget* )) );

	QObject::connect( RestoreTouchButton,SIGNAL(mouseButtonReleased(int, const QPoint&, QWidget*)),this,SLOT(RestoreReleasedSlot(int, const QPoint&, QWidget* )) );
	QObject::connect( ZoomInTouchButton,SIGNAL(mouseButtonReleased(int, const QPoint&, QWidget*)),this,SLOT(ZoomInReleasedSlot(int, const QPoint&, QWidget* )) );
	QObject::connect( ZoomOutTouchButton,SIGNAL(mouseButtonReleased(int, const QPoint&, QWidget*)),this,SLOT(ZoomOutReleasedSlot(int, const QPoint&, QWidget* )) );
	m_xMin = -1;	m_xMax = 1;
	m_yMin = -1;	m_yMax = 1;

	hideInfoUI();
	clearCurveData();

}// <-- RecordForm::RecordForm ()


RecordForm::~RecordForm(void)
{
	if(m_tmrToggle.isActive())
		m_tmrToggle.stop();

} // <-- ::~ ()


///////////////////////////////////////////////////////////////////////////////
// Overrides
///////////////////////////////////////////////////////////////////////////////

void RecordForm::attachedToScreen(const QString& rszScreenName)
{
	if(g->m_bIsLogin==false){
		dialog()->switchToScreen("MainScreen",NULL);
		return;
	}

	if(g->m_bIsLogin==true)
		setStatusBarElementText(g_pIni->m_strLogin, 1);
	else
		setStatusBarElementText(g_pIni->m_strNotLogin, 1);

	//Start Timer
	m_tmrToggle.setSingleShot(false);
	m_tmrToggle.setInterval(1000);
	// signal/slot connection for QTimer
	QObject::connect( &m_tmrToggle,SIGNAL(timeout()),this,SLOT(TimeoutSlot()) );
	// start timer
	//m_tmrToggle.start();

	TrainMileageLineEdit->setValue(g->double2double(g->m_SMWTotalTrainMileage));
	WorkMileageLineEdit->setValue(g->double2double(g->m_SMWTotalWorkMileage));
	checkMemory();
	if(g->m_strfileRecord.isEmpty()){
		setVSoftkeyDisable(4, true);
		setVSoftkeyDisable(5, true);
		setVSoftkeyDisable(6, true);
		setVSoftkeyDisable(7, true);
	}
	if(drawWidget->isEmpty()){
		RestoreTouchButton->setEnabled(false);
		ZoomInTouchButton->setEnabled(false);
		ZoomOutTouchButton->setEnabled(false);
	}
	if( g->IsWorkingState() )//是否作业状态？
	{
		setVSoftkeyDisable(1, true);
		setVSoftkeyDisable(2, true);
		setVSoftkeyDisable(3, true);
		setVSoftkeyDisable(4, true);
		setVSoftkeyDisable(5, true);
		setVSoftkeyDisable(6, true);
		setVSoftkeyDisable(7, true);
		setVSoftkeyDisable(8, true);
	}
	setStatusBarElementText("",0);
	g_pRecordForm = this;
	//testPlotData();
    // don't forget to call the standard implementation
    SlGfwDialogForm::attachedToScreen(rszScreenName);
}


void RecordForm::detachedFromScreen(const QString& rszScreenName)
{
	if(m_tmrToggle.isActive())
		m_tmrToggle.stop();

	g_pRecordForm = 0;

    // don't forget to call the standard implementation
    SlGfwDialogForm::detachedFromScreen(rszScreenName);
}

///////////////////////////////////////////////////////////////////////////////
// public SLOTS - system overrides
///////////////////////////////////////////////////////////////////////////////
void RecordForm::onFunction (const QString& rsFunction,
                                    const QString& rsArgs,
                                    bool& rbHandled)
{
	if ( "ZeroMileage" == rsFunction )//里程清零
	{
		g->m_SMWLastRSTTrainMileage = g->m_SMWTotalTrainMileage;
		g->m_SMWLastRSTWorkMileage = g->m_SMWTotalWorkMileage;
		g->m_SMWTotalTrainMileage = 0;
		g->m_SMWTotalWorkMileage = 0;
		g->m_SMWLastResetTime =  QDateTime::currentDateTime();

		TrainMileageLineEdit->setValue(g->double2double(g->m_SMWTotalTrainMileage));
		WorkMileageLineEdit->setValue(g->double2double(g->m_SMWTotalWorkMileage));
		g_pIni->SaveMileageParameters();
		rbHandled = true;
	}
	else if ( "AllReset" == rsFunction )//全部清零
	{
		g->m_SMWLastRSTTrainMileage = g->m_SMWTotalTrainMileage;
		g->m_SMWLastRSTWorkMileage = g->m_SMWTotalWorkMileage;
		g->m_SMWTotalTrainMileage = 0;
		g->m_SMWTotalWorkMileage = 0;
		g->m_SMWLastResetTime =  QDateTime::currentDateTime();

		TrainMileageLineEdit->setValue(g->double2double(g->m_SMWTotalTrainMileage));
		WorkMileageLineEdit->setValue(g->double2double(g->m_SMWTotalWorkMileage));
		g_pIni->SaveMileageParameters();

		hideInfoUI();
		clearCurveData();
		rbHandled = true;
	}
	else if ( "ExportRecord" == rsFunction )//导出记录
	{
		hideInfoUI();
		clearCurveData();
		QString sourceDir("..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\workrecord");
		QString targetDir("c:\\traindata");
		copyDirectoryFiles(sourceDir,targetDir,true);
		rbHandled = true;
	}
	else if ( "LH_Data" == rsFunction )//左侧横向数据
	{
		if(!g->m_strfileRecord.isEmpty() && !g->IsWorkingState() ){
			showInfoUI_LH(g->m_strfileRecord);
			showCurveData_LH(g->m_strfileRecord);
			RestoreTouchButton->setEnabled(true);
			ZoomInTouchButton->setEnabled(true);
			ZoomOutTouchButton->setEnabled(true);
		}
		rbHandled = true;
	}
	else if ( "LV_Data" == rsFunction )//左侧垂向数据
	{
		if(!g->m_strfileRecord.isEmpty() && !g->IsWorkingState() ){
			showInfoUI_LV(g->m_strfileRecord);
			showCurveData_LV(g->m_strfileRecord);
			RestoreTouchButton->setEnabled(true);
			ZoomInTouchButton->setEnabled(true);
			ZoomOutTouchButton->setEnabled(true);
		}
		rbHandled = true;
	}
	else if ( "RH_Data" == rsFunction )//右侧横向数据
	{
		if(!g->m_strfileRecord.isEmpty() && !g->IsWorkingState() ){
			showInfoUI_RH(g->m_strfileRecord);
			showCurveData_RH(g->m_strfileRecord);
			RestoreTouchButton->setEnabled(true);
			ZoomInTouchButton->setEnabled(true);
			ZoomOutTouchButton->setEnabled(true);
		}
		rbHandled = true;
	}
	else if ( "RV_Data" == rsFunction )//右侧垂向数据
	{
		if(!g->m_strfileRecord.isEmpty() && !g->IsWorkingState() ){
			showInfoUI_RV(g->m_strfileRecord);
			showCurveData_RV(g->m_strfileRecord);
			RestoreTouchButton->setEnabled(true);
			ZoomInTouchButton->setEnabled(true);
			ZoomOutTouchButton->setEnabled(true);
		}
		rbHandled = true;
	}
	else if ( "UserManagement" == rsFunction )
	{
		hideInfoUI();
		clearCurveData();
		dialog()->switchToScreen("UserManagerSreen",rsArgs);
		rbHandled = true;
	}
	// need to call the base class
	if ( false == rbHandled )
		SlGfwDialogForm::onFunction(rsFunction, rsArgs, rbHandled);
} // <-- RecordForm::onFunction ()

void RecordForm::timeoutSlot( )
{

}

bool RecordForm::copyDirectoryFiles(QString fromDir,QString toDir,bool coverFileIfExist)
{
	QByteArray qbDir = toDir.toLocal8Bit();
	char* cDir = qbDir.data();
	cDir[0]=m_UdiskDrive;
	toDir = toDir.fromLocal8Bit(cDir);
	QDir sourceDir(fromDir);
	QDir targetDir(toDir);
	if(!targetDir.exists())
		if(!targetDir.mkdir(targetDir.absolutePath()))
		{
			setStatusBarElementText(readText("createDirError","WorkRecord"),0);//´´½¨ÎÄ¼þ¼ÐÊ§°Ü
			return false;
		}
	QFileInfoList fileInfoList = sourceDir.entryInfoList();
	foreach(QFileInfo fileInfo,fileInfoList)
	{
		if(fileInfo.fileName()=="."||fileInfo.fileName()=="..")
			continue;
		if(fileInfo.isDir())//ÎªÄ¿Â¼Ê±µÝ¹éµ÷ÓÃ
		{
			if(!copyDirectoryFiles(fileInfo.filePath(),targetDir.filePath(fileInfo.fileName()),coverFileIfExist))
				return false;
		}
		else
		{
			QString recordName = fileInfo.fileName();
			QStringList nameList = recordName.split(" ");
			if(nameList.count() == 4){
				nameList[3] = nameList[3].remove(".csv");

				QDateTime createDatetime = fileInfo.created();
				QDateTime nowDatetime = QDateTime::currentDateTime();
				QDateTime borderDatetime = nowDatetime.addDays(-1);//ÌáÇ°Ò»¸öÔÂ
				if(createDatetime>borderDatetime && nameList[3].trimmed()==g->m_strNowUserName) //¶ÔÓ¦µÇÂ½ÕßµÃ×î½ü30Ìì¼ÇÂ¼
				{
					if(coverFileIfExist&&targetDir.exists(fileInfo.fileName()))//ÔÊÐí¸²¸ÇÎÄ¼þ
					{
						targetDir.remove(fileInfo.fileName());
					}
					if(!QFile::copy(fileInfo.filePath(),targetDir.filePath(fileInfo.fileName())))
					{
						setStatusBarElementText(readText("copyDirError","WorkRecord"),0);//´´½¨ÎÄ¼þ¼ÐÊ§°Ü
						return false;
					}
				}
			}
		}	
	}

	if( UninstallUsb(m_UdiskDrive) )
		setStatusBarElementText(readText("eS_UDiskSuccess","WorkRecord"),0);
	else
		setStatusBarElementText(readText("eS_UDiskError","WorkRecord"),0);

	setVSoftkeyDisable(3, true);
	return true;
}

void RecordForm::checkMemory()
{
	setVSoftkeyDisable(3, true);
	bool memoryIsReady = false;
	char DiskName[256]="E:\\";
	
	UINT DiskType;
	unsigned char i = 0x42;//B的ASCII码66:(42H)
	for(;i<0x5B;i+=0x1)//查询盘符从B到Z各个盘是否是可移动磁盘
	{
		DiskName[0]=i;//"B:\\"-"Z:\\"
		DiskType = GetDriveType(DiskName);
		if(DiskType==DRIVE_REMOVABLE)//可移动式硬盘
		{
			setVSoftkeyDisable(3, false);
			m_UdiskDrive = i;
			memoryIsReady = true;
			break;
		}
	}
}


void RecordForm::ZoomInPressedSlot(int, const QPoint&, QWidget* )
{
	if( drawWidget->zoomIn() == false){
		ZoomInTouchButton->setEnabled(false);
	}
	if( drawWidget->isZoomInAndOut()== true ){
		ZoomOutTouchButton->setEnabled(true);
		ZoomInTouchButton->setEnabled(true);

		ZoomInTouchButton->setPressed(true);
	}

}

void RecordForm::ZoomOutPressedSlot(int, const QPoint&, QWidget* )
{
	if( drawWidget->zoomOut()== false ){
		ZoomOutTouchButton->setEnabled(false);
	}
	if( drawWidget->isZoomInAndOut()== true ){
		ZoomOutTouchButton->setEnabled(true);
		ZoomInTouchButton->setEnabled(true);

		ZoomOutTouchButton->setPressed(true);
	}
}

void RecordForm::RestorePressedSlot(int, const QPoint&, QWidget* )
{
	ZoomOutTouchButton->setEnabled(true);
	ZoomInTouchButton->setEnabled(true);
	drawWidget->setXRange(m_xMin, m_xMax);
	drawWidget->setYRange(m_yMin, m_yMax);     
	drawWidget->restoreZoom();
	drawWidget->repaint();
	RestoreTouchButton->setPressed(true);
}

void RecordForm::ZoomInReleasedSlot(int, const QPoint&, QWidget* )
{
	ZoomInTouchButton->setPressed(false);
}

void RecordForm::ZoomOutReleasedSlot(int, const QPoint&, QWidget* )
{
	ZoomOutTouchButton->setPressed(false);
}

void RecordForm::RestoreReleasedSlot(int, const QPoint&, QWidget* )
{
	RestoreTouchButton->setPressed(false);
}

///////////////////////////////////////////////////////////////////////////////
// private methods
///////////////////////////////////////////////////////////////////////////////
void RecordForm::setVSoftkeyDisable(int nSoftkey, bool bDisabled)
{
	// get pointer to screen
	SlGfwScreen* pScreen = dialog()->screenRef("RecordScreen");

	if ( 0 != pScreen )
	{
		// get pointer to softkey
		SlGfwSoftKey* pSoftkey = pScreen->menuSoftkey("vr", nSoftkey);
		
		// enable/disable softkey
		if ( 0 != pSoftkey )
			pSoftkey->setDisabled(bDisabled);
	}
}

bool RecordForm::UninstallUsb(char discId)  //安全拔出可移动硬盘
{  
    HANDLE hDevice; // handle to the drive to be examined   
    BOOL bResult; // results flag   
    DWORD junk; // discard results   
    DWORD dwError;

    char szDriv[10];  
  
    sprintf(szDriv,"\\\\.\\%c:",discId);  

    hDevice = CreateFile(szDriv, // drive to open   
        GENERIC_READ | GENERIC_WRITE,   
        FILE_SHARE_READ | FILE_SHARE_WRITE, // share mode   
        NULL, // default security attributes   
        OPEN_EXISTING, // disposition   
        0, // file attributes   
        NULL); // don't copy any file's attributes   
  
    if (hDevice == INVALID_HANDLE_VALUE) // can't open the drive   
    {   
        dwError = GetLastError();   
        return FALSE;   
    }   
  
    //Dismount the volume   
    bResult = DeviceIoControl(   
        hDevice, // handle to volume   
        IOCTL_STORAGE_EJECT_MEDIA, //eject USB  
        NULL, // lpInBuffer   
        0, // nInBufferSize   
        NULL, // lpOutBuffer   
        0, // nOutBufferSize   
        &junk, // discard count of bytes returned   
        (LPOVERLAPPED) NULL); // synchronous I/O   
    if (!bResult) // IOCTL failed   
    {   
        dwError = GetLastError();   
    }   
  
    // Close the volume handle   
    bResult = CloseHandle(hDevice);   
    if (!bResult)   
    {   
        dwError = GetLastError();   
    }  
    return TRUE;   
}  

void RecordForm::testPlotData()
{
	double x,y1,y2,y3;	
	drawWidget->clearData();
    for (int i=100; i>=0; i--)
    {
		x = i/50.0 - 1;					// x goes from -1 to 1
		y1 = x*x;						// let's plot a quadratic function
 		y2 = sin(x*3.1415);				// let's plot a quadratic function
 		y3 = cos(x*3.1415);				// let's plot a quadratic function
		drawWidget->addData(x,y1,y2,y3);
	}
	m_xMin = -1;	m_xMax = 1;
	m_yMin = -1;	m_yMax = 1;
	drawWidget->setXRange(m_xMin, m_xMax);
	drawWidget->setYRange(m_yMin, m_yMax);     
	drawWidget->setBKColor(QColor(192,192,192));
	drawWidget->repaint();

	RestoreTouchButton->setEnabled(true);
	ZoomInTouchButton->setEnabled(true);
	ZoomOutTouchButton->setEnabled(true);
}

int RecordForm::getFileTotalLines(QString strFile)
{
	int nTotalLines = -1;
	QString line;
	QFile file(strFile);
	if(file.open(QIODevice::ReadOnly))
	{
		QTextStream stream(&file);
		while(!stream.atEnd())
		{		
			line = stream.readLine();
			nTotalLines++;
		}
	}
	file.close();
	return nTotalLines;
}

bool RecordForm::showCurveData_LH(QString strFile)
{
	return showCurveData(strFile,2,3,4,5);

}
bool RecordForm::showCurveData_LV(QString strFile)
{
	return showCurveData(strFile,10,11,12,13);
}

bool RecordForm::showCurveData_RH(QString strFile)
{
	return showCurveData(strFile,18,19,20,21);
}

bool RecordForm::showCurveData_RV(QString strFile)
{
	return showCurveData(strFile,26,27,28,29);
}

bool RecordForm::showCurveData(QString strFile,int xCol,int y1Col,int y2Col,int y3Col)
{
	int TotalLines = getFileTotalLines(strFile);
	int iStep = int(ceil(double(TotalLines)/30000));
	iStep = iStep >= 1 ? iStep : 1;
	int k=0;
	//if(TotalLines > 5000)
	//	return false;

	double yMin=1E10;
	double yMax=-1E10;
	double xMin=1E10;
	double xMax=-1E10;
	QString line;

	QFile file(strFile);
	if(file.open(QIODevice::ReadOnly))
	{
		QTextStream stream(&file);
		stream.setCodec(QTextCodec::codecForName("GBK"));
		drawWidget->clearData();
		while(!stream.atEnd())
		{		
			line = stream.readLine();
			QStringList lineArray = line.split(",");
			if( (lineArray.count() >= 36) && (k%iStep == 0) )
			{
				double x=lineArray[xCol].toDouble();
				double y1 = lineArray[y1Col].toDouble();
				double y2 = lineArray[y2Col].toDouble();
				double y3 = lineArray[y3Col].toDouble();
				drawWidget->addData(x,y1,y2,y3);
				yMin = qMin(yMin, y1);
				yMin = qMin(yMin, y2);
				yMin = qMin(yMin, y3);

				yMax = qMax(yMax, y1);
				yMax = qMax(yMax, y2);
				yMax = qMax(yMax, y3);

				xMin = qMin(xMin, x);
				xMax = qMax(xMax, x);

			}
			k++;
		}
	}
	file.close();
	xMin = xMin > 0 ? floor(xMin) : xMin;
	xMin = xMin < 0 ? floor(xMin) : xMin;
	xMax = xMax > 0 ? ceil(xMax) : xMax;
	xMax = xMax < 0 ? ceil(xMax) : xMax;

	yMin = yMin > 0 ? floor(yMin) : yMin;
	yMin = yMin < 0 ? floor(yMin) : yMin;
	yMax = yMax > 0 ? ceil(yMax) : yMax;
	yMax = yMax < 0 ? ceil(yMax) : yMax;

	drawWidget->setBKColor(QColor(192,192,192));
	m_xMin = xMin;		m_xMax = xMax;
	m_yMin = yMin;		m_yMax = yMax;
	drawWidget->setXRange(m_xMin, m_xMax);
	drawWidget->setYRange(m_yMin, m_yMax);     
	drawWidget->repaint();
	return true;
}

void RecordForm::hideInfoUI()
{
	CreateTimeLabel->setVisible(false);//创建时间
	CreateTimeText->setVisible(false); //
	CurvePosLabel->setVisible(false);  //曲线位置
	CurvePosText->setVisible(false);   //
}

void RecordForm::showInfoUI_LH(QString strFile)
{
	CreateTimeLabel->setVisible(true);
	CreateTimeText->setVisible(true);
	CurvePosLabel->setVisible(true);
	CurvePosText->setVisible(true);

	QFileInfo fileInfo(strFile);
	CreateTimeText->setText(fileInfo.created().toString("yyyy.MM.dd  hh:mm:ss"));
	CurvePosText->setText(readText("LH_Data","workRecord"));
}

void RecordForm::showInfoUI_LV(QString strFile)
{
	CreateTimeLabel->setVisible(true);
	CreateTimeText->setVisible(true);
	CurvePosLabel->setVisible(true);
	CurvePosText->setVisible(true);

	QFileInfo fileInfo(strFile);
	CreateTimeText->setText(fileInfo.created().toString("yyyy.MM.dd  hh:mm:ss"));
	CurvePosText->setText(readText("LV_Data","workRecord"));
}

void RecordForm::showInfoUI_RH(QString strFile)
{
	CreateTimeLabel->setVisible(true);
	CreateTimeText->setVisible(true);
	CurvePosLabel->setVisible(true);
	CurvePosText->setVisible(true);

	QFileInfo fileInfo(strFile);
	CreateTimeText->setText(fileInfo.created().toString("yyyy.MM.dd  hh:mm:ss"));
	CurvePosText->setText(readText("RH_Data","workRecord"));
}

void RecordForm::showInfoUI_RV(QString strFile)
{
	CreateTimeLabel->setVisible(true);
	CreateTimeText->setVisible(true);
	CurvePosLabel->setVisible(true);
	CurvePosText->setVisible(true);

	QFileInfo fileInfo(strFile);
	CreateTimeText->setText(fileInfo.created().toString("yyyy.MM.dd  hh:mm:ss"));
	CurvePosText->setText(readText("RV_Data","workRecord"));
}

void RecordForm::clearCurveData()
{
	drawWidget->clearData();
	drawWidget->repaint();
}
