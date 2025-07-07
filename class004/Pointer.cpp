// 指针
#include <iostream>

int main(){
    void *p; // 万能指针
    double PI = 3.14;
    p = &PI;
    // 解引用时需要强制类型转换
    std::cout << *(double *)p << '\n';

    // 引用不是一个对象，不存在指向引用的指针
    // 存在指向指针的引用
    int init = 42;
    int *pinit = nullptr;
    int *&rinit = pinit; // 指向指针的引用
    pinit = &init;
    std::cout << "init:" << init << '\n';
    std::cout << "pinit:" << *pinit << '\n';
    std::cout << "rinit:" << *rinit << '\n';

    // 指针的解引用必须保证不是空指针
    int *p1 = nullptr;
    std::cout << *p1 << '\n'; // 报错

    system("pause");
    return 0;
}