#include<iostream>
#include<vector>
using namespace std;

class Person {
public:
	int ma;
	mutable int mb; //mutable �ؼ���
	//thisָ�뱾����ָ�볣����ָ���ָ�򲻿��޸�
	//��Ա�����������const��������thisָ����ָ��ָ���ֵҲ�����޸�
	void showPerson() const {
		this.ma = 10;//�������޸�
		 mb = 19;//���Ϲؼ��ֺ�����޸�
	}

	void ssh(){}
};



int main() {

	const Person pp;//�����󣬳�����ֻ�ܵ��ó�����
	pp.showPerson();
	pp.ssh();

}