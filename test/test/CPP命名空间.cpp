#include <iostream>
using namespace std;

namespace A                //定义一个命名空间A
{
	int a = 100;
	namespace B            //嵌套一个命名空间B
	{
		int a = 20;
	}
}

int a = 200;//定义一个全局变量

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