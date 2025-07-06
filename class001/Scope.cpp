// 变量作用域
#include <iostream>
// using namespace std; 使用命名空间可以省略std

// 全局变量，具有全局作用域
int globalvar = 10;

void test01(){
    std::cout << "globalvar = " << globalvar << '\n';
}

// 局部变量，具有局部作用域
void test02(){
    int localvar = 20;
    std::cout << "localvar = " << localvar << '\n';
}

// 定义一个命名空间
namespace Mynamespace{
    // 命名空间中的变量，具有命名空间作用域
    int namespacevar = 30;
    void test03(){
        std::cout << "namespacevar = " << namespacevar << '\n';
    }
}

// 类作用域
class MyClass{
public:
    // 成员变量，具有类作用域
    int classvar = 40;

    // 成员函数，也可以访问类作用域内的成员变量
    void test04(){
        std::cout << "classvar = " << classvar << '\n';
    }
};

// 块作用域--局部作用域的一种特例
void func(){
    {
        int blockvar = 50;
        std::cout << "blockvar = " << blockvar << '\n';
    }
    // blockvar在这里之后不可见
    // std::cout << "blockvar = " << blockvar << '\n'; // 错误
}

int main(){
    // 访问全局变量
    std::cout << "globalvar = " << globalvar << '\n';
    test01();

    // 访问局部变量
    test02();
    // localvar在这里之后不可见

    // 使用命名空间中的变量
    std::cout << "Mynamespace::namespacevar = " << Mynamespace::namespacevar << '\n';
    // 使用命名空间中的函数
    Mynamespace::test03();

    // 使用类中的成员变量
    MyClass myclass;
    std::cout << "myclass.classvar = " << myclass.classvar << '\n';
    // 使用类中的成员函数
    myclass.test04();

    // 使用块作用域
    func();

    system("pause");
    return 0;
}