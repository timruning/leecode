// stringLoop.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<string>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	string s = "abcde";
	for (auto iter = s.begin(); iter != s.end(); iter++){
		if (*iter == 'b'){
			iter = s.erase(iter);
		}
	}
	cout << s << endl;
	return 0;
}

