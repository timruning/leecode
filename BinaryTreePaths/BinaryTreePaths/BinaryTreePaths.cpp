// BinaryTreePaths.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Stack{
	vector<TreeNode> vecStack;
public:
	TreeNode getTop(){
		if (vecStack.size() != 0)
			return vecStack[vecStack.size() - 1];
	}
	void push(TreeNode s){
		vecStack.push_back(s);
	}
	void pop(){
		if (vecStack.size()>0)
		vecStack.pop_back();
	}
	bool Empty(){
		if (vecStack.size() == 0)
			return true;
		else
			return false;
	}
};

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		TreeNode *sroot = root;
		Stack stack;
		string vecs;
		vector<string> vecstr;
		while (sroot != NULL){
			if (sroot == root){
				int val1 = sroot->val;
				vecs = intToString(val1);
			}
			else{
				int val1 = sroot->val;
				vecs += intToString(val1);
			}
			stack.push(*sroot);
			sroot = sroot->left;
		}
		vecstr.push_back(vecs);
		return vecstr;
	}
	string intToString(int n){
		char buf[256];
		sprintf_s(buf, "%d", n);
		string s = buf;
		return s;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode t(1);
	TreeNode *root;
	root = &t;
	TreeNode t1(3);
	root->left = &t1;
	TreeNode t2(6);
	root->left->right = &t2;
	vector<string> vc;
	Solution a;
	vc = a.binaryTreePaths(root);
	cout << vc[0] << endl;
}

