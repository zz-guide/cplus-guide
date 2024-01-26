#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>

#include <iostream>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int _error();
int main() {

	WORD ver = MAKEWORD(2, 2);
	WSADATA wsadata;
	int res = WSAStartup(ver, &wsadata);
	if (res != 0) {
		cout << "WSAStartup() failed" << endl;
		return EXIT_FAILURE;
	}
	else {
		cout << "WSAStartup() success" << endl;
	}

	// 检测版本号
	if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2) {
		cout << "Winsock版本号不符" << endl;
		WSACleanup();
		return EXIT_FAILURE;
	}
	else {
		cout << "Winsock版本正确" << endl;
	}

	// 客户端通过socket连接服务端 --------------------------------------------------
	int port = 15000;
	// 1. socket()
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN clientAddr = {};
	clientAddr.sin_family = AF_INET;
	clientAddr.sin_port = htons(port);
	// 将IPv4地址转换为网络字节顺序
	const char* ipAddress = "127.0.0.1";
	inet_pton(AF_INET, ipAddress, &(clientAddr.sin_addr));

	// 2. connect()
	int connectRes = connect(sock, (sockaddr*)&clientAddr, sizeof(clientAddr));
	if (connectRes == SOCKET_ERROR) {
		cout << "connect() failed" << WSAGetLastError() << endl;
		return _error();
	}
	else {
		cout << "connect() success" << endl;
	}

	cout << "==========================" << endl;

	// 3. 接收服务端信息
	char msg[128] = {};
	int recvLen = recv(sock, msg, sizeof(msg), 0);
	if (recvLen < 0) {
		cout << "未接收到数据" << endl;
	}
	else {
		cout << "接收到的数据内容:" << msg << endl;
	}

	closesocket(sock);
	WSACleanup();
	system("pause");
	return 0;
}

int _error() {
	WSACleanup();
	return EXIT_FAILURE;
}