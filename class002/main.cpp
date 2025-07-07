#include ".\inc\example01.h"
#include <iostream>
#include ".\inc\example02.hpp"
// 由于tasks.json中未配置，无法链接成功
// 解决方法：1.在tasks.json中配置includePath 2.使用cmake配置工程文件
// 3.直接使用g++编译

int main(){
    system("chcp 65001");
    MyClass1 obj1;
    obj1.func();

    std::cout << "example2 age: " << age << '\n';
    std::cout << "example2 name: " << name << '\n';

    
    // system("pause");
    return 0;
}