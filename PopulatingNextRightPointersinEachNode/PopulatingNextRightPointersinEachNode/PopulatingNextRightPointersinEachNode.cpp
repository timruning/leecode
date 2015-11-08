// PopulatingNextRightPointersinEachNode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
 struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution {
public:
	void connect(TreeLinkNode *root) {
		vector<TreeLinkNode*> vec;
		
		if (root == NULL){
			return;
		}
		vec.push_back(root);
		int count = 1;
		while (vec.size() != 0){
			int jcount = 0;
			for (int i = 0; i < count; i++){
				if (i < count - 1){
					vec[0]->next = vec[1];
				}
				if (vec[0]->left != NULL){
					vec.push_back(vec[0]->left);
					jcount++;
				}
				if (vec[0]->right != NULL){
					vec.push_back(vec[0]->right);
					jcount++;
				}
				vec.erase(vec.begin());
			}
			count = jcount;
		}
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	TreeLinkNode* t1 = new TreeLinkNode(0);
	TreeLinkNode* t2 = new TreeLinkNode(1);
	TreeLinkNode* t3 = new TreeLinkNode(2);
	TreeLinkNode* t4 = new TreeLinkNode(3);
	TreeLinkNode* t5 = new TreeLinkNode(4);
	TreeLinkNode* t6 = new TreeLinkNode(5);
	TreeLinkNode* t7 = new TreeLinkNode(6);
	t1->left = t2;
	t1->right = t3;
	t2->left = t4;
	t2->right = t5;
	t3->left = t6;
	t3->right = t7;
	Solution sol;
	sol.connect(t1);
	return 0;
}

