#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define __maxn 60020
#define INF 1200000

using namespace std;

struct Edge{
	int v;
	Edge(){}
	Edge(int v):v(v){}
};

vector<Edge>edges;
vector<int>G[__maxn];
int tot;
int inde[__maxn], outde[__maxn], cost[__maxn];
int n;
int dp[__maxn][2];



void dfs(int rt)
{
	// printf("dfs %d\n", rt);
	if(dp[rt][0] == -INF)
	{
		if(outde[rt] == 0)
		{
			dp[rt][0] = 0;
		}else{
			for(int i = 0; i < G[rt].size(); i++)
			{
				dfs(edges[G[rt][i]].v);
			}
			dp[rt][0] = 0;
			for(int i = 0; i < G[rt].size(); i++)
			{
				int to = edges[G[rt][i]].v;
				dp[rt][0] += max(0 ,max(dp[to][0], dp[to][1]));
			}
		}
	}
	if(dp[rt][1] == -INF)
	{
		if(outde[rt] == 0)
		{
			dp[rt][1] = cost[rt];
		}else{
			for(int i = 0; i < G[rt].size(); i++)
			{
				dfs(edges[G[rt][i]].v);
			}
			dp[rt][1] = cost[rt];
			for(int i = 0; i < G[rt].size(); i++)
			{
				int to = edges[G[rt][i]].v;
				dp[rt][1] += max(0, dp[to][0]);
			}
		}
	}

	// printf("rt = %d %d %d\n", rt, dp[rt][0], dp[rt][1]);
}


int main()
{

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	while(cin >> n)
	{
		edges.clear();
		for(int i = 0; i <= n; i++) G[i].clear();
		tot = 0;
		memset(inde, 0, sizeof(inde));
		memset(outde, 0, sizeof(outde));
		memset(cost, 0, sizeof(cost));
		for(int i = 1; i <= n; i++)
		{
			dp[i][0] = dp[i][1] = -INF;
			scanf("%d", &cost[i]);
		}

		int x, y;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d", &x, &y);
			if(x == 0 && y == 0) break;
			outde[y]++;
			inde[x]++;
			edges.push_back(Edge(x));
			G[y].push_back(tot++);
		}

		int i;
		for(i = 1; i <= n; i++)
			if(inde[i] == 0) break;
		dfs(i);

		printf("%d\n", max(dp[i][0], dp[i][1]));
	}




	return 0;
}