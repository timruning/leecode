// SearchInsertPosition1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int begin = 0;
		int end = nums.size()-1;
		int mid = (begin + end) / 2;
		while (begin != end){
			if (mid == end){
				if (nums[mid] >= target)
					return mid;
				else
					return nums.size();
			}
			if (nums[mid] < target&&nums[mid + 1] >= target)
				return mid+1;
			if (begin + 1 == end){
				break;
			}
			if (nums[mid] >= target){
				end = mid;
				mid = (begin + end) / 2;
			}
			else{
				begin = mid;
				mid = (begin + end) / 2;
			}
		}
		if (nums[0] >= target){
			return 0;
		}
		else{
			return nums.size();
		}
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec = { 1,2,3,4,5,6};
	Solution sol;
	int k = sol.searchInsert(vec,14);
	cout << k << endl;
	return 0;
}

