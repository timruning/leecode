// StringtoIntegeratoi.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		bool numHave = false;
		int t = 0;
		bool numF = true;
		string::iterator iter = str.begin();
		while (iter < str.end()){
			if (*iter == '+'){
				if (numHave == false){
					numHave = true;
					iter++;
					continue;
				}
				else{
					if (numF == false)
						return 0;
				}
			}
			if (*iter == '-'){
				if (numHave == false){
					numHave = true;
					numF = false;
					iter++;
					continue;
				}
				else{
					if (numF == true)
						return 0;
				}
			}
			if (*iter >= '0'&&*iter <= '9'){
				numHave = true;
				t = t * 10 + *iter - '0';
				iter++;
				continue;
			}
			if (numHave&&(*iter<'0'||*iter>'9')){
				break;
			}
			iter++;
		}
		if (numF){
			if (t>=0)
			return t;
			else{
				return 2147483647;
			}
		}
		else{
			if (t >= 0)
				return -t;
			else{
				t = 0-2147483648;
				return t;
			}
		}
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	int k = solution.myAtoi("23a8f");
	cout << k << endl;
	return 0;
}

