@echo off
IF EXIST "c:\Documents and Settings\Administrator\My Documents\Visual Studio 2008\Projects\TrainMilling\TrainMilling\Debug\Output\appl\..\cfg" GOTO EndCfg:
mkdir "c:\Documents and Settings\Administrator\My Documents\Visual Studio 2008\Projects\TrainMilling\TrainMilling\Debug\Output\appl\..\cfg"
:EndCfg

IF EXIST "c:\Documents and Settings\Administrator\My Documents\Visual Studio 2008\Projects\TrainMilling\TrainMilling\Debug\Output\appl\..\hlp" GOTO EndHlp:
mkdir "c:\Documents and Settings\Administrator\My Documents\Visual Studio 2008\Projects\TrainMilling\TrainMilling\Debug\Output\appl\..\hlp"
:EndHlp

IF EXIST "c:\Documents and Settings\Administrator\My Documents\Visual Studio 2008\Projects\TrainMilling\TrainMilling\Debug\Output\appl\..\lng" GOTO EndLng:
mkdir "c:\Documents and Settings\Administrator\My Documents\Visual Studio 2008\Projects\TrainMilling\TrainMilling\Debug\Output\appl\..\lng"
:EndLng

if errorlevel 1 goto VCReportError
goto VCEnd
:VCReportError
echo Project : error PRJ0019: A tool returned an error code from "Performing Pre-Build Event..."
exit 1
:VCEnd