
//根据字母的ASCII表进行转换，对应大小写字母之间相差32


#include <iostream>

using namespace std;

int main()
{
	char a[20];
	int i = 0;
	cout << "请输入一串字符:\n";
	cin >> a;
	for (; a[i]; i++)
	{
		if (a[i] >= 'a' && a[i] <= 'z')
			a[i] -= 32;
		else if (a[i] >= 'A' && a[i] <= 'Z')
			a[i] += 32;
	}
	for (i = 0; a[i]; i++)
		cout << a[i];
	cout << endl;

	system("pause");
	return 0;
}


//方法二，调用函数库

/*public:
    string toLowerCase(string str) {
        for (auto &i : str) {
            if (isupper(i))
              i = tolower(i);
        }
        return str;
    }*/