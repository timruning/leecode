// IsomorphicStrings.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<map>
#include<string>
using namespace std;
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.size() != t.size())
			return false;
		map<char, int> maps;
		map<char, int> mapt;
		char i = 'a';
		for (auto var : s){
			pair<char, int> pairs = make_pair(var, i);
			if (maps.insert(pairs).second){
				i++;
			}
		}
		char j = 'a';
		for (auto var : t){
			pair<char, int> pairt = make_pair(var, j);
			if (mapt.insert(pairt).second){
				j++;
			}
		}
		string ss = "", st = "";
		for (auto var : s){
			ss += maps.find(var)->second;
		}
		for (auto var : t){
			st += mapt.find(var)->second;
		}
		if (ss == st){
			return true;
		}
		else{
			return false;
		}
	}
}; 
int _tmain(int argc, _TCHAR* argv[])
{
	string s = "foo";
	string t = "bar";
	Solution sol;
	if (sol.isIsomorphic(s, t)){
		cout << "true" << endl;
	}
	else{
		cout << "false" << endl;
	}
	return 0;
}

