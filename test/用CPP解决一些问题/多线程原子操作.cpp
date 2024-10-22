#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> counter(0);  // 原子变量

void increment() {
    for (int i = 0; i < 1000; ++i) {
        counter++;  // 原子操作，自增
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter << std::endl;

    return 0;
}
/*std::atomic<int> counter(0)：定义了一个原子变量 counter，初始值为 0。这个变量可以在线程之间安全地共享。
counter++：对原子变量进行自增操作，这是一个不可中断的原子操作，即使有多个线程同时对它进行操作，也不会出现数据竞争。*/