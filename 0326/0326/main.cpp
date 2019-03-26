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
	//윈속 초기화
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) return 1;

	MessageBox(NULL, L"윈속초기화 성공", L"쪽지", MB_OK);
	
	//소켓 생성 socket()
	SOCKET tcp_sock = socket(AF_INET, SOCK_STREAM, 0);	//socket(버전4, TCP, 0)
	if(tcp_sock == INVALID_SOCKET) err_quit("socket()");	//소켓이 생성되지 않고 INVALID_SOCKET을 반환했을 경우 err_quit 함수 실행
	MessageBox(NULL, L"TCP 소켓 생성 성공", L"쪽지", MB_OK);	//소켓이 생성되었다면 MessageBox 출력

	//소켓 종료 closesocket()
	closesocket(tcp_sock);

	//윈속 종료
	WSACleanup();

	return 0;
}