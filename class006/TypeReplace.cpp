// 类型推导和替换
#include <iostream>

typedef double wage; // wage定义为double
typedef wage wage2,*p; // wage2定义为double p定义为double*
#define ll long long // 用long long将ll替换
using int64_t = long long; // int64_t定义为long long

typedef char *pstring;

int main(){
    const pstring str = "hello world"; // 这是一个指针常量，指向不能修改
    // const pstring == pstring const == char * const
    // str++; 报错

    // auto类型推导
    int age1 = 10;
    int age2 = 20;
    auto age_add = age1 + age2; // age_add的类型为int

    // auto sz = 0,PI = 3.14; // sz的类型为int PI的类型为double，报错
    const int i = 0;
    auto b = i; // auto忽略掉顶层const
    const auto c = i; // const int型

    const int *ptr = nullptr;
    auto ptr2 = ptr; // 底层const不会被忽略

    // decltype类型推导
    int age3 = 10;
    auto age4 = age3; // age4的类型为int
    decltype(age3) age5 = age4; // age5的类型为int
    // decltype(f()) a = b; // a的类型为f()的返回值类型，此时并不实际调用f()
    const int i2 = 0;
    decltype(i2) b2 = 0; // decltype不会忽略顶层const
    int i3=0,*ptr3=&i3;
    decltype(ptr3) ptr4; // ptr4的类型为int*
    decltype(*ptr3) i4 = i3; // i4的类型为int&，必须赋初值
    decltype((i3)) i5 = i3; // i5的类型为int&，必须赋初值
}