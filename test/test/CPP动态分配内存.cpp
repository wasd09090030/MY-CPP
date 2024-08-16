#include <iostream>
using namespace std;

class Box
{
public:
    Box() {
        cout << "调用构造函数！" << endl;
    }
    //析构函数，它是类的一个成员函数，名字由波浪号加类名构成。
    // 看它的名字我们大概就能联想到他功能，是执行与构造函数相反的操作：释放对象使用的资源，并销毁非static成员。
    //几个特点：  
  //  1.函数名是在类名前加上~，无参数且无返回值。
  //      2.一个类只能有且有一个析构函数，如果没有显式的定义，系统会生成一个缺省的析构函数（合成析构函数）。
     //   3.析构函数不能重载。每有一次构造函数的调用就会有一次析构函数的调用。
    ~Box() {
        cout << "调用析构函数！" << endl;
    }
};

int main()
{
    Box* myBoxArray = new Box[4];

    delete[] myBoxArray; // 删除数组
    return 0;
}