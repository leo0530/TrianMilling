///////////////////////////////////////////////////////////////////////////////
/*! \file	powerform.cpp
 *  \author
 *  \date
 *  \brief	Implementation file for class PowerForm
 *
 *  This file is part of the HMI Solutionline GUI Framework.
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////
#include "powerform.h"
#include <QtGui/QHBoxLayout>

///////////////////////////////////////////////////////////////////////////////
// CREATORS
///////////////////////////////////////////////////////////////////////////////

PowerForm::PowerForm(QWidget* pParent, const QString& rszName)
	: SlGfwDialogForm(pParent, rszName)
{
	long            lError = 0;
    int             nIdx = 0;
    QStringList     slTmp;
	
	setupUi(this);
	// first create a (main) QHBoxLayout to display the SlGfwTreeWidget automatically fullsize.
    QHBoxLayout* pHBoxLayout = new QHBoxLayout(this);
    // no margin
    pHBoxLayout->setMargin(0);

    
    // create a SlGfwTreeWidget for displaying the alarm list 
    m_pTreeWidget = new SlGfwTreeWidget(this);
    // dont show controls for root items 
    m_pTreeWidget->setRootIsDecorated(false);
    // no frame and no 3D effect
    m_pTreeWidget->setFrameStyle(QFrame::NoFrame | QFrame::Plain);

    // initialize the number of columns of the SlGfwTreeWidget
	m_pTreeWidget->setColumnCount(POWER_COL_MAX);
	
    // loop over the visible columns of the alarm list ...
	for(nIdx = POWER_COL_DEVICE; nIdx < POWER_COL_MAX; nIdx++)
    {	
		// ... and set the text alignment of each column
        m_pTreeWidget->headerItem()->setTextAlignment(nIdx, Qt::AlignHCenter);
   }
	m_pTreeWidget->header()->setResizeMode(QHeaderView::Stretch);

    // label the header of each column 
	/*
    slTmp = (QStringList() <<  readText(strNumber)
                            << readText(strTimer)
							<< readText(strState)
                            << readText(strText));
							*/
	QString strDevice = "Device";
 	QString strCurPower = "Current Power(Kwh)";
	QString strEnergyInput = "Energy Input(Kwh)";
	QString strRegenratedEnergy = "Regenrated Energy(Kwh)";
	QString strTotalEnergy = "Total Energy(Kwh)";
	slTmp = (QStringList() << strDevice << strCurPower << strEnergyInput << strRegenratedEnergy << strTotalEnergy);
    m_pTreeWidget->setHeaderLabels(slTmp);

    // add the SlGfwTreeWidget to the (main) QHBoxLayout
    pHBoxLayout->addWidget(m_pTreeWidget);

	m_tmrToggle.setSingleShot(false);
	m_tmrToggle.setInterval(1000);

	// signal/slot connection for QTimer
	QObject::connect( &m_tmrToggle,SIGNAL(timeout()),this,SLOT(TimeoutSlot()) );
	// start timer
	//m_tmrToggle.start();

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
	setStatusBarElementAlignment(Qt::AlignRight,1);
	setStatusBarElementText(g_pIni->m_strLogin, 1);
	setStatusBarVisible(true);

	timeoutSlot( );


}// <-- PowerForm::PowerForm ()


PowerForm::~PowerForm(void)
{
	if(m_tmrToggle.isActive())
		m_tmrToggle.stop();


} // <-- ::~ ()


///////////////////////////////////////////////////////////////////////////////
// Overrides
///////////////////////////////////////////////////////////////////////////////

void PowerForm::attachedToScreen(const QString& rszScreenName)
{
 	g_pPowerForm = this;
	// don't forget to call the standard implementation
    SlGfwDialogForm::attachedToScreen(rszScreenName);
}


void PowerForm::detachedFromScreen(const QString& rszScreenName)
{
 	g_pPowerForm = 0;
	// don't forget to call the standard implementation
    SlGfwDialogForm::detachedFromScreen(rszScreenName);
}


///////////////////////////////////////////////////////////////////////////////
// public ACCESSORS
///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// MANIPULATORS - system overrides
///////////////////////////////////////////////////////////////////////////////

void PowerForm::timeoutSlot( )
{
	SlQCap	m_capServer1,m_capServer2,m_capServer3,m_capServer4,m_capServer5;
	QVariant vValue1,vValue2,vValue3,vValue4,vValue5;
	QString szItem1 = "/Hmi/CtrlEnergy/DeviceNames";
	QString szItem2 = "/Hmi/CtrlEnergy/Power";
	QString szItem3 = "/Hmi/CtrlEnergy/ActiveEnergy";
	QString szItem4 = "/Hmi/CtrlEnergy/ReactiveEnergy";
	QString szItem5 = "/Hmi/CtrlEnergy/TotalEnergy";
	SlCapErrorEnum eError1,eError2,eError3,eError4,eError5; 
	SlGfwTreeWidgetItem*    pTreeWidgetItem = 0;
	QVariant::Type dataTypeVariant1,dataTypeVariant2,dataTypeVariant3,dataTypeVariant4,dataTypeVariant5;
	m_pTreeWidget->clear();

	eError1 = m_capServer1.read(szItem1, vValue1);
	handleRetVal(eError1);
	eError2 = m_capServer2.read(szItem2, vValue2);
	handleRetVal(eError2);
	eError3 = m_capServer3.read(szItem3, vValue3);
	handleRetVal(eError3);
	eError4 = m_capServer4.read(szItem4, vValue4);
	handleRetVal(eError4);
	eError5 = m_capServer5.read(szItem5, vValue5);
	handleRetVal(eError5);

	dataTypeVariant1 = vValue1.type();
	dataTypeVariant2 = vValue2.type();
	dataTypeVariant3 = vValue3.type();
	dataTypeVariant4 = vValue4.type();
	dataTypeVariant5 = vValue5.type();

	if ( QVariant::List == dataTypeVariant1 )
	{
		// convert to list
		QVariantList vValueList1 = vValue1.toList();
		QVariantList vValueList2 = vValue2.toList();
		QVariantList vValueList3 = vValue3.toList();
		QVariantList vValueList4 = vValue4.toList();
		QVariantList vValueList5 = vValue5.toList();

		pTreeWidgetItem = new SlGfwTreeWidgetItem (m_pTreeWidget);
		pTreeWidgetItem->setText(POWER_COL_DEVICE, QString::number(vValueList1.count()));
		pTreeWidgetItem->setTextAlignment(POWER_COL_DEVICE, Qt::AlignCenter);
		pTreeWidgetItem->setText(POWER_COL_CURPOWER, QString::number(vValueList2.count()));
		pTreeWidgetItem->setTextAlignment(POWER_COL_CURPOWER, Qt::AlignCenter);
		pTreeWidgetItem->setText(POWER_COL_ENERGYINPUT, QString::number(vValueList3.count()));
		pTreeWidgetItem->setTextAlignment(POWER_COL_CURPOWER, Qt::AlignCenter);
		pTreeWidgetItem->setText(POWER_COL_REGENERGY, QString::number(vValueList4.count()));
		pTreeWidgetItem->setTextAlignment(POWER_COL_CURPOWER, Qt::AlignCenter);
		pTreeWidgetItem->setText(POWER_COL_TOTALENERGY, QString::number(vValueList5.count()));
		pTreeWidgetItem->setTextAlignment(POWER_COL_CURPOWER, Qt::AlignCenter);

		if( (vValueList1.count() == vValueList2.count()) && (vValueList1.count() == vValueList3.count()) &&
			(vValueList1.count() == vValueList4.count()) && (vValueList1.count() == vValueList5.count()) )
		{
			// add the values to a QString, apart with "|"
			for ( int i = 0; i < vValueList1.count(); i++)
			{
				pTreeWidgetItem = new SlGfwTreeWidgetItem (m_pTreeWidget);
				pTreeWidgetItem->setText(POWER_COL_DEVICE, vValueList1[i].toString());
				pTreeWidgetItem->setTextAlignment(POWER_COL_DEVICE, Qt::AlignCenter);
				pTreeWidgetItem->setText(POWER_COL_CURPOWER, vValueList2[i].toString());
				pTreeWidgetItem->setTextAlignment(POWER_COL_CURPOWER, Qt::AlignCenter);
				pTreeWidgetItem->setText(POWER_COL_ENERGYINPUT, vValueList3[i].toString());
				pTreeWidgetItem->setTextAlignment(POWER_COL_CURPOWER, Qt::AlignCenter);
				pTreeWidgetItem->setText(POWER_COL_REGENERGY, vValueList4[i].toString());
				pTreeWidgetItem->setTextAlignment(POWER_COL_CURPOWER, Qt::AlignCenter);
				pTreeWidgetItem->setText(POWER_COL_TOTALENERGY, vValueList5[i].toString());
				pTreeWidgetItem->setTextAlignment(POWER_COL_CURPOWER, Qt::AlignCenter);
			}
		}
	}
	/*
	//---------------------the Sencond Row------------------------//
	szItem = 
	eError = m_capServer.read(szItem, vValue);
	handleRetVal(eError);
	// check type of QVariant
	dataTypeVariant = vValue.type();

	QVariantList vValueList = vValue.toList();
	pTreeWidgetItem = new SlGfwTreeWidgetItem (m_pTreeWidget);
	pTreeWidgetItem->setText(POWER_COL_CURPOWER, QString::number(eError));
	pTreeWidgetItem->setTextAlignment(POWER_COL_CURPOWER, Qt::AlignCenter);

	if ( QVariant::List == dataTypeVariant )
	{
		// convert to list
		QVariantList vValueList = vValue.toList();
					
		// add the values to a QString, apart with "|"
		for ( QVariantList::iterator it = vValueList.begin() ; it != vValueList.end() ; it++ )
		{
			pTreeWidgetItem = new SlGfwTreeWidgetItem (m_pTreeWidget);
			pTreeWidgetItem->setText(POWER_COL_CURPOWER, QString::number((*it).toDouble()));
			pTreeWidgetItem->setTextAlignment(POWER_COL_CURPOWER, Qt::AlignCenter);
		}
	}
	//---------------------the Third Row------------------------//
	szItem = 
	eError = m_capServer.read(szItem, vValue);
	handleRetVal(eError);
	// check type of QVariant
	dataTypeVariant = vValue.type();
	if ( QVariant::List == dataTypeVariant )
	{
		// convert to list
		QVariantList vValueList = vValue.toList();
					
		// add the values to a QString, apart with "|"
		for ( QVariantList::iterator it = vValueList.begin() ; it != vValueList.end() ; it++ )
		{
			pTreeWidgetItem = new SlGfwTreeWidgetItem (m_pTreeWidget);
			pTreeWidgetItem->setText(POWER_COL_ENERGYINPUT, QString::number((*it).toDouble()));
			pTreeWidgetItem->setTextAlignment(POWER_COL_ENERGYINPUT, Qt::AlignCenter);
		}
	}
	//---------------------the Fourth Row------------------------//
	szItem = 
	eError = m_capServer.read(szItem, vValue);
	handleRetVal(eError);
	// check type of QVariant
	dataTypeVariant = vValue.type();
	if ( QVariant::List == dataTypeVariant )
	{
		// convert to list
		QVariantList vValueList = vValue.toList();
					
		// add the values to a QString, apart with "|"
		for ( QVariantList::iterator it = vValueList.begin() ; it != vValueList.end() ; it++ )
		{
			pTreeWidgetItem = new SlGfwTreeWidgetItem (m_pTreeWidget);
			pTreeWidgetItem->setText(POWER_COL_REGENERGY, QString::number((*it).toDouble()));
			pTreeWidgetItem->setTextAlignment(POWER_COL_REGENERGY, Qt::AlignCenter);
		}
	}
	//---------------------the Fifth Row------------------------//
	szItem = 
	eError = m_capServer.read(szItem, vValue);
	handleRetVal(eError);
	// check type of QVariant
	dataTypeVariant = vValue.type();
	if ( QVariant::List == dataTypeVariant )
	{
		// convert to list
		QVariantList vValueList = vValue.toList();
					
		// add the values to a QString, apart with "|"
		for ( QVariantList::iterator it = vValueList.begin() ; it != vValueList.end() ; it++ )
		{
			pTreeWidgetItem = new SlGfwTreeWidgetItem (m_pTreeWidget);
			pTreeWidgetItem->setText(POWER_COL_TOTALENERGY, QString::number((*it).toDouble()));
			pTreeWidgetItem->setTextAlignment(POWER_COL_TOTALENERGY, Qt::AlignCenter);
		}
	}
	*/
}

///////////////////////////////////////////////////////////////////////////////
// public SLOTS - system overrides
///////////////////////////////////////////////////////////////////////////////
void PowerForm::onFunction (const QString& rsFunction,
                                    const QString& rsArgs,
                                    bool& rbHandled)
{
 	// check null pointer
	if  (0 != m_pTreeWidget  ) 
	{
		if ( "Start" == rsFunction )
		{
			// set that the event was handled by this function
			m_tmrToggle.start();
			SlCapErrorEnum eError = SL_CAP_OK;

			// write success or error to the status bar
			handleRetVal(eError);
			rbHandled = true;
		}
		else if ( "Stop" == rsFunction )
		{
			// set that the event was handled by this function
			if(m_tmrToggle.isActive())
				m_tmrToggle.stop();
			SlCapErrorEnum eError = SL_CAP_OK;

			// write success or error to the status bar
			handleRetVal(eError);
			rbHandled = true;
		}
	}

	// need to call the base class
	if ( false == rbHandled )
		SlGfwDialogForm::onFunction(rsFunction, rsArgs, rbHandled);
} // <-- PowerForm::onFunction ()


///////////////////////////////////////////////////////////////////////////////
// private methods
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Overrides
///////////////////////////////////////////////////////////////////////////////

void PowerForm::handleRetVal(SlCapErrorEnum eError)
{
	// evaluate return value
	if( SL_CAP_OK != eError )
	{
		// write error in status bar
		QString szHexErrorNr = QString("%1").arg(eError,0,16).right(8);
		setStatusBarElementText(ACCESS_ERROR.arg(szHexErrorNr), 0); 

		//Inner communication Error
		g->m_bPcuCommState = false;
		g_pErr->createPCUCOMAlarm();
	}
}