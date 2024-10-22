#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>

class ThreadPool {
public:
    ThreadPool(size_t numThreads);  // 构造函数，初始化线程池
    ~ThreadPool();  // 析构函数，销毁线程池

    // 向线程池提交任务，返回一个 std::future 对象以获取任务的返回值
    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>;

private:
    // 工作线程的循环函数
    void worker();

    // 线程池中的线程
    std::vector<std::thread> workers;

    // 任务队列
    std::queue<std::function<void()>> tasks;

    // 同步机制
    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;  // 用于控制线程池的关闭
};

// 构造函数，启动 numThreads 个线程
ThreadPool::ThreadPool(size_t numThreads) : stop(false) {
    for (size_t i = 0; i < numThreads; ++i) {
        workers.emplace_back([this] { this->worker(); });
    }
}

// 析构函数，关闭线程池
ThreadPool::~ThreadPool() {
    {
        std::unique_lock<std::mutex> lock(queueMutex);
        stop = true;
    }
    condition.notify_all();
    for (std::thread& worker : workers) {
        worker.join();
    }
}

// 向线程池提交任务
template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type> {
    using return_type = typename std::result_of<F(Args...)>::type;

    // 将任务封装为一个 std::packaged_task 对象
    auto task = std::make_shared<std::packaged_task<return_type()>>(
        std::bind(std::forward<F>(f), std::forward<Args>(args)...)
    );

    // 获取任务的 future 对象
    std::future<return_type> result = task->get_future();

    {
        std::unique_lock<std::mutex> lock(queueMutex);

        // 不允许在线程池关闭后提交新任务
        if (stop) {
            throw std::runtime_error("enqueue on stopped ThreadPool");
        }

        // 将任务添加到任务队列中
        tasks.emplace([task]() { (*task)(); });
    }

    // 通知一个工作线程有新任务
    condition.notify_one();

    return result;
}

// 工作线程的循环函数
void ThreadPool::worker() {
    while (true) {
        std::function<void()> task;

        {
            std::unique_lock<std::mutex> lock(queueMutex);

            // 等待新任务，或线程池关闭
            condition.wait(lock, [this] { return stop || !tasks.empty(); });

            // 如果线程池关闭且没有剩余任务，退出循环
            if (stop && tasks.empty()) {
                return;
            }

            // 从任务队列中取出一个任务
            task = std::move(tasks.front());
            tasks.pop();
        }

        // 执行任务
        task();
    }
}

int main() {
    // 创建一个包含 4 个线程的线程池
    ThreadPool pool(4);

    // 提交任务给线程池
    std::vector<std::future<int>> results;

    for (int i = 0; i < 8; ++i) {
        results.emplace_back(
            pool.enqueue([i] {
                std::cout << "Task " << i << " is running in thread " << std::this_thread::get_id() << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                return i * i;
                })
        );
    }

    // 获取任务结果
    for (auto&& result : results) {
        std::cout << "Result: " << result.get() << std::endl;
    }

    return 0;
}
