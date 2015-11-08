// RemoveLinkedListElements.cpp : 定义控制台应用程序的入口点。
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
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* p = head;
		if (p == NULL){
			return p;
		}
		ListNode* headf = new ListNode(-1);
		headf->next = head;
		ListNode* t = headf;
		while (p != NULL){
			if (p->val == val){
				ListNode* q = p;
				t->next = p->next;
				p = p->next;
				delete q;
			}
			else{
				t = t->next;
				p = p->next;
			}
		}
		head = headf->next;
		return head;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	ListNode* t1 = new ListNode(10);
	ListNode* t2 = new ListNode(10);
	ListNode* t3 = new ListNode(10);
	ListNode* t4 = new ListNode(10);
	ListNode* t5 = new ListNode(1);
	ListNode* t6 = new ListNode(10);
	t1->next = t2;
	t2->next = t3;
	t3->next = t4;
	t4->next = t5;
	t5->next = t6;
	Solution sol;
	t1 = sol.removeElements(t1, 10);
	while (t1 != NULL){
		cout << t1->val << endl;
		t1 = t1->next;
	}
	return 0;
}

