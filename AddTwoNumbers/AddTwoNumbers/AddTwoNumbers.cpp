// AddTwoNumbers.cpp : 定义控制台应用程序的入口点。
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		ListNode* p3 = p1;
		int k=0;
		while (p1 != NULL||p2 != NULL){
			if (p1 != NULL&&p2!=NULL){
				p1->val = p1->val + p2->val;
				p1->val += k;
				k = p1->val / 10;
				p1->val %= 10;
				p3 = p1;
				p1 = p1->next;
				p2 = p2->next;
			}else
				if (p1 != NULL){
					p1->val += k;
					k = p1->val / 10;
					p1->val %= 10;
					p3 = p1;
					p1 = p1->next;
				}else
					if (p2 != NULL){
						p2->val += k;
						k = p2->val / 10;
						p2->val %= 10;
						p3->next = p2;
						p3 = p2;
						p2 = p2->next;
					}
		}
		if (k != 0){
			ListNode* kp = new ListNode(k);
			p3->next = kp;
		}
		return l1;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	ListNode *t1;
	t1 = new ListNode(0);
	ListNode *p1;
	p1 = new ListNode(7);
	ListNode *p2;
	p2 = new ListNode(3);
	//ListNode *p3;
	//p3 = new ListNode(4);
	p1->next = p2;
	//p2->next = p3;
	Solution solution;
	ListNode *p = solution.addTwoNumbers(t1, p1);
	while (p != NULL){
		cout << p->val << endl;
		p = p->next;
	}
	return 0;
}

