// Searcha2DMatrixII2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
/*
	�Ӿ������Ͻǣ��������½ǿ�ʼ������
	�������Ŀ���������Ч�����С��Ŀ���������Ч
	��֮��Ȼ��
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

