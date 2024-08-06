/*C++ 引用 vs 指针
引用很容易与指针混淆，它们之间有三个主要的不同：

不存在空引用。引用必须连接到一块合法的内存。
一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
引用必须在创建时被初始化。指针可以在任何时间被初始化。*/

//引用相当于给变量起个外号，就是变量本身。


#include <iostream>

using namespace std;

int main()
{
	int i;
	int& r = i;
	//引用必须在声明时将其初始化，不能先声明后赋值
	i = 5;
	cout << "Value of i : " << i << endl;
	cout << "Value of i reference : " << r << endl;
	cout << "Addr of i: " << &i << endl;
	cout << "Addr of r: " << &r << endl;

	int x=6;
	
	int y = x;
	//开辟出新的内存空间
	
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
	//从结果可以看出，虽然在调用 rodent = bunnies; 后引用 rosent 的值变为 50，
	// 但是 rosent 所指向的地址空间还是指向了 rats，没有发生改变，
	// 说明 rodent = bunnies; 只是将 bunnies 的值赋值给引用 rodent 所指向的变量，没有改变引用的指向。






	return 0;
}