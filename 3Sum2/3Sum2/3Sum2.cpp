// 3Sum2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
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
		sort(nums.begin(), nums.end());
		map<int, int> fmap;
		map<int, int> zmap;
		int zeroCount = 0;
		int count = 0;
		for (int i = 0; i < nums.size(); i++){
			
			if (nums[i] < 0){
				count++;
				if (fmap.find(nums[i]) == fmap.end()){
					fmap.insert(make_pair(nums[i], 1));
				}
				else{
					fmap.find(nums[i])->second += 1;
				}
			}
			if(nums[i]>0) {
				if (zmap.find(nums[i]) == zmap.end()){
					zmap.insert(make_pair(nums[i], 1));
				}
				else{
					zmap.find(nums[i])->second += 1;
				}
			}
			if (nums[i] == 0){
				zeroCount++;
			}
		}
		if (zeroCount > 0){
			if (zeroCount >= 3){
				vector<int> vec = { 0, 0, 0 };
				anwser.push_back(vec);
			}
			for (auto var : fmap){
				if (zmap.find(-var.first) != zmap.end()){
					vector<int> vec = { var.first, 0, -var.first };
					anwser.push_back(vec);
				}
			}
		}
		//map<int, set<pair<int, int>>> fsum;
		//map<int, set<pair<int, int>>> zsum;
		//turn to map
		set<pair<int, int>> sumset;
		for (int i = 0; i < count-1; i++){
			for (int j = i + 1; j < count; j++){
				sumset.insert(make_pair(nums[i],nums[j]));
			}
		}
		for (int i = count + zeroCount; i < nums.size()-1; i++){
			for (int j = i + 1; j < nums.size(); j++){
				sumset.insert(make_pair(nums[i], nums[j]));
			}
		}
		for (auto var : sumset){
			int k = var.first + var.second;
			if (fmap.find(-k) != fmap.end()){
				vector<int> vec = { -k, var.first, var.second };
				anwser.push_back(vec);
				continue;
			}
			if (zmap.find(-k) != zmap.end()){
				vector<int> vec = { var.first, var.second, -k };
				anwser.push_back(vec);
				continue;
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

