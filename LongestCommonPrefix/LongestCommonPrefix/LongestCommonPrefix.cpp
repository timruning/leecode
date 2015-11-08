// LongestCommonPrefix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		sort(strs.begin(), strs.end());
		int an[2] = { 0, 0 };
		if (strs.size() == 0){
			return "";
		}
		if (strs.size() == 1){
			return strs[0];
		}
		for (int i = 1; i < strs.size(); i++){
			int j = 0;
			if (strs[i - 1] == strs[i]){
				continue;
			}
			while (j < strs[i - 1].size() && j < strs[i].size()){
				if (strs[i - 1][j] != strs[i][j]){
					break;
				}
				else{
					j++;
				}
			}
			if (j > an[1]){
				an[0] = i - 1;
				an[1] = j;
			}
		}
		string s = strs[an[0]].substr(0, an[1]);
		return s;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> vec = { "a", "a", "b" };
	Solution sol;
	string str = sol.longestCommonPrefix(vec);
	cout << str << endl;
	return 0;
}

