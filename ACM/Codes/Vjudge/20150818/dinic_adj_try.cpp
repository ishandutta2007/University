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
using namespace std;


struct Edge{
	int u, v, cap;
	Edge(){}
	Edge(int u, int v, int cap) : u(u), v(v), cap(cap){}
};



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
		system("pause");
		for(int j = 0; j < q.size(); j++)
			printf("%d%c", q[j], j == q.size() - 1? '\n' : ' ');
		q.push_back(1);
		memset(vis, 0, sizeof(vis));
		vis[1] = true;

		while(!q.empty())
		{
			for(int j = 0; j < q.size(); j++)
				printf("%d%c", q[j], j == q.size() - 1? '\n' : ' ');
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

				printf("minc = %d, minstart = %d\n", minc, minstart);
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

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	while(scanf("%d%d", &n, &m) != EOF)
	{
		int s, e, c;
		memset(G, 0, sizeof(G));
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d",&s,&e,&c);
			G[s][e] += c;
		}
		printf("%d\n", Dinic());
	}


	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}