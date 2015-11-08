// MajorityElementII.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int elem1, count1 = 0;
		int elem2, count2 = 0;
		for (int i = 0; i < nums.size(); i++){
			if (count1 == 0 && count2 == 0){
				elem1 = nums[i];
				count1 = 1;
				continue;
			}
			if (count1 == 0 && count2 != 0){
				if (elem2 == nums[i]){
					count2++;
				}
				else{
					elem1 = nums[i];
					count1 = 1;
				}
				continue;
			}
			if (count2 == 0 && count1 != 0){
				if (elem1 == nums[i]){
					count1++;
				}
				else{
					elem2 = nums[i];
					count2 = 1;
				}
				continue;
			}
			if (count2 != 0 && count1 != 0){
				if (elem1 == nums[i]){
					count1++;
				}
				if (elem2 == nums[i]){
					count2++;
				}
				if (elem1 != nums[i] && elem2 != nums[i]){
					count1--;
					count2--;
				}
				continue;
			}
		}
		if (count1 > 0){
			count1 = 0;
			for (int var : nums){

				if (var == elem1){
					count1++;
				}
			}
		}
	
		if (count2 > 0){
			count2 = 0;
			for (int var : nums){

				if (var == elem2){
					count2++;
				}
			}
		}
		vector<int> vec;
		if (count1>nums.size() / 3){
			vec.push_back(elem1);
		}
		if (count2 > nums.size() / 3){
			vec.push_back(elem2);

		}
		return vec;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	vector<int> vect = { 4, 2, 1, 1};
	vector<int> vec = solution.majorityElement(vect);
	for (auto var : vec){
		cout << var << endl;
	}
	return 0;
}

 