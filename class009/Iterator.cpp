// 迭代器
#include <iostream>
#include <vector>
#include <string>

int main(){
    {
        std::vector<int> vec = {1,2,3};
        auto iter_begin = vec.begin();
        std::vector<int>::iterator iter_end = vec.end(); // 尾后迭代器，指向容器尾部元素的下一位
        std::cout << *iter_end << '\n'; // 未知数字，越界
    }

    {
        std::string s("hello world");
        auto iter_begin = s.begin();
        *iter_begin = toupper(*iter_begin);
        std::cout << s << '\n';
    }

    {
        std::vector<int> vec = {1,2,3};
        std::vector<int>::const_iterator it = vec.begin(); // 指向常量的迭代器,指向的值不能修改
        it++; // 可以移动
        // *it = 4; // 报错
    }

    {
        // 定义一个只读迭代器
        std::vector<int>::const_iterator iter;
        std::vector<int> vec = {1,2,3};
        // cbegin(),cend(),返回常量迭代器
        for(iter=vec.cbegin();iter!=vec.cend();++iter){
            std::cout << *iter << ' ';
        }std::cout << '\n';

        const std::vector<int> vec2 = {1,2,3};
        // const声明的容器，begin()直接返回常量迭代器
        std::vector<int>::const_iterator it = vec2.begin();
        // std::vector<int>::iterator it2 = vec2.begin(); 报错，必须用const_iterator
    }

    // {
    //     std::vector<int> vec = {1,2,3};
    //     // 范围循环中对容器扩容，会导致迭代器失效
    //     for(auto it=vec.begin();it!=vec.end();++it){
    //         if(*it==2) vec.push_back(*it+2);
    //         // 输出的值为随机
    //         std::cout << *it << '\n';
    //     }
    // }

    {
        // 删除数组中的奇数
        std::vector<int> vec = {1,2,3,4,5};
        auto iter = vec.begin();
        while(iter!=vec.end()){
            if(*iter%2){
                iter = vec.erase(iter); // 直接将迭代器传入erase,并返回被删除值的下一个位置
            }else{
                ++iter;
            }
        }
        for(iter=vec.begin();iter!=vec.end();++iter){
            std::cout << *iter << ' ';
        }
        std::cout << '\n';
    }
    
    return 0;
}