// MergeSortedArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int>::iterator iter1 = nums1.begin();
		vector<int>::iterator iter2 = nums2.begin();
		if (nums1.size() <= 0){
			nums1 = nums2;
			return;
		}
		if (nums2.size() <= 0){
			return;
		}
		while (iter1 != nums1.end()){
			if (*iter1 < *iter2){
				iter1++;
				continue;
			}
			else{
				vector<int>::iterator t = iter2+1;
				while (t != nums2.end()){
					if (*t < *iter1){
						t++;
						continue;
					}
					else{
						break;
					}
				}
				iter1 = nums1.insert(iter1, iter2, t);
				if (t == nums2.end()){
					return;
				}
				else{
					iter2 = t;
				}
			}
		}
		if (iter2 < nums2.end()){
			nums1.insert(nums1.end(), iter2, nums2.end());
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec1 = { 1, 2, 3, 4 ,8};
	vector<int> vec2 = { 4 ,7};
	Solution sol;
	sol.merge(vec1,4, vec2,1);
	for (auto var : vec1){
		cout << var << ' ';
	}
	cout << endl;
	return 0;
}

