#include <iostream>
using namespace std;


class AbstractDrink {
public:
	//煮水
	virtual void boil() = 0;
	//冲泡
	virtual void brew() = 0;
	//倒进杯子
	virtual void pourIncCup() = 0;
	//加上辅料
	virtual void putInSomething() = 0;

	void makeDrink() {
		boil();
		brew();
		pourIncCup();
		putInSomething();
	}
};

class Coffe:public AbstractDrink {
	//煮水
	void boil() { cout << "煮开水" << endl; };
	//冲泡
	virtual void brew() { cout<<"冲泡咖啡" << endl; };
	//倒进杯子
	virtual void pourIncCup() { cout << "倒入杯子里" << endl; };
	//加上辅料
	virtual void putInSomething() { cout << "加入辅料" << endl; };

};

class Tea :public AbstractDrink {
	//煮水
	void boil() { cout << "煮开水" << endl; };
	//冲泡
	virtual void brew() { cout << "冲泡茶叶" << endl; };
	//倒进杯子
	virtual void pourIncCup() { cout << "倒入杯子里" << endl; };
	//加上辅料
	virtual void putInSomething() { cout << "加入枸杞" << endl; };

};


void test(AbstractDrink& ad){
	ad.makeDrink();
}

int main() {

	Tea tea;
	Coffe cof;

	test(tea);
	test(cof);


	return 0;
}