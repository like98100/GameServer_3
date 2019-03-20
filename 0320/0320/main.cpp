
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
//	if (gethostname(localhostname, MAX_PATH) == SOCKET_ERROR)//호스트 이름 얻어오기
//	{
//		return addr;
//	}
//	HOSTENT *ptr = gethostbyname(localhostname);//호스트 엔트리 얻어오기
//	while (ptr && ptr->h_name)
//	{
//		if (ptr->h_addrtype == PF_INET)//IPv4 주소 타입일 때
//		{
//			memcpy(&addr, ptr->h_addr_list[0], ptr->h_length);//메모리 복사
//			break;//반복문 탈출
//		}
//		ptr++;
//	}
//	return addr;
//}

// 도메인 이름 -> IP 주소
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
	time_t now = time(NULL); //시스템 시각을 얻어옴
	struct tm *lt = localtime(&now); //tm 구조체로 변환

	//printf("%d년 %d월 %d일\n", lt->tm_year+1900, 
	//							lt->tm_mon+1,
	//							lt->tm_mday);

	//printf("%d시 %d분\n", lt->tm_hour, lt->tm_min);

	printf("%d년 %d월 %d일 %d시 %d분 %d초\n", lt->tm_year + 1900,
												lt->tm_mon + 1,
												lt->tm_mday,
												lt->tm_hour, 
												lt->tm_min,
												lt->tm_sec);
	return 0;
}