// MergeTwoSortedLists.cpp : 定义控制台应用程序的入口点。
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL){
			return l2;
		}
		if (l2 == NULL){
			return l1;
		}
		ListNode* p1 = l1->val < l2->val ? l1 : l2;
		ListNode* p2 = l2->val > l1->val ? l2 : l1;
		ListNode* head = p1;
		ListNode* t1=p1;
		while (p1 != NULL){
			if (p1->val <= p2->val){
				t1 = p1;
				p1 = p1->next;
			}
			else{
				t1->next = p2;
				p2 = p1;
				p1 = t1->next;
			}
		}
		if (p2 != NULL){
			t1->next = p2;
		}
		return head;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	ListNode *p1 = new ListNode(5);
	ListNode *p2 = new ListNode(1);
	ListNode *pp2 = new ListNode(2);
	ListNode *ppp2 = new ListNode(4);
	p2->next = pp2;
	pp2->next = ppp2;
	Solution solution;
	ListNode *t = solution.mergeTwoLists(p1, p2);
	while (t != NULL){
		cout << t->val << endl;
		t = t->next;
	}
	return 0;
}

