#include<iostream>
#include<vector>
using namespace std;

class Person {
public:
	int ma;
	mutable int mb; //mutable 关键字
	//this指针本质是指针常量，指针的指向不可修改
	//成员函数后面加上const，修饰了this指向，让指针指向的值也不可修改
	void showPerson() const {
		this.ma = 10;//不允许修改
		 mb = 19;//加上关键字后可以修改
	}

	void ssh(){}
};



int main() {

	const Person pp;//常对象，常对象只能调用常函数
	pp.showPerson();
	pp.ssh();

}