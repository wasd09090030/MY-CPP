/*
左值 (lvalue)
定义：左值是指那些有 明确内存地址 的对象，即可以取地址 (&) 的对象。左值通常是表达式中出现在赋值运算符左边的对象。

特点：

左值有持久性，即它可以在表达式求值后继续存在。
左值可以出现在赋值操作的左侧或右侧。
左值可以被修改（如果是非常量左值）。
具有内存地址，可以通过取址符 & 获得其地址。


右值 (rvalue)
定义：右值是没有明确内存地址或仅在表达式求值时临时存在的对象，它们通常是表达式计算的结果值，无法获取其地址。右值通常是出现在赋值运算符右边的对象。

特点：

右值是临时的，它们只能在表达式的当前求值过程中存在。
右值不能出现在赋值操作的左侧（除非使用右值引用）。
右值一般是常量或临时值，无法取地址（即不能对右值使用取址符 &）。
*/

#include<iostream>
using namespace std;





//T&& 可以接受右值引用也可以接受左值引用，也就是说t可以为右值也可以为左值

void Fun(int& x) { cout << "左值引用" << endl; }
void Fun(const int& x) { cout << "const 左值引用" << endl; }
void Fun(int&& x) { cout << "右值引用" << endl; }
void Fun(const int&& x) { cout << "const 右值引用" << endl; }

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
	int &b = a;//左值引用，a与b用的同一块空间

	int&& c = 20;//右值引用
	//右值引用可以取地址，也可以修改

	cout << c << endl;

	cout << &c << endl;

	c = 30;

	cout << c << endl;
	//解释：通过右值引用，从编译器手中拿走了销毁右值的权利，右值在引用后依然存在



	PerfectForward(10);           // 右值
	int x = 1;
	PerfectForward(x);            // 左值
	PerfectForward(std::move(x)); // 右值
	const int y = 8;
	PerfectForward(y);      // const 左值
	PerfectForward(std::move(y)); // const 右值

	//我们最后打印的都是左值，只是由于右值引用在绑定右值后就退化为左值引用，
	// 编译器将t都识别为左值引用。绑定后的右值引用和左值引用没什么区别，都可以赋值都可以取地址，编译器不会主动的区分他们

	//就引入了完美转发概念，即在传递过程中保持引用的特性，即右值引用不退化。
	// 引入forward函数，如果为左值什么都不办，为退化后的右值，进行一次move
	PerfectForward2(10);
	PerfectForward2(x);            // 左值
	PerfectForward2(std::move(x));
	PerfectForward2(y);
	PerfectForward2(std::move(y));

	return 0;
}













































