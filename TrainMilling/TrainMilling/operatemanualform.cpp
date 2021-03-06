///////////////////////////////////////////////////////////////////////////////
/*! \file	operatemanualform.cpp
 *  \author
 *  \date
 *  \brief	Implementation file for class OperateManualForm
 *
 *  This file is part of the HMI Solutionline GUI Framework.
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////
#include "operatemanualform.h"
#include "QDateTime.h"
#include "QSettings.h"

const QString ENTRY_PICTURE_LIST = "/OperateManual/Src";
///////////////////////////////////////////////////////////////////////////////
// CREATORS
///////////////////////////////////////////////////////////////////////////////

OperateManualForm::OperateManualForm(QWidget* pParent, const QString& rszName)
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

}// <-- OperateManualForm::OperateManualForm ()


OperateManualForm::~OperateManualForm(void)
{

} // <-- ::~ ()


///////////////////////////////////////////////////////////////////////////////
// Overrides
///////////////////////////////////////////////////////////////////////////////

void OperateManualForm::attachedToScreen(const QString& rszScreenName)
{
	// initialize timer for toggle R-Parameter
	m_tmrToggle.setSingleShot(true);
	m_tmrToggle.setInterval(1000);

	// signal/slot connection for QTimer
	QObject::connect( &m_tmrToggle,SIGNAL(timeout()),this,SLOT(TimeoutSlot()) );
	// start timer
	//m_tmrToggle.start();
	if(g->m_bIsLogin==true)
		setStatusBarElementText(g_pIni->m_strLogin, 1);
	else
		setStatusBarElementText(g_pIni->m_strNotLogin, 1);

	m_PicNameList.clear();
	QSettings *configIniRead = new QSettings("C:/scr/parameter.ini", QSettings::IniFormat);  
	m_PicNameList = configIniRead->value(ENTRY_PICTURE_LIST).toStringList();	
	delete configIniRead; 

	m_PicIndex = 0;
	QString styleSheet = "border-image:url(" + m_PicNameList[m_PicIndex] + ")";
	this->label->setStyleSheet(styleSheet);
	if( m_PicNameList.count() == 1 )
	{
		setSoftkeyDisable(2,true);
		setSoftkeyDisable(3,true);
	}
	else if( m_PicNameList.count() > 1 && m_PicIndex == 0 )
	{
		setSoftkeyDisable(2,false);
		setSoftkeyDisable(3,true);
	}
	else if(  m_PicNameList.count() > 1 && m_PicIndex == m_PicNameList.count()-1)
	{
		setSoftkeyDisable(2,true);
		setSoftkeyDisable(3,false);
	}
	else
	{
		setSoftkeyDisable(2,false);
		setSoftkeyDisable(3,false);
	}

	g_pOperateManualForm = this;
    // don't forget to call the standard implementation
    SlGfwDialogForm::attachedToScreen(rszScreenName);
}


void OperateManualForm::detachedFromScreen(const QString& rszScreenName)
{
	g_pOperateManualForm = 0;
    // don't forget to call the standard implementation
    SlGfwDialogForm::detachedFromScreen(rszScreenName);
}


///////////////////////////////////////////////////////////////////////////////
// public ACCESSORS
///////////////////////////////////////////////////////////////////////////////
void OperateManualForm::TimeoutSlot()
{
	/*
	// read toggle-item
	QDateTime current_date_time =QDateTime::currentDateTime();
	QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss ddd");
	setCaptionBarElementText(current_date,1);
	*/
	//this->axWidget->setControl("Adobe PDF Reader");
	//this->axWidget->dynamicCall("LoadFile(const QString&)","c:/src/test.pdf");
	/*
	//QAxWidget officeContent = new QAxWidget(this,0);
    QAxWidget* officeContent_ = new QAxWidget(this);
    if(!officeContent_->setControl("Adobe PDF Reader"))
	{
		setStatusBarElementText("No pdf Reader", 0);
		return;
	}
    gridLayout->addWidget(officeContent_);
    officeContent_->dynamicCall("LoadFile(const QString&)","c:/src/test.pdf");
	*/
}


///////////////////////////////////////////////////////////////////////////////
// MANIPULATORS - system overrides
///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// public SLOTS - system overrides
///////////////////////////////////////////////////////////////////////////////
void OperateManualForm::onFunction (const QString& rsFunction,
                                    const QString& rsArgs,
                                    bool& rbHandled)
{
	// check null pointer
	if ( "NextPage" == rsFunction )
	{
		m_PicIndex ++;
		if( m_PicIndex >= m_PicNameList.count()-1)
			m_PicIndex = m_PicNameList.count()-1;

		QString styleSheet = "border-image:url(" + m_PicNameList[m_PicIndex] + ")";
		this->label->setStyleSheet(styleSheet);
		if( m_PicNameList.count() == 1 )
		{
			setSoftkeyDisable(2,true);
			setSoftkeyDisable(3,true);
		}
		else if( m_PicNameList.count() > 1 && m_PicIndex == 0 )
		{
			setSoftkeyDisable(2,false);
			setSoftkeyDisable(3,true);
		}
		else if(  m_PicNameList.count() > 1 && m_PicIndex == m_PicNameList.count()-1)
		{
			setSoftkeyDisable(2,true);
			setSoftkeyDisable(3,false);
		}
		else
		{
			setSoftkeyDisable(2,false);
			setSoftkeyDisable(3,false);
		}
		rbHandled = true;
	}
	else if ( "PreviousPage" == rsFunction )
	{
		m_PicIndex --;
		if( m_PicIndex <= 0)
			m_PicIndex = 0;

		QString styleSheet = "border-image:url(" + m_PicNameList[m_PicIndex] + ")";
		this->label->setStyleSheet(styleSheet);
		if( m_PicNameList.count() == 1 )
		{
			setSoftkeyDisable(2,true);
			setSoftkeyDisable(3,true);
		}
		else if( m_PicNameList.count() > 1 && m_PicIndex == 0 )
		{
			setSoftkeyDisable(2,false);
			setSoftkeyDisable(3,true);
		}
		else if(  m_PicNameList.count() > 1 && m_PicIndex == m_PicNameList.count()-1)
		{
			setSoftkeyDisable(2,true);
			setSoftkeyDisable(3,false);
		}
		else
		{
			setSoftkeyDisable(2,false);
			setSoftkeyDisable(3,false);
		}

		rbHandled = true;
	}
	// need to call the base class
	if ( false == rbHandled )
		SlGfwDialogForm::onFunction(rsFunction, rsArgs, rbHandled);
} // <-- OperateManualForm::onFunction ()


///////////////////////////////////////////////////////////////////////////////
// private methods
///////////////////////////////////////////////////////////////////////////////
void OperateManualForm::setSoftkeyDisable(int nSoftkey, bool bDisabled)
{
	// get pointer to screen
	SlGfwScreen* pScreen = dialog()->screenRef("OperateManualScreen");

	if ( 0 != pScreen )
	{
		// get pointer to softkey
		SlGfwSoftKey* pSoftkey = pScreen->menuSoftkey("vr", nSoftkey);
		
		// enable/disable softkey
		if ( 0 != pSoftkey )
			pSoftkey->setDisabled(bDisabled);
	}
}