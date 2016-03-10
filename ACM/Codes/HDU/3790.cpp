#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#define maxn 1020
#define INF 0x7f7f7f7f
using namespace std;
typedef pair<int, int> PII;
struct Edge
{
	int u, v, l, c;
	Edge(){}
	Edge(int u,int v, int l, int c):u(u),v(v),l(l),c(c){}
}edges[maxn*maxn];
struct Node
{
	int v, l, c;
	Node(){}
	Node(int v, int l, int c):v(v),l(l),c(c){}
	bool operator < (const Node &a) const
	{
		if(l == a.l) return c > a.c;
		return l > a.l;
	}
};
int tot;
vector<int>G[maxn];
priority_queue<Node>pq;
int n, m, dist[maxn], cost[maxn], vis[maxn];
void add_edge(int u, int v, int l, int c)
{
	edges[tot] = Edge(u, v, l, c);
	G[u].push_back(tot++);
}
PII dijstra(int s, int d)
{
	memset(dist, INF, sizeof(dist));
	memset(cost, INF, sizeof(cost));
	memset(vis, 0, sizeof(vis));
	while(!pq.empty()) pq.pop();
	pq.push(Node(s, 0, 0));
	while(!pq.empty())
	{
		Node nd = pq.top();
		pq.pop();
		if(vis[nd.v]) continue;
		vis[nd.v] = true;
		dist[nd.v] = nd.l;
		cost[nd.v] = nd.c;
		if(nd.v == d) return make_pair(dist[d], cost[d]);
		for(int i = 0, len = G[nd.v].size(); i < len; i++)
		{
			Edge e = edges[G[nd.v][i]];

			if(!vis[e.v])
			{
				pq.push(Node(e.v, nd.l + e.l, nd.c+e.c));
			}
		}
	}
	return make_pair(dist[d], cost[d]);
}
int main()
{
	while(scanf("%d%d", &n, &m) != EOF && n && m)
	{
		for(int i = 0; i <= n; i++) G[i].clear();
		memset(edges, 0, sizeof(edges));
		tot = 0;
		int a, b, c, d;
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d%d", &a, &b, &c, &d);
			add_edge(a, b, c, d);
			add_edge(b, a, c, d);
		}
		int s, t;
		scanf("%d%d", &s, &t);
		PII p = dijstra(s, t);
		printf("%d %d\n", p.first, p.second);
	}
	return 0;
}