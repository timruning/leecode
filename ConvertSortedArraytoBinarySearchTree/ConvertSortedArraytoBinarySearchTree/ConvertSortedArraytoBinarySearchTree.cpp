// ConvertSortedArraytoBinarySearchTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		
		if (nums.size() <= 0){
			return NULL;
		}
		TreeNode* root = new TreeNode(nums[nums.size() / 2]);
		if (nums.size() == 1)
		{
			return root;
		}
		vector<int> numsleft(nums.begin(), nums.begin() + nums.size() / 2);
		vector<int> numsright(nums.begin() + nums.size() / 2+1, nums.end());
		TreeNode* left = sortedArrayToBST(numsleft);
		TreeNode* right = sortedArrayToBST(numsright);
		root->left = left;
		root->right = right;
		return root;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec = { 1, 2, 3, 4, 5, 6 ,7};
	Solution sol;
	TreeNode* root = sol.sortedArrayToBST(vec);
	cout << root->val << endl;
	return 0;
}

