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
		int count = 0;
		
		string s="";
		if (strs.size() == 0)
			return s;
		int min = strs[0].size();
		for (int i = 1; i < strs.size(); i++){
			if (strs[i].size() < min){
				min = strs[i].size();
			}
		}
		while (count < min){
			bool find = true;
			for (int i = 1; i < strs.size(); i++){
				if (strs[i][count] != strs[0][count]){
					find = false;
					break;
				}
			}
			if (find == true){
				count++;
				continue;
				
			}
			else{
				break;
			}
		}
		s = strs[0].substr(0, count);
		return s;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> vec = { "a", "a", "ab" };
	Solution sol;
	string str = sol.longestCommonPrefix(vec);
	cout << str << endl;
	return 0;
}

