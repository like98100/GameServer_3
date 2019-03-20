
#include <stdlib.h>
#include <WinSock2.h>
//#include <Windows.h>
#include <stdio.h>
#include <time.h>

//#pragma comment(lib, "ws2_32")

//IN_ADDR GetDefaultMyIP()
//{
//	char localhostname[MAX_PATH];
//	IN_ADDR addr = { 0, };
//
//	if (gethostname(localhostname, MAX_PATH) == SOCKET_ERROR)//ȣ��Ʈ �̸� ������
//	{
//		return addr;
//	}
//	HOSTENT *ptr = gethostbyname(localhostname);//ȣ��Ʈ ��Ʈ�� ������
//	while (ptr && ptr->h_name)
//	{
//		if (ptr->h_addrtype == PF_INET)//IPv4 �ּ� Ÿ���� ��
//		{
//			memcpy(&addr, ptr->h_addr_list[0], ptr->h_length);//�޸� ����
//			break;//�ݺ��� Ż��
//		}
//		ptr++;
//	}
//	return addr;
//}

// ������ �̸� -> IP �ּ�
BOOL GetIPAddr(char *name, IN_ADDR *addr)
{
	HOSTENT *ptr = gethostbyname(name);

	memcpy(addr, ptr->h_addr, ptr->h_length);
	return TRUE;
}


int main(void)
{
	//1
	printf("HOSTNAME = %s\n", getenv("COMPUTERNAME"));
	printf("DOMAINNAME = %s\n\n", getenv("USERDOMAIN"));
	
	//2
	//WSADATA wsadata;
	//WSAStartup(MAKEWORD(2, 2), &wsadata);
	//IN_ADDR str;
	struct hostent *myent;
	IN_ADDR *str;
	char localname[MAX_PATH];

	myent = gethostbyname(getenv("COMPUTERNAME"));
	GetIPAddr(localname, str);

	//str = GetDefaultMyIP();
	printf("IP Address(16) = \n");
	//printf("IP Address(10) = %s\n", inet_ntoa(str));
	printf("HOSTNAME = \n\n");
	
	//3
	time_t now = time(NULL); //�ý��� �ð��� ����
	struct tm *lt = localtime(&now); //tm ����ü�� ��ȯ

	//printf("%d�� %d�� %d��\n", lt->tm_year+1900, 
	//							lt->tm_mon+1,
	//							lt->tm_mday);

	//printf("%d�� %d��\n", lt->tm_hour, lt->tm_min);

	printf("%d�� %d�� %d�� %d�� %d�� %d��\n", lt->tm_year + 1900,
												lt->tm_mon + 1,
												lt->tm_mday,
												lt->tm_hour, 
												lt->tm_min,
												lt->tm_sec);
	return 0;
}