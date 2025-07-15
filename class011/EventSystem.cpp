// 实现一个简易的事件系统，允许注册和触发回调函数
#include <iostream>
#include <vector>
#include <functional>

// 定义带参数的回调函数类型
using Callback = std::function<void(int)>;

// 事件系统类
class EventSystem{
private:
    std::vector<Callback> callbacks;

public:
    // 注册回调函数
    void registerCallback(const Callback& cb){
        callbacks.push_back(cb);
    }

    // 触发事件，传递参数给回调函数
    void triggerEvent(int data){
        std::cout << "Event triggered with data=" << data << ".Executing callbacks...\n";
        for(auto &cb:callbacks){
            cb(data);
        }
    }
};

// 示例函数作为回调
void onEvent(int data){
    std::cout << "Function callback received data: " << data << '\n';
}

int main(){
    EventSystem eventSystem;
    // 注册基于函数指针的回调
    eventSystem.registerCallback(onEvent);
    // 注册基于lambda表达式的回调
    eventSystem.registerCallback([](int x){
        std::cout << "Lambda callback received:" << x*2 << '\n';
    });
    // 注册带捕获的Lambda表达式的回调
    int multiplier = 5;
    eventSystem.registerCallback([multiplier](int x){
        std::cout << "Lambda with capture received:" << x*multiplier << '\n';
    });

    // 传递参数，触发事件
    eventSystem.triggerEvent(5);

    return 0;
}