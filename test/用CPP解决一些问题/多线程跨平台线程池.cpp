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
    ThreadPool(size_t numThreads);  // ���캯������ʼ���̳߳�
    ~ThreadPool();  // ���������������̳߳�

    // ���̳߳��ύ���񣬷���һ�� std::future �����Ի�ȡ����ķ���ֵ
    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>;

private:
    // �����̵߳�ѭ������
    void worker();

    // �̳߳��е��߳�
    std::vector<std::thread> workers;

    // �������
    std::queue<std::function<void()>> tasks;

    // ͬ������
    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;  // ���ڿ����̳߳صĹر�
};

// ���캯�������� numThreads ���߳�
ThreadPool::ThreadPool(size_t numThreads) : stop(false) {
    for (size_t i = 0; i < numThreads; ++i) {
        workers.emplace_back([this] { this->worker(); });
    }
}

// �����������ر��̳߳�
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

// ���̳߳��ύ����
template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type> {
    using return_type = typename std::result_of<F(Args...)>::type;

    // �������װΪһ�� std::packaged_task ����
    auto task = std::make_shared<std::packaged_task<return_type()>>(
        std::bind(std::forward<F>(f), std::forward<Args>(args)...)
    );

    // ��ȡ����� future ����
    std::future<return_type> result = task->get_future();

    {
        std::unique_lock<std::mutex> lock(queueMutex);

        // ���������̳߳عرպ��ύ������
        if (stop) {
            throw std::runtime_error("enqueue on stopped ThreadPool");
        }

        // ��������ӵ����������
        tasks.emplace([task]() { (*task)(); });
    }

    // ֪ͨһ�������߳���������
    condition.notify_one();

    return result;
}

// �����̵߳�ѭ������
void ThreadPool::worker() {
    while (true) {
        std::function<void()> task;

        {
            std::unique_lock<std::mutex> lock(queueMutex);

            // �ȴ������񣬻��̳߳عر�
            condition.wait(lock, [this] { return stop || !tasks.empty(); });

            // ����̳߳عر���û��ʣ�������˳�ѭ��
            if (stop && tasks.empty()) {
                return;
            }

            // �����������ȡ��һ������
            task = std::move(tasks.front());
            tasks.pop();
        }

        // ִ������
        task();
    }
}

int main() {
    // ����һ������ 4 ���̵߳��̳߳�
    ThreadPool pool(4);

    // �ύ������̳߳�
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

    // ��ȡ������
    for (auto&& result : results) {
        std::cout << "Result: " << result.get() << std::endl;
    }

    return 0;
}
