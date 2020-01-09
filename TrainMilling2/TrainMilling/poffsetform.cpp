///////////////////////////////////////////////////////////////////////////////
/*! \file	poffsetform.cpp
 *  \author
 *  \date
 *  \brief	Implementation file for class CPOffsetForm
 *
 *  This file is part of the HMI Solutionline GUI Framework.
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////
#include "poffsetform.h"

///////////////////////////////////////////////////////////////////////////////
// CREATORS
///////////////////////////////////////////////////////////////////////////////

CPOffsetForm::CPOffsetForm(QWidget* pParent, const QString& rszName)
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

    this->L_CPOffsetGroupBox->setVisible(false);  
	this->R_CPOffsetGroupBox->setVisible(false);  

	//QObject::connect( H_LowPassFiltercheckBox,SIGNAL(stateChanged(int)),this,SLOT(H_LowPassFilterStateChanged(int)) );
	//QObject::connect( V_LowPassFiltercheckBox,SIGNAL(stateChanged(int)),this,SLOT(V_LowPassFilterStateChanged(int)) );

}// <-- CPOffsetForm::CPOffsetForm ()


CPOffsetForm::~CPOffsetForm(void)
{

} // <-- ::~ ()


///////////////////////////////////////////////////////////////////////////////
// public SLOTS - system overrides
///////////////////////////////////////////////////////////////////////////////
void CPOffsetForm::onFunction (const QString& rsFunction,
                                    const QString& rsArgs,
                                    bool& rbHandled)
{
 	// check null pointer
	if ( "H_LowPassFilter" == rsFunction )
	{
		g->m_H_bLowPassFilter = !g->m_H_bLowPassFilter;
		this->H_LowPassFiltercheckBox->setChecked(g->m_H_bLowPassFilter);
		this->H_SoftShoeDirRatioLineEdit1->setReadOnly(g->m_H_bLowPassFilter);
		this->H_SoftShoeDirRatioLineEdit2->setReadOnly(g->m_H_bLowPassFilter);
		this->H_SoftShoeLayerLineEdit->setReadOnly(g->m_H_bLowPassFilter);
		rbHandled = true;
	}
	else if ( "V_LowPassFilter" == rsFunction )
	{
		g->m_V_bLowPassFilter = !g->m_V_bLowPassFilter;
		this->V_LowPassFiltercheckBox->setChecked(g->m_V_bLowPassFilter);
		this->V_SoftShoeDirRatioLineEdit1->setReadOnly(g->m_V_bLowPassFilter);
		this->V_SoftShoeDirRatioLineEdit2->setReadOnly(g->m_V_bLowPassFilter);
		this->V_SoftShoeLayerLineEdit->setReadOnly(true);
		//this->V_SoftShoeLayerLineEdit->setReadOnly(g->m_V_bLowPassFilter);
		rbHandled = true;
	}
	else if ( "SaveParameter" == rsFunction )
	{
		SaveParametersToIni();
		DisplayCPOffsetParameters();
		//SaveParametersToCNC();
		setSoftkeyDisable(2, true);
		setSoftkeyDisable(3, true);
		setSoftkeyDisable(7, true);
		setLineEditReadOnly(true);
		rbHandled = true;
	}
	// need to call the base class
	if ( false == rbHandled )
		SlGfwDialogForm::onFunction(rsFunction, rsArgs, rbHandled);

} // <-- CPOffsetForm::onFunction ()


///////////////////////////////////////////////////////////////////////////////
// private methods
///////////////////////////////////////////////////////////////////////////////
void CPOffsetForm::attachedToScreen(const QString& rszScreenName)
{
	g->CalVSoftShoeLayer( );

	setLineEditReadOnly(false);
	DisplayCPOffsetParameters( );
	this->H_SoftShoeDirRatioLineEdit1->setReadOnly(g->m_H_bLowPassFilter);
	this->H_SoftShoeDirRatioLineEdit2->setReadOnly(g->m_H_bLowPassFilter);
	this->V_SoftShoeDirRatioLineEdit1->setReadOnly(g->m_V_bLowPassFilter);
	this->V_SoftShoeDirRatioLineEdit2->setReadOnly(g->m_V_bLowPassFilter);
	this->H_SoftShoeLayerLineEdit->setReadOnly(g->m_H_bLowPassFilter);
	this->V_SoftShoeLayerLineEdit->setReadOnly(true);
	//this->V_SoftShoeLayerLineEdit->setReadOnly(g->m_V_bLowPassFilter);

	if(g->m_bIsLogin==true)
		setStatusBarElementText(g_pIni->m_strLogin, 1);
	else
		setStatusBarElementText(g_pIni->m_strNotLogin, 1);

	g_pCPOffsetForm = this;
    // don't forget to call the standard implementation
    SlGfwDialogForm::attachedToScreen(rszScreenName);
}


void CPOffsetForm::detachedFromScreen(const QString& rszScreenName)
{
	g_pCPOffsetForm = 0;
    // don't forget to call the standard implementation
    SlGfwDialogForm::detachedFromScreen(rszScreenName);
}

void CPOffsetForm::DisplayCPOffsetParameters()
{
	this->LH_CPOffsetLineEdit1->setValue(g->m_LH_CPOffset1);
	this->LV_CPOffsetLineEdit1->setValue(g->m_LV_CPOffset1);
	this->RH_CPOffsetLineEdit1->setValue(g->m_RH_CPOffset1);
	this->RV_CPOffsetLineEdit1->setValue(g->m_RV_CPOffset1);
	this->LH_CPOffsetLineEdit2->setValue(g->m_LH_CPOffset2);
	this->LV_CPOffsetLineEdit2->setValue(g->m_LV_CPOffset2);
	this->RH_CPOffsetLineEdit2->setValue(g->m_RH_CPOffset2);
	this->RV_CPOffsetLineEdit2->setValue(g->m_RV_CPOffset2);

	this->H_SoftShoeLenLineEdit->setValue(g->m_H_SoftShoeLen);//横向软件靴长度
	this->V_SoftShoeLenLineEdit->setValue(g->m_V_SoftShoeLen);//纵向软件靴长度
	this->H_SoftShoeAlphaLineEdit->setValue(g->m_H_SoftShoeAlph);//横向软件靴惯性量
	this->V_SoftShoeAlphaLineEdit->setValue(g->m_V_SoftShoeAlph);//垂向软件靴惯性量
	this->H_SoftShoeLayerLineEdit->setValue(g->m_H_SoftShoeLayer);//横向软件靴分层数量
	this->V_SoftShoeLayerLineEdit->setValue(g->m_V_SoftShoeLayer);//垂向软件靴分层数量
	this->H_SoftShoeDirRatioLineEdit1->setValue(g->m_H_SoftShoeDirRatio1);//横向正反软件靴比重1
	this->H_SoftShoeDirRatioLineEdit2->setValue(g->m_H_SoftShoeDirRatio2);//横向正反软件靴比重2
	this->V_SoftShoeDirRatioLineEdit1->setValue(g->m_V_SoftShoeDirRatio1);//垂向正反软件靴比重1
	this->V_SoftShoeDirRatioLineEdit2->setValue(g->m_V_SoftShoeDirRatio2);//垂向正反软件靴比重2
	this->LH_SensorRatioLineEdit->setValue(g->m_LH_SensorRatio);//左侧横向传感器1->2比重,横向
	this->LV_SensorRatioLineEdit->setValue(g->m_LV_SensorRatio);//左侧垂向传感器1->2比重,垂向
	this->RH_SensorRatioLineEdit->setValue(g->m_RH_SensorRatio);//右侧横向传感器1->2比重,横向
	this->RV_SensorRatioLineEdit->setValue(g->m_RV_SensorRatio);//右侧垂向传感器1->2比重,垂向

	this->H_LowPassFiltercheckBox->setChecked(g->m_H_bLowPassFilter);//低通滤波 横向
	this->V_LowPassFiltercheckBox->setChecked(g->m_V_bLowPassFilter);//低通滤波 纵向

	if(g->m_LH_bSensorPriority)
		LH_SensorChoose1->setChecked(true);
	else
		LH_SensorChoose2->setChecked(true);

	if(g->m_LV_bSensorPriority)
		LV_SensorChoose1->setChecked(true);
	else
		LV_SensorChoose2->setChecked(true);

	if(g->m_RH_bSensorPriority)
		RH_SensorChoose1->setChecked(true);
	else
		RH_SensorChoose2->setChecked(true);

	if(g->m_RV_bSensorPriority)
		RV_SensorChoose1->setChecked(true);
	else
		RV_SensorChoose2->setChecked(true);

	if(g->m_bSoftShoeDir)
		SoftShoeDir1->setChecked(true);
	else
		SoftShoeDir2->setChecked(true);
}

void CPOffsetForm::SaveParametersToIni()
{
	g->m_LH_CPOffset1 = this->LH_CPOffsetLineEdit1->value().toDouble();
	g->m_LV_CPOffset1 = this->LV_CPOffsetLineEdit1->value().toDouble();
	g->m_RH_CPOffset1 = this->RH_CPOffsetLineEdit1->value().toDouble();
	g->m_RV_CPOffset1 = this->RV_CPOffsetLineEdit1->value().toDouble();
	g->m_LH_CPOffset2 = this->LH_CPOffsetLineEdit2->value().toDouble();
	g->m_LV_CPOffset2 = this->LV_CPOffsetLineEdit2->value().toDouble();
	g->m_RH_CPOffset2 = this->RH_CPOffsetLineEdit2->value().toDouble();
	g->m_RV_CPOffset2 = this->RV_CPOffsetLineEdit2->value().toDouble();

	g->m_H_SoftShoeLen = this->H_SoftShoeLenLineEdit->value().toDouble();
	g->m_V_SoftShoeLen = this->V_SoftShoeLenLineEdit->value().toDouble();
	g->m_H_SoftShoeAlph = this->H_SoftShoeAlphaLineEdit->value().toDouble();
	g->m_V_SoftShoeAlph = this->V_SoftShoeAlphaLineEdit->value().toDouble();
	g->m_H_SoftShoeDirRatio1 = this->H_SoftShoeDirRatioLineEdit1->value().toDouble();
	g->m_H_SoftShoeDirRatio2 = this->H_SoftShoeDirRatioLineEdit2->value().toDouble();
	g->m_V_SoftShoeDirRatio1 = this->V_SoftShoeDirRatioLineEdit1->value().toDouble();
	g->m_V_SoftShoeDirRatio2 = this->V_SoftShoeDirRatioLineEdit2->value().toDouble();
	g->m_LH_SensorRatio = this->LH_SensorRatioLineEdit->value().toDouble();
	g->m_LV_SensorRatio = this->LV_SensorRatioLineEdit->value().toDouble();
	g->m_RH_SensorRatio = this->RH_SensorRatioLineEdit->value().toDouble();
	g->m_RV_SensorRatio = this->RV_SensorRatioLineEdit->value().toDouble();

	g->m_H_SoftShoeLayer = this->H_SoftShoeLayerLineEdit->value().toInt();
	g->m_V_SoftShoeLayer = this->V_SoftShoeLayerLineEdit->value().toInt();

	g->m_H_bLowPassFilter = this->H_LowPassFiltercheckBox->isChecked();
	g->m_V_bLowPassFilter = this->V_LowPassFiltercheckBox->isChecked();

	if( LH_SensorChoose1->isChecked( ) )
		g->m_LH_bSensorPriority = true;
	else
		g->m_LH_bSensorPriority = false;

	if( LV_SensorChoose1->isChecked( ) )
		g->m_LV_bSensorPriority = true;
	else
		g->m_LV_bSensorPriority = false;

	if( RH_SensorChoose1->isChecked( ) )
		g->m_RH_bSensorPriority = true;
	else
		g->m_RH_bSensorPriority = false;

	if( RV_SensorChoose1->isChecked( ) )
		g->m_RV_bSensorPriority = true;
	else
		g->m_RV_bSensorPriority = false;

	if( SoftShoeDir1->isChecked( ) )
		g->m_bSoftShoeDir = true;
	else
		g->m_bSoftShoeDir = false;

	g->CalVSoftShoeLayer( );
	g->ChooseSensor();
	g_pIni->SaveCPOffsetParameters( );
}

void CPOffsetForm::SaveParametersToCNC()
{
#ifdef PARA_TO_NCU
	// fill multi read specification
	QVector<SlCapWriteSpecType>	vecWriteSpec;

	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_LH_CPOffset1,QVariant(g->m_LH_CPOffset1) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_LV_CPOffset1,QVariant(g->m_LV_CPOffset1) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_RH_CPOffset1,QVariant(g->m_RH_CPOffset1) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_RV_CPOffset1,QVariant(g->m_RV_CPOffset1) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_LH_CPOffset2,QVariant(g->m_LH_CPOffset2) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_LV_CPOffset2,QVariant(g->m_LV_CPOffset2) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_RH_CPOffset2,QVariant(g->m_RH_CPOffset2) ) );
	vecWriteSpec.append( SlCapWriteSpecType(g_pIni->mstrNcu_RV_CPOffset2,QVariant(g->m_RV_CPOffset2) ) );
	// initialize result specification
	QVector<SlCapWriteResultType> vecWriteResult;

	// write data
	SlCapErrorEnum eError = m_capServer.multiWrite(vecWriteSpec, &vecWriteResult);

	// write success or error to the status bar
	handleRetVal(eError);
#endif
}

void CPOffsetForm::handleRetVal(SlCapErrorEnum eError)
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

void CPOffsetForm::setSoftkeyDisable(int nSoftkey, bool bDisabled)
{
	// get pointer to screen
	SlGfwScreen* pScreen = dialog()->screenRef("CPOffsetSreen");

	if ( 0 != pScreen )
	{
		// get pointer to softkey
		SlGfwSoftKey* pSoftkey = pScreen->menuSoftkey("CPOffsetVr", nSoftkey);
		
		// enable/disable softkey
		if ( 0 != pSoftkey )
			pSoftkey->setDisabled(bDisabled);
	}
}

void CPOffsetForm::setLineEditReadOnly(bool bReadOnly)
{
	this->LH_CPOffsetLineEdit1->setReadOnly(bReadOnly);
	this->LV_CPOffsetLineEdit1->setReadOnly(bReadOnly);
	this->RH_CPOffsetLineEdit1->setReadOnly(bReadOnly);
	this->RV_CPOffsetLineEdit1->setReadOnly(bReadOnly);
	this->LH_CPOffsetLineEdit2->setReadOnly(bReadOnly);
	this->LV_CPOffsetLineEdit2->setReadOnly(bReadOnly);
	this->RH_CPOffsetLineEdit2->setReadOnly(bReadOnly);
	this->RV_CPOffsetLineEdit2->setReadOnly(bReadOnly);

	this->H_SoftShoeLenLineEdit->setReadOnly(bReadOnly);
	this->V_SoftShoeLenLineEdit->setReadOnly(bReadOnly);
	this->H_SoftShoeAlphaLineEdit->setReadOnly(bReadOnly);
	this->V_SoftShoeAlphaLineEdit->setReadOnly(bReadOnly);
	this->H_SoftShoeLayerLineEdit->setReadOnly(bReadOnly);
	this->V_SoftShoeLayerLineEdit->setReadOnly(true);
	//this->V_SoftShoeLayerLineEdit->setReadOnly(bReadOnly);
	this->H_SoftShoeDirRatioLineEdit1->setReadOnly(bReadOnly);
	this->V_SoftShoeDirRatioLineEdit1->setReadOnly(bReadOnly);
	this->H_SoftShoeDirRatioLineEdit2->setReadOnly(bReadOnly);
	this->V_SoftShoeDirRatioLineEdit2->setReadOnly(bReadOnly);
	this->LH_SensorRatioLineEdit->setReadOnly(bReadOnly);
	this->LV_SensorRatioLineEdit->setReadOnly(bReadOnly);
	this->RH_SensorRatioLineEdit->setReadOnly(bReadOnly);
	this->RV_SensorRatioLineEdit->setReadOnly(bReadOnly);
}

/*
void CPOffsetForm::H_LowPassFilterStateChanged(int state)
{
	//g->m_H_bLowPassFilter = this->H_LowPassFiltercheckBox->isChecked();
	this->H_SoftShoeDirRatioLineEdit1->setReadOnly(g->m_H_bLowPassFilter);
	this->H_SoftShoeDirRatioLineEdit2->setReadOnly(g->m_H_bLowPassFilter);
}

void CPOffsetForm::V_LowPassFilterStateChanged(int state)
{
	//g->m_V_bLowPassFilter = this->V_LowPassFiltercheckBox->isChecked();
	this->V_SoftShoeDirRatioLineEdit1->setReadOnly(g->m_V_bLowPassFilter);
	this->V_SoftShoeDirRatioLineEdit2->setReadOnly(g->m_V_bLowPassFilter);
}
*/