#include "main.h"
#include <limits>

using namespace std;

int main()
{
	tInt();
	tUnsignedInt();
	tSignedInt();
	return 0;
}


void tInt() {
	cout << "" << endl;
	cout << "数据类型：int, 等价于signed int " << endl;
	cout << "int 占用字节数：" << sizeof(int) << endl;
	cout << "int 类型的最小值为：" << numeric_limits<int>::min() << endl;
	cout << "int 类型的最大值为：" << numeric_limits<int>::max() << endl;
}

void tUnsignedInt() {
	cout << "" << endl;
	cout << "数据类型：unsigned int" << endl;
	cout << "unsigned int 占用字节数：" << sizeof(unsigned int) << endl;
	cout << "unsigned int 类型的最小值为：" << numeric_limits<unsigned int>::min() << endl;
	cout << "unsigned int 类型的最大值为：" << numeric_limits<unsigned int>::max() << endl;
}

void tSignedInt() {
	cout << "" << endl;
	cout << "数据类型：signed int" << endl;
	cout << "signed int 占用字节数：" << sizeof(signed int) << endl;
	cout << "signed int 类型的最小值为：" << numeric_limits<signed int>::min() << endl;
	cout << "signed int 类型的最大值为：" << numeric_limits<signed int>::max() << endl;
}