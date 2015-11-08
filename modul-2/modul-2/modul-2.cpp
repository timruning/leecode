// modul-2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
/*
	一个数由model-2表示，他的加减怎么算？
	遇到进位 是-1,也就是11
*/
vector<int> pluss(vector<int> vec1, vector<int> vec2){
	int i = 0;
	int a, b;
	int k = vec1.size() > vec2.size() ? vec1.size() : vec2.size();
	vector<int> anwser(k, 0);
	while (i < vec1.size() || i < vec2.size()){
		if (i < vec1.size()){
			a = vec1[i];
		}
		else{
			a = 0;
		}
		if (i < vec2.size()){
			b = vec2[i];
		}
		else{
			b = 0;
		}
		anwser[i] = a + b;
		i++;
	}
	bool jinwei = false;
	for (int j = 0; j < k;j++){
		if (jinwei == true){
			if (anwser[j] >= 1){
				anwser[j]--;
			}
			else{
				if (j < k - 1){
					anwser[j]++;
					anwser[j + 1]++;
				}
				else{
					anwser[j]++;
					anwser.push_back(1);
					k++;
				}
			}
		}
		if (anwser[j] >= 2){
			anwser[j] = anwser[j] % 2;
			jinwei = true;
			if (j == k - 1){
				anwser.push_back(1);
				anwser.push_back(1);
			}
		}
		else{
			jinwei = false;
		}
	}
	return anwser;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> a = {1,0,1,1,1};
	vector<int> b = {1,1,1,1,1};
	vector<int> t = pluss(a, b);
	for (auto var : t){
		cout << var << " ";
	}
	cout << endl;
	return 0;
}

