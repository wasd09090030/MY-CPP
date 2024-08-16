/*
动态大小：vector 的大小可以根据需要自动增长和缩小。
连续存储：vector 中的元素在内存中是连续存储的，这使得访问元素非常快速。
可迭代：vector 可以被迭代，你可以使用循环（如 for 循环）来访问它的元素。
元素类型：vector 可以存储任何类型的元素，包括内置类型、对象、指针等。
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 创建一个空的整数向量
    vector<int> myVector;

    // 添加元素到向量中，添加到 vector 的末尾
    myVector.push_back(3);
    myVector.push_back(7);
    myVector.push_back(11);
    myVector.push_back(5);

    // 访问向量中的元素并输出
    cout << "Elements in the vector: ";
    for (int element : myVector) {
        cout << element << " ";
    }
    cout << endl;

    // 访问向量中的第一个元素并输出
    cout << "First element: " << myVector[0] << endl;

    // 访问向量中的第二个元素并输出
    cout << "Second element: " << myVector.at(1) << endl;

    // 获取向量的大小并输出
    cout << "Size of the vector: " << myVector.size() << endl;

    // 删除向量中的第三个元素
    myVector.erase(myVector.begin() + 2);

    // 输出删除元素后的向量
    cout << "Elements in the vector after erasing: ";
    for (int element : myVector) {
        cout << element << " ";
    }
    cout << endl;

    // 清空向量并输出
    myVector.clear();
    cout << "Size of the vector after clearing: " << myVector.size() << endl;

    return 0;
}