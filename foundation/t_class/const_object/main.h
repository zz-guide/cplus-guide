#pragma once

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Person {
public:
	string name;
	int age;
	Person(string name, int age);
	void print() const {
		cout << "姓名:" << name << endl;
		cout << "年龄:" << age << endl;
	}

	void print2() {
		cout << "姓名:" << this->name << endl;
		cout << "年龄:" << this->age << endl;
	}
};