#pragma once

#include <iostream>

using std::string;
using std::cout;
using std::endl;

void noParameterConstructor();
void hasParameterConstructor();
void t_constructor();




class People {
public:
	string name;
	int age;

	People();
	People(string name, int age);
	void print() const {
		cout << "姓名:" << name << endl;
		cout << "年龄:" << age << endl;
	}
};