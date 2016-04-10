#include <bits/stdc++.h>
using namespace std;

class Queueing
{
	double dp[1020][1020];
	double probFirst(int l1, int l2, int p1, int p2)
	{
		memset(dp, 0, sizeof(dp));
		double d1 = 1.0/p1, d2 = 1.0/p2;
		double u1 = 1.0-d1, u2 = 1.0-d2;

		for (int i = 1; i <= l2; i++)
			dp[0][i] = 1.0;

		for (int i = 1; i <= l1; i++)
			for (int j = 1; j <= l2; j++)
			{
				dp[i][j] = (dp[i-1][j]*d1*u2 + dp[i][j-1]*d2*u1 + dp[i-1][j-1]*d1*d2) / (1-u1*u2);
			}
		return dp[l1][l2];
	}
};