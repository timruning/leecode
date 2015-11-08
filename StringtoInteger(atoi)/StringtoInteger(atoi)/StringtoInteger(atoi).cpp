// StringtoInteger(atoi).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		int k = 0;
		bool fuhao=true;
		for (string::iterator iter = str.begin(); iter < str.end(); ++iter){
			if (*iter == '+')
			{
				fuhao = true;
				continue;
			}
			if (*iter == '-'){
				fuhao = false;
				continue;
			}
			k = k * 10 + *iter-48;
		}
		if (fuhao == false){
			k = -k;
		}
		return k;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	int u = solution.myAtoi("+1");
	cout << u << endl;
	return 0;
}

