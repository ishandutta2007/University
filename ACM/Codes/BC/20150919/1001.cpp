#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;


typedef long long LL;


int dp[1020][1020];
int n, p, a[1020];

const int m = 1e9 + 7;


int main()
{

	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &p);

		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			a[i] = ((a[i]%p)+p) % p;
		}


		memset(dp, 0, sizeof(dp));

		dp[0][0] = 1;

		for(int i = 1; i <= n; i++)
			for(int j = 0; j < p; j++)
			{
				dp[i][j] = (dp[i-1][((j-a[i])%p+p)%p] + dp[i-1][j]) % m;
			}



		// for(int i = 1; i <= n; i++)
		// 	for(int j = 0; j < p; j++)
		// 		printf("%d%c", dp[i][j], j == p-1? '\n':' ');

		printf("%d\n", dp[n][0]);
	}
	return 0;
}