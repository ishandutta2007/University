#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>


#define ll long long
#define __maxn 250
#define INF 0x3f3f3f3f

using namespace std;

struct Edge{
	int u, v, cap;
	Edge(){}
	Edge(int u, int v, int cap): u(u), v(v), cap(cap){}
}edges[__maxn*__maxn];

vector<int>G[__maxn];
int current[__maxn], layer[__maxn];
int tot, S, T;


void addedge(int u, int v, int cap)
{

	// 加入正向边和对应的反向边
	// 可通过 ^ 操作得到另一条边
	G[u].push_back(tot);
	edges[tot++] = Edge(u, v, cap);
	G[v].push_back(tot);
	edges[tot++] = Edge(v, u, 0);
}


int countlayer()
{
	// 计算出所有点到源点 S 的距离(层数)
	// 如果无法到达汇点则返回 0；
	queue<int> q;
	q.push(S);
	memset(layer, INF, sizeof(layer));
	layer[S] = 0;
	while(!q.empty())
	{
		int nd = q.front();
		q.pop();
		for(int i = 0; i < G[nd].size(); i++)
		{
			Edge& e = edges[G[nd][i]];
			if(e.cap > 0 && layer[e.v] == INF)
			{
				layer[e.v] = layer[nd] + 1;
				q.push(e.v);
			}
		}
	}
	return layer[T] < INF;
}


int dinic(int x, int maxflow)
{
	if(x == T) return maxflow;
	//i = current[x];
	//i 从 current[x] 开始， 当前弧优化
	for(int i = current[x]; i < G[x].size(); i++)
	{
		current[x] = i;
		Edge& e = edges[G[x][i]];
		if(layer[e.v] == layer[x] + 1 && e.cap > 0)
		{
			int flow = dinic(e.v, min(maxflow, e.cap));
			if(flow)
			{
				e.cap -= flow;
				edges[G[x][i]^1].cap += flow;
				return flow;
			}
		}
	}
	return 0;
}


int DINIC()
{
	int ans = 0;
	while(countlayer())
	{
		int flow;
		memset(current, 0, sizeof(current));
		while(flow = dinic(S, INF)) ans += flow;
	}
	return ans;
}


int main()
{

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	int t, n , m;
	scanf("%d", &t);
	for(int ka = 1; ka <= t; ka ++)
	{
		scanf("%d%d", &n, &m);
		tot = 0;
		for(int i = 1; i <= n; i++) 
			G[i].clear();
		memset(edges, 0, sizeof(edges));
		int x,y,z;
		for(int i = 1; i <= m; i++)
		{
			scanf("%d%d%d", &x,&y,&z);
			addedge(x, y, z);
		}
		S = 1;
		T = n;
		printf("Case %d: %d\n", ka, DINIC());
	}

	#ifdef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}