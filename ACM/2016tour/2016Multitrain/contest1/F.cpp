#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#define inf 999999999
#define mo 1000000007
#define LL long long 
using namespace std;
LL dp[11][2000];
LL sum[2000];
int x,l,now,n,m;
int main()
{
  for (int i=1;i<=1024;i++)
  {
    x=i;l=0;
    while(x)
    {
      if (x%2) l++;
      x/=2;
    }

    sum[i]=pow(2,l);
  }

  while (scanf("%d%d",&n,&m)!=EOF)
  {
    memset(dp,0,sizeof(dp));
    l=pow(2,m);
    // cout<<l<<endl;
    
    for (int i=0;i<l;i++)
      dp[1][i]=sum[i];

    for (int i=2;i<=n;i++)
    {
      for (int j=1;j<l;j++)
      {
        for (int k=1;k<l;k++)
        {
          now=j|k;
          dp[i][now]+=(dp[i-1][j]*sum[k])%mo;
        }
      }
    }
    for (int i=1;i<=n;i++)
    {
      for (int j=1;j<l;j++)
      {
        cout<<dp[i][j]<<' ';
      }
      cout<<endl;
    }
  } 
}
