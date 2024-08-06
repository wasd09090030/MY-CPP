#include <iostream>

using namespace std;

int main()
{
	char site[7] = { 'R', 'U', 'N', 'O', 'O', 'B', '\0' };
	//Array 直接初始化 char 数组是特殊的,这种初始化要记得字符是以一个 null 结尾的

	cout << site << endl;

	char ss[2] = { 'd','d' };

	cout << ss << endl;
	//ss输出会出现乱码

	return 0;
}