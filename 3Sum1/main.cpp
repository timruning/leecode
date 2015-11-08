#include <iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include "unp.h"
using namespace std;
int main()
{
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    random_shuffle(a,a+10);
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
