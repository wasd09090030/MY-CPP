#include<iostream>;
#include<iomanip>;

using namespace std;

int main() {
	//left����룬right�Ҷ���
	//setw��n���������N���ַ������ַ���������N����ʣ�ಿ������ո�
	cout << left << setw(10) << "Student" << setw(10) << "number" << endl;
	cout << left << setw(10) << "TOM" << setw(10) << 20 << endl;
	cout << left << setw(10) << "Tex" << setw(10) << 40 << endl;

	//������ѧ���Ҷ���
	cout << left << setw(10) << "Tex" << setw(10) << right<<40 << endl;

	//��һ������rigth�Ժ��������������Ӱ��
	cout << setw(10) << "Tss";

	return 0;
}