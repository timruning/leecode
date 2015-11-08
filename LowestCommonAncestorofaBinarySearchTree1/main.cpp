// LowestCommonAncestorofaBinarySearchTree.cpp : 定义控制台应用程序的入口点。
//

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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode *str = root;


		if (p->val > q->val){
			int k = p->val;
			p->val = q->val;
			q->val = k;
			//return lowestCommonAncestor(root, q, p);
		}
		cout<<p->val<<endl;
		cout<<q->val<<endl;
		if (str->val >= p->val&&str->val <= q->val){
			return str;
		}
		while ((str->val) < p->val || (str->val) > q->val){

			if (str->val < p->val){
				str = str->right;
			}
			else
				if (str->val > q->val){
					str = str->left;
				}
			if (str->val >= p->val&&str->val <= q->val){
				return str;
			}
		}
		return str;
	}
};
int main()
{
	TreeNode p1(1);
	TreeNode p2(2);
	TreeNode t1(2);

	TreeNode t2(1);
/*	TreeNode t3(8);
	TreeNode t4(0);

	TreeNode t5(4);
	TreeNode t6(7);
	TreeNode t7(9);
	TreeNode t8(3);
	TreeNode t9(5);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;*/
	t1.left = &t2;
	//t6.right = &t9;
	Solution solution;
	TreeNode* fa= solution.lowestCommonAncestor(&t1, &p1, &p2);
	cout << fa->val << endl;
	return 0;
}

