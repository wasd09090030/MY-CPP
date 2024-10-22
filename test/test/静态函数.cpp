#include<iostream>

using namespace std;

class Person {
public:
	static int height;
	int age;

	//静态成员函数
	static void function() {

		height = 2000;//静态成员函数可访问静态变量
		age = 0;//不可访问非静态，因为静态成员有全局性，只能有一个，无法分清非静态成员。
		cout << "静态函数可调用" << endl;
	}


private:

	void f2() {
		cout << "调用F2" << endl;
	}
	static void f3() {
		cout << "调用F3" << endl;
	}
};


int main() {

	Person p;
	p.function();
	Person::function();
	Person::f3();//类外访问不了私有的静态函数
}