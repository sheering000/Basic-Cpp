// 引用类型
// 引用在内部是用指针来实现的
#include <iostream>
#include <string>

std::string func(){
    return "Hello World";
}

int main(){
    int a = 100;
    int &b = a;

    std::cout << "b=" << b << '\n';
    // 修改a，b的值也会变
    a = 200;
    std::cout << "b=" << b << '\n';

    // a和b的地址相同
    std::cout << "Address a = " << &a << '\n';
    std::cout << "Address b = " << &b << '\n';

    // 引用必须初始化，且没有空引用
    // int &c; 报错

    // 引用不能更改，相当于指针常量
    int c = 300;
    // &b = &c; 报错

    // 左值引用和右值引用
    // 左值：可以被修改的值
    // 右值：不能被修改的值，如函数返回值，临时变量，字面量等

    // 绑定到左值的引用为左值引用
    int &d = a;
    // 绑定到右值的引用为右值引用
    int &&e = 100;

    std::cout << "Address e = " << &e << '\n';

    std::string &&str = func();
    std::cout << str << '\n';

    system("pause");
    return 0;
}