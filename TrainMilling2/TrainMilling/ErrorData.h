#pragma once

#ifndef ERRORDATA_H_INCLUDED
#define ERRORDATA_H_INCLUDED

#include "SlAeQAlarmPtrList.h"
#include "SlAeQEventSource.h"
#include "slhmimakros.h"
#include "GlobalVar.h"
#include "QWidget.h"
#include "ErrorForm.h"
#include "QSqlDatabase.h"
#include "QSqlError.h"
#include "QSqlQuery.h"

// OEM source-id (>= 100.000) of this HMI event source
#define TM_EVENTSOURCE_SOURCE_ID				100000

#define TM_EVENTSOURCE_LH_PCU_BASE				120000
#define TM_EVENTSOURCE_LH_PCU_BASE_YFELLOW		120000
#define TM_EVENTSOURCE_LH_PCU_BASE_CUTIN		120020
#define TM_EVENTSOURCE_LH_PCU_BASE_MILLING		120040
#define TM_EVENTSOURCE_LH_PCU_BASE_CUTOUT		120060
#define TM_EVENTSOURCE_LH_PCU_BASE_ENDFELLOW	120080

#define TM_EVENTSOURCE_LV_PCU_BASE				120100
#define TM_EVENTSOURCE_LV_PCU_BASE_YFELLOW		120100
#define TM_EVENTSOURCE_LV_PCU_BASE_CUTIN		120120
#define TM_EVENTSOURCE_LV_PCU_BASE_MILLING		120140
#define TM_EVENTSOURCE_LV_PCU_BASE_CUTOUT		120160
#define TM_EVENTSOURCE_LV_PCU_BASE_ENDFELLOW	120180

#define TM_EVENTSOURCE_RH_PCU_BASE				120200
#define TM_EVENTSOURCE_RH_PCU_BASE_YFELLOW		120200
#define TM_EVENTSOURCE_RH_PCU_BASE_CUTIN		120220
#define TM_EVENTSOURCE_RH_PCU_BASE_MILLING		120240
#define TM_EVENTSOURCE_RH_PCU_BASE_CUTOUT		120260
#define TM_EVENTSOURCE_RH_PCU_BASE_ENDFELLOW	120280

#define TM_EVENTSOURCE_RV_PCU_BASE				120300
#define TM_EVENTSOURCE_RV_PCU_BASE_YFELLOW		120300
#define TM_EVENTSOURCE_RV_PCU_BASE_CUTIN		120320
#define TM_EVENTSOURCE_RV_PCU_BASE_MILLING		120340
#define TM_EVENTSOURCE_RV_PCU_BASE_CUTOUT		120360
#define TM_EVENTSOURCE_RV_PCU_BASE_ENDFELLOW	120380

#define TM_EVENTSOURCE_PCU_ENDBASE				120400


#define TM_EVENTSOURCE_PLC_BASE					130000
#define TM_EVENTSOURCE_PLC_BASE_WAITING			130000
#define TM_EVENTSOURCE_PLC_BASE_READY			130100
#define TM_EVENTSOURCE_PLC_BASE_SCAN			130200
#define TM_EVENTSOURCE_PLC_BASE_LOADDOWN1		130300
#define TM_EVENTSOURCE_PLC_BASE_STARTTRAIN1		130400
#define TM_EVENTSOURCE_PLC_BASE_STARTTRAIN2		130500
#define TM_EVENTSOURCE_PLC_BASE_STARTWORK		130600
#define TM_EVENTSOURCE_PLC_BASE_STOPWORK		130700
#define TM_EVENTSOURCE_PLC_BASE_STOPTRAIN		130800
#define TM_EVENTSOURCE_PLC_BASE_LOADDOWN2		130900
#define TM_EVENTSOURCE_PLC_BASE_DEVICEUP		131000
#define TM_EVENTSOURCE_PLC_BASE_EMERGENCY		131100
#define TM_EVENTSOURCE_PLC_BASE_REPAIR			131200

#define TM_EVENTSOURCE_PLC_ENDBASE				131300

#define TM_EVENTSOURCE_LACKSPACEALARM			140000
#define TM_EVENTSOURCE_LICENSEALARM				140001
#define TM_EVENTSOURCE_TCUCOMALARM				140002
#define TM_EVENTSOURCE_PCUCOMALARM				140003
#define TM_EVENTSOURCE_STOPWORKALARM			140004

#define SHOW									1
#define SHOW_AND_TERMINATE						2
#define SHOW_AND_BITCLEAR						3
#define SHOW_TERMINATE_STOP						4

#define LOW_ACTIVE								false
#define HIGH_ACTIVE								true

#define MASK									true
#define NOMASK									false

#define ERRBITCOUNT								67
#define MEERBITCOUNT							8

class ErrorData : public QWidget
{
	Q_OBJECT

public:
	ErrorData(void);
	~ErrorData(void);

public:

	bool				m_CurErrSignals[ERRBITCOUNT];
	bool				m_PreErrSignals[ERRBITCOUNT];
	bool				m_SignalActive[ERRBITCOUNT];
	bool				m_ErrMask[ERRBITCOUNT];
	int					m_ErrLevel[ERRBITCOUNT];

	long				m_nErrorCode;
	long				m_nCNCConnectionError;

    SlAeQAlarmPtrList*	m_pQAlarmPtrList;//报警列表订阅
    SlAeQEventSource*   m_pQEventSource; //报警源

public:
	//QString			m_strSep;
	QStringList			m_nstrErrList;
	bool				SaveAlarmItem(QString szId,QString szDateTime,QString szState,QString szText,QString szWorkState);

public:
	QSqlDatabase	m_DataBase;
	bool			createDataFile(const QString &strFileName);  
	bool			isExistTable(const QString& strTableName);
	bool			OpenDataBase( );
	void			DeleteOutDatedItems( );
	void			CloseDataBase( );
	bool			SaveAlarmItemToDataBase(QString number,QString datetime,QString state, QString alarmtext,QString workstate );

public:
	void processPLCAlarms( );
	void createPLCAlarms( );
	void createPLCAlarm( int index );
	void clearPLCAlarm( int index );
	void clearTypePLCAlarms( int index );

public:
	void createPCUAlarms( );
	void createPCUAlarm( int index );
	void clearTypePCUAlarms( );
	void clearPCUAlarm( int index );

public:
	void createLackSpaceAlarm();
	void createLicenseAlarm();
	void createTCUCOMAlarm();
	void createPCUCOMAlarm();
	void createStopWorkAlarm();
public slots:
    void onListChanged( );
    void eventAcknowledged(const SlAeEvent&);
    void cancelAlarms(const long);
    void cancelAlarmGroup(const long);
    void alarmCanceled(const long, const SlAeEvent&);

public:
	void EventSourceIni( );
	void EventListIni( );
	void EventListActive();
	void EventListDeActive();
	void createGoingEvents(const long lCancelGroup);

public:
	void IniErrMask();
	void IniErrLevel();
	void IniSignalActive();

public:
	QString GetErrorWorkState(int ErrID);
};

#endif // ERRORDATA_H_INCLUDED