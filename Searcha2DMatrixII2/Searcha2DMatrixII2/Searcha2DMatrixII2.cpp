// Searcha2DMatrixII2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
/*
	从矩阵右上角，或者左下角开始遍历。
	如果大于目标则该列无效。如果小于目标则该行无效
	反之亦然。
*/
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		int n;
		if (m > 0){
			n = matrix[0].size();
		}
		int i = 0;
		int j = n - 1;
			while (i < m&&j >= 0){
				if (matrix[i][j] == target){
					return true;
				}
				if (matrix[i][j] < target){
					i++;
					if (i == m)
						break;
				}
				if (matrix[i][j] > target){
					j--;
					if (j < 0)
						break;
				}
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

