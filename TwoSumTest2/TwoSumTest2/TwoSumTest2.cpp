// TwoSumTest2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<hash_map>
#include<unordered_map>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_multimap <int, int> ma;
		vector<int> vec1;
	 
		for (auto i = 0; i < nums.size(); i++){
			ma.insert(make_pair(nums[i], i + 1));
		}
		for (auto i = 0; i < nums.size(); i++){
			if (target != 2 * nums[i]){
				if (ma.find(target-nums[i]) != ma.end()){
					vector<int> vec = { i + 1, ma.find(target - nums[i])->second };
					return vec;
				}
			}
			else{
				if (ma.count(nums[i]) > 1){
					auto iter = ma.find(nums[i]);
					vector<int> vec = { iter->second, (++iter)->second };
					return vec;
				}
			}
		}
		return vec1;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec = { 0, 4, 3, 0};
	Solution solution;
	vector<int> vo = solution.twoSum(vec, 0);
	for (int var : vo){
		cout << var << endl;
	}
}

