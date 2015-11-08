#include <iostream>
#include<string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1=haystack.size();
        int n2=needle.size();
        if(n2==0)
            return 0;
        else{
            if(n1==0)
                return -1;
        }
        for(int i=0;i<=n1-n2;){
            if(haystack[i]==needle[0]){
                bool find=true;
                int count=1;
                int pst=0;
                while(count<n2){
                    if(i+count>=n1)
                        return -1;
                    if(haystack[i+count]==needle[0]&&pst==0)
                        pst=count;
                    if(haystack[i+count]!=needle[count]){
                        find=false;
                        if(pst==0){
                            i=i+count+1;
                        }else{
                            i=i+pst;
                        }
                        break;
                    }
                    count++;
                }
                if(find)
                    return i;
                else{
                    continue;
                }
            }
            i++;
        }
        return -1;
    }
};
int main()
{
    Solution sol;
    //"mississippi","issip"
    //"pspidfsfpisdfsdf","pi"
    /*
        "abbabaaaabbbaabaabaabbbaaabaaaaaabbbabbaabbabaabbabaaaaababbabbaaaaabbbbaaabbaaabbbbabbbbaaabbaaaaababbaababbabaaabaabbbbbbbaabaabaabbbbababbbababbaaababbbabaabbaaabbbba"
"bbbbbbaa"
    */
    int t = sol.strStr("babbbbbabb","bbab");
    cout<<t<<endl;
    return 0;
}
