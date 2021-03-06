#include "QTcuCom.h"


QTcuCom::QTcuCom(void)
{
	//Start Timer
	m_tmrToggle.setSingleShot(false);
	m_tmrToggle.setInterval(100);
	// signal/slot connection for QTimer
	QObject::connect( &m_tmrToggle,SIGNAL(timeout()),this,SLOT(TimeoutSlot()) );
	// start timer
	//m_tmrToggle.start();
	m_bEnableTCU = true;

	m_bConnected = false;
	m_socket = INVALID_SOCKET;

	/*if(m_bEnableTCU){
		WSADATA wsaData;
		int Ret;
		if((Ret=WSAStartup(MAKEWORD(2,2),&wsaData))!=0)
		{
			WSACleanup();
		}
	}*/

	m_nHeartBeatCount = 0;

	m_nCurHeartBeatWord = 0;
	m_nCurStatusWord = 0;
	m_nCurWorkMileage_H = 0;
	m_nCurWorkMileage_L = 0;
	m_nCurSetSpeed = 0;

	m_nPreHeartBeatWord = m_nCurHeartBeatWord;
	m_nPreStatusWord = m_nCurStatusWord;
	m_nPreWorkMileage_H = m_nCurWorkMileage_H;
	m_nPreWorkMileage_L = m_nCurWorkMileage_L;
	m_nPreSetSpeed = m_nCurSetSpeed;
}

QTcuCom::~QTcuCom(void)
{
	if(m_tmrToggle.isActive())
		m_tmrToggle.stop();

	/*if(m_bEnableTCU){
		TcuComDisConnect( );
		WSACleanup();
	}*/
}

int QTcuCom::TcuComConnect( )
{
	if( m_bEnableTCU ){
		int con=0;
		/*
		QString ipAddr = "192.168.0.100";
		int port=502;
		m_socket = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
		struct sockaddr_in server;
		server.sin_family = AF_INET;
		server.sin_port = htons(port);
		QByteArray byte = ipAddr.toLatin1();
		char* ip=byte.data();
		server.sin_addr.s_addr = inet_addr(ip);	

		struct sockaddr_in localhost;
		localhost.sin_family = AF_INET;
		u_short portlocal=0;
		localhost.sin_port = htons(portlocal);
		QString ipl="127.0.0.1";
		QByteArray bytelocal = ipl.toLatin1();
		char* iplocal=bytelocal.data();
		localhost.sin_addr.s_addr = inet_addr(iplocal);
		con = bind(m_socket, (SOCKADDR *)&localhost,sizeof(localhost));
		*/   
		m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  

		sockaddr_in server;  
		server.sin_family = AF_INET;  
		server.sin_port = htons(502);  
		server.sin_addr.s_addr = inet_addr("172.16.0.21"/*"192.168.0.100"*/);  
  
		if(con>=0)
			con = ::connect(m_socket,(SOCKADDR *)&server,sizeof(server));
		if(con<0)
		{
			if(m_socket != INVALID_SOCKET)
			{
				closesocket(m_socket);
				m_socket = INVALID_SOCKET;
			}
		}
		else
			m_bConnected = true;

		return con;
	}
	return 0;
}

int QTcuCom::TcuComDisConnect( )
{
	if( m_bEnableTCU ){
		closesocket(m_socket);
		m_socket = INVALID_SOCKET;
		m_bConnected = false;
	}
    return 0;
}

void QTcuCom::TimeOutSlot( )
{

}

void QTcuCom::savelog(const QString& text)
{
	QFile file("..\\..\\..\\..\\oem\\sinumerik\\data\\trainmilling\\timerlog.txt");
	if(file.open(QIODevice::WriteOnly|QIODevice::Append))
	{
		QTextStream stream(&file);
		stream<<text<<QString("\r\n");
	}
	file.close();
}

/*--------------------------------------------------*/
//program 1 : SetHeartBeat!
/*--------------------------------------------------*/
void QTcuCom::SetHeartBeat( )
{
	if( m_bEnableTCU ){
		m_nHeartBeatCount++;
		if(m_nHeartBeatCount == 40){
			m_nCurHeartBeatWord = 0;
		}
		if(m_nHeartBeatCount == 80){
			m_nHeartBeatCount = 0;
			m_nCurHeartBeatWord = 1;
		}
	}
}

/*--------------------------------------------------*/
//program 2 : EnableTrain!
/*--------------------------------------------------*/
void QTcuCom::EnableTrain(bool bEnable)
{
	if( m_bEnableTCU ){

		if(bEnable)
			m_nCurStatusWord |= STATUS_ENABLETRAIN_BIT;
		else
			m_nCurStatusWord &= (~STATUS_ENABLETRAIN_BIT);
	}
}

/*--------------------------------------------------*/
//program 3 : SetTrainSpeed!
/*--------------------------------------------------*/
void QTcuCom::SetTrainSpeed(double fSpeed)
{
	if( m_bEnableTCU ){
		m_nCurSetSpeed = WORD(fSpeed*1000);
	}
}

/*--------------------------------------------------*/
//program 4 : SetWorkMileage!
/*--------------------------------------------------*/
void QTcuCom::SetWorkMileage(double fWorkMileage)
{
	if( m_bEnableTCU ){
		int iCurWorkMileage = int(fWorkMileage*1000);
		m_nCurWorkMileage_L = iCurWorkMileage & 0x0000FFFF;
		m_nCurWorkMileage_H = (iCurWorkMileage >> 16)& 0x0000FFFF;
	}
}

/*--------------------------------------------------*/
//program 5 : SetDeviceLockState!
/*--------------------------------------------------*/
void QTcuCom::SetDeviceLockState(bool bLocked)
{
	if( m_bEnableTCU ){

		if(bLocked)
			m_nCurStatusWord |= STATUS_DEVICELOCK_BIT;
		else
			m_nCurStatusWord &= (~STATUS_DEVICELOCK_BIT);
	}
}

/*--------------------------------------------------*/
//program 6 : SetWorkStartState!
/*--------------------------------------------------*/
void QTcuCom::SetWorkStartState(bool bStart)
{
	if( m_bEnableTCU ){

		if(bStart)
			m_nCurStatusWord |= STATUS_WORKSTART_BIT;
		else
			m_nCurStatusWord &= (~STATUS_WORKSTART_BIT);
	}
}

/*--------------------------------------------------*/
//program 7 : SetEmergencyLiftState!
/*--------------------------------------------------*/
void QTcuCom::SetEmergencyState(bool bEmergency)
{
	if( m_bEnableTCU ){

		if(bEmergency)
			m_nCurStatusWord |= STATUS_EMERGENCY_BIT;
		else
			m_nCurStatusWord &= (~STATUS_EMERGENCY_BIT);
	}
}

/*--------------------------------------------------*/
//program 8 : SetDeviceHighState!
/*--------------------------------------------------*/
void QTcuCom::SetDeviceHighState(bool bHigh)
{
	if( m_bEnableTCU ){

		if(bHigh)
			m_nCurStatusWord |= STATUS_DEVICEHIGH_BIT;
		else
			m_nCurStatusWord &= (~STATUS_DEVICEHIGH_BIT);
	}
}


/*--------------------------------------------------*/
//program 9 : SetDeviceErrState!
/*--------------------------------------------------*/
void QTcuCom::SetDeviceErrState(bool bErr)
{
	if( m_bEnableTCU ){

		if(bErr)
			m_nCurStatusWord |= STATUS_DEVICEERR_BIT;
		else
			m_nCurStatusWord &= (~STATUS_DEVICEERR_BIT);
	}
}

/*--------------------------------------------------*/
//program 10 : SendTcuData!
/*--------------------------------------------------*/
int QTcuCom::SendTcuData( )
{
	if( m_bEnableTCU && m_bConnected ){
		//----------First Word-----------
		if(m_nPreHeartBeatWord != m_nCurHeartBeatWord){
			int Len = WriteRegister(1,m_nCurHeartBeatWord);
			m_nPreHeartBeatWord = m_nCurHeartBeatWord;
			if( -1 == Len ){
				return -1;
			}
		}
		//----------Second m_nCurStatusWord-----------
		if(m_nPreStatusWord != m_nCurStatusWord){
			int Len =  WriteRegister(2,m_nCurStatusWord);
			/*
			int iLen = WriteRegister(7,m_nCurStatusWord+1);
			int jLen = WriteRegister(8,m_nCurStatusWord+2);
			int kLen = WriteRegister(9,m_nCurStatusWord+3);
			*/	
			m_nPreStatusWord = m_nCurStatusWord;
			if( -1 == Len ){
				return -1;
			}
		}	
		//----------Third m_nCurWorkMileage_H-----------
		if(m_nPreWorkMileage_H != m_nCurWorkMileage_H){
			int Len = WriteRegister(3,m_nCurWorkMileage_H);
			m_nPreWorkMileage_H = m_nCurWorkMileage_H;
			if( -1 == Len ){
				return -1;
			}
		}	
		//----------Fourth m_nCurWorkMileage_H-----------
		if(m_nPreWorkMileage_L != m_nCurWorkMileage_L){
			int Len = WriteRegister(4,m_nCurWorkMileage_L);
			m_nPreWorkMileage_L = m_nCurWorkMileage_L;
			if( -1 == Len ){
				return -1;
			}
		}	
		//----------Fifth m_nCurSetSpeed-----------
		if(m_nPreSetSpeed != m_nCurSetSpeed){
			int Len = WriteRegister(5,m_nCurSetSpeed);
			m_nPreSetSpeed = m_nCurSetSpeed;
			if( -1 == Len ){
				return -1;
			}
		}	
	}

	return 0;
}

int QTcuCom::WriteRegister(WORD addr, WORD value)
{
	/*
	//Mothod 1 : write Mutiple Registers
	unsigned char Temp_buf[20];
	Temp_buf[0] = 0;
	Temp_buf[1] = 0;
	Temp_buf[2] = 0;
	Temp_buf[3] = 0;
	Temp_buf[4] = 0;
	Temp_buf[5] = 9;
	Temp_buf[6] = 1;//id
	Temp_buf[7] = 16;
	Temp_buf[8] = (addr-1)/256;
	Temp_buf[9] = (addr-1) % 256;
	Temp_buf[10] = 0;
	Temp_buf[11] = 1;
	Temp_buf[12] = 2;
	Temp_buf[13] = value/256;
	Temp_buf[14] = value%256;
	int Len = send(m_socket,(char*)Temp_buf,15,0);
	return Len;
	*/
	//Mothod 2 :write Single Register
	unsigned char Temp_buf[20];
	Temp_buf[0] = 0;
	Temp_buf[1] = 0;
	Temp_buf[2] = 0;
	Temp_buf[3] = 0;
	Temp_buf[4] = 0;
	Temp_buf[5] = 6;
	Temp_buf[6] = 1;
	Temp_buf[7] = 6;
	Temp_buf[8] = (addr-1)/256;
	Temp_buf[9] = (addr-1) % 256;
	Temp_buf[10] = value/256;
	Temp_buf[11] = value%256;
	int Len = send(m_socket,(char*)Temp_buf,12,0);
	return Len;
}
