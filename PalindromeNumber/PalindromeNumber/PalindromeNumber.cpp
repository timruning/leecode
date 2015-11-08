// PalindromeNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		
		int k = 0;
		int p = 0;
		int t=x;
		if (x < 0)
			return false;
		if (x == 0)
			return true;
		while (t > 0){
			k = t % 10;
			p = p * 10 + k;
			t = t / 10;
		}
			if (p == x){
				return true;
			}
			else
				return false;

	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	if (solution.isPalindrome(1)){
		cout << "true" << endl;
	}
	else{
		cout << "false" << endl;
	}
	
	return 0;
}

