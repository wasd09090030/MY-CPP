#include <iostream>
#include <utility>  // std::move

class MyClass {
private:
    int* data;  // ��̬��Դ
public:
    // Ĭ�Ϲ��캯��
    MyClass() : data(new int[100]) {
        std::cout << "Constructor: Resource allocated.\n";
    }

    // �ƶ����캯��
    MyClass(MyClass&& other) noexcept : data(other.data) {
        other.data = nullptr;  // ȷ��ԭ�����ٳ�����Դ
        std::cout << "Move Constructor: Resource moved.\n";
    }

    // �ƶ���ֵ�����
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            delete[] data;  // �ͷŵ�ǰ�������Դ
            data = other.data;  // �ӹ���ֵ�������Դ
            other.data = nullptr;
            std::cout << "Move Assignment: Resource moved.\n";
        }
        return *this;
    }

    // ��������
    ~MyClass() {
        delete[] data;
        std::cout << "Destructor: Resource released.\n";
    }
};

int main() {
    MyClass obj1;            // Ĭ�Ϲ���
    MyClass obj2 = std::move(obj1);  // �ƶ�����
    MyClass obj3;
    obj3 = std::move(obj2);   // �ƶ���ֵ
    return 0;
}
/*obj1 ʹ��Ĭ�Ϲ��캯��������Դ��
�������� std::move(obj1) �� obj1 �ƶ��� obj2 ʱ���ƶ����캯�������ã�obj2 �ӹ��� obj1 ����Դ���� obj1 ��ָ�뱻��Ϊ nullptr��
���Ƶأ�obj3 �ӹ��� obj2 ����Դ�������˿������Ӷ���������ܡ�*/