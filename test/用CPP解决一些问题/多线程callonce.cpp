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

//�����������У����۶��ٸ��̵߳���thread_func��initialize����ֻ��ִ��һ��