// IntegertoRoman.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
	string intToRoman(int num) {
		string anwser = "";
		int t = num / 1000;
		for (int i = 0; i < t; i++){
			anwser.push_back('M');
		}
		num = num % 1000;
		if (num >= 900){
			anwser = anwser + "CM";
			num = num - 900;
		}
		else
		{
			if (num >= 500){
				int k = (num - 500) / 100;
				anwser.push_back('D');
				for (int i = 0; i < k; i++){
					anwser.push_back('C');
				}
				num = num - 500 - 100 * k;
			}
			else{
				if (num >= 400){
					num = num - 400;
					anwser += "CD";
				}
				else{
					int k = num / 100;
					for (int i = 0; i < k; i++){
						anwser.push_back('C');
					}
					num = num - 100 * k;
				}
			}
		}
		if (num >= 90){
			anwser = anwser + "XC";
			num = num - 90;
		}
		else{
			if (num >= 50){
				anwser.push_back('L');
				num = num - 50;
				int k = num / 10;
				for (int i = 0; i < k; i++){
					anwser.push_back('X');
				}
				num = num - 10 * k;
			}
			else{
				if (num >= 40){
					num = num - 40;
					anwser += "XL";
				}
				else{
					int k = num / 10;
					for (int i = 0; i < k; i++){
						anwser.push_back('X');
					}
					num = num - 10 * k;
				}
			}
		}
		if (num == 9){
			anwser += "IX";
		}
		else{
			if (num >= 5){
				anwser.push_back('V');
				num = num - 5;
				int k = num;
				for (int i = 0; i < k; i++){
					anwser.push_back('I');
				}
			}
			else{
				if (num == 4){
					anwser += "IV";
				}
				else{
					int k = num;
					for (int i = 0; i < k; i++){
						anwser.push_back('I');
					}
				}
			}
		}
		return anwser;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

