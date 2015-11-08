// 3Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<time.h>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> anwser;
		if (nums.size() == 0){
			return anwser;
		}
		map<int, int> num2;
		map<int, set<pair<int, int>>> an;
		for (auto var : nums){
			if (num2.find(var) != num2.end()){
				num2.find(var)->second++;
			}
			else{
				num2.insert(make_pair(var, 1));
			}
		}
		for (int i = 0; i < nums.size() - 1; i++){
			for (int j = i + 1; j < nums.size(); j++){
				int sum1 = -nums[i] - nums[j];
				if (an.find(sum1) == an.end()){
					int a = nums[i] < nums[j] ? nums[i] : nums[j];
					int b = nums[i] + nums[j] - a;
					pair<int, int> pa = make_pair(a, b);
					set<pair<int, int>> set1;
					set1.insert(pa);
					an.insert(make_pair(sum1,set1));
				}
				else{
					auto iter = an.find(sum1);
					int a = nums[i] < nums[j] ? nums[i] : nums[j];
					int b = nums[i] + nums[j] - a;
					iter->second.insert(make_pair(a, b));
				}
			}	
		}
		for (auto var : num2){
			if (an.find(var.first) != an.end()){
				auto iter = an.find(var.first);
				for (auto var1 : iter->second){
					if (var.first>var1.first)
						continue;
					if (var.first != var1.first&&var.first != var1.second){
						int a = var.first < var1.first ? var.first : var1.first;
						int b = var.first > var1.second ? var.first : var1.second;
						vector<int> vec = {a,-a-b,b };
						anwser.push_back(vec);
					}
					else{
						if (var.first == var1.first&&var.first == var1.second){
							if (var.second >= 3){
								vector<int> vec = { var.first, var.first, var.first };
								anwser.push_back(vec);
							}
						}
						else{
							if (var.second >= 2){
								vector<int> vec = { var1.first, var.first, var1.second };
								anwser.push_back(vec);
							}
						}
					}
				}
			}
		}
		return anwser;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	int start = clock();
	vector<int> fir = { 7, -1, 14, -12, -8, 7, 2, -15, 8, 8, -8, -14, -4, -5, 7, 9, 11, -4, -15, -6, 1, -14, 4, 3, 10, -5, 2, 1, 6, 11, 2, -2, -5, -7, -6, 2, -15, 11, -6, 8, -4, 2, 1, -1, 4, -6, -15, 1, 5, -15, 10, 14, 9, -8, -6, 4, -6, 11, 12, -15, 7, -1, -9, 9, -1, 0, -4, -1, -12, -2, 14, -9, 7, 0, -3, -4, 1, -2, 12, 14, -10, 0, 5, 14, -1, 14, 3, 8, 10, -8, 8, -5, -2, 6, -11, 12, 13, -7, -12, 8, 6, -13, 14, -2, -5, -11, 1, 3, -6 };
	Solution sol;
	vector<vector<int>> anwser = sol.threeSum(fir);
	for (auto var1 : anwser){
		for (auto var2 : var1){
			cout << var2 << " ";
		}
		cout << endl;
	}
	int finish = clock();
	cout << finish - start << endl;
	return 0;
}

