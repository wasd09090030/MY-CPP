//������ά���飺vector<vector<int>> table(size1, vector<int>(size2, 0));
//����˵��������һ����Ϊ table ����������Ԫ��Ϊ vector������������˵����һ��int�͵Ķ�ά���顣

#include <iostream>
#include <vector>
using namespace std;

int main()
{


    int rows = 2, columns = 3;
    int a1[2][3] = { 1,2,3,4,5,6 };

    vector<vector<int> > a3(rows, vector<int>(columns));

    for (int i = 0; i < rows; i++) {//��ʼ��
        for (int j = 0; j < columns; j++) {
            a3[i][j] = a1[i][j];
        }
    }
}