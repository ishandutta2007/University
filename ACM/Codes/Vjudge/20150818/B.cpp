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
#define maxn 1020
// #define OJ
using namespace std;

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
		for(int j = 1; j <= n; j++)
			if(G[v][j] > 0 && layer[j] == -1)
			{
				layer[j] = layer[v] + 1;
				if(j == n) return true;
				else q.push(j);
			}
	}
	return false;
}


int Dinic()
{
	int i;
	int maxflow = 0;
	deque<int> q;
	while(countLayer())
	{
		q.push_back(1);
		memset(vis, 0, sizeof(vis));
		vis[1] = true;

		while(!q.empty())
		{
			int nd = q.back();
			if(nd == n)
			{
				int minc = 1000000000;
				int minstart;
				for(i = 1; i < q.size();i++)
				{
					int vs = q[i-1];
					int ve = q[i];
					if(G[vs][ve] > 0 && minc > G[vs][ve])
					{
						minc = G[vs][ve];
						minstart = vs;
					}
				}
				maxflow += minc;
				for(i = 1; i < q.size(); i++)
				{
					int vs = q[i-1];
					int ve = q[i];
					G[vs][ve] -= minc;
					G[ve][vs] += minc;
				}
				while(!q.empty() && q.back() != minstart)
				{
					vis[q.back()] = false;
					q.pop_back();
				}
			}else{
				for(i = 1; i <= n; i++)
					if(G[nd][i] > 0 && layer[i] == layer[nd] + 1 && !vis[i])
					{
						vis[i] = true;
						q.push_back(i);
						break;
					}	
				if(i > n) q.pop_back();
			}
		}

	}

	return maxflow;
}


int main()
{

	#ifndef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif


	int N, F, D;
	scanf("%d%d%d", &N, &F, &D);
	n = 2 + F + D + 2 * N;
	for(int i = 2; i <= F + 1; i++)
		G[1][i] = 1;
	for(int i = F + 2; i <= F + N + 1; i++)
		G[i][i + N] = 1;
	for(int i = 2 + F + 2 * N; i < n; i++)
		G[i][n] = 1;

	for(int i = 1; i <= N; i++)
	{
		int f, d, x;
		scanf("%d%d", &f, &d);
		for(int j = 0; j < f; j++)
		{
			scanf("%d", &x);
			G[x + 1][1 + F + i] = 1;
		}

		for(int j = 0; j < d; j++)
		{
			scanf("%d", &x);
			G[1 + F + N + i][1 + F + N * 2 + x] = 1;
		}
	}

	
	printf("%d\n", Dinic());


	#ifndef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}