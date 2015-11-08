#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
    	int n=nums.size();
    	if(n==1||nums[0]<=nums[n-1])
    		return nums[0];
    	if(nums[n/2]>=nums[n-1]){
    		std::vector<int> v(nums.begin()+n/2,nums.end());
    		cout<<v[0]<<endl;
    		int pt = findMin(v);
    		return pt<nums[n-1]?pt:nums[n-1];
    	}else{
    		std::vector<int> v(nums.begin(),nums.begin()+n/2);
    		cout<<v[0]<<"  2"<<endl;
    		int pt=findMin(v);
    		return pt<nums[n/2]?pt:nums[n/2];
    	}
    }
};
int main(){
	std::vector<int> v;
	v.push_back(8);
	v.push_back(9);
	// v.push_back(10);
	// v.push_back(11);
	// v.push_back(12);
	// v.push_back(13);
	// v.push_back(14);
	// v.push_back(16);
	Solution sol;
	int k=sol.findMin(v);
	cout<<k<<endl;
	return 0;
}
