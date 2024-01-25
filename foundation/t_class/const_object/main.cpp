#include "main.h"

using namespace std;

Person::Person(string name, int age):name(name),age(age) {}

int main()
{
    const Person person("仔仔", 23);
    person.print(); // 可以调用常函数

    //person.print2(); // 无法调用普通函数
    return 0;
}