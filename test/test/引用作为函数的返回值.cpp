#include<iostream>
#include<vector>
using namespace std;

int& res() {
	int a = 10;//�ֲ�������ִ���꺯��������
	return a;
}


static int& res2() {
	static int b = 10;
	return b;
}

int main() {

	int& s = res();
	

	cout << s << endl;

	cout << s << endl;
	
	int& s2 = res2();

	cout << s2 << endl;


	return 0;
}