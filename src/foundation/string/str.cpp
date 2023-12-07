//
// Created by xuLei on 2022/11/24.
//
#include <iostream>

using namespace std;

#include "str.h"


void testString() {
    string s = "你好世界";
    cout << "字符串:" << s << endl;
    // 转义字符串
    string s1 = "你好世界\n 哈哈";
    cout << "转义字符串:" << s1 << endl;
    // 原生字符串， R"aa()aa", aa标签用来提供代码可读性，并不是字符串的一部分
    string s2 = R"aa(你好世界\n 哈哈)aa";
    cout << "原生字符串:" << s2 << endl;
    // 多行字符串,连接多行字符串,或者使用原生字符串
    string s3 = "你好世界 \
    阿斯利康的骄傲了圣诞节了 \
    爱上来得及阿拉萨的记录可 \
    哈哈";
    cout << "多行字符串:" << s3 << endl;
}