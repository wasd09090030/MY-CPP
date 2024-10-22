#include<iostream>
using namespace std;
#include<string>

class Person {

public:
	Person() {
		ma = 0;
		mb = 0;
	}
	Person(int a, int b) {
		ma = a;
		mb = b;
	}
	int ma;
	int mb;
};


Person operator+(Person& a, Person& b){
	Person c;
	c.ma = a.ma + b.ma;
	c.mb = a.mb + b.mb;
	return c;
}

int main() {
	Person a(10, 20);
	Person b(9, 2);

	Person x = a + b;

	cout << x.ma << "\\" << x.mb;
}