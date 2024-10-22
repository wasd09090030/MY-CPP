#include <iostream>
#include <utility>  // std::move

class MyClass {
private:
    int* data;  // 动态资源
public:
    // 默认构造函数
    MyClass() : data(new int[100]) {
        std::cout << "Constructor: Resource allocated.\n";
    }

    // 移动构造函数
    MyClass(MyClass&& other) noexcept : data(other.data) {
        other.data = nullptr;  // 确保原对象不再持有资源
        std::cout << "Move Constructor: Resource moved.\n";
    }

    // 移动赋值运算符
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            delete[] data;  // 释放当前对象的资源
            data = other.data;  // 接管右值对象的资源
            other.data = nullptr;
            std::cout << "Move Assignment: Resource moved.\n";
        }
        return *this;
    }

    // 析构函数
    ~MyClass() {
        delete[] data;
        std::cout << "Destructor: Resource released.\n";
    }
};

int main() {
    MyClass obj1;            // 默认构造
    MyClass obj2 = std::move(obj1);  // 移动构造
    MyClass obj3;
    obj3 = std::move(obj2);   // 移动赋值
    return 0;
}
/*obj1 使用默认构造函数分配资源。
当我们用 std::move(obj1) 将 obj1 移动给 obj2 时，移动构造函数被调用，obj2 接管了 obj1 的资源，而 obj1 的指针被置为 nullptr。
类似地，obj3 接管了 obj2 的资源，避免了拷贝，从而提高了性能。*/