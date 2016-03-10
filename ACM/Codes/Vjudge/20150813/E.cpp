#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

#define MAXN 110

using namespace std;


int a[MAXN];
int dp[MAXN][MAXN];



int main()
{
    int T;
    int n, m;
    scanf("%d",&T);
    for(int ka = 1; ka <= T; ka++)
    {
        scanf("%d%d",&n,&m);


        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);


        memset(dp,0,sizeof(dp));


        for(int i = 1; i <= n; i++)
            dp[i][i] = 1;
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<=n;j++)
            {
                dp[i][j]=dp[i+1][j]+1;
                for(int k=i;k<=j;k++)
                    if(a[i]==a[k])
                        dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k][j]);
            }
            for(int i1 = 1; i1 <= n; i1++)
                for(int j1 = 1; j1 <= n; j1++)
                    printf("%d%c", dp[i1][j1], j1 == n? '\n' : ' ');
            printf("\n=====================\n");

        }
        printf("Case %d: %d\n",ka,dp[1][n]);
    }
    return 0;
}
