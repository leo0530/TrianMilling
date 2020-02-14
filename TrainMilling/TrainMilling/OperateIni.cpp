#include "OperateIni.h"
#include "GlobalVar.h"

//------------------------------------------Workling Parameters------------------------//
#define PCU_LH_CUTTINGDEPTH  "/Parameter/PCU_LH_CuttingDepth"
#define PCU_LV_CUTTINGDEPTH  "/Parameter/PCU_LV_CuttingDepth"
#define PCU_RH_CUTTINGDEPTH  "/Parameter/PCU_RH_CuttingDepth"
#define PCU_RV_CUTTINGDEPTH  "/Parameter/PCU_RV_CuttingDepth"
#define PCU_LH_CUTTINGDEPTHOFFSET  "/Parameter/PCU_LH_CuttingDepthOffset"
#define PCU_LV_CUTTINGDEPTHOFFSET  "/Parameter/PCU_LV_CuttingDepthOffset"
#define PCU_RH_CUTTINGDEPTHOFFSET  "/Parameter/PCU_RH_CuttingDepthOffset"
#define PCU_RV_CUTTINGDEPTHOFFSET  "/Parameter/PCU_RV_CuttingDepthOffset"
#define PCU_H_DEVICEINIPOS  "/Parameter/PCU_H_DeviceIniPos"
#define PCU_V_DEVICEINIPOS  "/Parameter/PCU_V_DeviceIniPos"
#define PCU_H_WORKINIPOS  "/Parameter/PCU_H_WorkIniPos"
#define PCU_V_WORKINIPOS  "/Parameter/PCU_V_WorkIniPos"
#define PCU_TRAINSPEED  "/Parameter/PCU_TrainSpeed"
#define PCU_TRAINSPEEDDIFF "/Parameter/PCU_TrainSpeedDiff" // ligy 20190908 add .速度超差范围
#define PCU_TRAINSPEEDDIFFTIME "/Parameter/PCU_TrainSpeedDiffTime" // ligy 20190908 add .速度超差范围
#define PCU_SLOPELENGTH  "/Parameter/PCU_SlopeLength"
#define PCU_LV_POWERCONTROLVALUE  "/Parameter/PCU_LV_PowerControlValue"
#define PCU_RV_POWERCONTROLVALUE  "/Parameter/PCU_RV_PowerControlValue"
#define PCU_POWERCONTROLSELECT  "/Parameter/PCU_PowerControlSelect"

#define NCU_LH_CUTTINGDEPTH  "/Parameter/NCU_LH_CuttingDepth"
#define NCU_LV_CUTTINGDEPTH  "/Parameter/NCU_LV_CuttingDepth"
#define NCU_RH_CUTTINGDEPTH  "/Parameter/NCU_RH_CuttingDepth"
#define NCU_RV_CUTTINGDEPTH  "/Parameter/NCU_RV_CuttingDepth"
#define NCU_H_DEVICEINIPOS_CH1  "/Parameter/NCU_H_DeviceIniPos_ch1"
#define NCU_H_DEVICEINIPOS_CH2  "/Parameter/NCU_H_DeviceIniPos_ch2"
#define NCU_V_DEVICEINIPOS_CH1  "/Parameter/NCU_V_DeviceIniPos_ch1"
#define NCU_V_DEVICEINIPOS_CH2  "/Parameter/NCU_V_DeviceIniPos_ch2"
#define NCU_H_WORKINIPOS_CH1  "/Parameter/NCU_H_WorkIniPos_ch1"
#define NCU_H_WORKINIPOS_CH2  "/Parameter/NCU_H_WorkIniPos_ch2"
#define NCU_V_WORKINIPOS_CH1  "/Parameter/NCU_V_WorkIniPos_ch1"
#define NCU_V_WORKINIPOS_CH2  "/Parameter/NCU_V_WorkIniPos_ch2"
#define NCU_TRAINSPEED_CH1  "/Parameter/NCU_TrainSpeed_ch1"
#define NCU_TRAINSPEED_CH2  "/Parameter/NCU_TrainSpeed_ch2"
#define NCU_SLOPELENGTH_CH1  "/Parameter/NCU_SlopeLength_ch1"
#define NCU_SLOPELENGTH_CH2  "/Parameter/NCU_SlopeLength_ch2"

#define PLC_LH_CUTTINGDEPTH  "/Parameter/PLC_LH_CuttingDepth"
#define PLC_LV_CUTTINGDEPTH  "/Parameter/PLC_LV_CuttingDepth"
#define PLC_RH_CUTTINGDEPTH  "/Parameter/PLC_RH_CuttingDepth"
#define PLC_RV_CUTTINGDEPTH  "/Parameter/PLC_RV_CuttingDepth"
#define PLC_H_DEVICEINIPOS  "/Parameter/PLC_H_DeviceIniPos"
#define PLC_V_DEVICEINIPOS  "/Parameter/PLC_V_DeviceIniPos"
#define PLC_H_WORKINIPOS  "/Parameter/PLC_H_WorkIniPos"
#define PLC_V_WORKINIPOS  "/Parameter/PLC_V_WorkIniPos"
#define PLC_TRAINSPEED  "/Parameter/PLC_TrainSpeed"
#define PLC_SLOPELENGTH  "/Parameter/PLC_SlopeLength"

#define PCU_AXISLINEHIGHSPEED  "/Parameter/PCU_AxisLineHighSpeed"
#define PCU_AXISLINELOWERSPEED  "/Parameter/PCU_AxisLineLowerSpeed"
#define PCU_LEFTANDRIGHTUNIT  "/Parameter/LeftAndRightUnit"
#define PCU_LEFTUNIT  "/Parameter/LeftUnit"
#define PCU_RIGHTUNIT  "/Parameter/RightUnit"
#define PCU_NONEUNIT "/Parameter/NoneUnit"
/*
#define PLC_LUNITSELECTFLAG  "/Parameter/PLC_LUnitSelectFlag"
#define PLC_RUNITSELECTFLAG  "/Parameter/PLC_RUnitSelectFlag"
#define PLC_AXISHIGHSPEEDFLAG  "/Parameter/PLC_AxisHighSpeedFlag"
#define PLC_AUTOMILLINGFLAG  "/Parameter/PLC_AutoMillingFlag"
#define PLC_UNITLOCKEDFLAG  "/Parameter/PLC_UnitLockedFlag"
#define PLC_AXISSPEED  "/Parameter/PLC_AxisSpeed"
*/
#define  RST_LH_CUTTINGDEPTH  "/Parameter/RST_LH_CuttingDepth"
#define  RST_LV_CUTTINGDEPTH  "/Parameter/RST_LV_CuttingDepth"
#define  RST_RH_CUTTINGDEPTH  "/Parameter/RST_RH_CuttingDepth"
#define  RST_RV_CUTTINGDEPTH  "/Parameter/RST_RV_CuttingDepth"
#define  RST_H_DEVICEINIPOS  "/Parameter/RST_H_DeviceIniPos"
#define  RST_V_DEVICEINIPOS  "/Parameter/RST_V_DeviceIniPos"
#define  RST_H_WORKINIPOS  "/Parameter/RST_H_WorkIniPos"
#define  RST_V_WORKINIPOS  "/Parameter/RST_V_WorkIniPos"
#define  RST_TRAINSPEED  "/Parameter/RST_TrainSpeed"
#define  RST_SLOPELENGTH  "/Parameter/RST_SlopeLength"
#define  RST_AXISLINEHIGHSPEED  "/Parameter/RST_AxisLineHighSpeed"
#define  RST_AXISLINELOWERSPEED  "/Parameter/RST_AxisLineLowerSpeed"

//------------------------------------------System Parameters------------------------//
#define  PCU_LH_RAILOFFSET "/System/PCU_LH_RailOffset"
#define  PCU_LV_RAILOFFSET "/System/PCU_LV_RailOffset"
#define  PCU_RH_RAILOFFSET "/System/PCU_RH_RailOffset"
#define  PCU_RV_RAILOFFSET "/System/PCU_RV_RailOffset"
#define  PCU_LH_SENSORCALIBPOS1 "/System/PCU_LH_SensorCalibPos1"
#define  PCU_LV_SENSORCALIBPOS1 "/System/PCU_LV_SensorCalibPos1"
#define  PCU_RH_SENSORCALIBPOS1 "/System/PCU_RH_SensorCalibPos1"
#define  PCU_RV_SENSORCALIBPOS1 "/System/PCU_RV_SensorCalibPos1"
#define  PCU_LH_SENSORCALIBPOS2 "/System/PCU_LH_SensorCalibPos2"
#define  PCU_LV_SENSORCALIBPOS2 "/System/PCU_LV_SensorCalibPos2"
#define  PCU_RH_SENSORCALIBPOS2 "/System/PCU_RH_SensorCalibPos2"
#define  PCU_RV_SENSORCALIBPOS2 "/System/PCU_RV_SensorCalibPos2"
#define  PCU_AXISANGULARLOWERSPEED "/System/PCU_AxisAngularLowerSpeed"
#define  PCU_AXISANGULARHIGHSPEED "/System/PCU_AxisAngularHighSpeed"
#define  PCU_L_SMWDIAMETER "/System/PCU_L_SMWDiameter"
#define  PCU_R_SMWDIAMETER "/System/PCU_R_SMWDiameter"
#define  PCU_LIFTCUTTERPOWER "/System/PCU_LiftCutterPower"
#define  PCU_LIFTCUTTERTIME "/System/PCU_LiftCutterTime"
#define  PCU_ENDCUTTINGPOWER "/System/PCU_EndCuttingPower"
#define  PCU_ENDCUTTINGTIME "/System/PCU_EndCuttingTime"
#define  PCU_H_RAPIDMOVESPEED "/System/PCU_H_RapidMoveSpeed"
#define  PCU_V_RAPIDMOVESPEED "/System/PCU_V_RapidMoveSpeed"
#define  PCU_OFFSETSLOPELENGTH "/System/PCU_OffsetSlopeLength"
#define  PCU_CUTTERDIAMETER "/System/PCU_CutterDiameter"

#define  NCU_LH_RAILOFFSET "/System/NCU_LH_RailOffset"
#define  NCU_LV_RAILOFFSET "/System/NCU_LV_RailOffset"
#define  NCU_RH_RAILOFFSET "/System/NCU_RH_RailOffset"
#define  NCU_RV_RAILOFFSET "/System/NCU_RV_RailOffset"
#define  NCU_LH_SENSORCALIBPOS1 "/System/NCU_LH_SensorCalibPos1"
#define  NCU_LV_SENSORCALIBPOS1 "/System/NCU_LV_SensorCalibPos1"
#define  NCU_RH_SENSORCALIBPOS1 "/System/NCU_RH_SensorCalibPos1"
#define  NCU_RV_SENSORCALIBPOS1 "/System/NCU_RV_SensorCalibPos1"
#define  NCU_LH_SENSORCALIBPOS2 "/System/NCU_LH_SensorCalibPos2"
#define  NCU_LV_SENSORCALIBPOS2 "/System/NCU_LV_SensorCalibPos2"
#define  NCU_RH_SENSORCALIBPOS2 "/System/NCU_RH_SensorCalibPos2"
#define  NCU_RV_SENSORCALIBPOS2 "/System/NCU_RV_SensorCalibPos2"
#define  NCU_AXISANGULARLOWERSPEED_CH1 "/System/NCU_AxisAngularLowerSpeed_ch1"
#define  NCU_AXISANGULARLOWERSPEED_CH2 "/System/NCU_AxisAngularLowerSpeed_ch2"
#define  NCU_AXISANGULARHIGHSPEED_CH1 "/System/NCU_AxisAngularHighSpeed_ch1"
#define  NCU_AXISANGULARHIGHSPEED_CH2 "/System/NCU_AxisAngularHighSpeed_ch2"
#define  NCU_H_RAPIDMOVESPEED_CH1 "/System/NCU_H_RapidMoveSpeed_ch1"
#define  NCU_H_RAPIDMOVESPEED_CH2 "/System/NCU_H_RapidMoveSpeed_ch2"
#define  NCU_V_RAPIDMOVESPEED_CH1 "/System/NCU_V_RapidMoveSpeed_ch1"
#define  NCU_V_RAPIDMOVESPEED_CH2 "/System/NCU_V_RapidMoveSpeed_ch2"

#define  PLC_LH_RAILOFFSET "/System/PLC_LH_RailOffset"
#define  PLC_LV_RAILOFFSET "/System/PLC_LV_RailOffset"
#define  PLC_RH_RAILOFFSET "/System/PLC_RH_RailOffset"
#define  PLC_RV_RAILOFFSET "/System/PLC_RV_RailOffset"
#define  PLC_AXISANGULARLOWERSPEED "/System/PLC_AxisAngularLowerSpeed"
#define  PLC_AXISANGULARHIGHSPEED "/System/PLC_AxisAngularHighSpeed"
#define  PLC_L_SMWDIAMETER "/System/PLC_L_SMWDiameter"
#define  PLC_R_SMWDIAMETER "/System/PLC_R_SMWDiameter"
#define  PLC_LIFTCUTTERPOWER "/System/PLC_LiftCutterPower"
#define  PLC_LIFTCUTTERTIME "/System/PLC_LiftCutterTime"
#define  PLC_ENDCUTTINGPOWER "/System/PLC_EndCuttingPower"
#define  PLC_ENDCUTTINGTIME "/System/PLC_EndCuttingTime"
#define  PLC_H_RAPIDMOVESPEED "/System/PLC_H_RapidMoveSpeed"
#define  PLC_V_RAPIDMOVESPEED "/System/PLC_V_RapidMoveSpeed"
#define  PLC_OFFSETSLOPELENGTH "/System/PLC_OffsetSlopeLength"

#define  RST_LH_RAILOFFSET "/System/RST_LH_RailOffset"
#define  RST_LV_RAILOFFSET "/System/RST_LV_RailOffset"
#define  RST_RH_RAILOFFSET "/System/RST_RH_RailOffset"
#define  RST_RV_RAILOFFSET "/System/RST_RV_RailOffset"
#define  RST_AXISANGULARLOWERSPEED "/System/RST_AxisAngularLowerSpeed"
#define  RST_AXISANGULARHIGHSPEED "/System/RST_AxisAngularHighSpeed"
#define  RST_L_SMWDIAMETER "/System/RST_L_SMWDiameter"
#define  RST_R_SMWDIAMETER "/System/RST_R_SMWDiameter"
#define  RST_LIFTCUTTERPOWER "/System/RST_LiftCutterPower"
#define  RST_LIFTCUTTERTIME "/System/RST_LiftCutterTime"
#define  RST_ENDCUTTINGPOWER "/System/RST_EndCuttingPower"
#define  RST_ENDCUTTINGTIME "/System/RST_EndCuttingTime"
#define  RST_H_RAPIDMOVESPEED "/System/RST_H_RapidMoveSpeed"
#define  RST_V_RAPIDMOVESPEED "/System/RST_V_RapidMoveSpeed"
#define  RST_OFFSETSLOPELENGTH "/System/RST_OffsetSlopeLength"
#define  RST_CUTTERDIAMETER "/System/RST_CutterDiameter"
//------------------------------------------RailCalib Parameters------------------------//
#define  PCU_LH_MOTORCALIBPOS "/RailCalib/PCU_LH_MotorCalibPos"
#define  PCU_LV_MOTORCALIBPOS "/RailCalib/PCU_LV_MotorCalibPos"
#define  PCU_RH_MOTORCALIBPOS "/RailCalib/PCU_RH_MotorCalibPos"
#define  PCU_RV_MOTORCALIBPOS "/RailCalib/PCU_RV_MotorCalibPos"
#define	 PCU_LSCANNERTOCUTTEROFFSET "/RailCalib/PCU_LScannerToCutterOffset"
#define  PCU_RSCANNERTOCUTTEROFFSET "/RailCalib/PCU_RScannerToCutterOffset"
#define	 RST_LSCANNERTOCUTTEROFFSET "/RailCalib/RST_LScannerToCutterOffset"
#define  RST_RSCANNERTOCUTTEROFFSET "/RailCalib/RST_RScannerToCutterOffset"

#define  NCU_LH_MOTORCALIBPOS "/RailCalib/NCU_LH_MotorCalibPos"
#define  NCU_LV_MOTORCALIBPOS "/RailCalib/NCU_LV_MotorCalibPos"
#define  NCU_RH_MOTORCALIBPOS "/RailCalib/NCU_RH_MotorCalibPos"
#define  NCU_RV_MOTORCALIBPOS "/RailCalib/NCU_RV_MotorCalibPos"
//------------------------------------------CPOffset Parameters------------------------//
#define  PCU_LH_CPOFFSET1 "/CPOffset/PCU_LH_CPOffset1"
#define  PCU_LV_CPOFFSET1 "/CPOffset/PCU_LV_CPOffset1"
#define  PCU_RH_CPOFFSET1 "/CPOffset/PCU_RH_CPOffset1"
#define  PCU_RV_CPOFFSET1 "/CPOffset/PCU_RV_CPOffset1"
#define  PCU_LH_CPOFFSET2 "/CPOffset/PCU_LH_CPOffset2"
#define  PCU_LV_CPOFFSET2 "/CPOffset/PCU_LV_CPOffset2"
#define  PCU_RH_CPOFFSET2 "/CPOffset/PCU_RH_CPOffset2"
#define  PCU_RV_CPOFFSET2 "/CPOffset/PCU_RV_CPOffset2"

#define  NCU_LH_CPOFFSET1 "/CPOffset/NCU_LH_CPOffset1"
#define  NCU_LV_CPOFFSET1 "/CPOffset/NCU_LV_CPOffset1"
#define  NCU_RH_CPOFFSET1 "/CPOffset/NCU_RH_CPOffset1"
#define  NCU_RV_CPOFFSET1 "/CPOffset/NCU_RV_CPOffset1"
#define  NCU_LH_CPOFFSET2 "/CPOffset/NCU_LH_CPOffset2"
#define  NCU_LV_CPOFFSET2 "/CPOffset/NCU_LV_CPOffset2"
#define  NCU_RH_CPOFFSET2 "/CPOffset/NCU_RH_CPOffset2"
#define  NCU_RV_CPOFFSET2 "/CPOffset/NCU_RV_CPOffset2"

#define  RST_LH_CPOFFSET1 "/CPOffset/RST_LH_CPOffset1"
#define  RST_LV_CPOFFSET1 "/CPOffset/RST_LV_CPOffset1"
#define  RST_RH_CPOFFSET1 "/CPOffset/RST_RH_CPOffset1"
#define  RST_RV_CPOFFSET1 "/CPOffset/RST_RV_CPOffset1"
#define  RST_LH_CPOFFSET2 "/CPOffset/RST_LH_CPOffset2"
#define  RST_LV_CPOFFSET2 "/CPOffset/RST_LV_CPOffset2"
#define  RST_RH_CPOFFSET2 "/CPOffset/RST_RH_CPOffset2"
#define  RST_RV_CPOFFSET2 "/CPOffset/RST_RV_CPOffset2"

#define	 PCU_H_SOFTSHOELEN "/CPOffset/PCU_H_SoftShoeLen"
#define  PCU_V_SOFTSHOELEN "/CPOffset/PCU_V_SoftShoeLen"
#define  PCU_H_SOFTSHOEALPH "/CPOffset/PCU_H_SoftShoeAlph"
#define  PCU_V_SOFTSHOEALPH "/CPOffset/PCU_V_SoftShoeAlph"
#define  PCU_H_SOFTSHOELAYER "/CPOffset/PCU_H_SoftShoeLayer"
#define  PCU_V_SOFTSHOELAYER "/CPOffset/PCU_V_SoftShoeLayer"
#define  PCU_H_SOFTSHOEDIRRATIO1 "/CPOffset/PCU_H_SoftShoeDirRatio1"
#define  PCU_V_SOFTSHOEDIRRATIO1 "/CPOffset/PCU_V_SoftShoeDirRatio1"
#define  PCU_H_SOFTSHOEDIRRATIO2 "/CPOffset/PCU_H_SoftShoeDirRatio2"
#define  PCU_V_SOFTSHOEDIRRATIO2 "/CPOffset/PCU_V_SoftShoeDirRatio2"
#define  PCU_LH_SENSORRATIO "/CPOffset/PCU_LH_SensorRatio"
#define  PCU_LV_SENSORRATIO "/CPOffset/PCU_LV_SensorRatio"
#define  PCU_RH_SENSORRATIO "/CPOffset/PCU_RH_SensorRatio"
#define  PCU_RV_SENSORRATIO "/CPOffset/PCU_RV_SensorRatio"
#define  PCU_H_LOWPASSFILTER "/CPOffset/PCU_H_LowPassFilter"
#define  PCU_V_LOWPASSFILTER "/CPOffset/PCU_V_LowPassFilter"
#define  PCU_LH_SENSORPRIORITY "/CPOffset/PCU_LH_SensorPriority"
#define  PCU_LV_SENSORPRIORITY "/CPOffset/PCU_LV_SensorPriority"
#define  PCU_RH_SENSORPRIORITY "/CPOffset/PCU_RH_SensorPriority"
#define  PCU_RV_SENSORPRIORITY "/CPOffset/PCU_RV_SensorPriority"
#define  PCU_SOFTSHOEDIR "/CPOffset/PCU_SoftShoeDir"

//------------------------------------------Product Parameters------------------------//
#define ENTRY_PRODUCT_TYPE  "/Product/Type"
//------------------------------------------Login  Parameters---------------- --------//
#define ENTRY_USERNAME_STRING  "/Login/UserName"
#define ENTRY_PASSWORD_STRING  "/Login/Password"
#define ENTRY_NAMEERROR_STRING  "/Login/UnameError"
#define ENTRY_PDWERROR_STRING  "/Login/PwdError"
#define ENTRY_LOGIN_STRING  "/Login/Login"
#define ENTRY_NOTLOGIN_STRING  "/Login/NotLogin"
#define ENTRY_MODIFY_SUCCESS  "/Login/ModifySuccess"
#define ENTRY_MODIFY_FAILED  "/Login/ModifyFailed"
#define ENTRY_LOGIN_NAME  "/Login/LoginName"
#define ENTRY_LOGOFF_NAME  "/Login/LogoffName"
//------------------------------------------Error List Headers--------- -------------//
#define ENTRY_ERROR_NUMBER  "/ListHeader/Index"
#define ENTRY_ERROR_TIME  "/ListHeader/time"
#define ENTRY_ERROR_STATE  "/ListHeader/state"
#define ENTRY_ERROR_TEXT  "/ListHeader/text"
#define ENTRY_ERROR_WORKSTATE "/ListHeader/WorkState"
//------------------------------------------Status List Headers--------- -------------//
#define ENTRY_STATUSLIST_CONTROLUNIT  "/ListStatus/ControlUnit"
#define ENTRY_STATUSLIST_ADDRESS  "/ListStatus/Address"
#define ENTRY_STATUSLIST_STATUS  "/ListStatus/Status"
//------------------------------------NNScreen Parameters----------------------------//
#define ENTRY_NN_DEBUGPSW  "/NNScreen/DebugPsw"
#define ENTRY_NN_WAITFORREMOTE  "/NNScreen/WaitForRemote"
#define ENTRY_NN_LOGINSUCCESS  "/NNScreen/LoginSuccess"
#define ENTRY_NN_LOGINFAILED  "/NNScreen/LoginFailed"
#define ENTRY_NN_LOGINPREID  "/NNScreen/PreID"
#define ENTRY_NN_CONNECTSUCCESS  "/NNScreen/ConnectSuccess"
#define ENTRY_NN_STOP  "/NNScreen/Stop"
#define ENTRY_NN_OFFLINE  "/NNScreen/OffLine"
#define ENTRY_NN_CONNECTFAILED  "/NNScreen/ConnectFailed"

//------------------------------------Mileage Parameters----------------------------//
#define ENTRY_MILEAGE_TRAIN "/Mileage/TrainMileage"
#define ENTRY_MILEAGE_WORK "/Mileage/WorkMileage"
#define ENTRY_MILEAGE_RESETWORKMILEAGE "/Mileage/LastResetWorkMileage"
#define ENTRY_MILEAGE_RESETTRAINMILEAGE "/Mileage/LastResetTrainMileage"
#define ENTRY_MILEAGE_RESETTIME "/Mileage/LastResetTime"
//------------------------------------Debug Parameters----------------------------//
#define ENTRY_DEBUG_SETDEFAULT "/Debug/IsSetDefault"

//------------------------------------Repair Parameters----------------------------//
#define ENTRY_REPAIR_PWD			"/RepairLogin/RepairPwd"
#define ENTRY_REPAIR_PWDERROR		"/RepairLogin/RepairPwdError"
#define ENTRY_REPAIR_LOGIN			"/RepairLogin/RepairLogin"
#define ENTRY_REPAIR_LOGOFF			"/RepairLogin/RepairLogoff"
//------------------------------------Debug Parameters----------------------------//
#define ENTRY_DEBUG_PWD				"/RepairLogin/DebugPwd"
#define ENTRY_DEBUG_PWDERROR		"/RepairLogin/DebugPwdError"
#define ENTRY_DEBUG_LOGIN			"/RepairLogin/DebugLogin"
#define ENTRY_DEBUG_LOGOFF			"/RepairLogin/DebugLogoff"
//------------------------------------SoftLimit Parameters----------------------------//
#define PCU_LH_MOTORPOSHIGH			"/SoftLimit/PCU_LH_MotorPosHigh"
#define PCU_LH_MOTORPOSLOW			"/SoftLimit/PCU_LH_MotorPosLow"
#define PCU_LV_MOTORPOSHIGH			"/SoftLimit/PCU_LV_MotorPosHigh"
#define PCU_LV_MOTORPOSLOW			"/SoftLimit/PCU_LV_MotorPosLow"
#define PCU_RH_MOTORPOSHIGH			"/SoftLimit/PCU_RH_MotorPosHigh"
#define PCU_RH_MOTORPOSLOW			"/SoftLimit/PCU_RH_MotorPosLow"
#define PCU_RV_MOTORPOSHIGH			"/SoftLimit/PCU_RV_MotorPosHigh"
#define PCU_RV_MOTORPOSLOW			"/SoftLimit/PCU_RV_MotorPosLow"
#define PCU_LH_CUTTERPROTECT		"/SoftLimit/PCU_LH_CutterProtect"
#define PCU_LV_CUTTERPROTECT		"/SoftLimit/PCU_LV_CutterProtect"
#define PCU_RH_CUTTERPROTECT		"/SoftLimit/PCU_RH_CutterProtect" 
#define PCU_RV_CUTTERPROTECT		"/SoftLimit/PCU_RV_CutterProtect"
#define PCU_H_CUTBIASSTEP			"/SoftLimit/PCU_H_CutBiasStep" 
#define PCU_V_CUTBIASSTEP			"/SoftLimit/PCU_V_CutBiasStep"
#define PCU_H_MINCUTSTEP			"/SoftLimit/PCU_H_MinCutStep"
#define PCU_V_MINCUTSTEP			"/SoftLimit/PCU_V_MinCutStep"

//------------------------------------Information Parameters----------------------------//
#define ENTRY_INFO_TRAINSPDNOTREACH "/information/TrainSpdNotReach"
#define ENTRY_INFO_AXISSPDNOTREACH	"/information/AxisSpdNotReach"
#define ENTRY_INFO_DISKSPACELOW		"/information/DiskSpaceLow"
#define ENTRY_INFO_DISKSPACEALARM	"/information/DiskSpaceAlarm"
//------------------------------------WorkState Parameters----------------------------//
#define ENTRY_WORKSTATE_UNKOWN		"/WorkState/State_Unkown"
#define ENTRY_WORKSTATE_YFELLOW		"/WorkState/State_YFellow"
#define ENTRY_WORKSTATE_CUTIN		"/WorkState/State_CutIn"
#define ENTRY_WORKSTATE_MILLING		"/WorkState/State_Milling"
#define ENTRY_WORKSTATE_CUTOUT		"/WorkState/State_CutOut"
#define ENTRY_WORKSTATE_ENDFELLOW	"/WorkState/State_EndFellow"
#define ENTRY_WORKSTATE_WAITING		"/WorkState/State_Waiting"
#define ENTRY_WORKSTATE_READY		"/WorkState/State_Ready"
#define ENTRY_WORKSTATE_SCAN		"/WorkState/State_Scan"
#define ENTRY_WORKSTATE_LOADDOWN1	"/WorkState/State_LoadDown1"
#define ENTRY_WORKSTATE_STARTTRAIN1 "/WorkState/State_StartTrain1"
#define ENTRY_WORKSTATE_STARTTRAIN2 "/WorkState/State_StartTrain2"
#define ENTRY_WORKSTATE_STARTWORK	"/WorkState/State_StartWork"
#define ENTRY_WORKSTATE_STOPWORK	"/WorkState/State_StopWork"
#define ENTRY_WORKSTATE_STOPTRAIN	"/WorkState/State_StopTrain"
#define ENTRY_WORKSTATE_LOADDOWN2	"/WorkState/State_LoadDown2"
#define ENTRY_WORKSTATE_DEVICEUP	"/WorkState/State_DeviceUp"
#define ENTRY_WORKSTATE_EMERGENCY	"/WorkState/State_Emergency"
#define ENTRY_WORKSTATE_REPAIR		"/WorkState/State_Repair"

//------------------------------------ShineState Parameters----------------------------//
#define ENTRY_SHINESTATE_UNKOWN		"/ShineState/State_Unkown"
#define ENTRY_SHINESTATE_WAITING	"/ShineState/State_ShineWaiting"
#define ENTRY_SHINESTATE_READY	    "/ShineState/State_ShineReady"
#define ENTRY_SHINESTATE_DOWN1	    "/ShineState/State_ShineDown1"
#define ENTRY_SHINESTATE_DOWN2	    "/ShineState/State_ShineDown2"
#define ENTRY_SHINESTATE_START	    "/ShineState/State_StartShine"
#define ENTRY_SHINESTATE_END	    "/ShineState/State_EndShine"
#define ENTRY_SHINESTATE_UP	        "/ShineState/State_ShineUp"
#define ENTRY_SHINESTATE_EMGENCYSTOP "/ShineState/State_ShineStop"
//------------------------log status---------------------------------------//
#define ENTRY_LOG_OPERATETIME        "/Log/OperateTime"
#define ENTRY_LOG_OPERATOR           "/Log/Operator"
#define ENTRY_LOG_OPERATETYPE        "/Log/OperateType"
#define ENTRY_LOG_LOGIN              "/Log/Login"
#define ENTRY_LOG_LOGOFF             "/Log/LogOff"
#define ENTRY_LOG_SYSPARAMSAVE       "/Log/SysParameterSave"
#define ENTRY_LOG_WORKPARAMSAVE      "/Log/WorkParameterSave"
#define ENTRY_LOG_SCANPARAMSAVE      "/Log/ScanParameterSave"
#define ENTRY_LOG_BODYSTART          "/Log/BodyStart"
#define ENTRY_LOG_BODYSTOP           "/Log/BodyStop"
#define ENTRY_LOG_HYDRAULICSTART     "/Log/HydraulicStart"
#define ENTRY_LOG_HYDRAULICSTOP      "/Log/HydraulicStop"
#define ENTRY_LOG_CHIPSTART          "/Log/ChipStart"
#define ENTRY_LOG_CHIPSTOP           "/Log/ChipStop"
#define ENTRY_LOG_SPEEDWHEELSTART    "/Log/SpeedWheelStart"
#define ENTRY_LOG_SPEEDWHEELSTOP     "/Log/SpeedWheelStop"
#define ENTRY_LOG_STARTTRAIN         "/Log/StartTrain"
#define ENTRY_LOG_STOPTRAIN          "/Log/StopTrain"
#define ENTRY_LOG_STARTWORK          "/Log/StartWork"
#define ENTRY_LOG_STOPWORK           "/Log/StopWork"
#define ENTRY_LOG_DEVICEUP           "/Log/DeviceUp"
#define ENTRY_LOG_DEVICEDOWN         "/Log/DeviceDown"

OperateIni::OperateIni(void)
{	
	ReadInitialize( );
	ReadInfoParameters();
	ReadProductParameters( );
	ReadLoginParameters( );
	ReadWorkParameters( );
	ReadSystemParameters( );
	ReadRailCalibParameters( );
	ReadCPOffsetParameters( );
	ReadErrorListHeaders( );
	ReadStatusListHeaders( );
	ReadNNScreenParameters( );
	ReadDebugParameters( );
	ReadMileageParameters( );
	ReadRepairParameters( );
	ReadSoftLimitParameters( );
	ReadWorkStateParameters( );
	ReadShineStateParameters();//ligy 20190928 add.
	ReadFinalize( );

	g->ChooseSensor();
}

OperateIni::~OperateIni(void)
{


}

void OperateIni::ReadInitialize( )
{
	m_pcodec = QTextCodec::codecForName("utf8");			//GBK gbk 	
	m_pconfigIniRead = new QSettings("C:/scr/parameter.ini", QSettings::IniFormat);  
}

void OperateIni::ReadFinalize( )
{
	delete m_pconfigIniRead;  
}

void OperateIni::ReadWorkParameters( )
{
	g->m_LH_CutDepth = m_pconfigIniRead->value(PCU_LH_CUTTINGDEPTH).toDouble();
	g->m_LV_CutDepth = m_pconfigIniRead->value(PCU_LV_CUTTINGDEPTH).toDouble();
	g->m_RH_CutDepth = m_pconfigIniRead->value(PCU_RH_CUTTINGDEPTH).toDouble();
	g->m_RV_CutDepth = m_pconfigIniRead->value(PCU_RV_CUTTINGDEPTH).toDouble();
	g->m_H_DeviceIniPos = m_pconfigIniRead->value(PCU_H_DEVICEINIPOS).toDouble();
	g->m_V_DeviceIniPos = m_pconfigIniRead->value(PCU_V_DEVICEINIPOS).toDouble();
	g->m_H_WorkIniPos = m_pconfigIniRead->value(PCU_H_WORKINIPOS).toDouble();
	g->m_V_WorkIniPos = m_pconfigIniRead->value(PCU_V_WORKINIPOS).toDouble();
	g->m_DstTrainSpeed = m_pconfigIniRead->value(PCU_TRAINSPEED).toDouble();
	g->m_DstTrainSpeedDiff = m_pconfigIniRead->value(PCU_TRAINSPEEDDIFF).toDouble();//速度超差允许范围，单位%
	g->m_DstTrainSpeedDiffTime = m_pconfigIniRead->value(PCU_TRAINSPEEDDIFFTIME).toDouble();//速度超差监控时间，单位ms
	g->m_SlopeLength = m_pconfigIniRead->value(PCU_SLOPELENGTH).toDouble();
	g->m_HighSpindleSpeed = m_pconfigIniRead->value(PCU_AXISLINEHIGHSPEED).toDouble();
	g->m_LowerSpindleSpeed = m_pconfigIniRead->value(PCU_AXISLINELOWERSPEED).toDouble();
	g->m_LV_PowerControlValue = m_pconfigIniRead->value(PCU_LV_POWERCONTROLVALUE).toDouble();
	g->m_RV_PowerControlValue = m_pconfigIniRead->value(PCU_RV_POWERCONTROLVALUE).toDouble();
	g->m_bPowerControlMode = m_pconfigIniRead->value(PCU_POWERCONTROLSELECT).toBool();

	QStringList list;
	list= m_pconfigIniRead->value(NCU_LH_CUTTINGDEPTH).toStringList();		
	mstrNcu_LH_CuttingDepth = IniQStringListToQString(list);				
	list = m_pconfigIniRead->value(NCU_LV_CUTTINGDEPTH).toStringList();		
	mstrNcu_LV_CuttingDepth = IniQStringListToQString(list);				
	list = m_pconfigIniRead->value(NCU_RH_CUTTINGDEPTH).toStringList();		
	mstrNcu_RH_CuttingDepth = IniQStringListToQString(list);				
	list = m_pconfigIniRead->value(NCU_RV_CUTTINGDEPTH).toStringList();		
	mstrNcu_RV_CuttingDepth = IniQStringListToQString(list);

	list = m_pconfigIniRead->value(NCU_H_DEVICEINIPOS_CH1).toStringList();		
	mstrNcu_H_DeviceIniPos_ch1 = IniQStringListToQString(list);				
	list = m_pconfigIniRead->value(NCU_H_DEVICEINIPOS_CH2).toStringList();		
	mstrNcu_H_DeviceIniPos_ch2 = IniQStringListToQString(list);	
	list = m_pconfigIniRead->value(NCU_V_DEVICEINIPOS_CH1).toStringList();		
	mstrNcu_V_DeviceIniPos_ch1 = IniQStringListToQString(list);	
	list = m_pconfigIniRead->value(NCU_V_DEVICEINIPOS_CH2).toStringList();		
	mstrNcu_V_DeviceIniPos_ch2 = IniQStringListToQString(list);	
	list= m_pconfigIniRead->value(NCU_H_WORKINIPOS_CH1).toStringList();			
	mstrNcu_H_WorkIniPos_ch1  = IniQStringListToQString(list);					
	list= m_pconfigIniRead->value(NCU_H_WORKINIPOS_CH2).toStringList();			
	mstrNcu_H_WorkIniPos_ch2  = IniQStringListToQString(list);	
	list = m_pconfigIniRead->value(NCU_V_WORKINIPOS_CH1).toStringList();			
	mstrNcu_V_WorkIniPos_ch1  = IniQStringListToQString(list);	
	list = m_pconfigIniRead->value(NCU_V_WORKINIPOS_CH2).toStringList();			
	mstrNcu_V_WorkIniPos_ch2  = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(NCU_TRAINSPEED_CH1).toStringList();			
	mstrNcu_TrainSpeed_ch1  = IniQStringListToQString(list);					
	list = m_pconfigIniRead->value(NCU_TRAINSPEED_CH2).toStringList();			
	mstrNcu_TrainSpeed_ch2  = IniQStringListToQString(list);					
	list = m_pconfigIniRead->value(NCU_SLOPELENGTH_CH1).toStringList();			
	mstrNcu_SlopeLength_ch1 = IniQStringListToQString(list);					
	list = m_pconfigIniRead->value(NCU_SLOPELENGTH_CH2).toStringList();			
	mstrNcu_SlopeLength_ch2 = IniQStringListToQString(list);					

	list = m_pconfigIniRead->value(PLC_LH_CUTTINGDEPTH).toStringList();		
	mstrPlc_LH_CuttingDepth = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_LV_CUTTINGDEPTH).toStringList();		
	mstrPlc_LV_CuttingDepth = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_RH_CUTTINGDEPTH).toStringList();		
	mstrPlc_RH_CuttingDepth = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_RV_CUTTINGDEPTH).toStringList();		
	mstrPlc_RV_CuttingDepth = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_H_DEVICEINIPOS).toStringList();		
	mstrPlc_H_DeviceIniPos = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_V_DEVICEINIPOS).toStringList();		
	mstrPlc_V_DeviceIniPos = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_H_WORKINIPOS).toStringList();			
	mstrPlc_H_WorkIniPos = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_V_WORKINIPOS).toStringList();			
	mstrPlc_V_WorkIniPos = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_TRAINSPEED).toStringList();			
	mstrPlc_TrainSpeed = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_SLOPELENGTH).toStringList();			
	mstrPlc_SlopeLength = IniQStringListToQString(list);
/*
	list = m_pconfigIniRead->value(PLC_LUNITSELECTFLAG).toStringList();		
	mstrPlc_LEnableUnit = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_RUNITSELECTFLAG).toStringList();		
	mstrPlc_REnableUnit = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_AXISHIGHSPEEDFLAG).toStringList();			
	mstrPlc_AxisHighSpeedFlag = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_AUTOMILLINGFLAG).toStringList();			
	mstrPlc_AutoMillingFlag = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_UNITLOCKEDFLAG).toStringList();			
	mstrPlc_UnitLockedFlag = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_AXISSPEED).toStringList();			
	mstrPlc_AxisSpeed = IniQStringListToQString(list);
*/
	QByteArray byteArray = m_pconfigIniRead->value(PCU_LEFTANDRIGHTUNIT).toByteArray();
	m_strLeftAndRight = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(PCU_LEFTUNIT).toByteArray();
	m_strLeft = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(PCU_RIGHTUNIT).toByteArray();
	m_strRight = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(PCU_NONEUNIT).toByteArray();
	m_strNone = m_pcodec->toUnicode(byteArray);
	/*--------------------------------------------------------------------
	//for test Start
	QFile f("C:/scr/test.txt");  
	if(!f.open(QIODevice::WriteOnly | QIODevice::Text ))  
    {  
        //cout << "Open failed." << endl;  
        return ;  
    }  
    QTextStream txtOutput(&f);
	txtOutput << mstrPlc_LEnableUnit << endl;  
    txtOutput << mstrPlc_REnableUnit << endl; 
    txtOutput << mstrPlc_AxisHighSpeedFlag << endl;  
    txtOutput << mstrPlc_AutoMillingFlag << endl; 
    txtOutput << mstrPlc_UnitLockedFlag << endl;  
    txtOutput << mstrPlc_AxisSpeed << endl; 
	
    txtOutput << mstrNcu_LH_CuttingDepth << endl;  
    txtOutput << mstrNcu_LV_CuttingDepth << endl; 
    txtOutput << mstrNcu_RH_CuttingDepth << endl;  
    txtOutput << mstrNcu_RV_CuttingDepth << endl; 
    txtOutput << mstrNcu_H_DeviceIniPos_ch1 << endl;  
    txtOutput << mstrNcu_H_DeviceIniPos_ch2 << endl;  
    txtOutput << mstrNcu_V_DeviceIniPos_ch1 << endl; 
    txtOutput << mstrNcu_V_DeviceIniPos_ch2 << endl; 
    txtOutput << mstrNcu_H_WorkIniPos_ch1 << endl;  
    txtOutput << mstrNcu_H_WorkIniPos_ch2 << endl;  
    txtOutput << mstrNcu_V_WorkIniPos_ch1 << endl; 
    txtOutput << mstrNcu_V_WorkIniPos_ch2 << endl; 
    txtOutput << mstrNcu_TrainSpeed_ch1 << endl;  
    txtOutput << mstrNcu_TrainSpeed_ch2 << endl;  
    txtOutput << mstrNcu_SlopeLength_ch1 << endl; 
    txtOutput << mstrNcu_SlopeLength_ch2 << endl; 

    txtOutput << mstrPlc_LH_CuttingDepth << endl;  
    txtOutput << mstrPlc_LV_CuttingDepth << endl; 
	txtOutput << mstrPlc_RH_CuttingDepth << endl;  
    txtOutput << mstrPlc_RV_CuttingDepth << endl; 
    txtOutput << mstrPlc_H_DeviceIniPos << endl;  
    txtOutput << mstrPlc_V_DeviceIniPos << endl; 
    txtOutput << mstrPlc_H_WorkIniPos << endl;  
    txtOutput << mstrPlc_V_WorkIniPos << endl; 
    txtOutput << mstrPlc_TrainSpeed << endl;  
    txtOutput << mstrPlc_SlopeLength << endl; 
	
	f.close(); 
	//for test End
	//--------------------------------------------------------------------*/
}

void OperateIni::SaveWorkParameters( )
{
	QSettings *configIniWrite = new QSettings("C:/scr/parameter.ini", QSettings::IniFormat);
	configIniWrite->setValue(PCU_LH_CUTTINGDEPTH,g->m_LH_CutDepth);
	configIniWrite->setValue(PCU_LV_CUTTINGDEPTH,g->m_LV_CutDepth);
	configIniWrite->setValue(PCU_RH_CUTTINGDEPTH,g->m_RH_CutDepth);
	configIniWrite->setValue(PCU_RV_CUTTINGDEPTH,g->m_RV_CutDepth);
	configIniWrite->setValue(PCU_H_DEVICEINIPOS,g->m_H_DeviceIniPos);
	configIniWrite->setValue(PCU_V_DEVICEINIPOS,g->m_V_DeviceIniPos);
	configIniWrite->setValue(PCU_H_WORKINIPOS,g->m_H_WorkIniPos);
	configIniWrite->setValue(PCU_V_WORKINIPOS,g->m_V_WorkIniPos);
	configIniWrite->setValue(PCU_TRAINSPEED,g->m_DstTrainSpeed);
	configIniWrite->setValue(PCU_TRAINSPEEDDIFF,g->m_DstTrainSpeedDiff);//ligy 20190908 add.速度超差范围
	configIniWrite->setValue(PCU_TRAINSPEEDDIFFTIME,g->m_DstTrainSpeedDiffTime);//ligy 20190908 add.速度超差监控时间，单位ms
	configIniWrite->setValue(PCU_SLOPELENGTH,g->m_SlopeLength);
	configIniWrite->setValue(PCU_LV_POWERCONTROLVALUE,g->m_LV_PowerControlValue);
	configIniWrite->setValue(PCU_RV_POWERCONTROLVALUE,g->m_RV_PowerControlValue);
	configIniWrite->setValue(PCU_POWERCONTROLSELECT,g->m_bPowerControlMode);
	delete configIniWrite; 
}

void OperateIni::ReadSystemParameters( )
{
	g->m_LH_RailOffset = m_pconfigIniRead->value(PCU_LH_RAILOFFSET).toDouble();
	g->m_LV_RailOffset = m_pconfigIniRead->value(PCU_LV_RAILOFFSET).toDouble();
	g->m_RH_RailOffset = m_pconfigIniRead->value(PCU_RH_RAILOFFSET).toDouble();
	g->m_RV_RailOffset = m_pconfigIniRead->value(PCU_RV_RAILOFFSET).toDouble();
	g->m_LH_SensorCalibPos1 = m_pconfigIniRead->value(PCU_LH_SENSORCALIBPOS1).toDouble();
	g->m_LV_SensorCalibPos1 = m_pconfigIniRead->value(PCU_LV_SENSORCALIBPOS1).toDouble();
	g->m_RH_SensorCalibPos1 = m_pconfigIniRead->value(PCU_RH_SENSORCALIBPOS1).toDouble();
	g->m_RV_SensorCalibPos1 = m_pconfigIniRead->value(PCU_RV_SENSORCALIBPOS1).toDouble();
	g->m_LH_SensorCalibPos2 = m_pconfigIniRead->value(PCU_LH_SENSORCALIBPOS2).toDouble();
	g->m_LV_SensorCalibPos2 = m_pconfigIniRead->value(PCU_LV_SENSORCALIBPOS2).toDouble();
	g->m_RH_SensorCalibPos2 = m_pconfigIniRead->value(PCU_RH_SENSORCALIBPOS2).toDouble();
	g->m_RV_SensorCalibPos2 = m_pconfigIniRead->value(PCU_RV_SENSORCALIBPOS2).toDouble();
	g->m_LowAxisAngularSpeed = m_pconfigIniRead->value(PCU_AXISANGULARLOWERSPEED).toDouble();
	g->m_HighAxisAngularSpeed = m_pconfigIniRead->value(PCU_AXISANGULARHIGHSPEED).toDouble();
	g->m_L_SMWDiameter = m_pconfigIniRead->value(PCU_L_SMWDIAMETER).toDouble();
	g->m_R_SMWDiameter = m_pconfigIniRead->value(PCU_R_SMWDIAMETER).toDouble();
	g->m_LiftCutterPower = m_pconfigIniRead->value(PCU_LIFTCUTTERPOWER).toDouble();
	g->m_LiftCutterTime = m_pconfigIniRead->value(PCU_LIFTCUTTERTIME).toDouble();
	g->m_EndCuttingPower = m_pconfigIniRead->value(PCU_ENDCUTTINGPOWER).toDouble();
	g->m_EndCuttingTime = m_pconfigIniRead->value(PCU_ENDCUTTINGTIME).toDouble();
	g->m_H_RapidSpeed = m_pconfigIniRead->value(PCU_H_RAPIDMOVESPEED).toDouble();
	g->m_V_RapidSpeed = m_pconfigIniRead->value(PCU_V_RAPIDMOVESPEED).toDouble();
	g->m_OffsetSlopeLength = m_pconfigIniRead->value(PCU_OFFSETSLOPELENGTH).toDouble();
	g->m_CutterDiameter = m_pconfigIniRead->value(PCU_CUTTERDIAMETER).toDouble();

	QStringList list;
	list= m_pconfigIniRead->value(NCU_LH_RAILOFFSET).toStringList();		
	mstrNcu_LH_RailOffset = IniQStringListToQString(list);				
	list = m_pconfigIniRead->value(NCU_LV_RAILOFFSET).toStringList();		
	mstrNcu_LV_RailOffset = IniQStringListToQString(list);				
	list = m_pconfigIniRead->value(NCU_RH_RAILOFFSET).toStringList();		
	mstrNcu_RH_RailOffset = IniQStringListToQString(list);				
	list = m_pconfigIniRead->value(NCU_RV_RAILOFFSET).toStringList();		
	mstrNcu_RV_RailOffset = IniQStringListToQString(list);				
	list = m_pconfigIniRead->value(NCU_LH_SENSORCALIBPOS1).toStringList();		
	mstrNcu_LH_SensorCalibPos1 = IniQStringListToQString(list);				
	list = m_pconfigIniRead->value(NCU_LV_SENSORCALIBPOS1).toStringList();		
	mstrNcu_LV_SensorCalibPos1 = IniQStringListToQString(list);				
	list = m_pconfigIniRead->value(NCU_RH_SENSORCALIBPOS1).toStringList();			
	mstrNcu_RH_SensorCalibPos1 = IniQStringListToQString(list);					
	list = m_pconfigIniRead->value(NCU_RV_SENSORCALIBPOS1).toStringList();			
	mstrNcu_RV_SensorCalibPos1 = IniQStringListToQString(list);	
	list = m_pconfigIniRead->value(NCU_LH_SENSORCALIBPOS2).toStringList();		
	mstrNcu_LH_SensorCalibPos2 = IniQStringListToQString(list);				
	list = m_pconfigIniRead->value(NCU_LV_SENSORCALIBPOS2).toStringList();		
	mstrNcu_LV_SensorCalibPos2 = IniQStringListToQString(list);				
	list = m_pconfigIniRead->value(NCU_RH_SENSORCALIBPOS2).toStringList();			
	mstrNcu_RH_SensorCalibPos2 = IniQStringListToQString(list);					
	list = m_pconfigIniRead->value(NCU_RV_SENSORCALIBPOS2).toStringList();			
	mstrNcu_RV_SensorCalibPos2 = IniQStringListToQString(list);	

	list = m_pconfigIniRead->value(NCU_AXISANGULARLOWERSPEED_CH1).toStringList();			
	mstrNcu_AxisAngularLowerSpeed_ch1 = IniQStringListToQString(list);					
	list = m_pconfigIniRead->value(NCU_AXISANGULARLOWERSPEED_CH2).toStringList();			
	mstrNcu_AxisAngularLowerSpeed_ch2 = IniQStringListToQString(list);					
	list = m_pconfigIniRead->value(NCU_AXISANGULARHIGHSPEED_CH1).toStringList();			
	mstrNcu_AxisAngularHighSpeed_ch1 = IniQStringListToQString(list);					
	list = m_pconfigIniRead->value(NCU_AXISANGULARHIGHSPEED_CH2).toStringList();			
	mstrNcu_AxisAngularHighSpeed_ch2 = IniQStringListToQString(list);					
	list = m_pconfigIniRead->value(NCU_H_RAPIDMOVESPEED_CH1).toStringList();			
	mstrNcu_H_RapidMoveSpeed_ch1 = IniQStringListToQString(list);					
	list = m_pconfigIniRead->value(NCU_H_RAPIDMOVESPEED_CH2).toStringList();			
	mstrNcu_H_RapidMoveSpeed_ch2 = IniQStringListToQString(list);					
	list = m_pconfigIniRead->value(NCU_V_RAPIDMOVESPEED_CH1).toStringList();			
	mstrNcu_V_RapidMoveSpeed_ch1 = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(NCU_V_RAPIDMOVESPEED_CH2).toStringList();			
	mstrNcu_V_RapidMoveSpeed_ch2 = IniQStringListToQString(list);

	list = m_pconfigIniRead->value(PLC_LH_RAILOFFSET).toStringList();		
	mstrPlc_LH_RailOffset = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_LV_RAILOFFSET).toStringList();		
	mstrPlc_LV_RailOffset = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_RH_RAILOFFSET).toStringList();		
	mstrPlc_RH_RailOffset = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_RV_RAILOFFSET).toStringList();		
	mstrPlc_RV_RailOffset = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_AXISANGULARLOWERSPEED).toStringList();		
	mstrPlc_AxisAngularLowerSpeed = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_AXISANGULARHIGHSPEED).toStringList();		
	mstrPlc_AxisAngularHighSpeed = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_L_SMWDIAMETER).toStringList();			
	mstrPlc_L_SMWDiameter = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_R_SMWDIAMETER).toStringList();			
	mstrPlc_R_SMWDiameter = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_LIFTCUTTERPOWER).toStringList();			
	mstrPlc_LiftCutterPower = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_LIFTCUTTERTIME).toStringList();			
	mstrPlc_LiftCutterTime = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_ENDCUTTINGPOWER).toStringList();			
	mstrPlc_EndCuttingPower = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_ENDCUTTINGTIME).toStringList();			
	mstrPlc_EndCuttingTime = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_H_RAPIDMOVESPEED).toStringList();			
	mstrPlc_H_RapidMoveSpeed = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_V_RAPIDMOVESPEED).toStringList();			
	mstrPlc_V_RapidMoveSpeed = IniQStringListToQString(list);
	list = m_pconfigIniRead->value(PLC_OFFSETSLOPELENGTH).toStringList();			
	mstrPlc_OffsetSlopeLength = IniQStringListToQString(list);

	/*--------------------------------------------------------------------
	//for test Start
	QFile f("C:/scr/test.txt");  
	if(!f.open(QIODevice::WriteOnly | QIODevice::Text ))  
    {  
        //cout << "Open failed." << endl;  
        return ;  
    }  
    QTextStream txtOutput(&f);

	txtOutput << mstrNcu_LH_RailOffset << endl;  
    txtOutput << mstrNcu_LV_RailOffset << endl; 
    txtOutput << mstrNcu_RH_RailOffset << endl;  
    txtOutput << mstrNcu_RV_RailOffset << endl; 
    txtOutput << mstrNcu_LH_SensorCalibPos1 << endl;  
    txtOutput << mstrNcu_LV_SensorCalibPos1 << endl; 
    txtOutput << mstrNcu_RH_SensorCalibPos1 << endl;  
    txtOutput << mstrNcu_RV_SensorCalibPos1 << endl; 
    txtOutput << mstrNcu_LH_SensorCalibPos2 << endl;  
    txtOutput << mstrNcu_LV_SensorCalibPos2 << endl; 
    txtOutput << mstrNcu_RH_SensorCalibPos2 << endl;  
    txtOutput << mstrNcu_RV_SensorCalibPos2 << endl; 
    txtOutput << mstrNcu_AxisAngularLowerSpeed_ch1 << endl;  
    txtOutput << mstrNcu_AxisAngularLowerSpeed_ch2 << endl;  
    txtOutput << mstrNcu_AxisAngularHighSpeed_ch1 << endl; 
    txtOutput << mstrNcu_AxisAngularHighSpeed_ch2 << endl; 
    txtOutput << mstrNcu_H_RapidMoveSpeed_ch1 << endl;  
    txtOutput << mstrNcu_H_RapidMoveSpeed_ch2 << endl;  
    txtOutput << mstrNcu_V_RapidMoveSpeed_ch1 << endl; 
    txtOutput << mstrNcu_V_RapidMoveSpeed_ch2 << endl; 

    txtOutput << mstrPlc_LH_RailOffset << endl;  
    txtOutput << mstrPlc_LV_RailOffset << endl; 
    txtOutput << mstrPlc_RH_RailOffset << endl;  
    txtOutput << mstrPlc_RV_RailOffset << endl; 
    txtOutput << mstrPlc_AxisAngularLowerSpeed << endl;  
    txtOutput << mstrPlc_AxisAngularHighSpeed << endl; 
	txtOutput << mstrPlc_L_SMWDiameter << endl;  
 	txtOutput << mstrPlc_R_SMWDiameter << endl;  
	txtOutput << mstrPlc_LiftCutterPower << endl; 
    txtOutput << mstrPlc_LiftCutterTime << endl;  
    txtOutput << mstrPlc_EndCuttingPower << endl; 
    txtOutput << mstrPlc_EndCuttingTime << endl;  
    txtOutput << mstrPlc_H_RapidMoveSpeed << endl; 
    txtOutput << mstrPlc_V_RapidMoveSpeed << endl;  
    txtOutput << mstrPlc_OffsetSlopeLength << endl; 
	
	f.close(); 
	//for test End
	//--------------------------------------------------------------------*/
}

void OperateIni::ReadCPOffsetParameters( )
{
	g->m_LH_CPOffset1 = m_pconfigIniRead->value(PCU_LH_CPOFFSET1).toDouble();
	g->m_LV_CPOffset1 = m_pconfigIniRead->value(PCU_LV_CPOFFSET1).toDouble();
	g->m_RH_CPOffset1 = m_pconfigIniRead->value(PCU_RH_CPOFFSET1).toDouble();
	g->m_RV_CPOffset1 = m_pconfigIniRead->value(PCU_RV_CPOFFSET1).toDouble();
	g->m_LH_CPOffset2 = m_pconfigIniRead->value(PCU_LH_CPOFFSET2).toDouble();
	g->m_LV_CPOffset2 = m_pconfigIniRead->value(PCU_LV_CPOFFSET2).toDouble();
	g->m_RH_CPOffset2 = m_pconfigIniRead->value(PCU_RH_CPOFFSET2).toDouble();
	g->m_RV_CPOffset2 = m_pconfigIniRead->value(PCU_RV_CPOFFSET2).toDouble();

	g->m_H_SoftShoeLen = m_pconfigIniRead->value(PCU_H_SOFTSHOELEN).toDouble();
	g->m_V_SoftShoeLen = m_pconfigIniRead->value(PCU_V_SOFTSHOELEN).toDouble();
	g->m_H_SoftShoeAlph = m_pconfigIniRead->value(PCU_H_SOFTSHOEALPH).toDouble();
	g->m_V_SoftShoeAlph = m_pconfigIniRead->value(PCU_V_SOFTSHOEALPH).toDouble();
	g->m_H_SoftShoeLayer = m_pconfigIniRead->value(PCU_H_SOFTSHOELAYER).toInt();
	g->m_V_SoftShoeLayer = m_pconfigIniRead->value(PCU_V_SOFTSHOELAYER).toInt();
	g->m_H_SoftShoeDirRatio1 = m_pconfigIniRead->value(PCU_H_SOFTSHOEDIRRATIO1).toDouble();
	g->m_V_SoftShoeDirRatio1 = m_pconfigIniRead->value(PCU_V_SOFTSHOEDIRRATIO1).toDouble();
	g->m_H_SoftShoeDirRatio2 = m_pconfigIniRead->value(PCU_H_SOFTSHOEDIRRATIO2).toDouble();
	g->m_V_SoftShoeDirRatio2 = m_pconfigIniRead->value(PCU_V_SOFTSHOEDIRRATIO2).toDouble();
	g->m_LH_SensorRatio = m_pconfigIniRead->value(PCU_LH_SENSORRATIO).toDouble();
	g->m_LV_SensorRatio = m_pconfigIniRead->value(PCU_LV_SENSORRATIO).toDouble();
	g->m_RH_SensorRatio = m_pconfigIniRead->value(PCU_RH_SENSORRATIO).toDouble();
	g->m_RV_SensorRatio = m_pconfigIniRead->value(PCU_RV_SENSORRATIO).toDouble();

	g->m_H_bLowPassFilter = m_pconfigIniRead->value(PCU_H_LOWPASSFILTER).toBool();
	g->m_V_bLowPassFilter = m_pconfigIniRead->value(PCU_V_LOWPASSFILTER).toBool();

	g->m_LH_bSensorPriority = m_pconfigIniRead->value(PCU_LH_SENSORPRIORITY).toBool();
	g->m_LV_bSensorPriority = m_pconfigIniRead->value(PCU_LV_SENSORPRIORITY).toBool();
	g->m_RH_bSensorPriority = m_pconfigIniRead->value(PCU_RH_SENSORPRIORITY).toBool();
	g->m_RV_bSensorPriority = m_pconfigIniRead->value(PCU_RV_SENSORPRIORITY).toBool();

	g->m_bSoftShoeDir = m_pconfigIniRead->value(PCU_SOFTSHOEDIR).toBool();

	QStringList list;
	list = m_pconfigIniRead->value(NCU_LH_CPOFFSET1).toStringList();		
	mstrNcu_LH_CPOffset1 = IniQStringListToQString(list);				
	list = m_pconfigIniRead->value(NCU_LV_CPOFFSET1).toStringList();		
	mstrNcu_LV_CPOffset1 = IniQStringListToQString(list);				
	list = m_pconfigIniRead->value(NCU_RH_CPOFFSET1).toStringList();			
	mstrNcu_RH_CPOffset1 = IniQStringListToQString(list);					
	list = m_pconfigIniRead->value(NCU_RV_CPOFFSET1).toStringList();			
	mstrNcu_RV_CPOffset1 = IniQStringListToQString(list);	
	list = m_pconfigIniRead->value(NCU_LH_CPOFFSET2).toStringList();		
	mstrNcu_LH_CPOffset2 = IniQStringListToQString(list);				
	list = m_pconfigIniRead->value(NCU_LV_CPOFFSET2).toStringList();		
	mstrNcu_LV_CPOffset2 = IniQStringListToQString(list);				
	list = m_pconfigIniRead->value(NCU_RH_CPOFFSET2).toStringList();			
	mstrNcu_RH_CPOffset2 = IniQStringListToQString(list);					
	list = m_pconfigIniRead->value(NCU_RV_CPOFFSET2).toStringList();			
	mstrNcu_RV_CPOffset2 = IniQStringListToQString(list);	

	/*--------------------------------------------------------------------
	//for test Start
	QFile f("C:/scr/test.txt");  
	if(!f.open(QIODevice::WriteOnly | QIODevice::Text ))  
    {  
        //cout << "Open failed." << endl;  
        return ;  
    }  
    QTextStream txtOutput(&f);

    txtOutput << mstrNcu_LH_CPOffset1 << endl;  
    txtOutput << mstrNcu_LV_CPOffset1 << endl; 
    txtOutput << mstrNcu_RH_CPOffset1 << endl;  
    txtOutput << mstrNcu_RV_CPOffset1 << endl; 
    txtOutput << mstrNcu_LH_CPOffset2 << endl;  
    txtOutput << mstrNcu_LV_CPOffset2 << endl; 
    txtOutput << mstrNcu_RH_CPOffset2 << endl;  
    txtOutput << mstrNcu_RV_CPOffset2 << endl; 
	
	f.close(); 
	//for test End
	//--------------------------------------------------------------------*/
}

void OperateIni::SaveCPOffsetParameters( )
{
	QSettings *configIniWrite = new QSettings("C:/scr/parameter.ini", QSettings::IniFormat);
	configIniWrite->setValue(PCU_LH_CPOFFSET1,g->m_LH_CPOffset1);
	configIniWrite->setValue(PCU_LV_CPOFFSET1,g->m_LV_CPOffset1);
	configIniWrite->setValue(PCU_RH_CPOFFSET1,g->m_RH_CPOffset1);
	configIniWrite->setValue(PCU_RV_CPOFFSET1,g->m_RV_CPOffset1);
	configIniWrite->setValue(PCU_LH_CPOFFSET2,g->m_LH_CPOffset2);
	configIniWrite->setValue(PCU_LV_CPOFFSET2,g->m_LV_CPOffset2);
	configIniWrite->setValue(PCU_RH_CPOFFSET2,g->m_RH_CPOffset2);
	configIniWrite->setValue(PCU_RV_CPOFFSET2,g->m_RV_CPOffset2);
	configIniWrite->setValue(PCU_H_SOFTSHOELEN,g->m_H_SoftShoeLen);
	configIniWrite->setValue(PCU_V_SOFTSHOELEN,g->m_V_SoftShoeLen);
	configIniWrite->setValue(PCU_H_SOFTSHOEALPH,g->m_H_SoftShoeAlph);
	configIniWrite->setValue(PCU_V_SOFTSHOEALPH,g->m_V_SoftShoeAlph);
	configIniWrite->setValue(PCU_H_SOFTSHOELAYER,g->m_H_SoftShoeLayer);
	configIniWrite->setValue(PCU_V_SOFTSHOELAYER,g->m_V_SoftShoeLayer);
	configIniWrite->setValue(PCU_H_SOFTSHOEDIRRATIO1,g->m_H_SoftShoeDirRatio1);
	configIniWrite->setValue(PCU_V_SOFTSHOEDIRRATIO1,g->m_V_SoftShoeDirRatio1);
	configIniWrite->setValue(PCU_H_SOFTSHOEDIRRATIO2,g->m_H_SoftShoeDirRatio2);
	configIniWrite->setValue(PCU_V_SOFTSHOEDIRRATIO2,g->m_V_SoftShoeDirRatio2);
	configIniWrite->setValue(PCU_LH_SENSORRATIO,g->m_LH_SensorRatio);
	configIniWrite->setValue(PCU_LV_SENSORRATIO,g->m_LV_SensorRatio);
	configIniWrite->setValue(PCU_RH_SENSORRATIO,g->m_RH_SensorRatio);
	configIniWrite->setValue(PCU_RV_SENSORRATIO,g->m_RV_SensorRatio);

	configIniWrite->setValue(PCU_H_LOWPASSFILTER,g->m_H_bLowPassFilter);
	configIniWrite->setValue(PCU_V_LOWPASSFILTER,g->m_V_bLowPassFilter);

	configIniWrite->setValue(PCU_LH_SENSORPRIORITY,g->m_LH_bSensorPriority);
	configIniWrite->setValue(PCU_LV_SENSORPRIORITY,g->m_LV_bSensorPriority);
	configIniWrite->setValue(PCU_RH_SENSORPRIORITY,g->m_RH_bSensorPriority);
	configIniWrite->setValue(PCU_RV_SENSORPRIORITY,g->m_RV_bSensorPriority);
	configIniWrite->setValue(PCU_SOFTSHOEDIR,g->m_bSoftShoeDir);
	delete configIniWrite; 
}

void OperateIni::SaveSystemParameters( bool bRest )
{
	QSettings *configIniWrite = new QSettings("C:/scr/parameter.ini", QSettings::IniFormat);
	configIniWrite->setValue(PCU_LH_RAILOFFSET,g->m_LH_RailOffset);
	configIniWrite->setValue(PCU_LV_RAILOFFSET,g->m_LV_RailOffset);
	configIniWrite->setValue(PCU_RH_RAILOFFSET,g->m_RH_RailOffset);
	configIniWrite->setValue(PCU_RV_RAILOFFSET,g->m_RV_RailOffset);

	//configIniWrite->setValue(PCU_LH_MOTORCALIBPOS,g->m_LH_MotorCalibPos);
	//configIniWrite->setValue(PCU_RH_MOTORCALIBPOS,g->m_RH_MotorCalibPos);
	configIniWrite->setValue(PCU_LV_MOTORCALIBPOS,g->m_LV_MotorCalibPos);
	configIniWrite->setValue(PCU_RV_MOTORCALIBPOS,g->m_RV_MotorCalibPos);

	if(bRest == false){
		configIniWrite->setValue(PCU_LH_SENSORCALIBPOS1,g->m_LH_SensorCalibPos1);
		configIniWrite->setValue(PCU_LV_SENSORCALIBPOS1,g->m_LV_SensorCalibPos1);
		configIniWrite->setValue(PCU_RH_SENSORCALIBPOS1,g->m_RH_SensorCalibPos1);
		configIniWrite->setValue(PCU_RV_SENSORCALIBPOS1,g->m_RV_SensorCalibPos1);
		configIniWrite->setValue(PCU_LH_SENSORCALIBPOS2,g->m_LH_SensorCalibPos2);
		configIniWrite->setValue(PCU_LV_SENSORCALIBPOS2,g->m_LV_SensorCalibPos2);
		configIniWrite->setValue(PCU_RH_SENSORCALIBPOS2,g->m_RH_SensorCalibPos2);
		configIniWrite->setValue(PCU_RV_SENSORCALIBPOS2,g->m_RV_SensorCalibPos2);
	}
	else{
		configIniWrite->setValue(PCU_CUTTERDIAMETER,g->m_CutterDiameter);
	}
	configIniWrite->setValue(PCU_AXISANGULARLOWERSPEED,g->m_LowAxisAngularSpeed);
	configIniWrite->setValue(PCU_AXISANGULARHIGHSPEED,g->m_HighAxisAngularSpeed);
	configIniWrite->setValue(PCU_L_SMWDIAMETER,g->m_L_SMWDiameter);
	configIniWrite->setValue(PCU_R_SMWDIAMETER,g->m_R_SMWDiameter);
	configIniWrite->setValue(PCU_LIFTCUTTERPOWER,g->m_LiftCutterPower);
	configIniWrite->setValue(PCU_LIFTCUTTERTIME,g->m_LiftCutterTime);
	configIniWrite->setValue(PCU_ENDCUTTINGPOWER,g->m_EndCuttingPower);
	configIniWrite->setValue(PCU_ENDCUTTINGTIME,g->m_EndCuttingTime);
	configIniWrite->setValue(PCU_H_RAPIDMOVESPEED,g->m_H_RapidSpeed);
	configIniWrite->setValue(PCU_V_RAPIDMOVESPEED,g->m_V_RapidSpeed);
	configIniWrite->setValue(PCU_OFFSETSLOPELENGTH,g->m_OffsetSlopeLength);
	delete configIniWrite; 
}

void OperateIni::ReadSoftLimitParameters( )
{
	g->m_LH_MotorPosHigh = m_pconfigIniRead->value(PCU_LH_MOTORPOSHIGH).toDouble();
	g->m_LH_MotorPosLow = m_pconfigIniRead->value(PCU_LH_MOTORPOSLOW).toDouble();
	g->m_LV_MotorPosHigh = m_pconfigIniRead->value(PCU_LV_MOTORPOSHIGH).toDouble();
	g->m_LV_MotorPosLow = m_pconfigIniRead->value(PCU_LV_MOTORPOSLOW).toDouble();
	g->m_RH_MotorPosHigh = m_pconfigIniRead->value(PCU_RH_MOTORPOSHIGH).toDouble();
	g->m_RH_MotorPosLow = m_pconfigIniRead->value(PCU_RH_MOTORPOSLOW).toDouble();
	g->m_RV_MotorPosHigh = m_pconfigIniRead->value(PCU_RV_MOTORPOSHIGH).toDouble();
	g->m_RV_MotorPosLow = m_pconfigIniRead->value(PCU_RV_MOTORPOSLOW).toDouble();

	g->m_LH_CutterProtect = m_pconfigIniRead->value(PCU_LH_CUTTERPROTECT).toDouble();
	g->m_LV_CutterProtect = m_pconfigIniRead->value(PCU_LV_CUTTERPROTECT).toDouble();
	g->m_RH_CutterProtect = m_pconfigIniRead->value(PCU_RH_CUTTERPROTECT).toDouble();
	g->m_RV_CutterProtect = m_pconfigIniRead->value(PCU_RV_CUTTERPROTECT).toDouble();
	g->m_H_CutBiasStep = m_pconfigIniRead->value(PCU_H_CUTBIASSTEP).toDouble();
	g->m_V_CutBiasStep = m_pconfigIniRead->value(PCU_V_CUTBIASSTEP).toDouble();
	g->m_H_MinCutStep = m_pconfigIniRead->value(PCU_H_MINCUTSTEP).toDouble();
	g->m_V_MinCutStep = m_pconfigIniRead->value(PCU_V_MINCUTSTEP).toDouble();
}

void OperateIni::SaveSoftLimitParameters()
{
	QSettings *configIniWrite = new QSettings("C:/scr/parameter.ini", QSettings::IniFormat);
	configIniWrite->setValue(PCU_LH_MOTORPOSHIGH,g->m_LH_MotorPosHigh);
	configIniWrite->setValue(PCU_LH_MOTORPOSLOW,g->m_LH_MotorPosLow);
	configIniWrite->setValue(PCU_LV_MOTORPOSHIGH,g->m_LV_MotorPosHigh);
	configIniWrite->setValue(PCU_LV_MOTORPOSLOW,g->m_LV_MotorPosLow);
	configIniWrite->setValue(PCU_RH_MOTORPOSHIGH,g->m_RH_MotorPosHigh);
	configIniWrite->setValue(PCU_RH_MOTORPOSLOW,g->m_RH_MotorPosLow);
	configIniWrite->setValue(PCU_RV_MOTORPOSHIGH,g->m_RV_MotorPosHigh);
	configIniWrite->setValue(PCU_RV_MOTORPOSLOW,g->m_RV_MotorPosLow);

	configIniWrite->setValue(PCU_LH_CUTTERPROTECT,g->m_LH_CutterProtect);
	configIniWrite->setValue(PCU_LV_CUTTERPROTECT,g->m_LV_CutterProtect);
	configIniWrite->setValue(PCU_RH_CUTTERPROTECT,g->m_RH_CutterProtect);
	configIniWrite->setValue(PCU_RV_CUTTERPROTECT,g->m_RV_CutterProtect);

	configIniWrite->setValue(PCU_H_CUTBIASSTEP,g->m_H_CutBiasStep);
	configIniWrite->setValue(PCU_V_CUTBIASSTEP,g->m_V_CutBiasStep);
	configIniWrite->setValue(PCU_H_MINCUTSTEP,g->m_H_MinCutStep);
	configIniWrite->setValue(PCU_V_MINCUTSTEP,g->m_V_MinCutStep);
	delete configIniWrite; 
}

void OperateIni::ReadRailCalibParameters( )
{
	g->m_LH_MotorCalibPos = m_pconfigIniRead->value(PCU_LH_MOTORCALIBPOS).toDouble();
	g->m_LV_MotorCalibPos = m_pconfigIniRead->value(PCU_LV_MOTORCALIBPOS).toDouble();
	g->m_RH_MotorCalibPos = m_pconfigIniRead->value(PCU_RH_MOTORCALIBPOS).toDouble();
	g->m_RV_MotorCalibPos = m_pconfigIniRead->value(PCU_RV_MOTORCALIBPOS).toDouble();
	g->m_LScannerToCutterOffset = m_pconfigIniRead->value(PCU_LSCANNERTOCUTTEROFFSET).toDouble();
	g->m_RScannerToCutterOffset = m_pconfigIniRead->value(PCU_RSCANNERTOCUTTEROFFSET).toDouble();

	g->m_LH_CutDepthOffset = m_pconfigIniRead->value(PCU_LH_CUTTINGDEPTHOFFSET).toDouble();
	g->m_LV_CutDepthOffset = m_pconfigIniRead->value(PCU_LV_CUTTINGDEPTHOFFSET).toDouble();
	g->m_RH_CutDepthOffset = m_pconfigIniRead->value(PCU_RH_CUTTINGDEPTHOFFSET).toDouble();
	g->m_RV_CutDepthOffset = m_pconfigIniRead->value(PCU_RV_CUTTINGDEPTHOFFSET).toDouble();

	QStringList list;
	list = m_pconfigIniRead->value(NCU_LH_MOTORCALIBPOS).toStringList();		
	mstrNcu_LH_MotorCalibPos = IniQStringListToQString(list);				
	list = m_pconfigIniRead->value(NCU_LV_MOTORCALIBPOS).toStringList();		
	mstrNcu_LV_MotorCalibPos = IniQStringListToQString(list);				
	list = m_pconfigIniRead->value(NCU_RH_MOTORCALIBPOS).toStringList();			
	mstrNcu_RH_MotorCalibPos = IniQStringListToQString(list);					
	list = m_pconfigIniRead->value(NCU_RV_MOTORCALIBPOS).toStringList();			
	mstrNcu_RV_MotorCalibPos = IniQStringListToQString(list);	

	/*--------------------------------------------------------------------
	//for test Start
	QFile f("C:/scr/test.txt");  
	if(!f.open(QIODevice::WriteOnly | QIODevice::Text ))  
    {  
        //cout << "Open failed." << endl;  
        return ;  
    }  
    QTextStream txtOutput(&f);

    txtOutput << mstrNcu_LH_MotorCalibPos << endl;  
    txtOutput << mstrNcu_LV_MotorCalibPos << endl; 
    txtOutput << mstrNcu_RH_MotorCalibPos << endl;  
    txtOutput << mstrNcu_RV_MotorCalibPos << endl; 
	
	f.close(); 
	//for test End
	//--------------------------------------------------------------------*/
}

void OperateIni::SaveRailCalibParameters( int nType )
{
	QSettings *configIniWrite = new QSettings("C:/scr/parameter.ini", QSettings::IniFormat);
	switch(nType)
	{
	case STATIC_SAVE:
		configIniWrite->setValue(PCU_LSCANNERTOCUTTEROFFSET,g->m_LScannerToCutterOffset);
		configIniWrite->setValue(PCU_RSCANNERTOCUTTEROFFSET,g->m_RScannerToCutterOffset);
		configIniWrite->setValue(PCU_LH_CUTTINGDEPTHOFFSET,g->m_LH_CutDepthOffset);
		configIniWrite->setValue(PCU_LV_CUTTINGDEPTHOFFSET,g->m_LV_CutDepthOffset);
		configIniWrite->setValue(PCU_RH_CUTTINGDEPTHOFFSET,g->m_RH_CutDepthOffset);
		configIniWrite->setValue(PCU_RV_CUTTINGDEPTHOFFSET,g->m_RV_CutDepthOffset);
		break;
	case DYNAMIC_SAVE:
		configIniWrite->setValue(PCU_LH_MOTORCALIBPOS,g->m_LH_MotorCalibPos);
		configIniWrite->setValue(PCU_LV_MOTORCALIBPOS,g->m_LV_MotorCalibPos);
		configIniWrite->setValue(PCU_RH_MOTORCALIBPOS,g->m_RH_MotorCalibPos);
		configIniWrite->setValue(PCU_RV_MOTORCALIBPOS,g->m_RV_MotorCalibPos);

		configIniWrite->setValue(PCU_LH_SENSORCALIBPOS1,g->m_LH_SensorCalibPos1);
		configIniWrite->setValue(PCU_LV_SENSORCALIBPOS1,g->m_LV_SensorCalibPos1);
		configIniWrite->setValue(PCU_RH_SENSORCALIBPOS1,g->m_RH_SensorCalibPos1);
		configIniWrite->setValue(PCU_RV_SENSORCALIBPOS1,g->m_RV_SensorCalibPos1);
		configIniWrite->setValue(PCU_LH_SENSORCALIBPOS2,g->m_LH_SensorCalibPos2);
		configIniWrite->setValue(PCU_LV_SENSORCALIBPOS2,g->m_LV_SensorCalibPos2);
		configIniWrite->setValue(PCU_RH_SENSORCALIBPOS2,g->m_RH_SensorCalibPos2);
		configIniWrite->setValue(PCU_RV_SENSORCALIBPOS2,g->m_RV_SensorCalibPos2);
		break;
	default:
		break;
	}
	delete configIniWrite; 
}

void OperateIni::ReadMileageParameters( )
{
	g->m_SMWTotalTrainMileage = m_pconfigIniRead->value(ENTRY_MILEAGE_TRAIN).toDouble();
	g->m_SMWTotalWorkMileage = m_pconfigIniRead->value(ENTRY_MILEAGE_WORK).toDouble();

	g->m_SMWLastRSTTrainMileage = m_pconfigIniRead->value(ENTRY_MILEAGE_RESETTRAINMILEAGE).toDouble();
	g->m_SMWLastRSTWorkMileage = m_pconfigIniRead->value(ENTRY_MILEAGE_RESETWORKMILEAGE).toDouble();
	QString strBuffer = m_pconfigIniRead->value(ENTRY_MILEAGE_RESETTIME).toString();
	g->m_SMWLastResetTime = QDateTime::fromString(strBuffer, "yyyy-MM-dd hh:mm:ss");  
}

void OperateIni::ReadDebugParameters()
{
	QByteArray byteArray = m_pconfigIniRead->value(ENTRY_DEBUG_SETDEFAULT).toByteArray();
	m_strSetDefault = m_pcodec->toUnicode(byteArray);
}

void OperateIni::ReadShineStateParameters()//ligy 20190928 add
{
	QByteArray byteArray = m_pconfigIniRead->value(ENTRY_SHINESTATE_UNKOWN).toByteArray();
	m_strStateShineUnkown = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_SHINESTATE_WAITING).toByteArray();
	m_strStateShineWaiting = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_SHINESTATE_READY).toByteArray();
	m_strStateShineReady = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_SHINESTATE_DOWN1).toByteArray();
	m_strStateShineDown1 = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_SHINESTATE_DOWN2).toByteArray();
	m_strStateShineDown2 = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_SHINESTATE_START).toByteArray();
	m_strStateShineStart = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_SHINESTATE_END).toByteArray();
	m_strStateShineEnd = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_SHINESTATE_UP).toByteArray();
	m_strStateShineUp = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_SHINESTATE_EMGENCYSTOP).toByteArray();
	m_strStateShineEmgencyStop = m_pcodec->toUnicode(byteArray);//打磨急停

	//ligy 20200212 add.保存参数
	byteArray = m_pconfigIniRead->value("/SaveData/Data1").toByteArray();
	m_strSaveDataParam1 = m_pcodec->toUnicode(byteArray);//保存参数1
	byteArray = m_pconfigIniRead->value("/SaveData/Data2").toByteArray();
	m_strSaveDataParam2 = m_pcodec->toUnicode(byteArray);//保存参数2
	byteArray = m_pconfigIniRead->value("/SaveData/Data3").toByteArray();
	m_strSaveDataParam3 = m_pcodec->toUnicode(byteArray);//保存参数3
	byteArray = m_pconfigIniRead->value("/SaveData/Data4").toByteArray();
	m_strSaveDataParam4 = m_pcodec->toUnicode(byteArray);//保存参数4
	byteArray = m_pconfigIniRead->value("/SaveData/Data5").toByteArray();
	m_strSaveDataParam5 = m_pcodec->toUnicode(byteArray);//保存参数5
	byteArray = m_pconfigIniRead->value("/SaveData/Data6").toByteArray();
	m_strSaveDataParam6 = m_pcodec->toUnicode(byteArray);//保存参数6
	byteArray = m_pconfigIniRead->value("/SaveData/Data7").toByteArray();
	m_strSaveDataParam7 = m_pcodec->toUnicode(byteArray);//保存参数7
	byteArray = m_pconfigIniRead->value("/SaveData/Data8").toByteArray();
	m_strSaveDataParam8 = m_pcodec->toUnicode(byteArray);//保存参数8
	byteArray = m_pconfigIniRead->value("/SaveData/Data9").toByteArray();
	m_strSaveDataParam9 = m_pcodec->toUnicode(byteArray);//保存参数9
	byteArray = m_pconfigIniRead->value("/SaveData/Data10").toByteArray();
	m_strSaveDataParam10 = m_pcodec->toUnicode(byteArray);//保存参数10
	byteArray = m_pconfigIniRead->value("/SaveData/Data11").toByteArray();
	m_strSaveDataParam11 = m_pcodec->toUnicode(byteArray);//保存参数11
	byteArray = m_pconfigIniRead->value("/SaveData/Data12").toByteArray();
	m_strSaveDataParam12 = m_pcodec->toUnicode(byteArray);//保存参数12
	byteArray = m_pconfigIniRead->value("/SaveData/Data13").toByteArray();
	m_strSaveDataParam13 = m_pcodec->toUnicode(byteArray);//保存参数13
	byteArray = m_pconfigIniRead->value("/SaveData/Data14").toByteArray();
	m_strSaveDataParam14 = m_pcodec->toUnicode(byteArray);//保存参数14
	byteArray = m_pconfigIniRead->value("/SaveData/Data15").toByteArray();
	m_strSaveDataParam15 = m_pcodec->toUnicode(byteArray);//保存参数15
	byteArray = m_pconfigIniRead->value("/SaveData/Data16").toByteArray();
	m_strSaveDataParam16 = m_pcodec->toUnicode(byteArray);//保存参数16
	byteArray = m_pconfigIniRead->value("/SaveData/Data17").toByteArray();
	m_strSaveDataParam17 = m_pcodec->toUnicode(byteArray);//保存参数17
	byteArray = m_pconfigIniRead->value("/SaveData/Data18").toByteArray();
	m_strSaveDataParam18 = m_pcodec->toUnicode(byteArray);//保存参数18
	byteArray = m_pconfigIniRead->value("/SaveData/Data19").toByteArray();
	m_strSaveDataParam19 = m_pcodec->toUnicode(byteArray);//保存参数19
	byteArray = m_pconfigIniRead->value("/SaveData/Data20").toByteArray();
	m_strSaveDataParam20 = m_pcodec->toUnicode(byteArray);//保存参数20
	byteArray = m_pconfigIniRead->value("/SaveData/Data21").toByteArray();
	m_strSaveDataParam21 = m_pcodec->toUnicode(byteArray);//保存参数21
	byteArray = m_pconfigIniRead->value("/SaveData/Data22").toByteArray();
	m_strSaveDataParam22 = m_pcodec->toUnicode(byteArray);//保存参数22
	byteArray = m_pconfigIniRead->value("/SaveData/Data23").toByteArray();
	m_strSaveDataParam23 = m_pcodec->toUnicode(byteArray);//保存参数23
	byteArray = m_pconfigIniRead->value("/SaveData/Data24").toByteArray();
	m_strSaveDataParam24 = m_pcodec->toUnicode(byteArray);//保存参数24
	byteArray = m_pconfigIniRead->value("/SaveData/Data25").toByteArray();
	m_strSaveDataParam25 = m_pcodec->toUnicode(byteArray);//保存参数25
	byteArray = m_pconfigIniRead->value("/SaveData/Data26").toByteArray();
	m_strSaveDataParam26 = m_pcodec->toUnicode(byteArray);//保存参数26
	byteArray = m_pconfigIniRead->value("/SaveData/Data27").toByteArray();
	m_strSaveDataParam27 = m_pcodec->toUnicode(byteArray);//保存参数27

	//日志
	byteArray = m_pconfigIniRead->value(ENTRY_LOG_OPERATETIME).toByteArray();
	m_strLog_OperateTime = m_pcodec->toUnicode(byteArray);//
	byteArray = m_pconfigIniRead->value(ENTRY_LOG_OPERATOR).toByteArray();
	m_strLog_Operator = m_pcodec->toUnicode(byteArray);//
	byteArray = m_pconfigIniRead->value(ENTRY_LOG_OPERATETYPE).toByteArray();
	m_strLog_OperateType = m_pcodec->toUnicode(byteArray);//

	byteArray = m_pconfigIniRead->value(ENTRY_LOG_LOGIN).toByteArray();
	m_strLog_Login = m_pcodec->toUnicode(byteArray);//
	byteArray = m_pconfigIniRead->value(ENTRY_LOG_LOGOFF).toByteArray();
	m_strLog_Logoff = m_pcodec->toUnicode(byteArray);//
	byteArray = m_pconfigIniRead->value(ENTRY_LOG_SYSPARAMSAVE).toByteArray();
	m_strLog_SysParamSave = m_pcodec->toUnicode(byteArray);//
	byteArray = m_pconfigIniRead->value(ENTRY_LOG_WORKPARAMSAVE).toByteArray();
	m_strLog_WorkParamSave = m_pcodec->toUnicode(byteArray);//
	byteArray = m_pconfigIniRead->value(ENTRY_LOG_SCANPARAMSAVE).toByteArray();
	m_strLog_ScanParamSave = m_pcodec->toUnicode(byteArray);//
	byteArray = m_pconfigIniRead->value(ENTRY_LOG_BODYSTART).toByteArray();
	m_strLog_BodyStart = m_pcodec->toUnicode(byteArray);//
	byteArray = m_pconfigIniRead->value(ENTRY_LOG_BODYSTOP).toByteArray();
	m_strLog_BodyStop = m_pcodec->toUnicode(byteArray);//
	byteArray = m_pconfigIniRead->value(ENTRY_LOG_HYDRAULICSTART).toByteArray();
	m_strLog_HydraulicStart = m_pcodec->toUnicode(byteArray);//
	byteArray = m_pconfigIniRead->value(ENTRY_LOG_HYDRAULICSTOP).toByteArray();
	m_strLog_HydraulicStop = m_pcodec->toUnicode(byteArray);//
	byteArray = m_pconfigIniRead->value(ENTRY_LOG_CHIPSTART).toByteArray();
	m_strLog_ChipStart = m_pcodec->toUnicode(byteArray);//
	byteArray = m_pconfigIniRead->value(ENTRY_LOG_CHIPSTOP).toByteArray();
	m_strLog_ChipStop = m_pcodec->toUnicode(byteArray);//
	byteArray = m_pconfigIniRead->value(ENTRY_LOG_SPEEDWHEELSTART).toByteArray();
	m_strLog_SpeedWheelStart = m_pcodec->toUnicode(byteArray);//
	byteArray = m_pconfigIniRead->value(ENTRY_LOG_SPEEDWHEELSTOP).toByteArray();
	m_strLog_SpeedWheelStop = m_pcodec->toUnicode(byteArray);//
	//ligy 20200214 add.启动列车等文本翻译
	byteArray = m_pconfigIniRead->value(ENTRY_LOG_STARTTRAIN).toByteArray();
	m_strLog_StartTrain = m_pcodec->toUnicode(byteArray);//
	byteArray = m_pconfigIniRead->value(ENTRY_LOG_STOPTRAIN).toByteArray();
	m_strLog_StopTrain= m_pcodec->toUnicode(byteArray);//
	byteArray = m_pconfigIniRead->value(ENTRY_LOG_STARTWORK).toByteArray();
	m_strLog_StartWork = m_pcodec->toUnicode(byteArray);//
	byteArray = m_pconfigIniRead->value(ENTRY_LOG_STOPWORK).toByteArray();
	m_strLog_StopWork = m_pcodec->toUnicode(byteArray);//
	byteArray = m_pconfigIniRead->value(ENTRY_LOG_DEVICEUP).toByteArray();
	m_strLog_DeviceUp = m_pcodec->toUnicode(byteArray);//
	byteArray = m_pconfigIniRead->value(ENTRY_LOG_DEVICEDOWN).toByteArray();
	m_strLog_DeviceDown = m_pcodec->toUnicode(byteArray);//
	
}
void OperateIni::ReadWorkStateParameters()
{
	QByteArray byteArray = m_pconfigIniRead->value(ENTRY_WORKSTATE_UNKOWN).toByteArray();
	m_strStateUnkown = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_WORKSTATE_YFELLOW).toByteArray();
	m_strStateYFellow = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_WORKSTATE_CUTIN).toByteArray();
	m_strStateCutIn = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_WORKSTATE_MILLING).toByteArray();
	m_strStateMilling = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_WORKSTATE_CUTOUT).toByteArray();
	m_strStateCutOut = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_WORKSTATE_ENDFELLOW).toByteArray();
	m_strStateEndFellow = m_pcodec->toUnicode(byteArray);

	byteArray = m_pconfigIniRead->value(ENTRY_WORKSTATE_WAITING).toByteArray();
	m_strStateWaiting = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_WORKSTATE_READY).toByteArray();
	m_strStateReady = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_WORKSTATE_SCAN).toByteArray();
	m_strStateScan = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_WORKSTATE_LOADDOWN1).toByteArray();
	m_strStateLoadDown1 = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_WORKSTATE_STARTTRAIN1).toByteArray();
	m_strStateStartTrain1 = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_WORKSTATE_STARTTRAIN2).toByteArray();
	m_strStateStartTrain2 = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_WORKSTATE_STARTWORK).toByteArray();
	m_strStateStartWork = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_WORKSTATE_STOPWORK).toByteArray();
	m_strStateStopWork = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_WORKSTATE_STOPTRAIN).toByteArray();
	m_strStateStopTrain = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_WORKSTATE_LOADDOWN2).toByteArray();
	m_strStateLoadDown2 = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_WORKSTATE_DEVICEUP).toByteArray();
	m_strStateDeviceUp = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_WORKSTATE_EMERGENCY).toByteArray();
	m_strStateEmergency = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_WORKSTATE_REPAIR).toByteArray();
	m_strStateRepair = m_pcodec->toUnicode(byteArray);
}

void OperateIni::ReadRepairParameters()
{
	QByteArray byteArray = m_pconfigIniRead->value(ENTRY_REPAIR_PWD).toByteArray();
	m_strRepairPwd = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_REPAIR_PWDERROR).toByteArray();
	m_strRepairPwdError = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_REPAIR_LOGIN).toByteArray();
	m_strRepairLogin = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_REPAIR_LOGOFF).toByteArray();
	m_strRepairLogoff = m_pcodec->toUnicode(byteArray);

	byteArray = m_pconfigIniRead->value(ENTRY_DEBUG_PWD).toByteArray();
	m_strDebugPwd = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_DEBUG_PWDERROR).toByteArray();
	m_strDebugPwdError = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_DEBUG_LOGIN).toByteArray();
	m_strDebugLogin = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_DEBUG_LOGOFF).toByteArray();
	m_strDebugLogoff = m_pcodec->toUnicode(byteArray);
}

void OperateIni::SaveMileageParameters( )
{
	QSettings *configIniWrite = new QSettings("C:/scr/parameter.ini", QSettings::IniFormat);
	configIniWrite->setValue(ENTRY_MILEAGE_TRAIN,g->m_SMWTotalTrainMileage);
	configIniWrite->setValue(ENTRY_MILEAGE_WORK,g->m_SMWTotalWorkMileage);
	configIniWrite->setValue(ENTRY_MILEAGE_RESETTRAINMILEAGE,g->m_SMWLastRSTTrainMileage);
	configIniWrite->setValue(ENTRY_MILEAGE_RESETWORKMILEAGE,g->m_SMWLastRSTWorkMileage);
	configIniWrite->setValue(ENTRY_MILEAGE_RESETTIME,g->m_SMWLastResetTime.toString("yyyy-MM-dd hh:mm:ss"));
	delete configIniWrite; 
}

void OperateIni::SaveUserPassword( QString NewPassword  )
{
	m_strPassword = NewPassword;
	QSettings *configIniWrite = new QSettings("C:/scr/parameter.ini", QSettings::IniFormat);
	configIniWrite->setValue(ENTRY_PASSWORD_STRING,m_strPassword);
	delete configIniWrite; 
}

void OperateIni::SaveRepairPassword( QString NewPassword )
{
	m_strRepairPwd = NewPassword;
	QSettings *configIniWrite = new QSettings("C:/scr/parameter.ini", QSettings::IniFormat);
	configIniWrite->setValue(ENTRY_REPAIR_PWD,m_strRepairPwd);
	delete configIniWrite; 
}

void OperateIni::SaveDebugPassword( QString NewPassword )
{
	m_strDebugPsw = NewPassword;
	QSettings *configIniWrite = new QSettings("C:/scr/parameter.ini", QSettings::IniFormat);
	configIniWrite->setValue(ENTRY_NN_DEBUGPSW,m_strDebugPsw);
	delete configIniWrite; 
}

void OperateIni::ReadLoginParameters( )
{
	//Read INI file,Get The ProductType
	QByteArray byteArray = m_pconfigIniRead->value(ENTRY_USERNAME_STRING).toByteArray();
	m_strUserName = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_PASSWORD_STRING).toByteArray();
	m_strPassword = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_NAMEERROR_STRING).toByteArray();
	m_strNameError = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_PDWERROR_STRING).toByteArray();
	m_strPwdError = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_LOGIN_STRING).toByteArray();
	m_strLogin = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_NOTLOGIN_STRING).toByteArray();
	m_strNotLogin = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_MODIFY_SUCCESS).toByteArray();
	m_strModifySuccess = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_MODIFY_FAILED).toByteArray();
	m_strModifyFailed = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_LOGIN_NAME).toByteArray();
	m_strLoginName = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_LOGOFF_NAME).toByteArray();
	m_strLogoffName = m_pcodec->toUnicode(byteArray);
}

void OperateIni::ReadProductParameters( )
{
	//Read INI file,Get The ProductType
	QByteArray byteArray = m_pconfigIniRead->value(ENTRY_PRODUCT_TYPE).toByteArray();
	m_strProductInfo = m_pcodec->toUnicode(byteArray);
}

void OperateIni::ReadErrorListHeaders( )
{
	QByteArray byteArray = m_pconfigIniRead->value(ENTRY_ERROR_NUMBER).toByteArray();
	m_strErrorNumber = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_ERROR_TIME).toByteArray();
	m_strErrorTime = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_ERROR_STATE).toByteArray();
	m_strErrorState = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_ERROR_TEXT).toByteArray();
	m_strErrorText = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_ERROR_WORKSTATE).toByteArray();
	m_strErrorWorkState = m_pcodec->toUnicode(byteArray);
}

void OperateIni::ReadStatusListHeaders( )
{
	QByteArray byteArray = m_pconfigIniRead->value(ENTRY_STATUSLIST_CONTROLUNIT).toByteArray();
	m_strStatusListControlUnit = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_STATUSLIST_ADDRESS).toByteArray();
	m_strStatusListAddress = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_STATUSLIST_STATUS).toByteArray();
	m_strStatusListStatus = m_pcodec->toUnicode(byteArray);
}

void OperateIni::ReadNNScreenParameters( )
{
	QByteArray byteArray = m_pconfigIniRead->value(ENTRY_NN_DEBUGPSW).toByteArray();
	m_strDebugPsw = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_NN_WAITFORREMOTE).toByteArray();
	m_strWaitForRemote = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_NN_LOGINSUCCESS).toByteArray();
	m_strLoginSuccess = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_NN_LOGINFAILED).toByteArray();
	m_strLoginFailed = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_NN_LOGINPREID).toByteArray();
	m_strLoginPreID = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_NN_CONNECTSUCCESS).toByteArray();
	m_strConnectSuccess = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_NN_STOP).toByteArray();
	m_strStop = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_NN_OFFLINE).toByteArray();
	m_strOffLine = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_NN_CONNECTFAILED).toByteArray();
	m_strConnectFailed = m_pcodec->toUnicode(byteArray);
}

void OperateIni::ReadInfoParameters()
{
	QByteArray byteArray = m_pconfigIniRead->value(ENTRY_INFO_TRAINSPDNOTREACH).toByteArray();
	m_strTrainSpdNotReach = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_INFO_AXISSPDNOTREACH).toByteArray();
	m_strAxisSpdNotReach = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_INFO_DISKSPACELOW).toByteArray();
	m_strDiskSpaceLow = m_pcodec->toUnicode(byteArray);
	byteArray = m_pconfigIniRead->value(ENTRY_INFO_DISKSPACEALARM).toByteArray();
	m_strDiskSpaceAlarm = m_pcodec->toUnicode(byteArray);
}

void OperateIni::ResetAllParameters( )
{
	QSettings* pconfigIniRead = new QSettings("C:/scr/parameter.ini", QSettings::IniFormat); 
	//-------------------------Workling Parameters(12 parameters)------------------------//
	g->m_LH_CutDepth = pconfigIniRead->value(RST_LH_CUTTINGDEPTH).toDouble();
	g->m_LV_CutDepth = pconfigIniRead->value(RST_LV_CUTTINGDEPTH).toDouble();
	g->m_RH_CutDepth = pconfigIniRead->value(RST_RH_CUTTINGDEPTH).toDouble();
	g->m_RV_CutDepth = pconfigIniRead->value(RST_RV_CUTTINGDEPTH).toDouble();
	g->m_H_DeviceIniPos = pconfigIniRead->value(RST_H_DEVICEINIPOS).toDouble();
	g->m_V_DeviceIniPos = pconfigIniRead->value(RST_V_DEVICEINIPOS).toDouble();
	g->m_H_WorkIniPos = pconfigIniRead->value(RST_H_WORKINIPOS).toDouble();
	g->m_V_WorkIniPos = pconfigIniRead->value(RST_V_WORKINIPOS).toDouble();
	g->m_DstTrainSpeed = pconfigIniRead->value(RST_TRAINSPEED).toDouble();
	g->m_SlopeLength = pconfigIniRead->value(RST_SLOPELENGTH).toDouble();
	g->m_HighSpindleSpeed = pconfigIniRead->value(RST_AXISLINEHIGHSPEED).toDouble();
	g->m_LowerSpindleSpeed = pconfigIniRead->value(RST_AXISLINELOWERSPEED).toDouble();
	//---------------------System Parameters(16 parameters)------------------------//
	g->m_LH_RailOffset = pconfigIniRead->value(RST_LH_RAILOFFSET).toDouble();
	g->m_LV_RailOffset = pconfigIniRead->value(RST_LV_RAILOFFSET).toDouble();
	g->m_RH_RailOffset = pconfigIniRead->value(RST_RH_RAILOFFSET).toDouble();
	g->m_RV_RailOffset = pconfigIniRead->value(RST_RV_RAILOFFSET).toDouble();
	g->m_LowAxisAngularSpeed = pconfigIniRead->value(RST_AXISANGULARLOWERSPEED).toDouble();
	g->m_HighAxisAngularSpeed = pconfigIniRead->value(RST_AXISANGULARHIGHSPEED).toDouble();
	g->m_L_SMWDiameter = pconfigIniRead->value(RST_L_SMWDIAMETER).toDouble();
	g->m_R_SMWDiameter = pconfigIniRead->value(RST_R_SMWDIAMETER).toDouble();
	g->m_LiftCutterPower = pconfigIniRead->value(RST_LIFTCUTTERPOWER).toDouble();
	g->m_LiftCutterTime = pconfigIniRead->value(RST_LIFTCUTTERTIME).toDouble();
	g->m_EndCuttingPower = pconfigIniRead->value(RST_ENDCUTTINGPOWER).toDouble();
	g->m_EndCuttingTime = pconfigIniRead->value(RST_ENDCUTTINGTIME).toDouble();
	g->m_H_RapidSpeed = pconfigIniRead->value(RST_H_RAPIDMOVESPEED).toDouble();
	g->m_V_RapidSpeed = pconfigIniRead->value(RST_V_RAPIDMOVESPEED).toDouble();
	g->m_OffsetSlopeLength = pconfigIniRead->value(RST_OFFSETSLOPELENGTH).toDouble();
	g->m_CutterDiameter = pconfigIniRead->value(RST_CUTTERDIAMETER).toDouble();
	//-----------------------CPOffset Parameters(8 parameters)---------------------//
	/*
	g->m_LH_CPOffset1 = pconfigIniRead->value(RST_LH_CPOFFSET1).toDouble();
	g->m_LV_CPOffset1 = pconfigIniRead->value(RST_LV_CPOFFSET1).toDouble();
	g->m_RH_CPOffset1 = pconfigIniRead->value(RST_RH_CPOFFSET1).toDouble();
	g->m_RV_CPOffset1 = pconfigIniRead->value(RST_RV_CPOFFSET1).toDouble();
	g->m_LH_CPOffset2 = pconfigIniRead->value(RST_LH_CPOFFSET2).toDouble();
	g->m_LV_CPOffset2 = pconfigIniRead->value(RST_LV_CPOFFSET2).toDouble();
	g->m_RH_CPOffset2 = pconfigIniRead->value(RST_RH_CPOFFSET2).toDouble();
	g->m_RV_CPOffset2 = pconfigIniRead->value(RST_RV_CPOFFSET2).toDouble();
	g->m_LScannerToCutterOffset = m_pconfigIniRead->value(RST_LSCANNERTOCUTTEROFFSET).toDouble();
	g->m_RScannerToCutterOffset = m_pconfigIniRead->value(RST_RSCANNERTOCUTTEROFFSET).toDouble();
	*/
	delete pconfigIniRead; 

	SaveWorkParameters( );
	SaveSystemParameters( true );
	//SaveCPOffsetParameters( );
}

