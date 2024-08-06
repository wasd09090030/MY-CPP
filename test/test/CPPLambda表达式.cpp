#include <iostream>

using namespace std;

int main()
{
    int i = 1024;
    //Lambda表达式
    auto func = [=] {  // [=] 表明将外部的所有变量拷贝一份到该Lambda函数内部，既i的值，没有“=”会报错
        cout << i<<endl;
        };
    func();



    auto add = [](int a, int b) -> int { return a + b; };

    // 自动推断返回类型
    auto multiply = [](int a, int b) { return a * b; };
    int sum = add(2, 5);   // 输出：7
    int product = multiply(2, 5);  // 输出：10
    cout << sum << endl;
    cout << product << endl;

    return 0;
}