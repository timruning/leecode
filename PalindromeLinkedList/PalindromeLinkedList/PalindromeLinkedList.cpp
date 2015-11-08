// PalindromeLinkedList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
	ListNode(){
		val = -1;
		next = NULL;
	}
};
ListNode* arrayToListNode(int a[],int n){
	static ListNode* head;
	head = new ListNode();
	head->val = a[0];
	ListNode* p = head;
	for (int i = 1; i < n; i++){
		p->next = new ListNode();
		p = p->next;
		p->val = a[i];
	}
	return head;
}
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL){
			return true;
		}
		if (head->next->next == NULL)
		{
			return head->val == head->next->val;
		}
		ListNode* p1 = head;
		ListNode* t1 = head;
		ListNode* p2 = p1->next;
		ListNode* p3 = p2->next;
		while ( t1->next != NULL){
			if (t1->next->next == NULL)
				break;
			t1 = t1->next->next;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
			p3 = p3->next;
		}
		head->next = NULL;
		if (t1->next == NULL){
			p1 = p1->next;
			while (p1 != NULL&&p2 != NULL){
				if (p1->val != p2->val){
					return false;
				}
				p1 = p1->next;
				p2 = p2->next;
			}
			return true;
		}
		if (t1->next->next == NULL){
			while (p1 != NULL&&p2 != NULL){
				if (p1->val != p2->val){
					return false;
				}
				p1 = p1->next;
				p2 = p2->next;
			}
			return true;
		}
		
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 1,0,0};
	ListNode* head = arrayToListNode(a, 3);
	ListNode* p = head;
	while (p != NULL){
		cout << p->val << endl;
		p = p->next;
	}
	Solution solution;
	if (solution.isPalindrome(head)==true){
		cout << "true" << endl;
	}
	else
		cout << "error" << endl;
	return 0;
}

