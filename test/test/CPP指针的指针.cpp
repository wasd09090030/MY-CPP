#include <iostream>

using namespace std;

int main()
{
    int  var;//�ٸ����ӣ�var�ǳ��е���Ʒ����������ƻ��
    int* ptr;//ptr��ֵ���ǣ�ָ������ƻ�������򣬱���Ҳ��ָƻ��
    
    int** pptr;//pptr����ƻ������Ʒ��ţ�����Ҳ��ָƻ��
    int*** ppptr;//�಻������

    var = 3000;

    // ��ȡ var �ĵ�ַ
    ptr = &var;

    int* douptr = ptr;

    // ʹ������� & ��ȡ ptr �ĵ�ַ
    pptr = &ptr;

    ppptr = &pptr;

    cout << "**pptr ֵΪ :" << **pptr << endl;
    cout << "*pptr ֵΪ :" << *pptr << endl;
    cout << "pptr ֵΪ:" << pptr << endl;

    cout << "var ֵΪ :" << var << endl;
    cout << "*ptr ֵΪ:" << *ptr << endl;
    cout << "*douptr ֵΪ:" << *douptr << endl;
    cout << "**pptr ֵΪ:" << **pptr << endl;
    cout << "***ppptr ֵΪ:" << ***ppptr << endl;

    // ʹ�� pptr ��ȡֵ
    cout << "var ֵΪ :" << var << endl;
    cout << "ptr ֵΪ:" << ptr << endl;
    cout << "douptr ֵΪ:" << douptr << endl;
    cout << "pptr ֵΪ:" << pptr << endl;
    cout << "ppptr ֵΪ:" << ppptr << endl;

    cout << "var ��ַΪ :" << &var << endl;
    cout << "ptr ��ַΪ:" << &ptr << endl;
    cout << "pptr ��ַΪ:" << &pptr << endl;
    cout << "ppptr ��ַΪ:" << &ppptr << endl;

    return 0;
}