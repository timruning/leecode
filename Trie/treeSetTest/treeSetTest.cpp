// treeSetTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
using namespace std;

class TreeNode
{
public:
	char getVar(){
		return var;
	};
	map<char,TreeNode*> getChild(){
		return child;
	};
	void setVar(char a){
		var = a;
	}
	void addNode(TreeNode* T){
		child.insert(make_pair(T->var,T));
	};
	void eraseNode(TreeNode* T){
		child.erase(T->var);
	}
	TreeNode* find(char t){
		if (child.size() == 0)
			return NULL;
		auto iter = child.find(t);
		if (iter != child.end()){
			return iter->second;
		}
		else{
			return NULL;
		}
	};
	int childSize(){
		return child.size();
	}
	TreeNode(char x) :var(x){};
	~TreeNode(){
	};
private:
	char var;
	map<char,TreeNode* > child;
};
class Trie
{
public:
	TreeNode* newTreeNode(char a){
		TreeNode* p = new TreeNode(a);
		return p;
	}
	void deleteTreeNode(TreeNode* t){
		delete t;
	}
	void insert(string s);
	void erase(string s);
	Trie();
	~Trie();
private:
	TreeNode* root;
};

Trie::Trie()
{
	TreeNode* p = new TreeNode('+');
	root = p;
}
void Trie::insert(string s){
	TreeNode* p = root;
	for (auto var : s){
		if (p->find(var) != NULL){
			p = p->find(var);
		}
		else{
			TreeNode* T = newTreeNode(var);
			p->addNode(T);
			p = p->find(var);
		}
	}
}
void Trie::erase(string s){
	TreeNode* p = root;
	TreeNode* father = p;
	TreeNode* t = p;
	int i = 0;
	int count = 0;
	while (i < s.size()){
		TreeNode* iter = p->find(s[i]);
		if (iter!=NULL){
			if (p->childSize() > 1 && iter->childSize() == 1){
				father = p;
				t = iter;
				count = i;
			}
			p = iter;
		}
		else{
			return;
		}
		i++;
	}
	if (p->childSize() > 0){
		return;
	}
	father->eraseNode(t);
	while (t!=NULL){
		TreeNode* cut = t;
		count++;
		if (count < s.size())
			t = t->find(s[count]);
		else
			t = NULL;
		delete cut;
	}
}
Trie::~Trie()
{
}
int _tmain(int argc, _TCHAR* argv[])
{
	Trie trie;
	string s1 = "abcde";
	string s2 = "abef";
	string s3 = "abcefg";
	string s4 = "sdfgsdfd";
	string s5 = "asddgg";
	trie.insert(s1);
	trie.insert(s2);
	trie.insert(s3);
	trie.insert(s4);
	trie.insert(s5);
	trie.erase(s1);
	trie.erase("abce");
	return 0;
}

