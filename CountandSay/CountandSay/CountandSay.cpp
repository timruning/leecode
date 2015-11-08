// CountandSay.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string countAndSay(int n) {
		if (n == 0){
			return "1";
		}
		if (n == 1){
			return "11";
		}
		string t = countAndSay(n - 1);
		int i = 0;
		int j = 0;
		string s;
		while (i < t.size()){
			int count = 0;
			while (j < t.size()){
				if (t[i] == t[j]){
					j++;
					count++;
				}
				else{
					break;
				} 
			}
			if (count > 0){
				s.push_back(count + 48);
				s.push_back(t[i]);
				i = j;
			}
		}
		return s;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution sol;
	string s = sol.countAndSay(3);
	cout << s << endl;
	return 0;
}

