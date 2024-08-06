#include<iostream>;
using namespace std;
#define f(x) x*x//#define 没有作用域的限制

void func1();
void func2();


int main()
{
    int a = 6, b = 2, c;
    c = f(a) / f(b);//实际算式c=6*6/2*2;
    //根本原因就在于 #define 只是简单的字符串替换。
    printf("%d\n", c);

    func2();//输出HelloWorld


    
    return 0;
}


void func1()
{
    #define HW "HelloWorld";
    typedef unsigned int UINT;//typedef有自己的作用域
}
//#define 没有作用域的限制，只要是之前预定义过的宏，在以后的程序中都可以使用

void func2()
{
    string str = HW;
    cout << str << endl;
    //UINT uValue = 5 编译时会输出error C2065: 'UINT' : undeclared identifier
    //而给UINT加上public访问权限后，则可编译通过
}