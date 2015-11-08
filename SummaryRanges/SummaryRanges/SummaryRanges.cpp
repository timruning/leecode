// SummaryRanges.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> summaryRanges(vector<int>& nums) {
	

	int first=0, second=0;
	vector<string> vecstr;
	string var;
	if (nums.size() == 0)
		return vecstr;
	for (auto i = 0; i < nums.size()-1; i++){
		if (nums[i + 1] == nums[i] + 1){
			second = i + 1;
		}
		else
		{
			int a = nums[first];
			int b = nums[second];
			char bufa[256];
			char bufb[256];
			sprintf_s(bufa, "%d", a);
			sprintf_s(bufb, "%d", b);
			string as = bufa;
			string bs = bufb;
			if (first != second)
			{
				var = as + "->" + bs;
			}
			else
				var = as;
			vecstr.push_back(var);
			first = i + 1;
			second = i + 1;
		}
	}
	if (second == nums.size() - 1){
		if (first == second){
			int a = nums[first];
			char bufa[256];
			sprintf_s(bufa, "%d", a);
			string as = bufa;
			vecstr.push_back(as);
		}
		else{
			int a = nums[first];
			int b = nums[second];
			char bufa[256];
			char bufb[256];
			sprintf_s(bufa, "%d", a);
			sprintf_s(bufb, "%d", b);
			string as = bufa;
			string bs = bufb;
			var = as + "->" + bs;
			vecstr.push_back(var);
		}
	}
	return vecstr;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a = -2147483648;
	char buf[256];
	sprintf_s(buf, "%d", a);
	cout << buf << endl;
	return 0;
}

