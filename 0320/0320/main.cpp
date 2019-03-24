
#include <stdlib.h>
#include <WinSock2.h>
#include <Windows.h>
#include <stdio.h>
#include <time.h>

#pragma comment(lib, "ws2_32")


int main(int argc, char* argv[])
{
	//1
	printf("HOSTNAME = %s\n", getenv("COMPUTERNAME"));
	printf("DOMAINNAME = %s\n\n", getenv("USERDOMAIN"));
	
	//2
	WSADATA wsadata;
	int nRet = WSAStartup(MAKEWORD(2, 2), &wsadata);
	struct hostent *myent;
	myent = gethostbyname(argv[1]);

	int i = 0;
	while (myent->h_addr_list[i] != NULL)
	{
		in_addr addr;
		char *temp;

		addr.s_addr = *((u_long *)(myent->h_addr_list[i]));
		temp = inet_ntoa(addr);
		printf("IP Address(16) : %x\n", inet_addr(temp));
		printf("IP Address(10) : %s\n", temp);
		i++;
	}

	printf("HOSTNAME = %s\n\n", myent->h_name);
	WSACleanup();
	
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

	system("pause");
	return 0;
}