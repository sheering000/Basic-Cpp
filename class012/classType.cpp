// 类基础
#include <iostream>
#include <cstring>

class MyString{
private:
    char* data;

public:
    // 默认构造函数
    MyString():data(nullptr){}

    // 有参构造函数
    MyString(const char* str){
        if(str){
            data = new char[strlen(str)+1]; // +1为了储存'\0'
            strcpy(data,str);
        }else{
            data = nullptr;
        }
    }

    // 深拷贝构造函数
    MyString(const MyString& other){
        if(other.data){
            data = new char[strlen(other.data)+1];
            strcpy(data,other.data);
        }else{
            data = nullptr;
        }
    }

    // 移动构造
    MyString(MyString&& other) noexcept{
        if(other.data){
            data = new char[strlen(other.data)+1];
            std::copy(other.data,other.data+strlen(other.data),data);
            std::cout << "Move constructor called.\n";
        }
        other.data = nullptr;
    }

    // 赋值运算符重载
    MyString& operator=(const MyString& other){
        // 避免自赋值，防止循环
        if(this!=&other){
            delete[] data;
            if(other.data){
                data = new char[strlen(other.data)+1];
                strcpy(data,other.data);
            }else{
                data = nullptr;
            }
        }
        return *this;
    }

    // 移动赋值运算
    MyString& operator=(MyString&& other){
        if(this==&other) return *this;
        std::cout << "Move Assignment called.\n";
        delete[] data;
        if(other.data){
            data = new char[strlen(other.data)+1];
            strcpy(data,other.data);
            other.data = nullptr;
        }else{
            data = nullptr;
        }
        return *this;
    }

    // 比较运算符重载
    bool operator==(const MyString& other){
        if(data==nullptr&&other.data==nullptr) return true;
        if(data==nullptr||other.data==nullptr) return false;
        return strcmp(data,other.data)==0;
    }

    // 输出运算符重载
    // 利用友元函数方式
    friend std::ostream& operator<<(std::ostream& os,const MyString& str){
        if(str.data){
            os<<str.data;
        }
        return os;
    }// 友元函数重载时，不能直接使用this.data

    // 析构函数
    ~MyString(){
        delete[] data;  // 堆区内存手动释放
    }
};


class MyClass2{
public:
    int data;
public:
    // 使用默认构造函数
    MyClass2() = default;
    
    MyClass2(int x):data(x){}

    // 禁用拷贝构造
    MyClass2(const MyClass2& other) = delete;

    // 移动构造
    MyClass2(MyClass2&& other) noexcept:data(std::move(other.data)){
        std::cout << "Move constructor called." << std::endl;
    }
};


int main() {
    MyString str1("Hello, World!");
    MyString str2 = str1; // 拷贝构造
    MyString str3;

    str3 = str1; // 赋值运算符重载

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "str3: " << str3 << std::endl;

    if (str1 == str2) {
        std::cout << "str1 and str2 are equal." << std::endl;
    } else {
        std::cout << "str1 and str2 are not equal." << std::endl;
    }

    // 调用移动构造
    MyClass2 obj1(1);
    MyClass2 obj2 = std::move(obj1);
    std::cout << obj1.data << std::endl;

    // 调用被禁用的拷贝函数
    // MyClass2 obj3 = obj2;
    // 无法引用 函数 "MyClass2::MyClass2(const MyClass2 &other)"-- 它是已删除的函数

    return 0;
}