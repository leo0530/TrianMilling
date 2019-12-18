/* 头文件NNVideo.h

  欢迎使用NN P2P网络视频聊天开发包。
使用该开发包你可以轻松实现类似QQ，MSN的P2P视频语音聊天功能。

  本开发包可以免费使用，我很高兴能够收到您反馈的
错误/建议, 我将在以后的版本中很快改进和实现.
  本开发包可免费使用，并提供10人同时在线的免费测试服务器。
若需要更多的服务器容量（即同时在线量），你需要支付一定的授权费

  官方网站：http://www.enen6.com
*/
//状态类型
#define NNTYPE_CURRENT	1	//当前操作状态
#define NNTYPE_ONLINE	2	//在线状态
#define NNTYPE_DEVICE	3	//视频设备,用回车换行分割多个设备.
#define NNTYPE_ID		4	//连接ID，用于标志本客户端
#define NNTYPE_SEND		5  //是否发送端 
//用户接口
//1：创建视频窗口，参数：父窗口；返回：创建的视频窗口。
HWND WINAPI NNSCreateWindow(HWND hWndParent);
//2:删除视频窗口，退出程序时调用。
void WINAPI NNSDestory();
//3:登陆服务器，参数：服务器IP，授权序列号。
BOOL WINAPI NNSLogin(LPCSTR strIP,LPCSTR strSerial);
//4:发起连接。参数：对方ID,连接失败后是否通过服务器中转.
BOOL WINAPI NNSConnect(LPCSTR strUser,BOOL bUserServer);
//5:停止会话
void WINAPI NNSStopChat();
//6:获取状态。参数：状态类型:NNTYPE_CURRENT,NNTYPE_ONLINE,NNTYPE_DEVICE,NNTYPE_ID
//注意返回值不能修改.
LPCSTR WINAPI NNSGetStatus(int nType); 
//7:设置颜色深度和是否接收对方鼠标控制.设置颜色深度分别为4,8,16.设置是否接收鼠标为1或0
int WINAPI NNSSetDevice(int nDevice);
//8:是否通服务器中转,如果双方不能直连，在允许的情况下会通过服务器中转。
BOOL WINAPI NNSIsFromServer();
//9:刷新窗口位置或大小时调用.
void WINAPI NNSUpdateWidnow();
//10:初始化视频设备.参数：本地视频窗口，视频设备序号，目前不用，可随意设置
int WINAPI NNSInitVideoDevice(HWND hWndShow,int nDevice);

//发送文字
BOOL WINAPI NNSSendData(LPCSTR strUser,char* pBuf,int nLen,BYTE nType);
//读取文字
int WINAPI NNSReadData(char* strUser,char* pBuf,int nLen,BYTE& nType);

//打开文件,参数：父窗口句柄(NULL表示关闭传输)，接收文件路径的缓冲区。返回文件大小
DWORD WINAPI NNSOpenFileSafe(HWND hParent,char* pFilePath);
//接收文件：文件名，父窗口句柄，接收文件路径的缓冲区。
BOOL WINAPI NNSReceiveFileSave(LPCSTR strFileName,HWND hParent,char* pFilePath);
//正式发送文件，开始发送的位置
BOOL WINAPI NNSSendFile(DWORD dwStart);
//正式接收文件，开始发送的位置
BOOL WINAPI NNSRecvFile(DWORD dwStart);

//返回文件进度,0表示结束
DWORD WINAPI NNSFilePos();