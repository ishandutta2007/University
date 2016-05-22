#include <bits/stdc++.h>

using namespace std;

const int maxn = 1020;


struct Edge
{
	int u, v, c;
	Edge(){}
	Edge(int u, int v, int c):u(u),v(v),c(c){}
};



// vector<Edge> G[maxn];
vector<Edge> edges;
int dist[maxn];
int n, m;

void addedge(int u, int v, int c)
{
	edges.push_back(Edge(u,v,c));
	// edges.push_back(Edge(v,u,c));
}

bool bellmanford(int s)
{
	memset(dist, 0x3f, sizeof(dist));

	dist[s] = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0, len = edges.size(); j < len; j++)
			{
				int u = edges[j].u, v = edges[j].v, c = edges[j].c;
				if(dist[v] > dist[u] + c)
					dist[v] = dist[u] + c;
			}

		// for (int j = 1; j <= n; j++)
		// 	printf("%d ", dist[j]);
		// printf("\n");
	}

	for (int i = 0, len = edges.size(); i < len; i++)
	{
		Edge& edge = edges[i];
			if(dist[edge.v] > dist[edge.u] + edge.c)
				return false;
	}
	return true;
}

int main()
{
	scanf("%d%d", &n, &m);

	int u,v,c;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u,&v,&c);
		addedge(u, v, c);
	}
	if(bellmanford(1))
	{
		for (int i = 1; i <= n; i++)
			printf("%d%c", dist[i], i == n? '\n' : ' ');
	}
	else
	{
		printf("No shortest path!!!\n");
	}
	return 0;
}