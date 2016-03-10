#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int n, m, k;

LL a[20], dp[1<<19][20];
LL b[20][20];

int main()
{

	scanf("%d%d%d", &n, &m, &k);

	for(int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);


	int x, y, z;

	for(int i = 0; i < k; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		b[x-1][y-1] = z;
	}

	for(int mask = 0; mask < (1<<n); mask++)
	{
		for(int x = 0; x < n; x++)if(((1<<x) & mask))
		{
			for(int y = 0; y < n; y++)if(((1<<y) & mask) == 0)
			{
				dp[mask| (1<<y)][y] = max(dp[mask | (1<<y)][y], dp[mask][x] + b[x][y]);
			}
		}
	}


	LL ans = 0;
	LL tmp;
	for(int mask = 0; mask < (1<<n); mask++)
	{
		int cnt = 0;
		tmp = 0;
		for(int i = 0; i < n; i++)if(mask & (1<<i))
		{
			cnt++;
			tmp += a[i];
		}
		if(cnt != m) continue;

		for(int i = 0; i < n; i++)if(mask & (1<<i))
			ans = max(ans, tmp + dp[mask][i]);

	}

	printf("%I64d\n", ans);

	return 0;
}