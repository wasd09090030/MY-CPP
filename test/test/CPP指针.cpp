#include <iostream>

using namespace std;

//*是值，&是地址

int main()
{
	int  var = 20;   // 实际变量的声明
	int* ip;        // 指针变量的声明

	ip = &var;       // 在指针变量中存储 var 的地址

	//指针IP 前面加上 *代表引用，找到指针指向的内存中的数据

	cout << "Value of var variable: ";
	cout << var << endl;

	// 输出在指针变量中存储的地址
	cout << "Address stored in ip variable: ";
	cout << ip << endl;//输出地址

	// 访问指针中地址的值
	cout << "Value of *ip variable: ";
	cout << *ip << endl;//输出20

	return 0;
}