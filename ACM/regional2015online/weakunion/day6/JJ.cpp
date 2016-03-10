#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;



char mp[1020][1020];
int n, m;
int dp[1020][1020];
int ll[1020], rr[1020];

int cal()
{

	int L = ll[0], R = rr[0];
	int minpre = 1;
	// cout << L <<' ' << R << endl;

	dp[0][L] = dp[0][R] = 0;
	for(int i = L+1; i <= R; i++)
		dp[0][i] = 1;
	for(int i = L; i < R; i++)
		dp[0][i] = 1;

	for(int i = 0; i < m; i++)
	{
		minpre = min(minpre, dp[0][i]);
	}

	for(int i = 1; i < n-1; i++)
	{
		for(int j = ll[i]; j <= rr[i]; j++)
		{
			dp[i][j] = minpre+1;
		}

		int tmp = 0x3f3f3f3f;
		for(int j = ll[i]; j <= rr[i]; j++)if(mp[i+1][j] == '#')
		{
			dp[i][j] = min(dp[i][j] + 1, dp[i-1][j]);
			tmp = min(dp[i][j], tmp);
		}
		minpre = tmp;
	}


	int ans = 0;
	for(int i = ll[n-1]; i <= rr[n-1]; i++)
	{
		dp[n-1][i] = minpre+1;
		dp[n-1][i] = min(dp[n-1][i], dp[n-2][i]);
		ans = max(dp[n-1][i], ans);
	}
	
	return ans;
}



int main()
{


	freopen("jinxiety.in", "r", stdin);
	freopen("jinxiety.out", "w", stdout);

	while(scanf("%d%d",&n,&m) != EOF)
	{

		if(n == 0 && m == 0) break;
		memset(dp, 0x3f, sizeof(dp));
		for(int i = 0; i < n; i++)
		{
			scanf("%s", mp[i]);
			int l = 0;
			int r = m-1;
			while(mp[i][l] != '#') l++;
			while(mp[i][r] != '#') r--;

			ll[i] = l;
			rr[i] = r;
		}


		int ans = cal();


		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
				printf("%d\t", dp[i][j]);
			printf("\n");
		}

		printf("%d\n", ans);

	}
	return 0;
}