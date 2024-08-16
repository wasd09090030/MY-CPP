/*
��̬��С��vector �Ĵ�С���Ը�����Ҫ�Զ���������С��
�����洢��vector �е�Ԫ�����ڴ����������洢�ģ���ʹ�÷���Ԫ�طǳ����١�
�ɵ�����vector ���Ա������������ʹ��ѭ������ for ѭ��������������Ԫ�ء�
Ԫ�����ͣ�vector ���Դ洢�κ����͵�Ԫ�أ������������͡�����ָ��ȡ�
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // ����һ���յ���������
    vector<int> myVector;

    // ���Ԫ�ص������У���ӵ� vector ��ĩβ
    myVector.push_back(3);
    myVector.push_back(7);
    myVector.push_back(11);
    myVector.push_back(5);

    // ���������е�Ԫ�ز����
    cout << "Elements in the vector: ";
    for (int element : myVector) {
        cout << element << " ";
    }
    cout << endl;

    // ���������еĵ�һ��Ԫ�ز����
    cout << "First element: " << myVector[0] << endl;

    // ���������еĵڶ���Ԫ�ز����
    cout << "Second element: " << myVector.at(1) << endl;

    // ��ȡ�����Ĵ�С�����
    cout << "Size of the vector: " << myVector.size() << endl;

    // ɾ�������еĵ�����Ԫ��
    myVector.erase(myVector.begin() + 2);

    // ���ɾ��Ԫ�غ������
    cout << "Elements in the vector after erasing: ";
    for (int element : myVector) {
        cout << element << " ";
    }
    cout << endl;

    // ������������
    myVector.clear();
    cout << "Size of the vector after clearing: " << myVector.size() << endl;

    return 0;
}