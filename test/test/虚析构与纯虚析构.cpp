#include<iostream>
#include<string>
using namespace std;

class animal {
public:
	animal() {
		cout << "animal���캯������" << endl;
	}
	virtual ~animal() {
		cout << "animal������������" << endl;
	}

	virtual void speak() = 0;

};

class Cat:public animal {
public:

	void speak() { cout <<*mNa<< "Сè˵��" << endl; };

	Cat(string nn) {
		mNa = new string(nn);
		cout << "cat���캯������" << endl;
	}

	~Cat() {
		if (mNa!=NULL) {
			cout << "è��������������" << endl;
			delete mNa;
		}
	}

	string* mNa ;
};

void test() {
	
	animal* aa = new Cat("sa");
	aa->speak();
	delete aa;
	//animal ��������������virtual
	//�ͻ᲻���� cat������������
	// ������������ж������ݣ�����ڴ�й¶
};


int main() {
	
	test();
	return 0;
}