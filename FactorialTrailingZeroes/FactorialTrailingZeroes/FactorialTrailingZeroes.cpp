// FactorialTrailingZeroes.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class Solution {
public:
	int trailingZeroes(int n) {
		int k = 0;
		long long t = 5;
		while (n / t > 0){
			k += (n / t);
			t *= 5;
			cout << t << endl;
		}
		return k;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution as;
	cout << as.trailingZeroes(1808548329) << endl;
	return 0;
}

