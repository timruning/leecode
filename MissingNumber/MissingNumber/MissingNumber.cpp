// MissingNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int k = 0;;
		for (int i = 0; i < nums.size(); i++){
			k += nums[i];
		}
		int n = nums.size();
		k = k - n*(n - 1) / 2;
		return n - k;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution a;
	vector<int> aa = { 3, 1, 2, 0, 5 };
	cout << a.missingNumber(aa)<<endl;
	return 0;
}

