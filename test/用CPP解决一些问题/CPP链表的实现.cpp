#include <iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;

	ListNode(int x) : val(x), next(nullptr) {}

	ListNode() : val(0), next(nullptr) {}
};


//实现链表功能
class Linklist {

private:
	ListNode* headnode;

public:
	//无参构造
	Linklist():headnode(nullptr){}
	//有参构造
	Linklist(int data) : headnode(nullptr) { insert(data); }
	
	
	//插入函数
	void insert(int data) {

		ListNode* newnode = new ListNode(data);

		if (headnode == nullptr)
			headnode = newnode;

		else {
			//使用临时指针
			ListNode* tmp = headnode;
			//遍历链表找到空节点
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = newnode;
		}

	}


	//实现删除功能
	void erase(int key){
		ListNode* tmp = headnode;
		//prenode 用于记录tmp前一个点
		ListNode* prenode = nullptr;
		//如果链表为空
	    if(tmp==nullptr)
		{
			cout << "链表为空" << endl;
			//使用return 提前结束函数
			return;
		}

		//如果头节点就是需要删除的
		if (tmp != nullptr && tmp->val == key) {
			//头节点指向下个节点
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
			//tmp前一个点的next指向 tmp->next
			prenode->next = tmp->next;
			delete tmp;
		}


	}


	//实现打印功能
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
