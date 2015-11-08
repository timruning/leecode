// SetMatrixZeroes.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int t = matrix.size();
		if (t == 0)
			return;
		int k = matrix[0].size();
		set<int> row;
		set<int> line;
		for (int i = 0; i < t; ++i){
			for (int j = 0; j < k; ++j){
				if (matrix[i][j] == 0){
					row.insert(i);
					line.insert(j);
				}
			}
		}
		for (auto var : row){
			for (int j = 0; j < k; ++j){
				matrix[var][j] = 0;
			}
		}
		for (auto var : line){
			for (int i = 0; i < t; ++i){
				matrix[i][var] = 0;
			}
		}
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int>> matrix = { { 0, 1, 2, 3, 4 }, { 1, 3, 0, 5, 4 } };
	Solution sol;
	sol.setZeroes(matrix);
	for (auto var : matrix){
		for (auto var1 : var){
			cout << var1 << " ";
		}
		cout << endl;
	}
	return 0;
}

