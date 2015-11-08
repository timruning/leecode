// ReverseLinkedList.cpp : 定义控制台应用程序的入口点。
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
	ListNode* reverseList(ListNode* head) {
		ListNode* p = head;
		if (p == NULL)
			return p;
		ListNode* q = p->next;
		if (q == NULL){
			return p;
		}
		while (q->next != NULL){
			ListNode* r = q->next;
			q->next = p;
			p = q;
			q = r;
		}
		if (q != NULL&&q->next == NULL){
			q->next = p;
		}
		head->next = NULL;
		head = q;
		return head;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	ListNode l1(1);
	ListNode l2(2); 
//	ListNode l3(3);
//	ListNode l4(4);
//	ListNode l5(5);
//	ListNode l6(6);
//	ListNode l7(7);
//	ListNode l8(8);
//	ListNode l9(9);
	//ListNode l1(1);
	//ListNode l2(2);
	//ListNode l3(3);
	l1.next = &l2;
//	l2.next = &l3;
//	l3.next = &l4;
//	l4.next = &l5;
//	l5.next = &l6;
//	l6.next = &l7;
//	l7.next = &l8;
//	l8.next = &l9;
	Solution sol;
	ListNode*t= sol.reverseList(&l1);
	while (t != NULL){
		cout << t->val << endl;
		t = t->next;
	}
	return 0;
}

