#include<iostream>

using namespace std;

class Person {
public:
	static int height;
	int age;

	//��̬��Ա����
	static void function() {

		height = 2000;//��̬��Ա�����ɷ��ʾ�̬����
		age = 0;//���ɷ��ʷǾ�̬����Ϊ��̬��Ա��ȫ���ԣ�ֻ����һ�����޷�����Ǿ�̬��Ա��
		cout << "��̬�����ɵ���" << endl;
	}


private:

	void f2() {
		cout << "����F2" << endl;
	}
	static void f3() {
		cout << "����F3" << endl;
	}
};


int main() {

	Person p;
	p.function();
	Person::function();
	Person::f3();//������ʲ���˽�еľ�̬����
}