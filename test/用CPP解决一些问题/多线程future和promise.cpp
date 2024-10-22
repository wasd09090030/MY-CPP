#include <iostream>
#include <thread>
#include <future>

// 任务函数，异步计算结果
void async_task(std::promise<int>&& promiseObj, int x) {
    std::this_thread::sleep_for(std::chrono::seconds(2));  // 模拟耗时操作
    int result = x * x;
    promiseObj.set_value(result);  // 将结果传递给 future
}

int main() {
    // 创建 promise 对象
    std::promise<int> promiseObj;

    // 获取 future 对象
    std::future<int> futureObj = promiseObj.get_future();

    // 启动线程，异步执行任务
    std::thread t(async_task, std::move(promiseObj), 10);

    std::cout << "Waiting for result from async task..." << std::endl;

    // 获取异步任务的结果
    int result = futureObj.get();  // 阻塞，直到结果可用

    std::cout << "Async task result: " << result << std::endl;

    t.join();  // 等待线程结束

    return 0;
}
