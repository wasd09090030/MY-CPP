#include<iostream>;
#include<iomanip>;

using namespace std;

int main() {
	//left左对齐，right右对齐
	//setw（n）代表输出N个字符，如字符数量不足N，则剩余部分输出空格
	cout << left << setw(10) << "Student" << setw(10) << "number" << endl;
	cout << left << setw(10) << "TOM" << setw(10) << 20 << endl;
	cout << left << setw(10) << "Tex" << setw(10) << 40 << endl;

	//下面是学号右对齐
	cout << left << setw(10) << "Tex" << setw(10) << right<<40 << endl;

	//上一行最后的rigth对后面所有输出都有影响
	cout << setw(10) << "Tss";

	return 0;
}