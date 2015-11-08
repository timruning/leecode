// BinaryTreePreorderTraversal.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> anwser;
		if (root == NULL){
			return anwser;
		}
		if (root->left == NULL&&root->right == NULL){
			anwser.push_back(root->val);
			return anwser;
		}
		vector<int> left = preorderTraversal(root->left);
		vector<int> right = preorderTraversal(root->right);
		anwser.push_back(root->val);
		anwser.insert(anwser.end(), left.begin(), left.end());
		anwser.insert(anwser.end(), right.begin(), right.end());
		return anwser;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

