/*C++ ���� vs ָ��
���ú�������ָ�����������֮����������Ҫ�Ĳ�ͬ��

�����ڿ����á����ñ������ӵ�һ��Ϸ����ڴ档
һ�����ñ���ʼ��Ϊһ�����󣬾Ͳ��ܱ�ָ����һ������ָ��������κ�ʱ��ָ����һ������
���ñ����ڴ���ʱ����ʼ����ָ��������κ�ʱ�䱻��ʼ����*/

//�����൱�ڸ����������ţ����Ǳ�������


#include <iostream>

using namespace std;

int main()
{
	int i;
	int& r = i;
	//���ñ���������ʱ�����ʼ����������������ֵ
	i = 5;
	cout << "Value of i : " << i << endl;
	cout << "Value of i reference : " << r << endl;
	cout << "Addr of i: " << &i << endl;
	cout << "Addr of r: " << &r << endl;

	int x=6;
	
	int y = x;
	//���ٳ��µ��ڴ�ռ�
	
	cout << "Value of x : " << x << endl;
	cout << "Value of y : " << y << endl;
	cout << "Addr of x: " << &x << endl;
	cout << "Addr of y: " << &y << endl;

	cout << "===================================" << endl;

	int rats = 100;
	int& rodent = rats;

	cout << "rats = " << rats << ", rosent = " << rodent << endl;
	cout << "rats address = " << &rats << endl;
	cout << "rosent address = " << &rodent << endl;

	cout << "===================================" << endl;
	int bunnies = 50;
	rodent = bunnies;

	cout << "rats = " << rats << ", rosent = " << rodent << ", bunnies = " << bunnies << endl;
	cout << "rats address = " << &rats << endl;
	cout << "rosent address = " << &rodent << endl;
	cout << "bunniess address = " << &bunnies << endl;
	//�ӽ�����Կ�������Ȼ�ڵ��� rodent = bunnies; ������ rosent ��ֵ��Ϊ 50��
	// ���� rosent ��ָ��ĵ�ַ�ռ仹��ָ���� rats��û�з����ı䣬
	// ˵�� rodent = bunnies; ֻ�ǽ� bunnies ��ֵ��ֵ������ rodent ��ָ��ı�����û�иı����õ�ָ��






	return 0;
}