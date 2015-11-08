// PowerofTwo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

bool isPowerOfTwo(int n) {
	if (n == 0)
		return false;
	while (n % 8 == 0){
		n = n / 8;
	}
	if (n == 1 || n == 2||n==4){
		return true;
	}
	else
		return false;
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

