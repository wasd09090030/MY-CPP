#include<iostream>
#include<vector>
using namespace std;

class Person {

public:
	int age;

	//���캯����
	//û�з���ֵ������void
	//��������������ͬ
	//���캯�������в������������ء�
	//���������ʱ���Զ�����һ��
	Person() {
		cout << "����һ����Person" << endl;
	}

	//�����������ã�����������������
	//�������������в��������ܹ�����
	~Person() {
		
		cout << "������������" << endl;
	}


	//��������
	Person(const Person&p) {
		age = p.age;
	}
};

void test() {
     Person();
	 //ִ����Ϻ��Զ�ִ����������
}

int main() {

	test();


	return 0;
}