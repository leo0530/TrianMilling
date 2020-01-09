///////////////////////////////////////////////////////////////////////////////
/*! \file   mainform.h
 *  \author
 *  \date
 *  \brief  Definition file for class MainForm
 *
 *
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef MAINFORM_H_INCLUDED
#define MAINFORM_H_INCLUDED

#include "ui_mainform.h" //vom UIC erzeugte Header-Datei
#include "slgfwdialogform.h"
#include <QtCore/QTimer>
#include "slgfwhmidialog.h"
#include "slgfwscreen.h"
#include "slgfwsoftkey.h"
#include "OperateIni.h"
#include <QtNetwork/QTcpServer>//使用QTcpServer，需要添加QtNetwork4.lib
#include <QtNetwork/QTcpSocket>
#include <slaeqalarmptrlist.h >
/*! \class MainForm
 *  \brief
 */
class MainForm : public SlGfwDialogForm,
					public Ui::MainFormUi
{
	Q_OBJECT
public:
	MainForm(QWidget* pParent = 0, const QString& rszName = QString::null);
	virtual ~MainForm(void);

public:
	QTimer	m_tmrToggle;
	QTcpServer *tcpServer;
	QList<QTcpSocket*> tcpClient;
	QTcpSocket *currentClient;
	bool m_bStartTcp;

public:
	void			setHSoftkeyDisable(int nSoftkey, bool bDisabled);
	void			setVSoftkeyDisable(int nSoftkey, bool bDisabled);
	void			Login();
	void			Logoff(const QString& rsArgs);
	void			Start();
	void			Stop();
	void			OperateManual(const QString& rsArgs);
	void			OperateNotice(const QString& rsArgs);
	bool			TcpServerInit(void); //打开tcp服务器
	void			TcpServerClose(void);//关闭tcp服务器
public slots:
	void			TimeOutSlot( );     //定时器
	void			NewConnectionSlot();//客户端连接
	void			disconnectedSlot(); //客户端端口
	void			ReadDataSlot();     //收到数据

	virtual void	onFunction (const QString& rszFunction, const QString& rszArgs, bool& rbHandled);
signals:
	void			emitDiconnectSlot();
	void			emitShowSendData();
private:

	void			attachedToScreen(const QString& rszScreenName);
	void			detachedFromScreen(const QString& rszScreenName);
public:
	void			showLoginUI();
	void			hideLoginUI();
	void			setLoginOutKeyState();
	void			setHSoftkeyState();

};

#endif // MAINFORM_H_INCLUDED
