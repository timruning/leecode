// FirstBadVersion.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
bool isBadVersion(int version){
	if (version >= 1702766719){
		return true;
	}
	else{
		return false;
	}
}
class Solution {
public:
	int firstBadVersion(int n) {
		if (isBadVersion(1)||n==1){
			return 1;
		}
		long long small = 1;
		long long big = n;
		long long mil = (small + big) / 2;
		while (mil < big){
			if (isBadVersion(mil) == false && isBadVersion(mil + 1) == true){
				return mil + 1;
			}
			if (isBadVersion(mil) == true && isBadVersion(mil + 1) == true){
				big = mil;
				mil = (small + big) / 2;
			}
			if (isBadVersion(mil) == false && isBadVersion(mil + 1) == false){
				small = mil;
				mil = (small + big) / 2;
			}
		}
		if (mil == big){
			return mil;
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	int k = solution.firstBadVersion(2126753390);
	cout << k << endl;
	return 0;
}

