//
// Created by xulei on 2022/11/24.
//
#include <iostream>
using namespace std;


void testInt()
{
    // int 类型
    int a = 123;
    cout << "整型" << a << endl;
}

void testBool()
{
    bool a = true;
    bool b = false;
    cout << "sizeof(bool)=" << sizeof(bool) << endl;
    cout << "a=" << a << ",b=" << b << endl;

}

void testType()
{
//    testInt();
    testBool();
}
