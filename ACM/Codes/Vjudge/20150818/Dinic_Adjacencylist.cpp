#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <string.h>
#define ll long long
#define maxn 320
#define maxe 320

using namespace std;

struct Edge{
	int u, v, c;
	int next;
}edge[maxe];
int head[maxn];

int tot;

void addedge(int u, int v, int c)
{
	tot++;
	edge[tot].u = u;
	edge[tot].v = v;
	edge[tot].c = c;
	edge[tot].next = head[u];
	head[u] = tot;
}



int G[maxn][maxn], layer[maxn];
int m, n;
bool vis[maxn];

bool countLayer()
{
	queue<int>q;
	memset(layer, 0xff, sizeof(layer));
	layer[1] = 0;q.push(1);

	while(!q.empty())
	{
		int v = q.front();q.pop();
		for(int j = head[v]; j != 0; j = edge[j].next)if(layer[edge[j].v] == -1 && edge[j].c > 0)
		{
			layer[edge[j].v] = layer[v] + 1;
			if(edge[j].v == n) return true;
			else q.push(edge[j].v);
		}

	}
	return false;
}


int Dinic()
{
	int i;
	int maxflow = 0;
	deque<int> q, q1;
	while(countLayer())
	{
		q.push_back(1);
		q1.clear();
		memset(vis, 0, sizeof(vis));
		vis[1] = true;

		while(!q.empty())
		{
			int nd = q.back();
			if(nd == n)
			{
				int minc = 1000000000;
				int minstart;
				for(i = 0; i < q1.size();i++)
				{
					int id = q1[i];
					if(edge[id].c > 0 && minc > edge[id].c)
					{
						minc = edge[id].c;
						minstart = edge[id].u;
					}
				}
				maxflow += minc;
				for(i = 0; i < q1.size(); i++)
				{
					int id = q1[i];
					edge[id].c -= minc;
					edge[id^1].c += minc;
				}
				while(!q.empty() && q.back() != minstart)
				{
					vis[q.back()] = false;
					q.pop_back();
					q1.pop_back();
				}
			}else{
				for(i = head[nd]; i != 0; i = edge[i].next)if(edge[i].c > 0)
				{
					int to = edge[i].v;
					if(layer[to] == layer[nd] + 1 && !vis[to])
					{
						vis[to] = true;
						q.push_back(to);
						q1.push_back(i);
						break;
					}
				}
				if(i == 0)
				{
					q.pop_back();
					q1.pop_back();
				}
			}
		}

	}

	return maxflow;
}


int main()
{

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	int t;
	scanf("%d", &t);
	for(int ka = 1; ka <= t; ka++)
	{
		scanf("%d%d", &n, &m);
		int s, e, c;
		memset(G, 0, sizeof(G));
		memset(edge, 0, sizeof(edge));
		memset(head, 0, sizeof(head));
		tot = 0;
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d",&s,&e,&c);
			if(s > e) swap(s, e);
			// printf("%d %d\n", s, e);
			addedge(s, e, c);
			addedge(e, s, 0);
		}

		printf("Case %d: %d\n",ka, Dinic());
	}


	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}