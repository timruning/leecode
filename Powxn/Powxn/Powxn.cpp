// Powxn.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	double myPow(double x, int n) {
		double t = 1.0;
		int i = 0;
		int p;
		if (n > 0){
			p = n;
		}
		if (n < 0){
			p = -n;
		}
		if (n == 0&&x!=0){
			return 1;
		}
		if (x == 1.0){
			return 1.0;
		}
		if (x == -1.0){
			if (n % 2 == 0){
				return 1.0;
			}
			else{
				return -1.0;
			}
		}
		while (i<p)
		{
			t = t*x;
			if (t == 0){
				return 0;
			}
			i++;
		}
		if (n>0)
		return t;
		if (n < 0){
			t = 1 / t;
			return t;
		}
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

