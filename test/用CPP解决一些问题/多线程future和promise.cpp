#include <iostream>
#include <thread>
#include <future>

// ���������첽������
void async_task(std::promise<int>&& promiseObj, int x) {
    std::this_thread::sleep_for(std::chrono::seconds(2));  // ģ���ʱ����
    int result = x * x;
    promiseObj.set_value(result);  // ��������ݸ� future
}

int main() {
    // ���� promise ����
    std::promise<int> promiseObj;

    // ��ȡ future ����
    std::future<int> futureObj = promiseObj.get_future();

    // �����̣߳��첽ִ������
    std::thread t(async_task, std::move(promiseObj), 10);

    std::cout << "Waiting for result from async task..." << std::endl;

    // ��ȡ�첽����Ľ��
    int result = futureObj.get();  // ������ֱ���������

    std::cout << "Async task result: " << result << std::endl;

    t.join();  // �ȴ��߳̽���

    return 0;
}
