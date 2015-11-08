// ImplementstrStr().cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int strStr(string haystack, string needle) {
		int i = 0;
		int a = haystack.size();
		int b = needle.size();
		if (a<b){
			return -1;
		}
		if (haystack == needle||needle==""){
			return 0;
		}
		int t = 1;
		while (t<b)
		{
			if (needle[t] == needle[0]){
				break;
			}
			else{
				t++;
			}
		}
		while (i < a){
			if (haystack[i] == needle[0]){
				bool find = true;
				for (int ii = 0; ii < b; ii++){
					if (haystack[i + ii] == needle[ii]){
						continue;
					}
					else{
						find = false;
						break;
					}
				}
				if (find == true){
					return i;
				}
				else{
					i += t;
					continue;
				}
			}
			else{
				i++;
			}
		}
		return -1;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution sol;
	int t= sol.strStr("babbbbbabb","bbab");
	if (t==-1){
		cout << "no" << endl;
	}
	else{
		cout << "t = " << t << endl;
	}
	return 0;
}

