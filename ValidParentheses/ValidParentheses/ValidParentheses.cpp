// ValidParentheses.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		string t;
		for (auto cha : s){
			if (cha == '(' || cha == '[' || cha == '{'){
				t.push_back(cha);
				continue;
			}
			if (cha == ')' || cha == ']' || cha == '}'){
				int kt = t.size();
				if (kt == 0){
					return false;
				}
				if ((cha==')'&&t[kt-1]!='(')||(cha==']'&&t[kt-1]!='[')||(cha=='}'&&t[kt-1]!='{'))
				{
					return false;
				}
				if ((cha == ')'&&t[kt - 1] == '(') || (cha == ']'&&t[kt - 1] == '[') || (cha == '}'&&t[kt - 1] == '{'))
				{
					t.pop_back() ;
				}
			}
		}
		if (t.size() == 0){
			return true;
		}
		else{
			return false;
		}
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution sol;
	bool t=sol.isValid("[]");
	if (t){
		cout << "yes" << endl;
	}
	else{
		cout << "no" << endl;
	}
	return 0;
}

