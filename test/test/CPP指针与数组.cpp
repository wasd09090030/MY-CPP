#include <iostream>
#include<algorithm>
using namespace std;
const int MAX = 3;

int main()
{
    int  var[MAX] = { 10, 100, 200 };
    int* ptr;


    //*min_element���ص��ǵ�ַ
    int x = *min_element(var,var+2);

    cout << "��Сֵ" << x<<endl;
    // ָ���е������ַ
    ptr = var;
    //ָ��ָ�������һ�����ĵ�ַ
    for (int i = 0; i < MAX; i++)
    {
        cout << "var[" << i << "]���ڴ��ַΪ ";
        cout << ptr << endl;

        cout << "var[" << i << "] ��ֵΪ ";
        cout << *ptr << endl;
        //���ptr���ƶ���*ptrָ�����Զ�������һ��Ԫ��

        // �ƶ�����һ��λ��
        ptr++;
    }
    return 0;
}