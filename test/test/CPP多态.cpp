#include <iostream> 
using namespace std;


//���³�������
//Parent class area :
//Parent class area :

//��int area()ǰ�����Virual
//��ʱ��������������ָ������ݣ��������������͡���ˣ����� tri �� rec ��Ķ���ĵ�ַ�洢�� *shape �У����Ի���ø��Ե� area() ������
//�������������ģ�ÿ�����඼��һ������ area() �Ķ���ʵ�֡�����Ƕ�̬��һ��ʹ�÷�ʽ
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
};
class Rectangle : public Shape {
public:
    Rectangle(int a = 0, int b = 0) :Shape(a, b) { }
    int area()
    {
        cout << "Rectangle class area :" << endl;
        return (width * height);
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
};
// �����������
int main()
{
    Shape* shape;
    Rectangle rec(10, 7);
    Triangle  tri(10, 5);

    // �洢���εĵ�ַ
    shape = &rec;
    // ���þ��ε���������� area
    shape->area();

    // �洢�����εĵ�ַ
    shape = &tri;
    // ���������ε���������� area
    shape->area();

    return 0;
}