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
#define OJ
using namespace std;

int G[maxn][maxn], layer[maxn];
int n, m;
bool vis[maxn];

bool countLayer()
{
	// int nowlayer = 0;
	queue<int>q;
	memset(layer, 0xff, sizeof(layer));
	layer[1] = 0;q.push(1);

	while(!q.empty())
	{
		int v = q.front();q.pop();
		for(int j = 1; j <= m; j++)
			if(G[v][j] > 0 && layer[j] == -1)
			{
				layer[j] = layer[v] + 1;
				if(j == m) return true;
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
			if(nd == m)
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
				for(i = 1; i <= m; i++)
					if(G[nd][i] > 0 && layer[i] == layer[nd] + 1 && !vis[i])
					{
						vis[i] = true;
						q.push_back(i);
						break;
					}	
				if(i > m) q.pop_back();
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
	int t;
	scanf("%d", &t);
	for(int ka = 1; ka <= t; ka++)
	{
		scanf("%d%d", &m, &n);
		int s, e, c;
		memset(G, 0, sizeof(G));
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d%d",&s,&e,&c);
			G[s][e] += c;
		}
		printf("Case %d: %d\n", ka, Dinic());
	}


	#ifndef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
	system("pause");
	return 0;
}