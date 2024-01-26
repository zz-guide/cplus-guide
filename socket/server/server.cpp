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

	// 服务端建立socket服务 --------------------------------------------------
	int port = 15000;
	// 1. socket()
	SOCKET socketSrv = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN serverAddr = {};
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port); // 1024以上的端口号，此处需要转端序
	serverAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY); // 表示0.0.0.0，或者inet_addr("127.0.0.1")

	// 2. bind()
	int bindRes = bind(socketSrv, (sockaddr*)&serverAddr, sizeof(serverAddr));
	if (bindRes == SOCKET_ERROR) {
		cout << "bind() failed" << WSAGetLastError() << endl;
		return _error();
	}
	else {
		cout << "bind() success" << endl;
	}

	// 3. listen()
	int listenRes = listen(socketSrv, SOMAXCONN);
	if (listenRes == SOCKET_ERROR) {
		cout << "listen() failed:" << WSAGetLastError() << endl;
		return _error();
	}

	// 4. accept()
	
	SOCKADDR_IN acceptAddr = {};
	int acceptAddrLen = sizeof(acceptAddr);
	SOCKET socketAccept = INVALID_SOCKET;
	// 同步处理客户端链接，并返回信息
	while (1) {
		socketAccept = accept(socketSrv, (sockaddr*)&acceptAddr, &acceptAddrLen);
		if (socketAccept == INVALID_SOCKET) {
			cout << "accept() failed" << endl;
			continue;
		}

		cout << "==========================" << endl;
		cout << "accept() success" << endl;
		
		char buf[20] = { 0 };
		inet_ntop(AF_INET, &acceptAddr.sin_addr, buf, sizeof(buf));

		cout << "新客户端加入, IP:" << buf << endl;

		// 5. 向客户端发送一条信息
		const char msg[128] = "hello client";
		send(socketAccept, msg, sizeof(msg), 0);
	}
	
	closesocket(socketSrv);
	WSACleanup();
	return 0;
}

int _error() {
	WSACleanup();
	return EXIT_FAILURE;
}