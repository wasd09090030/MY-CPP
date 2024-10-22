#include<iostream>
using namespace std;
#include<string>


//可以破坏封装
class Pclass {
	//友元可以访问私有成员
	//友元函数
	friend void build2(Pclass* PP);
	//友元类
	friend class Pclasd;
	//成员函数作友元
	friend void Pclassad::visit();

public:
	Pclass() {
		room = "asd";
		classroom = "dasd";
	}


private:

	string classroom;

public:
	string room;
};

class Pclasd {

	Pclass dsa;

	void visit() {
		cout << "可以访问" <<dsa.classroom<< endl;
	}
};


class Pclassad {

	Pclass dsa;

public:
	void visit1() {
		cout << "可以访问" << dsa.classroom << endl;
	}
	void visit() const;
};




void Pclassad::visit() const {
	cout << "可以访问" << dsa.classroom << endl;
}


//全局函数
void build(Pclass* PP) {
	cout << "正在访问全局函数" << PP->classroom<<endl;
}
//可访问私有成员
void build2(Pclass* PP) {
	cout << "正在访问全局函数" << PP->classroom << endl;
}


int main() {

	Pclass ps;
	build(&ps);
}

