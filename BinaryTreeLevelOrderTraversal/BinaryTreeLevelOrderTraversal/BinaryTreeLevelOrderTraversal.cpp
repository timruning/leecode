// BinaryTreeLevelOrderTraversal.cpp : 定义控制台应用程序的入口点。
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		TreeNode* p = root;
		vector<vector<int>> anwser;
		if (p == NULL){
			return anwser;
		}
		vector<TreeNode* > vecTree;
		vecTree.push_back(p);
		int count = 0;
		while (vecTree.size() > 0){
			vector<int> vec;
			int vsize = vecTree.size();
			int q = count;
			count = 0;
			for (int i = 0; i < vsize - q; i++){
				if (vecTree[i]->left != NULL){
					vecTree.push_back(vecTree[i]->left);
					count++;
				}
				if (vecTree[i]->right != NULL){
					vecTree.push_back(vecTree[i]->right);
					count++;
				}
			}
			for (int i = 0; i < vsize - q; i++){
				vec.push_back(vecTree[i]->val);
			}
			vecTree.erase(vecTree.begin(),vecTree.begin() + vsize - q);
			if (vec.size()>0)
				anwser.push_back(vec);
		}
		return anwser;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

