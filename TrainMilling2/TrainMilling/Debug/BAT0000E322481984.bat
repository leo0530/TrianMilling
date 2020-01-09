@echo off
copy  "c:\Documents and Settings\Administrator\My Documents\Visual Studio 2008\Projects\TrainMilling\TrainMilling\systemconfiguration.ini" "c:\Documents and Settings\Administrator\My Documents\Visual Studio 2008\Projects\TrainMilling\TrainMilling\Debug\Output\appl\..\cfg\systemconfiguration.ini"

if errorlevel 1 goto VCReportError
goto VCEnd
:VCReportError
echo Project : error PRJ0019: A tool returned an error code from "Copy  "c:\Documents and Settings\Administrator\My Documents\Visual Studio 2008\Projects\TrainMilling\TrainMilling\systemconfiguration.ini" "c:\Documents and Settings\Administrator\My Documents\Visual Studio 2008\Projects\TrainMilling\TrainMilling\Debug\Output\appl\..\cfg\systemconfiguration.ini""
exit 1
:VCEnd