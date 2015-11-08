// AddBinary.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		int tar = 0;
		int cou = 0;
		string::reverse_iterator ai = a.rbegin();
		string::reverse_iterator bi = b.rbegin();
		for (; ai < a.rend() && bi < b.rend(); ai++, bi++){
			if (*ai == '1')
				cou++;
			if (tar == 1)
				cou++;
			if (*bi == '1')
				cou++;
			if (cou % 2){
				*ai = '1';
			}
			else{
				*ai = '0';
			}
			tar = cou / 2;
			cou = 0;
		}
		if (ai < a.rend()){
			while (ai < a.rend()){
				if (tar == 1)
					cou++;
				if (*ai == '1')
					cou++;
				if (cou % 2){
					*ai = '1';
				}
				else{
					*ai = '0';
				}
				tar = cou / 2;
				cou = 0;
				ai++;
			}
		}
		if (bi < b.rend()){
			while (bi < b.rend()){
				if (tar == 1)
					cou++;
				if (*bi == '1')
					cou++;
				if (cou % 2){
					a = '1'+a;
				}
				else{
					a = '0'+a;
				}
				tar = cou / 2;
				cou = 0;
				bi++;
			}
		}
		if (tar == 1){
			a = "1" + a;
		}
		return a;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	cout << solution.addBinary("1", "111") << endl;
	return 0;
}

