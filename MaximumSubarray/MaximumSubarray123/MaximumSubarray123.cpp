// MaximumSubarray123.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = nums[0];
		int anwser = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			if (sum < 0){
				sum = nums[i];
			}
			else{
				sum += nums[i];
			}
			if (sum > anwser){
				anwser = sum;
			}
		}
		return anwser;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

