#include <iostream> 
using namespace std;


//以下程序会输出
//Parent class area :
//Parent class area :

//在int area()前面加上Virual
//此时，编译器看的是指针的内容，而不是它的类型。因此，由于 tri 和 rec 类的对象的地址存储在 *shape 中，所以会调用各自的 area() 函数。
//正如您所看到的，每个子类都有一个函数 area() 的独立实现。这就是多态的一般使用方式


//动态多态满足条件
//1.子类继承父类
//2.子类重写父类的虚函数


//抽象类，拥有纯虚函数的类
//特点：无法实例化对象
//抽象类的子类必须重写父类的纯虚函数，否则也是抽象类
class Abstract {
    virtual void sa() = 0;//纯虚函数
};


class Shape {
protected:
    int width, height;
public:
    Shape(int a = 0, int b = 0)
    {
        width = a;
        height = b;
    }
    int area()
    {
        cout << "Parent class area :" << endl;
        return 0;
    }
    //虚函数,晚绑定地址
    virtual void showtype() {
        cout << "无形状" << endl;
    }
};
class Rectangle : public Shape {
public:
    Rectangle(int a = 0, int b = 0) :Shape(a, b) { }
    int area()
    {
        cout << "Rectangle class area :" << endl;
        return (width * height);
    }
    void showtype() {
        cout << "三角形" << endl;
    }
};
class Triangle : public Shape {
public:
    Triangle(int a = 0, int b = 0) :Shape(a, b) { }
    int area()
    {
        cout << "Triangle class area :" << endl;
        return (width * height / 2);
    }
    void showtype() {
        cout<<"长方形" << endl;
    }
};

// 程序的主函数
int main()
{
    Shape* shape;
    Rectangle rec(10, 7);
    Triangle  tri(10, 5);
    
    // 存储矩形的地址
    shape = &rec;//父类的引用指向子类对象，Cpp中父类与子类不需要强制转换类型
    // 调用矩形的求面积函数 area
    shape->area();
    shape->showtype();
    // 存储三角形的地址
    shape = &tri;
    // 调用三角形的求面积函数 area
    shape->area();
    shape->showtype();

    return 0;
}