// SingleNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		set<int> set1;
		for (auto var : nums){
			if (set1.find(var) == set1.end()){
				set1.insert(var);
			}
			else{
				set1.erase(set1.find(var));
			}
		}
		return *set1.begin();
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

