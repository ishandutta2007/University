/*
 *
 *	Dijstra shortest path and minimal cost
 *
 */
#include <bits/stdc++.h>
#define maxn 1020
#define INF 0x7f7f7f7f
using namespace std;
typedef pair<int, int> PII;
struct Edge
//l 为边的长度， c为费用
{
	int u, v, l, c;
	Edge(){}
	Edge(int u,int v, int l, int c):u(u),v(v),l(l),c(c){}
};
struct Node
//Node 用于 priority_queue 的记录
//v: node id
//l: length from start
//c: mincost
{
	int v, l, c;
	Node(){}
	Node(int v, int l, int c):v(v),l(l),c(c){}
	bool operator < (const Node &a) const
	//priority_queue 的优先级和 < 相反
	{
		if(l == a.l) return c > a.c;
		return l > a.l;
	}
};
vector<Edge>G[maxn];
priority_queue<Node>pq;
int dist[maxn],cost[maxn],vis[maxn],tot;
void add_edge(int u, int v, int l, int c)
{
	G[u].push_back(Edge(u, v, l, c));
}
PII dijstra(int s, int d)
//start s, dest d
{
	memset(dist, INF, sizeof(dist));
	memset(cost, INF, sizeof(cost));
	memset(vis, 0, sizeof(vis));
	while(!pq.empty()) pq.pop();
	pq.push(Node(s, 0, 0));
	while(!pq.empty())
	{
		const Node nd = pq.top();
		pq.pop();
		if(vis[nd.v]) continue;
		vis[nd.v] = true;
		dist[nd.v] = nd.l;
		cost[nd.v] = nd.c;
		if(nd.v == d) return make_pair(dist[d], cost[d]);
		for(int i = 0, len = G[nd.v].size(); i < len; i++)
		{
			Edge& e = G[nd.v][i];
			if(!vis[e.v])
			{
				pq.push(Node(e.v, nd.l + e.l, nd.c+e.c));
			}
		}
	}
	//dist[d]: shortest distance
	//cost[d]: mincost
	return make_pair(dist[d], cost[d]);
}
