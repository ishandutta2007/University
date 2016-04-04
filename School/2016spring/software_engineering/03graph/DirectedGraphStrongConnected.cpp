/*
	vertex index from 1 to n;
	created on 2016/4/14
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;

struct Edge
{
	int u, v;
	Edge(){}
	Edge(int u, int v):u(u),v(v){}
};
vector<Edge> G[MAXN];
vector<int> sc[MAXN];
deque<int> stak;
bool instak[MAXN];
int n, m, dfn[MAXN], low[MAXN],tot,sccnt;
void addedge(int u, int v)
{
	G[u].push_back(Edge(u,v));
}


void tarjan(int u)
{
	dfn[u] = low[u] = ++tot;
	stak.push_back(u);
	instak[u] = true;
	int v;
	for (int i = 0, len = G[u].size(); i < len; i++)
	{
		int v = G[u][i].v;
		if (dfn[v] == 0)
		{
			tarjan(v);
			if(low[u] > low[v])
				low[u] = low[v];
		}
		// else if(instak[v] && low[v] < low[u])
		else if(instak[v] && dfn[v] < low[u])
			low[u] = low[v];
	}
	if(dfn[u] == low[u])
	{
		sccnt++;
		while(true)
		{
			v = stak.back();
			stak.pop_back();
			sc[sccnt].push_back(v);
			instak[v] = false;
			if(v == u) break;
		}
	}
}




int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++)
		G[i].clear(),sc[i].clear();
	memset(instak, 0, sizeof(instak));
	stak.clear();
	sccnt = 0;
	int u, v;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		addedge(u,v);
	}
	tot = 0;
	for (int i = 1; i <= n; i++) if(dfn[i] == 0)
		tarjan(i);

	for (int i = 1; i <= sccnt; i++)
		for (int j = 0, len = sc[i].size(); j < len; j++)
			printf("%d%c", sc[i][j], j == len-1? '\n':' ');

	return 0;
}

/*
sample 1:
6 8
1 2
1 3
2 4
3 4
3 5
4 1
4 6
5 6

*/