// SingleNumberIII.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		map<int,int> map1;
		vector<int> anwser;
		for (int i = 0; i < nums.size(); i++){
			if (map1.find(nums[i]) == map1.end()){
				map1.insert(make_pair(nums[i], 0));
			}
			else{
				map1.find(nums[i])->second++;
			}
		}
		for (auto var : map1){
			if (var.second == 0){
				anwser.push_back(var.first);
			}
		}
		return anwser;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec1 = { 0, 0, 1, 2};
	Solution sol;
	vector<int> vec = sol.singleNumber(vec1);
	for (auto var : vec){
		cout << var << " ";
	}
	cout << endl;
	return 0;
}

