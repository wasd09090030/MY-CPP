#include <iostream>
#include<algorithm>
using namespace std;
const int MAX = 3;

int main()
{
    int  var[MAX] = { 10, 100, 200 };
    int* ptr;


    //*min_element返回的是地址
    int x = *min_element(var,var+2);

    cout << "最小值" << x<<endl;
    // 指针中的数组地址
    ptr = var;
    //指针指向数组第一个数的地址
    for (int i = 0; i < MAX; i++)
    {
        cout << "var[" << i << "]的内存地址为 ";
        cout << ptr << endl;

        cout << "var[" << i << "] 的值为 ";
        cout << *ptr << endl;
        //如果ptr不移动，*ptr指向的永远是数组第一个元素

        // 移动到下一个位置
        ptr++;
    }
    return 0;
}