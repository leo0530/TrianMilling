/* ͷ�ļ�NNVideo.h

  ��ӭʹ��NN P2P������Ƶ���쿪������
ʹ�øÿ��������������ʵ������QQ��MSN��P2P��Ƶ�������칦�ܡ�

  ���������������ʹ�ã��Һܸ����ܹ��յ���������
����/����, �ҽ����Ժ�İ汾�кܿ�Ľ���ʵ��.
  �������������ʹ�ã����ṩ10��ͬʱ���ߵ���Ѳ��Է�������
����Ҫ����ķ�������������ͬʱ��������������Ҫ֧��һ������Ȩ��

  �ٷ���վ��http://www.enen6.com
*/
//״̬����
#define NNTYPE_CURRENT	1	//��ǰ����״̬
#define NNTYPE_ONLINE	2	//����״̬
#define NNTYPE_DEVICE	3	//��Ƶ�豸,�ûس����зָ����豸.
#define NNTYPE_ID		4	//����ID�����ڱ�־���ͻ���
#define NNTYPE_SEND		5  //�Ƿ��Ͷ� 
//�û��ӿ�
//1��������Ƶ���ڣ������������ڣ����أ���������Ƶ���ڡ�
HWND WINAPI NNSCreateWindow(HWND hWndParent);
//2:ɾ����Ƶ���ڣ��˳�����ʱ���á�
void WINAPI NNSDestory();
//3:��½��������������������IP����Ȩ���кš�
BOOL WINAPI NNSLogin(LPCSTR strIP,LPCSTR strSerial);
//4:�������ӡ��������Է�ID,����ʧ�ܺ��Ƿ�ͨ����������ת.
BOOL WINAPI NNSConnect(LPCSTR strUser,BOOL bUserServer);
//5:ֹͣ�Ự
void WINAPI NNSStopChat();
//6:��ȡ״̬��������״̬����:NNTYPE_CURRENT,NNTYPE_ONLINE,NNTYPE_DEVICE,NNTYPE_ID
//ע�ⷵ��ֵ�����޸�.
LPCSTR WINAPI NNSGetStatus(int nType); 
//7:������ɫ��Ⱥ��Ƿ���նԷ�������.������ɫ��ȷֱ�Ϊ4,8,16.�����Ƿ�������Ϊ1��0
int WINAPI NNSSetDevice(int nDevice);
//8:�Ƿ�ͨ��������ת,���˫������ֱ���������������»�ͨ����������ת��
BOOL WINAPI NNSIsFromServer();
//9:ˢ�´���λ�û��Сʱ����.
void WINAPI NNSUpdateWidnow();
//10:��ʼ����Ƶ�豸.������������Ƶ���ڣ���Ƶ�豸��ţ�Ŀǰ���ã�����������
int WINAPI NNSInitVideoDevice(HWND hWndShow,int nDevice);

//��������
BOOL WINAPI NNSSendData(LPCSTR strUser,char* pBuf,int nLen,BYTE nType);
//��ȡ����
int WINAPI NNSReadData(char* strUser,char* pBuf,int nLen,BYTE& nType);

//���ļ�,�����������ھ��(NULL��ʾ�رմ���)�������ļ�·���Ļ������������ļ���С
DWORD WINAPI NNSOpenFileSafe(HWND hParent,char* pFilePath);
//�����ļ����ļ����������ھ���������ļ�·���Ļ�������
BOOL WINAPI NNSReceiveFileSave(LPCSTR strFileName,HWND hParent,char* pFilePath);
//��ʽ�����ļ�����ʼ���͵�λ��
BOOL WINAPI NNSSendFile(DWORD dwStart);
//��ʽ�����ļ�����ʼ���͵�λ��
BOOL WINAPI NNSRecvFile(DWORD dwStart);

//�����ļ�����,0��ʾ����
DWORD WINAPI NNSFilePos();