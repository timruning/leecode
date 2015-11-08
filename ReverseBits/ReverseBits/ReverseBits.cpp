// ReverseBits.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include <cstdint>
#include<string>
using namespace std;
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		string s = "00000000000000000000000000000000";
		uint32_t t = n;
		int i = 0;
		while (t > 0&&i<32){
			s[i] = t % 2 + 48;
			i++;
			t = t / 2;
		}
		uint32_t anwser = 0;
		for (auto i : s){
			anwser = anwser * 2 + i - 48;
		}
		return anwser;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution sol;
	uint32_t t = sol.reverseBits(2147483648);
	cout << t << endl;
	return 0;
}

