// AddDigits.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
int addDigits(int num) {
	int a = num - (num - 1) / 9 * 9;
	return a;
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

