// 认识变量和输出
#include <iostream>
// 格式化输出
#include <iomanip>

int main(){
    // 声明一个内存，未初始化
    int age; // 栈上声明，随机分配一个值；堆上声明，分配为0；
    // 声明并初始化一个变量
    int height = 100;

    // 输出运算符：std::cout
    std::cout << height << '\n';

    double PI = 3.14159265;

    // 使用std::setw设置输出宽度
    std::cout << std::setw(2) << PI << '\n';
    // 使用std::setprecision设置输出精度
    std::cout << std::setprecision(2) << PI << '\n';
    
    
    // 内置类型转换
    char a = 100; // 100是int类型，转换为char类型，int是4字节，char是1字节，如果数字过大会损失精度
    int b = a; // 100是char类型，转换为int类型，char是1字节，int是4字节，不会损失精度
    double c = b; // int类型转换为double

    std::cout << "a=" << static_cast<int>(a) << '\n'; // 强制将a转换成int类型输出
    std::cout << "b=" << b << '\n';
    std::cout << "c=" << c << '\n';

    // 下面的转换可能会导致数据丢失
    unsigned int d = -1; // int转换为unsigned int类型，导致数据丢失
    std::cout << "d=" << d << '\n'; // 输出一个很大的数


    // 变量大小
    std::cout << "char size=" << sizeof(char) << '\n';
    std::cout << "int size=" << sizeof(int) << '\n';
    std::cout << "short size=" << sizeof(short) << '\n';
    std::cout << "long size=" << sizeof(long) << '\n';
    std::cout << "long long size=" << sizeof(long long) << '\n';
    std::cout << "float size=" << sizeof(float) << '\n';
    std::cout << "double size=" << sizeof(double) << '\n';

    
    system("pause");
    return 0;
}