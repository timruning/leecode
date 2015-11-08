// Searcha2DMatrix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int a = 0;
		if (matrix.size() == 0)
			return false;
		int b = matrix[0].size()-1;
		while (a < matrix.size() && b>=0){
			if (matrix[a][b] == target)
				return true;
			if (matrix[a][b] < target){
				a++;
			}
			else{
				if (matrix[a][b] > target)
					b--;
			}
		}
		return false;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

