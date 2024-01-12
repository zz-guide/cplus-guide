#include "main.h"
#include <limits>

using namespace std;

int main()
{
	tChar();
	tUnsignedChar();
	tSignedChar();
	return 0;
}


void tChar() {
	cout << "" << endl;
	cout << "数据类型：char, 等价于signed  char " << endl;
	cout << "char 占用字节数：" << sizeof(char) << endl;
	cout << "char 类型的最小值为：" << (int)(numeric_limits<char>::min()) << endl;
	cout << "char 类型的最大值为：" << (int)(numeric_limits<char>::max()) << endl;
}

void tUnsignedChar() {
	cout << "" << endl;
	cout << "数据类型：unsigned char" << endl;
	cout << "unsigned char 占用字节数：" << sizeof(unsigned char) << endl;
	cout << "unsigned char 类型的最小值为：" << (int)(numeric_limits<unsigned char>::min()) << endl;
	cout << "unsigned char 类型的最大值为：" << (int)(numeric_limits<unsigned char>::max()) << endl;
}

void tSignedChar() {
	cout << "" << endl;
	cout << "数据类型：signed char" << endl;
	cout << "signed char 占用字节数：" << sizeof(signed char) << endl;
	cout << "signed char 类型的最小值为：" << (int)(numeric_limits<signed char>::min()) << endl;
	cout << "signed char 类型的最大值为：" << (int)(numeric_limits<signed char>::max()) << endl;
}