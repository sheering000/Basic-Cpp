// const修饰符
#include <iostream>

int i4 = 4;
int GetSize(){return 1;}

int main(){
    // 常量指针 指向的值不可变
    const double PI = 3.14;
    // double *p = &PI; 报错，不能用非常量指针指向常量
    const double *p = &PI;
    double PI2 = 3.14;
    const double *p2 = &PI2; // 常量指针可以指向非常量
    PI2 = 3.7; // 可以绕过常量指针修改其指向的值

    // 指针常量 指针指向的地址不可变
    double* const p3 = &PI2;
    // p3 = p2; 修改指针的指向，报错

    // double* const ptr = &PI; 报错，不能用指针常量指向常量
    const double* const ptr = &PI; // 正确，既不能修改指针指向，也不能修改指针指向的值


    // 常量表达式，编译期计算
    const int a = 10; // 左右都是不可修改的常量
    const int b = a + 1; // 右边是常量表达式，左边是常量
    // 非常量表达式，运行时计算
    int c = 10; // 左边非常量
    const int int_size = sizeof(int); // 右边需要计算才能得出结果

    constexpr int i1 = 10; // 声明为常量表达式，编译期计算
    // constexpr int i2 = GetSize(); GetSize()是非常量表达式，运行时计算，编译时报错

    constexpr int *ptr2 = nullptr; // 等价于 int *const ptr2 = nullptr;
    int i3 = 10;
    // constexpr int *ptr3 = &i3; // 报错，因为i3定义在栈中，无固定地址
    constexpr int *ptr4 = &i4; // 正确，i4定义在堆中，有固定地址
}