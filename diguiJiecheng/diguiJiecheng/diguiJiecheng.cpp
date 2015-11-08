// diguiJiecheng.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int jiecheng(int n, int k){
	int a = n < k ? n : k;
	int b = n + k - a;
	if (n == 0 || k == 0){
		return 1;
	}
	int anwser = 1;
	int i = 1;
	while (i <= b-a){
		anwser = anwser*(k + i) / i;
		i++;
	}
	return anwser;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n=34;
	int k=17;
	int anwser = jiecheng(n, k);
	cout << anwser << endl;
	return 0;
}

