// ValidAnagram.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
bool isAnagram(string s, string t) {
	if (s.length() != t.length){
		return false;
	}
	for (auto i = 0; i < s.length(); i++){
		bool hava = false;
		for (auto j = i; j < t.length(); j++){
			if (s[i] == t[j]){
				hava = true;
				char sk = t[i];
				t[i] = t[j];
				t[j] = sk;
				break;
			}
		}

		if (hava == false)
			return false;
	}
	return true;
}
int _tmain(int argc, _TCHAR* argv[])
{
	string s = "anagram";
	string t = "nagaram";
	if (isAnagram(s, t))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}

