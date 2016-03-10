#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

#define __maxn 1020
#define EPS 1e-10

using namespace std;



int n,k;
long long dp[20][100][1200];
int style[1200];

int check_and_count(int x)
{
	int cnt = 0, pre = 0, now = 0;

	while(x)
	{
		now = x % 2;
		cnt += now;
		x /= 2;
		if(now && pre) return -1;
		pre = now;
	}
	if(cnt > k) return -1;
	return cnt;
}

void init(int n)
{
	int high = (1 << n);
	for(int i = 0; i < high; i++)
	{
		style[i] = check_and_count(i);
		// printf("i:%d = %d\n", i, style[i]);
	}
}

bool __check(int a, int b)
{
	if((a & b)) return false;
	if((a >> 1) & b) return false;
	if((a << 1) & b) return false;
	return true;
}

int main(int argc, char const *argv[])
{

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);

	init(n);
	int _high = 1 << n;


	// printf("after init()\n");
	// printf("%d %d %d\n", n, k, _high);
	// for(int i = 0; i < _high; i++)
	dp[0][0][0] = 1LL;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= k; j++)
		{
			for(int x = 0; x < _high; x++)if(style[x] >= 0 && style[x] <= j)
			{
				for(int y = 0; y < _high; y++)if(style[y] >= 0 && style[y] <= j)
				{
					if(__check(x, y) && style[y] <= j)
					{
						// printf("(%d,%d,%d) from (%d,%d,%d) add %d\n",i, j, y, i -1, j - style[y], x ,dp[i - 1][j - style[y]][x]);
						dp[i][j][y] += dp[i - 1][j - style[y]][x];
					}
				}
			}
		}
		// for(int j = 0; j < _high; j++)
		// {
		// 	printf("dp:%d i:%d j:%d k:%d\n", dp[i][k][j], i, k, j);
		// }
	}

	long long ans = 0LL;
	for(int i = 0; i < _high; i++)
		ans += dp[n][k][i];

	printf("%lld\n", ans);

	return 0;
}