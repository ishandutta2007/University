#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int dp[40][40][3000];
int map[40][40];
int n, m;
const int INF = 0x3f3f3f3f;
int main()
{


	int T;
	scanf("%d", &T);
	for(int ka = 1; ka <= T; ka++)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
			{
				scanf("%d", &map[i][j]);
			}
		memset(dp, 0x3f, sizeof(dp));
		dp[1][1][map[1][1]] = map[1][1]*map[1][1];

		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				for(int k = 0; k <= 1800; k++)if(dp[i][j][k] != INF)
				{
					dp[i+1][j][k+map[i+1][j]] = min(dp[i+1][j][k+map[i+1][j]], dp[i][j][k] + map[i+1][j]*map[i+1][j]);
					dp[i][j+1][k+map[i][j+1]] = min(dp[i][j+1][k+map[i][j+1]], dp[i][j][k] + map[i][j+1]*map[i][j+1]);
				}
		int ans = INF;
		for(int i = 0; i <= 1800; i++)if(dp[n][m][i] != INF)
			ans = min(ans, dp[n][m][i]*(n+m-1) - i*i);
		printf("Case #%d: %d\n",ka, ans);
	}
	return 0;
}