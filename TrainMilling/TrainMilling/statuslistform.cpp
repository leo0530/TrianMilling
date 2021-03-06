///////////////////////////////////////////////////////////////////////////////
/*! \file	statuslistform.cpp
 *  \author
 *  \date
 *  \brief	Implementation file for class StatusListForm
 *
 *  This file is part of the HMI Solutionline GUI Framework.
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////
#include "statuslistform.h"
#include "QFile.h"
#include "QTextStream.h"
#include "QTextCodec.h"
#include "QSettings.h"
#include "QTreeWidgetItemIterator.h"

///////////////////////////////////////////////////////////////////////////////
// CREATORS
///////////////////////////////////////////////////////////////////////////////

StatusListForm::StatusListForm(QWidget* pParent, const QString& rszName)
	: SlGfwDialogForm(pParent, rszName)
{
	setupUi(this);
	/*
	QTextCodec *codec = QTextCodec::codecForName("GBK");  
	QTextCodec::setCodecForTr(codec);  
	QTextCodec::setCodecForLocale(codec);  
	QTextCodec::setCodecForCStrings(codec); 
	*/
	//Read INI file,Get The ProductType


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

	m_pLeftTreeWidget->setRootIsDecorated(false);
    m_pLeftTreeWidget->setFrameStyle(QFrame::NoFrame | QFrame::Plain);
	m_pLeftTreeWidget->setColumnCount(3);

	m_pRightTreeWidget->setRootIsDecorated(false);
    m_pRightTreeWidget->setFrameStyle(QFrame::NoFrame | QFrame::Plain);
	m_pRightTreeWidget->setColumnCount(3);

	for(int nIdx = 0; nIdx < 3; nIdx++){
        m_pLeftTreeWidget->headerItem()->setTextAlignment(nIdx, Qt::AlignHCenter);
        m_pRightTreeWidget->headerItem()->setTextAlignment(nIdx, Qt::AlignHCenter);
	}

    QStringList slTmp = (QStringList() << g_pIni->m_strStatusListControlUnit 
									   << g_pIni->m_strStatusListAddress 
									   << g_pIni->m_strStatusListStatus );
    m_pLeftTreeWidget->setHeaderLabels(slTmp);
    m_pRightTreeWidget->setHeaderLabels(slTmp);
	m_pLeftTreeWidget->header()->setResizeMode(QHeaderView::ResizeToContents );
	m_pRightTreeWidget->header()->setResizeMode(QHeaderView::ResizeToContents );
	m_pLeftTreeWidget->header()->setStretchLastSection( true);
	m_pRightTreeWidget->header()->setStretchLastSection( true);

	//Start Timer
	m_tmrToggle.setSingleShot(false);
	m_tmrToggle.setInterval(1000);
	// signal/slot connection for QTimer
	QObject::connect( &m_tmrToggle,SIGNAL(timeout()),this,SLOT(TimeOutSlot()) );
	// start timer
	//m_tmrToggle.start();

}// <-- StatusListForm::StatusListForm ()


StatusListForm::~StatusListForm(void)
{
	m_tmrToggle.stop();
} // <-- ::~ ()

void StatusListForm::ListIOItems( )
{ 
	QMutexLocker locker(&m_Mutex);  

	SlGfwTreeWidgetItem* pLeftTreeWidgetItem;
	SlGfwTreeWidgetItem* pRightTreeWidgetItem;
	//RandomIOSignals( );

	memcpy(g->m_PreIOSignals,g->m_CurIOSignals,sizeof(g->m_CurIOSignals));

	m_pLeftTreeWidget->clear();
	m_pRightTreeWidget->clear();

	QFile fin("C:/scr/IOList.csv");
	if(!fin.open(QIODevice::ReadOnly | QIODevice::Text ))
	{
		//qDebug()<<"OPEN FILE FAILED";  
	}
	QTextStream txtinput(&fin);
	txtinput.setCodec("GBK");
	m_Lineitems = txtinput.readAll().split("\n");
	int TotalLines = m_Lineitems.count() - 1;
	for(int i = 0 ; i < TotalLines ; i++)
	{ 
		QStringList Unititem = m_Lineitems.at(i).split(",");
		int nInputOrOutput = Unititem.at(0).toInt();    //A:1-输入，2-输出
		int nStatusListChosen = Unititem.at(1).toInt(); //B:1-输入，2-输出，3-集屑，4-
		QString IOText = Unititem.at(2);//C
		QString IOAdrr = Unititem.at(3);//D
		int nLeftOrRight = Unititem.at(4).toInt();//E
		switch(g->m_nStatusListChosen)
		{
		case 1:
		case 2:
			if( nInputOrOutput == g->m_nStatusListChosen ){
				if(nLeftOrRight == 0){//左边
					if( !IOText.isEmpty() ){
						pLeftTreeWidgetItem = new SlGfwTreeWidgetItem(m_pLeftTreeWidget);
						pLeftTreeWidgetItem->setText(0, IOText);
						pLeftTreeWidgetItem->setTextAlignment(0, Qt::AlignCenter);
						pLeftTreeWidgetItem->setText(1, IOAdrr);
						pLeftTreeWidgetItem->setTextAlignment(1, Qt::AlignCenter);
						if( g->m_CurIOSignals[i] )
							pLeftTreeWidgetItem->setIcon(2,QIcon(szGreenIcon));
						else
							pLeftTreeWidgetItem->setIcon(2,QIcon(szGreyIcon));
						pLeftTreeWidgetItem->setTextAlignment(2, Qt::AlignCenter);
						
					}
				}
				if(nLeftOrRight == 1){//右边
					if( !IOText.isEmpty() ){
						pRightTreeWidgetItem = new SlGfwTreeWidgetItem(m_pRightTreeWidget);
						pRightTreeWidgetItem->setText(0, IOText);
						pRightTreeWidgetItem->setTextAlignment(0, Qt::AlignCenter);
						pRightTreeWidgetItem->setText(1, IOAdrr);
						pRightTreeWidgetItem->setTextAlignment(1, Qt::AlignCenter);
						if( g->m_CurIOSignals[i] )
							pRightTreeWidgetItem->setIcon(2,QIcon(szGreenIcon));
						else
							pRightTreeWidgetItem->setIcon(2,QIcon(szGreyIcon));
						pRightTreeWidgetItem->setTextAlignment(2, Qt::AlignCenter);

					}
				}
			}
			break;
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			if( nStatusListChosen == g->m_nStatusListChosen ){
				if(nLeftOrRight == 0){
					if( !IOText.isEmpty() ){
						pLeftTreeWidgetItem = new SlGfwTreeWidgetItem(m_pLeftTreeWidget);
						pLeftTreeWidgetItem->setText(0, IOText);
						pLeftTreeWidgetItem->setTextAlignment(0, Qt::AlignCenter);
						pLeftTreeWidgetItem->setText(1, IOAdrr);
						pLeftTreeWidgetItem->setTextAlignment(1, Qt::AlignCenter);
						if( g->m_CurIOSignals[i] )
							pLeftTreeWidgetItem->setIcon(2,QIcon(szGreenIcon));
						else
							pLeftTreeWidgetItem->setIcon(2,QIcon(szGreyIcon));
						pLeftTreeWidgetItem->setTextAlignment(2, Qt::AlignCenter);

					}
				}
				if(nLeftOrRight == 1){
					if( !IOText.isEmpty() ){
						pRightTreeWidgetItem = new SlGfwTreeWidgetItem(m_pRightTreeWidget);
						pRightTreeWidgetItem->setText(0, IOText);
						pRightTreeWidgetItem->setTextAlignment(0, Qt::AlignCenter);
						pRightTreeWidgetItem->setText(1, IOAdrr);
						pRightTreeWidgetItem->setTextAlignment(1, Qt::AlignCenter);
						if( g->m_CurIOSignals[i] )
							pRightTreeWidgetItem->setIcon(2,QIcon(szGreenIcon));
						else
							pRightTreeWidgetItem->setIcon(2,QIcon(szGreyIcon));
						pRightTreeWidgetItem->setTextAlignment(2, Qt::AlignCenter);

					}
				}
			}
			break;
		default:
			break;
		}
	}
	fin.close();
}

void StatusListForm::UpdateIOItems( )
{
	QMutexLocker locker(&m_Mutex); 

	SlGfwTreeWidgetItem* pLeftTreeWidgetItem;
	SlGfwTreeWidgetItem* pRightTreeWidgetItem;
	//RandomIOSignals( );

	if( m_pLeftTreeWidget->topLevelItemCount() == 0 && 
		m_pRightTreeWidget->topLevelItemCount() == 0 )
	{
		memcpy(g->m_PreIOSignals,g->m_CurIOSignals,sizeof(g->m_CurIOSignals));
		return;
	}

	int L_Index = 0;
	int R_Index = 0;
	int TotalLines = m_Lineitems.count() - 1;

	for(int i = 0 ; i < TotalLines ; i++)
	{ 
		QStringList Unititem = m_Lineitems.at(i).split(",");
		int nInputOrOutput = Unititem.at(0).toInt();
		int nStatusListChosen = Unititem.at(1).toInt();
		QString IOText = Unititem.at(2);
		//QString IOAdrr = Unititem.at(3);
		int nLeftOrRight = Unititem.at(4).toInt();
		bool CurSignal = g->m_CurIOSignals[i];
		bool PreSignal = g->m_PreIOSignals[i];
		switch(g->m_nStatusListChosen)
		{
		case 1:
		case 2:
			if( nInputOrOutput == g->m_nStatusListChosen ){
				if( nLeftOrRight == 0 && !IOText.isEmpty() ){
					if( CurSignal != PreSignal ){//状态变化时，更新指示灯显示状态。ligy 20190920 add
						pLeftTreeWidgetItem = m_pLeftTreeWidget->topLevelItem(L_Index);
						if( CurSignal )
							pLeftTreeWidgetItem->setIcon(2,QIcon(szGreenIcon));
						else
							pLeftTreeWidgetItem->setIcon(2,QIcon(szGreyIcon));
					}
					L_Index++;
				}
				if(nLeftOrRight == 1 && !IOText.isEmpty() ){
					if( CurSignal != PreSignal ){//状态变化时，更新指示灯显示状态。ligy 20190920 add
						pRightTreeWidgetItem = m_pRightTreeWidget->topLevelItem(R_Index);
						if( CurSignal )
							pRightTreeWidgetItem->setIcon(2,QIcon(szGreenIcon));
						else
							pRightTreeWidgetItem->setIcon(2,QIcon(szGreyIcon));
					}
					R_Index++;
				}
			}
			break;
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			if( nStatusListChosen == g->m_nStatusListChosen ){
				if(nLeftOrRight == 0 && !IOText.isEmpty() ){
					if( CurSignal != PreSignal ){//状态变化时，更新指示灯显示状态。ligy 20190920 add
						pLeftTreeWidgetItem = m_pLeftTreeWidget->topLevelItem(L_Index);
						if( CurSignal )
							pLeftTreeWidgetItem->setIcon(2,QIcon(szGreenIcon));
						else
							pLeftTreeWidgetItem->setIcon(2,QIcon(szGreyIcon));
					}
					L_Index++;
				}
				if(nLeftOrRight == 1 && !IOText.isEmpty() ){
					if( CurSignal != PreSignal ){//状态变化时，更新指示灯显示状态。ligy 20190920 add
						pRightTreeWidgetItem = m_pRightTreeWidget->topLevelItem(R_Index);
						if( CurSignal )
							pRightTreeWidgetItem->setIcon(2,QIcon(szGreenIcon));
						else
							pRightTreeWidgetItem->setIcon(2,QIcon(szGreyIcon));
					}
					R_Index++;
				}
			}
			break;
		default:
			break;
		}
	}
	memcpy(g->m_PreIOSignals,g->m_CurIOSignals,sizeof(g->m_CurIOSignals));
}

void StatusListForm::attachedToScreen(const QString& rszScreenName)
{
	if(g->m_bIsLogin==true)
		setStatusBarElementText(g_pIni->m_strLogin, 1);
	else
		setStatusBarElementText(g_pIni->m_strNotLogin, 1);

	//UpdateIOItems( );
	ListIOItems( );

	g_pStatusListForm = this;
}

void StatusListForm::detachedFromScreen(const QString& rszScreenName)
{
	g_pStatusListForm = 0;
}

///////////////////////////////////////////////////////////////////////////////
// public ACCESSORS
///////////////////////////////////////////////////////////////////////////////
void StatusListForm::TimeOutSlot( )
{
	UpdateIOItems( );
}

void StatusListForm::onFunction (const QString& rsFunction,
                                    const QString& rsArgs,
                                    bool& rbHandled)
{
	if ( "InputState" == rsFunction )//输入量
	{
		g->m_nStatusListChosen = 1;
		ListIOItems( );
		rbHandled = true;
	}
	if ( "OutputState" == rsFunction )//输出量
	{
		g->m_nStatusListChosen = 2;
		ListIOItems( );
		rbHandled = true;
	}
	if ( "HydraulicState" == rsFunction )//液压状态
	{
		g->m_nStatusListChosen = 3;
		ListIOItems( );
		rbHandled = true;
	}
	if ( "CollectorBinState" == rsFunction )//机械状态
	{
		g->m_nStatusListChosen = 4;
		ListIOItems( );
		rbHandled = true;
	}
	if ( "GrindState" == rsFunction )//打磨状态
	{
		g->m_nStatusListChosen = 5;
		ListIOItems( );
		rbHandled = true;
	}
	if ( "SMWAndLockState" == rsFunction )//测速轮和锁定状态
	{
		g->m_nStatusListChosen = 6;
		ListIOItems( );
		rbHandled = true;
	}
	if ( "BogyState" == rsFunction )//转向架
	{
		g->m_nStatusListChosen = 7;
		ListIOItems( );
		rbHandled = true;
	}
	// need to call the base class
	if ( false == rbHandled )
		SlGfwDialogForm::onFunction(rsFunction, rsArgs, rbHandled);
} // <-- StatusListForm::onFunction ()

void StatusListForm::RandomIOSignals( )
{
	qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
	int IOBitCount = IOBITCOUNT;								
	for(int i=0 ; i< IOBitCount; i++)
		g->m_CurIOSignals[i] = (char)(qrand()%2);
}

