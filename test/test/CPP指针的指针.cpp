#include <iostream>

using namespace std;

int main()
{
    int  var;//举个例子，var是超市的商品，假设他是苹果
    int* ptr;//ptr的值就是，指定售卖苹果的区域，本身也是指苹果
    
    int** pptr;//pptr就是苹果的商品编号，本身也是指苹果
    int*** ppptr;//编不出来了

    var = 3000;

    // 获取 var 的地址
    ptr = &var;

    int* douptr = ptr;

    // 使用运算符 & 获取 ptr 的地址
    pptr = &ptr;

    ppptr = &pptr;

    cout << "**pptr 值为 :" << **pptr << endl;
    cout << "*pptr 值为 :" << *pptr << endl;
    cout << "pptr 值为:" << pptr << endl;

    cout << "var 值为 :" << var << endl;
    cout << "*ptr 值为:" << *ptr << endl;
    cout << "*douptr 值为:" << *douptr << endl;
    cout << "**pptr 值为:" << **pptr << endl;
    cout << "***ppptr 值为:" << ***ppptr << endl;

    // 使用 pptr 获取值
    cout << "var 值为 :" << var << endl;
    cout << "ptr 值为:" << ptr << endl;
    cout << "douptr 值为:" << douptr << endl;
    cout << "pptr 值为:" << pptr << endl;
    cout << "ppptr 值为:" << ppptr << endl;

    cout << "var 地址为 :" << &var << endl;
    cout << "ptr 地址为:" << &ptr << endl;
    cout << "pptr 地址为:" << &pptr << endl;
    cout << "ppptr 地址为:" << &ppptr << endl;

    return 0;
}