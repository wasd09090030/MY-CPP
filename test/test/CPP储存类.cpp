/*auto：这是默认的存储类说明符，通常可以省略不写。auto 指定的变量具有自动存储期，即它们的生命周期仅限于定义它们的块（block）。
auto 变量通常在栈上分配。

register：用于建议编译器将变量存储在CPU寄存器中以提高访问速度。
在 C++11 及以后的版本中，register 已经是一个废弃的特性，不再具有实际作用。

static：用于定义具有静态存储期的变量或函数，它们的生命周期贯穿整个程序的运行期。
在函数内部，static变量的值在函数调用之间保持不变。在文件内部或全局作用域，static变量具有内部链接，只能在定义它们的文件中访问。

extern：用于声明具有外部链接的变量或函数，它们可以在多个文件之间共享。
默认情况下，全局变量和函数具有 extern 存储类。在一个文件中使用extern声明另一个文件中定义的全局变量或函数，可以实现跨文件共享。

mutable (C++11)：用于修饰类中的成员变量，允许在const成员函数中修改这些变量的值。
通常用于缓存或计数器等需要在const上下文中修改的数据。

thread_local (C++11)：用于定义具有线程局部存储期的变量，每个线程都有自己的独立副本。
线程局部变量的生命周期与线程的生命周期相同。*/

#include <iostream>
using namespace std;

// 全局变量，具有外部链接，默认存储类为extern
int globalVar=99;

void function() {
    // 局部变量，具有自动存储期，默认存储类为auto
     int localVar = 10;

    // 静态变量，具有静态存储期，生命周期贯穿整个程序
    static int staticVar = 20;

    const int constVar = 30; // const变量默认具有static存储期

    // 尝试修改const变量，编译错误
    // constVar = 40;

    // mutable成员变量，可以在const成员函数中修改
    class MyClass {
    public:
        mutable int mutableVar;

        void constMemberFunc() const {
            mutableVar = 50; // 允许修改mutable成员变量
        }
    };

    // 线程局部变量，每个线程有自己的独立副本
    thread_local int threadVar = 60;

    cout << globalVar;
}

int main() {
    extern int externalVar; // 声明具有外部链接的变量

    function();
    

    return 0;
}