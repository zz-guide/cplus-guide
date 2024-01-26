#include "main.h"

using namespace std;

int main()
{
    int a = 5;
    const int* p = &a; // 先定义指针，再加const修饰，意味常量指针
    //*p = 20;   //error  不可以通过修改所指向的变量的值

    int b = 20;
    p = &b; //right  指针可以指向别的变量


    return 0;
}