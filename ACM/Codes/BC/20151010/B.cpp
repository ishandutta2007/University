#include <cstdio>
#include <cstring>
#include <algorithm>


using namespace std;


typedef long long LL;

LL dp[1002][3002];
int n, t;

struct Node{
	int a, b, c;
}nd[1020];


bool cmp(struct Node a, struct Node b)
{
	return a.c < b.c;
}


int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d", &n, &t);
		memset(dp, 0, sizeof(dp));

		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &nd[i].a, &nd[i].b, &nd[i].c);
		}

		sort(nd + 1, nd + n + 1, cmp);

		for(int i = 1; i <= n; i++)
			for(int j = 0; j <= t; j++)
			{
				dp[i][j] = dp[i-1][j];
				if(j >= nd[i].c)
					dp[i][j] = max(dp[i-1][j-nd[i].c] + nd[i].a - nd[i].b * j, dp[i][j]);
			}
				

		// for(int i = 1; i <= n; i++)
		// {
		// 	for(int j = 0; j <= t; j++)
		// 		printf("%4d", dp[i][j]);
		// 	printf("\n");
		// }

		LL ans = 0;

		for(int i = 0; i <= t; i++)
			ans = max(ans, dp[n][i]);

		printf("%I64d\n", ans);
	}



	return 0;
}