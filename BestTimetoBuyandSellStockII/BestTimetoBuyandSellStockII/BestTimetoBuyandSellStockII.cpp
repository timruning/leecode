// BestTimetoBuyandSellStockII.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <=1)
			return 0;
		bool fang = false;
		vector<int> buy(prices.size(), 0);
		for (int i = 1; i < prices.size(); i++){
			if (prices[i]>prices[i - 1]){
				if (fang == false){
					buy[i - 1] = -1;
					fang = true;
				}
			}
			else{
				if (prices[i] < prices[i - 1]){
					if (fang == true){
						buy[i - 1] = 1;
						fang = false;
					}
					
				}
			}
		}
		if (fang == true){
			*buy.rbegin() = 1;
		}
		int anwser = 0;
		for (int i=0; i < buy.size(); i++){
			anwser =anwser + buy[i] * prices[i];
		}
		return anwser;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec = { 1, 9, 6, 9, 1, 7, 1, 1, 5, 9, 9, 9};
	Solution sol;
	int k = sol.maxProfit(vec);
	cout << k << endl;
	return 0;
}

