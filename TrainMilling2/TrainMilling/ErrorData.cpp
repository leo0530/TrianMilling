#include "ErrorData.h"

ErrorData::ErrorData(void)
{
	m_nErrorCode = 0x0000;
	m_nCNCConnectionError = 0x0001;
    m_pQAlarmPtrList = 0;
    m_pQEventSource = 0;
	//memset(m_CurErrSignals,false,sizeof(m_CurErrSignals));
	//memset(m_PreErrSignals,false,sizeof(m_PreErrSignals));
	IniErrLevel( );
	IniSignalActive();
	IniErrMask();
	EventSourceIni( );
	EventListIni( );
	EventListActive( );
	//m_strSep = "hqy";
	OpenDataBase( );
 	DeleteOutDatedItems( );
	m_nstrErrList.clear();
}

ErrorData::~ErrorData(void)
{
	// check null pointer
    if ( 0 != m_pQAlarmPtrList )
    {
        // finalize the alarm list class
        m_pQAlarmPtrList->fini();

        // delete the alarm list class
        delete m_pQAlarmPtrList;
        m_pQAlarmPtrList = 0;
    }

	// check null pointer
    if( 0 != m_pQEventSource )
    {
        // deactivate and finalize the event source class
		m_pQEventSource->deactivate();
	    m_pQEventSource->fini();

        // delete the event source class
	    delete m_pQEventSource;
	    m_pQEventSource = 0;
    }
	//SaveErrToDataBase( );
	CloseDataBase( );
	m_nstrErrList.clear();
}

void ErrorData::processPLCAlarms( )
{
	int ErrBitCount = ERRBITCOUNT;				
	SlQCap nWriteServer;
	SlCapErrorEnum nError;
	for(int nErrIndex=0 ; nErrIndex<ErrBitCount ; nErrIndex++){
		bool CurErrBit = m_CurErrSignals[nErrIndex];
		bool PreErrBit = m_PreErrSignals[nErrIndex];
		bool SignalActive = m_SignalActive[nErrIndex];
		bool ErrMask = m_ErrMask[nErrIndex];
		int  ErrLevel = m_ErrLevel[nErrIndex];

		if( (ErrMask == NOMASK) && (PreErrBit != SignalActive) && (CurErrBit == SignalActive) ){
			switch(ErrLevel)
			{
			case SHOW:
				break;
			case SHOW_AND_TERMINATE:
				//if( g->m_nWorkState != WORKSTATE_NULL )
				//	g->SetPCUWorkState(WORKSTATE_EMERGENCY_PLC);
				break;
			case SHOW_AND_BITCLEAR:
				nError = nWriteServer.write(szItem_InvalidPress_Bit,QVariant(0));
				break;
			case SHOW_TERMINATE_STOP:
				//if( g->m_nWorkState != WORKSTATE_NULL )
				//	g->SetPCUWorkState(WORKSTATE_EMERGENCY_PLC);
				//Send Stop Train COmmand
				break;
			default:
				break;
			}
		}
	}
}

void ErrorData::createPLCAlarms( )
{
	int ErrBitCount = ERRBITCOUNT;				
	int subBaseIndex;
	switch(g->m_nPLCWorkState)
	{
	case PLC_WORKSTATE_WAITING:		
		subBaseIndex = 0;
		break;
	case PLC_WORKSTATE_READY:
		subBaseIndex = 100;
		break;
	case PLC_WORKSTATE_SCAN:		
		subBaseIndex = 200;
		break;
	case PLC_WORKSTATE_LOADDOWN1:		
		subBaseIndex = 300;
		break;
	case PLC_WORKSTATE_STARTTRAIN1:		
		subBaseIndex = 400;
		break;
	case PLC_WORKSTATE_STARTTRAIN2:		
		subBaseIndex = 500;
		break;
	case PLC_WORKSTATE_STARTWORK:	
		subBaseIndex = 600;
		break;
	case PLC_WORKSTATE_STOPWORK:		
		subBaseIndex = 700;
		break;
	case PLC_WORKSTATE_STOPTRAIN:			
		subBaseIndex = 800;
		break;
	case PLC_WORKSTATE_LOADDOWN2:			
		subBaseIndex = 900;
		break;
	case PLC_WORKSTATE_DEVICEUP:
		subBaseIndex = 1000;
		break;
	case PLC_WORKSTATE_EMERGENCY:		
		subBaseIndex = 1100;
		break;
	case PLC_WORKSTATE_REPAIR:	
		subBaseIndex = 1200;
		break;
	default:
		subBaseIndex = 0;
		break;
	}
	for(int nErrIndex=0 ; nErrIndex<ErrBitCount ; nErrIndex++)
	{
		bool CurErrBit = m_CurErrSignals[nErrIndex];
		bool PreErrBit = m_PreErrSignals[nErrIndex];
		bool SignalActive = m_SignalActive[nErrIndex];
		bool ErrMask = m_ErrMask[nErrIndex];
		if( (ErrMask == NOMASK) && (PreErrBit != SignalActive) && (CurErrBit == SignalActive) )
			createPLCAlarm( TM_EVENTSOURCE_PLC_BASE + subBaseIndex + nErrIndex );

		if( (ErrMask == NOMASK) && (PreErrBit == SignalActive) && (CurErrBit != SignalActive) )
			//clearPLCAlarm( TM_EVENTSOURCE_PLC_BASE + subBaseIndex + nErrIndex );
			clearTypePLCAlarms(nErrIndex);
	}
}

void ErrorData::createPLCAlarm( int index)
{
	if( 0 != m_pQEventSource ){
		long lError = 0;

		SlAeEvent aeEvent;

		aeEvent.setAlarmId(index);
		aeEvent.setSourceId(TM_EVENTSOURCE_SOURCE_ID);
		aeEvent.setAlarmState(SLAE_ALARM_COMING);
		aeEvent.setCategory(SLAE_EV_CAT_SINUMERIK_HMI);

		lError = m_pQEventSource->createEvent(aeEvent);
	}
}

void ErrorData::clearPLCAlarm( int index )
{
	if( 0 != m_pQEventSource ){
		long lError = 0;
		SlAeEvent aeEvent;

		aeEvent.setAlarmId(index);
		aeEvent.setSourceId(TM_EVENTSOURCE_SOURCE_ID);
		aeEvent.setAlarmState(SLAE_ALARM_CAME_GOING);
		aeEvent.setCategory(SLAE_EV_CAT_SINUMERIK_HMI);
		lError = m_pQEventSource->createEvent(aeEvent);
	}
}


void ErrorData::clearTypePLCAlarms( int index )
{
	//Tips:"This Button is unused in this state!"
	if( index == 1)
		return;

	for(int i=0 ; i<13; i++)
	{
		int subBaseIndex = i*100;
		clearPLCAlarm(TM_EVENTSOURCE_PLC_BASE + subBaseIndex + index );
	}
}


void ErrorData::createPCUAlarms( )
{
	int BaseIndex;
	int subBaseIndex;
	switch(g->m_nPreWorkState)
	{
	case WORKSTATE_NULL:			
	case WORKSTATE_STARTFELLOW_INI:
	case WORKSTATE_STARTFELLOW:		
	case WORKSTATE_ADJUST_INI:		
	case WORKSTATE_ADJUST:		
	case WORKSTATE_YFELLOW_INI:		
	case WORKSTATE_YFELLOW:	
		subBaseIndex = 0;
		break;
	case WORKSTATE_WORKIN_INI:		
	case WORKSTATE_WORKIN:			
	case WORKSTATE_CUTIN_INI:			
	case WORKSTATE_CUTIN:
		subBaseIndex = 20;
		break;
	case WORKSTATE_MILLING_INI:		
	case WORKSTATE_MILLING:	
		subBaseIndex = 40;
		break;
	case WORKSTATE_CUTOUT_INI:		
	case WORKSTATE_CUTOUT:			
	case WORKSTATE_WORKOUT_INI:		
	case WORKSTATE_WORKOUT:			
		subBaseIndex = 60;
		break;
	case WORKSTATE_YFELLOW2_INI:		
	case WORKSTATE_YFELLOW2:	
	case WORKSTATE_ENDFELLOW_INI:		
	case WORKSTATE_ENDFELLOW:
		subBaseIndex = 80;
		break;
	default:
		subBaseIndex = 0;
		break;
	}
	//for g->m_LH_Error
	if(g->m_LH_Error != 0){
		BaseIndex = TM_EVENTSOURCE_LH_PCU_BASE;
		for(int i=0 ; i<16 ;i++){
			bool theBit = (g->m_LH_Error >> i) & 0x0001;
			if( theBit ){
				int ErrIndex = BaseIndex + subBaseIndex + i;
				createPCUAlarm( ErrIndex );
			}
		}
	}
	//for g->m_LV_Error
	if(g->m_LV_Error != 0){
		BaseIndex = TM_EVENTSOURCE_LV_PCU_BASE;
		for(int i=0 ; i<16 ;i++){
			bool theBit = (g->m_LV_Error >> i) & 0x0001;
			if( theBit ){
				int ErrIndex = BaseIndex + subBaseIndex + i;
				createPCUAlarm( ErrIndex );
			}
		}
	}
	//for g->m_RH_Error
	if(g->m_RH_Error != 0){
		BaseIndex = TM_EVENTSOURCE_RH_PCU_BASE;
		for(int i=0 ; i<16 ;i++){
			bool theBit = (g->m_RH_Error >> i) & 0x0001;
			if( theBit ){
				int ErrIndex = BaseIndex + subBaseIndex + i;
				createPCUAlarm( ErrIndex );
			}
		}
	}	
	//for g->m_RV_Error
	if(g->m_RV_Error != 0){
		BaseIndex = TM_EVENTSOURCE_RV_PCU_BASE;
		for(int i=0 ; i<16 ;i++){
			bool theBit = (g->m_RV_Error >> i) & 0x0001;
			if( theBit ){
				int ErrIndex = BaseIndex + subBaseIndex + i;
				createPCUAlarm( ErrIndex );
			}
		}
	}	
}

void ErrorData::clearTypePCUAlarms(  )
{
	int BaseIndex;
	int subBaseIndex;
	for(int k=0 ; k<5; k++)
	{
		subBaseIndex = k*20;
		//for g->m_LH_Error
		if(g->m_LH_Error != 0){
			BaseIndex = TM_EVENTSOURCE_LH_PCU_BASE;
			for(int i=0 ; i<16 ;i++){
				bool theBit = (g->m_LH_Error >> i) & 0x0001;
				if( theBit ){
					int ErrIndex = BaseIndex + subBaseIndex + i;
					clearPCUAlarm( ErrIndex );
				}
			}
		}
		//for g->m_LV_Error
		if(g->m_LV_Error != 0){
			BaseIndex = TM_EVENTSOURCE_LV_PCU_BASE;
			for(int i=0 ; i<16 ;i++){
				bool theBit = (g->m_LV_Error >> i) & 0x0001;
				if( theBit ){
					int ErrIndex = BaseIndex + subBaseIndex + i;
					clearPCUAlarm( ErrIndex );
				}
			}
		}
		//for g->m_RH_Error
		if(g->m_RH_Error != 0){
			BaseIndex = TM_EVENTSOURCE_RH_PCU_BASE;
			for(int i=0 ; i<16 ;i++){
				bool theBit = (g->m_RH_Error >> i) & 0x0001;
				if( theBit ){
					int ErrIndex = BaseIndex + subBaseIndex + i;
					clearPCUAlarm( ErrIndex );
				}
			}
		}	
		//for g->m_RV_Error
		if(g->m_RV_Error != 0){
			BaseIndex = TM_EVENTSOURCE_RV_PCU_BASE;
			for(int i=0 ; i<16 ;i++){
				bool theBit = (g->m_RV_Error >> i) & 0x0001;
				if( theBit ){
					int ErrIndex = BaseIndex + subBaseIndex + i;
					clearPCUAlarm( ErrIndex );
				}
			}
		}
	}
	g->m_LH_Error = REPORT_NO_ERR;
	g->m_LV_Error = REPORT_NO_ERR;
	g->m_RH_Error = REPORT_NO_ERR;
	g->m_RV_Error = REPORT_NO_ERR;
}

void ErrorData::createPCUAlarm( int index )
{
	if( 0 != m_pQEventSource ){
		long lError = 0;
		SlAeEvent aeEvent;

		aeEvent.setAlarmId(index);
		aeEvent.setSourceId(TM_EVENTSOURCE_SOURCE_ID);
		aeEvent.setAlarmState(SLAE_ALARM_COMING);
		aeEvent.setCategory(SLAE_EV_CAT_SINUMERIK_HMI);
		lError = m_pQEventSource->createEvent(aeEvent);
	}
}

void ErrorData::clearPCUAlarm( int index )
{
	if( 0 != m_pQEventSource ){
		long lError = 0;
		SlAeEvent aeEvent;

		aeEvent.setAlarmId(index);
		aeEvent.setSourceId(TM_EVENTSOURCE_SOURCE_ID);
		aeEvent.setAlarmState(SLAE_ALARM_CAME_GOING);
		aeEvent.setCategory(SLAE_EV_CAT_SINUMERIK_HMI);
		lError = m_pQEventSource->createEvent(aeEvent);
	}
}


void ErrorData::createLackSpaceAlarm()
{
	if( 0 != m_pQEventSource ){
		long lError = 0;
		SlAeEvent aeEvent;

		aeEvent.setAlarmId(TM_EVENTSOURCE_LACKSPACEALARM);
		aeEvent.setSourceId(TM_EVENTSOURCE_SOURCE_ID);
		aeEvent.setAlarmState(SLAE_ALARM_COMING);
		aeEvent.setCategory(SLAE_EV_CAT_SINUMERIK_HMI);
		lError = m_pQEventSource->createEvent(aeEvent);
	}
}

void ErrorData::createLicenseAlarm()
{
	if( 0 != m_pQEventSource ){
		long lError = 0;
		SlAeEvent aeEvent;

		aeEvent.setAlarmId(TM_EVENTSOURCE_LICENSEALARM);
		aeEvent.setSourceId(TM_EVENTSOURCE_SOURCE_ID);
		aeEvent.setAlarmState(SLAE_ALARM_COMING);
		aeEvent.setCategory(SLAE_EV_CAT_SINUMERIK_HMI);
		lError = m_pQEventSource->createEvent(aeEvent);
	}
}

void ErrorData::createTCUCOMAlarm()
{
	if( 0 != m_pQEventSource ){
		long lError = 0;
		SlAeEvent aeEvent;

		aeEvent.setAlarmId(TM_EVENTSOURCE_TCUCOMALARM);
		aeEvent.setSourceId(TM_EVENTSOURCE_SOURCE_ID);
		aeEvent.setAlarmState(SLAE_ALARM_COMING);
		aeEvent.setCategory(SLAE_EV_CAT_SINUMERIK_HMI);
		lError = m_pQEventSource->createEvent(aeEvent);
	}
}

void ErrorData::createPCUCOMAlarm()
{
	if( 0 != m_pQEventSource ){
		long lError = 0;
		SlAeEvent aeEvent;

		aeEvent.setAlarmId(TM_EVENTSOURCE_PCUCOMALARM);
		aeEvent.setSourceId(TM_EVENTSOURCE_SOURCE_ID);
		aeEvent.setAlarmState(SLAE_ALARM_COMING);
		aeEvent.setCategory(SLAE_EV_CAT_SINUMERIK_HMI);
		lError = m_pQEventSource->createEvent(aeEvent);
	}
}

void ErrorData::createStopWorkAlarm()
{
	if( 0 != m_pQEventSource ){
		long lError = 0;
		SlAeEvent aeEvent;

		aeEvent.setAlarmId(TM_EVENTSOURCE_STOPWORKALARM);
		aeEvent.setSourceId(TM_EVENTSOURCE_SOURCE_ID);
		aeEvent.setAlarmState(SLAE_ALARM_COMING);
		aeEvent.setCategory(SLAE_EV_CAT_SINUMERIK_HMI);
		lError = m_pQEventSource->createEvent(aeEvent);
	}
}

void ErrorData::EventListIni( )
{
     long            lError = 0;
   // create an instance of the alarm list class
    m_pQAlarmPtrList = new SlAeQAlarmPtrList(this);

    // check null pointer
    if ( 0 != m_pQAlarmPtrList )
    {
		// initialize the alarm list 
        lError = m_pQAlarmPtrList->init();

        if ( SL_SUCCEEDED(lError) )
        {
            // set sorting
			lError = m_pQAlarmPtrList->setSorting(SLAE_SORTBY_TIMESTAMP, 
											      SLAE_ORDER_DESCENDING);

			if( SL_SUCCEEDED(lError) )
			{
				// create the list of additional return attributes which we want to recieve with each alarm
				SlAeIdsList attributes2Subscribe;
				// add the attribute alarm text
                attributes2Subscribe.push_back(SLAE_EV_ATTR_MSGTEXT);
                attributes2Subscribe.push_back(SLAE_EV_ATTR_CANCELGROUP);


				// query all known alarm categories
				SlAeCategoryInfoArray rCategories;
				rCategories.clear();
				lError = m_pQAlarmPtrList->queryCategories(rCategories);
				if(SL_SUCCEEDED(lError))
				{
					SlAeCategoryInfoArray::Iterator it;

					// iterate over all known alarm categories ...
					for(it = rCategories.begin(); it != rCategories.end(); ++it)
					{
						// ... and set the return attributes we want to recieve with each alarm
						lError = m_pQAlarmPtrList->setReturnAttributes((*it).m_nId, attributes2Subscribe);
						if(!SL_SUCCEEDED(lError))
						{
							// error
						}
					}
				}
				else
				{
					// error
				}

				// connect with the signal "alarmListChanged" of the alarm list 
                QObject::connect(m_pQAlarmPtrList, SIGNAL(listChanged()),
						         this, SLOT(onListChanged()));
			}
			else
			{
			    // error
			}
        }
        else
        {
			// error
        }
    }
}

void ErrorData::EventSourceIni( )
{
    // create an instance of the event source class
	m_pQEventSource = new SlAeQEventSource();

    // initialize the event source with the source-id
    if ( SL_SUCCEEDED(m_pQEventSource->init(TM_EVENTSOURCE_SOURCE_ID)) )
	{
		// activate source
		if ( SL_SUCCEEDED(m_pQEventSource->activate()) )
		{
			// connect with the signal "eventAcknowledged" of the event source
			connect(m_pQEventSource, SIGNAL(eventAcknowledged(const SlAeEvent&)),
				    this, SLOT(eventAcknowledged(const SlAeEvent&)));

			// connect with the signal "cancelAlarms" of the event source
			connect(m_pQEventSource, SIGNAL(cancelAlarms(const long)),
				    this, SLOT(cancelAlarms(const long)));

			// connect with the signal "cancelAlarmGroup" of the event source
			connect(m_pQEventSource, SIGNAL(cancelAlarmGroup(const long)),
				    this, SLOT(cancelAlarmGroup(const long)));

			// connect with the signal "alarmCanceled" of the event source
			connect(m_pQEventSource, SIGNAL(alarmCanceled(const long, const SlAeEvent&)),
				    this, SLOT(alarmCanceled(const long, const SlAeEvent&)));
		}
		else
		{
			// error
		}
	}
    else
    {
        // error
    }
}

void ErrorData::eventAcknowledged(const SlAeEvent& rEvent)
{

}

void ErrorData::cancelAlarms(const long lFlags)
{

}


void ErrorData::cancelAlarmGroup(const long lCancelGroup)
{
    createGoingEvents(lCancelGroup);
}


void ErrorData::alarmCanceled(const long lFlags, const SlAeEvent& rEvent)
{

}

void ErrorData::createGoingEvents(const long lCancelGroup)
{
    QList<SlAeEvent*>*              pList = m_pQEventSource->getList();
    QListIterator<SlAeEvent*>       it(*pList);

    // set the iterator before the first element
    it.toFront();
    // iterate over every element of the internal list of all my created HMI alarms
    while(it.hasNext())
    {
        SlAeEvent*  pAEEvent = it.next();
        SlAeEvent*  pAEEventClone = 0;
        QVariant    vCancelGroup;
        long        lState;
        bool        bDoCreateEvent = true;

        // get the cancel group of the iterated alarm.
        vCancelGroup = pAEEvent->getAttribute(SLAE_EV_ATTR_CANCELGROUP);
        
        if ( lCancelGroup == vCancelGroup.toLongLong() )
        {// only if we found an alarm with the correct cancel group

            // clone the alarm
            pAEEventClone = pAEEvent->clone();
            
            // get the current state of this alarm
            lState = pAEEventClone->getAlarmState();

            bDoCreateEvent = true; 

            // depending on the current state of the alarm set the correct going-state for the event.

            if ( SLAE_ALARM_HMI_CANCEL_BTN_COMING == (SLAE_ALARM_HMI_CANCEL_BTN_COMING & lState) )
            {// "HMI cancel button" alarm
                pAEEventClone->setAlarmState(SLAE_ALARM_HMI_CANCEL_BTN_CAME_GOING);
            }
            else if ( SLAE_ALARM_HMI_CANCEL_TIME_COMING == (SLAE_ALARM_HMI_CANCEL_TIME_COMING & lState) )
            {// "HMI cancel time" alarm
                pAEEventClone->setAlarmState(SLAE_ALARM_HMI_CANCEL_TIME_CAME_GOING);
            }
            else if ( SLAE_ALARM_COMING_TOACK == (SLAE_ALARM_COMING_TOACK & lState) )
            {// acknowledgeable alarm - not acknowledged and not gone up to now
                pAEEventClone->setAlarmState(SLAE_ALARM_CAME_GOING_TOACK);
            }
            else if ( SLAE_ALARM_CAME_ACKING == (SLAE_ALARM_CAME_ACKING & lState) )
            {// acknowledgeable alarm - acknowledged and not gone up to now
                pAEEventClone->setAlarmState(SLAE_ALARM_CAME_ACKED_GOING);
            }
            else if ( SLAE_ALARM_COMING == (SLAE_ALARM_COMING & lState) )
            {// non acknowledgeable alarm
                pAEEventClone->setAlarmState(SLAE_ALARM_CAME_GOING);
            }
            else
            {
                bDoCreateEvent = false;
            }

            if (bDoCreateEvent)
            {
                // create the going-event 
                long lError = m_pQEventSource->createEvent(*pAEEventClone);
            }

            delete pAEEventClone;
            pAEEventClone = 0;
        }
    }
}

void ErrorData::onListChanged( )
{
	if( 0 == g_pErrorForm ){
		QDateTime				dt;
		QString					szId;
		QString					szDateTime;
		QString					szState;
		QString					szText;
		QString					szWorkState;

		QVariant				vTmp;
		int                     nNrOfAlarms = 0;
		// check null pointer
		if ( 0 != m_pQAlarmPtrList ) 
		{
			// get the current size of the event list (QAlarmPtrList)
			nNrOfAlarms = m_pQAlarmPtrList->getList()->size();

			QList<SlAeEvent*>::iterator it;

			for(it = m_pQAlarmPtrList->getList()->begin(); it != m_pQAlarmPtrList->getList()->end(); ++it)
			{
				SlAeEvent* pAEEvent = *it;

				// get the alarm number of the alarm list and add it to a cell of a SlGfwTreeWidgetItem 
				szId = szId.setNum(pAEEvent->getAlarmId());
				szWorkState = GetErrorWorkState(pAEEvent->getAlarmId());
 
				// get the date and time of the alarm list and add it to a cell of a SlGfwTreeWidgetItem 
				dt = pAEEvent->getTimestamp();
				szDateTime = dt.toString("yyyy.MM.dd  hh:mm:ss");

				// get the event state of the event list and add it to a cell of a SlGfwTreeWidgetItem 
				szState = szState.setNum(pAEEvent->getAlarmState());

				// get the alarm text of the alarm list and add it to a cell of a SlGfwTreeWidgetItem 
				// note: the alarm text is an additional return attribute
				vTmp = pAEEvent->getAttribute(SLAE_EV_ATTR_MSGTEXT);
				szText = vTmp.toString();

				SaveAlarmItem(szId,szDateTime,szState,szText,szWorkState);//save alarm info

				pAEEvent = 0;
			}
		}
	}
	if( 0 != g_pErrorForm ){
		g_pErrorForm->onListChanged( );
	}
}

bool ErrorData::SaveAlarmItem(QString szId,QString szDateTime,QString szState,QString szText,QString szWorkState)
{
	bool bNewItem = true;
	int TotalCount = m_nstrErrList.count() / 5;
	for(int i=0; i<TotalCount ;i++) //查询列表中是否已经存在该条告警信息。check if had the same alarm item in the list
	{
		int j = 5*i;
		QString inumber = m_nstrErrList.at(j++);
		QString idatetime = m_nstrErrList.at(j++);
		QString istate = m_nstrErrList.at(j++);
		QString ialarmtext = m_nstrErrList.at(j++);

		if( szId==inumber && szDateTime==idatetime && szState==istate && szText==ialarmtext){
			bNewItem = false;
			break;
		}
	}

	if(bNewItem)
	{
		m_nstrErrList.append(szId);//编号
		m_nstrErrList.append(szDateTime);//时间
		m_nstrErrList.append(szState);//状态
		m_nstrErrList.append(szText);//告警文本
		m_nstrErrList.append(szWorkState);//工作状态
		SaveAlarmItemToDataBase(szId,szDateTime,szState,szText,szWorkState );
	}
	return bNewItem;

	/*
	bool bNewItem = true;
	int TotalCount = m_nstrErrList.count();
	for(int i=0; i<TotalCount ;i++)
	{
		QStringList item = m_nstrErrList.at(i).split(m_strSep);
		QString inumber = item.at(0);
		QString idatetime = item.at(1);
		QString istate = item.at(2);
		QString ialarmtext = item.at(3);

		if( szId==inumber && szDateTime==idatetime && szState==istate && szText==ialarmtext){
			bNewItem = false;
			break;
		}
	}

	if(bNewItem)
	{
		QString szAlarm = szId + m_strSep + szDateTime + m_strSep + szState + m_strSep + szText + m_strSep + szWorkState;
		m_nstrErrList.append(szAlarm);
		SaveAlarmItemToDataBase(szId,szDateTime,szState,szText,szWorkState );
	}
	return bNewItem;
	*/
}

void ErrorData::EventListActive( )
{
	// check null pointer
    if ( 0 != m_pQAlarmPtrList )
    {
        // activate the alarm list 
        m_pQAlarmPtrList->activate();
    }

}

void ErrorData::EventListDeActive( )
{
	// check null pointer
    if ( 0 != m_pQAlarmPtrList )
    {
        // deactivate the alarm list 
        m_pQAlarmPtrList->deactivate();
    }

}

QString ErrorData::GetErrorWorkState(int ErrID)
{
	QString retStr;
	if( (ErrID >= TM_EVENTSOURCE_LH_PCU_BASE_YFELLOW && ErrID < TM_EVENTSOURCE_LH_PCU_BASE_CUTIN) ||
		(ErrID >= TM_EVENTSOURCE_LV_PCU_BASE_YFELLOW && ErrID < TM_EVENTSOURCE_LV_PCU_BASE_CUTIN) ||
		(ErrID >= TM_EVENTSOURCE_RH_PCU_BASE_YFELLOW && ErrID < TM_EVENTSOURCE_RH_PCU_BASE_CUTIN) ||
		(ErrID >= TM_EVENTSOURCE_RV_PCU_BASE_YFELLOW && ErrID < TM_EVENTSOURCE_RV_PCU_BASE_CUTIN) )
		retStr = g_pIni->m_strStateYFellow;

	else if( (ErrID >= TM_EVENTSOURCE_LH_PCU_BASE_CUTIN && ErrID < TM_EVENTSOURCE_LH_PCU_BASE_MILLING) ||
		(ErrID >= TM_EVENTSOURCE_LV_PCU_BASE_CUTIN && ErrID < TM_EVENTSOURCE_LV_PCU_BASE_MILLING) ||
		(ErrID >= TM_EVENTSOURCE_RH_PCU_BASE_CUTIN && ErrID < TM_EVENTSOURCE_RH_PCU_BASE_MILLING) ||
		(ErrID >= TM_EVENTSOURCE_RV_PCU_BASE_CUTIN && ErrID < TM_EVENTSOURCE_RV_PCU_BASE_MILLING ) )
		retStr = g_pIni->m_strStateCutIn;

	else if( (ErrID >= TM_EVENTSOURCE_LH_PCU_BASE_MILLING && ErrID < TM_EVENTSOURCE_LH_PCU_BASE_CUTOUT) ||
		(ErrID >= TM_EVENTSOURCE_LV_PCU_BASE_MILLING && ErrID < TM_EVENTSOURCE_LV_PCU_BASE_CUTOUT) ||
		(ErrID >= TM_EVENTSOURCE_RH_PCU_BASE_MILLING && ErrID < TM_EVENTSOURCE_RH_PCU_BASE_CUTOUT) ||
		(ErrID >= TM_EVENTSOURCE_RV_PCU_BASE_MILLING && ErrID < TM_EVENTSOURCE_RV_PCU_BASE_CUTOUT) )
		retStr = g_pIni->m_strStateMilling;

	else if( (ErrID >= TM_EVENTSOURCE_LH_PCU_BASE_CUTOUT && ErrID < TM_EVENTSOURCE_LH_PCU_BASE_ENDFELLOW) ||
		(ErrID >= TM_EVENTSOURCE_LV_PCU_BASE_CUTOUT && ErrID < TM_EVENTSOURCE_LV_PCU_BASE_ENDFELLOW) ||
		(ErrID >= TM_EVENTSOURCE_RH_PCU_BASE_CUTOUT && ErrID < TM_EVENTSOURCE_RH_PCU_BASE_ENDFELLOW) ||
		(ErrID >= TM_EVENTSOURCE_RV_PCU_BASE_CUTOUT && ErrID < TM_EVENTSOURCE_RV_PCU_BASE_ENDFELLOW) )
		retStr = g_pIni->m_strStateCutOut;

	else if( (ErrID >= TM_EVENTSOURCE_LH_PCU_BASE_ENDFELLOW && ErrID < TM_EVENTSOURCE_LV_PCU_BASE) ||
		(ErrID >= TM_EVENTSOURCE_LV_PCU_BASE_ENDFELLOW && ErrID < TM_EVENTSOURCE_RH_PCU_BASE) ||
		(ErrID >= TM_EVENTSOURCE_RH_PCU_BASE_ENDFELLOW && ErrID < TM_EVENTSOURCE_RV_PCU_BASE) ||
		(ErrID >= TM_EVENTSOURCE_RV_PCU_BASE_ENDFELLOW && ErrID < TM_EVENTSOURCE_PCU_ENDBASE) )
		retStr = g_pIni->m_strStateEndFellow;

	else if(ErrID >= TM_EVENTSOURCE_PLC_BASE_WAITING && ErrID < TM_EVENTSOURCE_PLC_BASE_READY)
		retStr = g_pIni->m_strStateWaiting;

	else if(ErrID >= TM_EVENTSOURCE_PLC_BASE_READY && ErrID < TM_EVENTSOURCE_PLC_BASE_SCAN)
		retStr = g_pIni->m_strStateReady;

	else if(ErrID >= TM_EVENTSOURCE_PLC_BASE_SCAN && ErrID < TM_EVENTSOURCE_PLC_BASE_LOADDOWN1)
		retStr = g_pIni->m_strStateScan;

	else if(ErrID >= TM_EVENTSOURCE_PLC_BASE_LOADDOWN1 && ErrID < TM_EVENTSOURCE_PLC_BASE_STARTTRAIN1)
		retStr = g_pIni->m_strStateLoadDown1;

	else if(ErrID >= TM_EVENTSOURCE_PLC_BASE_STARTTRAIN1 && ErrID < TM_EVENTSOURCE_PLC_BASE_STARTTRAIN2)
		retStr = g_pIni->m_strStateStartTrain1;

	else if(ErrID >= TM_EVENTSOURCE_PLC_BASE_STARTTRAIN2 && ErrID < TM_EVENTSOURCE_PLC_BASE_STARTWORK)
		retStr = g_pIni->m_strStateStartTrain2;

	else if(ErrID >= TM_EVENTSOURCE_PLC_BASE_STARTWORK && ErrID < TM_EVENTSOURCE_PLC_BASE_STOPWORK)
		retStr = g_pIni->m_strStateStartWork;

	else if(ErrID >= TM_EVENTSOURCE_PLC_BASE_STOPWORK && ErrID < TM_EVENTSOURCE_PLC_BASE_STOPTRAIN)
		retStr = g_pIni->m_strStateStopWork;

	else if(ErrID >= TM_EVENTSOURCE_PLC_BASE_STOPTRAIN && ErrID < TM_EVENTSOURCE_PLC_BASE_LOADDOWN2)
		retStr = g_pIni->m_strStateStopTrain;

	else if(ErrID >= TM_EVENTSOURCE_PLC_BASE_LOADDOWN2 && ErrID < TM_EVENTSOURCE_PLC_BASE_DEVICEUP)
		retStr = g_pIni->m_strStateLoadDown2;

	else if(ErrID >= TM_EVENTSOURCE_PLC_BASE_DEVICEUP && ErrID < TM_EVENTSOURCE_PLC_BASE_EMERGENCY)
		retStr = g_pIni->m_strStateDeviceUp;

	else if(ErrID >= TM_EVENTSOURCE_PLC_BASE_EMERGENCY && ErrID < TM_EVENTSOURCE_PLC_BASE_REPAIR)
		retStr = g_pIni->m_strStateEmergency;

	else if(ErrID >= TM_EVENTSOURCE_PLC_BASE_REPAIR && ErrID < TM_EVENTSOURCE_PLC_ENDBASE)
		retStr = g_pIni->m_strStateRepair;

	else
		retStr = g_pIni->m_strStateUnkown;

	return retStr;
}

void ErrorData::IniErrLevel( )
{
	m_ErrLevel[0] = SHOW_TERMINATE_STOP;
	m_ErrLevel[1] = SHOW_AND_BITCLEAR;
	m_ErrLevel[2] = SHOW_AND_TERMINATE;
	m_ErrLevel[3] = SHOW_AND_TERMINATE;
	m_ErrLevel[4] = SHOW_AND_TERMINATE;
	m_ErrLevel[5] = SHOW_AND_TERMINATE;
	m_ErrLevel[6] = SHOW_AND_TERMINATE;
	m_ErrLevel[7] = SHOW_AND_TERMINATE;

	m_ErrLevel[8] = SHOW;
	m_ErrLevel[9] = SHOW;
	m_ErrLevel[10] = SHOW_AND_TERMINATE;
	m_ErrLevel[11] = SHOW_AND_TERMINATE;
	m_ErrLevel[12] = SHOW;
	m_ErrLevel[13] = SHOW;
	m_ErrLevel[14] = SHOW_AND_TERMINATE;
	m_ErrLevel[15] = SHOW_AND_TERMINATE;

	m_ErrLevel[16] = SHOW_AND_TERMINATE;
	m_ErrLevel[17] = SHOW;
	m_ErrLevel[18] = SHOW;
	m_ErrLevel[19] = SHOW_AND_TERMINATE;
	m_ErrLevel[20] = SHOW_AND_TERMINATE;
	m_ErrLevel[21] = SHOW;
	m_ErrLevel[22] = SHOW;
	m_ErrLevel[23] = SHOW;

	m_ErrLevel[24] = SHOW;
	m_ErrLevel[25] = SHOW;
	m_ErrLevel[26] = SHOW;
	m_ErrLevel[27] = SHOW;
	m_ErrLevel[28] = SHOW_AND_TERMINATE;
	m_ErrLevel[29] = SHOW;
	m_ErrLevel[30] = SHOW;
	m_ErrLevel[31] = SHOW;

	m_ErrLevel[32] = SHOW;
	m_ErrLevel[33] = SHOW_TERMINATE_STOP;
	m_ErrLevel[34] = SHOW;
	m_ErrLevel[35] = SHOW;
	m_ErrLevel[36] = SHOW;
	m_ErrLevel[37] = SHOW;
	m_ErrLevel[38] = SHOW;
	m_ErrLevel[39] = SHOW;

	m_ErrLevel[40] = SHOW;
	m_ErrLevel[41] = SHOW;
	m_ErrLevel[42] = SHOW;
	m_ErrLevel[43] = SHOW;
	m_ErrLevel[44] = SHOW_AND_TERMINATE;
	m_ErrLevel[45] = SHOW_AND_TERMINATE;
	m_ErrLevel[46] = SHOW_AND_TERMINATE;
	m_ErrLevel[47] = SHOW;

	m_ErrLevel[48] = SHOW;
	m_ErrLevel[49] = SHOW_AND_TERMINATE;
	m_ErrLevel[50] = SHOW_AND_TERMINATE;
	m_ErrLevel[51] = SHOW_AND_TERMINATE;
	m_ErrLevel[52] = SHOW_AND_TERMINATE;
	m_ErrLevel[53] = SHOW_AND_TERMINATE;
	m_ErrLevel[54] = SHOW_AND_TERMINATE;
	m_ErrLevel[55] = SHOW_AND_TERMINATE;

	m_ErrLevel[56] = SHOW_AND_TERMINATE;
	m_ErrLevel[57] = SHOW;
	m_ErrLevel[58] = SHOW;
	m_ErrLevel[59] = SHOW;
	m_ErrLevel[60] = SHOW;
	m_ErrLevel[61] = SHOW;
	m_ErrLevel[62] = SHOW;
	m_ErrLevel[63] = SHOW;

	m_ErrLevel[64] = SHOW_AND_TERMINATE;
	m_ErrLevel[65] = SHOW_AND_TERMINATE;
	m_ErrLevel[66] = SHOW_AND_TERMINATE;
}

void ErrorData::IniSignalActive( )
{
	m_SignalActive[0] = HIGH_ACTIVE;
	m_SignalActive[1] = HIGH_ACTIVE;
	m_SignalActive[2] = HIGH_ACTIVE;
	m_SignalActive[3] = HIGH_ACTIVE;
	m_SignalActive[4] = HIGH_ACTIVE;
	m_SignalActive[5] = HIGH_ACTIVE;
	m_SignalActive[6] = HIGH_ACTIVE;
	m_SignalActive[7] = HIGH_ACTIVE;

	m_SignalActive[8] = LOW_ACTIVE;
	m_SignalActive[9] = LOW_ACTIVE;
	m_SignalActive[10] = LOW_ACTIVE;
	m_SignalActive[11] = LOW_ACTIVE;
	m_SignalActive[12] = LOW_ACTIVE;
	m_SignalActive[13] = LOW_ACTIVE;
	m_SignalActive[14] = LOW_ACTIVE;
	m_SignalActive[15] = LOW_ACTIVE;

	m_SignalActive[16] = LOW_ACTIVE;
	m_SignalActive[17] = LOW_ACTIVE;
	m_SignalActive[18] = LOW_ACTIVE;
	m_SignalActive[19] = LOW_ACTIVE;
	m_SignalActive[20] = LOW_ACTIVE;
	m_SignalActive[21] = LOW_ACTIVE;
	m_SignalActive[22] = LOW_ACTIVE;
	m_SignalActive[23] = LOW_ACTIVE;

	m_SignalActive[24] = LOW_ACTIVE;
	m_SignalActive[25] = LOW_ACTIVE;
	m_SignalActive[26] = LOW_ACTIVE;
	m_SignalActive[27] = LOW_ACTIVE;
	m_SignalActive[28] = LOW_ACTIVE;
	m_SignalActive[29] = LOW_ACTIVE;
	m_SignalActive[30] = LOW_ACTIVE;
	m_SignalActive[31] = LOW_ACTIVE;

	m_SignalActive[32] = LOW_ACTIVE;
	m_SignalActive[33] = HIGH_ACTIVE;
	m_SignalActive[34] = HIGH_ACTIVE;
	m_SignalActive[35] = HIGH_ACTIVE;
	m_SignalActive[36] = HIGH_ACTIVE;
	m_SignalActive[37] = HIGH_ACTIVE;
	m_SignalActive[38] = HIGH_ACTIVE;
	m_SignalActive[39] = HIGH_ACTIVE;

	m_SignalActive[40] = HIGH_ACTIVE;
	m_SignalActive[41] = HIGH_ACTIVE;
	m_SignalActive[42] = HIGH_ACTIVE;
	m_SignalActive[43] = HIGH_ACTIVE;
	m_SignalActive[44] = LOW_ACTIVE;
	m_SignalActive[45] = LOW_ACTIVE;
	m_SignalActive[46] = LOW_ACTIVE;
	m_SignalActive[47] = LOW_ACTIVE;

	m_SignalActive[48] = LOW_ACTIVE;
	m_SignalActive[49] = HIGH_ACTIVE;
	m_SignalActive[50] = HIGH_ACTIVE;
	m_SignalActive[51] = HIGH_ACTIVE;
	m_SignalActive[52] = HIGH_ACTIVE;
	m_SignalActive[53] = HIGH_ACTIVE;
	m_SignalActive[54] = HIGH_ACTIVE;
	m_SignalActive[55] = HIGH_ACTIVE;

	m_SignalActive[56] = HIGH_ACTIVE;	
	m_SignalActive[57] = LOW_ACTIVE;	
	m_SignalActive[58] = HIGH_ACTIVE;	
	m_SignalActive[59] = HIGH_ACTIVE;	
	m_SignalActive[60] = HIGH_ACTIVE;	
	m_SignalActive[61] = HIGH_ACTIVE;	
	m_SignalActive[62] = LOW_ACTIVE;	
	m_SignalActive[63] = HIGH_ACTIVE;	

	m_SignalActive[64] = LOW_ACTIVE;	
	m_SignalActive[65] = LOW_ACTIVE;	
	m_SignalActive[66] = LOW_ACTIVE;	

	for(int i=0 ; i<ERRBITCOUNT ; i++)
	{
		m_CurErrSignals[i] = !m_SignalActive[i];
		m_PreErrSignals[i] = !m_SignalActive[i];
	}
}

void ErrorData::IniErrMask()
{
	for(int i=0 ; i<ERRBITCOUNT ; i++ ){
		m_ErrMask[i] = NOMASK;
	}
	m_ErrMask[0] = MASK;	//permenent delete!!! M Variables Error
	m_ErrMask[1] = MASK;	//permenent delete!!! M Variables Error
	m_ErrMask[2] = MASK;	//permenent delete!!! M Variables Error
	m_ErrMask[3] = MASK;	//permenent delete!!! M Variables Error
	m_ErrMask[4] = MASK;	//permenent delete!!! M Variables Error
	m_ErrMask[5] = MASK;	//permenent delete!!! M Variables Error
	m_ErrMask[6] = MASK;	//permenent delete!!! M Variables Error
	m_ErrMask[7] = MASK;	//permenent delete!!! M Variables Error

	m_ErrMask[20] = MASK;	//temporary
	m_ErrMask[21] = MASK;	//temporary

	m_ErrMask[23] = MASK;	//temporary

	m_ErrMask[26] = MASK;	//temporary
	m_ErrMask[27] = MASK;	//temporary
	m_ErrMask[28] = MASK;	//temporary
	m_ErrMask[29] = MASK;	//temporary

	m_ErrMask[31] = MASK;	//temporary
	m_ErrMask[32] = MASK;	//temporary

	m_ErrMask[33] = MASK;	//permenent delete!!!
	m_ErrMask[34] = MASK;	//permenent delete!!!
	m_ErrMask[35] = MASK;	//permenent delete!!!

	m_ErrMask[47] = MASK;	//temporary
	m_ErrMask[48] = MASK;	//temporary

	m_ErrMask[66] = MASK;	//permenent delete!!! deplicate
}

//about SQL DataBase
bool ErrorData::createDataFile(const QString &strFileName)  
{  
    if(!QFile::exists(strFileName))
    {  
        QDir fileDir = QFileInfo(strFileName).absoluteDir();  
        QString strFileDir = QFileInfo(strFileName).absolutePath();  
        if(!fileDir.exists()) 
        {  
            fileDir.mkpath(strFileDir);  
        }  
        QFile dbFile(strFileName);  
        if(!dbFile.open(QIODevice::WriteOnly))
        {  
            dbFile.close();  
            return false;  
        }  
        dbFile.close();  
    }  
    return true;  
} 

bool ErrorData::isExistTable(const QString& strTableName)  
{  
    QSqlQuery query(m_DataBase);  
    QString strSql = QString("SELECT 1 FROM sqlite_master where type = 'table' and  name = '%1'").arg(strTableName);  
    query.exec(strSql);  
    if(query.next())  
    {  
        int nResult = query.value(0).toInt();
        if(nResult)  
        {  
            return true;  
        }  
    }  
    return false;  
}  

bool ErrorData::OpenDataBase( ) //QSqlDatabase sqlite
{
	bool bReseult = false;
	if (QSqlDatabase::contains("qt_sql_default_connection"))
	{
		m_DataBase = QSqlDatabase::database("qt_sql_default_connection");
	}
	else
	{
		m_DataBase = QSqlDatabase::addDatabase("QSQLITE");
		m_DataBase.setDatabaseName("..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\DataBase\\TrainMilling.db");
	}
	if(m_DataBase.open( ) )
	{
		if(isExistTable("ErrInfo") == false)
		{
			QSqlQuery sql_query(m_DataBase);
			QString create_sql = "create table ErrInfo (number varchar(15), datetime varchar(30),state varchar(15),alarmtext varchar(100), workstate varchar(30) )";
			sql_query.prepare(create_sql);
			bReseult = sql_query.exec();
		}
	}
	return bReseult;
}

void ErrorData::DeleteOutDatedItems( )
{
	if( !m_DataBase.isOpen( ) )
		return;

	QDateTime nowDatetime = QDateTime::currentDateTime();
	QDateTime borderDatetime = nowDatetime.addDays(-720);
	QString dDateTime=borderDatetime.toString("yyyy.MM.dd  hh:mm:ss");
	QSqlQuery sql_query(m_DataBase);
	QString delete_sql = QString("delete from ErrInfo where datetime < '%1'").arg(dDateTime);
	bool bReseult = sql_query.exec(delete_sql);
}

bool ErrorData::SaveAlarmItemToDataBase(QString number,QString datetime,QString state, QString alarmtext,QString workstate )
{
	if( !m_DataBase.isOpen( ) )
		return false;

	QSqlQuery sql_query(m_DataBase);
	QString insert_sql = "insert into ErrInfo (number,datetime,state,alarmtext,workstate) values (?, ?, ?, ?, ?)";
	sql_query.prepare(insert_sql);
	sql_query.addBindValue(number);
	sql_query.addBindValue(datetime);
	sql_query.addBindValue(state);
	sql_query.addBindValue(alarmtext);
	sql_query.addBindValue(workstate);
	if(sql_query.exec())
	{
		//qDebug() << "inserted succeed!";
		return true;
	}
	else
	{
		//qDebug() << sql_query.lastError();
		return false;
	}
	return true;
}

void ErrorData::CloseDataBase( )
{
    m_DataBase.close();
}