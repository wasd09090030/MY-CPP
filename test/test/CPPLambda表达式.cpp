#include <iostream>

using namespace std;

int main()
{
    int i = 1024;
    //Lambda���ʽ
    auto func = [=] {  // [=] �������ⲿ�����б�������һ�ݵ���Lambda�����ڲ�����i��ֵ��û�С�=���ᱨ��
        cout << i<<endl;
        };
    func();



    auto add = [](int a, int b) -> int { return a + b; };

    // �Զ��ƶϷ�������
    auto multiply = [](int a, int b) { return a * b; };
    int sum = add(2, 5);   // �����7
    int product = multiply(2, 5);  // �����10
    cout << sum << endl;
    cout << product << endl;

    return 0;
}