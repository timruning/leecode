// ContainsDuplicate.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		map<int, int> as;
		for (int i = 0; i < nums.size(); i++){
			if (as.find(nums[i]) != as.end()){
				if (as.find(nums[i])->second == 1){
					return true;
				}
			} else
			{
				as.insert(pair<int, int>(nums[i], 1));
			}
		}
		return false;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec = {0,2,1,3,5,6,10};
	Solution solution;
	if (solution.containsDuplicate(vec)){
		cout << "yes" << endl;
	}
	else{
		cout << "no" << endl;
	}
	return 0;
}

