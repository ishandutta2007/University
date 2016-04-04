#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
typedef pair<int, int> PII;
struct Edge
{
	int u,v;
	Edge(){}
	Edge(int u, int v):u(u),v(v){}
};
vector<Edge> G[MAXN];
void addedge(int u, int v)
{
	G[u].push_back(Edge(u, v));
	G[v].push_back(Edge(v, u));
}
int n, m, tot, vbs, ves;
int dfn[MAXN], low[MAXN], vis[MAXN];
bool cut[MAXN];
deque<PII> stak;

set<int> belongs[MAXN];
void mark(int u, int id)
{
	if(belongs[u].find(id) == belongs[u].end())
	{
		belongs[u].insert(id);
		printf("%d ", u);
	}
}
set< PII > bridge;
void addbrige(int u, int v)
{
	if(u > v) swap(u, v);
	bridge.insert(PII(u, v));
}
bool isbridge(int u, int v)
{
	if(u > v) swap(u, v);
	if(bridge.find(PII(u, v)) == bridge.end()) return false;
	return true;
}
void tarjan(int now, int pre)
{
	dfn[now] = low[now] = ++tot;
	int child = 0;
	for (int i = 0, len = G[now].size(); i < len; i++)
	if(G[now][i].v != pre && dfn[G[now][i].v] < dfn[now])
	{
		int to = G[now][i].v;
		stak.push_back(PII(now, to));
		if(dfn[to] == 0)
		{
			child++;
			tarjan(to, now);
			low[now] = min(low[now], low[to]);
			if((pre == -1 && child > 1) || (pre != -1 && dfn[now] <= low[to]))
				cut[now] = true;
			if(low[to] > dfn[now])
				addbrige(now, to);
			if(low[to] >= dfn[now])
			{
				PII tmp;
				printf("biconnectivity found %d:\n", ++vbs);
				while(true)
				{
					tmp = stak.back();
					stak.pop_back();
					mark(tmp.first, vbs);
					mark(tmp.second, vbs);
					if(tmp == PII(now, to))
						break;
				}
				printf("\n");
			}
		}
		else if(to != pre)
			low[now] = min(low[now], dfn[to]);
	}
}

void dfs_no_bridge(int now, int pre)
{
	vis[now] = true;
	printf("%d ", now);

	for (int i = 0, len = G[now].size(); i < len; i++)
		if(!isbridge(now, G[now][i].v) && !vis[G[now][i].v])
		{
			dfs_no_bridge(G[now][i].v, now);
		}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		G[i].clear(),belongs[i].clear();
	bridge.clear();
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(cut, 0, sizeof(cut));
	memset(vis, 0, sizeof(vis));
	stak.clear();
	vbs = ves = tot = 0;
	int u, v;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		addedge(u, v);
	}

	printf("Point biconnectivity:\n");
	for (int i = 1; i <= n; i++) if(dfn[i] == 0)
		tarjan(i, -1);

	printf("Briges:\n");
	for (PII x : bridge)
	{
		printf("%d - %d\n", x.first, x.second);
	}

	printf("Edge biconnectivity:\n");
	for (int i = 1; i <= n; i++) if(!vis[i])
	{
		printf("biconnectivity found %d:\n", ++ves);
		dfs_no_bridge(i, -1);
		printf("\n");
	}

	return 0;
}


/*
sample 1:
7 8
1 2
2 3
3 4
1 4
4 5
5 6
6 7
4 7


*/