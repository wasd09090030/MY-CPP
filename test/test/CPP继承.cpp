#include <iostream>

using namespace std;

// ����
class Shape
{
public:

    Shape() {
        cout << "����һ��ͼ��" << endl;
    }
    ~Shape() {
        cout << "����һ��ͼ��" << endl;
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
        cout << "���ø��ຯ��" << endl;
    }

    int width=0;
    int height=0;
};

// ������
class Rectangle :virtual public Shape
{
public:

    Rectangle() {
        cout << "����һ��������" << endl;
    }
    ~Rectangle() {
        cout << "����һ��������" << endl;
    }
    int getArea()
    {
        return (width * height);
    }

    void func() {
        cout << "�������ຯ��" << endl;
    }

  
};


class Cube:virtual public Shape{
public:
    
};

//�������μ̳У�cube��rectangle����width
//final���̳�����width����˷�.��Ҫvirtual�ؼ���

class final:public Cube,public Rectangle{
  public:
    
};

int main(void)
{
    //�ȴ��츸�࣬�ٴ�������
    Rectangle Rect;
    //���������࣬�����ٸ���


    //���������ʹ�û���ķ���
    Rect.setWidth(5);
    Rect.setHeight(7);

    // �����������
    cout << "Total area: " << Rect.getArea() << endl;

    cout <<"�����Ԫ��"<< Rect.width << endl;
    //����Ҫͨ��������ʸ����Ԫ�أ���Ҫָ��������
    cout << "�����Ԫ��" << Rect.Shape::width << endl;

    //����ͬ������
    Rect.func();
    Rect.Shape::func();

    final ss;

    ss.Rectangle::width = 44;
    ss.Cube::width = 66;
    //��Ϊ66������virtual�ؼ��ֺ󣬴��ݵ�ʵ����ָ��
    cout << ss.Rectangle::width << endl;
    cout << ss.Cube::width << endl;
    cout << ss.width << endl;
    return 0;
}