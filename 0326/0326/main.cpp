#pragma comment(lib, "ws2_32")
#include <WinSock2.h>

void err_quit(char *msg)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	MessageBox(NULL, (LPCTSTR)lpMsgBuf, (LPCTSTR)msg, MB_ICONERROR);
	LocalFree(lpMsgBuf);
	exit(1);
	exit(1);
}

int main(int argc, char *argv[])
{
	//���� �ʱ�ȭ
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) return 1;

	MessageBox(NULL, L"�����ʱ�ȭ ����", L"����", MB_OK);
	
	//���� ���� socket()
	SOCKET tcp_sock = socket(AF_INET, SOCK_STREAM, 0);	//socket(����4, TCP, 0)
	if(tcp_sock == INVALID_SOCKET) err_quit("socket()");	//������ �������� �ʰ� INVALID_SOCKET�� ��ȯ���� ��� err_quit �Լ� ����
	MessageBox(NULL, L"TCP ���� ���� ����", L"����", MB_OK);	//������ �����Ǿ��ٸ� MessageBox ���

	//���� ���� closesocket()
	closesocket(tcp_sock);

	//���� ����
	WSACleanup();

	return 0;
}