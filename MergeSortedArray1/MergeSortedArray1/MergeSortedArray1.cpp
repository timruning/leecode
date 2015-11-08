// MergeSortedArray1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int j = 0;
		vector<int> nums3(nums1.begin(), nums1.begin() + m);
		while (j < n){
			int i = 0;
			while (i < m){
				if (nums3[i] < nums2[j]){
					i++;
					continue;
				}
				else{
					break;
				}
			}
				nums3.insert(nums3.begin() + i, nums2[j]);
				m++;
				j++;
				continue;
		}
		nums1 = nums3;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec1 = {1,4,7};
	vector<int> vec2 = {0,5,9};
	Solution sol;
	sol.merge(vec1,0, vec2,vec2.size());
	for (auto var : vec1){
		cout << var << " ";
	}
	cout << endl;
	return 0;
}

