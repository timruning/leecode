#include<vector>
#include<set>
#include<map>
#include"Community.h"
#pragma once
using namespace std;
class Result
{
public:
	vector<int> result;
	Result();
	~Result();
	map<int, set<int>> toCommunity(){
		map<int, set<int>> anwser;
		for (auto i = 0; i < result.size(); i++){
			if (anwser.find(result[i]) == anwser.end()){
				set<int> t;
				t.insert(i);
				anwser.insert(pair<int,set<int>>(result[i],t));
			}
			else{
				anwser.find(result[i])->second.insert(i);
			}
		}
		return anwser;
	}
};

