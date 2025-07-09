// 结构体类型
#include <iostream>
#include <string>

// 结构体与类用法基本相同
struct Student{
// public: // 结构体默认成员变量为共有
    std::string name;
    int age;
    double score;

    // 结构体中可以定义成员函数
    void setId(int id){
        this->id = id;
    }
private: // 可以定义为私有
    int id;
};

struct Class{
    int id;
    int grade;
};

typedef struct{
    int id;
    std::string name;
} StudentType; // StudentType定义为结构体

using StudentType2 = struct{
    int id;
    std::string name;
}; // StudentType2定义为结构体

int main(){
    // 无成员函数，且无私有成员变量的结构体，可用花括号直接赋初值
    Class c1 = {1,2};

    Student s1;
    s1.age = 18;
    s1.name = "张三";
    s1.score = 100.0;
    s1.setId(1);

    StudentType s2 = {2, "李四"};

    StudentType2 s3 = {3, "王五"};

    system("pause");
    return 0;
}