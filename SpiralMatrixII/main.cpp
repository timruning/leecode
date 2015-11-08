#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0){
            vector<vector<int>> anwser;
            return anwser;
        }

        vector<int> vec(n,0);
        vector<vector<int>> anwser(n,vec);
        int t=0;
        int i=0,j=0;
        int count=1;
        int num=n*n;
        anwser[0][0]=1;
        while(count<num){
            count++;
            if(t%4==0){
                j++;
                if(j==n||anwser[i][j]>0){
                    j--;
                    i++;
                    t++;
                }
            }
            else if(t%4==1){
                i++;
                if(i==n||anwser[i][j]>0){
                    i--;
                    j--;
                    t++;
                }
            }
            else if(t%4==2){
                j--;
                if(j<0||anwser[i][j]>0){
                    j++;
                    i--;
                    t++;
                }
            }
            else{
                i--;
                if(i<0||anwser[i][j]>0){
                    i++;
                    j++;
                    t++;
                }
            }
            anwser[i][j]=count;
        }
        return anwser;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> ve=sol.generateMatrix(4);
    for(auto vec:ve){
        for(auto var:vec)
            cout<<var<<" ";
        cout<<endl;
    }
    return 0;
}
