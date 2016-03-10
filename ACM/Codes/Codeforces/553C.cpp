#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define maxn 200020
#define MOD 1000000007


struct Edge{
	int v, c;
}edges[maxn];
int tot;

vector<int>G[maxn];

int n, m;
int color[maxn];

void add_edge(int a, int b, int c)
{
	edges[tot].v = b;
	edges[tot].c = 1-c;
	G[a].push_back(tot++);
}


bool dfs(int u, int c)
{
	color[u] = c;
	for(int i = 0, len = G[u].size(); i < len; i++)
	{
		Edge& e = edges[G[u][i]];
		if(color[e.v] == -1)
		{
			if(!dfs(e.v, c^e.c))
			{
				return false;
			}
		}
		else
		{
			if(((color[e.v])^(color[u])^(e.c)) != 0)
				return false;
		}
	}



	return true;
}


int main()
{
	scanf("%d%d",&n,&m);

	int a, b, c;

	for(int i = 0; i < m; i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		add_edge(a, b, c);
		add_edge(b, a, c);
	}


	memset(color, -1, sizeof(color));
	int ans = 1;
	for(int i = 1; i <= n; i++)
	{
		if(color[i] == -1)
		{
			if(dfs(i, 0))
			{
				if(i!=1) ans = ans*2 % MOD;
			}
			else
			{
				ans = 0;
				break;
			}
		}
	}


	printf("%d\n", ans);

	return 0;
}