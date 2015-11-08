// RemoveNthNodeFromEndofList.cpp : 定义控制台应用程序的入口点。
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int count = 0;
		ListNode* p = head;
		if (n == 0){
			return head;
		}
		while (p != NULL){
			count++;
			p = p->next;
		}
		if (n > count){
			return head;
		}
		if (n == count){
			ListNode* t = head;
			head = head->next;
			delete t;
			return head;
		}
		p = head;
		int i = 0;
		while (i < count-n-1){
			i++;
			p = p->next;
		}
//		ListNode* q = p->next;
		p->next = p->next->next;
//		delete q;
		return head;
	}
};
ListNode* turnToList(int a[], int n){
	ListNode* head = NULL;
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
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	ListNode* head = turnToList(a, sizeof(a) / sizeof(a[0]));
	Solution sol;
	head = sol.removeNthFromEnd(head, 9);
	ListNode* p = head;
	while (p!=NULL){
		cout << p->val << endl;
		p = p->next;
	}
	return 0;
}

