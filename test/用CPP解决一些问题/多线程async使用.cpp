#include <iostream>
#include <future>
#include <thread>
#include <chrono>

int async_task(int x) {
    std::this_thread::sleep_for(std::chrono::seconds(2));  // 模拟耗时任务
    return x * x;
}

int main() {
    std::cout << "Starting async task..." << std::endl;

    // 使用 std::async 启动异步任务
    std::future<int> result = std::async(std::launch::async, async_task, 10);// 任务在后台异步执行

    std::cout << "Doing other work while async task is running..." << std::endl;
    std::cout << "另一个线程  " << async_task(8) << std::endl;//该线程与async线程异步同时运行
    // 获取异步任务的结果
    int value = result.get();  // 阻塞，直到异步任务完成
    std::cout << "另一个线程  " << async_task(9) << std::endl;
    std::cout << "Async task result: " << value << std::endl;
    

    return 0;
}
