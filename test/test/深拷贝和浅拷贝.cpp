#include<iostream>
#include<vector>
using namespace std;


//浅拷贝可能的问题：堆区的内存重复释放
class Person {

public:
	int Age;
	int* height;

	Person() {
		cout << "构造一个类Person" << endl;
	}

	Person(int age,int H) {

		cout << "构造一个类Person" << endl;
		Age = age;
		height = new int(H);
	}
	
	//拷贝函数
	Person(const Person& p) {
		Age = p.Age;
		//height = p.height; 浅拷贝操作，本质上内存地址不变，只是复制了一遍
		height = new int(*p.height);//深拷贝，重新申请一块内存
	}

	~Person() {
		//将堆区开辟的数据进行释放操作
		//进行浅拷贝函数时，同一块内存会释放两次然后报错
		if (height != nullptr) {
			delete height;
			height = nullptr;
		}
		cout << "析构代码调用" << endl;

	}
};

void test() {
	Person p2(18,160);
	Person p3(p2);
	
	//执行完毕后，自动执行析构函数
}

int main() {

	test();


	return 0;
}