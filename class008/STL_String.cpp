// string类
#include <iostream>
#include <string>

void example1(){
    std::string str1; // 默认构造函数，空字符串
    std::string str2 = "Hello World"; // 使用字面值初始化字符串
    std::string str3 = str2; // 使用拷贝构造函数进行复制
    std::string str4(str3); // 使用拷贝构造函数进行复制
    std::string str5(5,'a'); // str5 = "aaaaa"
    std::string str6(str5.begin(),str5.end()); // str6 = "aaaaa"
    std::string str7(str2,1,4); // str7 = "ello"

    std::cout << "str1:" << str1 << '\n'
            << "str2:" << str2 << '\n'
            << "str3:" << str3 << '\n'
            << "str4:" << str4 << '\n'
            << "str5:" << str5 << '\n'
            << "str6:" << str6 << '\n'
            << "str7:" << str7 << '\n';
}

void example2(){
    std::string str = "Hello World!";
    std::string word = "bye";
    size_t pos = str.find(word); // size_t:无符号整型
    if(pos == std::string::npos){ // 找不到返回npos
        std::cout << "Found " << word << " at position " << pos << '\n';
        std::cout << pos << '\n';
    }

    // 截取 substr(start,end)
    std::string sub = str.substr(7,5);
    std::cout << sub << '\n';
    
}

int main(){
    //example1();
    example2();

    system("pause");
    return 0;
}