///////////////////////////////////////////////////////////////////////////////
/*! \file	errorform.cpp
 *  \author
 *  \date
 *  \brief	Implementation file for class ErrorForm
 *
 *  This file is part of the HMI Solutionline GUI Framework.
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////
#include "errorform.h"
#include "QTextCodec.h"
#include "QSettings.h"
#include "GlobalVar.h"

///////////////////////////////////////////////////////////////////////////////
// CREATORS
///////////////////////////////////////////////////////////////////////////////

ErrorForm::ErrorForm(QWidget* pParent, const QString& rszName)
	: SlGfwDialogForm(pParent, rszName)
{
	setupUi(this);
	//calendarWidget Initialize
	m_bTodayOrHis = true;				//true for Today,false for History
	this->calendarWidget->setLocale(QLocale(QLocale::English,QLocale::China));
	this->calendarWidget->setVisible(!m_bTodayOrHis);
	connect(this->calendarWidget,SIGNAL(clicked(const QDate&)),this,SLOT(SelectDate(const QDate &)));
	//Start Timer
	QDateTime current_date_time =QDateTime::currentDateTime();
	QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss ddd");

	this->setCaptionBarElementCount(2);
	this->setCaptionBarElementAlignment(Qt::AlignLeft,0);
	this->setCaptionBarElementText(g_pIni->m_strProductInfo,0);
	this->setCaptionBarElementAlignment(Qt::AlignRight,1);
	this->setCaptionBarElementText(current_date,1);
	this->setCaptionBarVisible(true);

	// set the text of the main widget
	setStatusBarElementCount(2); 
	setStatusBarElementAlignment(Qt::AlignCenter,0);
	setStatusBarElementAlignment(Qt::AlignRight,1);
	setStatusBarVisible(true);

	// initialize timer for toggle R-Parameter
	m_tmrToggle.setSingleShot(false);
	m_tmrToggle.setInterval(1000);
	// signal/slot connection for QTimer
	QObject::connect( &m_tmrToggle,SIGNAL(timeout()),this,SLOT(TimeoutSlot()) );
	// start timer
	//m_tmrToggle.start();

    int             nIdx = 0;
    QStringList     slTmp;

	// first create a (main) QHBoxLayout to display the SlGfwTreeWidget automatically fullsize.
    //QHBoxLayout* pHBoxLayout = new QHBoxLayout(this);
    // no margin
    //pHBoxLayout->setMargin(0);

    
    // create a SlGfwTreeWidget for displaying the alarm list 
    //m_pTreeWidget = new SlGfwTreeWidget(this);
    // dont show controls for root items 
    m_pTreeWidget->setRootIsDecorated(false);
    // no frame and no 3D effect
    m_pTreeWidget->setFrameStyle(QFrame::NoFrame | QFrame::Plain);

    // initialize the number of columns of the SlGfwTreeWidget
	m_pTreeWidget->setColumnCount(ALM_COL_MAX);
	
    // loop over the visible columns of the alarm list ...
	for(nIdx = ALM_COL_TIMESTAMP; nIdx < ALM_COL_MAX; nIdx++)
    {	
		// ... and set the text alignment of each column
        m_pTreeWidget->headerItem()->setTextAlignment(nIdx, Qt::AlignHCenter);
    }
	m_pTreeWidget->headerItem()->setTextAlignment(ALM_COL_TEXT, Qt::AlignLeft);

    // label the header of each column 
	/*
    slTmp = (QStringList() <<  readText(strNumber)
                            << readText(strTimer)
							<< readText(strState)
                            << readText(strText));
							*/
    slTmp = (QStringList() << g_pIni->m_strErrorNumber //编号
						   << g_pIni->m_strErrorTime   //时间 
						   << g_pIni->m_strErrorState  //状态
						   << g_pIni->m_strErrorText   //文本
						   << g_pIni->m_strErrorWorkState );//工作状态
    m_pTreeWidget->setHeaderLabels(slTmp);

	//m_pTreeWidgetSave->setVisible(false);
   // add the SlGfwTreeWidget to the (main) QHBoxLayout
    //pHBoxLayout->addWidget(m_pTreeWidget);

}// <-- ErrorForm::ErrorForm ()


ErrorForm::~ErrorForm(void)
{
	// check null pointer
	if(m_tmrToggle.isActive())
		m_tmrToggle.stop();

} // <-- ::~ ()


void ErrorForm::LoadErrFromDataBase( QString date ) //load error info from database
{
	if( 0 == g_pErr )
		return;
	if( !g_pErr->m_DataBase.isOpen() )
		return;

	SlGfwTreeWidgetItem* pTreeWidgetItem;
	QSqlQuery sql_query(g_pErr->m_DataBase);
	QString select_sql = QString("select number,datetime,state,alarmtext,workstate from ErrInfo where datetime like '%%1%'").arg(date);
	//sql_query.prepare(select_sql);
	//sql_query.addBindValue(date);

	m_pTreeWidget->clear( );
	if(sql_query.exec(select_sql))
	{
		while(sql_query.next())
		{
			QString number    = sql_query.value(0).toString();
			QString datetime  = sql_query.value(1).toString();
			QString state     = sql_query.value(2).toString();
			QString alarmtext = sql_query.value(3).toString();
			QString workstate = sql_query.value(4).toString();

            pTreeWidgetItem = new SlGfwTreeWidgetItem (m_pTreeWidget);
			if(0 != pTreeWidgetItem)
			{
				pTreeWidgetItem->setText(ALM_COL_NUMBER, number);
				pTreeWidgetItem->setTextAlignment(ALM_COL_NUMBER, Qt::AlignCenter);

				pTreeWidgetItem->setText(ALM_COL_TIMESTAMP, datetime);
				pTreeWidgetItem->setTextAlignment(ALM_COL_TIMESTAMP, Qt::AlignCenter);

				pTreeWidgetItem->setText(ALM_COL_STATE, state);
				pTreeWidgetItem->setTextAlignment(ALM_COL_STATE, Qt::AlignCenter);

				pTreeWidgetItem->setText(ALM_COL_TEXT, alarmtext);
				pTreeWidgetItem->setTextAlignment(ALM_COL_TEXT, Qt::AlignVCenter);

				pTreeWidgetItem->setText(ALM_COL_WORKSTATE, workstate);
				pTreeWidgetItem->setTextAlignment(ALM_COL_WORKSTATE, Qt::AlignCenter);
			}
		}
	}
	else
	{
		//qDebug()<<sql_query.lastError();
	}
}


void ErrorForm::LoadErrFromAlarmList( )
{
    SlGfwTreeWidgetItem*    pTreeWidgetItem = 0;
    QDateTime				dt;
	QString					szId;
	QString					szDateTime;
	QString					szState;
	QString					szText;
	QString					szWorkState;
    QVariant				vTmp;
	int						nDispIdx = 0;
    int                     nIdx;
    int                     nNrOfAlarms = 0;

	// check null pointer
	if ( ( 0 != m_pTreeWidget ) && ( 0 != g_pErr->m_pQAlarmPtrList ) )
    {
		// save the current selected alarm in the alarm list display (SlGfwTreeWidget)
        nDispIdx = m_pTreeWidget->indexOfTopLevelItem(m_pTreeWidget->currentItem());
		
        // clear the alarm list display (SlGfwTreeWidget)
        m_pTreeWidget->clear();

		// get the current size of the event list (QAlarmPtrList)
        nNrOfAlarms = g_pErr->m_pQAlarmPtrList->getList()->size();

        QList<SlAeEvent*>::iterator it;

        for(it = g_pErr->m_pQAlarmPtrList->getList()->begin(); it != g_pErr->m_pQAlarmPtrList->getList()->end(); ++it)
        {
            SlAeEvent* pAEEvent = *it;

            // create a new row (SlGfwTreeWidgetItem) in the alarm list
            pTreeWidgetItem = new SlGfwTreeWidgetItem (m_pTreeWidget);

            // check null pointer 
            if ( 0 != pTreeWidgetItem )
            {
                // get the alarm number of the alarm list and add it to a cell of a SlGfwTreeWidgetItem 
                szId = szId.setNum(pAEEvent->getAlarmId());
				szWorkState = g_pErr->GetErrorWorkState(pAEEvent->getAlarmId());
                pTreeWidgetItem->setText(ALM_COL_NUMBER, szId);
				pTreeWidgetItem->setTextAlignment(ALM_COL_NUMBER, Qt::AlignCenter);
 
				// get the date and time of the alarm list and add it to a cell of a SlGfwTreeWidgetItem 
                dt = pAEEvent->getTimestamp();
				szDateTime = dt.toString("yyyy.MM.dd  hh:mm:ss");
				pTreeWidgetItem->setText(ALM_COL_TIMESTAMP, szDateTime);
				pTreeWidgetItem->setTextAlignment(ALM_COL_TIMESTAMP, Qt::AlignCenter);

                // get the event state of the event list and add it to a cell of a SlGfwTreeWidgetItem 
                szState = szState.setNum(pAEEvent->getAlarmState());
                pTreeWidgetItem->setText(ALM_COL_STATE, szState);
				pTreeWidgetItem->setTextAlignment(ALM_COL_STATE, Qt::AlignCenter);

                // get the alarm text of the alarm list and add it to a cell of a SlGfwTreeWidgetItem 
                // note: the alarm text is an additional return attribute
                vTmp = pAEEvent->getAttribute(SLAE_EV_ATTR_MSGTEXT);
                szText = vTmp.toString();
                pTreeWidgetItem->setText(ALM_COL_TEXT, szText);
				pTreeWidgetItem->setTextAlignment(ALM_COL_TEXT, Qt::AlignVCenter);

				//set WorkState
                pTreeWidgetItem->setText(ALM_COL_WORKSTATE, szWorkState);
				pTreeWidgetItem->setTextAlignment(ALM_COL_WORKSTATE, Qt::AlignCenter);

				//SaveAlarmItem(pTreeWidgetItem);
				g_pErr->SaveAlarmItem(szId,szDateTime,szState,szText,szWorkState );

				pAEEvent = 0;
            } //end if
        } //end for

		// correct the saved and selected alarm in the alarm list display (SlGfwTreeWidget)
        if ( nNrOfAlarms <= nDispIdx )
		{
			nDispIdx = nNrOfAlarms - 1;
		}
		if ( 0 > nDispIdx )
		{
			nDispIdx = 0;
		}

        // only if there are alarms at all
        if ( 0 < nNrOfAlarms )
		{
			// set the current selected alarm in the alarm list display (SlGfwTreeWidget)
            m_pTreeWidget->setCurrentItem(m_pTreeWidget->topLevelItem(nDispIdx));

            // iterate over every column and resize their width to their content
            for(nIdx = ALM_COL_TIMESTAMP; nIdx <= ALM_COL_MAX; nIdx++)
            {
                m_pTreeWidget->resizeColumnToContents(nIdx);
            }
        }
    }
	/*
    SlGfwTreeWidgetItem*    pTreeWidgetItem = 0;
    QString					szTmp;
	int						nDispIdx = 0;
    int                     nIdx;
    int                     nNrOfAlarms = 0;

	// check null pointer
	if ( ( 0 != m_pTreeWidget ) && ( 0 != g_pErr ) )
    {
		// save the current selected alarm in the alarm list display (SlGfwTreeWidget)
        nDispIdx = m_pTreeWidget->indexOfTopLevelItem(m_pTreeWidget->currentItem());
		
        // clear the alarm list display (SlGfwTreeWidget)
        m_pTreeWidget->clear();

        nNrOfAlarms = g_pErr->m_nstrErrList.size() / 4;

        for(int i=0 ; i<nNrOfAlarms ; i++)
        {
            // create a new row (SlGfwTreeWidgetItem) in the alarm list
            pTreeWidgetItem = new SlGfwTreeWidgetItem (m_pTreeWidget);

            // check null pointer 
            if ( 0 != pTreeWidgetItem )
            {
                // get the alarm number of the alarm list and add it to a cell of a SlGfwTreeWidgetItem 
				szTmp = g_pErr->m_nstrErrList.at(4*i);
                pTreeWidgetItem->setText(ALM_COL_NUMBER, szTmp);
				pTreeWidgetItem->setTextAlignment(ALM_COL_NUMBER, Qt::AlignCenter);
 
				// get the date and time of the alarm list and add it to a cell of a SlGfwTreeWidgetItem 
				szTmp = g_pErr->m_nstrErrList.at(4*i+1);
				pTreeWidgetItem->setText(ALM_COL_TIMESTAMP, szTmp);
				pTreeWidgetItem->setTextAlignment(ALM_COL_TIMESTAMP, Qt::AlignCenter);

                // get the event state of the event list and add it to a cell of a SlGfwTreeWidgetItem 
				szTmp = g_pErr->m_nstrErrList.at(4*i+2);
                pTreeWidgetItem->setText(ALM_COL_STATE, szTmp);
				pTreeWidgetItem->setTextAlignment(ALM_COL_STATE, Qt::AlignCenter);

                // get the alarm text of the alarm list and add it to a cell of a SlGfwTreeWidgetItem 
                // note: the alarm text is an additional return attribute
				szTmp = g_pErr->m_nstrErrList.at(4*i+3);
                pTreeWidgetItem->setText(ALM_COL_TEXT, szTmp);
				pTreeWidgetItem->setTextAlignment(ALM_COL_TEXT, Qt::AlignVCenter);
            }
        }

		// correct the saved and selected alarm in the alarm list display (SlGfwTreeWidget)
        if ( nNrOfAlarms <= nDispIdx )
		{
			nDispIdx = nNrOfAlarms - 1;
		}
		if ( 0 > nDispIdx )
		{
			nDispIdx = 0;
		}

        // only if there are alarms at all
        if ( 0 < nNrOfAlarms )
		{
			// set the current selected alarm in the alarm list display (SlGfwTreeWidget)
            m_pTreeWidget->setCurrentItem(m_pTreeWidget->topLevelItem(nDispIdx));

            // iterate over every column and resize their width to their content
            for(nIdx = ALM_COL_TIMESTAMP; nIdx <= ALM_COL_MAX; nIdx++)
            {
                m_pTreeWidget->resizeColumnToContents(nIdx);
            }
        }
    }
	*/
}

///////////////////////////////////////////////////////////////////////////////
// Overrides
///////////////////////////////////////////////////////////////////////////////
void ErrorForm::attachedToScreen(const QString& rszScreenName)
{
	// check null pointer
	if(g->m_bIsLogin==false){
		dialog()->switchToScreen("MainScreen",NULL);
		return;
	}

	if(g->m_bIsLogin==true)
		setStatusBarElementText(g_pIni->m_strLogin, 1);
	else
		setStatusBarElementText(g_pIni->m_strNotLogin, 1);

	this->calendarWidget->setVisible(!m_bTodayOrHis);

	//g_pErr->EventListActive( );
	onListChanged( );

	setVSoftkeyDisable(7, m_bTodayOrHis);		//m_bTodayOrHis true for Today,false for History
	updateLabel(m_bTodayOrHis);
	g_pErrorForm = this;
    // don't forget to call the standard implementation
    SlGfwDialogForm::attachedToScreen(rszScreenName);
}


void ErrorForm::detachedFromScreen(const QString& rszScreenName)
{
    //g_pErr->EventListDeActive( );
	//SaveErrToDataBase( );

	g_pErrorForm = 0;
    // don't forget to call the standard implementation
    SlGfwDialogForm::detachedFromScreen(rszScreenName);
}

void ErrorForm::TimeoutSlot()
{
	/*
	// read toggle-item
	QDateTime current_date_time =QDateTime::currentDateTime();
	QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss ddd");
	setCaptionBarElementText(current_date,1);
	*/
}

void ErrorForm::onListChanged()
{
	if(m_bTodayOrHis == true)				//true for Today,false for History
		LoadErrFromAlarmList( );
}
///////////////////////////////////////////////////////////////////////////////
// Overrides
///////////////////////////////////////////////////////////////////////////////
void ErrorForm::onHelp(QString& rszDocument,QString& rszAnchor,bool& rbHandled)
{
	SlGfwTreeWidgetItem* pTreeWidgetItem = 0;
	if(m_pTreeWidget->isVisible())
	{
		pTreeWidgetItem = m_pTreeWidget->currentItem();
	}
	if(pTreeWidgetItem!=0)
	{
		QString alarmIndex = pTreeWidgetItem->text(0);
		rszAnchor = alarmIndex;
	}
	SlGfwDialogForm::onHelp(rszDocument,rszAnchor,rbHandled);
}

///////////////////////////////////////////////////////////////////////////////
// public SLOTS - system overrides
///////////////////////////////////////////////////////////////////////////////
void ErrorForm::onFunction (const QString& rsFunction,
                                    const QString& rsArgs,
                                    bool& rbHandled)
{
      //call base class
 	if ( "TodayAlarm" == rsFunction )
	{
		//createPcuCncComAlarm( );
		m_bTodayOrHis = true;						//true for Today,false for History
		setVSoftkeyDisable(7, m_bTodayOrHis);		//m_bTodayOrHis true for Today,false for History
		this->calendarWidget->setVisible(!m_bTodayOrHis);
		updateLabel(m_bTodayOrHis);
		LoadErrFromAlarmList( );
		rbHandled = true;
	}
 	else if ( "HistoryAlarm" == rsFunction )
	{
		m_bTodayOrHis = false;						//true for Today,false for History
		setVSoftkeyDisable(7, m_bTodayOrHis);		//m_bTodayOrHis true for Today,false for History
		this->calendarWidget->setVisible(!m_bTodayOrHis);
		updateLabel(m_bTodayOrHis);
		rbHandled = true;
	}
 	else if ( "DateSelected" == rsFunction )
	{
		SelectDate( );
		rbHandled = true;
	}
	// need to call the base class
	if ( false == rbHandled )
		SlGfwDialogForm::onFunction(rsFunction, rsArgs, rbHandled);

} // <-- ErrorForm::onFunction ()

void ErrorForm::SelectDate(const QDate &date)
{
	QString hDate = date.toString("yyyy.MM.dd");
	LoadErrFromDataBase( hDate );
	this->calendarWidget->setVisible(false);
}

void ErrorForm::SelectDate( )
{
	if(this->calendarWidget->isVisible())
	{
		QDate date = this->calendarWidget->selectedDate();
		QString hDate = date.toString("yyyy.MM.dd");
		LoadErrFromDataBase( hDate );
		this->calendarWidget->setVisible(false);
	}
	else{
		this->calendarWidget->setVisible(true);
	}
}

///////////////////////////////////////////////////////////////////////////////
// private methods
///////////////////////////////////////////////////////////////////////////////


void ErrorForm::setVSoftkeyDisable(int nSoftkey, bool bDisabled)
{
	// get pointer to screen
	SlGfwScreen* pScreen = dialog()->screenRef("ErrorScreen");

	if ( 0 != pScreen )
	{
		// get pointer to softkey
		SlGfwSoftKey* pSoftkey = pScreen->menuSoftkey("ErrorVr", nSoftkey);
		
		// enable/disable softkey
		if ( 0 != pSoftkey )
			pSoftkey->setDisabled(bDisabled);
	}
}

void ErrorForm::updateLabel(bool bTodayorHis)
{
	//true for Today,false for History
	this->TodayLabel->setVisible(bTodayorHis);
	this->HistoryLabel->setVisible(!bTodayorHis);
}