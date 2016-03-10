#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int a[500][500];
int sum,ans,num;
int t,n,m,x,y;
int dp[50][50][3000];
int main()
{
	scanf("%d",&t);
	for (int ka=1;ka<=t;ka++)
	{
		memset(a,0,sizeof(a));
		memset(dp,-1,sizeof(dp));

		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);

		dp[1][1][a[1][1]]=a[1][1]*a[1][1];
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				x=i-1;y=j-1;
				if (x>0) 
				{
					for (int k=0;k<=1800;k++)
					{
						if (dp[x][j][k]==-1) continue;
						sum=k+a[i][j];
						num=dp[x][j][k]+a[i][j]*a[i][j];
						if (dp[i][j][sum]==-1) dp[i][j][sum]=num;
						dp[i][j][sum]=min(dp[i][j][sum],num);
					}
				}

				if (y>0)
				{
					for (int k=0;k<=1800;k++)
					{
						if (dp[i][y][k]==-1) continue;
						sum=k+a[i][j];
						num=dp[i][y][k]+a[i][j]*a[i][j];
						if (dp[i][j][sum]==-1) dp[i][j][sum]=num;
						dp[i][j][sum]=min(dp[i][j][sum],num);
					}
				}
			}
		}    
		
		ans=999999999;
		for (int i=0;i<=1800;i++)
		{
			if (dp[n][m][i]==-1) continue;
			num=(n+m-1)*dp[n][m][i]-i*i;
			//cout<<i<<' '<<dp[n][m][i]<<' '<<num<<endl;
			ans=min(ans,num);
		}
			
		printf("Case #%d: %d\n",ka,ans);
	}
} 