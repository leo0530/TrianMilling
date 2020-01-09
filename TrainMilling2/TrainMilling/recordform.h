///////////////////////////////////////////////////////////////////////////////
/*! \file	recordform.h
 *  \author
 *  \date
 *  \brief	Definition file for class RecordForm
 *
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef RECORDFORM_H_INCLUDED
#define RECORDFORM_H_INCLUDED

#include "ui_recordform.h" //vom UIC erzeugte Header-Datei
#include "slgfwdialogform.h"
#include "slqcap.h"
#include <QtCore/QTimer>
#include "GlobalVar.h"
#include "OperateIni.h"
#include "slgfwhmidialog.h"
#include "QMath.h"
#include "QFileDialog.h"
/*! \class RecordForm
 *  \brief
*/
#define LOCK_TIMEOUT        10000       // 10 Seconds  
#define LOCK_RETRIES        20  

class RecordForm : public SlGfwDialogForm,
					public Ui::RecordFormUi
{
    Q_OBJECT


public:

    ///////////////////////////////////////////////////////////////////////////
    // CREATORS
    ///////////////////////////////////////////////////////////////////////////

    /*!
     *	\fn RecordForm(QWidget* pParent = 0, const QString& rszName = QString::null)
     *
     *  Constructor
    */
    RecordForm(QWidget* pParent = 0, const QString& rszName = QString::null);

    /*! \fn virtual ~RecordForm(void)
     *
     *  Destructor
    */
    virtual ~RecordForm(void);

///////////////////////////////////////////////////////////////////////////////
// MANIPULATORS - system overrides
///////////////////////////////////////////////////////////////////////////////
public:
	QTimer	m_tmrToggle;
	double	m_xMin;
	double	m_yMin;
	double	m_xMax;
	double	m_yMax;

public slots:
	void	timeoutSlot( );
	void	RestorePressedSlot(int, const QPoint&, QWidget* );
	void	ZoomInPressedSlot(int, const QPoint&, QWidget* );
	void	ZoomOutPressedSlot(int, const QPoint&, QWidget* );
	void	RestoreReleasedSlot(int, const QPoint&, QWidget* );
	void	ZoomInReleasedSlot(int, const QPoint&, QWidget* );
	void	ZoomOutReleasedSlot(int, const QPoint&, QWidget* );
///////////////////////////////////////////////////////////////////////////////
// public SLOTS - system overrides
///////////////////////////////////////////////////////////////////////////////
/*!
*  \fn virtual void onFunction(const QString& rszFunction, const QString& rszArgs, bool& rbHandled);
*
*  Will be called by the framework, if a function should be executed, e.g. if a softkey
*  should execute a command
*/
virtual void onFunction (const QString& rszFunction, const QString& rszArgs, bool& rbHandled);


private:
	char	m_UdiskDrive;//uÅÌÇý¶¯Æ÷ÅÌ·û

///////////////////////////////////////////////////////////////////////////////
// member variables
///////////////////////////////////////////////////////////////////////////////

    void attachedToScreen(const QString& rszScreenName);
    void detachedFromScreen(const QString& rszScreenName);

	void checkMemory();
	bool copyDirectoryFiles(QString fromDir,QString toDir,bool coverFileIfExist);
	void setVSoftkeyDisable(int nSoftkey, bool bDisabled);
	bool UninstallUsb(char discId);
	void testPlotData();

	int  getFileTotalLines(QString strFile);
	bool showCurveData(QString strFile,int xCol,int y1Col,int y2Col,int y3Col);
	bool showCurveData_LH(QString strFile);
	bool showCurveData_LV(QString strFile);
	bool showCurveData_RH(QString strFile);
	bool showCurveData_RV(QString strFile);
	void clearCurveData();

///////////////////////////////////////////////////////////////////////////////
// private METHODS
///////////////////////////////////////////////////////////////////////////////
	void hideInfoUI();
	void showInfoUI_LH(QString strFile);
	void showInfoUI_LV(QString strFile);
	void showInfoUI_RH(QString strFile);
	void showInfoUI_RV(QString strFile);

};

#endif // RECORDFORM_H_INCLUDED
