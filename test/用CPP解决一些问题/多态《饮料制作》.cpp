#include <iostream>
using namespace std;


class AbstractDrink {
public:
	//��ˮ
	virtual void boil() = 0;
	//����
	virtual void brew() = 0;
	//��������
	virtual void pourIncCup() = 0;
	//���ϸ���
	virtual void putInSomething() = 0;

	void makeDrink() {
		boil();
		brew();
		pourIncCup();
		putInSomething();
	}
};

class Coffe:public AbstractDrink {
	//��ˮ
	void boil() { cout << "��ˮ" << endl; };
	//����
	virtual void brew() { cout<<"���ݿ���" << endl; };
	//��������
	virtual void pourIncCup() { cout << "���뱭����" << endl; };
	//���ϸ���
	virtual void putInSomething() { cout << "���븨��" << endl; };

};

class Tea :public AbstractDrink {
	//��ˮ
	void boil() { cout << "��ˮ" << endl; };
	//����
	virtual void brew() { cout << "���ݲ�Ҷ" << endl; };
	//��������
	virtual void pourIncCup() { cout << "���뱭����" << endl; };
	//���ϸ���
	virtual void putInSomething() { cout << "�������" << endl; };

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