// CodeTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<map>
#include<vector>
#include<unordered_map>
#include<hash_map>
#include<string>
using namespace std;

class TestNode{
	//****
public:
	vector<int> a;
};
class TestClass{
public:
	int a;
	int b;
	bool operator==(TestClass obj){
		if (a == obj.a&&b==obj.b){
			return true;
		}
		else
			return false;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	int a = '0';
	cout << "a = "<<a << endl;
	TestClass testClass1;
	TestClass testClass2;
	testClass1.a = 1;
	testClass1.b = 1;
	testClass2.a = 1;
	testClass2.b = 1;
	TestClass &testClass3 = testClass1;
	testClass3.a = 10000;
	if (testClass1 == testClass2){
		cout << "asddsffg" << endl;
	}
	return 0;
}

