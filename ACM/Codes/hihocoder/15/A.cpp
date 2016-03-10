#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


typedef long long LL;

int n;
int a[1020][1020];
int a2[1020][1020];
int a5[1020][1020];


int dp[1020][1020];
int op[1020][1020];


int main()
{

	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			if(a[i][j] != 0)
			{
				int tmp = a[i][j];
				while(tmp % 2 == 0)
				{
					a2[i][j] ++;
					tmp/=2;
				}
				tmp = a[i][j];
				while(tmp % 5 == 0)
				{
					a5[i][j] ++;
					tmp/=5;
				}
			}
		}


	memset(dp, 0x3f, sizeof(dp));
	memset(op, 0, sizeof(op));

	op[1][1] = a5[1][1];
	dp[1][1] = a2[1][1];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)if(a[i][j] != 0)
		{
			if(a[i+1][j] != 0)
			{
				if(dp[i+1][j] > dp[i][j] + a2[i+1][j])
				{
					dp[i+1][j] = dp[i][j] + a2[i+1][j];
					op[i+1][j] = op[i][j] + a5[i+1][j];
				}
			}
			if(a[i][j+1] != 0)
			{
				if(dp[i][j+1] > dp[i][j] + a2[i][j+1])
				{
					dp[i][j+1] = dp[i][j] + a2[i][j+1];
					op[i][j+1] = op[i][j] + a5[i][j+1];
				}
			}
		}
	}

	int ans = min(dp[n][n], op[n][n]);

	memset(dp, 0x3f, sizeof(dp));
	memset(op, 0, sizeof(op));

	op[1][1] = a2[1][1];
	dp[1][1] = a5[1][1];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)if(a[i][j] != 0)
		{
			if(a[i+1][j] != 0)
			{
				if(dp[i+1][j] > dp[i][j] + a5[i+1][j])
				{
					dp[i+1][j] = dp[i][j] + a5[i+1][j];
					op[i+1][j] = op[i][j] + a2[i+1][j];
				}
			}
			if(a[i][j+1] != 0)
			{
				if(dp[i][j+1] > dp[i][j] + a5[i][j+1])
				{
					dp[i][j+1] = dp[i][j] + a5[i][j+1];
					op[i][j+1] = op[i][j] + a2[i][j+1];
				}
			}
		}
	}

	ans = min(ans, min(dp[n][n], op[n][n]));

	printf("%d\n", ans);

	return 0;
}