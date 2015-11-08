// BinaryTreePathsTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution {
public:
	string intToString(int k){
		char buf[256];
		sprintf_s(buf, "%d", k);
		string s = buf;
		return s;
	}
	string toStringQueue(vector<TreeNode*>& queue1){
		string re;
		if (queue1.size()>0){
			int k = queue1[0]->val;
			string ks = intToString(k);
			re = ks;
			if (queue1.size() > 1){
				for (int i = 1; i < queue1.size(); i++){
					int ki = queue1[i]->val;
					string kis = intToString(ki);
					re = re + "->" + kis;
				}
			}
		}
		return re;
	}
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<TreeNode*> queue;
		TreeNode *sroot = root;
		vector<string> vecstr;
		if (root== NULL)
			return vecstr;
		while ((sroot->left != NULL||sroot->right!=NULL)&&sroot!=NULL){
			queue.push_back(sroot);
			//sroot = sroot->left;
			if (sroot->left != NULL){
				sroot = sroot->left;
			}
			else
				sroot = sroot->right;
		}
		if (sroot!=NULL)
		queue.push_back(sroot);
		TreeNode *p=root;
		while (p->right != NULL||p->left!=NULL){
			if (p->right != NULL){
				p = p->right;
			}
			else{
				p = p->left;
			}
		}
		while (queue.size()>0){
			vecstr.push_back(toStringQueue(queue));
			if (p == queue[queue.size()-1])
				break;
			if (queue.size() > 1){
				/*if (queue.size()>2 && (queue[queue.size() - 2]->left == queue[queue.size() - 1]))
				queue.pop_back();
				else
				{
					while (((queue[queue.size() - 2]->right == queue[queue.size() - 1])||())&&queue.size()>0){
						queue.pop_back();
					}
				}*/

				if (queue.size()==2)
					queue.pop_back();

				if (queue.size() > 2){
					int count = 1;
					while (queue[queue.size() - count-1]->right == NULL || queue[queue.size() - count-1]->right == queue[queue.size() -count]){
						count++;
					}
					queue.erase(queue.end() - count, queue.end());
				}

				sroot = queue[queue.size() - 1]->right;
				while ((sroot->left != NULL || sroot->right != NULL)&&sroot!=NULL){
					queue.push_back(sroot);
					//sroot = sroot->left;
					if (sroot->left != NULL){
						sroot = sroot->left;
					}
					else
						sroot = sroot->right;
				}
				if (sroot != NULL){
					queue.push_back(sroot);
				}
			
			}
		}
		return vecstr;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode t1(1);
	TreeNode t2(2);
	TreeNode t3(3);
	TreeNode t4(4);
	TreeNode t5(5);
	TreeNode t6(6);
//	TreeNode t7(7);
//	TreeNode t8(8);
	t1.right = &t4;
	t4.left = &t3;
	
//	t4.left = &t7;
//	t4.right = &t8;
	t4.right = &t5;
	t3.left=&t2;
	t5.right = &t6;
	Solution a;
	vector<string> vec;
	vec = a.binaryTreePaths(&t1);
	for (auto i : vec)
		cout << i << endl;
	return 0;
}

