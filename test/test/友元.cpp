#include<iostream>
using namespace std;
#include<string>


//�����ƻ���װ
class Pclass {
	//��Ԫ���Է���˽�г�Ա
	//��Ԫ����
	friend void build2(Pclass* PP);
	//��Ԫ��
	friend class Pclasd;
	//��Ա��������Ԫ
	friend void Pclassad::visit();

public:
	Pclass() {
		room = "asd";
		classroom = "dasd";
	}


private:

	string classroom;

public:
	string room;
};

class Pclasd {

	Pclass dsa;

	void visit() {
		cout << "���Է���" <<dsa.classroom<< endl;
	}
};


class Pclassad {

	Pclass dsa;

public:
	void visit1() {
		cout << "���Է���" << dsa.classroom << endl;
	}
	void visit() const;
};




void Pclassad::visit() const {
	cout << "���Է���" << dsa.classroom << endl;
}


//ȫ�ֺ���
void build(Pclass* PP) {
	cout << "���ڷ���ȫ�ֺ���" << PP->classroom<<endl;
}
//�ɷ���˽�г�Ա
void build2(Pclass* PP) {
	cout << "���ڷ���ȫ�ֺ���" << PP->classroom << endl;
}


int main() {

	Pclass ps;
	build(&ps);
}

