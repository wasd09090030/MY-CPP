#include<iostream>  
using namespace std;

int main()
{
    int a, b, c, d, m, n, z;
    a = 10;
    b = 20;
    c = 30;
    d = 40;

    //������Ԫ�����
    //����  exp1?exp2:exp3
    //(x < 0) ? (y = 10) : (Z = 20);������if-else�����ͬ
    /*
    if (x < 0)
    y = 10��
    else
    z = 20;
    */

    m = a > b ? a : b;
    //���a>b,��m=a,����m=b
    n = c > d ? c : d;
    z = m > n ? m : n;
    cout << "���ֵΪ��" << z << endl;
    //���Ϊ40
    return 0;
}