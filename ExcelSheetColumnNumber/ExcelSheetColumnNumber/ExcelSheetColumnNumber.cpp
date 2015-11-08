// ExcelSheetColumnNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include<iostream>
using namespace std;
int titleToNumber(string s) {

	int scount = s.length();
	static int a = 0;
	for (int i = 0; i < scount; i++){
		a = 26 * a + s[i] - 'A' + 1;
	}
	return a;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string s = "B";
	int a = titleToNumber(s);
	cout << a << endl;
}

