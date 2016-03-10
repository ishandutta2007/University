#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef long long LL;
const LL maxn = 100020;

struct Edge{
	int v, id, next;
}edges[maxn*2];

int head[maxn];
int tot = 2;
int n;
int cost[maxn];
int cnt[maxn];
bool vis[maxn];

void addadge(int u, int v, int id)
{
	edges[tot].v = v;
	edges[tot].id = id;
	edges[tot].next = head[u];
	head[u] = tot++;
}
int dfs(int u)
{
	vis[u] = true;
	int res = 1;
	for(int i = head[u]; i != -1; i = edges[i].next)if(vis[edges[i].v] == false)
	{
		vis[edges[i].v] = true;
		int tmp = dfs(edges[i].v);
		cnt[i/2] = tmp;
		res += tmp;
	}
	return res;
}
void solve()
{
	vis[1] = true;
	for(int i = head[1]; i != -1; i = edges[i].next)
	{
		vis[edges[i].v] = true;
		cnt[i/2] = dfs(edges[i].v);
	}
}



int main()
{
	memset(head, -1, sizeof(head));
	scanf("%d", &n);
	int u, v;
	for(int i = 1; i < n; i++)
	{
		scanf("%d%d%d",&u,&v,cost+i);
		addadge(u, v, i);
		addadge(v, u, i);
	}
	solve();
	int m;
	scanf("%d", &m);
	int a, b;
	double ans = 0.0;

	for(int i = 1; i < n; i++)
	{
		LL l = cnt[i], r = n - cnt[i];
		ans += (double)cost[i] * (l*(l-1)/2 * r + r*(r-1)/2 * l) / ((LL)n*(n-1)*(n-2) / 6);
	}	


	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		LL l = cnt[a], r = n - cnt[a];
		ans -= (double)cost[a] * (l*(l-1)/2 * r + r*(r-1)/2 * l) / ((LL)n*(n-1)*(n-2) / 6);
		cost[a] = b;
		ans += (double)cost[a] * (l*(l-1)/2 * r + r*(r-1)/2 * l) / ((LL)n*(n-1)*(n-2) / 6);
		printf("%.7f\n", ans * 2);
	}



	return 0;
}