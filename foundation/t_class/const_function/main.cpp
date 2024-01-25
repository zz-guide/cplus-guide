#include "main.h"

using namespace std;

int main()
{
    Person person;
    person.name = "仔仔";
    person.age = 23;
    person.print();

    // 没加const之前是可以修改的，或者加了const, 属性同时增加mutable也能修改
    person.updatePerson("张三", 34);
    person.print();
    return 0;
}