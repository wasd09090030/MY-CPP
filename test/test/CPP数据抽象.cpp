#include <iostream>
using namespace std;

//数据抽象：数据抽象是指，只向外界提供关键信息，并隐藏其后台的实现细节，即只表现必要的信息而不呈现细节。

class Adder {
public:
    // 构造函数
    Adder(int i = 0)
    {
        total = i;
    }
    // 对外的接口
    void addNum(int number)
    {
        total += number;
    }
    // 对外的接口
    int getTotal()
    {
        return total;
    };
private:
    // 对外隐藏的数据
    int total;
};
int main()
{
    Adder a;

    a.addNum(10);
    a.addNum(20);
    a.addNum(30);

    cout << "Total " << a.getTotal() << endl;
    return 0;
}