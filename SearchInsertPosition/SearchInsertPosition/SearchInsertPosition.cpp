// SearchInsertPosition.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int count = 0;
		while (count<nums.size())
		{
			if (nums[count] >= target)
				return count;
			count++;
		}
		return count;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

