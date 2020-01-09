///////////////////////////////////////////////////////////////////////////////
/*! \file	softlimitform.cpp
 *  \author
 *  \date
 *  \brief	Implementation file for class SoftLimitForm
 *
 *  This file is part of the HMI Solutionline GUI Framework.
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////
#include "softlimitform.h"



///////////////////////////////////////////////////////////////////////////////
// CREATORS
///////////////////////////////////////////////////////////////////////////////

SoftLimitForm::SoftLimitForm(QWidget* pParent, const QString& rszName)
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

}// <-- SoftLimitForm::SoftLimitForm ()


SoftLimitForm::~SoftLimitForm(void)
{

} // <-- ::~ ()


void SoftLimitForm::onFunction (const QString& rsFunction,
                                    const QString& rsArgs,
                                    bool& rbHandled)
{
	if ( "SaveParameter" == rsFunction )
	{
		SaveParametersToIni( );
		setSoftkeyDisable(7, true);
		setLineEditReadOnly(true);
	}
	// need to call the base class
	if ( false == rbHandled )
		SlGfwDialogForm::onFunction(rsFunction, rsArgs, rbHandled);

} // <-- SoftLimitForm::onFunction ()


void SoftLimitForm::attachedToScreen(const QString& rszScreenName)
{
	if(g->m_bIsLogin==true)
		setStatusBarElementText(g_pIni->m_strLogin, 1);
	else
		setStatusBarElementText(g_pIni->m_strNotLogin, 1);

	g->CalCutBiasStep( );

	RefreshParameters( );
	setLineEditReadOnly(false);
	g_pSoftLimitFormForm = this;
    // don't forget to call the standard implementation
    SlGfwDialogForm::attachedToScreen(rszScreenName);
}

void SoftLimitForm::detachedFromScreen(const QString& rszScreenName)
{
	g_pSoftLimitFormForm = 0;
    // don't forget to call the standard implementation
    SlGfwDialogForm::detachedFromScreen(rszScreenName);
}

void SoftLimitForm::SaveParametersToIni( )
{
	g->m_LH_MotorPosHigh = LH_MotorLimitPosHighLineEdit->value().toDouble();//横向电机上限位 左
	g->m_LH_MotorPosLow = LH_MotorLimitPosLowLineEdit->value().toDouble();//横向电机下限位 左
	g->m_LV_MotorPosHigh = LV_MotorLimitPosHighLineEdit->value().toDouble();//垂向电机上限位 左
	g->m_LV_MotorPosLow = LV_MotorLimitPosLowLineEdit->value().toDouble();//垂向电机下限位 左
	g->m_RH_MotorPosHigh = RH_MotorLimitPosHighLineEdit->value().toDouble();//横向电机上限位 右
	g->m_RH_MotorPosLow = RH_MotorLimitPosLowLineEdit->value().toDouble();//横向电机下限位 右
	g->m_RV_MotorPosHigh = RV_MotorLimitPosHighLineEdit->value().toDouble();//垂向电机上限位 右
	g->m_RV_MotorPosLow = RV_MotorLimitPosLowLineEdit->value().toDouble();//垂向电机下限位 右

	g->m_LH_CutterProtect = LH_CutterProtectLineEdit->value().toDouble();//横向进刀保护 左
	g->m_LV_CutterProtect = LV_CutterProtectLineEdit->value().toDouble();//垂向进刀保护 左
	g->m_RH_CutterProtect = RH_CutterProtectLineEdit->value().toDouble();//横向进刀保护 右
	g->m_RV_CutterProtect = RV_CutterProtectLineEdit->value().toDouble();//垂向进刀保护 右

	g->m_H_CutBiasStep = H_CutBiasStepLineEdit->value().toDouble();//横向分步进刀值
	g->m_V_CutBiasStep = V_CutBiasStepLineEdit->value().toDouble();//垂向分步进刀值
	g->m_H_MinCutStep = H_MinCutStepLineEdit->value().toDouble();//横向最小进刀量
	g->m_V_MinCutStep = V_MinCutStepLineEdit->value().toDouble();//垂向最小进刀量
	g_pIni->SaveSoftLimitParameters( );

}

void SoftLimitForm::RefreshParameters( )
{
	LH_MotorLimitPosHighLineEdit->setValue(g->m_LH_MotorPosHigh);
	LH_MotorLimitPosLowLineEdit->setValue(g->m_LH_MotorPosLow);
	LV_MotorLimitPosHighLineEdit->setValue(g->m_LV_MotorPosHigh);
	LV_MotorLimitPosLowLineEdit->setValue(g->m_LV_MotorPosLow);
	RH_MotorLimitPosHighLineEdit->setValue(g->m_RH_MotorPosHigh);
	RH_MotorLimitPosLowLineEdit->setValue(g->m_RH_MotorPosLow);
	RV_MotorLimitPosHighLineEdit->setValue(g->m_RV_MotorPosHigh);
	RV_MotorLimitPosLowLineEdit->setValue(g->m_RV_MotorPosLow);

	LH_CutterProtectLineEdit->setValue(g->m_LH_CutterProtect);
	LV_CutterProtectLineEdit->setValue(g->m_LV_CutterProtect);
	RH_CutterProtectLineEdit->setValue(g->m_RH_CutterProtect);
	RV_CutterProtectLineEdit->setValue(g->m_RV_CutterProtect);

	H_CutBiasStepLineEdit->setValue(double2double(g->m_H_CutBiasStep));
	V_CutBiasStepLineEdit->setValue(double2double(g->m_V_CutBiasStep));
	H_MinCutStepLineEdit->setValue(g->m_H_MinCutStep);
	V_MinCutStepLineEdit->setValue(g->m_V_MinCutStep);
}

void SoftLimitForm::setLineEditReadOnly(bool bReadOnly)
{
	this->LH_MotorLimitPosHighLineEdit->setReadOnly(bReadOnly);
	this->LH_MotorLimitPosLowLineEdit->setReadOnly(bReadOnly);
	this->LV_MotorLimitPosHighLineEdit->setReadOnly(bReadOnly);
	this->LV_MotorLimitPosLowLineEdit->setReadOnly(bReadOnly);
	this->RH_MotorLimitPosHighLineEdit->setReadOnly(bReadOnly);
	this->RH_MotorLimitPosLowLineEdit->setReadOnly(bReadOnly);
	this->RV_MotorLimitPosHighLineEdit->setReadOnly(bReadOnly);
	this->RV_MotorLimitPosLowLineEdit->setReadOnly(bReadOnly);
	this->LH_CutterProtectLineEdit->setReadOnly(bReadOnly);
	this->LV_CutterProtectLineEdit->setReadOnly(bReadOnly);
	this->RH_CutterProtectLineEdit->setReadOnly(bReadOnly);
	this->RV_CutterProtectLineEdit->setReadOnly(bReadOnly);
	this->H_CutBiasStepLineEdit->setReadOnly(true);
	this->V_CutBiasStepLineEdit->setReadOnly(true);
	this->H_MinCutStepLineEdit->setReadOnly(bReadOnly);
	this->V_MinCutStepLineEdit->setReadOnly(bReadOnly);
}

void SoftLimitForm::setSoftkeyDisable(int nSoftkey, bool bDisabled)
{
	// get pointer to screen
	SlGfwScreen* pScreen = dialog()->screenRef("SoftLimitSreen");

	if ( 0 != pScreen )
	{
		// get pointer to softkey
		SlGfwSoftKey* pSoftkey = pScreen->menuSoftkey("SoftLimitVr", nSoftkey);
		
		// enable/disable softkey
		if ( 0 != pSoftkey )
			pSoftkey->setDisabled(bDisabled);
	}
}

double SoftLimitForm::double2double(double input_d)
{
	double r_double = 0;
	input_d*=10000.000;
	int tmp = input_d;
	r_double = tmp/10000.000;
	return r_double;
}