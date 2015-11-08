// MinStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
class MinStack {
	vector<int> stack;
	int k;
	bool have=false;
public:
	void push(int x) {
		if (stack.size() == 0){
			k = x;
			have = true;
		}
		else{
			k = k < x ? k : x;
		}
		stack.push_back(x);
	}

	void pop() {
		if (k == *stack.rbegin()){
			if (stack.size() > 1){
				k = stack[0];
				for (auto i = 0; i < stack.size() - 1;i++){
					k = k < stack[i] ? k : stack[i];
				}
			}
			else{
				have = false;
			}
		}
		stack.pop_back();
	}

	int top() {
		return *stack.rbegin();
	}

	int getMin() {
		int anwser;
		if (have){
			anwser = k;
		}
		return anwser;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	MinStack minStack;
	minStack.push(2);
	minStack.push(0);
	minStack.push(3);
	minStack.push(0);
	cout << minStack.getMin() << endl;
	minStack.pop();
	cout << minStack.getMin() << endl;
	minStack.pop();
	cout << minStack.getMin() << endl;
	minStack.pop();
	cout << minStack.getMin() << endl;
	return 0;
}

