#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <string.h>

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
	// 假设只能接收一个客户端链接
	socketAccept = accept(socketSrv, (sockaddr*)&acceptAddr, &acceptAddrLen);
	if (socketAccept == INVALID_SOCKET) {
		cout << "accept() failed" << endl;
		return _error();
	}

	cout << "==========================" << endl;
	cout << "accept() success" << endl;

	char buf[20] = { 0 };
	inet_ntop(AF_INET, &acceptAddr.sin_addr, buf, sizeof(buf));
	cout << "新客户端加入, IP:" << buf << endl;

	// 5. 接收客户端发来的信息
	char recvMsg[1024] = {};
	while (1) {
		int recvLen = recv(socketAccept, recvMsg, sizeof(recvMsg), 0);
		if (recvLen <= 0) {
			cout << "接收消息失败" << endl;
			break;
		}

		cout << "客户端发送:" << recvMsg << endl;
		if (strcmp(recvMsg, "info") == 0) {
			char sendMsg[1024] = "{\"info\":\"info\"}";
			send(socketAccept, sendMsg, sizeof(sendMsg), 0);
		} else if (strcmp(recvMsg, "name") == 0) {
			char sendMsg[1024] = "{\"name\":\"仔仔\"}";
			send(socketAccept, sendMsg, sizeof(sendMsg), 0);
		} else {
			char sendMsg[1024] = "{\"msg\":\"非法\"}";
			send(socketAccept, sendMsg, sizeof(sendMsg), 0);
		}

		strcpy(recvMsg, "");
	}

	closesocket(socketSrv);
	WSACleanup();
	return EXIT_SUCCESS;
}

int _error() {
	WSACleanup();
	return EXIT_FAILURE;
}