// UglyNumberII.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Solution {
public:
	int nthUglyNumber(int n) {
		if (n <= 0){
			return 0;
		}
		if (n < 6 && n>0){
			return n;
		}
		int *uglyNum = new int[n]();
		uglyNum[0] = 1;
		
		int i = 1;
		while (i<n){
			int a=0, b=0, c=0;
			for (int j = 0; j < i; j++){
				int ka = uglyNum[j] * 2;
				int kb = uglyNum[j] * 3;
				int kc = uglyNum[j] * 5;
				if (ka>uglyNum[i - 1]&&a==0)
					a = ka;
				if (kb > uglyNum[i - 1]&&b==0)
					b = kb;
				if (kc > uglyNum[i - 1]&&c==0)
					c = kc;
				if (a != 0)
					break;
			}
			int count = a < b ? a : b;
			count = count < c ? count : c;
			uglyNum[i] = count;
			i++;
		}
		return uglyNum[n - 1];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution a;
	int count = a.nthUglyNumber(10);
	cout << count << endl;
	return 0;
}

