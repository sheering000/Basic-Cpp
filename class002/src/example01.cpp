// 源文件.cpp 实现对应头文件中的声明
#include "..\inc\example01.h"
#include <iostream>

// 实现函数
MyClass1::MyClass1(){
    std::cout << "MyClass对象被构造！" << '\n';
}

void MyClass1::func(){
    std::cout << "MyClass对象的成员函数 func() 被调用！" << '\n';
}