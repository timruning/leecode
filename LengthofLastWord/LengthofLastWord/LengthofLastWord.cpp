// LengthofLastWord.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int lengthOfLastWord(string s) {
	if (s.length() == 0)
		return 0;
	int count = s.length();
	int acount = 0;
	for (int i = count - 1; i >= 0; i--){
		
		if (s[i] == ' '){
			count--;
		}
		else{
			break;
		}
	}
	acount = count - acount;
	for (int i = 0; i < count; i++){
		if (s[i] == ' '){
			acount = count - i-1;
		}
	}
	return acount;
}
int _tmain(int argc, _TCHAR* argv[])
{
	string s = "       a";
	int count = lengthOfLastWord(s);
	cout << count << endl;
	return 0;
}

