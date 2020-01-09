
#pragma once

#ifndef GLOBALVAR_H_INCLUDED
#define GLOBALVAR_H_INCLUDED


#include "QString.h"
#include "OperateIni.h"
#include "GlobalData.h"
#include "ErrorData.h"

class TrainMillingdialog;
class ScanForm;
class OperateManualForm;
class OperateNoticeForm;
class StatusForm;
class PowerForm;
class DebugForm;
class ErrorForm;
class ParameterForm;
class RecordForm;
class SystemForm;
class MainForm;
class StatusListForm;
class RailCalibForm;
class CPOffsetForm;
class UserManagerForm;
class ConfirmForm;
class DeviceRepair;
class DebugModeForm;//ligy 20191205 add
class SoftLimitForm;
class OperateIni;
class GlobalData;
class ErrorData;
class QTcuCom;


//using namespace ScannerChoose;
//using namespace ErrorCode;

/*--------------------------------------------
 *about the background actions
 *--------------------------------------------
 */
extern  TrainMillingdialog*	g_pDialog;
extern  ScanForm*			g_pScanForm; 
extern  OperateManualForm*	g_pOperateManualForm; 
extern  OperateNoticeForm*	g_pOperateNoticeForm; 
extern  StatusForm*			g_pStatusForm; 
extern  PowerForm*			g_pPowerForm; 
extern  DebugForm*			g_pDebugForm; 
extern  ErrorForm*			g_pErrorForm; 
extern  ParameterForm*		g_pParameterForm; 
extern  RecordForm*			g_pRecordForm; 
extern  SystemForm*			g_pSystemForm; 
extern  MainForm*			g_pMainForm; 
extern	StatusListForm*		g_pStatusListForm;
extern	RailCalibForm*		g_pRailCalibForm;
extern	CPOffsetForm*		g_pCPOffsetForm;
extern	UserManagerForm*	g_pUserManagerForm;
extern	ConfirmForm*		g_pConfirmForm;
extern	DeviceRepair*		g_pDeviceRepairForm;
extern  DebugModeForm*      g_pDebugModeForm;//ligy 20191205 add
extern	SoftLimitForm*		g_pSoftLimitFormForm;
extern  OperateIni*			g_pIni;
extern	ErrorData*			g_pErr;
extern	QTcuCom*			g_pTcu;
extern	GlobalData*			g;

extern	QString				szRedStyle;
extern	QString				szGreenStyle;
extern	QString				szYellowStyle;
extern	QString				szGreyStyle;

extern	QString				szRedIcon;
extern	QString				szGreenIcon;
extern	QString				szYellowIcon;
extern	QString				szGreyIcon;

extern	QString				szRedColor;
extern	QString				szGreyColor;
extern	QString				szDarkGreyColor;
#endif // GLOBALVAR_H_INCLUDED