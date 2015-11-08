// Searcha2DMatrixII.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int i = 0;
		int j = 0;
		int m = matrix.size();
		int n = matrix[0].size();
		if (target < matrix[i][j]){
			return false;
		}
		if (matrix[i][j] == target){
			return true;
		}
		if (m == 1){
			for (; j < n; j++){
				if (matrix[i][j] == target){
					return true;
				}
				else
					if (matrix[i][j] > target){
						return false;
					}
			}
			return false;
		}
		
		for (; i < m; i++){
			int tar = matrix[i][j];
			if (tar == target){
				return true;
			}
			if (tar>target){
				if (n == 1){
					return false;
				}
				break;
			}
		}
		i--;
		while (matrix[i][j] < target&&i>0){
			while (matrix[i][j] < target&&j < n){
				j++;
			}
			if (matrix[i][j] == target){
				return true;
			}
			else
			{
				i--;
				j = 0;
				if (i < 0){
					return false;
				}
			}
		}
		if (matrix[i][j] == target){
			return true;
		}
		return false;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int>> matrix =
	{ 
		{ 1, 2, 3, 7, 8 }, 
		{ 5, 10, 14, 16, 19 }, 
		{ 8, 10, 18, 19, 23 }, 
		{9, 12, 22, 24, 29}
	};
	Solution a;
	if (a.searchMatrix(matrix, 14)){
		cout << "true" << endl;
	}
	else
		cout << "error" << endl;
	return 0;
}

