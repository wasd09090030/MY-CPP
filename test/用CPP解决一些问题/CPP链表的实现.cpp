#include <iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;

	ListNode(int x) : val(x), next(nullptr) {}

	ListNode() : val(0), next(nullptr) {}
};


//ʵ��������
class Linklist {

private:
	ListNode* headnode;

public:
	//�޲ι���
	Linklist():headnode(nullptr){}
	//�вι���
	Linklist(int data) : headnode(nullptr) { insert(data); }
	
	
	//���뺯��
	void insert(int data) {

		ListNode* newnode = new ListNode(data);

		if (headnode == nullptr)
			headnode = newnode;

		else {
			//ʹ����ʱָ��
			ListNode* tmp = headnode;
			//���������ҵ��սڵ�
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = newnode;
		}

	}


	//ʵ��ɾ������
	void erase(int key){
		ListNode* tmp = headnode;
		//prenode ���ڼ�¼tmpǰһ����
		ListNode* prenode = nullptr;
		//�������Ϊ��
	    if(tmp==nullptr)
		{
			cout << "����Ϊ��" << endl;
			//ʹ��return ��ǰ��������
			return;
		}

		//���ͷ�ڵ������Ҫɾ����
		if (tmp != nullptr && tmp->val == key) {
			//ͷ�ڵ�ָ���¸��ڵ�
			headnode = tmp->next;
			delete tmp;
			return;
		}

		while (tmp != nullptr && tmp->val != key) {
			prenode = tmp;
			tmp = tmp->next;			
		}

		if (tmp == nullptr) {
			cout << "not find" << endl;
			return;
		}
		else {
			//tmpǰһ�����nextָ�� tmp->next
			prenode->next = tmp->next;
			delete tmp;
		}


	}


	//ʵ�ִ�ӡ����
	void printList() {
		ListNode* temp = headnode;
		while (temp != nullptr) {
			cout << temp->val<< " -> ";
			temp = temp->next;
		}
		cout << "nullptr" << endl;
	}

};



int main() {
	
	Linklist ss;

	ss.insert(6);
	ss.insert(7);
	ss.insert(9);

	ss.printList();

	ss.erase(7);
	ss.printList();


	return 0;

}
