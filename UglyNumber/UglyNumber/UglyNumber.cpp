// UglyNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
bool isUgly(int num) {
	if (num == 1)
		return true;
	int k = num;
	while (k % 2 == 0){
		k = k / 2;
	}
	while (k % 3 == 0){
		k = k / 3;
	}
	while (k % 5 == 0){
		k = k/ 5;
	}
	if (k == 1){
		return true;
	}
	else
		return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int num = 14;
	if (isUgly(num))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}

