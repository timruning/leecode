// IntersectionofTwoLinkedLists.cpp : 定义控制台应用程序的入口点。
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
	ListNode *reverseList(ListNode *head){
		ListNode* p = head;
		if (p == NULL){
			return p;
		}
		ListNode* q = p->next;
		p->next = NULL;
		if (q == NULL)
			return p;
		while (q->next != NULL){
			ListNode* r = q->next;
			q->next = p;
			p = q;
			q = r;
		}
		q->next = p;
		head = q;
		return head;
	}
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL)
			return NULL;
		ListNode* p = reverseList(headA);
		ListNode* q = reverseList(headB);
		ListNode* t = NULL;
		while (p != NULL&&q != NULL){
			if (p->val == q->val){
				t = p;
				p = p->next;
				q = q->next;
			}
			else{
				return t;
			}
		}
		return t;
	}
};
ListNode* turnToList(int a[], int n){
	ListNode* head=NULL;
	if (n == 0){
		return head;
	}
	head = new ListNode(a[0]);
	ListNode *p = head;
	for (int i = 1; i < n; i++){
		ListNode *t = new ListNode(a[i]);
		p->next = t;
		p = p->next;
	}
	return head;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a[22] = { 1, 3, 5, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 };
	int b[17] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 };
	ListNode *headA = turnToList(a, 22);

	ListNode *headB = turnToList(b, 17);
	Solution sol;
//	headA = sol.reverseList(headA);
//	while (headA != NULL){
//		cout << headA->val << endl;
//		headA = headA->next;
//	}
	ListNode* p = sol.getIntersectionNode(headA,headB);
	if (p == NULL){
		cout << "no" << endl;
	}
	else{
		cout << p->val << endl;
	}
	
	return 0;
}

