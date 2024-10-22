#include<iostream>
#include<vector>
using namespace std;

class Person {

public:
	int age;

	//构造函数：
	//没有返回值，不用void
	//函数名与类名相同
	//构造函数可以有参数，可以重载、
	//创建对象的时候自动调用一次
	Person() {
		cout << "构造一个类Person" << endl;
	}

	//析构函数调用，程序结束后进行清理
	//析构函数不可有参数，不能够重载
	~Person() {
		
		cout << "析构函数调用" << endl;
	}


	//拷贝函数
	Person(const Person&p) {
		age = p.age;
	}
};

void test() {
     Person();
	 //执行完毕后，自动执行析构函数
}

int main() {

	test();


	return 0;
}