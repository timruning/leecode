// Trie.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<set>
#include<vector>
#include<iostream>
using namespace std;
class TreeNode
{
public:
	char var;
	vector<TreeNode* > child;
	TreeNode(char x) :var(x){};
	~TreeNode();
	
};
TreeNode* Trie(vector<string> vecstr){
	TreeNode* root = new TreeNode('+');
	TreeNode* p = root;
	p->child.push_back(root);
	return root;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector < string > vec= {"sdf", "sfg"};
	TreeNode* t = Trie(vec);
	return 0;
}

