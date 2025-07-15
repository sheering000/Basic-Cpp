// 使用lambda表达式
#include <bits/stdc++.h>

int main(){
    std::vector<std::string> fruits = {"apple","banana","kiwi","strawberry","grape","pineapple"};

    // 使用lambda表达式按照字符串长度进行排序
    std::sort(fruits.begin(),fruits.end(),[](const std::string& a,const std::string& b) -> bool{
        return a.length()<b.length();
    });

    std::cout << "Fruits sorted by length:\n";
    for(const auto &fruit:fruits)
        std::cout << fruit << ' ';
    std::cout << '\n';
    
    return 0;
}