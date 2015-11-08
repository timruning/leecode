// ReverseInteger.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		int anwser = 0;
		bool fu;
		if (x > 0)
			fu = false;
		if (x < 0)
			fu = true;
		int font = anwser;
		while (x != 0){
			font = anwser;
			anwser = 10 * anwser + x % 10;
			x = x / 10;
			if (fu==false){
				if (anwser<2*font)
					return 0;
				continue;
			}
			if (fu=true){
				if (anwser>2*font)
					return 0;
				continue;
			}
		}
		return anwser;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	cout << solution.reverse(1534236469) << endl;
	return 0;
}

