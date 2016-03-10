#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define __maxn 400020
#define INF 1200000

using namespace std;

struct Edge{
	int v, c;
	Edge(){}
	Edge(int v, int c):v(v), c(c){}
};

vector<Edge>edges;
vector<int>G[__maxn];
int tot;
int n;
int dp[__maxn];
bool vis[__maxn];


void dfs(int rt, int nowcost)
{
	dp[rt] = 0;
	vis[rt] = true;
	for(int i = 0; i < G[rt].size(); i++)
	{
		Edge e = edges[G[rt][i]];
		if(vis[e.v]) continue;
		dfs(e.v, nowcost + e.c);
		dp[rt] += dp[e.v] + e.c;
	}
}


int main()
{

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	while(cin >> n)
	{

		int x, y;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d", &x, &y);
			edges.push_back(Edge(y, 0));
			G[x].push_back(tot++);
			edges.push_back(Edge(x, 1));
			G[y].push_back(tot++);
		}

		dfs(1, 0);

		for(int i = 1; i <= n; i++)
		{
			printf("%d %d\n", i, dp[i]);
		}

	}




	return 0;
}