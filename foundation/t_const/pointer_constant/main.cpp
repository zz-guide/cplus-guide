#include "main.h"

using namespace std;

int main()
{
    int a = 5;
    int* const p = &a; // 先定义变量，再使用const修饰，然后再定义指针，意味指针常量
    *p = 20;     //right 可以修改所指向变量的值

    int b = 10;
    //p = &b;      //error 不可以指向别的变量


    return 0;
}