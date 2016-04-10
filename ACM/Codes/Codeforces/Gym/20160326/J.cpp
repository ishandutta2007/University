#include <bits/stdc++.h>
using namespace std;

int n, p, q;
int pos[2020];
int dp[2020][2020];

bool check(int w)
{
	// printf("!!!%d:\n", w);
	if(p + q >= n) return true;
	int tp, tq;

	tq = min(n, q);
	tp = min(n, p);
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++) if(dp[i][j] != 0x3f3f3f3f)
		{
			int sr = pos[i+1] + w - 1;
			int ed = i;
			while(ed + 1 <= n && pos[ed+1] <= sr)
			{
				ed ++;
				dp[ed][j+1] = min(dp[ed][j+1], dp[i][j]);
			}
			int br = pos[i+1] + 2*w - 1;
			ed = i;
			while(ed + 1 <= n && pos[ed+1] <= br)
			{
				ed ++;
				dp[ed][j] = min(dp[ed][j], dp[i][j] + 1);
			}
		}


	// for (int i = 0; i <= n; i++)
	// 	for (int j = 0; j <= n; j++)
	// 		printf("%d%c", dp[i][j], j == n ? '\n' : ' ');

	for (int i = 0; i <= tp; i++)
		if(dp[n][i] <= q) return true;
	// if(dp[n][p] <= q) return true;
	// else return false;
	// printf("false\n");
	return false;
	// printf("%s\n", now >= n? "yes" : "no");
	// return now >= n;
}


int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &n,&p,&q);
		for (int i = 1; i <= n; i++)
			scanf("%d", &pos[i]);
		sort(pos + 1, pos + n + 1);

		int low = 1, high = 2000;
		int mid;
		while(low < high)
		{
			mid = (low + high) / 2;
			if(check(mid)) high = mid - 1;
			else low = mid + 1;
		}
		printf("%d\n", mid);
	}
	return 0;
}