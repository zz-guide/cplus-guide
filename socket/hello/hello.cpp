#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <windows.h>

#include <iostream>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {

	WORD ver = MAKEWORD(2, 2);
	WSADATA wsadata;
	int res = WSAStartup(ver, &wsadata);
	if (res != 0) {
		cout << "WSAStartup() failed" << endl;
		return EXIT_FAILURE;
	} else{
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

	WSACleanup();
	
	return 0;
}