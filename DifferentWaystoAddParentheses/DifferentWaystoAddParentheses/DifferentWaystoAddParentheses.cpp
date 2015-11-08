// DifferentWaystoAddParentheses.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
class StackNode
{
public:
	char val;
	StackNode* next;
	StackNode(){}
	StackNode(char x) :val(x), next(NULL){}

};
class Stack{
public:
	StackNode* top;
	Stack(){
		top = 0;
	}
	StackNode* getTop(){
		return top;
	}
	void push(StackNode* stacknode){
		stacknode->next = top;
		top = stacknode;
	}
	void pop(){
		StackNode* p = top;
		top = top->next;
		delete p;
	}
	bool empty(){
		if (top == 0)
			return true;
		else
			return false;
	}

};
/*
class Solution {
public:
vector<int> diffWaysToCompute(string input) {
Stack s1;
Stack s2;
string v="";
for (char var : input){
StackNode* p;
p = new StackNode();
p->val = var;
s1.push(p);
}
}
};
*/

int _tmain(int argc, _TCHAR* argv[])
{
	Stack s1;
	Stack s2;
	string v = "";
	string input = "123456789";
	for (char var : input){
		StackNode* p;
		p = new StackNode();
		p->val = var;
		s1.push(p);
	}
	s1.pop();
	while (!s1.empty()){
		cout << s1.getTop()->val ;

		s1.pop();
	}
	cout << endl;
	return 0;
}

