// GrayCode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> anwser;
		if (n == 0){
			anwser.push_back(0);
			return anwser;
		}

		if (n == 1){
			anwser = { 0, 1 };
			return anwser;
		}
		vector<int> t = grayCode(n - 1);
		anwser = t;
		int a = 1;
		int i = 0;
		while (i < n - 1){
			a *= 2;
			i++;
		}
		//		for (vector<int>::reverse_iterator iter = t.rbegin(); iter < t.rend(); ++iter){

		//		}
		for (int i = 0; i < t.size(); i++){
			t[i] += a;
		}
		anwser.insert(anwser.end(), t.rbegin(), t.rend());
		return anwser;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution sol;
	vector<int> anwser = sol.grayCode(3);
	for (auto var : anwser){
		cout << var << " ";
	}
	cout << endl;
	return 0;
}

