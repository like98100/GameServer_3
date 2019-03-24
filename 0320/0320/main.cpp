
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

	system("pause");
	return 0;
}