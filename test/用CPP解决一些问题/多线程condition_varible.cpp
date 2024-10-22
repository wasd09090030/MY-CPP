#include <iostream>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> product;

void producer(int id) {
    for (int i = 0; i < 5; ++i) {
        std::unique_lock<std::mutex> lck(mtx);//锁住
        product.push(id * 100 + i);
        std::cout << "Producer " << id << " produced " << product.back() << std::endl;
        cv.notify_one();//唤醒wait()的线程
        lck.unlock();//解锁
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer(int id) {
    while (true) {
        std::unique_lock<std::mutex> lck(mtx);//锁住

        //消费者线程在等待条件变量 cv，直到 product 队列不为空
        cv.wait(lck, [] { return !product.empty(); });
        if (!product.empty()) {
            int prod = product.front();
            product.pop();
            std::cout << "Consumer " << id << " consumed " << prod << std::endl;
        }
        lck.unlock();
    }
}

int main() {
    std::thread producers[2];
    std::thread consumers[2];

    for (int i = 0; i < 2; ++i) {
        producers[i] = std::thread(producer, i + 1);
    }

    for (int i = 0; i < 2; ++i) {
        consumers[i] = std::thread(consumer, i + 1);
    }

    for (int i = 0; i < 2; ++i) {
        producers[i].join();
        consumers[i].join();
    }

    return 0;
}