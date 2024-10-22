#include <iostream>
#include <future>
#include <thread>
#include <chrono>

int async_task(int x) {
    std::this_thread::sleep_for(std::chrono::seconds(2));  // ģ���ʱ����
    return x * x;
}

int main() {
    std::cout << "Starting async task..." << std::endl;

    // ʹ�� std::async �����첽����
    std::future<int> result = std::async(std::launch::async, async_task, 10);// �����ں�̨�첽ִ��

    std::cout << "Doing other work while async task is running..." << std::endl;
    std::cout << "��һ���߳�  " << async_task(8) << std::endl;//���߳���async�߳��첽ͬʱ����
    // ��ȡ�첽����Ľ��
    int value = result.get();  // ������ֱ���첽�������
    std::cout << "��һ���߳�  " << async_task(9) << std::endl;
    std::cout << "Async task result: " << value << std::endl;
    

    return 0;
}
