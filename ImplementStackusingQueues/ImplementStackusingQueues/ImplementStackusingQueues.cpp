// ImplementStackusingQueues.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<vector>
using namespace std;
class Queue{
private:
	vector<int> queue;
public:
	void push(int x) {
		queue.push_back(x);
	}
	void pop(){
		if (queue.size() != 0){
			queue.erase(queue.begin());
		}
	}
	int getfront() {
		int i;
		if (queue.size() != 0)
		{
			i = queue[0];
		}
		return i;
	}
	bool isEmpty(){
		if (queue.size()==0)
			return true;
		else
			return false;
	}
};
class Stack {
	Queue queue1;
	Queue queue2;
public:
	// Push element x onto stack.
	void push(int x) {
		if (queue1.isEmpty()){
			queue1.push(x);
		}
		else{
			while (queue1.isEmpty() == false){
				int k = queue1.getfront();
				queue1.pop();
				queue2.push(k);
			}
			queue1.push(x);
			while (queue2.isEmpty() == false){
				int k = queue2.getfront();
				queue2.pop();
				queue1.push(k);
			}
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		if (queue1.isEmpty() == false){
			queue1.pop();
		}
	}

	// Get the top element.
	int top() {
		if (queue1.isEmpty() == false){
			return queue1.getfront();
		}
	}

	// Return whether the stack is empty.
	bool empty() {
		if (queue1.isEmpty()==true)
			return true;
		else
			return false;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

