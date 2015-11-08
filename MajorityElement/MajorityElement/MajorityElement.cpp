// MajorityElement.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int elem;
		int count = 0;
		for (int i = 0; i < nums.size(); i++){
			if (count == 0){
				elem = nums[i];
				count = 1;
			}
			else{
				if (nums[i] == elem){
					count++;
				}
				else{
					count--;
				}
			}
		}
		return elem;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	vector<int> vec = { 3, 3, 4};
	cout << solution.majorityElement(vec) << endl;
	return 0;
}

