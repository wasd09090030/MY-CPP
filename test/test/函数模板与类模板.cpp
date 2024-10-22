#include<iostream>
using namespace std;
#include<string>

//类似于JAVA的泛型
template<typename T>
void Myswap(T& a, T& b) {

	T c = a;
	a = b;
	b = c;
 }

//类模板允许有参数
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


//如果要继承类模板的父类，子类必须指定T类型
class sa :public Person<int, string> {};

//如果需要灵活运用T，那么子类也必须是类模板
template<class T1, class T2>
class sa2 :public Person<T1, T2> {};


//类模板与函数模板的区别

//类模板作为参数传入
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