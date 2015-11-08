// SlidingWindowMaximum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> numMax;
	int n = nums.size();
	if (n == 0 || k == 0){
		return numMax;
	}
	int max = nums[0];

	if (k >= n){
		for (int i = 1; i < n; i++){
			if (nums[i]>max)
				max = nums[i];
		}
		numMax.push_back(max);
		return numMax;
	}

	int t = 0;
	for (int i = t + 1; i < t + k; i++){
		if (nums[i] > max){
			max = nums[i];
		}

	}
	numMax.push_back(max);
	t++;
	while (t + k <= n){
		if (max == nums[t - 1]){
			max = nums[t];
			for (int i = t + 1; i < t + k; i++){
				if (nums[i] > max){
					max = nums[i];
				}
			}
			numMax.push_back(max);
		}
		else{
			if (max>nums[t + k - 1]){
				numMax.push_back(max);
			}
			else{
				max = nums[t + k - 1];
				numMax.push_back(max);
			}
		}
		t++;
	}
	return numMax;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
	vector<int > ma = maxSlidingWindow(nums, 3);
	for (auto var : ma){
		cout << var << "  ";
	}
	cout << endl;
	return 0;
}

