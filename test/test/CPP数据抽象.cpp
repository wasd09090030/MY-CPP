#include <iostream>
using namespace std;

//���ݳ������ݳ�����ָ��ֻ������ṩ�ؼ���Ϣ�����������̨��ʵ��ϸ�ڣ���ֻ���ֱ�Ҫ����Ϣ��������ϸ�ڡ�

class Adder {
public:
    // ���캯��
    Adder(int i = 0)
    {
        total = i;
    }
    // ����Ľӿ�
    void addNum(int number)
    {
        total += number;
    }
    // ����Ľӿ�
    int getTotal()
    {
        return total;
    };
private:
    // �������ص�����
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