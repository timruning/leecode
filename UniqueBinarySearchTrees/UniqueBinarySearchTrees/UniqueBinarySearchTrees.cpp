// UniqueBinarySearchTrees.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int numTrees(int n) {
		int t = 1;
		vector<int> vec1(n, 1);
		vector<int> vec2(n, 1);
		for (int i = 0; i < n; i++){
			vec1[i] = n + i + 1;
			vec2[i] = i + 1;
		}

		for (int ii = 0; ii < 5; ii++){
			for (int i = 0; i < n; i++){
				if (vec1[i] % 2 == 0){
					if (vec2[vec1[i] / 2-1] != 1){
						
						vec2[vec1[i] / 2-1] = 1;
						vec1[i] = 2;
						continue;
					}

				}
				if (vec1[i] % 3 == 0){
					if (vec2[vec1[i] / 3-1] != 1){
						
						vec2[vec1[i] / 3-1] = 1;
						vec1[i] = 3;
						continue;
					}
				}
				if (vec1[i] % 5 == 0){
					if (vec2[vec1[i] / 5-1] != 1){
						
						vec2[vec1[i] / 5-1] = 1;
						vec1[i] = 5;
						continue;
					}
				}
				if (vec1[i] % 7 == 0){
					if (vec2[vec1[i] / 7-1] != 1){
						
						vec2[vec1[i] / 7-1] = 1;
						vec1[i] = 7;
						continue;
					}
				}
			}
		}

		for (int i = 0; i < n;i++){
			t = t*vec2[i];
		}
		for (int i = 0; i < n; i++){
			if (t%vec1[i] == 0){
				t = t / vec1[i];
				vec1[i] = 1;
			}
			if (t == 1)
				break;
		}
		long long anwser = 1;
		for (int i = 0; i < n; i++){
			anwser = anwser*vec1[n-i-1]; 
			if (t!=1&&anwser%t == 0){
				anwser = anwser / t;
				t = 1;
			}
		}
		anwser = anwser / t;
		cout << anwser << endl;
		anwser = anwser / (n + 1);
		return anwser;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution sol;
	int k = sol.numTrees(19);
	cout << k << endl;
	return 0;
}

