#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define LL long long
#define mod 1000000007

using namespace std;


int n, m;
int dp[12][1<<11];
int d;
int i;

void dfs(int j, int s2)
{

	if(j == m) dp[i+1][s2] = (dp[i+1][s2]+d)% mod;
	else
	{
		if(j < m) dfs(j+1, (1 << j) ^ s2);
		if(j+1 < m && ((3<<j)&s2) == 0) dfs(j+2, s2);
	}
}


int main ()
{

	while(cin >> n)
	{
		// if(n < m) swap(n, m);
		m = 3;
		memset(dp, 0, sizeof(dp));

		dp[0][0] = 1;

		for(i = 0; i < n; i++)
		{
			for(int j = 0; j < (1<<m); j++)if(dp[i][j])
			{
				// cout << i <<" " << j << endl;
				d = dp[i][j];
				dfs(0, j);
			}
		}

		cout << dp[n][0] << endl;

	}

	return 0;
}