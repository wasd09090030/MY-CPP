#include<iostream>
#include<vector>
using namespace std;


//ǳ�������ܵ����⣺�������ڴ��ظ��ͷ�
class Person {

public:
	int Age;
	int* height;

	Person() {
		cout << "����һ����Person" << endl;
	}

	Person(int age,int H) {

		cout << "����һ����Person" << endl;
		Age = age;
		height = new int(H);
	}
	
	//��������
	Person(const Person& p) {
		Age = p.Age;
		//height = p.height; ǳ�����������������ڴ��ַ���䣬ֻ�Ǹ�����һ��
		height = new int(*p.height);//�������������һ���ڴ�
	}

	~Person() {
		//���������ٵ����ݽ����ͷŲ���
		//����ǳ��������ʱ��ͬһ���ڴ���ͷ�����Ȼ�󱨴�
		if (height != nullptr) {
			delete height;
			height = nullptr;
		}
		cout << "�����������" << endl;

	}
};

void test() {
	Person p2(18,160);
	Person p3(p2);
	
	//ִ����Ϻ��Զ�ִ����������
}

int main() {

	test();


	return 0;
}