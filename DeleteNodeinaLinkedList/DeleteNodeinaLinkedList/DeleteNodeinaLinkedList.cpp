// DeleteNodeinaLinkedList.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

	void deleteNode(ListNode* node) {
		ListNode t=*(node->next);
			node = &t;

	}
};
class List{
public:
	ListNode *head;

};
int _tmain(int argc, _TCHAR* argv[])
{
	List list;
	
	ListNode t1(0);
	ListNode t2(1);
	t1.next = &t2;
	list.head = &t1;
	Solution a;
	a.deleteNode(&t1);
	ListNode *p = list.head;
	while (p != NULL){
		cout << p->val << endl;
		p = p->next;
	}
	return 0;
}

