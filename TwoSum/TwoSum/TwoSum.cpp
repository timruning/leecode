// TwoSum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> vec;
		for (int i = 1; i < nums.size(); i++){
			int j = 0;
			int k = j + i;
			bool find = false;
			while (k < nums.size()){
				
				if (nums[j] + nums[k] == target){
					cout << i << " " << j;
					vec.push_back(j + 1);
					vec.push_back(k + 1);
					find = true;
					break;
				}
				j++;
				k++;
			}
			if (find)
				break;
		}
		return vec;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> a = { 0,4,3,0 };
	int target = 0;
	vector<int> vec;
	Solution aa;
	vec = aa.twoSum(a, target);
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << endl;
	return 0;
}

