// 头文件.hpp
// 声明变量、函数、类

// 第二种预处理指令，防止重复包含
// 非C++标准，但在大多数编译器上都支持
#pragma once
#include <string>

// 声明变量
// extern解决重定义问题
extern int age; // extern int age = 10; 错误，extern不能初始化
extern std::string name;
// 头文件只做变量和函数的声明，不做定义