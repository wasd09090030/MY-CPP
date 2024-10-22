#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int shared_data = 0;

void func() {

	std::lock_guard<std::mutex> mmtx(mtx);

	for (int i = 0; i <= 10000; i++) {
		
		shared_data++;
	}

}


int main() {

	std::thread t1(func);
	std::thread t2(func);
	t1.join();
	t2.join();

	std::cout << shared_data;

	return 0;

}
