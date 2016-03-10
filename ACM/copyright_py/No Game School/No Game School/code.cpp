#include <bits/stdc++.h>
using namespace std;



int dp[1000];
int c[1000], v[1000];
int t[1000];

int main()
{
	
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int T;
	scanf("%d", &T);
	int l, n, m;
	while(T--)
	{		
		scanf("%d%d%d", &l, &n, &m);
		
		t[0] = 0;
		t[n + 1] = l;
		for(int i = 1; i <= n; i++)
			scanf("%d",&t[i]);
		n+=2;
		for(int i = 0; i < m; i++)
			scanf("%d%d", &c[i], &v[i]);
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < m; i++)
		{
			for(int j = c[i]; j < 1000; j++)
			{
				dp[j] = max(dp[j], dp[j-c[i]] + v[i]);
			}
		}
		
		int ans = 0;
		for(int i = 1; i < n; i++)
			ans += dp[t[i] - t[i-1]];
		cout << ans << endl;
	}
	
	return 0;
}