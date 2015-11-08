// SingleNumberII.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		map<int, int> map1;
		for (auto var : nums){
			if (map1.find(var) != map1.end()){
				map1.find(var)->second++;
			}
			else{
				map1.insert(make_pair(var, 1));
			}
		}
		for (auto var : map1){
			if (var.second == 1){
				return var.first;
			}
		}
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

