// 运算符重载
#include <iostream>

struct Student{
    int age;
    Student(){}
    Student(int x):age(x){}
    // 作为成员函数重载
    Student operator+(const Student &c){
        Student ans;
        ans.age = age+c.age;
        return ans;
    }

    // 作为友元函数重载
    friend Student operator-(const Student &c1,const Student &c2);
};

Student operator-(const Student &c1,const Student &c2){
    Student ans;
    ans.age = c1.age-c2.age;
    return ans;
}

int main(){
    Student s1(17),s2(22);
    std::cout << (s1+s2).age << '\n';
    std::cout << (s2-s1).age << '\n';
    return 0;
}