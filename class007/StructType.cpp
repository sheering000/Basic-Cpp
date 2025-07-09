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
private:
    int num;
};

int main(){
    // 无成员函数，且无私有成员变量的结构体，可用花括号直接赋初值
    Class c1;

    Student s1;
    s1.age = 18;
    s1.name = "张三";
    s1.score = 100.0;
    s1.setId(1);

    system("pause");
    return 0;
}