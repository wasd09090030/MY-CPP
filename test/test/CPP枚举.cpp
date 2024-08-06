#include <iostream>
using namespace std;
enum time
{
    first, second,
    third, forth, fifth
};
//enum没必要在main函数中定义

int main()
{
    enum time Rank = fifth;
    if (Rank == fifth)
    {
        cout << "Succeed!"<<endl;
    }
    



    enum Weekend { Zero, One, Two, Three, Four };
    int a, b, c, d, e;
    a = Zero;
    b = One;
    c = Two;
    d = Three;
    e = Four;
    cout << a << "," << b << "," << c << "," << d << "," << e << endl;
    //每个枚举元素在声明时被分配一个整型值，默认从 0 开始，逐个加 1。



    enum Weekend02 { W1, W2, W3 = 555, W4, W5 };
    int m,n,j,k,l;
    m = W1;
    n = W2;
    j = W3;
    k = W4;
    l = W5;
    cout << m << "," << n << "," << j << "," << k << "," << l << endl;
    //也可以在定义枚举类型时对枚举元素赋值，此时，赋值的枚举值为所赋的值，而其他没有赋值的枚举值在为前一个枚举值加 1。
    





    return 0;
}