// Searcha2DMatrixII1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int i = 0; int j = 0;
		if (target == matrix[i][j]){
			return true;
		}
		if (target < matrix[i][j]){
			return false;
		}
		int m = matrix.size();
		if (m == 0){
			return false;
		}
		int n = matrix[0].size();
		int t = 0;
		if (m == 1){
			for (auto var : matrix[0]){
				if (var == target){
					return true;
				}
				if (var > target)
					return false;
			}
			return false;
		}
		if (n == 1){
			for (auto var : matrix){
				if (var[0] == target){
					return true;
				}
				if (var[0] > target)
					return false;
			}
			return false;
		}
		for (; t < m&&t < n; t++){
			if (target == matrix[t][t]){
				return true;
			}
			if (target < matrix[t][t]){
				break;
			}
		}
		vector<vector<int>> matrix1(matrix);
		vector<vector<int>> matrix2(matrix);
		
			for (int ii = 0; ii < t; ii++){
				matrix1.erase(matrix1.begin());
			}
			for (int ii = t; ii < m; ii++){
				matrix2.pop_back();
			}
			for (auto jj = 0; jj < matrix1.size();jj++){
				for (int ii = t; ii <= n; ii++){
					matrix1[jj].pop_back();
				}
			}
			for (auto jj = 0; jj < matrix2.size(); jj++){
				for (int ii = 0; ii < t; ii++){
					matrix2[jj].erase(matrix2[jj].begin());
				}
			}
			bool find = false;
			if (matrix1.size()!=0)
				if (matrix1[0].size() != 0){
					find = searchMatrix(matrix1, target);
				}
			if (find)
				return find;
			if (matrix2.size() != 0)
				if (matrix2[0].size() != 0){
					find = searchMatrix(matrix2, target);
				}
			return find;
				
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int>> matrix =
	{
		{ 1, 2, 3, 7, 8 },
		{ 5, 10, 14, 16, 19 },
		{ 8, 10, 18, 19, 23 },
		{ 9, 12, 22, 24, 29 }
	};
	Solution a;
	if (a.searchMatrix(matrix, 28)){
		cout << "true" << endl;
	}
	else
		cout << "error" << endl;
	return 0;
	return 0;
}

