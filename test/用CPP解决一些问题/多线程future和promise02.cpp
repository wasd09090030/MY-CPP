#include <iostream>
#include <future>
#include <chrono>

void Thread_Fun1(std::promise<int>& p)
{
	//Ϊ��ͻ��Ч��������ʹ�߳�����5s
	std::this_thread::sleep_for(std::chrono::seconds(5));

	int iVal = 233;
	std::cout << "��������(int)��" << iVal << std::endl;

	//��������iVal
	p.set_value(iVal);
}

void Thread_Fun2(std::future<int>& f)
{
	//����������ֱ���յ��������std::promise�����������
	auto iVal = f.get();		//iVal = 233

	std::cout << "�յ�����(int)��" << iVal << std::endl;
}

int main()
{
	//����һ��std::promise����pr1���䱣���ֵ����Ϊint
	std::promise<int> pr1;
	//����һ��std::future����fu1����ͨ��std::promise��get_future()������pr1��
	std::future<int> fu1 = pr1.get_future();

	//����һ���߳�t1��������Thread_Fun1������pr1�����߳�����ִ��
	std::thread t1(Thread_Fun1, std::ref(pr1));//ʹ��std::ref������ģ�崫�ε�ʱ��������
	//����һ���߳�t2��������Thread_Fun2������fu1�����߳�����ִ��
	std::thread t2(Thread_Fun2, std::ref(fu1));

	//�������߳̽���
	t1.join();
	t2.join();

	return 1;
}