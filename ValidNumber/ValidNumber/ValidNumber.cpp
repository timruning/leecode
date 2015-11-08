// ValidNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<regex>
using namespace std;
class Solution {
public:
	bool isNumber(string s) {
		regex pattern("^\s*[+-]?(\d*\.\d+|\d+\.?)([Ee][+-]?\d+)?\s*$");
		return regex_match(s, pattern);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string s = "1";
	Solution sol;
	bool k=sol.isNumber(s);
	if (k==true){
		cout << "true" << endl;
	}
	else{
		cout << "false" << endl;
	}
	return 0;
}

