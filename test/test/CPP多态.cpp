#include <iostream> 
using namespace std;


//���³�������
//Parent class area :
//Parent class area :

//��int area()ǰ�����Virual
//��ʱ��������������ָ������ݣ��������������͡���ˣ����� tri �� rec ��Ķ���ĵ�ַ�洢�� *shape �У����Ի���ø��Ե� area() ������
//�������������ģ�ÿ�����඼��һ������ area() �Ķ���ʵ�֡�����Ƕ�̬��һ��ʹ�÷�ʽ


//��̬��̬��������
//1.����̳и���
//2.������д������麯��


//�����࣬ӵ�д��麯������
//�ص㣺�޷�ʵ��������
//����������������д����Ĵ��麯��������Ҳ�ǳ�����
class Abstract {
    virtual void sa() = 0;//���麯��
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
    //�麯��,��󶨵�ַ
    virtual void showtype() {
        cout << "����״" << endl;
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
        cout << "������" << endl;
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
        cout<<"������" << endl;
    }
};

// �����������
int main()
{
    Shape* shape;
    Rectangle rec(10, 7);
    Triangle  tri(10, 5);
    
    // �洢���εĵ�ַ
    shape = &rec;//���������ָ���������Cpp�и��������಻��Ҫǿ��ת������
    // ���þ��ε���������� area
    shape->area();
    shape->showtype();
    // �洢�����εĵ�ַ
    shape = &tri;
    // ���������ε���������� area
    shape->area();
    shape->showtype();

    return 0;
}