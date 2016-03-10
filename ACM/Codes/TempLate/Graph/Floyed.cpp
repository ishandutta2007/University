#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 1020
#define INF 0x3f3f3f3f
using namespace std;
int G[maxn][maxn];
int pre[maxn][maxn];
int dist[maxn][maxn];
int n, m;
void floyed()
{
	memset(dist, INF, sizeof(dist));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			pre[i][j] = i;
		dist[i][i] = 0;
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{
				if(G[i][j] > G[i][k] + G[k][j])
				{
					G[i][j] = G[i][k] + G[k][j];
					pre[i][j] = pre[k][j];
				}
			}

}
void show_path(int x, int y)
{
	if(x == y)
	{
		printf("%d \n", x);
		return;
	}

	show_path(x, pre[x][y]);
	printf("%d \n", y);
}
int main()
{
	while(scanf("%d%d",&n,&m) != EOF)
	{
		memset(G, INF, sizeof(G));
		for(int i = 1; i <= n; i++)
			G[i][i] = 0;

		int x, y, z;
		for(int i = 1; i <= m; i++)
		{
			scanf("%d%d%d", &x, &y, &z);
			G[x][y] = min(G[x][y], z);
			G[y][x] = min(G[y][x], z);
		}
		// for(int i = 1; i <= n; i++)
		// 	for(int j = 1; j <= n; j++)
		// 		printf("%d%c", G[i][j], j == n? '\n':' ');
		floyed();
		int q;
		scanf("%d",&q);
		int s, e;
		while(q--)
		{
			scanf("%d%d", &s, &e);
			printf("from %d to %d is %d\n", s, e, G[s][e]);
			show_path(s, e);
		}

	}

	return 0;
}