#include <bits/stdc++.h>
using namespace std;

int n, a[2020];
int pre[2020];
int dp[2020][2020];
int c[2020][2020];
const int mod = 1e9 + 7;

int main()
{

	c[0][0] = 1;
	for (int i = 1; i <= 2010; i++)
		for (int j = 0; j <= i; j++)
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;

	

	scanf("%d", &n);
	for (int i = 1; i <= n;i++)
		scanf("%d", &a[i]);
	for (int i = 0; i <= n; i++)
		dp[0][i] = 1;

	for (int i = 1; i <= n; i++)
	{
		int p = pre[i];
		for (int j = 1; j <= n; j++)
		{



		}
		
	}


	return 0;
}