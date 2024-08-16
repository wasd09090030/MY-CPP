//声明二维数组：vector<vector<int>> table(size1, vector<int>(size2, 0));
//代码说明：声明一个名为 table 的容器，其元素为 vector的容器。简单来说类似一个int型的二维数组。

#include <iostream>
#include <vector>
using namespace std;

int main()
{


    int rows = 2, columns = 3;
    int a1[2][3] = { 1,2,3,4,5,6 };

    vector<vector<int> > a3(rows, vector<int>(columns));

    for (int i = 0; i < rows; i++) {//初始化
        for (int j = 0; j < columns; j++) {
            a3[i][j] = a1[i][j];
        }
    }
}