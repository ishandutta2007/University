#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#define M 1001010
#define N 100010
#define ll long long
#define inf 1<<30
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;

int n,mm=10000007;
int dp[21][11000],mx,s;
int a[21];
int main()
{
    int T,n,m,x,cas=0;
    cin>>T;
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&a[i]);
            a[i]-=x;
            m-=x;
        }
	memset(dp,0,sizeof(dp));
	if (m<0) {
		printf("Case #%d: 0\n",++cas);
		continue;
	}
        dp[0][0]=1;mx=0;
        for (int i=1;i<=n;i++)
        {
            mx+=a[i];
            s=0;
            for (int j=0;j<=mx&&j<=m;j++)
            {
                s=(s+dp[i-1][j])%mm;
                if (j>a[i])
                    s=(s-dp[i-1][j-a[i]-1]+mm)%mm;
                dp[i][j]=s;
            }
        }

        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)
            printf("%d%c", dp[i][j], j == m? '\n':' ');
        printf("Case #%d: %d\n",++cas,dp[n][m]);
    }
}

