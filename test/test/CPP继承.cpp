#include <iostream>

using namespace std;

// 基类
class Shape
{
public:

    Shape() {
        cout << "创造一个图形" << endl;
    }
    ~Shape() {
        cout << "销毁一个图形" << endl;
    }
    void setWidth(int w)
    {
        width = w;
    }
    void setHeight(int h)
    {
        height = h;
    }

    void func() {
        cout << "调用父类函数" << endl;
    }

    int width=0;
    int height=0;
};

// 派生类
class Rectangle :virtual public Shape
{
public:

    Rectangle() {
        cout << "创造一个三角形" << endl;
    }
    ~Rectangle() {
        cout << "销毁一个三角形" << endl;
    }
    int getArea()
    {
        return (width * height);
    }

    void func() {
        cout << "调用子类函数" << endl;
    }

  
};


class Cube:virtual public Shape{
public:
    
};

//出现菱形继承，cube和rectangle都有width
//final类会继承两个width造成浪费.需要virtual关键字

class final:public Cube,public Rectangle{
  public:
    
};

int main(void)
{
    //先创造父类，再创造子类
    Rectangle Rect;
    //先销毁子类，在销毁父类


    //派生类可以使用基类的方法
    Rect.setWidth(5);
    Rect.setHeight(7);

    // 输出对象的面积
    cout << "Total area: " << Rect.getArea() << endl;

    cout <<"子类的元素"<< Rect.width << endl;
    //当需要通过子类访问父类的元素，需要指定作用域
    cout << "父类的元素" << Rect.Shape::width << endl;

    //调用同名函数
    Rect.func();
    Rect.Shape::func();

    final ss;

    ss.Rectangle::width = 44;
    ss.Cube::width = 66;
    //都为66，加上virtual关键字后，传递到实际是指针
    cout << ss.Rectangle::width << endl;
    cout << ss.Cube::width << endl;
    cout << ss.width << endl;
    return 0;
}