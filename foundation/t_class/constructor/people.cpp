#include "people.h"

using std::cout;
using std::endl;

People::People() {
	name = "";
	age = 0;
	cout << "[自定义] 无参构造 1" << endl;
}

//People::People(string name, int age) {
//	this->name = name;
//	this->age = age;
//	cout << "[自定义] 有参构造 1" << endl;
//}

//People::People():name(),age() {
//	cout << "[自定义] 无参构造 2" << endl;
//}
//
People::People(string name, int age):name(name), age(age){
	cout << "[自定义] 有参构造 2" << endl;
}


void t_constructor()
{
	//noParameterConstructor();
	hasParameterConstructor();
}

void noParameterConstructor() {
	People p1; // 无参构造
	People p2 = People(); // 无参构造
	People* p3 = new People; // 无参构造
	People* p4 = new People(); // 无参构造
}

void hasParameterConstructor() {
	People p1("仔仔", 22); // 有参构造
	p1.print();
	People p2 = People("仔仔", 22); // 有参构造
	p2.print();
	People* p3 = new People("仔仔", 22); // 有参构造
	p3->print();
}