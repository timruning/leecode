// LinkedListCycle.cpp : 定义控制台应用程序的入口点。
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
	bool hasCycle(ListNode *head) {
		ListNode* p = head;
		ListNode* q = p;
		bool kaishi = false;
		while (p != NULL&&q != NULL){
			
			q = q->next;
			if (q == NULL){
				return false;
			}
			q = q->next;
			if (q == NULL){
				return false;
			}
			p = p->next;
			if (p == NULL){
				return false;
			}
			if (p == q){
				return true;
			}
		}
		return false;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

