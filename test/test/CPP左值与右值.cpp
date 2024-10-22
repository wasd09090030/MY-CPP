/*
��ֵ (lvalue)
���壺��ֵ��ָ��Щ�� ��ȷ�ڴ��ַ �Ķ��󣬼�����ȡ��ַ (&) �Ķ�����ֵͨ���Ǳ��ʽ�г����ڸ�ֵ�������ߵĶ���

�ص㣺

��ֵ�г־��ԣ����������ڱ��ʽ��ֵ��������ڡ�
��ֵ���Գ����ڸ�ֵ�����������Ҳࡣ
��ֵ���Ա��޸ģ�����Ƿǳ�����ֵ����
�����ڴ��ַ������ͨ��ȡַ�� & ������ַ��


��ֵ (rvalue)
���壺��ֵ��û����ȷ�ڴ��ַ����ڱ��ʽ��ֵʱ��ʱ���ڵĶ�������ͨ���Ǳ��ʽ����Ľ��ֵ���޷���ȡ���ַ����ֵͨ���ǳ����ڸ�ֵ������ұߵĶ���

�ص㣺

��ֵ����ʱ�ģ�����ֻ���ڱ��ʽ�ĵ�ǰ��ֵ�����д��ڡ�
��ֵ���ܳ����ڸ�ֵ��������ࣨ����ʹ����ֵ���ã���
��ֵһ���ǳ�������ʱֵ���޷�ȡ��ַ�������ܶ���ֵʹ��ȡַ�� &����
*/

#include<iostream>
using namespace std;





//T&& ���Խ�����ֵ����Ҳ���Խ�����ֵ���ã�Ҳ����˵t����Ϊ��ֵҲ����Ϊ��ֵ

void Fun(int& x) { cout << "��ֵ����" << endl; }
void Fun(const int& x) { cout << "const ��ֵ����" << endl; }
void Fun(int&& x) { cout << "��ֵ����" << endl; }
void Fun(const int&& x) { cout << "const ��ֵ����" << endl; }

template<typename T>
void PerfectForward(T&& t)
{
	Fun(t);
}



template<typename T>
void PerfectForward2(T&& t)
{
	Fun(std::forward<T>(t));
}


int main() {

	int a = 10;
	int &b = a;//��ֵ���ã�a��b�õ�ͬһ��ռ�

	int&& c = 20;//��ֵ����
	//��ֵ���ÿ���ȡ��ַ��Ҳ�����޸�

	cout << c << endl;

	cout << &c << endl;

	c = 30;

	cout << c << endl;
	//���ͣ�ͨ����ֵ���ã��ӱ���������������������ֵ��Ȩ������ֵ�����ú���Ȼ����



	PerfectForward(10);           // ��ֵ
	int x = 1;
	PerfectForward(x);            // ��ֵ
	PerfectForward(std::move(x)); // ��ֵ
	const int y = 8;
	PerfectForward(y);      // const ��ֵ
	PerfectForward(std::move(y)); // const ��ֵ

	//��������ӡ�Ķ�����ֵ��ֻ��������ֵ�����ڰ���ֵ����˻�Ϊ��ֵ���ã�
	// ��������t��ʶ��Ϊ��ֵ���á��󶨺����ֵ���ú���ֵ����ûʲô���𣬶����Ը�ֵ������ȡ��ַ��������������������������

	//������������ת��������ڴ��ݹ����б������õ����ԣ�����ֵ���ò��˻���
	// ����forward���������Ϊ��ֵʲô�����죬Ϊ�˻������ֵ������һ��move
	PerfectForward2(10);
	PerfectForward2(x);            // ��ֵ
	PerfectForward2(std::move(x));
	PerfectForward2(y);
	PerfectForward2(std::move(y));

	return 0;
}













































