#pragma once

#ifndef TCUCOM_H_INCLUDED
#define TCUCOM_H_INCLUDED

#include "QWidget.h"
#include <QtCore/QTimer>
#include "QFile.h"
#include "QTextStream.h"
#include "GlobalVar.h"
#include "winsock2.h"

#define STATUS_ENABLETRAIN_BIT		0x0001
#define STATUS_DEVICELOCK_BIT		0x0002
#define STATUS_WORKSTART_BIT		0x0004
#define STATUS_EMERGENCY_BIT		0x0008
#define STATUS_DEVICEHIGH_BIT		0x0010
#define STATUS_DEVICEERR_BIT		0x0020

class QTcuCom : public QWidget
{
	Q_OBJECT

public:
	QTcuCom(void);
	~QTcuCom(void);

	int TcuComConnect();
	int TcuComDisConnect();

public:
	QTimer		m_tmrToggle;
	SOCKET		m_socket;
	int			m_nHeartBeatCount;
	bool		m_bEnableTCU;
	bool		m_bConnected;

	WORD		m_nCurHeartBeatWord;
	WORD		m_nCurStatusWord;
	WORD		m_nCurWorkMileage_H;
	WORD		m_nCurWorkMileage_L;
	WORD		m_nCurSetSpeed;

	WORD		m_nPreHeartBeatWord;
	WORD		m_nPreStatusWord;
	WORD		m_nPreWorkMileage_H;
	WORD		m_nPreWorkMileage_L;
	WORD		m_nPreSetSpeed;

private slots:
	void		TimeOutSlot( );

public:
	void		SetHeartBeat();
	void		EnableTrain(bool bEnable);
	void		SetTrainSpeed(double fSpeed);
	void		SetWorkMileage(double fWorkMileage);
	void		SetDeviceLockState(bool bLocked);
	void		SetWorkStartState(bool bStart);

	void		SetEmergencyState(bool bEmergency);
	void		SetDeviceHighState(bool bHigh);
	void		SetDeviceErrState(bool bErr);

	int			SendTcuData();
	int			WriteRegister(WORD addr, WORD value);

	void		savelog(const QString& text);

};
#endif // TCUCOM_H_INCLUDED