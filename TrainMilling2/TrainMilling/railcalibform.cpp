///////////////////////////////////////////////////////////////////////////////
/*! \file	railcalibform.cpp
 *  \author
 *  \date
 *  \brief	Implementation file for class RailCalibForm
 *
 *  This file is part of the HMI Solutionline GUI Framework.
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////
#include "railcalibform.h"
#include "QDateTime.h"
#include "GlobalVar.h"

///////////////////////////////////////////////////////////////////////////////
// CREATORS
///////////////////////////////////////////////////////////////////////////////

RailCalibForm::RailCalibForm(QWidget* pParent, const QString& rszName)
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

}// <-- RailCalibForm::RailCalibForm ()


RailCalibForm::~RailCalibForm(void)
{

} // <-- ::~ ()


///////////////////////////////////////////////////////////////////////////////
// Overrides
///////////////////////////////////////////////////////////////////////////////

void RailCalibForm::attachedToScreen(const QString& rszScreenName)
{
	if(g->m_bIsLogin==true)
		setStatusBarElementText(g_pIni->m_strLogin, 1);
	else
		setStatusBarElementText(g_pIni->m_strNotLogin, 1);

	L_ScannerToCutterOffsetLineEdit->setReadOnly(false);//�������뵶�̺���ƫ��  ��ϳ����Ԫ
	R_ScannerToCutterOffsetLineEdit->setReadOnly(false);//�������뵶�̺���ƫ��  ��ϳ����Ԫ
	LH_CuttingDepthOffsetLineEdit->setReadOnly(false);//��������ƫ�� ��ϳ����Ԫ
	LV_CuttingDepthOffsetLineEdit->setReadOnly(false);//��������ƫ�� ��ϳ����Ԫ
	RH_CuttingDepthOffsetLineEdit->setReadOnly(false);//��������ƫ�� ��ϳ����Ԫ
	RV_CuttingDepthOffsetLineEdit->setReadOnly(false);//��������ƫ�� ��ϳ����Ԫ
	m_bStopFresh = false;
	DisplayIniParameters( );

	g_pRailCalibForm = this;
    // don't forget to call the standard implementation
    SlGfwDialogForm::attachedToScreen(rszScreenName);
}


void RailCalibForm::detachedFromScreen(const QString& rszScreenName)
{
	g_pRailCalibForm = 0;
    // don't forget to call the standard implementation
    SlGfwDialogForm::detachedFromScreen(rszScreenName);
}

///////////////////////////////////////////////////////////////////////////////
// public SLOTS - system overrides
///////////////////////////////////////////////////////////////////////////////
void RailCalibForm::onFunction (const QString& rsFunction,
                                    const QString& rsArgs,
                                    bool& rbHandled)
{
  	if ( "StaticSave" == rsFunction )
	{
		SaveParametersToIni( STATIC_SAVE );
		SaveParametersToCNC( );
		L_ScannerToCutterOffsetLineEdit->setReadOnly(true);
		R_ScannerToCutterOffsetLineEdit->setReadOnly(true);
		LH_CuttingDepthOffsetLineEdit->setReadOnly(true);
		LV_CuttingDepthOffsetLineEdit->setReadOnly(true);
		RH_CuttingDepthOffsetLineEdit->setReadOnly(true);
		RV_CuttingDepthOffsetLineEdit->setReadOnly(true);
		rbHandled = true;
	}
	if ( "DynamicSave" == rsFunction )
	{
		m_bStopFresh = true;
		SaveParametersToIni( DYNAMIC_SAVE );
		SaveParametersToCNC( );
		rbHandled = true;
	}
	// need to call the base class
	if ( false == rbHandled )
		SlGfwDialogForm::onFunction(rsFunction, rsArgs, rbHandled);
} // <-- RailCalibForm::onFunction ()


///////////////////////////////////////////////////////////////////////////////
// private methods
///////////////////////////////////////////////////////////////////////////////
void RailCalibForm::SaveParametersToIni(  int nType  )
{
	switch(nType)
	{
	case STATIC_SAVE:
		g->m_LScannerToCutterOffset = L_ScannerToCutterOffsetLineEdit->value().toDouble();
		g->m_RScannerToCutterOffset = R_ScannerToCutterOffsetLineEdit->value().toDouble();
		g->m_LH_CutDepthOffset = LH_CuttingDepthOffsetLineEdit->value().toDouble();
		g->m_LV_CutDepthOffset = LV_CuttingDepthOffsetLineEdit->value().toDouble();
		g->m_RH_CutDepthOffset = RH_CuttingDepthOffsetLineEdit->value().toDouble();
		g->m_RV_CutDepthOffset = RV_CuttingDepthOffsetLineEdit->value().toDouble();
		g_pIni->SaveRailCalibParameters( STATIC_SAVE );
		setSoftkeyDisable(3, true);
		break;
	case DYNAMIC_SAVE:
		g->m_LH_MotorCalibPos = LH_MotorCalibPosLineEdit->value().toDouble();
		g->m_LV_MotorCalibPos = LV_MotorCalibPosLineEdit->value().toDouble();
		g->m_RH_MotorCalibPos = RH_MotorCalibPosLineEdit->value().toDouble();
		g->m_RV_MotorCalibPos = RV_MotorCalibPosLineEdit->value().toDouble();
		g->m_LH_SensorCalibPos1 = LH_SensorCalibPosLineEdit1->value().toDouble();
		g->m_LV_SensorCalibPos1 = LV_SensorCalibPosLineEdit1->value().toDouble();
		g->m_RH_SensorCalibPos1 = RH_SensorCalibPosLineEdit1->value().toDouble();
		g->m_RV_SensorCalibPos1 = RV_SensorCalibPosLineEdit1->value().toDouble();
		g->m_LH_SensorCalibPos2 = LH_SensorCalibPosLineEdit2->value().toDouble();
		g->m_LV_SensorCalibPos2 = LV_SensorCalibPosLineEdit2->value().toDouble();
		g->m_RH_SensorCalibPos2 = RH_SensorCalibPosLineEdit2->value().toDouble();
		g->m_RV_SensorCalibPos2 = RV_SensorCalibPosLineEdit2->value().toDouble();

		g_pIni->SaveRailCalibParameters( DYNAMIC_SAVE );
		setSoftkeyDisable(7, true);
		break;
	default:
		break;
	}
}

void RailCalibForm::SaveParametersToCNC( )
{
#ifdef PARA_TO_NCU
	// fill multi read specification
	QVector<SlCapWriteSpecType>	vecWriteSpec;
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_LH_MotorCalibPos,QVariant(g->m_LH_MotorCalibPos) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_LV_MotorCalibPos,QVariant(g->m_LV_MotorCalibPos) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_RH_MotorCalibPos,QVariant(g->m_RH_MotorCalibPos) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_RV_MotorCalibPos,QVariant(g->m_RV_MotorCalibPos) ) );
	// initialize result specification
	QVector<SlCapWriteResultType> vecWriteResult;

	// write data
	SlCapErrorEnum eError = m_capServer.multiWrite(vecWriteSpec, &vecWriteResult);

	// write success or error to the status bar
	handleRetVal(eError);
#endif
}

//Read Parameters From Ini Files
void RailCalibForm::DisplayIniParameters( ) //ligy 20190918 add�����ע��
{
	LH_MotorCalibPosLineEdit->setValue(g->m_LH_MotorCalibPos);//������ ��
	LV_MotorCalibPosLineEdit->setValue(g->m_LV_MotorCalibPos);//������ ��
	RH_MotorCalibPosLineEdit->setValue(g->m_RH_MotorCalibPos);//������ ��
	RV_MotorCalibPosLineEdit->setValue(g->m_RV_MotorCalibPos);//������ ��
	LH_SensorCalibPosLineEdit1->setValue(g->m_LH_SensorCalibPos1);//Y1����(1)
	LV_SensorCalibPosLineEdit1->setValue(g->m_LV_SensorCalibPos1);//Z1����(1)
	RH_SensorCalibPosLineEdit1->setValue(g->m_RH_SensorCalibPos1);//Y2����(1)
	RV_SensorCalibPosLineEdit1->setValue(g->m_RV_SensorCalibPos1);//Z2����(1)
	LH_SensorCalibPosLineEdit2->setValue(g->m_LH_SensorCalibPos2);//Y1����(2)
	LV_SensorCalibPosLineEdit2->setValue(g->m_LV_SensorCalibPos2);//Z1����(2)
	RH_SensorCalibPosLineEdit2->setValue(g->m_RH_SensorCalibPos2);//Y2����(2)
	RV_SensorCalibPosLineEdit2->setValue(g->m_RV_SensorCalibPos2);//Z2����(2)
	L_ScannerToCutterOffsetLineEdit->setValue(g->m_LScannerToCutterOffset);//�������뵶�̺���ƫ�� ��
	R_ScannerToCutterOffsetLineEdit->setValue(g->m_RScannerToCutterOffset);//�������뵶�̺���ƫ�� ��
	LH_CuttingDepthOffsetLineEdit->setValue(g->m_LH_CutDepthOffset);//��������ƫ�� ��
	LV_CuttingDepthOffsetLineEdit->setValue(g->m_LV_CutDepthOffset);//��������ƫ�� ��
	RH_CuttingDepthOffsetLineEdit->setValue(g->m_RH_CutDepthOffset);//��������ƫ�� ��
	RV_CuttingDepthOffsetLineEdit->setValue(g->m_RV_CutDepthOffset);//��������ƫ�� ��
}

//Read Parameters From Sensors
void RailCalibForm::FreshParameters( )
{
	if(m_bStopFresh == false)
	{
		LH_MotorCalibPosLineEdit->setValue(g->double2double(g->mf_LH_MotorCurPos));
		LV_MotorCalibPosLineEdit->setValue(g->double2double(g->mf_LV_MotorCurPos));
		RH_MotorCalibPosLineEdit->setValue(g->double2double(g->mf_RH_MotorCurPos));
		RV_MotorCalibPosLineEdit->setValue(g->double2double(g->mf_RV_MotorCurPos));
		LH_SensorCalibPosLineEdit1->setValue(g->double2double(g->mf_LH_SensorCurValue1));
		LV_SensorCalibPosLineEdit1->setValue(g->double2double(g->mf_LV_SensorCurValue1));
		RH_SensorCalibPosLineEdit1->setValue(g->double2double(g->mf_RH_SensorCurValue1));
		RV_SensorCalibPosLineEdit1->setValue(g->double2double(g->mf_RV_SensorCurValue1));
		LH_SensorCalibPosLineEdit2->setValue(g->double2double(g->mf_LH_SensorCurValue2));
		LV_SensorCalibPosLineEdit2->setValue(g->double2double(g->mf_LV_SensorCurValue2));
		RH_SensorCalibPosLineEdit2->setValue(g->double2double(g->mf_RH_SensorCurValue2));
		RV_SensorCalibPosLineEdit2->setValue(g->double2double(g->mf_RV_SensorCurValue2));
	}
}

void RailCalibForm::setSoftkeyDisable(int nSoftkey, bool bDisabled)
{
	// get pointer to screen
	SlGfwScreen* pScreen = dialog()->screenRef("RailCalibSreen");

	if ( 0 != pScreen )
	{
		// get pointer to softkey
		SlGfwSoftKey* pSoftkey = pScreen->menuSoftkey("RailCalibVr", nSoftkey);
		
		// enable/disable softkey
		if ( 0 != pSoftkey )
			pSoftkey->setDisabled(bDisabled);
	}
}

void RailCalibForm::handleRetVal( SlCapErrorEnum eError )
{
	// evaluate return value
	if( SL_CAP_OK != eError )
	{
		// write error in status bar
		QString szHexErrorNr = QString("%1").arg(eError,0,16).right(8);
		setStatusBarElementText(ACCESS_ERROR.arg(szHexErrorNr), 0); 
		g_pErr->m_nErrorCode |= g_pErr->m_nCNCConnectionError;

		//Inner communication Error
		g->m_bPcuCommState = false;
		g_pErr->createPCUCOMAlarm();
	}
}