///////////////////////////////////////////////////////////////////////////////
/*! \file   trainmillingdialog.h
 *  \author
 *  \date
 *  \brief  Definition file for class TrainMillingdialog
 *
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef _H_INCLUDED
#define _H_INCLUDED

#include "slgfwhmidialog.h"
#include <QtCore/QTimer>
#include <QtCore/QCryptographicHash>
#include <QtCore/QFileInfo>
#include <QtCore/QDir>
#include "ScanForm.h"
#include "OperateManualForm.h"
#include "OperateNoticeForm.h"
#include "StatusForm.h"
#include "PowerForm.h"
#include "DebugForm.h"
#include "ErrorForm.h"
#include "ParameterForm.h"
#include "RecordForm.h"
#include "SystemForm.h"
#include "MainForm.h"
#include "StatusListForm.h"
#include "RailCalibForm.h"
#include "POffsetForm.h"
#include "UserManagerForm.h"
#include "onfirmForm.h"
#include "DeviceRepair.h"
#include "SoftLimitForm.h"
#include "OperateIni.h"
#include "GlobalData.h"
#include "ErrorData.h"
#include "QTcuCom.h"
#include "SlQCap.h"
#include "QFile.h"
#include "QTextStream.h"
#include "QMath.h"
#include "QFile.h"
#include "QDateTime.h"
#include "slqmd.h"

//#include "QNetworkInterface.h"
//#include "QList.h"
/*! \class TrainMillingdialog
 *  \brief
 */
class TrainMillingdialog : public SlGfwHmiDialog
{
   Q_OBJECT

public:

   TrainMillingdialog (QObject* pParent = 0, const QString& rsName = 0);
   virtual ~TrainMillingdialog ();

   ///////////////////////////////////////////////////////////////////////////
   // public ACCESSORS
   ///////////////////////////////////////////////////////////////////////////
public:
	SlQCap						  m_capGDServerRead;
	QVector<SlCapReadSpecType>	  m_vecGDReadSpec;
	QVector<SlCapReadResultType>  m_vecGDReadResult;

	SlQCap						  m_capGDServerWrite;

	/*! SlQCapHandle for advise data */
	SlQCap						  m_MillingDataHotlink;
	SlQCap						  m_MillingControlHotlink;
	SlQCap						  m_StatusHotlink;
	SlQCap						  m_IOListHotlink;
	SlQCap						  m_ErrListHotlink;

	SlQCapHandle				  m_MillingDataHandleHotlink;
	SlQCapHandle				  m_MillingControlHandleHotlink;
	SlQCapHandle				  m_StatusHandleHotlink;
	SlQCapHandle				  m_IOListHandleHotlink;
	SlQCapHandle				  m_ErrListHandleHotlink;

	QFile			m_fileRecord;
	QTextStream		m_StreamRecord;
	void			StartRecordData( );
	void			StopRecordData( );

public:
	SlQMd			m_objSlQMd;
	void			readTPValues();

public:
	bool			m_bIsInitial;
	void			IniHotlink();
	void			IniGDReadParameter();
	void			IniGDWriteParameter();
	void			handleRetVal(SlCapErrorEnum eError);
	void			ShowInformation(QString szInfo);
	int				checkDiskSpace();
	bool			checkSerialNumber();
	void			genSerialNumber();
	bool			checkHostMacAddress();
	void			genHostMacAddress();
	QString			getHostMacAddress();
	QString			getSerialNumber();
	bool			checkBothSerialNumber();
	void			genBothSerialNumber();
	bool			deleteDirectoryFiles(QString srcDir);
	bool			GetMAC(LPTSTR lpszMAC);


public slots:
	void			TimeoutSlot();
	void			MillingTimeoutSlot();
	void			ScanTimeoutSlot();
	void			FreshMillingDataSlot(SlCapErrorEnum, const QVector<SlCapAdviseResultType>&);
	void			FreshMillingControlSlot(SlCapErrorEnum, const QVector<SlCapAdviseResultType>&);
	void			FreshStatusSlot(SlCapErrorEnum, const QVector<SlCapAdviseResultType>&);
	void			FreshIOListSlot(SlCapErrorEnum, const QVector<SlCapAdviseResultType>&);
	void			FreshErrListSlot(SlCapErrorEnum, const QVector<SlCapAdviseResultType>&);
public:
	bool			m_bIsScanning;
	bool			m_bIsNewScanData;
	void			StartScan( );
	void			StopScan( );
public:
	bool			m_bIsTrainSpeedIni;
	void			TrainSpeedBtnProcIni( );
	void			TrainSpeedBtnProc( );
private:
	QTimer			m_tmrToggle;
	QTimer			m_tmrMilling;
	QTimer			m_tmrScan;

private:
	void			EmergencyStopProc( );
	void			PLCWorkStateProc( );
	void            PLCShineStateProc( );

private:
	void			WriteWorkingParametersToCNC();
};

#endif // _H_INCLUDED
