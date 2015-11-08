// MinimumDepthofBinaryTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int minDepth(TreeNode* root) {
		TreeNode* p = root;
		if (p == NULL){
			return 0;
		}
		if (p->left == NULL&&p->right == NULL){
			return 1;
		}
		if ((p->left != NULL&&p->left->left == NULL&&p->left->right == NULL) ||
			(p->right != NULL&&p->right->left == NULL&&p->right->right == NULL)){
			return 2;
		}
		int t = 0;
		int t1 = minDepth(p->left);
		int t2 = minDepth(p->right);
		if (t1 == 0)
			return t2 + 1;
		if (t2 == 0)
			return t1 + 1;
		t = t1 < t2 ? t1 : t2;
		return t+1;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);
	t1->left = t2;
	t2->left = t3;
	t3->left = t4;
	t4->left = t5;
	Solution sol;
	int k = sol.minDepth(t1);
	cout << k << endl;
	return 0;
}

