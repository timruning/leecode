#include<vector>
#include"Community.h"
using namespace std;
class graph
{
public:
	vector<vector<int> > nodeList = { { 1, 2 }, { 0, 2 }, { 0, 1, 3 }, { 2, 4 }, { 3, 5, 6 }, { 4, 7 }, { 4, 7 }, {5,6} };
	graph();
	~graph();
	double comModularity(Community community);
};

