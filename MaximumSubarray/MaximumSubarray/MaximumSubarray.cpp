// MaximumSubarray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int anwser = nums[0];
		int sum;
		int p =0, q = 0;
		int i = 0;
		int t = nums.size();
		bool begin = false;
		while (i < t){
			if (begin == false){
				if (nums[i] > 0){
					sum = nums[i];
					if (sum > anwser){
						anwser = sum;
					}
					begin = true;
					p = i;
					i++;
					continue;
				}
			}
			else{
				sum = sum + nums[i];
				if (sum < 0){
					begin = false;
					i = p;
					i++;
					continue;
				}
				if (sum > anwser){
					anwser = sum;
				}
				q = i;
				i++;
				continue;
			}
			i++;
		}
		if (anwser < 0){
			for (auto var : nums){
				if (var > anwser){
					anwser = var;
				}
			}
		}
		return anwser;

	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec = { -1, 0, -2 };
	Solution sol;
	int k = sol.maxSubArray(vec);
	cout << k << endl;
	return 0;
}

