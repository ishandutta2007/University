#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#define inf 999999999
#define mo 1000000007
#define LL long long 
using namespace std;
int n;
int run[10000];
void Solve(int k)
{
    int sum=0,l=0;
    while (sum<n)
    {
        l=0;
        for (int i=1;i<=n;i++)
            if (run[i]==0)
            {
                l++;
                if (l%k==1){cout<<i<<' ';run[i]=1;sum++;}
            }
    }
    return ;
}
int main()
{
  freopen("tab.out", "w", stdout);

    n=10;
    for (int j=2;j<=n+1;j++)
    {
        cout<<"k="<<j<<endl;
        memset(run,0,sizeof(run));
        Solve(j);
        cout<<endl;
    }
}
