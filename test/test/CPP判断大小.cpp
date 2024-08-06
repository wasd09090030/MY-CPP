#include<iostream>  
using namespace std;

int main()
{
    int a, b, c, d, m, n, z;
    a = 10;
    b = 20;
    c = 30;
    d = 40;

    //？：三元运算符
    //例：  exp1?exp2:exp3
    //(x < 0) ? (y = 10) : (Z = 20);与下列if-else语句相同
    /*
    if (x < 0)
    y = 10；
    else
    z = 20;
    */

    m = a > b ? a : b;
    //如果a>b,则m=a,否则m=b
    n = c > d ? c : d;
    z = m > n ? m : n;
    cout << "最大值为：" << z << endl;
    //输出为40
    return 0;
}