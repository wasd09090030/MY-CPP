#include<iostream>
using namespace std;

//结构化绑定
//C++17新增
int main() {


	int values[3] = { 2,6,9 };

	auto [x, y, z] = values;
	//等同于
	//int x=v[0]
	//int y=v[1]
	//int z=v[2]

	cout << x << "  " << y << "  " << z;




}