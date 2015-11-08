// IntersectionofTwoLinkedLists1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		vector<int> vecA;
		vector<int> vecB;
		ListNode* p = headA;
		ListNode* q = headB;
		if (p == NULL || q == NULL){
			return NULL;
		}
		while (p != NULL){
			vecA.push_back(p->val);
			p = p->next;
		}
		while (q!=NULL)
		{
			vecB.push_back(q->val);
			q = q->next;
		}
		int count = 0;
//		bool have = false;
		for (int i = vecA.size() - 1, j = vecB.size() - 1; i >= 0, j >= 0; i--, j--){
			if (vecA[i] == vecB[j]){
				count++;
			}
			else{
//				have = true;
				break;
			}
		}
			p = headA;
			for (int i = 0; i < vecA.size() - count; i++){
				p = p->next;
			}
			return p;
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
	int a[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21 };
	int b[] = {2};
	ListNode* head1 = turnToList(a, sizeof(a)/sizeof(a[0]));
//	ListNode* head2 = turnToList(b, sizeof(b)/sizeof(b[0]));
	ListNode* head2=NULL;
	Solution sol;
	ListNode* p = sol.getIntersectionNode(head1, head2);
	if (p != NULL){
		cout << p->val << endl;
	}
	else{
		cout << "null" << endl;
	}
	return 0;
}

