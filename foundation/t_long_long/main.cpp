#include "main.h"
#include <limits>

using namespace std;

int main()
{
	tLong();
	tUnsignedLong();
	tSignedLong();
	return 0;
}


void tLong() {
	cout << "" << endl;
	cout << "数据类型：long, 等价于signed long " << endl;
	cout << "long 占用字节数：" << sizeof(long) << endl;
	cout << "long 类型的最小值为：" << numeric_limits<long>::min() << endl;
	cout << "long 类型的最大值为：" << numeric_limits<long>::max() << endl;
}

void tUnsignedLong() {
	cout << "" << endl;
	cout << "数据类型：unsigned long" << endl;
	cout << "unsigned long 占用字节数：" << sizeof(unsigned long) << endl;
	cout << "unsigned long 类型的最小值为：" << numeric_limits<unsigned long>::min() << endl;
	cout << "unsigned long 类型的最大值为：" << numeric_limits<unsigned long>::max() << endl;
}

void tSignedLong() {
	cout << "" << endl;
	cout << "数据类型：signed long" << endl;
	cout << "signed long 占用字节数：" << sizeof(signed long) << endl;
	cout << "signed long 类型的最小值为：" << numeric_limits<signed long>::min() << endl;
	cout << "signed long 类型的最大值为：" << numeric_limits<signed long>::max() << endl;
}