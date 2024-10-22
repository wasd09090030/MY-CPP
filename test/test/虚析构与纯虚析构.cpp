#include<iostream>
#include<string>
using namespace std;

class animal {
public:
	animal() {
		cout << "animal构造函数调用" << endl;
	}
	virtual ~animal() {
		cout << "animal析构函数调用" << endl;
	}

	virtual void speak() = 0;

};

class Cat:public animal {
public:

	void speak() { cout <<*mNa<< "小猫说话" << endl; };

	Cat(string nn) {
		mNa = new string(nn);
		cout << "cat构造函数调用" << endl;
	}

	~Cat() {
		if (mNa!=NULL) {
			cout << "猫的析构函数调用" << endl;
			delete mNa;
		}
	}

	string* mNa ;
};

void test() {
	
	animal* aa = new Cat("sa");
	aa->speak();
	delete aa;
	//animal 的析构函数不加virtual
	//就会不调用 cat的析构函数，
	// 导致如果子类有堆区数据，造成内存泄露
};


int main() {
	
	test();
	return 0;
}