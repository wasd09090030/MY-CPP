#include<iostream>;
using namespace std;
#define f(x) x*x//#define û�������������

void func1();
void func2();


int main()
{
    int a = 6, b = 2, c;
    c = f(a) / f(b);//ʵ����ʽc=6*6/2*2;
    //����ԭ������� #define ֻ�Ǽ򵥵��ַ����滻��
    printf("%d\n", c);

    func2();//���HelloWorld


    
    return 0;
}


void func1()
{
    #define HW "HelloWorld";
    typedef unsigned int UINT;//typedef���Լ���������
}
//#define û������������ƣ�ֻҪ��֮ǰԤ������ĺ꣬���Ժ�ĳ����ж�����ʹ��

void func2()
{
    string str = HW;
    cout << str << endl;
    //UINT uValue = 5 ����ʱ�����error C2065: 'UINT' : undeclared identifier
    //����UINT����public����Ȩ�޺���ɱ���ͨ��
}