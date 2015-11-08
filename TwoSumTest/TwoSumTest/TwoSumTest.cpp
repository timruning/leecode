// TwoSumTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		multimap <int, int> ma;
		vector<int> vec;
		for (int i = 0; i < nums.size(); i++){
			
			int t = i + 1;
				ma.insert(pair<int, int>(nums[i], t));
			
		}
		for (int i = 0; i < nums.size(); i++){
			if (target != 2 * nums[i]){
				if (ma.find(target - nums[i]) != ma.end()){
					vec.push_back(i+1);
					vec.push_back(ma.find(target - nums[i])->second);
					return vec;
				}
			}
			else{
				if (ma.find(nums[i]) != ma.end()){
					if (ma.count(nums[i]) > 1){
						auto iter = ma.find(nums[i]);
						vec.push_back(iter->second);
						iter++;
						vec.push_back(iter->second);
						return vec;
					}
				}
			}
		}
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums = { 0, 4, 3, 0 };
	Solution solution;
	vector<int> t = solution.twoSum(nums, 0);
	for (auto var : t){
		cout << var << endl;
	}
	return 0;
}

