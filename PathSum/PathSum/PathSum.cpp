// PathSum.cpp : 定义控制台应用程序的入口点。
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
	bool hasPathSum(TreeNode* root, int sum) {
		TreeNode* p = root;
		if (p == NULL){
			return false;
		}
		if (p->val == sum&&(p->left==NULL||p->right==NULL)){
			return true;
		}
		int t = p->val;
		if (hasPathSum(p->left, sum - t) || hasPathSum(p->right, sum - t)){
			return true;
		}
		else{
			return false;
		}
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

