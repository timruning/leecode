// InvertBinaryTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
struct TreeNode {
    int val;
    TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL){
			return root;
		}
		if (root->left == NULL&&root->right == NULL){
			return root;
		}
		TreeNode* test = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(test);
		return root;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

