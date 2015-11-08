// ValidPalindrome.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	bool isPalindrome(string s) {
		string t = s;
		for (string::iterator iter = t.begin(); iter != t.end();){
			if ((*iter >= 'a'&&*iter <= 'z')||(*iter>='0'&&*iter<='9')){
				iter++;
				continue;
			}
			else
				if (*iter >= 'A'&&*iter <= 'Z'){
					*iter = *iter + 'a' - 'A';
					iter++;
				}
				else{
					iter = t.erase(iter);
				}
		}
		int i = 0;
		int k = t.size();
		while (i <= k/2){
			if (t[i] == t[k - i - 1]){
				i++;
				continue;
			}
			else{
				return false;
			}
			i++;
		}
		return true;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	string s = "race a car";
	Solution sol;
	if (sol.isPalindrome(s)){
		cout << "true" << endl;
	}
	else{
		cout << "false" << endl;
	}
	return 0;
}

