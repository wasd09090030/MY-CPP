#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> counter(0);  // ԭ�ӱ���

void increment() {
    for (int i = 0; i < 1000; ++i) {
        counter++;  // ԭ�Ӳ���������
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
/*std::atomic<int> counter(0)��������һ��ԭ�ӱ��� counter����ʼֵΪ 0����������������߳�֮�䰲ȫ�ع���
counter++����ԭ�ӱ���������������������һ�������жϵ�ԭ�Ӳ�������ʹ�ж���߳�ͬʱ�������в�����Ҳ����������ݾ�����*/