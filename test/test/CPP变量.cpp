#include <iostream>
using namespace std;

// 全局变量声明
int g = 20;
//全局变量可以被任何函数访问。也就是说，全局变量一旦声明，在整个程序中都是可用的。

int main()
{
	// 局部变量声明
	int g = 10;
	//局部变量和全局变量的名称可以相同，但是在函数内，局部变量的值会覆盖全局变量的值

	cout << g<<endl;

	int a = 10;
	{
		int a = 20;  // 块作用域变量
		cout << "块变量: " << a << endl;
	}
	    cout << "外部变量: " << a << endl;
		//内部的代码块中声明了一个名为 a 的变量，它与外部作用域中的变量 a 同名。
		// 内部作用域中的变量 a 将覆盖外部作用域中的变量 a，在内部作用域中访问 a 时输出的是20，而在外部作用域中访问 a 时输出的是 10。

	return 0;
}