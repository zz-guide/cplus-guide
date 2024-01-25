#pragma once

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Person {
public:
	mutable string name = "";
	mutable int age = 0;

	void updatePerson(string name, int age) const {
		this->name = name;
		this->age = 22;
		this->print(); // 无法调用普通函数
	}

	void print() const {
		cout << "姓名:" << name << endl;
		cout << "年龄:" << age << endl;
	}
};