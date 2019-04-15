#define _CRT_SECURE_NO_WARNINGS         // 최신 VC++ 컴파일 시 경고 방지
#define _WINSOCK_DEPRECATED_NO_WARNINGS // 최신 VC++ 컴파일 시 경고 방지
#pragma comment(lib, "ws2_32")
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SERVERIP   "127.0.0.1"
#define SERVERPORT 9000
#define BUFSIZE    100

struct mPacket
{
public:
	int id;
	int x;
	int y;
	int z;
	char message[BUFSIZE];
};

// 소켓 함수 오류 출력 후 종료
void err_quit(char *msg)
{
    LPVOID lpMsgBuf;
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
        NULL, WSAGetLastError(),
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&lpMsgBuf, 0, NULL);
    MessageBox(NULL, (LPCTSTR)lpMsgBuf, (LPCWSTR)msg, MB_ICONERROR);
    LocalFree(lpMsgBuf);
    exit(1);
}

// 소켓 함수 오류 출력
void err_display(char *msg)
{
    LPVOID lpMsgBuf;
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
        NULL, WSAGetLastError(),
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&lpMsgBuf, 0, NULL);
    printf("[%s] %s", msg, (char *)lpMsgBuf);
    LocalFree(lpMsgBuf);
}

int main(int argc, char *argv[])
{
    int retval;

    // 윈속 초기화
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
        return 1;

    // socket()
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) err_quit("socket()");

    // connect()
    SOCKADDR_IN serveraddr;
    ZeroMemory(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(SERVERIP);
    serveraddr.sin_port = htons(SERVERPORT);
    retval = connect(sock, (SOCKADDR *)&serveraddr, sizeof(serveraddr));
    if (retval == SOCKET_ERROR) err_quit("connect()");

    // 데이터 통신에 사용할 변수
    char buf[BUFSIZE];
    char *testdata[] = {
        "안녕하세요",
        "반가워요",
        "오늘따라 할 이야기가 많을 것 같네요",
        "저도 그렇네요",
    };
	int len;
	

	srand(time(NULL));
	mPacket mine;
	mine.id = rand() % 10;
	mine.x = rand() % 10; mine.y = rand() % 10; mine.z = rand() % 10;

    // 서버와 데이터 통신
	//sprintf(buf, "%d", mine.id);
	//len = sizeof(int);
	//retval = send(sock, (char*)&len, sizeof(int), 0);
	//if (retval == SOCKET_ERROR) {
	//	err_display("send()");
	//}
	//retval = send(sock, buf, len, 0);
	//if (retval == SOCKET_ERROR) {
	//	err_display("send()");
	//}
	//printf("[TCP 클라이언트] %d바이트를 보냈습니다.\n", sizeof(int), retval);

	//sprintf(buf, "%d", mine.x);
	//len = sizeof(int);
	//retval = send(sock, (char*)&len, sizeof(int), 0);
	//if (retval == SOCKET_ERROR) {
	//	err_display("send()");
	//}
	//retval = send(sock, buf, len, 0);
	//if (retval == SOCKET_ERROR) {
	//	err_display("send()");
	//}
	//printf("[TCP 클라이언트] %d바이트를 보냈습니다.\n", sizeof(int), retval);

	//sprintf(buf, "%d", mine.y);
	//len = sizeof(int);
	//retval = send(sock, (char*)&len, sizeof(int), 0);
	//if (retval == SOCKET_ERROR) {
	//	err_display("send()");
	//}
	//retval = send(sock, buf, len, 0);
	//if (retval == SOCKET_ERROR) {
	//	err_display("send()");
	//}
	//printf("[TCP 클라이언트] %d바이트를 보냈습니다.\n", sizeof(int), retval);

	//sprintf(buf, "%d", mine.z);
	//len = sizeof(int);
	//retval = send(sock, (char*)&len, sizeof(int), 0);
	//if (retval == SOCKET_ERROR) {
	//	err_display("send()");
	//}
	//retval = send(sock, buf, len, 0);
	//if (retval == SOCKET_ERROR) {
	//	err_display("send()");
	//}
	//printf("[TCP 클라이언트] %d바이트를 보냈습니다.\n", sizeof(int), retval);


	//len = strlen(mine.message[0]);
	//strncpy(buf, mine.message[0], len);
	//retval = send(sock, (char*)&len, sizeof(int), 0);
	//if (retval == SOCKET_ERROR) {
	//	err_display("send()");
	//}

	//retval = send(sock, buf, len, 0);
	//if (retval == SOCKET_ERROR) {
	//	err_display("send()");
	//}
	//printf("[TCP 클라이언트] %d + %d바이트를 보냈습니다.\n", sizeof(int), retval);

	for (int i = 0; i < 4; i++)
	{
		len = strlen(testdata[i]);
		strncpy(mine.message, testdata[i], len);

		retval = send(sock, (char*)&len, sizeof(int), 0);
		if (retval == SOCKET_ERROR) {
			err_display("send()");
			break;
		}

		retval = send(sock, (char*)&mine, sizeof(mine) - BUFSIZE + len, 0);
		if (retval == SOCKET_ERROR) {
			err_display("send()");
			break;
		}
		printf("[TCP 클라이언트] %d + %d바이트를 보냈습니다.\n", sizeof(int), retval);
	}

  //  for (int i = 0; i < 4; i++) {
  //      // 데이터 입력(시뮬레이션)
  //      //memset(buf, '#', sizeof(buf));
		//len = strlen(testdata[i]);
  //      strncpy(buf, testdata[i], len);

  //      // 데이터 보내기
  //      //retval = send(sock, buf, BUFSIZE, 0);
		//retval = send(sock, (char*)&len, sizeof(int), 0);
		//if (retval == SOCKET_ERROR) {
		//	err_display("send()");
		//	break;
		//}

		//retval = send(sock, buf, len, 0);
  //      if (retval == SOCKET_ERROR) {
  //          err_display("send()");
  //          break;
  //      }
  //      printf("[TCP 클라이언트] %d + %d바이트를 보냈습니다.\n", sizeof(int), retval);
  //  }

    // closesocket()
    closesocket(sock);

    // 윈속 종료
    WSACleanup();
    return 0;
}
