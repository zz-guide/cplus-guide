#include "main.h"

using namespace std;

int main()
{
    // const 修饰变量
    int const a = 100;
    //const int a = 100; //与上面等价

    cout << "a=" << a << endl;
    //a = 200; // 不能给常量赋值
    cout << "a=" << a << endl;

    return 0;
}