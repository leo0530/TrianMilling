///////////////////////////////////////////////////////////////////////////////
/*! \file	scanform.h
 *  \author
 *  \date
 *  \brief	Definition file for class ScanForm
 *
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef SCANFORM_H_INCLUDED
#define SCANFORM_H_INCLUDED

#include "ui_scanform.h" //vom UIC erzeugte Header-Datei
#include "TrainMillingdialog.h"
#include "slgfwdialogform.h"
#include <QtCore/QTimer>
#include "math.h"
#include "OperateIni.h"
#include "slgfwhmidialog.h"
#include "slgfwscreen.h"
#include "slgfwsoftkey.h"
#include "SlQCap.h"
#include "QFile.h"
#include "QTextStream.h"
/*! \class ScanForm:¹ìÀªÉ¨Ãè
 *  \brief
*/
class ScanForm : public SlGfwDialogForm,
					public Ui::ScanFormUi
{
    Q_OBJECT

public:
    ScanForm(QWidget* pParent = 0, const QString& rszName = QString::null);
    virtual ~ScanForm(void);

public:
	void TestScanData( );
	void ReadScanData( );
	void SwitchScanner( );
	void Increase();
	void Decrease();
	void QuickIncrease();
	void QuickDecrease();
	bool Save();
	void setSoftkeyDisable(int nSoftkey, bool bDisabled);
	void setSaveKeyState( );

public:
	void PlotDrawing( );

public slots:
	void TimeoutSlot();
	virtual void onFunction (const QString& rszFunction, const QString& rszArgs, bool& rbHandled);


private:
	QTimer	m_tmrToggle;//¶¨Ê±Æ÷

    void attachedToScreen(const QString& rszScreenName);
    void detachedFromScreen(const QString& rszScreenName);
};

#endif // SCANFORM_H_INCLUDED
