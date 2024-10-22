#include <iostream>
#include <thread>
#include <mutex>

std::once_flag flag;

void initialize() {
    std::cout << "Resource initialized." << std::endl;
}

void thread_func() {
    std::call_once(flag, initialize);
    std::cout << "Thread executed." << std::endl;
}

int main() {
    std::thread t1(thread_func);
    std::thread t2(thread_func);
    std::thread t3(thread_func);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}

//在上述代码中，无论多少个线程调用thread_func，initialize函数只会执行一次