#include<iostream>
#include<string>
using namespace std;
int lengthOfLastWord(string s) {
	int count = 0;
	for (int i = 0;  i < s.length(); i++){
		if (s[i] == ' '){
			count = s.length() - i;
		}
	}
	return count;
}
int main()
{
	string s = "Hello World";
	int count = lengthOfLastWord(s);
	cout << count << endl;
}