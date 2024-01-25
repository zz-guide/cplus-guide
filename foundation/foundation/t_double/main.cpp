#include "main.h"
#include <limits>

using namespace std;

int main()
{
	tShort();
	tUnsignedShort();
	tSignedShort();
	return 0;
}


void tShort() {
	cout << "" << endl;
	cout << "数据类型：short, 等价于signed short " << endl;
	cout << "short 占用字节数：" << sizeof(short) << endl;
	cout << "short 类型的最小值为：" << numeric_limits<short>::min() << endl;
	cout << "short 类型的最大值为：" << numeric_limits<short>::max() << endl;
}

void tUnsignedShort() {
	cout << "" << endl;
	cout << "数据类型：unsigned short" << endl;
	cout << "unsigned short 占用字节数：" << sizeof(unsigned short) << endl;
	cout << "unsigned short 类型的最小值为：" << numeric_limits<unsigned short>::min() << endl;
	cout << "unsigned short 类型的最大值为：" << numeric_limits<unsigned short>::max() << endl;
}

void tSignedShort() {
	cout << "" << endl;
	cout << "数据类型：signed short" << endl;
	cout << "signed short 占用字节数：" << sizeof(signed short) << endl;
	cout << "signed short 类型的最小值为：" << numeric_limits<signed short>::min() << endl;
	cout << "signed short 类型的最大值为：" << numeric_limits<signed short>::max() << endl;
}