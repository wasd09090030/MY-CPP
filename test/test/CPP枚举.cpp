#include <iostream>
using namespace std;
enum time
{
    first, second,
    third, forth, fifth
};
//enumû��Ҫ��main�����ж���

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
    //ÿ��ö��Ԫ��������ʱ������һ������ֵ��Ĭ�ϴ� 0 ��ʼ������� 1��



    enum Weekend02 { W1, W2, W3 = 555, W4, W5 };
    int m,n,j,k,l;
    m = W1;
    n = W2;
    j = W3;
    k = W4;
    l = W5;
    cout << m << "," << n << "," << j << "," << k << "," << l << endl;
    //Ҳ�����ڶ���ö������ʱ��ö��Ԫ�ظ�ֵ����ʱ����ֵ��ö��ֵΪ������ֵ��������û�и�ֵ��ö��ֵ��Ϊǰһ��ö��ֵ�� 1��
    





    return 0;
}