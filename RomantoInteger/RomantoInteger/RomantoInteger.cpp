// RomantoInteger.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<iostream>
#include<map>
using namespace std;
class Solution {
	//Ⅰ（1）、X（10）、C（100）、M（1000）、V（5）、L（50）、D（500）
	
public:
	int romanToInt(string s) {
		map<char, int> st =
		{
			{ 'I', 1 },
			{ 'V', 5 },
			{ 'X', 10 },
			{ 'L', 50 },
			{ 'C', 100 },
			{ 'D', 500 },
			{ 'M', 1000 }
		};
		int k = 0;
		for (string::iterator it=s.begin(); it < s.end(); ++it){
			if (it<s.end()-1){
				string::iterator iter = it + 1;
				if (st.find(*it)->second < st.find(*iter)->second){
					k = k - st.find(*it)->second;
				}
				else{
					k = k + st.find(*it)->second;
				}
			}
			else{
				k = k + st.find(*it)->second;
			}
		}
		
		return k;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	string s = "MCMXCVI";
	Solution solution;
	cout << solution.romanToInt(s) << endl;;
	return 0;
}

