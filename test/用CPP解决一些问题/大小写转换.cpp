
//������ĸ��ASCII�����ת������Ӧ��Сд��ĸ֮�����32


#include <iostream>

using namespace std;

int main()
{
	char a[20];
	int i = 0;
	cout << "������һ���ַ�:\n";
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


//�����������ú�����

/*public:
    string toLowerCase(string str) {
        for (auto &i : str) {
            if (isupper(i))
              i = tolower(i);
        }
        return str;
    }*/