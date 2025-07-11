// vector类
#include <iostream>
#include <vector>

void example1(){
    std::vector<int> vec1 = {1,2,3,4,5};
    for(auto it = vec1.begin();it!=vec1.end();++it){
        std::cout << *it << " ";
    }
    std::cout << '\n';

    std::vector<int> vec2(std::move(vec1)); // 移动vec1到vec2
    for(auto it = vec2.begin();it!=vec2.end();++it){
        std::cout << *it << " ";
    }
    std::cout << '\n';

    // std::cout << vec1[0] << '\n'; 报错，此时vec1已经被析构
}

void example2(){
    std::vector<int> vec = {1,2};
    std::cout << "vec capacity:" << vec.capacity() << '\n';
    vec.clear();
    std::cout << "After clear,vec capacity:" << vec.capacity() << '\n';

    {
        // 利用块的内存回收机制，回收vec的内存
        std::vector<int> empty_vec;
        empty_vec.swap(vec);
        std::cout << "After swap,vec capacity:" << vec.capacity() << '\n';
        std::cout << "After swap,empty_vec capacity:" << empty_vec.capacity() << '\n';
    }
    std::cout << "After swap,vec capacity:" << vec.capacity() << '\n';
}

int main(){
    // example1();
    example2();
    return 0;
}