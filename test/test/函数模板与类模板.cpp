#include<iostream>
using namespace std;
#include<string>

//������JAVA�ķ���
template<typename T>
void Myswap(T& a, T& b) {

	T c = a;
	a = b;
	b = c;
 }

//��ģ�������в���
template<class TypeAge,class TypeName>
class Person {
public:
	TypeAge age;
	TypeName name;

	Person(TypeAge mage, TypeName mname) {
		this->age = mage;
		this->name = mname;
	}

	void showPerson() {
		cout << "name : " << name << endl;
		cout << "age: " << age << endl;
	}
};


//���Ҫ�̳���ģ��ĸ��࣬�������ָ��T����
class sa :public Person<int, string> {};

//�����Ҫ�������T����ô����Ҳ��������ģ��
template<class T1, class T2>
class sa2 :public Person<T1, T2> {};


//��ģ���뺯��ģ�������

//��ģ����Ϊ��������
template<class P>
void show(P& s) {
	s.showPerson();
}


void test() {
	Person ss(19, "TOM");
	show(ss);
}

int main() {

	int a = 9, b = 8;

	char s1 = 's';
	char s2 = '2';

	Myswap(a, b);
	Myswap(s1, s2);

	
	cout << "a" << "= " << a<<endl;
	cout << "b" << "= " << b << endl;
	cout << "s1" << "= " << s1 << endl;
	cout << "s2" << "= " << s2 << endl;

	test();

	return 0;
}