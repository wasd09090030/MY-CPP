#include <iostream>
using namespace std;

namespace A                //����һ�������ռ�A
{
	int a = 100;
	namespace B            //Ƕ��һ�������ռ�B
	{
		int a = 20;
	}
}

int a = 200;//����һ��ȫ�ֱ���

int main() {

	cout << "A::a =" << A::a << endl;       //a=100
	cout << "A::B::a =" << A::B::a << endl; //a=20
	cout << "a =" << a << endl;             //a=200
	cout << "::a =" << ::a << endl;         //a=200

	int a = 30;
	cout << "a =" << a << endl;             //30
	cout << "::a =" << ::a << endl;         //200


	return 0;





}